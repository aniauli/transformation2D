#include "matrixForScaling.h"

matrixForScaling::matrixForScaling()
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

matrixForScaling::matrixForScaling(double sx, double sy)
{
    element[0][0] = sx;
    element[0][1] = 0;
    element[0][2] = 0;
    element[1][0] = 0;
    element[1][1] = sy;
    element[1][2] = 0;
    element[2][0] = 0;
    element[2][1] = 0;
    element[2][2] = 1;
}

matrix matrixForScaling::inverseMatrix()
{
    matrix *inverse = this;
    if(element[0][0]!= 0 && element[1][1] != 0)
    {
        inverse->element[0][0] = 1.0/element[0][0];
        inverse->element[1][1] = 1.0/element[1][1];
    }
    return *inverse;
}

void matrixForScaling::setSxSy(double sx, double sy)
{
    if(sx != 0 && sy != 0)
    {
        element[0][0] = sx;
        element[1][1] = sy;
    }
    else
    {
        element[0][0] = 1;
        element[1][1] = 1;
    }
}
