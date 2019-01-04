#include <iostream>
#include <random>
#include <cassert>
#include <stdexcept>
#include "mchain.h"

#define ARR2D_COLS(x) (sizeof((x)[0]) / sizeof((x)[0][0]))
#define ARR2D_ROWS(x) (sizeof((x)) / sizeof((x)[0]))

int main()
{
    double arr[][3] = {
        { 0.9,     0.05,     0.05},
        { 0.8,      0.1,      0.1},
        { 0.5,      0.0,      0.5}
    };
    std::string names[] = {"sleep", "PHP", "food"};

    try {
        MChain x(&arr[0][0], names, ARR2D_COLS(arr), 0);
        int max_tries = 40;
        std::cout << "Running simulation M.A.K.I.S. " << max_tries << " tries\n";
        std::cout << "Initial state = (" << x.getCurrStateName() << ", " << x.getCurrState() << ")\n";
        for (int i = 0; i < max_tries; i++) {
            x();
            std::cout << "Current state = (" << x.getCurrStateName() << ", " << x.getCurrState() << ")\n";
        }

    } catch (const std::exception& e) {
        std::cout << e.what() << '\n';
    }


    return 0;
}
