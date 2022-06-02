#ifndef NOT_H
#define NOT_H

#include "Gate.h"


class Not : public Gate
{
    public:

    //holding the outputs

        virtual const vector<bool> getOutput()
        {
            vector<bool> res;
            auto b = inputs[0]->getOutput()[0];

            //Let's assign the value of the incoming input to the result vector, we return it
            
            res.push_back(!b);
            return res;
        }
};


#endif