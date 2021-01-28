#include "player.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QApplication>
#include "mainwindow.h"

#include <QMap>
#include <QFileInfo>
int main(int argc, char *argv[])
{
    QApplication EditorApp(argc, argv);


    MainWindow w;
	return EditorApp.exec();
}

