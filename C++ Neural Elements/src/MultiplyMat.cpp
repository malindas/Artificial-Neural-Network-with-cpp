#include "../includes/MultiplyMat.hpp"


/*=====================================================
*
*		      Constructor
*
=======================================================*/
utils::MultiplyMat::MultiplyMat(Matrix * a, Matrix *b){

  this->a = a;
  this->b = b;

  if (a->getNumCols() != b->getNumRows()){
  cerr << "A_rows: " << a->getNumRows() << "!= B_Cols" << b->getNumCols() <<endl;
  assert(false);
  }
  this->c = new Matrix(a->getNumRows(), b->getNumCols(),false);
}


/*=====================================================
*
*		Do Multiplication
*
=======================================================*/
Matrix *utils::MultiplyMat::execute(){
  for(int i =0 ; i< a->getNumRows(); i++){
    for(int j =0 ; j< b->getNumCols(); j++){
      for(int k =0 ; k< b->getNumRows(); k++){
        double p = this->a->getValue(i,k) * this->b->getValue(k,j);
        double newVal = this->c->getValue(i,j) + p;
        this->c->setValue(i,j,newVal);
      }
    }
  }
return this->c;
}
