#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "champs.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Champs* champsVectoriel;
};

#endif // MAINWINDOW_H
