#include  "../includes/Matrix.hpp"

/*=====================================================
*
*	     Print Matrix to Console
*
=======================================================*/
void Matrix::printToConsole(){
  for(int i = 0; i < numRows; i++){
    for(int j = 0 ;j < numCols; j++){
      cout << this->values.at(i).at(j) << "\t\t";
    }
    cout << endl;
  }

}


/*=====================================================
*
*	           Constructor
*
=======================================================*/
Matrix::Matrix(int numRows, int numCols, bool isRandom){
  this->numRows = numRows;
  this->numCols = numCols;
  for(int i = 0 ; i< numRows ; i++){
    vector<double> colValues;
    for(int j = 0 ; j < numCols ; j++){
        double r = 0.0;
        if(isRandom){
          r = this->generateRandomNumber();
        }
      colValues.push_back(r);
    }
    this->values.push_back(colValues);
  }
}


/*=====================================================
*
*	Generate Random Numbers for the Matrix
*
=======================================================*/
double Matrix::generateRandomNumber(){
  /*std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0,1);
  return   dis(gen);*/
  double rnd = (double)(rand()%10);
  
  return (double)rnd/10.0;;
  
}

/*=====================================================
*
*		Get Transpose of a Matrix
*
=======================================================*/
Matrix *Matrix::transpose(){
  Matrix *m = new Matrix(this->numCols,this->numRows,false);
  for(int i = 0 ; i< numRows ; i++){
    for(int j = 0 ; j < numCols ; j++){
      m->setValue(j,i,this->getValue(i,j));
    }
  }
  return m;
}

/*=====================================================
*
*	     set Value for a Matrix cell
*
=======================================================*/
void Matrix::setValue(int r,int c, double v){
  this->values.at(r).at(c) = v;
}

/*=====================================================
*
*	  Get value from a cell of a Matrix
*
=======================================================*/
double Matrix::getValue(int r,int c){
  return this->values.at(r).at(c);
}
