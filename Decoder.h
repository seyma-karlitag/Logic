#pragma once

#include "Gate.h"
#include "output.h"

////the gate class is our inherited class

class Decoder : public Gate
{
    private:

    //our vector with gate pointer that receives outputs

        vector<Gate*> outputs;
    public:
        virtual const vector<bool> getOutput()
        {
            vector<bool> res;
            for(const auto& output : outputs)
                static_cast<Output*>(output)->setVal(false);
                
            //Our integer values ​​that take 2 inputs
            int n1 = inputs[0]->getOutput()[0];
            int n0 = inputs[1]->getOutput()[0];

            //Our output vector, which returns the index of what is true according to the position of the inputs

            static_cast<Output*>(outputs[2*n1 + n0])->setVal(true);
            for(auto& output : outputs)
                res.push_back(output->getOutput()[0]);
            return res;
        } 
        //After the decoder, we throw all of them 
        //into the output vector so that it can output the outputs.

        void addOutput(Gate* output){ outputs.push_back(output); }
};