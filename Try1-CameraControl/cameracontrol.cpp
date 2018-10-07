#include "cameracontrol.h"
#include "ui_cameracontrol.h"


CameraControl::CameraControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CameraControl)
{
    ui->setupUi(this);

    capture = NULL;
    timer = new QTimer(this);
    img = new QImage();

    cout << "START" << endl;

    /* signal and slots */
    connect( timer, SIGNAL(timeout()), this, SLOT(frameProcessing()) );
}

CameraControl::~CameraControl()
{
    closeCamera();
    delete ui;
}

void CameraControl::openCamera()//open the camera and start the timer
{
    capture = cvCreateCameraCapture(-1);
    //capture.open(0);
    counter = 0;
    if(!capture)
    {
        cout << "Camera cannot open!";
    }
    else
    {
        cout << "Camera is on!";
        timer->start(33);
    }
}

void CameraControl::frameProcessing()
{
    frame = cvQueryFrame(capture);//return IplImage*

    if(!frame)
    {
        cout << "Cannot get frame!";
    }
    else
    {
        ui->label->setPixmap(QPixmap::fromImage( (*(IplImageToQImage(frame))).mirrored(true,false) ));
    }
}

void CameraControl::closeCamera()
{
    timer->stop();
    cvReleaseCapture(&capture);
    ui->label->clear();
}

QImage* CameraControl::IplImageToQImage(IplImage *img)
{
    QImage *image;
    cvCvtColor(img,img,CV_BGR2RGB);
    uchar* imgData = (uchar*)img->imageData;
    image = new QImage(imgData,img->width,img->height,QImage::Format_RGB888);
    return image;
}

void CameraControl::on_ButtonOpen_clicked()
{
     openCamera();
}

void CameraControl::on_ButtonClose_clicked()
{
    closeCamera();
}

void CameraControl::on_ButtonScreenShot_clicked()
{
    if(ui->label->text().isEmpty())
    {
        ui->label->setText("Can not take pictures \nbecause the camera is closed \nOpen the camera to take pictures=>");
    }
    else
    {
        counter ++;

        QString temp = QString("%1.jpg").arg(counter);
        QString strFilename = "/home/ethereal/myPictures/IMG_" + temp;

        img = IplImageToQImage(frame);
        img->save(strFilename, "JPG", 100);
    }
}
