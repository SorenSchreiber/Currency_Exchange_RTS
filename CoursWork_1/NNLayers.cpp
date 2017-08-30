#include "NNLayers.h"

//Layer constructor
NetworkLayer::NetworkLayer()
{
	//set default values
	_Parent = nullptr;
	_Child = nullptr;
	linearOutput = false;
	UseMomentum = false;
	Momentum = 0.9;
}

//init network layer
void NetworkLayer::INIT(int NodeCount, NetworkLayer^ parent, NetworkLayer^ child)
{
	//set up arrays for network layer
	ValuesNeuron = gcnew array<double>(LayerNodes);
	ValuesDesired = gcnew array<double>(LayerNodes);
	Errors = gcnew array<double>(LayerNodes);

	if (parent != nullptr) //if has parent
	{
		_Parent = parent;
	}
	if (child != nullptr)//if has child
	{
		_Child = child;
		Weights = gcnew array<double,2>(LayerNodes,ChildNodes);
		WeightChange = gcnew array<double, 2>(LayerNodes, ChildNodes);
		
		ValuesBias = gcnew array<double>(ChildNodes);
		WeightsBias = gcnew array<double>(ChildNodes);
	}
	else
	{
		Weights = nullptr;
		WeightsBias = nullptr;
		ValuesBias = nullptr;
		WeightChange = nullptr;
	}

	//init arrays as 0
	for (int x = 0;x < LayerNodes;x++)
	{
		ValuesNeuron[x] = 0;
		ValuesDesired[x] = 0;
		Errors[x] = 0;

		if (hasChildLayer())
		{
			for (int y = 0;y < ChildNodes;y++)
			{
				Weights[x,y] = 0;
				WeightChange[x,y] = 0;
			}
		}
	}

	//Init bias values and weights
	if (hasChildLayer())
	{
		for (int x = 0;x< ChildNodes;x++)
		{
			ValuesBias[x] = -1;
			WeightsBias[x] = 0;
		}
	}
}

//does layer has child
bool NetworkLayer::hasChildLayer()
{
	if (_Child == nullptr) //if has no child
		return false;
	else
		return true;
}

//does layer have parent
bool NetworkLayer::hasParentLayer()
{
	if (_Parent == nullptr) //if has no parent
		return false;
	else
		return true;
}

//randomize layer weights
void NetworkLayer::RandWeights()
{
	int randNumber;

	srand((unsigned)time(NULL));

	//create random weight for all connections
	for (int x = 0;x < LayerNodes;x++)
	{
		for (int y = 0; y < ChildNodes; y++)
		{
			randNumber = (((abs(rand()) % (randMax - randMin + 1)) + randMin)); //create random number

			//limit value between min and max
			if (randNumber > randMax)
				randNumber = randMax;
			if (randNumber < randMin)
				randNumber = randMin;

			Weights[x,y] = randNumber/100.0f-1; //set number between 0 and 1
		}
	}

	//create random weight bias for all child nodes
	for (int x = 0; x < ChildNodes; x++)
	{
		randNumber = (((abs(rand()) % (randMax - randMin + 1)) + randMin)); //create random number

		//limit value between min and max
		if (randNumber > randMax)
			randNumber = randMax;
		if (randNumber < randMin)
			randNumber = randMin;

		WeightsBias[x] = randNumber / 100.0f - 1; //set number between 0 and 1
	}
}

//calculate layer error
void NetworkLayer::CalculateErrors()
{
	double sum;

	if (!hasChildLayer())	//Error values on output layer
	{
		for (int x = 0;x < LayerNodes;x++)
		{
			Errors[x] = (ValuesDesired[x] - ValuesNeuron[x])*ValuesNeuron[x] * (1.0f - ValuesNeuron[x]);
		}
	}
	else if (!hasParentLayer()) //Error values on input layer
	{
		for (int x = 0;x < LayerNodes;x++)
		{
			Errors[x] = 0.0f;
		}
	}
	else				//Error on hiden layers
	{
		for (int x = 0;x < LayerNodes;x++)
		{
			sum = 0;
			for (int y = 0;y < ChildNodes;y++)
			{
				sum += _Child->Errors[y] * Weights[x,y];
			}
			Errors[x]=sum*ValuesNeuron[x] * (1.0f - ValuesNeuron[x]);
		}
	}
}

//adjust layer weights
void NetworkLayer::AdjustWeights()
{
	double weightChange;

	if (hasChildLayer())	//if has child
	{
		for (int x = 0;x < LayerNodes;x++)
		{
			for (int y = 0; y < ChildNodes;y++)
			{
				weightChange = RateOfLearning*_Child->Errors[y] * ValuesNeuron[x];	//set weightchange value

				if (UseMomentum)	//if use momentum
				{
					Weights[x,y] += weightChange + Momentum*WeightChange[x,y];	//set weights
					WeightChange[x,y] = weightChange;							//set weightchange
				}
				else
				{
					Weights[x,y] += weightChange;								//set weights
				}
			}
		}

		for (int x = 0;x < ChildNodes;x++)		//for all child notes set weight bias
		{
			WeightsBias[x] += RateOfLearning*_Child->Errors[x] * ValuesBias[x];
		}
	}
}

//calculate layer values
void NetworkLayer::CalculateNeuronValues()
{
	double value=0;

	if (hasParentLayer())													//if has parent layer
	{
		for (int x = 0; x < LayerNodes; x++)								//for all layer nodes
		{
			value = 0;
			for (int y = 0;y < ParentNodes; y++)							//for all parent nodes
			{
				value += _Parent->ValuesNeuron[y] * _Parent->Weights[y,x];	//add to value
			}

			value += _Parent->ValuesBias[x] * _Parent->WeightsBias[x];		//add bias to value

			if (!hasChildLayer() && linearOutput)							//if it has no child and linear output is active
				ValuesNeuron[x] = value;									//set neuron value
			else
				ValuesNeuron[x] = 1.0f / (1 + exp(-value));					//set neuron value with activation funcion
		}
	}
}