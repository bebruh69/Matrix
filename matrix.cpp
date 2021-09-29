#include "matrix.h"

Matrix::Matrix (int size_x, int size_y, initializer_list<initializer_list<int>> matrix)
    {
    size_x_ = size_x;
    size_y_ = size_y;

    matrix_ = new int*[size_y_];
    for (int i = 0; i < size_y_; i++)
        matrix_[i] = new int [size_x_];

    int y = 0, x = 0;

    for (auto row: matrix)
        {
        for (auto elem: row)
            {
            matrix_[y][x] = elem;
            x++;
            }
        x = 0;
        y++;
        }
    }

Matrix::Matrix (int size_x, int size_y, int** matrix)
    {
    size_x_ = size_x;
    size_y_ = size_y;

    matrix_ = new int*[size_y_];
    for (int i = 0; i < size_y_; i++)
        matrix_[i] = new int [size_x_];

    for (int y = 0; y < size_y_; y++)
        for (int x = 0; x < size_x_; x++)
            matrix_[y][x] = matrix[y][x];
    }

Matrix::Matrix (int size_x, int size_y)
    {
    size_x_ = size_x;
    size_y_ = size_y;

    matrix_ = new int*[size_y_];
    for (int i = 0; i < size_y_; i++)
        matrix_[i] = new int [size_x_];

    for (int y = 0; y < size_y_; y++)
        for (int x = 0; x < size_x_; x++)
            matrix_[y][x] = 0;
    }
