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

Matrix::Matrix ()
    {
    size_x_ = 0;
    size_y_ = 0;

    matrix_ = new int*[1];
    for (int i = 0; i < 1; i++)
        matrix_[i] = new int [1];

    matrix_[0][0] = 0;
    }

Matrix::Matrix (const Matrix &matrix1)
    {
    size_x_ = matrix1.size_x_;
    size_y_ = matrix1.size_y_;

    matrix_ = new int*[size_y_];
    for (int i = 0; i < size_y_; i++)
        matrix_[i] = new int [size_x_];

    for (int y = 0; y < size_y_; y++)
        for (int x = 0; x < size_x_; x++)
            matrix_[y][x] = matrix1.matrix_[y][x];
    }

Matrix::~Matrix ()
    {
    for (int i = 0; i < size_y_; i++)
        delete[] matrix_[i];
    }

Matrix& Matrix::operator= (const Matrix &matrix)
    {
    this->~Matrix();

    size_x_ = matrix.size_x_;
    size_y_ = matrix.size_y_;

    matrix_ = new int*[size_y_];
    for (int i = 0; i < size_y_; i++)
        matrix_[i] = new int [size_x_];


    for (int y = 0; y < size_y_; y++)
        for (int x = 0; x < size_x_; x++)
            matrix_[y][x] = matrix.matrix_[y][x];

    return *this;
    }
