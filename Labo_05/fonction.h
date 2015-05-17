/**
    Fonction - Full Fonction Declaration File
    Fonction is a Virtual Class.
    Purpose: Will be used to create different functions.

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
    @date 2015-04-28
*/

#ifndef FONCTION_H
#define FONCTION_H

class Fonction
{
    public:
        /** Default constructor */
        Fonction() {}
        /** Default destructor */
        virtual ~Fonction() {}

        /**
            Returns the result of the equation with a specified x

            @param x The value of the "unknown" value of the equation
            @return The result of the solved equation
        */
        virtual long double f(long double x) = 0;
    protected:
    private:
};

#endif // FONCTION_H
