#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QImage>
#include <QMouseEvent>
#include <QColorDialog>
#include <QColor>
#include "punkt.h"
#include "matrix.h"
#include "matrixForTranslation.h"
#include "matrixForScaling.h"
#include "matrixForRotation.h"
#include "matrixForShearingOX.h"
#include "matrixForShearingOY.h"
#include<iostream>
#include<cmath>

namespace Ui {
    class MyWindow;
}

class MyWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MyWindow(QWidget *parent = 0);

    ~MyWindow();

private:
    Ui::MyWindow *ui;

    QColor colorCzysc, pktColor, czerwony;

    QImage *img, *T, *podstawa;

    int szer;
    int wys;

    double PI = 3.14159265;

    int srodekTranslacjiSlider = 380;
    int srodekSkalowaniaSlider = 10;
    int srodekRotacjiSlider = 0;
    int srodekPochyleniaSlider = 10;

    int valueTx0 = srodekTranslacjiSlider;
    int valueTy0 = srodekTranslacjiSlider;
    int currentTx = 0;
    int currentTy = 0;

    double valueSx0 = 10.0;
    double valueSy0 = 10.0;
    double currentSx = 1;
    double currentSy = 1;

    int valueAlpha0 = srodekRotacjiSlider;
    double currentAlpha = 0;

    double currentShx = 0;
    double currentShy = 0;
    int valueShx0 = srodekPochyleniaSlider;
    int valueShy0 = srodekPochyleniaSlider;

    matrixForTranslation *macierzTmpPlus = new matrixForTranslation();
    matrixForTranslation *macierzTmpMinus = new matrixForTranslation();

    matrixForTranslation *macierzPrzesuniecia = new matrixForTranslation();

    matrixForScaling *macierzSkalowania0 = new matrixForScaling();
    matrix *macierzSkalowania = new matrix();

    matrixForRotation *macierzRotacji0 = new matrixForRotation();
    matrix *macierzRotacji = new matrix();

    matrixForShearingOX *macierzPochyleniaOX0 = new matrixForShearingOX();
    matrix *macierzPochyleniaOX = new matrix();

    matrixForShearingOY *macierzPochyleniaOY0 = new matrixForShearingOY();
    matrix *macierzPochyleniaOY = new matrix();

    matrix *macierz = new matrix();

    punkt pocz, pkt, transformedPoint, srodekObrazu;

    void zamalujPiksel(punkt &piksel, QColor &color);
    void reset();
    void czysc();
    void transformImage();
    void fillImage();
    bool czyPikselMaInnyKolor(punkt &piksel);
    QColor innyKolor(punkt &piksel);

private slots:
    void paintEvent(QPaintEvent*);
    void on_resetButton_clicked();
    void on_exitButton_clicked();
    void on_downUpSlider_valueChanged(int value);
    void on_leftRightSlider_valueChanged(int value);
    void on_slimFatSlider_valueChanged(int value);
    void on_shortTallSlider_valueChanged(int value);
    void on_rotationSlider_valueChanged(int value);
    void on_axisOXSlider_valueChanged(int value);
    void on_axisOYSlider_valueChanged(int value);
};

#endif
