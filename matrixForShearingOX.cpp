#include "matrixForShearingOX.h"

matrixForShearingOX::matrixForShearingOX()
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

matrixForShearingOX::matrixForShearingOX(double shx)
{
    element[0][0] = 1;
    element[0][1] = shx;
    element[0][2] = 0;
    element[1][0] = 0;
    element[1][1] = 1;
    element[1][2] = 0;
    element[2][0] = 0;
    element[2][1] = 0;
    element[2][2] = 1;
}

matrix matrixForShearingOX::inverseMatrix()
{
    matrix *inverse = this;
    inverse->element[0][1] = -element[0][1];
    return *inverse;
}

void matrixForShearingOX::setShx(double shx)
{
    element[0][1] = shx;
}
