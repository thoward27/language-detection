#pragma once

#include <string>

class Lang
{
private:
    /** The valid ascii range, to compute length of frequencies. 
     */
    const int ascii_range = 27;
    /** n signifies what n_gram analysis to provide.
     */
    const int n;
    // Len is the length of the interal frequency array. 
    const int len;
    // The internal frequency array. 
    int* freq;

    // Computes the index for each character, uses ascii base. 
    int power(int c, int b);


    void compute_freq(std::string language);
public:
    Lang(std::string language, int n=3);
    ~Lang();

    void print();
    int operator[](int i);
};