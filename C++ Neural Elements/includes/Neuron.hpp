#ifndef _NEURON_HPP_
#define _NEURON_HPP_

#include <iostream>
#include <cmath>

using namespace std;


class Neuron{

public:

  Neuron(double val);

  void setVal(double val);


  // Fast Sigmoid Function
  // f(x) = x / (1 + |x|)
  void activate();

  // Derivative for the fast Sigmoid Function
  // f'(x) = f(x) * (1 - f(x))
  void derive();
	
  double getVal(){ return this->Val;}
  double getActivatedVal(){return this-> activatedVal;}
  double getDerivedVal(){return this->derivedVal;}

  // Default learning Rate;
  static double learningRate;

private:
  double Val;
  double activatedVal;
  double derivedVal;
  
};


#endif
