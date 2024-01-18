#include "matrix.hpp"

Matrix::Matrix()
{
    mat[0][0] = 1;
    mat[0][1] = 0;
    mat[1][0] = 0;
    mat[1][1] = 1;
}

int Matrix::get(int i, int j) const
{
    return mat[i][j];
}

void Matrix::set(int i, int j, int val)
{
    mat[i][j] = val;
}

Matrix Matrix::operator*(const Matrix &other) const
{
    Matrix result;
    result.set(0,0,0);
    result.set(1,1,0);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                result.mat[i][j] = (result.mat[i][j] + ((long long)mat[i][k] * other.get(k, j)) % 100000000) % 100000000;

            }
        }
    }
    return result;
}