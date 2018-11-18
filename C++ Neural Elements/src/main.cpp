#include  <iostream>
#include <vector>
#include "../includes/Neuron.hpp"
#include "../includes/Matrix.hpp"
#include "../includes/NeuralNetwork.hpp"
#include "../includes/MultiplyMat.hpp"
#include "../includes/Matrix2Vec.hpp"


using namespace std;

extern double Neuron::learningRate;

int main(int argc, char** argv){
 
  Neuron::learningRate = 0.245;
 
  vector<double> input;
  input.push_back(1.0);
  input.push_back(0.0);
  input.push_back(1.0);
  
  vector<double> target;
  target.push_back(1.0);
  target.push_back(1.0);
  target.push_back(1.0);


  vector<int> topology;
  topology.push_back(3);
  topology.push_back(2);
  topology.push_back(4);
  topology.push_back(2);
  topology.push_back(3);
  
  cout << "LearningRate: " <<  Neuron::learningRate << endl;
  

  NeuralNetwork *nn = new NeuralNetwork(topology);
  nn->setCurrentInput(input);
  nn->setCurrentTarget(target);

int i = 0;
double Error_Threshould = 0.001;
do
{
  nn->feedForword();  
  nn->backPropagation();
  cout << "epoch: " << i << "\tError: " << nn->getTotalError() <<   endl;
  cout << "\n----------------------------------------------------------------------" << endl;
  i++;
}while(abs(nn->getTotalError()) > Error_Threshould);
  return 0;

}
