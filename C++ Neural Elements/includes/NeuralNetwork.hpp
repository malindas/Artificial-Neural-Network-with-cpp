#ifndef _NEURAL_NETWORK_HPP_
#define _NEURAL_NETWORK_HPP_

#include <iostream>
#include <vector>
#include <algorithm>
#include "Matrix.hpp"
#include "Layer.hpp"
#include "MultiplyMat.hpp"
#include "Matrix2Vec.hpp"
#include <assert.h>


using namespace std;

class NeuralNetwork{

public:
	
	NeuralNetwork(vector<int> topology);
	void setCurrentInput(vector<double> input);
	void setCurrentTarget(vector<double> target){this->target = target;}

	// Feedforword
	void feedForword();

	// Back Propagation
	void backPropagation();

	// Set Errors
	void setErrors();
	
	// Printing the Network details
	void printToConsole();

	// Get Matrix functions
	Matrix *getNeuronMatrix(int index){return this->layers.at(index)->matrixify();}
	Matrix *getActivatedNeuronMatrix(int index) {return this->layers.at(index)->matrixifyActivatedVal();}
	Matrix *getDerivedNeuronMatrix(int index) {return this->layers.at(index)->matrixifyDerivedVal();}
	Matrix *getWeightMatrix(int index) {return this->weightMatrices.at(index);}
	
	// Setting Neuron values of a Layer
	void setNeuronValue(int indexLayer,int indexNeuron,double val){this->layers.at(indexLayer)->setVal(indexNeuron,val);}	

	// Get total Error	
	double getTotalError(){return this->error;}

	// Get Error vector
	vector<double> getErrors(){return this->errors;}

private:
	// Topology 
	int topologySize;
	vector<int> topology;

	// Layers
	vector<Layer *> layers;
	
	// Weights
	vector<Matrix *> weightMatrices;

	// Inputs and outputs
	vector<double> input;
	vector<double> target;

	// Errors
	double error;
	vector<double> errors;
	vector<double> errorHistory;
	
	// Gradient Matrices
	vector<Matrix *> gradientMatrices;

};

#endif
