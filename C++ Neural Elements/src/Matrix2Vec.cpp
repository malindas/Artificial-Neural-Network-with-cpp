#include "../includes/Matrix2Vec.hpp"

/*=====================================================
*
*		    Constructor
*
=======================================================*/
utils::Matrix2Vec::Matrix2Vec(Matrix * a){
this->a = a;
}

/*=====================================================
*
*		Do Matrix to Vecotr
*
=======================================================*/
vector<double> * utils::Matrix2Vec::execute(){
  vector<double> *result;
  for(int r = 0; r < a->getNumRows(); r++){
    for(int c = 0; c < a->getNumCols(); c++){
      result->push_back(a->getValue(r,c));
    }
  }
  return result;
}
