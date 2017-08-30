//#pragma once
//#include "NNLayers2.h"
//
//using namespace System;
//using namespace System::Collections;
//
//#define maxErrorDefault 0.05
//#define maxIterationsDefault 50000
//
//ref class NeuralNetwork
//{
//public:
//	String^ name;
//	double maxError;
//	int maxIterations;
//	bool scaling;
//	array<double, 2>^ scale;
//
//	NetworkLayer^ _Input;
//	array<NetworkLayer^>^ _Hidden;//rewrite to allow user manioulation and custom layermasks
//	int sizeHiddenLayer = 1;
//	NetworkLayer^ _Output;
//
//	void INIT(String^ nameInput, int InputNodes, array<int>^ HiddenNodes, int OutputNodes, int sizeArray);
//	void Clean();
//	void feedData();
//	void PropagateBackwards();
//
//	void SetInput(int node, double value);
//	void SetWantedOutput(int node, double value);
//	void SetHiddenLayerNodes(int layer, int node, double value);
//	void SetBiasValues(int layer, int node, double valueBias, double weightBias);
//	void SetWeightValues(int layer, int node, int connNode, double valueWeight, double biasWeight);
//	double getOutput(int node);
//
//	int getMaxOutputID();
//
//	double CalculateError();
//
//	void setLearningRate(double LRate);
//	void setLinearOutput(bool linear);
//	void setMomentum(bool momentum, double value);
//
//	void trainNeuralNetwork(NeuralNetwork^ network, Generic::List<array<double>^>^ trainData, bool reTrain);
//
//	double scaleUp(double value, double min, double max);
//	double scaleDown(double value, double min, double max);
//};