#include "mchain/mchain.h"
#include <iostream>
#include <stdexcept>

using std::size_t;


MChain::MChain(double* const& transition_matrix,
               std::string* const& transition_names,
               size_t state_cnt,
               size_t state_init) :
               rg(),
               tr_matrix(transition_matrix, transition_names, state_cnt),
               curr_state(state_init),
               prev_state(state_init)
{
    if (state_init >= state_cnt) {
        throw std::invalid_argument("MChain: initial states must be between '0' and 'state_cnt - 1'");
    }
}

MChain::~MChain()
{

}

void MChain::advance()
{
    double probability = rg.randDbl(),
           left = 0, right;
    std::size_t i = tr_matrix.getIndex(curr_state, 0),
                row_end = i + tr_matrix.total_states;

    for (; i < row_end; i++) {
        right = left + tr_matrix[i];

        if (probability >= left && probability <= right) {
            prev_state = curr_state;
            curr_state = i % tr_matrix.rows;
            break;
        }

        left = right;
    }
}

std::size_t MChain::nextState()
{
    advance();

    return curr_state;
}

std::size_t MChain::nextState(std::string& state_name)
{
    advance();

    state_name = getCurrStateName();
    return curr_state;
}

std::size_t MChain::operator()()
{
    return nextState();
}

std::size_t MChain::operator()(std::string& state_name)
{
    return nextState(state_name);
}

std::size_t MChain::getCurrState()
{
    return curr_state;
}

std::string MChain::getCurrStateName()
{
    return tr_matrix.getStateName(curr_state);
}
