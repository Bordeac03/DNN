#pragma once
#include <bits/stdc++.h>
#include "matrix.h"
#include "Layer.h"

namespace NN
{
    class NeuralNetwork
    {
    public:

        NeuralNetwork(int I, int H, int O, double learning_rate);

        Matrix feedforward(Matrix input);

        void Backpropagation(Matrix input,Matrix target);

        void AddLayer();
    private:
        int numI, numH, numO;
        double lr;
        Layer Input;
        list<Layer> Hidden_Layers;
    };
}
