#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    approximationPI = new Integral(new FonctionA(), 0, 1);
}

MainWindow::~MainWindow()
{
    delete approximationPI;
    delete ui;
}

void MainWindow::on_pushButtonSimpson_clicked()
{
    long double eval = (long double)4.0 * approximationPI->approximateSimpson(400);
    QString s = QString::number(eval, 'f', 18);
    qDebug() << s;
    ui->labelSimpsonResult->setText(s);
}

void MainWindow::on_pushButtonMiddlePoint_clicked()
{
    long double eval = (long double)4.0 * approximationPI->approximateMiddlePoint(10000000);
    QString s = QString::number(eval, 'f', 18);
    qDebug() << s;
    ui->labelResultMiddlePoint->setText(s);
}
