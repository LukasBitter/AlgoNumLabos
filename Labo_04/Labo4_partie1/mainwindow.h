#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "fonctionsgraphique.h"

class QAction;
class QMenu;
class QToolBar;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void createActions();
    void createMenus();

    QMenu *fileMenu;
    QAction *printAct;

    FonctionsGraphique* graph;
};

#endif // MAINWINDOW_H
