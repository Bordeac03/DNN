#pragma once

#include<bits/stdc++.h>
using namespace std;



typedef vector<vector<double> > Matrice;
 class Matrix
    {

    public:

        Matrix(int x, int y);

        void Add(double n);

        static Matrix Add_st(Matrix x,double n);

        void Add(Matrix n);

        static Matrix Add_st(Matrix x,Matrix n);

        void Sub(double n);

        static Matrix Sub_st(Matrix x,double n);

        void Sub(Matrix n);

        static Matrix Sub_st(Matrix x,Matrix n);

        void Multiply(double n);

        static Matrix Multiply_st(Matrix x,double n);

        void Multiply(Matrix n);

        void Dot(Matrix n);

        static Matrix Dot_st(Matrix x,Matrix n);

        static Matrix Multiply_st(Matrix x,Matrix n);

        static Matrix transpose(Matrix x);

        void Func(double (*f)(double));

        static Matrix Func_st(Matrix x ,double (*f)(double));

        void randomize();

        static Matrix From_Array(vector<double> x);

        static vector<double> To_Array(Matrix x);

        void print();

    private:
        int rows, cols;
        Matrice matrix;
    };