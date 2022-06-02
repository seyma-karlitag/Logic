#include <iostream>
#include <vector>
#include <fstream>

//Defining header files

#include "And.h"
#include "Gate.h"
#include "Decoder.h"
#include "Flipflop.h"
#include "input.h"
#include "Not.h"
#include "Or.h"
#include "output.h"


std::vector<std::string> split(std::string s)
{
    ////our function that splits strings and assigns them to vector

    std::vector<std::string> res;
    auto it = s.find(" ");
    while(it != std::string::npos)
    {
        std::string temp = s.substr(0,it);
        res.push_back(temp);
        s = s.substr(it + 1);
        it = s.find(" ");
    }

    if(s != "")
        res.push_back(s);

    return res;
}

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
//----------------------Main Menu---------------------------------------------
//----------------------------------------------------------------------------
//----------------------------------------------------------------------------

int main()
{      
    //Defining class vectors

    std::vector<Gate*> components,outputs;
    std::vector<Input*> inputs;
    std::vector<Flipflop*> flipflops;
    std::vector<std::vector<bool>> results;

    //Opening the input file

    std::ifstream circuit("circuit.txt");
    std::string line;

    //performs the operation of reading line
    // data from the file and breaking it down with the function

    while (getline(circuit,line))
    {
        std::vector<std::string> temp = split(line);

        //Creating Input class dynamic if the first name is input

        if(temp[0] == "INPUT")
        {
            for(int i = 1;i < temp.size();i++)
            {
                Input* inp = new Input();
                inp->setName(temp[i]);

                //assigning all read values ​​to the components vector

                components.push_back(inp);
                inputs.push_back(inp);
            }
        }
        
        //Creating Input class dynamic if the first name is output

        else if(temp[0] == "OUTPUT")
        {
            for(int i = 1;i < temp.size();i++)
            {
                Output* out = new Output();
                out->setName(temp[i]);

                //assigning all read values ​​to the components vector

                components.push_back(out);
                outputs.push_back(out);
            }
        }

        else if(temp[0] == "AND")
        {
            auto a = new And();

            //Getting the output name for and

            a->setName(temp[1]);
            for(int i = 0;i < components.size();i++)

            //Reading line-by-line data from the file and splitting it with the split function
                if(components[i]->getName() == temp[2])
                {
                    a->addInput(components[i]);
                    break;
                }
            for(int i = 0;i < components.size();i++)
                if(components[i]->getName() == temp[3])
                {
                    a->addInput(components[i]);
                    break;
                }
            //assigning received values ​​to components vectors
            components.push_back(a);
        }
        else if(temp[0] == "OR")
        {
            Or* o = new Or();

            //Getting the output name for or
            //Its name is assigned to the input of the Or class

            o->setName(temp[1]);
            for(int i = 0;i < components.size();i++)

            //We take 2 and 3 indexes as inputs
                if(components[i]->getName() == temp[2])
                {
                    o->addInput(components[i]);
                    break;
                }
            for(int i = 0;i < components.size();i++)
                if(components[i]->getName() == temp[3])
                {
                    o->addInput(components[i]);
                    break;
                }
            components.push_back(o);
        }
        else if(temp[0] == "NOT")
        {
            Not* n = new Not();
            n->setName(temp[1]);

             //Getting the output name for NOT
            //Its name is assigned to the input of the NOT class

            for(int i = 0;i < components.size();i++)
                if(components[i]->getName() == temp[2])
                {
                    //the last index is taken as input

                    n->addInput(components[i]);
                    break;
                }
            components.push_back(n);
        }
        else if(temp[0] == "FLIPFLOP")
        {
            Flipflop* flipflop = new Flipflop();
            flipflop->setName(temp[1]);
            for(int i = 0;i < components.size();i++)

            //the last index is taken as input
                if(components[i]->getName() == temp[2])
                {
                    flipflop->addInput(components[i]);
                    break;
                }
            components.push_back(flipflop);
            flipflops.push_back(flipflop);
        }
        else if(temp[0] == "DECODER")
        {
            //The last index input is taken and the inputs
            // are determined according to the previous input.
            
            Decoder* decoder = new Decoder();
            for(int i = 0;i < components.size();i++)
                if(components[i]->getName() == temp[5])
                {
                    decoder->addInput(components[i]);
                    break;
                }
            for(int i = 0;i < components.size();i++)
                if(components[i]->getName() == temp[6])
                {
                    decoder->addInput(components[i]);
                    break;
                }
            for(const auto& output : outputs)
                decoder->addOutput(output);
            components.push_back(decoder);
        }
    }

    //Closing the circuit.txt file

    circuit.close();

    //Opening the input.txt file

    std::ifstream input("input.txt");

    //Reading line-by-line data from the file
    // and splitting it with the split function

    while(getline(input,line))
    {
        auto temp = split(line);
        for(int i = 0;i < temp.size();i++)
            static_cast<Input*>(inputs[i])->setVal(temp[i] == "1");
        for(const auto& flipflop : flipflops)
            flipflop->reset();
        for(const auto& b : components.back()->getOutput())
            cout << (b ? "1 " : "0 ");
        cout << "\n";
    }
    



    return 0;
}
