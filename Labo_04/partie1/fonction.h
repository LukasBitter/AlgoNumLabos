/**
    Fonction - Header File

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)

    last update : 03.05.2015
*/

#ifndef FONCTION_H
#define FONCTION_H
class Fonction
{
private:
    double h;
public:
    Fonction();
    virtual ~Fonction()=0;

    virtual double f(double x)=0;
    double f_derivate(double x);
    double f_derivateSecond(double x);

    void seth(double h);
};

#endif // FONCTION_H
