#ifndef OR_H
#define OR_H

#include "Gate.h"

//the gate class is our inherited class

class Or : public Gate
{
    public:
        virtual const vector<bool> getOutput(){
            vector<bool> res;

            //The function that puts incoming inputs into or operation

            res.push_back(inputs[0]->getOutput()[0] || inputs[1]->getOutput()[0]);

            //get the result and return the vector
            
            return res;
        }
};


#endif