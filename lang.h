#pragma once

#include <string>

class Lang
{
private:
    const int asccii_range = 27;
    const int n;
    const int len;
    int* freq;

    void build_table();
    void compute_freq(std::string language);
public:
    Lang(std::string language, int n=3);
    ~Lang();

    void print();
    int operator[](int i);
};