#include "include/ANN.h"

using namespace NN;

NeuralNetwork::NeuralNetwork(int I, int H, int O, double learning_rate):
            numI(I),
            numH(H),
            numO(O),
            lr(learning_rate),
            Input(I,H,learning_rate)
            {
                Layer Hidden(this->numH,this->numO,this->lr);
                Hidden_Layers.push_back(Hidden);
            };

Matrix NeuralNetwork::feedforward(Matrix input)
{
    Matrix Output = this->Input.feedforward(input);
    for(list<Layer>::iterator it = Hidden_Layers.begin(); it != Hidden_Layers.end(); it++)
        Output = (*it).feedforward(Output);

    return Output;
}

void NeuralNetwork::Backpropagation(Matrix input,Matrix target)
{
    list<Matrix> Outputs;
    Outputs.push_back(this->Input.feedforward(input));
    for(list<Layer>::iterator it = Hidden_Layers.begin(); it != Hidden_Layers.end(); it++)
        Outputs.push_back((*it).feedforward(Outputs.back()));
    Matrix Output = Outputs.back();
    Outputs.pop_back();
    Matrix Error = Matrix::Sub_st(target,Output);
    list<Layer>::reverse_iterator  it = Hidden_Layers.rbegin();
    while(it != prev(Hidden_Layers.rend()))
    {
        (*it).Backpropagation(Outputs.back(),Error);
        Outputs.pop_back();
        it++;
        Error = Matrix::Dot_st(Matrix::transpose((*prev(it)).w),Error);
    }


     (Hidden_Layers.front()).Backpropagation(Outputs.back(),Error);
     Outputs.pop_back();
     Error = Matrix::Dot_st(Matrix::transpose(Hidden_Layers.front().w),Error);
     this->Input.Backpropagation(input,Error);
}

void NeuralNetwork::AddLayer()
{
    Layer Hidden(this->numH,this->numH,this->lr);
    Hidden_Layers.push_front(Hidden);
}

