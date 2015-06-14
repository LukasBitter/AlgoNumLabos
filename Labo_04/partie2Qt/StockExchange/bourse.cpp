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
 * Assuming one could get better use of an investment if it is not in the highest derivate
 */
void Bourse::findSteapestMoment()
{
    double previousPrice = cours.first();
    double previousYearPrice = previousPrice;
    maxInflation = 0;
    maxYearInflation = 0;
    bestDate = 0;
    bestYear = 0;

    QMap<int,double>::iterator it;

    for (it=cours.begin()++; it!=cours.end();++it)
    {
        // Manage daily quotes
        this->inflation.insert(it.key(), it.value());
        double value = (it.value() - previousPrice) / previousPrice;
        if(value > maxInflation)
        {
            maxInflation = value;
            bestDate = it.key();
        }
        previousPrice = it.value();

        // Manage yearly quotes assuming the yearly quote is the first years day quote
        int year = QDate::fromJulianDay(it.key()).year();
        if(!this->yearlyInflation.contains(year))
        {
            this->yearlyInflation.insert(year, it.value());
            double yearValue = (it.value() - previousYearPrice) / previousYearPrice;
            if(yearValue > maxYearInflation)
            {
                maxYearInflation = yearValue;
                bestYear = year;
            }
            previousYearPrice = it.value();
        }
    }

    qDebug() << "Résutlat : " << QDate::fromJulianDay(bestDate) <<" : " << maxInflation << " / Year: " << QDate::fromJulianDay(bestDate).year();
}

/**
 * @brief Bourse::getCours
 * return quote
 * @return
 */
QMap<int, double> Bourse::getCours()
{
    return this->cours;
}

/**
 * @brief Bourse::calculateMaxMin
 * @return
 */
void Bourse::calculateMaxMin()
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

/**
 * @brief Bourse::getMaxInflation
 * @return
 */
QString Bourse::getMaxInflation()
{
    QString text = "Over the whole period, the best time to buy is on ";
    text.append(QDate::fromJulianDay(bestDate).toString());
    return text;
}

/**
 * @brief Bourse::getMaxYearInflation
 * @return
 */
QString Bourse::getMaxYearInflation()
{
    QString text = "With yearly time interval, the best year to buy is on ";
    text.append(QString::number(bestYear));
    return text;
}

/**
 * @brief Bourse::getMax
 * @return
 */
double Bourse::getMax()
{
    return this->max;
}

/**
 * @brief Bourse::getMin
 * @return
 */
double Bourse::getMin()
{
    return this->min;
}

/**
 * @brief Bourse::getSize
 * @return
 */
double Bourse::getSize()
{
    return this->size;
}
