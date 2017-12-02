#pragma once

#include <string>

class Lang
{
private:
    int asccii_range = 27;
    int n;
    int len;
    int* freq;

    void compute_freq(std::string language);
public:
    Lang(std::string language, int n=3);
    ~Lang();

    void print();
};