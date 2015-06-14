/**
    Bourse - Implementation File
    Purpose: manage stock quotes

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)

    last update : 14.06.2015
*/
#include "bourse.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <windows.h>
#include <QString>
#include <QVector>
#include <QDebug>
#include <QFile>
#include <QDate>

/**
 * @brief Bourse::Bourse
 * @param coursFileName
 * @param inflationFileName
 */
Bourse::Bourse(QString coursFileName)
{
    this->cours = readCSVFile(coursFileName);
    calculateMaxMin();
    findSteapestMoment();
}

Bourse::~Bourse()
{
    //dtor
}

/**
 * @brief Bourse::readCSVFile
 * Reads a csv name and returns a map containing the two vlaues in the expected columns
 * @param filename
 * The name of the input file
 * @return
 */
QMap<int,double> Bourse::readCSVFile(QString filename)
{
    QFile file(filename);
    QString line;
    QMap<int,double> map;

    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            line = in.readLine(0);
            QStringList splitLine = line.split(';');
            QDate date = QDate::fromString(splitLine[0],"dd'.'MM'.'yyyy");
            map.insert(date.toJulianDay(),splitLine[1].toDouble());
        }
        file.close();
    }

    return map;
}

/**
 * @brief Bourse::findSteapestMoment
 * Finds the interval with the steapest interval (derivate)
 * Assuming one could get better use of an investment if it is not
 */
void Bourse::findSteapestMoment()
{
    double maxInflation = 0;
    double previousPrice = cours.first();
    int bestDate = 0;

    QMap<int,double>::iterator it;

    for (it=cours.begin()++; it!=cours.end();++it)
    {
        //map.insert(date.toJulianDay(),splitLine[1].toDouble());
        this->inflation.insert(it.key(), it.value());
        double value = (it.value() - previousPrice) / previousPrice;
        if(value > maxInflation)
        {
            maxInflation = value;
            bestDate = it.key();
        }
        previousPrice = it.value();
    }

    qDebug() << "Résutlat : " << QDate::fromJulianDay(bestDate) <<" : " << maxInflation;
}

void Bourse::displayMapCours()
{
    displayMap(this->cours);
}

void Bourse::displayMapInflation()
{
    displayMap(this->inflation);
}

QMap<int, double> Bourse::getCours()
{
    return this->cours;
}

double Bourse::calculateMaxMin()
{
    this->max = 0;
    this->min = 0;
    this->size = 0;

    QMap<int, double>::iterator i;
    for (i = cours.begin(); i != cours.end(); ++i)
    {
        this->size++;
        if(i.value() > max) {
            this->max = i.value();
        }
        else if(i.value() < min) {
            this->min = i.value();
        }
    }
}

double Bourse::getMax()
{
    return this->max;
}

double Bourse::getMin()
{
    return this->min;
}

double Bourse::getSize()
{
    return this->size;
}
