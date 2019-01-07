#include "mchain/randgen.h"
#include <random>

#ifdef __MINGW32__
#include <ctime>
#endif

struct RandGenState {
    //mingw32's implementation of std::random_device
    //uses a deterministic seed and it's bad for testing
#ifndef __MINGW32__
    std::random_device rand_dev;
#endif
    std::mt19937 rand_uint;
    std::uniform_real_distribution<double> uniform_dbl;

    RandGenState()
    {
#ifdef __MINGW32__
        rand_uint = std::mt19937(std::time(0));
#else
        rand_uint = std::mt19937(rand_dev());
#endif

        uniform_dbl = std::uniform_real_distribution<double>(0.0, 1.0);
    }
};


RandGen::RandGen()
{
    rgs = new RandGenState();
}

RandGen::~RandGen()
{
    delete rgs;
}

unsigned int RandGen::randUInt() const
{
    return rgs->rand_uint();
}

double RandGen::randDbl() const
{
    return rgs->uniform_dbl(rgs->rand_uint);
}
