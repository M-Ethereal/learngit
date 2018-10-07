#include "cameracontrol.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CameraControl w;
    w.show();

    return a.exec();
}
