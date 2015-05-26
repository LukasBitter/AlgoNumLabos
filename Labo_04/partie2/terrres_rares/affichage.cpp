/**
    Affichage - Implementation File
    Purpose: Add printing methods for a better user interaction

    @author Equipe 6 (Bitter Lukas, Da Mota Marques Fabio Manuel, Divernois Margaux, Visinand Steve)
*/

#include "affichage.h"
#include <fstream>
#include <sstream>

// Constructor
Affichage::Affichage()
{
    //ctor
}

// Destructor
Affichage::~Affichage()
{
    //dtor
}
// Print the header
void Affichage::header()
{
    system("cls");
    cout<<"*************************************************"<<endl;
    cout<<"**        Numerical Algorithms - Labo 4        **"<<endl;
    cout<<"**            Cost of (rare) metals            **"<<endl;
    cout<<"*************************************************"<<endl;
    cout<<endl<<endl;
}

// Print the menu
void Affichage::menu()
{
    cout<<"  1. Rare metal (last 5 years)"<<endl;
    cout<<"  2. Gold (last 20 years)"<<endl;
    cout<<"  3. Read me"<<endl;
    cout<<"  4. Quit"<<endl;
    cout<<endl;
}

// First user interaction
int Affichage::menuBegin()
{
    int answer = 0;

    header();
    menu();
    cout<<"  Enter a menu between 1 and 4: ";
    cin>>answer;
    return answer;
}

// Repeat user interaction in case of wrong entry
int Affichage::menuNotValid()
{
    int answer = 0;

    header();
    menu();
    cout<<"  Invalid command. Try again. "<<endl;
    cout<<"  Enter a menu between 1 and 4: ";
    cin>>answer;
    return answer;
}


// Read the file readme.txt and print it
void Affichage::readme()
{
    system("cls");
    ifstream in("./readme.txt");

    if(!in)
    {
        cout << "  Can not open input file.\n";
    }
    else
    {
        char str[255];

        while(in)
        {
            in.getline(str, 255);  // delim defaults to '\n'
            if(in) cout << str << endl;
        }
        in.close();
    }
    system("pause");
}

// Ask the user to press a key to continue
void Affichage::pressKey()
{
    cout << endl << "  -> Press a key to continue..." << endl;
    getch();
}
