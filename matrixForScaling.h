#ifndef MATRIXFORSCALING_H
#define MATRIXFORSCALING_H

#include"matrix.h"
#include"punkt.h"

class matrixForScaling: public matrix
{
public:
    matrixForScaling();
    matrixForScaling(double sx, double sy);
    matrix inverseMatrix();
    void setSxSy(double sx, double sy);
};

#endif // MATRIXFORSCALING_H
