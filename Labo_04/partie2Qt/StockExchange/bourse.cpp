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

Bourse::Bourse(QString coursFileName, QString inflationFileName)
{
    this->cours = readCSVFile(coursFileName);
    this->inflation = readCSVFile(inflationFileName);
    calculateMaxMin();
}

Bourse::~Bourse()
{
    //dtor
}

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

void Bourse::findSteapestMoment()
{
    double maxInflation = 0;
    double previousPrice;
    int nbIt = 0;
    string smin="";
    QMap<int,double>::iterator it;

    for (it=cours.begin(); it!=cours.end();++it)
    {
        if(nbIt > 0)
        {
            if((it->second)-previousPrice > maxInflation)
            {
                maxInflation = (it->second-previousPrice)/previousPrice;
                smin=it->first;
            }
        }
        perviousPrice = it->second;
        nbIt++;
    }
    cout<< "The best moment was in "<<smin <<" => "<<maxInflation<<endl<<endl;

}

void Bourse::findCheapestMoment()
{
    /*double minvalue=10000000;
    string smin="";
    QMap<QString,double>::iterator it;

    for (it=cours.begin(); it!=cours.end();++it)
    {
        if(it->second<minvalue)
        {
            smin=it->first;
            minvalue=it->second;
        }
    }
    cout<< "The cheapest moment was in "<<smin <<" => "<<minvalue<<endl<<endl;*/
}

void Bourse::findBestPeriodToBuyAndSale()
{
    /*double inflationMax=-2;
    double inflationMin=2;
    string start=startDate(inflation);
    string timeToBuy=start;
    string timeToSale=start;
    map<string,double>::iterator it;
    map<string,double>::iterator it2;

    string timeToBuyTemp="";
    string timeToSaleTemp="";
    double inflationMinTemp=0;
    double inflationMaxTemp=0;
    double inflationSum=0;

    for (it=inflation.begin(); it!=inflation.end();++it)
    {
        timeToBuyTemp=it->first;
        timeToSaleTemp=it->first;
        inflationMinTemp=it->second;
        inflationMaxTemp=it->second;
        inflationSum=0;

        for (it2=it; it2!=inflation.end();++it2)
        {
            inflationSum+=it2->second;

            if(inflationSum>inflationMaxTemp && inflationSum>inflationMax && timeToSaleTemp.compare(timeToBuy)>0)
            {
                timeToSale=it2->first;
                inflationMax=inflationSum;
            }
            else if(inflationSum>inflationMaxTemp)
            {
                timeToSaleTemp=it2->first;
                inflationMaxTemp=inflationSum;
            }
            else if(inflationSum<inflationMinTemp && inflationSum<inflationMin && timeToBuyTemp.compare(timeToSale)<0)
            {
                timeToBuy=it2->first;
                inflationMin=inflationSum;
            }
            else if(inflationSum<inflationMinTemp)
            {
                timeToBuyTemp=it2->first;
                inflationMinTemp=inflationSum;
            }
        }
    }
    cout<<"Best time to buy = "<<timeToBuy<<endl;
    cout<<"Inflation min = "<<inflationMin<<endl<<endl;
    cout<<"Best time to sale = "<<timeToSale<<endl;
    cout<<"Inflation max = "<<inflationMax<<endl<<endl<<endl;*/
}

QString Bourse::startDate(QMap<int,double> m)
{
    /*QString startDate="2015";
    QMap<QString,double>::iterator it;
    for (it=m.begin(); it!=m.end();++it)
    {
        if(it->first.compare(startDate)<0)
        {
            startDate=it->first;
        }
    }
    return startDate;*/
}

void Bourse::displayMap(QMap<int,double> m)
{
    /*QMap<QString,double>::iterator it;

    for (it=m.begin(); it!=m.end();++it)
    {
    qDebug() << it->first << " => " << it->second << endl;
    }*/
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
