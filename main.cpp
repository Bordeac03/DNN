#include <bits/stdc++.h>
#include "src/include/ANN.h"
#include "src/include/matrix.h"

using namespace std;
using namespace NN;

double f(double x)
{
    return x+2;
}

int main()
{

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 3);


    NeuralNetwork brain(2,2,1,0.2);
    brain.AddLayer();

    vector <vector<double> >input;
    vector<double> in;
    vector<double> output;
    vector<double> out;
    vector <vector<double> > target;
    Matrix Input(2,1);
    Matrix Target(1,1);

    in.push_back(1);
    in.push_back(0);
    input.push_back(in);

    in.erase(in.begin(),in.end());
    in.push_back(0);
    in.push_back(1);
    input.push_back(in);

    in.erase(in.begin(),in.end());
    in.push_back(0);
    in.push_back(0);
    input.push_back(in);

    in.erase(in.begin(),in.end());
    in.push_back(1);
    in.push_back(1);
    input.push_back(in);

    out.push_back(1);
    target.push_back(out);
    target.push_back(out);

    out.erase(out.begin(),out.end());
    out.push_back(0);
    target.push_back(out);
    target.push_back(out);


    for(int i = 0; i < 1000000; i++)
    {
        int k = dis(gen);
        Input = Matrix::From_Array(input[k]);
        //Input.print();
        Target = Matrix::From_Array(target[k]);
        //Target.print();
        brain.Backpropagation(Input,Target);

    }
    for(int i = 0; i < 4; i++)
    {
        Input = Matrix::From_Array(input[i]);
        //Input.print();
        Target = Matrix::From_Array(target[i]);
        Target.print();
        brain.feedforward(Input).print();
    }


}