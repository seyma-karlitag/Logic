#ifndef AND_H
#define AND_H

#include "Gate.h"

//the gate class is our inherited class

class And : public Gate
{
    public:
    //holding the outputs
        virtual const vector<bool> getOutput() 
        { 
            vector<bool> res; 
            
            //The function that puts incoming inputs into and operation
            res.push_back(inputs[inputs.size() - 2]->getOutput()[0] && inputs.back()->getOutput()[0]); 
            return res;
        }
};


#endif