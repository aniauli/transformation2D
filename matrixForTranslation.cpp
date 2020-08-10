#include "matrixForTranslation.h"

matrixForTranslation::matrixForTranslation()
{
    element[0][0] = 1;
    element[0][1] = 0;
    element[0][2] = 0;
    element[1][0] = 0;
    element[1][1] = 1;
    element[1][2] = 0;
    element[2][0] = 0;
    element[2][1] = 0;
    element[2][2] = 1;
}

matrixForTranslation::matrixForTranslation(double tx, double ty)
{
    element[0][0] = 1;
    element[0][1] = 0;
    element[0][2] = tx;
    element[1][0] = 0;
    element[1][1] = 1;
    element[1][2] = ty;
    element[2][0] = 0;
    element[2][1] = 0;
    element[2][2] = 1;
}

matrix matrixForTranslation::inverseMatrix()
{
    matrix *inverse = this;
    inverse->element[0][2] = -element[0][2];
    inverse->element[1][2] = -element[1][2];
    return *inverse;
}

void matrixForTranslation::setTxTy(double tx, double ty)
{
    element[0][0] = 1;
    element[0][1] = 0;
    element[0][2] = tx;
    element[1][0] = 0;
    element[1][1] = 1;
    element[1][2] = ty;
    element[2][0] = 0;
    element[2][1] = 0;
    element[2][2] = 1;
}
