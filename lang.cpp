
#include "lang.h"
#include <iostream>
#include <string>
#include <cmath>

using std::string;

Lang::Lang(string language, int n_gram)
{
    n = n_gram;
    len = n*asccii_range;
    freq = new int[len];
    compute_freq(language);
}

Lang::~Lang()
{
    delete[] freq;
}

void Lang::print()
{
    for (int i=0; i<len; i++)
        std::cout << freq[i] << std::endl;
}

void Lang::compute_freq(string language)
{
    for (int i=0; i < language.size()-n; i++)
    {
        int index=0;
        for (int j=0; j<n; j++)
        {
            index += power(language[i+j], n-j-1); // n-j-1 because we have to include to the 0 power
        }
        freq[index]++;
    }
}

int power(int c, int b)
{
    return static_cast<int>(std::pow(static_cast<float>(c), 2.0));
}