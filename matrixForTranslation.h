#ifndef TRANSLATIONMATRIX_H
#define TRANSLATIONMATRIX_H
#include"matrix.h"
#include"punkt.h"

class matrixForTranslation: public matrix
{
public:
    matrixForTranslation();
    matrixForTranslation(double tx, double ty);
    void setTxTy(double tx, double ty);
    matrix inverseMatrix();
};

#endif // TRANSLATIONMATRIX_H
