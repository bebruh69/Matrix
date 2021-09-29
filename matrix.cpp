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
