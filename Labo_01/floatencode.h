#ifndef FLOATENCODE_H
#define FLOATENCODE_H

#include <iostream>
#include <math.h>
#include <bitset>

using namespace std;

// Constants
#define BITS_TOTAL 17
#define BITS_E 5
#define BITS_S 1
#define BITS_M (BITS_TOTAL - BITS_E - BITS_S)
#define CONST_D 15

class FloatEncode
{
    public:
        // Constructors/destructors
        FloatEncode(double _value);
        virtual ~FloatEncode();

        // Public Accessors
        bitset<BITS_S> get_s();
        bitset<BITS_E> get_e();
        bitset<BITS_M> get_m();
        double getDouble();

        // Public methods
        bitset<BITS_TOTAL> getBitset();

    protected:
    private:

        // Private attributes
        double value;
        bitset<BITS_E> bitset_e;
        bitset<BITS_S> bitset_s;
        bitset<BITS_M> bitset_m;

        // Private methods
        void calcE();
        void calcS();
        bool checkSpecial(double value);

};

#endif // FLOATENCODE_H
