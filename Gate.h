#ifndef GATE_H
#define GATE_H
#include <string>
#include <vector>
using namespace std;

//Basa Class

class Gate
{
    public:
    //our vector holding the outputs
    
        virtual const vector<bool> getOutput() = 0;
        void addInput(Gate* input)
        {
            inputs.push_back(input);
        }

        //definition of get and set functions named after doors

        void setName(string& name) { this->name = name;}
        const string& getName() const { return name;}
    protected:
        vector<Gate*> inputs;
        //and, or vb. string holding names

        string name;
};
#endif











