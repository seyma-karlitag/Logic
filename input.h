#ifndef INPUT_H
#define INPUT_H
#include "Gate.h"

//the gate class is our inherited class

class Input : public Gate
{
    public:

    //holding the outputs
        virtual const vector<bool> getOutput()
        {
            vector<bool> res{val};
            return res;
        }
        void setVal(const bool& val) { this->val = val;}
    private:
        bool val = false;
};


#endif