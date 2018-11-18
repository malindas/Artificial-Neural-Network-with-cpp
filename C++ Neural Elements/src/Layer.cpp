#include  "../includes/Layer.hpp"



/*=====================================================
*
*         Matrixify Neuron Values of a layer
*
=======================================================*/
Matrix * Layer::matrixify(){
  Matrix *m = new Matrix(1, this->neurons.size(),false);
  for(int i = 0; i<this->neurons.size(); i++){
     m->setValue(0,i,this->neurons.at(i)->getVal());
  }
  return m;
}

/*=====================================================
*
*	Matrixify Activated Neuron values of a layer
*
=======================================================*/
Matrix * Layer::matrixifyActivatedVal(){
  Matrix *m = new Matrix(1, this->neurons.size(),false);
  for(int i = 0; i<this->neurons.size(); i++){
     m->setValue(0,i,this->neurons.at(i)->getActivatedVal());
  }
  return m;
}


/*=====================================================
*
*	Matrixify Derived neuron values of a Layer
*
=======================================================*/
Matrix * Layer::matrixifyDerivedVal(){
  Matrix *m = new Matrix(1, this->neurons.size(),false);
  for(int i = 0; i<this->neurons.size(); i++){
     m->setValue(0,i,this->neurons.at(i)->getDerivedVal());
  }
return m;
}

/*=====================================================
*
*	Set Value to a Neurone at a layer
*
=======================================================*/
void Layer::setVal(int i , double v){
  this->neurons.at(i)->setVal(v);

}

/*=====================================================
*
*	 	 Layer Constructor
*
=======================================================*/
Layer::Layer(int size){

  this->size = size;
  for(int i= 0; i < size ; i++){
      Neuron *n = new Neuron(0.00);
      this->neurons.push_back(n);
  }

}
