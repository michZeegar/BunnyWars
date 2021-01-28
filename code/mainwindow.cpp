#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget * parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    Interface * field= new Interface();
}

MainWindow::~MainWindow() {
    delete ui;
}
