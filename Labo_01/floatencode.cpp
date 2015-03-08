#include "floatencode.h"
#include <windows.h> //temporaire

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
FloatEncode::FloatEncode(string value)
{
    if(value.length()== BITS_TOTAL)
    {
        int j = 0;

        if(value[j]=='1')
        {
            bitset_s[0]=1;
        }
        else
        {
            bitset_s[0]=0;
        }

        j++;

        for(int i = BITS_E-1; i >= 0; i--)
        {
            if(value[j]=='1')
            {
                bitset_e[i]=1;
            }
            else
            {
                bitset_e[i]=0;
            }

            j++;
        }

        for(int i = BITS_M-1; i >= 0; i--)
        {
            if(value[j]=='1')
            {
                bitset_m[i]=1;
            }
            else
            {
                bitset_m[i]=0;
            }

            j++;
        }


    }

    this->value=getDouble();

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
    if(exp<-15)
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

FloatEncode FloatEncode::add(FloatEncode value1, FloatEncode value2)
{
    FloatEncode result(0);

    cout<<"  Le nombre 1 : "<< value1.get_s() << "|" << value1.get_e() << "|1" << value1.get_m() <<endl;
    cout<<"  Le nombre 2 : "<< value2.get_s() << "|" << value2.get_e() << "|1" << value2.get_m() <<endl;

    bitset<BITS_M+1> bitset_mcache1;
    bitset<BITS_M+1> bitset_mcache2;

    for(int i = 0; i<BITS_M; i++)
    {
        bitset_mcache1[i] = value1.bitset_m[i];
        bitset_mcache2[i] = value2.bitset_m[i];
    }
    bitset_mcache1[BITS_M] = 1;
    bitset_mcache2[BITS_M] = 1;

    while(value1.bitset_e != value2.bitset_e)
    {
        int e1 = (int)(value1.bitset_e.to_ulong());
        int e2 = (int)(value2.bitset_e.to_ulong());

        if(e1 < e2)
        {
            value1.bitset_e = bitset<BITS_E>(value1.bitset_e.to_ulong() + 1ULL);
            bitset_mcache1>>=1;
        }
        else if(e1 > e2)
        {
            value2.bitset_e = bitset<BITS_E>(value2.bitset_e.to_ulong() + 1ULL);
            bitset_mcache2>>=1;
        }
    }
    result.bitset_e = bitset<BITS_E>(value1.bitset_e.to_ulong() + 1ULL);
    cout << endl;
    cout<<"  Le nombre 1 : "<< value1.get_s() << "|" << value1.get_e() << "|" << bitset_mcache1 <<endl;
    cout<<"  Le nombre 2 : "<< value2.get_s() << "|" << value2.get_e() << "|" << bitset_mcache2 <<endl;

    int retenue = 0;
    for(int i = 0; i<BITS_M; i++)
    {
        if(bitset_mcache1[i] == 0 && bitset_mcache2[i] == 0)
        {
            result.bitset_m[i] = 0 + retenue;
            retenue = 0;
        }
        else if(bitset_mcache1[i] == 1 && bitset_mcache2[i] == 1)
        {
            result.bitset_m[i] = 0 + retenue;
            retenue = 1;
        }
        else
        {
            if(retenue == 1)
            {
                result.bitset_m[i] = 0;
                retenue = 1;
            }
            else
            {
                result.bitset_m[i] = 1;
                retenue = 0;
            }
        }
    }

    if(bitset_mcache1[BITS_M] == 1 && bitset_mcache2[BITS_M] == 1)
    {
        if(result.bitset_m[0]==1)
        {
            inc(result.bitset_m);
        }
        cout << result.bitset_m << endl;
        result.bitset_m>>=1;

        result.bitset_m[BITS_M-1] = retenue;
        cout << result.bitset_m << endl;
    }
    else if(bitset_mcache1[BITS_M] == 0 && bitset_mcache2[BITS_M] == 0 && retenue == 0)
    {
        while(result.bitset_m[BITS_M-1]!=1)
        {
            result.bitset_m<<=1;
        }
    }
    else if((bitset_mcache1[BITS_M] == 1 || bitset_mcache2[BITS_M] == 1) && retenue == 1)
    {
        if(result.bitset_m[0]==1)
        {
            inc(result.bitset_m);
        }
        result.bitset_m>>=1;

        result.bitset_m[BITS_M-1]= retenue;
    }


    cout << "  Le resultat : "<< result.get_s() << "|" << result.get_e() << "|1" << result.get_m() <<endl << endl;

    return result;
}

void FloatEncode::inc(bitset<BITS_M> m)
{
    int retenue = 1;
    for(int i = 0; i < BITS_M; i++)
    {
        if(m[i] == 1 && retenue==1)
        {
            m[i] = 0;
            retenue = 1;
        }
        else if(retenue == 1)
        {
            m[i] = retenue;
            retenue = 0;
        }
    }
}
