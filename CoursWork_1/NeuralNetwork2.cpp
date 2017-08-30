//#include "NeuralNetwork2.h"
//
//
//void NeuralNetwork::INIT(String^ nameInput, int InputNodes, array<int>^ HiddenNodes, int OutputNodes, int sizeArray) //rewrite to allow user manioulation and custom layermasks
//{
//	name = nameInput;
//	_Hidden = gcnew array<NetworkLayer^>(sizeArray);
//	sizeHiddenLayer = sizeArray;//save number of hiddne layers
//
//	_Input = gcnew NetworkLayer();
//	for (int x = 0; x < sizeHiddenLayer; x++)
//	{
//		_Hidden[x] = gcnew NetworkLayer();
//	}
//	_Output = gcnew NetworkLayer();
//
//	_Input->LayerNodes = InputNodes;
//	_Input->ChildNodes = HiddenNodes[0];
//	_Input->ParentNodes = 0;
//	_Input->INIT(InputNodes, nullptr, _Hidden[0]);
//	_Input->RandWeights();
//
//	for (int x = 0; x<sizeHiddenLayer; x++)
//	{
//		_Hidden[x]->LayerNodes = HiddenNodes[x];
//
//		if (x == 0)
//		{
//			if ((x + 1) == sizeHiddenLayer)
//			{
//				_Hidden[x]->ChildNodes = OutputNodes;
//				_Hidden[x]->ParentNodes = InputNodes;
//				_Hidden[x]->INIT(HiddenNodes[x], _Input, _Output);
//			}
//			else
//			{
//				_Hidden[x]->ChildNodes = HiddenNodes[x + 1];
//				_Hidden[x]->ParentNodes = InputNodes;
//				_Hidden[x]->INIT(HiddenNodes[x], _Input, _Hidden[x + 1]);
//			}
//		}
//		else if (x == sizeHiddenLayer - 1)
//		{
//			_Hidden[x]->ChildNodes = OutputNodes;
//			_Hidden[x]->ParentNodes = _Hidden[x - 1]->LayerNodes;
//			_Hidden[x]->INIT(HiddenNodes[x], _Hidden[x - 1], _Output);
//		}
//		else
//		{
//			_Hidden[x]->ChildNodes = HiddenNodes[x + 1];
//			_Hidden[x]->ParentNodes = _Hidden[x - 1]->LayerNodes;
//			_Hidden[x]->INIT(HiddenNodes[x], _Hidden[x - 1], _Hidden[x + 1]);
//		}
//
//		_Hidden[x]->RandWeights();
//	}
//
//	_Output->LayerNodes = OutputNodes;
//	_Output->ChildNodes = 0;
//	_Output->ParentNodes = HiddenNodes[sizeArray - 1];
//	_Output->INIT(OutputNodes, _Hidden[sizeArray - 1], nullptr);
//}
//
//void NeuralNetwork::Clean()
//{
//	_Input->Clean();
//
//	for (int x = 0;x < sizeHiddenLayer;x++)
//	{
//		_Hidden[x]->Clean();
//	}
//
//	_Output->Clean();
//}
//
//void NeuralNetwork::feedData()
//{
//	_Input->CalculateNeuronValues();
//	for (int x = 0;x < sizeHiddenLayer;x++)
//	{
//		_Hidden[x]->CalculateNeuronValues();
//	}
//	_Output->CalculateNeuronValues();
//}
//
//void NeuralNetwork::PropagateBackwards()
//{
//	_Output->CalculateErrors();
//	for (int x = -1 + sizeHiddenLayer;x >= 0;x--)
//	{
//		_Hidden[x]->CalculateErrors();
//	}
//
//	for (int x = -1 + sizeHiddenLayer;x >= 0;x--)
//	{
//		_Hidden[x]->AdjustWeights();
//	}
//	_Input->AdjustWeights();
//}
//
//void NeuralNetwork::SetInput(int node, double value)
//{
//	if ((node >= 0) && (value != NULL) && (node < _Input->LayerNodes))
//	{
//		_Input->ValuesNeuron[node] = value;
//	}
//}
//
//void NeuralNetwork::SetWantedOutput(int node, double value)
//{
//	if ((node >= 0) && (value = NULL) && (node < _Output->LayerNodes))
//	{
//		_Output->ValuesDesired[node] = value;
//	}
//}
//
//void NeuralNetwork::SetHiddenLayerNodes(int layer, int node, double value)
//{
//	if ((node >= 0) && (value != NULL) && (node < _Hidden[layer]->LayerNodes))
//	{
//		_Hidden[layer]->ValuesNeuron[node] = value;
//	}
//}
//
//void NeuralNetwork::SetBiasValues(int layer, int node, double valueBias, double weightBias)
//{
//	if (layer == NULL)//bias for hidden layer 1 stored in input layer
//	{
//		_Input->ValuesBias[node] = valueBias;
//		_Input->WeightsBias[node] = weightBias;
//	}
//	else //bias for all remaining layers stored in their parent layer
//	{
//		_Hidden[layer]->ValuesBias[node] = valueBias;
//		_Hidden[layer]->WeightsBias[node] = weightBias;
//	}
//}
//
//void NeuralNetwork::SetWeightValues(int layer, int node, int connNode, double valueWeight, double biasWeight)
//{
//	if (layer == NULL)//bias for hidden layer 1 stored in input layer
//	{
//		_Input->Weights[node][connNode] = valueWeight;
//		_Input->WeightsBias[connNode] = biasWeight;
//	}
//	else //bias for all remaining layers stored in their parent layer
//	{
//		_Hidden[layer]->Weights[node][connNode] = valueWeight;
//		_Hidden[layer]->WeightsBias[connNode] = biasWeight;
//	}
//}
//
//double NeuralNetwork::getOutput(int node)
//{
//	if ((node >= 0) && (node < _Output->LayerNodes))
//	{
//		return _Output->ValuesNeuron[node];
//	}
//	else
//	{
//		return (double)INT_MAX;		//error indicator
//	}
//}
//
//int NeuralNetwork::getMaxOutputID()
//{
//	int neuron = 0;
//	double maxValue = _Output->ValuesNeuron[0];
//
//	for (int x = 1;x < _Output->LayerNodes;x++)
//	{
//		if (_Output->ValuesNeuron[x] > maxValue)
//		{
//			maxValue = _Output->ValuesNeuron[x];
//			neuron = x;
//		}
//	}
//
//	return neuron;
//}
//
//double NeuralNetwork::CalculateError()
//{
//	double error = 0;
//
//	for (int x = 0;x < _Output->LayerNodes;x++)
//	{
//		error += pow(_Output->ValuesNeuron[x] - _Output->ValuesDesired[x], 2);
//	}
//
//	error = error / _Output->LayerNodes;
//
//	return error;
//}
//
//void NeuralNetwork::setLearningRate(double LRate)
//{
//	_Input->RateOfLearning = LRate;
//	for (int x = 0;x < sizeHiddenLayer;x++)
//	{
//		_Hidden[x]->RateOfLearning = LRate;
//	}
//	_Output->RateOfLearning = LRate;
//}
//
//void NeuralNetwork::setLinearOutput(bool linear)
//{
//	_Input->linearOutput = linear;
//	for (int x = 0;x < sizeHiddenLayer;x++)
//	{
//		_Hidden[x]->linearOutput = linear;
//	}
//	_Output->linearOutput = linear;
//}
//
//void NeuralNetwork::setMomentum(bool momentum, double value)
//{
//	_Input->UseMomentum = momentum;
//	_Input->Momentum = value;
//
//	for (int x = 0;x < sizeHiddenLayer;x++)
//	{
//		_Hidden[x]->UseMomentum = momentum;
//		_Hidden[x]->Momentum = value;
//	}
//
//	_Output->UseMomentum = momentum;
//	_Output->Momentum = value;
//}
//
//void NeuralNetwork::trainNeuralNetwork(NeuralNetwork^ network, Generic::List<array<double>^>^ trainData, bool reTrain)
//{
//	if (maxError == NULL)
//		maxError = maxErrorDefault;
//
//	if (maxIterations == NULL)
//		maxIterations = maxIterationsDefault;
//
//	if (reTrain == true)
//	{
//		maxIterations = maxIterations / 10;
//	}
//
//	double errorValue = 1;
//	int iterationCount = 0;
//
//	while (errorValue > maxError&&iterationCount < maxIterations)
//	{
//		errorValue = 0;
//		iterationCount++;
//
//		for each(array<double>^ data in trainData)
//		{
//			for (int y = 0; y < network->_Input->LayerNodes;y++)
//			{
//				network->SetInput(y, data[y]);
//			}
//
//			for (int z = 0;z < network->_Output->LayerNodes;z++)
//			{
//				network->SetWantedOutput(z, data[z + network->_Input->LayerNodes]);
//			}
//
//			network->feedData();
//			errorValue += network->CalculateError();
//			network->PropagateBackwards();
//		}
//
//		errorValue = errorValue / trainData->Count;
//	}
//}
//
//double NeuralNetwork::scaleUp(double value, double min, double max)
//{
//	double bottomLimit = 0.0;
//	double topLimit = 1.0;
//
//	if (value > topLimit)
//		value = topLimit;
//	if (value < bottomLimit)
//		value = bottomLimit;
//
//	double scaled = 0;
//
//	scaled = ((max - min) * (value - bottomLimit) / (topLimit - bottomLimit)) + min;
//
//	return scaled;
//}
//
//double NeuralNetwork::scaleDown(double value, double min, double max)
//{
//	double bottomLimit = 0.0;
//	double topLimit = 1.0;
//
//	if (value > max)
//		value = max;
//	if (value < min)
//		value = min;
//
//	double scaled = 0;
//
//	scaled = ((topLimit - bottomLimit) * (value - min) / (max - min)) + bottomLimit;
//
//	return scaled;
//}