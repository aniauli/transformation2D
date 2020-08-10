#include "mywindow.h"
#include "ui_mywindow.h"

MyWindow::MyWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MyWindow)
{
    ui->setupUi(this);

    szer = ui->rysujFrame->width();
    wys = ui->rysujFrame->height();
    pocz.x = ui->rysujFrame->x();
    pocz.y = ui->rysujFrame->y();

    img = new QImage(":/stitch.png");
    T = new QImage(szer, wys, QImage::Format_RGB32);
    podstawa = new QImage(":/stitch.png");
    srodekObrazu.x = (int)szer/2;
    srodekObrazu.y = (int)wys/2;

    colorCzysc.setRgb(255, 255, 255, 255);
    czerwony.setRgb(255,0,0,255);
}

void MyWindow::paintEvent(QPaintEvent*)
{
    QPainter p(this);
    p.drawImage(pocz.x, pocz.y, *img);
}

MyWindow::~MyWindow()
{
    delete ui;
}

void MyWindow::on_resetButton_clicked()
{
    reset();
    update();
}

void MyWindow::on_exitButton_clicked()
{
    qApp->quit();
}

void MyWindow::on_downUpSlider_valueChanged(int value)
{
    currentTy = -(value - valueTy0);
    valueTy0 = value;
    macierzPrzesuniecia->setTxTy(0, currentTy);
    srodekObrazu.y += currentTy;
    *macierz = macierzPrzesuniecia->multiplyByMatrix(*macierz);
    transformImage();
}

void MyWindow::on_leftRightSlider_valueChanged(int value)
{
    currentTx = value - valueTx0;
    valueTx0 = value;
    macierzPrzesuniecia->setTxTy(currentTx, 0);
    srodekObrazu.x += currentTx;
    *macierz = macierzPrzesuniecia->multiplyByMatrix(*macierz);
    transformImage();
}

void MyWindow::on_slimFatSlider_valueChanged(int value)
{
    currentSx = (double) value / valueSx0;
    valueSx0 = value;
    macierzTmpPlus->setTxTy(srodekObrazu.x, srodekObrazu.y);
    macierzTmpMinus->setTxTy(-srodekObrazu.x, -srodekObrazu.y);
    macierzSkalowania0->setSxSy(currentSx, 1);
    *macierzSkalowania = macierzSkalowania0->composition(*macierzTmpPlus, *macierzTmpMinus);
    *macierz = macierzSkalowania->multiplyByMatrix(*macierz);
    transformImage();
}

void MyWindow::on_shortTallSlider_valueChanged(int value)
{
    currentSy = (double) value / valueSy0;
    valueSy0 = value;
    macierzTmpPlus->setTxTy(srodekObrazu.x, srodekObrazu.y);
    macierzTmpMinus->setTxTy(-srodekObrazu.x, -srodekObrazu.y);
    macierzSkalowania0->setSxSy(1, currentSy);
    *macierzSkalowania = macierzSkalowania0->composition(*macierzTmpPlus, *macierzTmpMinus);
    *macierz = macierzSkalowania->multiplyByMatrix(*macierz);
    transformImage();
}

void MyWindow::on_rotationSlider_valueChanged(int value)
{
    currentAlpha = (value - valueAlpha0) * PI/180;
    valueAlpha0 = value;
    macierzTmpPlus->setTxTy(srodekObrazu.x, srodekObrazu.y);
    macierzTmpMinus->setTxTy(-srodekObrazu.x, -srodekObrazu.y);
    macierzRotacji0->setAlpha(currentAlpha);
    *macierzRotacji = macierzRotacji0->composition(*macierzTmpPlus, *macierzTmpMinus);
    *macierz = macierzRotacji->multiplyByMatrix(*macierz);
    transformImage();
}

void MyWindow::on_axisOXSlider_valueChanged(int value)
{
    currentShx = value - valueShx0;
    valueShx0 = value;
    macierzTmpPlus->setTxTy(srodekObrazu.x, srodekObrazu.y);
    macierzTmpMinus->setTxTy(-srodekObrazu.x, -srodekObrazu.y);
    macierzPochyleniaOX0->setShx(currentShx);
    *macierzPochyleniaOX = macierzPochyleniaOX0->composition(*macierzTmpPlus, *macierzTmpMinus);
    *macierz = macierzPochyleniaOX->multiplyByMatrix(*macierz);
    transformImage();
}

void MyWindow::on_axisOYSlider_valueChanged(int value)
{
    currentShy = value - valueShy0;
    valueShy0 = value;
    macierzTmpPlus->setTxTy(srodekObrazu.x, srodekObrazu.y);
    macierzTmpMinus->setTxTy(-srodekObrazu.x, -srodekObrazu.y);
    macierzPochyleniaOY0->setShy(currentShy);
    *macierzPochyleniaOY = macierzPochyleniaOY0->composition(*macierzTmpPlus, *macierzTmpMinus);
    *macierz = macierzPochyleniaOY->multiplyByMatrix(*macierz);
    transformImage();
}

void MyWindow::czysc()
{
    punkt pkt;
    colorCzysc.setRgb(255, 255, 255, 255);
    for(pkt.y = 0; pkt.y < wys; pkt.y ++)
    {
        for(pkt.x = 0; pkt.x < szer; pkt.x ++)
        {
            zamalujPiksel(pkt, colorCzysc);
        }
    }
    update();
}

void MyWindow::reset()
{
    currentTx = 0;
    currentTy = 0;
    currentSx = 1;
    currentSy = 1;
    currentShx = 0;
    currentShy = 0;
    currentAlpha = 0;

    valueTx0 = srodekTranslacjiSlider;
    valueTy0 = srodekTranslacjiSlider;
    valueSx0 = 1.0;
    valueSy0 = 1.0;
    valueShx0 = srodekPochyleniaSlider;
    valueShy0 = srodekPochyleniaSlider;
    valueAlpha0 = srodekRotacjiSlider;

    ui->downUpSlider->setValue(srodekTranslacjiSlider);
    ui->leftRightSlider->setValue(srodekTranslacjiSlider);
    ui->slimFatSlider->setValue(srodekSkalowaniaSlider);
    ui->shortTallSlider->setValue(srodekSkalowaniaSlider);
    ui->rotationSlider->setValue(srodekRotacjiSlider);
    ui->axisOXSlider->setValue(srodekPochyleniaSlider);
    ui->axisOYSlider->setValue(srodekPochyleniaSlider);

    macierz = new matrix();

    srodekObrazu.x = (int)szer/2;
    srodekObrazu.y = (int)wys/2;
    img = new QImage(":/stitch.png");
}

void MyWindow::transformImage()
{
    *T = *podstawa;
    czysc();

    for(pkt.y = 0; pkt.y < wys; pkt.y ++)
    {
        for(pkt.x = 0; pkt.x < szer; pkt.x ++)
        {
            pktColor = T->pixelColor(pkt.x, pkt.y);
            transformedPoint = macierz->muliplyMatrixByPoint(pkt);
            zamalujPiksel(transformedPoint, pktColor);
        }
    }
    //fillImage();
    update();
}

void MyWindow::fillImage(){
    for(pkt.y = 1; pkt.y < wys-1; pkt.y ++)
    {
        for(pkt.x = 1; pkt.x < szer-1; pkt.x ++)
        {
            if(img->pixelColor(pkt.x, pkt.y) == colorCzysc /*&& czyPikselMaInnyKolor(pkt) == true*/){
                QColor newColor = innyKolor(pkt);
                zamalujPiksel(pkt, newColor);
            }
        }
    }
}

bool MyWindow::czyPikselMaInnyKolor(punkt &piksel)
{
    QColor kolor = img->pixelColor(piksel.x, piksel.y);
    QColor kolorSasiada[8];

    kolorSasiada[0] = img->pixelColor(piksel.x - 1, piksel.y - 1);
    kolorSasiada[1] = img->pixelColor(piksel.x - 1, piksel.y);
    kolorSasiada[2] = img->pixelColor(piksel.x, piksel.y - 1);
    kolorSasiada[3] = img->pixelColor(piksel.x + 1, piksel.y);
    kolorSasiada[4] = img->pixelColor(piksel.x, piksel.y + 1);
    kolorSasiada[5] = img->pixelColor(piksel.x - 1, piksel.y + 1);
    kolorSasiada[6] = img->pixelColor(piksel.x + 1, piksel.y - 1);
    kolorSasiada[7] = img->pixelColor(piksel.x + 1, piksel.y + 1);

    if(kolor != kolorSasiada[0] && kolor != kolorSasiada[1] && kolor != kolorSasiada[2] &&
       kolor != kolorSasiada[3] && kolor != kolorSasiada[4] && kolor != kolorSasiada[5] &&
       kolor != kolorSasiada[6] && kolor != kolorSasiada[7])
    {
        return true;
    }
    else
        return false;
}

QColor MyWindow::innyKolor(punkt &piksel)
{
    QColor innyKolor;
    QColor kolorSasiada[8];

    kolorSasiada[0] = img->pixelColor(piksel.x - 1, piksel.y - 1);
    kolorSasiada[1] = img->pixelColor(piksel.x - 1, piksel.y);
    kolorSasiada[2] = img->pixelColor(piksel.x, piksel.y - 1);
    kolorSasiada[3] = img->pixelColor(piksel.x + 1, piksel.y);
    kolorSasiada[4] = img->pixelColor(piksel.x, piksel.y + 1);
    kolorSasiada[5] = img->pixelColor(piksel.x - 1, piksel.y + 1);
    kolorSasiada[6] = img->pixelColor(piksel.x + 1, piksel.y - 1);
    kolorSasiada[7] = img->pixelColor(piksel.x + 1, piksel.y + 1);

    innyKolor.setRed(0.125 * (kolorSasiada[0].red() + kolorSasiada[1].red() + kolorSasiada[2].red() +
            kolorSasiada[3].red() + kolorSasiada[4].red() + kolorSasiada[5].red() +
            kolorSasiada[6].red() + kolorSasiada[7].red()));
    innyKolor.setGreen(0.125 * (kolorSasiada[0].green() + kolorSasiada[1].green() + kolorSasiada[2].green() +
            kolorSasiada[3].green() + kolorSasiada[4].green() + kolorSasiada[5].green() +
            kolorSasiada[6].green() + kolorSasiada[7].green()));
    innyKolor.setBlue(0.125 * (kolorSasiada[0].blue() + kolorSasiada[1].blue() + kolorSasiada[2].blue() +
            kolorSasiada[3].blue() + kolorSasiada[4].blue() + kolorSasiada[5].blue() +
            kolorSasiada[6].blue() + kolorSasiada[7].blue()));

    return innyKolor;
}

void MyWindow::zamalujPiksel(punkt &piksel, QColor &color)
{
    unsigned char *ptr;
    ptr = img->bits();
    int skladowaRed = 4*piksel.x + szer*4*piksel.y + 2;
    int skladowaGreen = skladowaRed - 1;
    int skladowaBlue = skladowaRed - 2;

    if ((piksel.x>=0)&&(piksel.y>=0)&&(piksel.x<szer)&&(piksel.y<wys))
    {
            ptr[skladowaRed]= color.red();
            ptr[skladowaGreen] = color.green();
            ptr[skladowaBlue] = color.blue();
    }
}














