#ifndef OUTPUT_H
#define OUTPUT_H

#include "Gate.h"

////the gate class is our inherited class

class Output : public Gate
{
    public:
    //holding the outputs
        virtual const vector<bool> getOutput()
        {
            vector<bool> res{val};
            return res;
        }
    //set function that takes outputs

        void setVal(const bool& val) { this->val = val;}
    private:
        bool val = false;
};


#endif