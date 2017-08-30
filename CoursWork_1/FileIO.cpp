#include "FileIO.h"

//Read a file line by line returning a list of all lines within the file
Generic::List<String^>^ readFromFile(String^ file, String^ path)
{
	String^ Cpath = path + file;		//complete file path

	if (File::Exists(Cpath))			//checking if file exists
	{
		StreamReader^ inFile = gcnew StreamReader(Cpath); //new stream reader for file io

		Generic::List<String^>^ lines = gcnew Generic::List<String^>();	//new list for all lines within the file
		while (!inFile->EndOfStream)	//run until reaching end of file
		{
			lines->Add(inFile->ReadLine());	//add read line to list
		}

		inFile->Close();		//close stream reader
		return lines;		//return all lines
	}
	else //if file not found
		return nullptr;		//return null pointer
}

//Write a String to a designated file, either appending or overwriting
void writeToFile(String^ path, String^ file, String^ data, bool append)
{
	String^ Cpath = path + file;			//full file path
	if (!Directory::Exists(path))			//check if directory exists
	{
		Directory::CreateDirectory(path);	//if not create directory
	}
	StreamWriter^ outFile = gcnew StreamWriter(Cpath,append);	//open new stream writer
	outFile->Write(data);					//write to file
	outFile->Close();						//close stream writer
}

//Parsing data from internet into appropriate form
array<String^,2>^ parseInternetRead(String^ data, int searchCount)
{
	/* Data Formate
	1 search:
	"rate":{Data}

	Data:

	"Field":"data",
	"Field":"data",

	2+ search:

	[Data]
	Data:
	{
		"Field":"data",
		"Field":"data",
	},
	{
	...
	},
	...
	*/
	String^ reqData;															//string 
	data->Replace("\r\n", "");													//removing all new lines from file
	array<String^, 2>^ returnData = gcnew array<String^, 2>(searchCount+1, 2);	//create Array for all information
	String^ DateTime = data->Substring(data->IndexOf("created") + 10, 19);		//filter date and time 
	array<String^>^ Date = DateTime->Split('T')[0]->Split('-');					//parse date
	String^ Time = DateTime->Split('T')[1];										//parse time

	returnData[0, 0] = Date[2] + "-" + Date[1] + "-" + Date[0];					//adding date in correct form to array
	returnData[0, 1] = Time;													//add time to array

	if (searchCount == 1)														//if only one currency exchange is being viewed
	{
		reqData = data->Substring(data->IndexOf("rate") + 7)->Split('}')[0];	//find reqiured data
		reqData = reqData->Replace("\"", "");									//remove any "

		array<String^>^ dataValues = reqData->Split(',');						//split values
		returnData[1, 0] = dataValues[0]->Split(':')[1];						//add name to array
		returnData[1, 1] = dataValues[1]->Split(':')[1];						//add rate to array
	}
	else			//same as abouve just for multiple exchange rates
	{
		reqData = data->Split('[')[1]->Split(']')[0];
		reqData=reqData->Replace("},{", "|");
		reqData = reqData->Replace("}", "");
		reqData = reqData->Replace("{", "");
		reqData = reqData->Replace("\"", "");

		array<String^>^ dataSets = reqData->Split('|');
		for (int x = 0;x < dataSets->Length;x++)
		{
			array<String^>^ dataValues = dataSets[x]->Split(',');

			returnData[x + 1, 0] = dataValues[0]->Split(':')[1];
			returnData[x + 1, 1] = dataValues[1]->Split(':')[1];
		}

	}

	return returnData;	//return data
}

//Parsing train data into appropriate form
Generic::List<array<double>^>^ parseTrainignData(int nodes,String^ file)
{
	array<String^>^ splittInput = file->Split('\\');
	String^ fileName = splittInput[splittInput->Length - 1];
	String^ path = file->Remove(file->Length - fileName->Length); //split file into fileName and file path

	Generic::List<array<double>^>^ output = gcnew Generic::List<array<double>^>();	//create new data array list

	Generic::List<String^>^ data = readFromFile(fileName, path);	//read all lines from selected file

	for each(String^ dataset in data)								//for each line in file
	{
		array<double>^ trainSet = gcnew array<double>(nodes);		//new array of size nodes
		array<String^>^ parse = dataset->Split(':');				//string array containing parsed data

		for (int x = 0;x < nodes;x++)								//for all nodes(array length)
		{
			try
			{
				trainSet[x] = Convert::ToDouble(parse[x]);				//set value to Converted double
			}
			catch (Exception^ e)										//catch error message
			{
				System::Windows::Forms::MessageBox::Show("An exception has occured while converting Data!\r\n Error reads: "+e->Message);
			}
		}
		output->Add(trainSet);										//add current array to list
	}

	return output;													//return output list
}

//parsing history data for a speific currency exchange
array<String^,2>^ loadHData(String^ currency)
{
	Generic::List<String^>^ fileData = readFromFile("HData_" + currency+".txt", "FileIO/Historic_Data/");	//new list with file data
	
	if (fileData != nullptr)	//if fileData is not nullpointer
	{
		array<String^, 2>^ data = gcnew array<String^, 2>(fileData->Count, 3); //create data array

		for (int x = 0;x < fileData->Count;x++)			//for each line in fileData
		{
			data[x, 0] = fileData[x]->Split(';')[0];	//parse first element
			data[x, 1] = fileData[x]->Split(';')[1];	//parse second element
			data[x, 2] = fileData[x]->Split(';')[2];	//parse third element
		}

		return data;									//return data string
	}
	else 
		return nullptr;									//else return null pointer
}

//saving a neural network to a text file
void saveNeuralNetwork(NeuralNetwork^ network, String^ path, String^ file)
{
	/*File Formate:
	Name
	HiddenLayer number
	InputLayer	(-)(:)(;)
	HiddenLayer (-)(:)(;)
	HiddenLayer (-)(:)(;)
	...
	OutputLayer	(-)(:)(;)
	*/

	//Variable definitions
	String^ dataForFileWrite = "";
	
	String^ scale;

	String^ valuesBias;
	String^ weightBias;
	String^ weights;
	String^ weightChanges;
	String^ NeuronValues;

	//Network Information
	dataForFileWrite += network->name+":"+network->_Input->LayerNodes+":";
	for (int x = 0; x < network->_Hidden->Length;x++)
	{
		dataForFileWrite += network->_Hidden[x]->LayerNodes;
		if (x < network->_Hidden->Length - 1)
		{
			dataForFileWrite += "|";
		}
	}
	dataForFileWrite += ":" + network->_Output->LayerNodes;
	dataForFileWrite += "\r\n";
	dataForFileWrite += network->_Hidden->Length+":"+ network->maxError+":"+network->maxIterations+":"+network->scaling;
	dataForFileWrite += "\r\n";
	
	//scaling values
	if (network->scale != nullptr)
	{
		for (int x = 0;x < network->scale->GetLength(0);x++)
		{
			scale += network->scale[x, 0] + "|" + network->scale[x, 1];
			if (x < network->scale->GetLength(0) - 1)
			{
				scale += ":";
			}
		}
	}
	else
	{
		scale += "nullptr";
	}
	dataForFileWrite += scale+ "\r\n";

	//Input Layer
	dataForFileWrite = dataForFileWrite + network->_Input->LayerNodes + ":" + network->_Input->ParentNodes + ":" + network->_Input->ChildNodes;
	dataForFileWrite += ";";
	
	//layer node values
	dataForFileWrite += " ";
	dataForFileWrite += ";";

	//Bias values+weight
	for (int x = 0;x< network->_Input->ChildNodes;x++)
	{
		valuesBias += network->_Input->ValuesBias[x];
		weightBias += network->_Input->WeightsBias[x];

		if (x < network->_Input->ChildNodes-1)
		{
			valuesBias += "|";
			weightBias += "|";
		}
		else
		{
			valuesBias += ":";
			weightBias += ";";
		}
	}
	dataForFileWrite += valuesBias + weightBias;

	//weights and weight changes
	for (int x = 0;x < network->_Input->LayerNodes;x++)
	{
		for (int y = 0;y < network->_Input->ChildNodes;y++)
		{
			weights += network->_Input->Weights[x,y];
			weightChanges += network->_Input->WeightChange[x,y];

			if (y < network->_Input->ChildNodes-1)
			{
				weights += "|";
				weightChanges += "|";
			}
			else if(x<network->_Input->LayerNodes-1)
			{
				weights += ":";
				weightChanges += ":";
			}
			else
			{
				weights += ";";
				weightChanges += ";";
			}
		}
	}
	dataForFileWrite += weights + weightChanges;

	//general information
	dataForFileWrite += network->_Input->RateOfLearning + ";";
	dataForFileWrite += network->_Input->linearOutput + ";";
	dataForFileWrite += network->_Input->UseMomentum + ";";
	dataForFileWrite += network->_Input->Momentum;
	dataForFileWrite += "\r\n";

	//Hidden Layers
	for (int x = 0;x< network->_Hidden->Length;x++)
	{
		valuesBias ="";
		weightBias ="";
		weights = "";
		weightChanges = "";

		//hidden layer information
		dataForFileWrite = dataForFileWrite + network->_Hidden[x]->LayerNodes + ":" + network->_Hidden[x]->ParentNodes + ":" + network->_Hidden[x]->ChildNodes;
		dataForFileWrite += ";";
		
		//layer node values
		for (int y = 0;y< network->_Hidden[x]->LayerNodes;y++)
		{
			NeuronValues += network->_Hidden[x]->ValuesNeuron[y];
			if (y < network->_Hidden[x]->LayerNodes - 1)
			{
				NeuronValues += "|";
			}
		}
		dataForFileWrite += NeuronValues;
		dataForFileWrite += ";";

		//Bias values+weight
		for (int z = 0;z< network->_Hidden[x]->ChildNodes;z++)
		{
			valuesBias += network->_Hidden[x]->ValuesBias[z];
			weightBias += network->_Hidden[x]->WeightsBias[z];

			if (z < network->_Hidden[x]->ChildNodes-1)
			{
				valuesBias += "|";
				weightBias += "|";
			}
			else
			{
				valuesBias += ":";
				weightBias += ";";
			}
		}
		dataForFileWrite += valuesBias + weightBias;

		//weights and weight changes
		for (int z = 0;z < network->_Hidden[x]->LayerNodes;z++)
		{
			for (int y = 0;y < network->_Hidden[x]->ChildNodes;y++)
			{
				weights += network->_Hidden[x]->Weights[z,y];
				weightChanges += network->_Hidden[x]->WeightChange[z,y];

				if (y < network->_Hidden[x]->ChildNodes - 1)
				{
					weights += "|";
					weightChanges += "|";
				}
				else if (z < network->_Hidden[x]->LayerNodes - 1)
				{
					weights += ":";
					weightChanges += ":";
				}
				else
				{
					weights += ";";
					weightChanges += ";";
				}
			}
		}
		dataForFileWrite += weights + weightChanges;

		//general information
		dataForFileWrite += network->_Hidden[x]->RateOfLearning + ";";
		dataForFileWrite += network->_Hidden[x]->linearOutput + ";";
		dataForFileWrite += network->_Hidden[x]->UseMomentum + ";";
		dataForFileWrite += network->_Hidden[x]->Momentum;
		dataForFileWrite += "\r\n";
	}

	//Output Layer
	dataForFileWrite = dataForFileWrite + network->_Output->LayerNodes + ":" + network->_Output->ParentNodes + ":" + network->_Output->ChildNodes;
	dataForFileWrite += ";";
	
	//layer node values
	dataForFileWrite += " ";
	dataForFileWrite += ";";

	//Bias values+weight
	dataForFileWrite += " ";
	dataForFileWrite += ";";

	//weights and weight changes
	dataForFileWrite += " ";
	dataForFileWrite += ";";

	dataForFileWrite += " ";
	dataForFileWrite += ";";
	
	//general information
	dataForFileWrite += network->_Output->RateOfLearning + ";";
	dataForFileWrite += network->_Output->linearOutput + ";";
	dataForFileWrite += network->_Output->UseMomentum + ";";
	dataForFileWrite += network->_Output->Momentum;


	writeToFile(path,file,dataForFileWrite, false);	//write to file
}

//loading a neural network from a text file
NeuralNetwork^ loadNeuralNetwork(String^ file)
{
	NeuralNetwork^ load = gcnew NeuralNetwork();				//new network

	array<String^>^ splittInput = file->Split('\\');
	String^ fileName = splittInput[splittInput->Length - 1];
	String^ path=file->Remove(file->Length-fileName->Length);	//split file path into path and file name

	Generic::List<String^>^ dataLines = readFromFile(fileName, path);	//read lines from file
	if (dataLines != nullptr)
	{
		//Processing read data

		try
		{
			//network name
			array<String^>^netINIT = dataLines[0]->Split(':');
			array<String^>^hidden = netINIT[2]->Split('|');
			array<int>^ hiddenLayers = gcnew array<int>(hidden->Length);
			for (int x = 0;x < hiddenLayers->Length;x++)
				hiddenLayers[x] = Convert::ToInt32(hidden[x]);

			load->INIT(netINIT[0], Convert::ToInt32(netINIT[1]), hiddenLayers, Convert::ToInt32(netINIT[3]), hiddenLayers->Length);

			//network information
			array<String^>^  seg2 = dataLines[1]->Split(':');
			load->sizeHiddenLayer = Convert::ToInt32(seg2[0]);
			load->maxError = Convert::ToDouble(seg2[1]);
			load->maxIterations = Convert::ToInt32(seg2[2]);
			load->scaling = Convert::ToBoolean(seg2[3]);

			//scale
			if (dataLines[2] == "nullptr")
			{
				load->scale = nullptr;
			}
			else
			{
				array<String^>^ scaleBuffer = dataLines[2]->Split(':');
				load->scale = gcnew array<double, 2>(scaleBuffer->Length, 2);

				for (int x = 0;x < scaleBuffer->Length;x++)
				{
					array<String^>^ data = scaleBuffer[x]->Split('|');

					load->scale[x, 0] = Convert::ToDouble(data[0]);
					load->scale[x, 1] = Convert::ToDouble(data[1]);
				}
			}

			//InputLayer
			array<String^>^ inlayer = dataLines[3]->Split(';');
			array<String^>^ InNodes = inlayer[0]->Split(':');

			//layer nodes
			load->_Input->LayerNodes = Convert::ToInt32(InNodes[0]);
			load->_Input->ParentNodes = Convert::ToInt32(InNodes[1]);
			load->_Input->ChildNodes = Convert::ToInt32(InNodes[2]);

			//bias weight/values
			array<String^>^ bias = inlayer[2]->Split(':');
			array<String^>^ biasValues = bias[0]->Split('|');
			array<String^>^ biasWeights = bias[1]->Split('|');

			for (int x = 0; x < load->_Input->ChildNodes;x++)
			{
				load->_Input->ValuesBias[x] = Convert::ToDouble(biasValues[x]);
				load->_Input->WeightsBias[x] = Convert::ToDouble(biasWeights[x]);
			}

			//weights
			array<String^>^ weight = inlayer[3]->Split(':');
			for (int x = 0; x < weight->Length;x++)
			{
				array<String^>^ weights = weight[x]->Split('|');
				for (int y = 0; y < weights->Length;y++)
				{
					load->_Input->Weights[x, y] = Convert::ToDouble(weights[y]);
				}
			}

			//weightchanges
			array<String^>^ weightCH = inlayer[4]->Split(':');
			for (int x = 0; x < weightCH->Length;x++)
			{
				array<String^>^ weightChanges = weightCH[x]->Split('|');
				for (int y = 0; y < weightChanges->Length;y++)
				{
					load->_Input->WeightChange[x, y] = Convert::ToDouble(weightChanges[y]);
				}
			}

			//general information
			load->_Input->RateOfLearning = Convert::ToDouble(inlayer[5]);
			load->_Input->linearOutput = Convert::ToBoolean(inlayer[6]);
			load->_Input->UseMomentum = Convert::ToBoolean(inlayer[7]);
			load->_Input->Momentum = Convert::ToDouble(inlayer[8]);

			//HiddenLayer
			for (int x = 4;x < dataLines->Count - 1;x++)
			{
				//layer nodes
				array<String^>^ hiddenlayer = dataLines[x]->Split(';');
				array<String^>^ HiddenNodes = hiddenlayer[0]->Split(':');

				load->_Hidden[x - 4]->LayerNodes = Convert::ToInt32(HiddenNodes[0]);
				load->_Hidden[x - 4]->ParentNodes = Convert::ToInt32(HiddenNodes[1]);
				load->_Hidden[x - 4]->ChildNodes = Convert::ToInt32(HiddenNodes[2]);

				//node values
				array<String^>^ nodeValues = hiddenlayer[1]->Split('|');

				for (int y = 0;y < nodeValues->Length;y++)
				{
					load->_Hidden[x - 4]->ValuesNeuron[y] = Convert::ToDouble(nodeValues[y]);
				}

				//bias weight/values
				array<String^>^ bias = hiddenlayer[2]->Split(':');
				array<String^>^ biasValues = bias[0]->Split('|');
				array<String^>^ biasWeights = bias[1]->Split('|');

				for (int y = 0; y < load->_Hidden[x - 4]->ChildNodes;y++)
				{
					load->_Hidden[x - 4]->ValuesBias[y] = Convert::ToDouble(biasValues[y]);
					load->_Hidden[x - 4]->WeightsBias[y] = Convert::ToDouble(biasWeights[y]);
				}

				//weights
				array<String^>^ weight = hiddenlayer[3]->Split(':');
				for (int y = 0; y < weight->Length;y++)
				{
					array<String^>^ weights = weight[y]->Split('|');
					for (int z = 0; z < weights->Length;z++)
					{
						load->_Hidden[x - 4]->Weights[y, z] = Convert::ToDouble(weights[z]);
					}
				}

				//weight cahnges
				array<String^>^ weightCH = hiddenlayer[4]->Split(':');
				for (int y = 0; y < weightCH->Length;y++)
				{
					array<String^>^ weightChanges = weightCH[y]->Split('|');
					for (int z = 0; z < weightChanges->Length;z++)
					{
						load->_Hidden[x - 4]->WeightChange[y, z] = Convert::ToDouble(weightChanges[z]);
					}
				}

				//general information
				load->_Hidden[x - 4]->RateOfLearning = Convert::ToDouble(hiddenlayer[5]);
				load->_Hidden[x - 4]->linearOutput = Convert::ToBoolean(hiddenlayer[6]);
				load->_Hidden[x - 4]->UseMomentum = Convert::ToBoolean(hiddenlayer[7]);
				load->_Hidden[x - 4]->Momentum = Convert::ToDouble(hiddenlayer[8]);
			}

			//OutputLayer
			array<String^>^ outlayer = dataLines[dataLines->Count - 1]->Split(';');
			array<String^>^ Outnodes = outlayer[0]->Split(':');

			//layer nodes
			load->_Output->LayerNodes = Convert::ToInt32(Outnodes[0]);
			load->_Output->ParentNodes = Convert::ToInt32(Outnodes[1]);
			load->_Output->ChildNodes = Convert::ToInt32(Outnodes[2]);

			//general information
			load->_Output->RateOfLearning = Convert::ToDouble(outlayer[5]);
			load->_Output->linearOutput = Convert::ToBoolean(outlayer[6]);
			load->_Output->UseMomentum = Convert::ToBoolean(outlayer[7]);
			load->_Output->Momentum = Convert::ToDouble(outlayer[8]);

			return load;	//return loaded network
		}
		catch (Exception^ e)	//catch exceptions
		{
			System::Windows::Forms::MessageBox::Show("Loading failed because of corrupted save file. \r\n Error Message reads: "+e->Message);

			return nullptr;
		}
	}
	else 
		return nullptr;		//reutrn null pointer
}

//adding to the historic data file
void saveToHData(String^ path, String^ file, String^ data)
{
	writeToFile(path, file, data+"\r\n", true);	//wrtie data to the end of file
}

//load history data for a speific currency exchange
Generic::List<String^>^ loadHData(String^ path, String^ file)
{
	Generic::List<String^>^ HDataRead = readFromFile(file,path); //read all history data

	return HDataRead;
}

//delete files from pc
void deleteFiles(String^ file)
{
	String^ selectedFile = "FileIO\\NN_Saves\\NN_Save_" + file+".txt";	//create full path

	if (File::Exists(selectedFile))					//if file exists
		System::IO::File::Delete(selectedFile);		//delete file
	else											//if file doesnt exist
	{
		System::Windows::Forms::MessageBox::Show("No additional files located.");
	}
}

//create train file for trending from history data
void createFileForTrend(String^ file, int inputNodes)
{
	Generic::List<double>^ trainData = gcnew Generic::List <double>();

	array<String^>^ splittInput = file->Split('\\');
	String^ fileName = splittInput[splittInput->Length - 1];
	String^ path = file->Remove(file->Length - fileName->Length); //split full path into path and name

	Generic::List<String^>^ data = readFromFile(fileName, path);	//read lines from file

	for each(String^ item in data)
	{
		trainData->Add(Convert::ToDouble(item->Split(';')[2]));		//get all data objects from lines
	}

	String^ output="";
	for (int x = 0;x < trainData->Count-(inputNodes+1); x++)		//create inputs and wanted outputs for all values in the file
	{
		for (int y = x ;y < inputNodes+x; y++)
		{
			if (trainData[y] < trainData[y + 1])
			{
				output += "0.9";
			}
			else if (trainData[y] > trainData[y + 1])
			{
				output += "0.1";
			}
			else
			{
				output += "0.5";
			}

			if (y < 20 + x - 1)
			{
				output += ":";
			}
			else
			{
				output += ":";
				if (trainData[y+1] > trainData[y + 2])
				{ 
					output += "0.1:0.1:0.9";
				}
				else if (trainData[y + 1] < trainData[y + 2])
				{ 
					output += "0.9:0.1:0.1";
				}
				else
				{
					output += "0.1:0.9:0.1";
				}
			}
		}
		if(x < trainData->Count - (inputNodes+2)) //add new line
			output += "\r\n";
	}

	writeToFile("FileIO/TrainData/", "Train_Trend_"+fileName, output, false);		//write created data to file
}

//create trin file for scaling from history data
void createFileForScale(String^ file, int inputNodes)
{
	Generic::List<double>^ trainData = gcnew Generic::List <double>();
	NeuralNetwork^ net = gcnew NeuralNetwork();

	array<String^>^ splittInput = file->Split('\\');
	String^ fileName = splittInput[splittInput->Length - 1];
	String^ path = file->Remove(file->Length - fileName->Length);	//split full path into path and file name

	Generic::List<String^>^ data = readFromFile(fileName, path);	//red data from file

	for each(String^ item in data)
	{
		trainData->Add(Convert::ToDouble(item->Split(';')[2]));		//get all data objects from lines
	}

	String^ output = "";
	for (int x = 0;x < trainData->Count - (inputNodes+1); x++)		//create inputs and wanted outputs for all values in the file
	{
		for (int y = x;y < 20 + x; y++)
		{
			double datainput = trainData[y + 1] - trainData[y];

			output += Convert::ToString(net->scaleDown(datainput, -1, 1));

			if (y < inputNodes + x - 1)
			{
				output += ":";
			}
			else
			{
				output += ":";
				double pre = trainData[y + 2] - trainData[y+1];

				output += Convert::ToString(net->scaleDown(pre, -1, 1));
			}
		}
		if (x < trainData->Count - (inputNodes+2))					//add new line 
			output += "\r\n";
	}

	writeToFile("FileIO/TrainData/", "Train_Scale_" + fileName, output, false);		//write to file
}