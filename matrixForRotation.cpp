#include "matrixForRotation.h"

matrixForRotation::matrixForRotation()
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

matrixForRotation::matrixForRotation(double alpha)
{
    element[0][0] = cos(alpha);
    element[0][1] = -sin(alpha);
    element[0][2] = 0;
    element[1][0] = sin(alpha);
    element[1][1] = cos(alpha);
    element[1][2] = 0;
    element[2][0] = 0;
    element[2][1] = 0;
    element[2][2] = 1;
}

matrix matrixForRotation::inverseMatrix()
{
    matrix* inverse = this;
    inverse->element[0][1] = -element[0][1];
    inverse->element[1][0] = -element[1][0];
    return *inverse;
}

void matrixForRotation::setAlpha(double alpha)
{
    element[0][0] = cos(alpha);
    element[0][1] = -sin(alpha);
    element[1][0] = sin(alpha);
    element[1][1] = cos(alpha);
}
