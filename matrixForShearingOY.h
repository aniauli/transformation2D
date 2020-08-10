#ifndef MATRIXFORSHEARINGOY_H
#define MATRIXFORSHEARINGOY_H

#include"matrix.h"
#include"punkt.h"

class matrixForShearingOY: public matrix
{
public:
    matrixForShearingOY();
    matrixForShearingOY(double shy);
    matrix inverseMatrix();
    void setShy(double shy);
};

#endif // MATRIXFORSHEARINGOY_H
