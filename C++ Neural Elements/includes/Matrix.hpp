#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_

#include <random>
#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

class Matrix{

public:

  Matrix(int numRows,int numCols, bool isRandom);
  Matrix * transpose();
  void setValue(int r, int c, double v);
  double getValue(int r, int c);
  void printToConsole();
  int getNumCols(){return this->numCols; }
  int getNumRows(){return this->numRows; }


private:
  int numRows,numCols;
  vector<vector<double> > values;
  double generateRandomNumber();

};


#endif
