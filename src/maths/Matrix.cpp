#include "Matrix.h"

//Matrix::Matrix(const size_t cols, const size_t rows) {
//}

Matrix::Matrix(const Array2D<double>& matrix) {
    m_cols = matrix.size();
    m_rows = matrix[0].size();

    m_matrix.clear();
    m_matrix.reserve(m_cols);

    for (size_t i = 0; i < m_cols; i++) {
        Array1D<double> jGrid;
        jGrid.reserve(m_rows);

        for (size_t j = 0; i < m_rows; j++) {
            jGrid.push_back(matrix[i][j]);
        }
        m_matrix.push_back(jGrid);
    }
}

Matrix::Matrix(const Matrix& other) {
    m_cols = other.m_matrix.size();
    m_rows = other.m_matrix[0].size();

    m_matrix.clear();
    m_matrix.reserve(m_cols);

    for (size_t i = 0; i < m_cols; i++) {
        Array1D<double> jGrid;
        jGrid.reserve(m_rows);

        for (size_t j = 0; i < m_rows; j++) {
            jGrid.push_back(other.m_matrix[i][j]);
        }
        m_matrix.push_back(jGrid);
    }
}

Matrix::Matrix(const size_t cols, const size_t rows) {
    m_cols = cols;
    m_rows = rows;

    m_matrix.clear();
    m_matrix.reserve(m_cols);

    for (size_t i = 0; i < m_cols; i++) {
        Array1D<double> jGrid;
        jGrid.reserve(m_rows);

        for (size_t j = 0; j < m_rows; j++) {
            jGrid.push_back(0.0);
        }
        m_matrix.push_back(jGrid);
    }
}

Matrix& Matrix::operator=(const Array2D<double>& copy) {
    m_cols = copy.size();
    m_rows = copy[0].size();

    m_matrix.clear();
    m_matrix.reserve(m_cols);

    for (size_t i = 0; i < m_cols; i++) {
        Array1D<double> jGrid;
        jGrid.reserve(m_rows);

        for (size_t j = 0; i < m_rows; j++) {
            jGrid.push_back(copy[i][j]);
        }
        m_matrix.push_back(jGrid);
    }
    return *this;
}

Matrix& Matrix::operator=(const Matrix& copy) {
    if (this == &copy) return *this;

    m_cols = copy.m_matrix.size();
    m_rows = copy.m_matrix[0].size();

    m_matrix.clear();
    m_matrix.reserve(m_cols);

    for (size_t i = 0; i < m_cols; i++) {
        Array1D<double> jGrid;
        jGrid.reserve(m_rows);

        for (size_t j = 0; i < m_rows; j++) {
            jGrid.push_back(copy.m_matrix[i][j]);
        }
        m_matrix.push_back(jGrid);
    }

    return *this;
}