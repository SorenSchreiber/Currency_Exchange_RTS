//#include "NNLayers2.h"
//
//NetworkLayer::NetworkLayer()
//{
//	_Parent = nullptr;
//	_Child = nullptr;
//	linearOutput = false;
//	UseMomentum = false;
//	Momentum = 0.9;
//}
//
//void NetworkLayer::INIT(int NodeCount, NetworkLayer^ parent, NetworkLayer^ child)
//{
//	//memory allocation
//	ValuesNeuron = (double*)malloc(sizeof(double)* LayerNodes);
//	ValuesDesired = (double*)malloc(sizeof(double)* LayerNodes);
//	Errors = (double*)malloc(sizeof(double)* LayerNodes);
//
//	if (parent != nullptr)
//	{
//		_Parent = parent;
//	}
//	if (child != nullptr)
//	{
//		_Child = child;
//		Weights = (double**)malloc(sizeof(double*)*LayerNodes);
//		WeightChange = (double**)malloc(sizeof(double*)*LayerNodes);
//		for (int x = 0;x < LayerNodes;x++)
//		{
//			WeightChange[x] = (double*)malloc(sizeof(double)*LayerNodes);
//			Weights[x] = (double*)malloc(sizeof(double)*LayerNodes);
//		}
//		ValuesBias = (double*)malloc(sizeof(double)*LayerNodes);
//		WeightsBias = (double*)malloc(sizeof(double)*LayerNodes);
//	}
//	else
//	{
//		Weights = NULL;
//		WeightsBias = NULL;
//		ValuesBias = NULL;
//		WeightChange = NULL;
//	}
//
//	//init arrays as 0
//	for (int x = 0;x < LayerNodes;x++)
//	{
//		ValuesNeuron[x] = 0;
//		ValuesDesired[x] = 0;
//		Errors[x] = 0;
//
//		if (hasChildLayer())
//		{
//			for (int y = 0;y < ChildNodes;y++)
//			{
//				Weights[x][y] = 0;
//				WeightChange[x][y] = 0;
//			}
//		}
//	}
//
//	//Init bias values and weights
//	if (hasChildLayer())
//	{
//		for (int x = 0;x< ChildNodes;x++)
//		{
//			ValuesBias[x] = -1;
//			WeightsBias[x] = 0;
//		}
//	}
//}
//
//bool NetworkLayer::hasChildLayer()
//{
//	if (_Child == nullptr)
//		return false;
//	else
//		return true;
//}
//
//bool NetworkLayer::hasParentLayer()
//{
//	if (_Parent == nullptr)
//		return false;
//	else
//		return true;
//}
//
//void NetworkLayer::Clean()
//{
//	free(ValuesNeuron);
//	free(ValuesDesired);
//	free(Errors);
//
//	if (Weights != NULL)
//	{
//		for (int x = 0; x < LayerNodes; x++)
//		{
//			free(Weights[x]);
//			free(WeightChange[x]);
//		}
//		free(Weights);
//		free(WeightChange);
//	}
//
//	if (ValuesBias != NULL)
//		free(ValuesBias);
//	if (WeightsBias != NULL)
//		free(WeightsBias);
//}
//
//void NetworkLayer::RandWeights()
//{
//	int randNumber;
//
//	srand((unsigned)time(NULL));
//
//	for (int x = 0;x < LayerNodes;x++)
//	{
//		for (int y = 0; y < ChildNodes; y++)
//		{
//			randNumber = (((abs(rand()) % (randMax - randMin + 1)) + randMin));
//
//			if (randNumber > randMax)
//				randNumber = randMax;
//			if (randNumber < randMin)
//				randNumber = randMin;
//
//			Weights[x][y] = randNumber / 100.0f - 1;
//		}
//	}
//
//	for (int x = 0; x < ChildNodes; x++)
//	{
//		randNumber = (((abs(rand()) % (randMax - randMin + 1)) + randMin));
//
//		if (randNumber > randMax)
//			randNumber = randMax;
//		if (randNumber < randMin)
//			randNumber = randMin;
//
//		WeightsBias[x] = randNumber / 100.0f - 1;
//	}
//}
//
//void NetworkLayer::CalculateErrors()
//{
//	double sum;
//
//	if (!hasChildLayer())	//Error values on output layer
//	{
//		for (int x = 0;x < LayerNodes;x++)
//		{
//			Errors[x] = (ValuesDesired[x] - ValuesNeuron[x])*ValuesNeuron[x] * (1.0f - ValuesNeuron[x]);
//		}
//	}
//	else if (!hasParentLayer()) //Error values on input layer
//	{
//		for (int x = 0;x < LayerNodes;x++)
//		{
//			Errors[x] = 0.0f;
//		}
//	}
//	else				//Error on hiden layers
//	{
//		for (int x = 0;x < LayerNodes;x++)
//		{
//			sum = 0;
//			for (int y = 0;y < LayerNodes;y++)
//			{
//				sum += _Child->Errors[y] * Weights[x][y];
//			}
//			Errors[x] = sum*ValuesNeuron[x] * (1.0f - ValuesNeuron[x]);
//		}
//	}
//}
//
//void NetworkLayer::AdjustWeights()
//{
//	double weightChange;
//
//	if (hasChildLayer())
//	{
//		for (int x = 0;x < LayerNodes;x++)
//		{
//			for (int y = 0; y < ChildNodes;y++)
//			{
//				weightChange = RateOfLearning*_Child->Errors[y] * ValuesNeuron[x];
//
//				if (UseMomentum)
//				{
//					Weights[x][y] += weightChange + Momentum*WeightChange[x][y];
//					WeightChange[x][y] = weightChange;
//				}
//				else
//				{
//					Weights[x][y] += weightChange;
//				}
//			}
//		}
//
//		for (int x = 0;x < ChildNodes;x++)
//		{
//			WeightsBias[x] += RateOfLearning*_Child->Errors[x] * ValuesBias[x];
//		}
//	}
//}
//
//void NetworkLayer::CalculateNeuronValues()
//{
//	double value = 0;
//
//	if (hasParentLayer())
//	{
//		for (int x = 0; x < LayerNodes; x++)
//		{
//			value = 0;
//			for (int y = 0;y < ParentNodes; y++)
//			{
//				value += _Parent->ValuesNeuron[y] * _Parent->Weights[x][y];
//			}
//
//			value += _Parent->ValuesBias[x] * _Parent->WeightsBias[x];
//
//			if (!hasChildLayer() && linearOutput)
//				ValuesNeuron[x] = value;
//			else
//				ValuesNeuron[x] = 1.0f / (1 + exp(-value));
//		}
//	}
//}