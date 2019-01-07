#ifndef RANDGEN_H_INCLUDED
#define RANDGEN_H_INCLUDED

struct RandGenState;

class RandGen {
    RandGenState *rgs;
public:
    RandGen();
    ~RandGen();
    unsigned int randUInt() const;
    double randDbl() const;
};


#endif // RANDGEN_H_INCLUDED
