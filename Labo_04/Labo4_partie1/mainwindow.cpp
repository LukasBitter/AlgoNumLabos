#include <QtWidgets>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    graph = new FonctionsGraphique(this);
    setCentralWidget(graph);
    setWindowTitle(tr("labo4_partie1"));

    resize(800,600);

    createActions();
    createMenus();
}
void MainWindow::createActions()
{
    printAct = new QAction(tr("&Imprimer"), this);
    printAct->setShortcut(tr("Ctrl+P"));
    printAct->setStatusTip(tr("Imprimer"));
    connect(printAct, SIGNAL(triggered()), graph, SLOT(print()));
}
void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&Fichier"));
    fileMenu->addAction(printAct);
}
MainWindow::~MainWindow()
{

}
