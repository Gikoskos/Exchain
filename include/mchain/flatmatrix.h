#ifndef FLATMATRIX_H_INCLUDED
#define FLATMATRIX_H_INCLUDED

#include <memory>
#include <cstddef>


template <class T>
class FlatMatrix {
protected:
    std::unique_ptr<T[]> fmat;
public:
    const std::size_t rows, cols;
    const std::size_t length;

    FlatMatrix(T* const& arr, std::size_t rows, std::size_t cols);
    T operator[](std::size_t index) const;
    T at(std::size_t row, std::size_t col) const;
    std::size_t getIndex(std::size_t row, std::size_t col) const;

    friend void flatmatrix_tests();
};

#include "flatmatrix.tpp"

#endif // FLATMATRIX_H_INCLUDED
