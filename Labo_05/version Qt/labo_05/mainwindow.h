#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "integral.h"
#include "fonctiona.h"
#include "fonction.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Integral* approximationPI;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButtonSimpson_clicked();

    void on_pushButtonMiddlePoint_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
