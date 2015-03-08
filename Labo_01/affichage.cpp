#include "affichage.h"
#include "floatencode.h"
#include <fstream>

Affichage::Affichage()
{
    //ctor
}

Affichage::~Affichage()
{
    //dtor
}

void Affichage::header()
{
    system("cls");
    cout<<"*************************************************"<<endl;
    cout<<"**         Algorithmes numeriques Labo 1       **"<<endl;
    cout<<"**   Codage d'un nombre flottant sur 17 bits   **"<<endl;
    cout<<"*************************************************"<<endl;
    cout<<endl<<endl;
}

void Affichage::menu()
{
    cout<<"  1. Encodage d'un nombre"<<endl;
    cout<<"  2. Decodage d'un nombre"<<endl;
    cout<<"  3. Additionner deux nombres"<<endl;
    cout<<"  4. Informations"<<endl;
    cout<<"  5. Readme"<<endl;    cout<<"  9. Fin"<<endl;
    cout<<endl;
}

int Affichage::menuBegin()
{
    int rep = 0;

    header();
    menu();
    cout<<"  Saisissez un choix du menu (1 a 9): ";
    cin>>rep;
    return rep;
}

int Affichage::menuNotValid()
{
    int rep = 0;

    header();
    menu();
    cout<<"  Commande non valide. Recommencez. "<<endl;
    cout<<"  Saisissez un choix du menu (1 a 9): ";
    cin>>rep;
    return rep;
}

void Affichage::info()
{
    header();
    cout<<"  info"<<endl;
    cout<<endl;
    system("pause");
}

void Affichage::encode()
{
    double num = 0;

    header();
    cout<<"  Saisissez un nombre a encoder: " << endl;

    cin>>num;

    FloatEncode userFloat(num);

    cout<<"  s = "<<userFloat.get_s()<<endl;
    cout<<"  e = "<<userFloat.get_e()<<endl;
    cout<<"  m = "<<userFloat.get_m()<<endl<<endl;


    if(!userFloat.get_e().all())
    {
        cout<<"  Le nombre decode vaut: "<<userFloat.getDouble()<<endl<<endl;
    }
    else
    {
        if(userFloat.get_s().all())
        {
            cout<<"  Le nombre decode vaut moins l'infini car il depasse la limite du codage"<<endl<<endl;
        }
        else
        {
            cout<<"  Le nombre decode vaut l'infini car il depasse la limite du codage"<<endl<<endl;
        }

    }

    system("pause");
}

void Affichage::decode()
{
    string num;

    header();
    cout<<"                                 *****************" << endl;
    cout<<"  Saisissez un nombre a decoder: ";
    cin>>num;

    // ici faire un test si num est bien un nombre
    FloatEncode userFloat(num);
    cout<<"  Le nombre encode vaut: "<<userFloat.getBitset()<<endl<<endl;
    cout<<"  s = "<<userFloat.get_s()<<endl;
    cout<<"  e = "<<userFloat.get_e()<<endl;
    cout<<"  m = "<<userFloat.get_m()<<endl<<endl;
    cout<<"  Le nombre decode vaut: "<<userFloat.getDouble()<<endl<<endl;
    system("pause");
}

void Affichage::addition()
{
    double num1 = 0;
    double num2 = 0;

    header();
    cout<<"  Saisissez un premier nombre: ";
    cin>>num1;
    cout<<"  Saisissez un second nombre: ";
    cin>>num2;

    FloatEncode userFloat1(num1);
    FloatEncode userFloat2(num2);
    FloatEncode result(0);

    result = FloatEncode::calculate(userFloat1, userFloat2);

    cout<< "  " << num1 << " + " << num2 << " = " <<result.getDouble()<<endl<<endl;
    system("pause");
}

void Affichage::readme()
{

 ifstream in("./readme.txt");

  if(!in) {
    cout << "Cannot open input file.\n";
  }
  else {

      char str[255];

      while(in) {
        in.getline(str, 255);  // delim defaults to '\n'
        if(in) cout << str << endl;
      }
      in.close();
  }
  system("pause");
}

