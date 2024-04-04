#pragma once

#include <vector>

/// <summary>
/// 1D Array Template
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
using Array1D = std::vector<T>;

/// <summary>
/// 2D Array Template
/// </summary>
/// <typeparam name="T"></typeparam>
template <typename T>
using Array2D = std::vector<std::vector<T>>;

class Matrix {
public:
    Matrix(const Array2D<double>& matrix);
    Matrix(const Matrix& other);
    Matrix(const size_t cols = 1, const size_t rows = 1);
    ~Matrix() {};

    // ----- ASSIGNMENT OPERATOR -----

    Matrix& operator=(const Array2D<double>& copy);
    Matrix& operator=(const Matrix& copy);

private:
    size_t m_cols, m_rows;

    Array2D<double> m_matrix;

};