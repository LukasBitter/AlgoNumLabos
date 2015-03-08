#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include <windows.h>
#include <iostream>

using namespace std;


class Affichage
{
    public:
        Affichage();
        virtual ~Affichage();
        static int menuBegin();
        static int menuNotValid();
        static void encode();
        static void info();
        static void readme();
    protected:
    private:
        static void header();
        static void menu();
};

#endif // AFFICHAGE_H
