#pragma once

#include <bits/stdc++.h>
#include "matrix.h"

class Layer
    {
    public:
        int numI,numO;
        double lr;
        Matrix w;
        Matrix bi;

        Layer(int I,int O, double learning_rate);

        Matrix feedforward(Matrix input);

        void Backpropagation(Matrix input,Matrix Error);
    };