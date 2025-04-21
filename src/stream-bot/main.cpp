#include "widgets/mainwindow.h"

#include <QApplication>

#include <media-controller/mediaplaylist.h>

int main(int argc, char *argv[])
{
    try
    {
        QApplication a(argc, argv);

        MediaPlaylist playlist;

        MainWindow w;
        w.show();

        return a.exec();
    }
    catch(...)
    {
    }
}
