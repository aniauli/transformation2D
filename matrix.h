#ifndef MACIERZ_H
#define MACIERZ_H

#include"punkt.h"
#include<cstdlib>
#include<cmath>

class matrix
{
public:
    matrix();
    double element[3][3];
    punkt muliplyMatrixByPoint(punkt &piksel);
    matrix multiplyByMatrix(matrix &rightMatrix);
    matrix composition(matrix leftMatrix, matrix rightMatrix);
    void setSxSy(double sx, double sy);
};

#endif // MACIERZ_H
