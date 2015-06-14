/**
    MainWindow - Implementation File

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
    @date 14.06.2015
*/

#include "mainwindow.h"

//Constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle("Champs Vectoriel");
    champsVectoriel = new Champs();
    setCentralWidget(champsVectoriel);
}

//Destructor
MainWindow::~MainWindow()
{
    delete champsVectoriel;
}
