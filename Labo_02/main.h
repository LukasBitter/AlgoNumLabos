/**
    Main - Declaration File

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
*/

#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <string>

    int main();

    /**
        Get an insertion from the user with control of minimum and maximum value.

        @param valeurMin, valeurMax (Minimum and Maximum value accepted), str (String value containing the message)
        @return double numerical value entered by the user
    */
    double saisieValeur(const double &valeurMin, const double &valeurMax, const std::string &str);

    /** Empty the Buffer */
    void viderBuffer();

#endif // MAIN_H_INCLUDED
