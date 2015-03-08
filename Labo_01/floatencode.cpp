#include "floatencode.h"

/*------------------------------------------------------------------*\
|*	            Constructors / Destructors							*|
\*------------------------------------------------------------------*/

FloatEncode::FloatEncode(double _value) : value(_value)
{
    if(!checkSpecial(_value))
    {
        calcE();
        calcS();
        //calcDouble();
    }
}

FloatEncode::~FloatEncode()
{
    //dtor
}

/*------------------------------------------------------------------*\
|*							Public Accessors				    	*|
\*------------------------------------------------------------------*/

bitset<BITS_S> FloatEncode::get_s()
{
    return bitset_s;
}

bitset<BITS_E> FloatEncode::get_e()
{
    return bitset_e;
}

bitset<BITS_M> FloatEncode::get_m()
{
    return bitset_m;
}

double FloatEncode::getDouble()
{
    //calcul e
    int e = (int)(bitset_e.to_ulong());

    //calcul M
    //take the hidden bit
    bitset<BITS_M+1> bitset_mcache;

    for(int i = 0; i<BITS_M; i++)
    {
        bitset_mcache[i] = bitset_m[i];
    }

    if(e==0){
        bitset_mcache[BITS_M] = 0;
    }
    else{
        bitset_mcache[BITS_M] = 1;
    }

    //calcul m
    int m = (int)(bitset_mcache.to_ulong());
    double M = m / pow(2, bitset_mcache.size());

    //determinate x
    double x;
    x = M*pow(2, e - CONST_D);

    //sign of the value (S)
    if(bitset_s[0]==1)
    {
        x = x*(-1);
    }

    return x;
}

/*------------------------------------------------------------------*\
|*							Public methods			    			*|
\*------------------------------------------------------------------*/

bitset<BITS_TOTAL> FloatEncode::getBitset()
{
    // Declaration du nombre encodé
    bitset<BITS_TOTAL> x;

    // Décalage et copie de bitset_e
    for(int i = BITS_M; i<BITS_E+BITS_M; i++)
    {
        x[i] = bitset_e[i-BITS_M];
    }

    for(int i = 0; i<BITS_M; i++)
    {
        x[i] = bitset_m[i];
    }

    x[BITS_TOTAL-1] = bitset_s[0];
    return x;
}

/*------------------------------------------------------------------*\
|*							Private methods			    			*|
\*------------------------------------------------------------------*/

void FloatEncode::calcE()
{
    int exp=0;
    double M = fabs(value)/pow(2, exp);
    while(M<0.5 || M>=1)
    {
        if(M<=0.5)
            exp--;
        else
            exp++;
        M = fabs(value)/pow(2, exp);
    }
    if(exp<0)
        bitset_e = bitset<BITS_E>(0);
    else
        bitset_e = bitset<BITS_E>(exp+CONST_D);
    bitset_m = bitset<BITS_M>(M*pow(2, BITS_M));
    bitset_m<<=1;
}

void FloatEncode::calcS()
{
    if(value<0)
        bitset_s[0] = 1;
    else
        bitset_s[0] = 0;
}

bool FloatEncode::checkSpecial(double value)
{
    if (value == 0)
    {
        bitset_s[0] = 0;
        bitset_e = bitset<BITS_E>(0);
        bitset_m = bitset<BITS_M>(0);
        return true;
    }
    return false;
}

FloatEncode FloatEncode::add(FloatEncode value)
{
    cout << "This.bitset_e : " << this->bitset_e << endl;
    cout << "value.bitset_e : " << value.bitset_e << endl;

    while(this->bitset_e != value.bitset_e)
    {
//        if(this->bitset_e < value.bitset_e)
//        {
//            this.>bitset_e++;
//        }
//        else
//        {
//            value.bitset_e++;
//        }
    }
    cout << "This.bitset_e : " << this->bitset_e << endl;
    cout << "value.bitset_e : " << value.bitset_e << endl;

    return value;
}
