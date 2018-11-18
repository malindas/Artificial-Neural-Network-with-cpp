#include "../includes/Neuron.hpp"

/*=====================================================
*
*			Constructor
*
=======================================================*/
Neuron::Neuron(double val){
  this->Val = val;
  activate();
  derive();
}


/*=====================================================
*
*	Set Value to a Neurone
*
=======================================================*/
void Neuron::setVal(double val){
  this->Val = val;
  activate();
  derive();
}



/*=====================================================
*
*	       _Fast Sigmoid Function_
* 		f(x) = x / (1 + |x|)
*
=======================================================*/

void Neuron::activate(){
  this->activatedVal = this->Val /(1 + abs(this->Val));
}


/*=====================================================
*
*	 Derivative for the fast Sigmoid Function
*              f'(x) = f(x) * (1 - f(x))
*
=======================================================*/
void Neuron::derive(){
  this->derivedVal = this->activatedVal * (1 - this->activatedVal);
}
