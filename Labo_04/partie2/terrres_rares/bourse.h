#ifndef BOURSE_H
#define BOURSE_H

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <windows.h>

using namespace std;

class Bourse
{
    public:
        Bourse(string cours, string inflation);
        virtual ~Bourse();

        map<string,double> readCSVFile(string filename);

        void findCheapestMoment();
        void findBestPeriodToBuyAndSale();

        string startDate(map<string,double> m);

        void displayMap(map<string,double> m);
        void displayMapCours();
        void displayMapInflation();

    protected:
    private:
        map<string,double> cours;
        map<string,double> inflation;
};

#endif // BOURSE_H
