/**
    Fonction - Full Fonction Declaration File
    Fonction is a Virtual Class.
    Purpose: Will be used to create different functions.

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
*/

#ifndef FONCTION_H
#define FONCTION_H

class Fonction
{
    public:
        Fonction() {}
        virtual ~Fonction() {}

        virtual double f(double x) = 0;
    protected:
    private:
};

#endif // FONCTION_H
