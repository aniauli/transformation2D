#ifndef MATRIXFORSHEARINGOX_H
#define MATRIXFORSHEARINGOX_H

#include"matrix.h"
#include"punkt.h"

class matrixForShearingOX: public matrix
{
public:
    matrixForShearingOX();
    matrixForShearingOX(double shx);
    matrix inverseMatrix();
    void setShx(double shx);
};

#endif // MATRIXFORSHEARINGOX_H
