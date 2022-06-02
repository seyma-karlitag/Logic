#ifndef FLIPFLOP_H
#define FLIPFLOP_H

#include "Gate.h"

//the gate class is our inherited class

class Flipflop : public Gate
{
    public:

    //Checking if flip flop has been called before
        virtual const vector<bool> getOutput(){
            if(calculated)
                return {prev};

            //Value taken with x or previous value

            prev = inputs.back()->getOutput()[0] ^ prev;
            vector<bool> res{prev};
            
            //Since flip flop takes the previous value as input, we control it.
            calculated = true;
            return res;
        };
        void reset() { calculated = false;}
    private:
        bool prev = false;
        bool calculated = false;

};


#endif