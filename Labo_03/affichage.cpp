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
    cout<<"**        Numerical Algorithms - Labo 3        **"<<endl;
    cout<<"**Find all roots of a system of linear equations*"<<endl;
    cout<<"*************************************************"<<endl;
    cout<<endl<<endl;
}

// Print the menu
void Affichage::menu()
{
    cout<<"  1. Tester la matrice du prof (200x200)"<<endl;
    cout<<"  2. Tester la matrice easy (3x3)"<<endl;
    cout<<"  3. Read me"<<endl;
    cout<<"  4. End"<<endl;
    cout<<endl;
}

// First user interaction
int Affichage::menuBegin()
{
    int answer = 0;

    header();
    menu();
    cout<<"  Enter your menu choice (1-4): ";
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
    cout<<"  Enter your menu choice (1-4): ";
    cin>>answer;
    return answer;
}

// Check the value entered by the user and return it
double Affichage::saisieValeur(const double &valeurMin, const double &valeurMax)
{
    double valeurDeRetour= valeurMin-1;
    while(true)
    {

        cout << "   Give a value between " << valeurMin << " and " << valeurMax << ": ";
        cin >> valeurDeRetour;

        if(cin.eof() || cin.bad())
        {
            cerr << "  An internal error happened." << endl;
            if(cin.eof() || valeurDeRetour <= valeurMin || valeurDeRetour >=valeurMax)
            {
                break;
            }
            viderBuffer();
            continue;
        }
        else if(cin.fail() || valeurDeRetour <= valeurMin ||valeurDeRetour >=valeurMax)
        {
            cerr << "  ERROR, incorrect value." << endl;
            viderBuffer();
            continue;
        }
        break;
    }
    return valeurDeRetour;
}

// Empty the buffer
void Affichage::viderBuffer()
{
    cin.clear();
    cin.seekg(0, ios::end);

    if(!cin.fail())
    {
        cin.ignore(numeric_limits<streamsize>::max());
    }
    else
    {
        cin.clear();
    }
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
