#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <limits>
#include <cmath>


template <class T>
TrMatrix<T>::TrMatrix(T* const& arr,
                      std::string* const& transition_names,
                      std::size_t state_cnt) :
                      FlatMatrix<T>(arr, state_cnt, state_cnt),
                      tr_names(std::make_unique<std::string[]>(state_cnt)),
                      total_states(state_cnt)
{
    static const char* const err_msg[] = {
        "TrMatrix<T>::TrMatrix: legal transition matrix values are between '0.0' and '1.0'",
        "TrMatrix<T>::TrMatrix: probabilities in each row of the transition matrix must add up to '1.0'"
    };

    for (size_t i = 0; i < state_cnt; i++) {
        double row_sum = 0;

        for (size_t j = 0; j < state_cnt; j++) {
            auto curr_value = this->at(i, j);

            if (curr_value < 0 || curr_value > 1.0) {
                throw std::invalid_argument(err_msg[0]);
            }

            row_sum += curr_value;
        }

        if (std::fabs(row_sum - 1.0) > std::numeric_limits<double>::epsilon()) {
            throw std::invalid_argument(err_msg[1]);
        }

        tr_names[i] = transition_names[i];
        std::cout << tr_names[i] << '\n';
    }
}

template <class T>
std::string TrMatrix<T>::getStateName(std::size_t state) const
{
    if (state >= this->rows) {
        throw std::out_of_range("TrMatrix<T>::getStateName: out of bounds access detected");
    }

    return tr_names[state];
}
