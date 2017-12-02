#pragma once

#include <string>

class Lang
{
private:
    const int ascii_range = 27;
    const int n;
    const int len;
    int* freq;

    int power(int c, int b);
    void compute_freq(std::string language);
public:
    Lang(std::string language, int n=3);
    ~Lang();

    void print();
    int operator[](int i);
};