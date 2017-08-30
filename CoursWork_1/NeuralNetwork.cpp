#include "NeuralNetwork.h"

//initializing network
void NeuralNetwork::INIT(String^ nameInput, int InputNodes, array<int>^ HiddenNodes, int OutputNodes, int sizeArray) //rewrite to allow user manioulation and custom layermasks
{
	name = nameInput;												//network name
	_Hidden = gcnew array<NetworkLayer^>(sizeArray);				//hidden layer array
	sizeHiddenLayer = sizeArray;									//save number of hiddne layers

	_Input = gcnew NetworkLayer();									//new input layer
	for (int x = 0; x < sizeHiddenLayer; x++)
	{
		_Hidden[x] = gcnew NetworkLayer();							//new hidden layer
	}
	_Output = gcnew NetworkLayer();									//new output layer

	//init input layer with values
	_Input->LayerNodes = InputNodes;								
	_Input->ChildNodes = HiddenNodes[0];
	_Input->ParentNodes = 0;
	_Input->INIT(InputNodes, nullptr, _Hidden[0]);
	_Input->RandWeights();

	//init every hidden layer with values
	for(int x=0; x<sizeHiddenLayer; x++)
	{
		_Hidden[x]->LayerNodes = HiddenNodes[x];

		if (x == 0)																	//first hiddne layer
		{
			if ((x + 1) == sizeHiddenLayer)											//if only hidden layer
			{
				_Hidden[x]->ChildNodes = OutputNodes;
				_Hidden[x]->ParentNodes = InputNodes;
				_Hidden[x]->INIT(HiddenNodes[x], _Input, _Output);
			}
			else
			{
				_Hidden[x]->ChildNodes = HiddenNodes[x+1];
				_Hidden[x]->ParentNodes = InputNodes;
				_Hidden[x]->INIT(HiddenNodes[x], _Input, _Hidden[x + 1]);
			}
		}
		else if (x == sizeHiddenLayer - 1)											//last hiddne layer
		{
			_Hidden[x]->ChildNodes = OutputNodes;
			_Hidden[x]->ParentNodes = _Hidden[x - 1]->LayerNodes;
			_Hidden[x]->INIT(HiddenNodes[x], _Hidden[x - 1], _Output);
		}
		else																		//all othe rhidden layers
		{
			_Hidden[x]->ChildNodes = HiddenNodes[x + 1];
			_Hidden[x]->ParentNodes = _Hidden[x - 1]->LayerNodes;
			_Hidden[x]->INIT(HiddenNodes[x], _Hidden[x - 1], _Hidden[x + 1]);
		}

		_Hidden[x]->RandWeights();
	}

	//init output layer with values
	_Output->LayerNodes = OutputNodes;
	_Output->ChildNodes = 0;
	_Output->ParentNodes = HiddenNodes[sizeArray-1];
	_Output->INIT(OutputNodes, _Hidden[sizeArray - 1], nullptr);
}

//feeding data trhough the network
void NeuralNetwork::feedData()
{
	_Input->CalculateNeuronValues();			//calculate values input
	for (int x = 0;x < sizeHiddenLayer;x++)
	{
		_Hidden[x]->CalculateNeuronValues();	//calculate values hidden
	}
	_Output->CalculateNeuronValues();			//calculate values output
}

//recalculate network values to compensate for error
void NeuralNetwork::PropagateBackwards()
{
	_Output->CalculateErrors();						//calc error in output
	for (int x = -1+sizeHiddenLayer;x >=0 ;x--)
	{
		_Hidden[x]->CalculateErrors();				//calc error in hidden
	}

	for (int x = -1 + sizeHiddenLayer;x >= 0;x--)	//adjust hidden weights
	{
		_Hidden[x]->AdjustWeights();
	}
	_Input->AdjustWeights();						//adjust input weights
}

//set value to specific input node
void NeuralNetwork::SetInput(int node, double value)
{
	if ((node >= 0) && (value != NULL) && (node < _Input->LayerNodes))		//if parameters valid
	{
		_Input->ValuesNeuron[node] = value;									//set neuron value
	}
}

//set desired value of specific output node
void NeuralNetwork::SetWantedOutput(int node, double value)
{
	if ((node >= 0) && (value != NULL) && (node < _Output->LayerNodes))	//if parameters valid
	{
		_Output->ValuesDesired[node] = value;							//set wanted output
	}
}

//set hiddne layer node
void NeuralNetwork::SetHiddenLayerNodes(int layer, int node, double value)
{
	if ((node >= 0) && (value != NULL) && (node < _Hidden[layer]->LayerNodes))	//if parameters valid
	{
		_Hidden[layer]->ValuesNeuron[node] = value;								//set neuron value
	}
}

//set bias values/weights
void NeuralNetwork::SetBiasValues(int layer, int node, double valueBias, double weightBias)
{
	if (layer == NULL)//bias for hidden layer 1 stored in input layer
	{
		//set bias
		_Input->ValuesBias[node] = valueBias;
		_Input->WeightsBias[node] = weightBias;
	}
	else //bias for all remaining layers stored in their parent layer
	{
		//set bias
		_Hidden[layer]->ValuesBias[node] = valueBias;
		_Hidden[layer]->WeightsBias[node] = weightBias;
	}
}

//set weights
void NeuralNetwork::SetWeightValues(int layer, int node, int connNode, double valueWeight, double biasWeight)
{
	if (layer == NULL)//bias for hidden layer 1 stored in input layer
	{
		//set weights
		_Input->Weights[node,connNode] = valueWeight;
		_Input->WeightsBias[connNode] = biasWeight;
	}
	else //bias for all remaining layers stored in their parent layer
	{
		//set weights
		_Hidden[layer]->Weights[node,connNode] = valueWeight;
		_Hidden[layer]->WeightsBias[connNode] = biasWeight;
	}
}

//get output of specific node
double NeuralNetwork::getOutput(int node)
{
	if ((node >= 0) && (node < _Output->LayerNodes))	//if paramter is valid
	{
		return _Output->ValuesNeuron[node];				//get output value
	}
	else
	{
		return (double)INT_MAX;		//error indicator
	}
}

//get id of highest output node
int NeuralNetwork::getMaxOutputID()
{
	int neuron=0;
	double maxValue=_Output->ValuesNeuron[0];

	//check each output nuron for highest value
	for(int x = 1;x < _Output->LayerNodes;x++)
	{
		if (_Output->ValuesNeuron[x] > maxValue)		//if bigger than stored
		{
			maxValue = _Output->ValuesNeuron[x];
			neuron = x;
		}
	}

	return neuron;	//return biggest value id
}

//compute error
double NeuralNetwork::CalculateError()
{
	double error = 0;

	for (int x = 0;x < _Output->LayerNodes;x++)
	{
		error += pow(_Output->ValuesNeuron[x] - _Output->ValuesDesired[x], 2); //calculate and add all output errors
	}

	error = error / _Output->LayerNodes;	//get average Error

	return error;	//return error
}

//set learning rate
void NeuralNetwork::setLearningRate(double LRate)
{
	//set learnign rate throughout all layers
	_Input->RateOfLearning = LRate;
	for (int x = 0;x < sizeHiddenLayer;x++)
	{
		_Hidden[x]->RateOfLearning = LRate;
	}
	_Output->RateOfLearning = LRate;
}

//set linear output
void NeuralNetwork::setLinearOutput(bool linear)
{
	//set linear output throughout all layers
	_Input->linearOutput = linear;
	for (int x = 0;x < sizeHiddenLayer;x++)
	{
		_Hidden[x]->linearOutput = linear;
	}
	_Output->linearOutput = linear;
}

//set momentum
void NeuralNetwork::setMomentum(bool momentum, double value)
{
	//set momentum troughout all layers
	_Input->UseMomentum = momentum;
	_Input->Momentum = value;

	for (int x = 0;x < sizeHiddenLayer;x++)
	{
		_Hidden[x]->UseMomentum = momentum;
		_Hidden[x]->Momentum = value;
	}

	_Output->UseMomentum = momentum;
	_Output->Momentum = value;
}

//train network with given training data
void NeuralNetwork::trainNeuralNetwork(NeuralNetwork^ network, Generic::List<array<double>^>^ trainData,bool reTrain)
{
	if (maxError == NULL)
		maxError = maxErrorDefault;	//set default max error

	if (maxIterations == NULL)
		maxIterations = maxIterationsDefault; //set default max iterations

	if (reTrain == true)
	{
		maxIterations = maxIterations / 10;		//ife retraining use only 10% of iterations
	}

	double errorValue=1;
	int iterationCount=0;

	while (errorValue > maxError&&iterationCount < maxIterations)	//while error to high and not enough iterations
	{
		errorValue = 0;
		iterationCount++;

		for each(array<double>^ data in trainData)					//for each training set 
		{
			for (int y = 0; y < network->_Input->LayerNodes;y++)	//set inputs
			{
				network->SetInput(y, data[y]);
			}

			for (int z = 0;z < network->_Output->LayerNodes;z++)	//set desired outputs
			{
				network->SetWantedOutput(z, data[z + network->_Input->LayerNodes]);
			}

			network->feedData();	//feed data
			errorValue += network->CalculateError();	//calc and add error
			network->PropagateBackwards();				//propagate back
		}

		errorValue = errorValue / trainData->Count;		//get average error
	}
}

//scale values up
double NeuralNetwork::scaleUp(double value,double min, double max)
{
	double bottomLimit = 0.0;	//bottom value of input
	double topLimit = 1.0;		//upper value of input

	if (value > topLimit)		//set value to top limit
		value = topLimit;
	if (value < bottomLimit)	//set value to bottom limit
		value = bottomLimit;

	double scaled = 0;			//sacled outut

	scaled = ((max - min) * (value - bottomLimit) / (topLimit - bottomLimit)) + min; //scale value from 0/1 to x/y

	return scaled;				//return scaled value
}	

//scale values down
double NeuralNetwork::scaleDown(double value, double min, double max)
{
	double bottomLimit = 0.0;	//bottom limit of output value
	double topLimit = 1.0;		//upper limit of output value

	if (value > max)	//set value to max
		value = max;
	if (value < min)	//set value to min
		value = min;

	double scaled=0;	//output value

	scaled = ((topLimit - bottomLimit) * (value - min) / (max - min)) + bottomLimit; //scale input between x/y to 0/1

	return scaled;		//return scaled value
}