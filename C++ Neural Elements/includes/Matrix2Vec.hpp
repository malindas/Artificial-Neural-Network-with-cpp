#ifndef _MATRIX2VEC_HPP
#define _MATRIX2VEC_HPP

#include <iostream>
#include <vector>
#include <assert.h>

#include "Matrix.hpp"

using namespace std;

namespace utils
{
  class Matrix2Vec{
  public:
    Matrix2Vec(Matrix * a);
    vector<double> * execute();
  private:
    Matrix * a;
  };

}


#endif
