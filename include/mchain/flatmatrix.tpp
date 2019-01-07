#include <iostream>
#include <stdexcept>


template <class T>
FlatMatrix<T>::FlatMatrix(T* const& arr,
                          std::size_t rows,
                          std::size_t cols) :
                          rows(rows),
                          cols(cols),
                          length(rows * cols)
{
    if (!rows && !cols) {
        throw std::invalid_argument("FlatMatrix<T>::FlatMatrix: can't create a matrix with 0 rows and 0 columns");
    }

    if (!length) {
        throw std::invalid_argument("FlatMatrix<T>::FlatMatrix: can't create a vector with this class");
    }

    fmat = std::make_unique<T[]>(length);

    for (size_t i = 0; i < length; i++) {
        fmat[i] = arr[i];
    }
}

template <class T>
T FlatMatrix<T>::operator[](std::size_t index) const
{
    if (index >= length) {
        throw std::out_of_range("FlatMatrix<T>::operator[]: out of bounds access detected");
    }

    return fmat[index];
}

template <class T>
T FlatMatrix<T>::at(std::size_t row, std::size_t col) const
{
    return (*this)[getIndex(row, col)];
}

template <class T>
std::size_t FlatMatrix<T>::getIndex(std::size_t row, std::size_t col) const
{
    if (row >= rows) {
        throw std::out_of_range("FlatMatrix<T>::getIndex: row should be less than the matrix's rows");
    }

    if (col >= cols) {
        throw std::out_of_range("FlatMatrix<T>::getIndex: col should be less than the matrix's columns");
    }

    return row * cols + col;
}
