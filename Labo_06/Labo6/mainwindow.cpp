#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Champs Vectoriel");
    champsVectoriel = new Champs();
    setCentralWidget(champsVectoriel);
}

MainWindow::~MainWindow()
{

}
