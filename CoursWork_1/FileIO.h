#pragma once
#include <string>
#include <iostream>
#include <fstream>

#include "NeuralNetwork.h"

using namespace System;
using namespace System::IO;
using namespace System::Collections;

Generic::List<String^>^ readFromFile(String^ file, String^ path);				//read information from file

void writeToFile(String^ path,String^ file, String^ data, bool append);			//write information to file(either at the end or overwrite)

array<String^,2>^ parseInternetRead(String^ data, int searchCount);				//parse data from internet to desired formate

Generic::List<array<double>^>^ parseTrainignData(int nodes, String^ file);		//parse trainign data to desired form

array<String^, 2>^ loadHData(String^ currency);									//load History Data of currency

void saveNeuralNetwork(NeuralNetwork^ network, String^ path, String^ file);		//save selected neural network in text file

NeuralNetwork^ loadNeuralNetwork(String^ file);									//load neural network from text file

void saveToHData(String^ path, String^ file, String^ data);						//save data to currency history data

Generic::List<String^>^ loadHData(String^ path, String^ file);					//load history data from file

void deleteFiles(String^ file);													//delete seleted file from pc

//the following two functions are no longer used wihtin the aplication. 
//the were used to create sample trainign sets and are left for code review

void createFileForTrend(String^ file, int inputNodes);							//create train data from history data for trend network

void createFileForScale(String^ file, int inputNodes);							//create train data from history data for scale network