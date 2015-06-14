#ifndef BOURSE_H
#define BOURSE_H

using namespace std;

#include <QMap>
#include <QString>

class Bourse
{
    public:
        Bourse(QString cours);
        virtual ~Bourse();

        QMap<int, double> readCSVFile(QString filename);

        void findCheapestMoment();
        void findBestPeriodToBuyAndSale();
        void findSteapestMoment();

        QString startDate(QMap<int,double> m);
        QMap<int, double> getCours();

        void calculateMaxMin();
        double getMin();
        double getMax();
        double getSize();
        QString getMaxInflation();
        QString getMaxYearInflation();


    protected:
    private:
        QMap<int,double> cours;
        QMap<int,double> inflation;
        QMap<int,double> yearlyInflation;

        double maxYearInflation;
        double maxInflation;
        int bestDate;
        int bestYear;
        double max;
        double min;
        double size;

};

#endif // BOURSE_H
