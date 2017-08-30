//#pragma once
//#include <ctime>
//#include <iostream>
//
//#define randMin  0
//#define randMax  200
//
//ref class NetworkLayer
//{
//public:
//	int LayerNodes;
//	int ChildNodes;
//	int ParentNodes;
//
//	double RateOfLearning;
//	double Momentum;
//
//	bool linearOutput;
//	bool UseMomentum;
//
//	double** Weights;
//	double** WeightChange;
//	double* ValuesNeuron;
//	double* ValuesDesired;
//	double* Errors;
//	double* WeightsBias;
//	double* ValuesBias;
//
//	NetworkLayer^ _Parent;
//	NetworkLayer^ _Child;
//
//	NetworkLayer();
//
//	void INIT(int NodeCount, NetworkLayer^ parent, NetworkLayer^ child);
//	void Clean();
//	void RandWeights();
//	void CalculateErrors();
//	void AdjustWeights();
//	void CalculateNeuronValues();
//	bool hasChildLayer();
//	bool hasParentLayer();
//};