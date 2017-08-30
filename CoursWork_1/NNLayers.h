#pragma once
#include <ctime>
#include <iostream>

#define randMin  0		//min value for randomization
#define randMax  200	//max value for randomization

ref class NetworkLayer
{
public:
	int LayerNodes;															//number of nodes in layer
	int ChildNodes;															//number of nodes in child
	int ParentNodes;														//number of nodes in parent

	double RateOfLearning;													//rate of learning
	double Momentum;														//momentum value

	bool linearOutput;														//bool for linear output
	bool UseMomentum;														//bool use momentum

	array<double,2>^ Weights;												//2d array for weights
	array<double,2>^ WeightChange;											//2d araay for weight changes
	array<double>^ ValuesNeuron;											//array of neuron values
	array<double>^ ValuesDesired;											//array of desired values
	array<double>^ Errors;													//array of error
	array<double>^ WeightsBias;												//array of weight biases
	array<double>^ ValuesBias;												//array of bias values

	NetworkLayer^ _Parent;													//pointer to parent layer
	NetworkLayer^ _Child;													//pointer to child layer

	NetworkLayer();															//constructor

	void INIT(int NodeCount, NetworkLayer^ parent, NetworkLayer^ child);	//init layer
	void RandWeights();														//randomize weights
	void CalculateErrors();													//calc error
	void AdjustWeights();													//adjust weights
	void CalculateNeuronValues();											//calc neuron values
	bool hasChildLayer();													//layer has child?
	bool hasParentLayer();													//layer has parent?
};	