#include "include/matrix.h"


Matrix::Matrix(int x, int y):
            rows(x),
            cols(y)
            {
                srand(time(NULL));
                vector<double> row;
                for(int i = 0; i < this->rows; i++)
                    {
                        for(int j = 0; j < this->cols; j++)
                            row.push_back(0);
                        this->matrix.push_back(row);
                    }
            }
void Matrix::Add(double n)
        {
            for(int i = 0; i < this->rows; i++)
                for(int j = 0; j < this->cols; j++)
                    this->matrix[i][j] += n;
        }
Matrix Matrix::Add_st(Matrix x,double n)
        {
            Matrix result(x.rows,x.cols);
            for(int i = 0; i < result.rows; i++)
                for(int j = 0; j < result.cols; j++)
                    result.matrix[i][j] = x.matrix[i][j] + n;
            return result;
        }
void Matrix::Add(Matrix n)
        {
            for(int i = 0; i < this->rows; i++)
                for(int j = 0; j < this->cols; j++)
                    this->matrix[i][j] += n.matrix[i][j];
        }
Matrix Matrix::Add_st(Matrix x, Matrix n)
        {
            Matrix result(x.rows,x.cols);
            for(int i = 0; i < result.rows; i++)
                for(int j = 0; j < result.cols; j++)
                    result.matrix[i][j] = x.matrix[i][j] + n.matrix[i][j];
            return result;
        }
void Matrix::Sub(double n)
        {
            for(int i = 0; i < this->rows; i++)
                for(int j = 0; j < this->cols; j++)
                    this->matrix[i][j] -= n;
        }
Matrix Matrix::Sub_st(Matrix x,double n)
        {
            Matrix result(x.rows,x.cols);
            for(int i = 0; i < result.rows; i++)
                for(int j = 0; j < result.cols; j++)
                    result.matrix[i][j] = x.matrix[i][j] - n;
            return result;
        }
void Matrix::Sub(Matrix n)
        {
            for(int i = 0; i < this->rows; i++)
                for(int j = 0; j < this->cols; j++)
                    this->matrix[i][j] -= n.matrix[i][j];
        }
Matrix Matrix::Sub_st(Matrix x, Matrix n)
        {
            Matrix result(x.rows,x.cols);
            for(int i = 0; i < result.rows; i++)
                for(int j = 0; j < result.cols; j++)
                    result.matrix[i][j] = x.matrix[i][j] - n.matrix[i][j];
            return result;
        }
void Matrix::Multiply(double n)
        {
            for(int i = 0; i < this->rows; i++)
                for(int j = 0; j < this->cols; j++)
                    this->matrix[i][j] *= n;
        }
Matrix Matrix::Multiply_st(Matrix x,double n)
        {
            Matrix result(x.rows,x.cols);
            for(int i = 0; i < result.rows; i++)
                for(int j = 0; j < result.cols; j++)
                    result.matrix[i][j] = x.matrix[i][j] * n;
            return result;
        }
Matrix Matrix::Multiply_st(Matrix x,Matrix n)
        {
            Matrix result(x.rows,x.cols);
            for(int i = 0; i < result.rows; i++)
                for(int j = 0; j < result.cols; j++)
                    result.matrix[i][j] = x.matrix[i][j] * n.matrix[i][j];
            return result;
        }
void Matrix::Multiply(Matrix n)
        {
            Matrix result(this->rows,this->cols);
            for(int i = 0; i < result.rows; i++)
                for(int j = 0; j < result.cols; j++)
                    result.matrix[i][j] = this->matrix[i][j] * n.matrix[i][j];
            this->matrix = result.matrix;
        }
void Matrix::Dot(Matrix n)
        {
            Matrix result(this->rows,n.cols);
            if(this->cols != n.rows)
                {cout << "Eroare!Matrice!" << endl; // Catch Err
                return ;}

            for(int i = 0; i < result.rows; i++)
                for(int j = 0; j < result.cols; j++)
                    {
                        double sum = 0;
                        for(int k = 0; k < this->cols; k++)
                            sum += this->matrix[i][k] * n.matrix[k][j];
                        result.matrix[i][j] = sum;
                    }
            this->matrix = result.matrix;
        }
Matrix Matrix::Dot_st(Matrix x,Matrix n)
        {
            Matrix result(x.rows,n.cols);
            if(x.cols != n.rows)
                {cout << "Eroare!Matrice!" << endl; // Catch Err
                return result;}

            for(int i = 0; i < result.rows; i++)
                for(int j = 0; j < result.cols; j++)
                    {
                        double sum = 0;
                        for(int k = 0; k < x.cols; k++)
                            sum += x.matrix[i][k] * n.matrix[k][j];
                        result.matrix[i][j] = sum;
                    }
            return result;
        }
Matrix Matrix::transpose(Matrix x)
        {
            Matrix result(x.cols,x.rows);
            for(int i = 0; i < x.rows; i++)
                for(int j = 0; j < x.cols; j++)
                    result.matrix[j][i] = x.matrix[i][j];
            return result;
        }
void Matrix::Func(double (*f)(double))
        {
            for(int i = 0; i < this->rows; i++)
                for(int j = 0; j < this->cols; j++)
                    this->matrix[i][j] = f(this->matrix[i][j]);
        }
Matrix Matrix::Func_st(Matrix x,double (*f)(double))
        {
            Matrix result(x.rows,x.cols);
            for(int i = 0; i < result.rows; i++)
                for(int j = 0; j < result.cols; j++)
                    result.matrix[i][j] = f(x.matrix[i][j]);
            return result;
        }
void Matrix::randomize()
        {
            for(int i = 0; i < this->rows; i++)
                for(int j = 0; j < this->cols; j++)
                    this->matrix[i][j] = (double)(rand()%100/100.);
        }
void Matrix::print()
{
    for(int i = 0; i < this->rows; i++)
            {
                for(int j = 0; j < this->cols; j++)
                    cout << this->matrix[i][j] << " ";
                cout << endl;
            }
    cout << endl;
}
Matrix Matrix::From_Array(vector<double> x)
{
    Matrix result(x.size(),1);
    for(int i = 0; i < result.rows; i++)
            result.matrix[i][0]=x[i];
    return result;
}
vector<double> Matrix::To_Array(Matrix x)
{
    vector<double> result;
    for(int i = 0; i < x.rows; i++)
            result.push_back(x.matrix[i][0]);
    return result;
}