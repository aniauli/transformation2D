#include "matrixForShearingOY.h"

matrixForShearingOY::matrixForShearingOY()
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

matrixForShearingOY::matrixForShearingOY(double shy)
{
    element[0][0] = 1;
    element[0][1] = 0;
    element[0][2] = 0;
    element[1][0] = shy;
    element[1][1] = 1;
    element[1][2] = 0;
    element[2][0] = 0;
    element[2][1] = 0;
    element[2][2] = 1;
}

matrix matrixForShearingOY::inverseMatrix()
{
    matrix *inverse = this;
    inverse->element[1][0] = -element[1][0];
    return *inverse;
}

void matrixForShearingOY::setShy(double shy)
{
    element[1][0] = shy;
}
