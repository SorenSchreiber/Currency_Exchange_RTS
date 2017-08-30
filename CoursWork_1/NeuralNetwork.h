#pragma once
#include "NNLayers.h"

using namespace System;
using namespace System::Collections;

#define maxErrorDefault 0.05																				//default max error
#define maxIterationsDefault 50000																			//default max iterations

ref class NeuralNetwork
{
public:
	String^ name;																							//network name
	double maxError;																						//max error
	int maxIterations;																						//max iterations
	bool scaling;																							//network is scaling?
	array<double, 2>^ scale;																				//array for scaling values

	NetworkLayer^ _Input;																					//pointer to input layer
	array<NetworkLayer^>^ _Hidden;																			//array of pointers to hidden layers
		int sizeHiddenLayer=1;																				//number of hiddne layers (default 1)
	NetworkLayer^ _Output;																					//pointer to output layer

	void INIT(String^ nameInput, int InputNodes, array<int>^ HiddenNodes, int OutputNodes,int sizeArray);	//initialize network
	void feedData();																						//feed data for prediction/training
	void PropagateBackwards();																				//change network values to compensate for errors

	void SetInput(int node, double value);																	//set input node
	void SetWantedOutput(int node, double value);															//set wanted output node
	void SetHiddenLayerNodes(int layer, int node, double value);											//set hiddne layer nodes
	void SetBiasValues(int layer, int node, double valueBias, double weightBias);							//set bias values
	void SetWeightValues(int layer, int node, int connNode, double valueWeight, double biasWeight);			//set weight values
	double getOutput(int node);																				//get value of output node

	int getMaxOutputID();																					//get output id with greatest neuron value

	double CalculateError();																				//calculate error values

	void setLearningRate(double LRate);																		//set learning rate
	void setLinearOutput(bool linear);																		//set linear output
	void setMomentum(bool momentum, double value);															//set momentum

	void trainNeuralNetwork(NeuralNetwork^ network, Generic::List<array<double>^>^ trainData, bool reTrain);//train network eith given dataset

	double scaleUp(double value, double min, double max);													//scale values up
	double scaleDown(double value, double min, double max);													//scale values down
};