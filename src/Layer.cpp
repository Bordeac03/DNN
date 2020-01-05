#include "include/Layer.h"


double Sigmoid(double x)
    {
        return 1 / (1 + exp(-x));
    }

double Dsigmoid(double y) /// y = Sigmoid(x);
    {
        return y*(1-y);
    }

Layer::Layer(int I,int O, double learning_rate):
    numI(I),
    numO(O),
    lr(learning_rate),
    w(O,I),
    bi(O,1)
{
    this->w.randomize();
    this->bi.randomize();
}

Matrix Layer::feedforward(Matrix input)
{
    Matrix Output(this->numO,this->numI);
    Output = Matrix::Dot_st(this->w,input);
    Output.Add(this->bi);
    Output.Func(&Sigmoid);

    return Output;
}

void Layer::Backpropagation(Matrix input,Matrix Error)
{
    Matrix Output(this->numO,this->numI);
    Output = Matrix::Dot_st(this->w,input);
    Output.Add(this->bi);
    Output.Func(&Sigmoid);

    Matrix Gradient = Matrix::Func_st(Output,Dsigmoid);
    Gradient.Multiply(Error);
    Gradient.Multiply(this->lr);

    Matrix w_delta = Matrix::Dot_st(Gradient,Matrix::transpose(input));

    this->w.Add(w_delta);
    this->bi.Add(Gradient);
}