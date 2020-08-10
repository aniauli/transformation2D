#ifndef MATRIXFORROTATION_H
#define MATRIXFORROTATION_H

#include"matrix.h"
#include"punkt.h"

class matrixForRotation: public matrix
{
public:
    matrixForRotation();
    matrixForRotation(double alpha);
    matrix inverseMatrix();
    void setAlpha(double alpha);
};

#endif // MATRIXFORROTATION_H
