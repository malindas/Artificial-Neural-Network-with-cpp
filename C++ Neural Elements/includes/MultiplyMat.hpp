#ifndef _MULTIPLY_MAT_HPP
#define _MULTIPLY_MAT_HPP

#include <iostream>
#include <vector>
#include <assert.h>

#include "Matrix.hpp"
using namespace std;
namespace utils
{
  class MultiplyMat{
  public:
      MultiplyMat(Matrix * a, Matrix * b);
      Matrix * execute();

  private:
    Matrix * a;
    Matrix * b;
    Matrix * c;

  };


}
#endif
