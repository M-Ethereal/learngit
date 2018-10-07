#ifndef CAMERACONTROL_H
#define CAMERACONTROL_H

#include <QWidget>
#include "opencv2/opencv.hpp"
#include <qlabel.h>
#include <iostream>
#include <qtimer.h>
#include <qbytearray.h>
#include <qstring.h>
#include <qpixmap.h>

using namespace std;
using namespace cv;

namespace Ui {
class CameraControl;
}

class CameraControl : public QWidget
{
    Q_OBJECT

public:
    explicit CameraControl(QWidget *parent = 0);
    ~CameraControl();
    
private slots:
    void openCamera();
    void frameProcessing();
    void closeCamera();
    QImage* IplImageToQImage(IplImage*);
    void on_ButtonOpen_clicked();

    void on_ButtonClose_clicked();

    void on_ButtonScreenShot_clicked();

private:
    Ui::CameraControl *ui;
    QTimer *timer;
    QImage *img;
    CvCapture *capture;
    IplImage *frame;
    int counter;
};

#endif // CAMERACONTROL_H
