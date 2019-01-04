#ifndef MCHAIN_H_INCLUDED
#define MCHAIN_H_INCLUDED

#include <cstddef>
#include <string>
#include <array>
#include <memory>
#include "trmatrix.h"
#include "randgen.h"

class MChain {
    const RandGen rg;
    const TrMatrix<double> tr_matrix;
    std::size_t curr_state, prev_state;

    void advance();
public:
    MChain(double* const& transition_matrix,
           std::string* const& transition_names,
           std::size_t state_cnt,
           std::size_t state_init = 0);
    ~MChain();
    std::size_t getCurrState();
    std::string getCurrStateName();
    std::size_t nextState();
    std::size_t nextState(std::string& state_name);
    std::size_t operator()();
    std::size_t operator()(std::string& state_name);

    friend void mchain_tests();
};


#endif // MCHAIN_H_INCLUDED
