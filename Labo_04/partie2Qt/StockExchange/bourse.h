#ifndef BOURSE_H
#define BOURSE_H

using namespace std;

#include <QMap>
#include <QString>

class Bourse
{
    public:
        Bourse(QString cours, QString inflation);
        virtual ~Bourse();

        QMap<int, double> readCSVFile(QString filename);

        void findCheapestMoment();
        void findBestPeriodToBuyAndSale();
        void findSteapestMoment();

        QString startDate(QMap<int,double> m);
        QMap<int, double> getCours();

        void displayMap(QMap<int,double> m);
        void displayMapCours();
        void displayMapInflation();

        double calculateMaxMin();
        double getMax();
        double getMin();
        double getSize();

    protected:
    private:
        QMap<int,double> cours;
        QMap<int,double> inflation;

        double min;
        double max;
        double size;
};

#endif // BOURSE_H
