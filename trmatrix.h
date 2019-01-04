#ifndef TRMATRIX_H_INCLUDED
#define TRMATRIX_H_INCLUDED

#include <cstddef>
#include <string>
#include "flatmatrix.h"


template <class T>
class TrMatrix : public FlatMatrix<T> {
    const std::unique_ptr<std::string[]> tr_names;
public:
    const std::size_t total_states;

    TrMatrix(T* const& arr,
             std::string* const& transition_names,
             std::size_t state_cnt);
    std::string getStateName(std::size_t state) const;

    friend void trmatrix_tests();
};

#include "trmatrix.tpp"

#endif // TRMATRIX_H_INCLUDED
