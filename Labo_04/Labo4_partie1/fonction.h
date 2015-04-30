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
