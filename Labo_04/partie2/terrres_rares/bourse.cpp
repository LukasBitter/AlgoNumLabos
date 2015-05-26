#include "bourse.h"

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <windows.h>

Bourse::Bourse(string coursFileName, string inflationFileName)
{
    this->cours = readCSVFile(coursFileName);
    this->inflation = readCSVFile(inflationFileName);
}

Bourse::~Bourse()
{
    //dtor
}

map<string,double> Bourse::readCSVFile(string filename)
{
    ifstream file(filename.c_str());
    string line;
    vector<string> v;
    map<string,double> mapToReturn;

    while(file.good())
    {
        getline(file, line, ';');
        v.push_back(line);
        getline(file, line, '\n');
        v.push_back(line);

        mapToReturn.insert(pair<string,double>(v[0],strtod(v[1].c_str(), NULL)));
        v.clear();
    }

    file.close();
    return mapToReturn;
}

void Bourse::findCheapestMoment()
{
    double minvalue=10000000;
    string smin="";
    map<string,double>::iterator it;

    for (it=cours.begin(); it!=cours.end();++it)
    {
        if(it->second<minvalue)
        {
            smin=it->first;
            minvalue=it->second;
        }
    }
    cout<< "The cheapest moment was in "<<smin <<" => "<<minvalue<<endl<<endl;
}

void Bourse::findBestPeriodToBuyAndSale()
{
    double inflationMax=-2;
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
    cout<<"Inflation max = "<<inflationMax<<endl<<endl<<endl;
}

string Bourse::startDate(map<string,double> m)
{
    string startDate="2015";
    map<string,double>::iterator it;
    for (it=m.begin(); it!=m.end();++it)
    {
        if(it->first.compare(startDate)<0)
        {
            startDate=it->first;
        }
    }
    return startDate;
}

void Bourse::displayMap(map<string,double> m)
{
    map<string,double>::iterator it;

    cout<<endl;
    for (it=m.begin(); it!=m.end();++it)
    {
    cout << it->first << " => " << it->second << endl;
    }
    cout<<endl;
}

void Bourse::displayMapCours()
{
    displayMap(this->cours);
}

void Bourse::displayMapInflation()
{
    displayMap(this->inflation);
}
