
#include "lang.h"
#include <iostream>
#include <string>
#include <cmath>

using std::string;

int power(int c, int b)
{
    // Returns a static cast int from the power function. 
    return static_cast<int>(std::pow(static_cast<float>(c), b));
}

void Lang::build_table()
{
    table = new int[256]();
    // Handle Spaces
    table[' '] = 1;
    
    // Handle a-z
    int c = 2;
    for (int i='a'; i<='z'; i++)
        table[i] = c++;
    
}

Lang::Lang(string language, int n_gram)
{
    n = n_gram; // N-Gram setting (default 3)
    len = power(asccii_range, n); // Range is n*n n_gram times
    freq = new int[len]; // Frequency array
    compute_freq(language); // Fill the frequency array
}

Lang::~Lang()
{
    delete[] freq;
    delete[] table;
}

void Lang::print()
{
    for (int i=0; i<len; i++)
        std::cout << freq[i] << std::endl;
}


void Lang::compute_freq(string language)
{
    for (int i=0; i < static_cast<int>(language.size())-n; i++)
    {
        int index=0;
        for (int j=0; j<n; j++)
        {
            index += power(language[i+j], n-j-1); // n-j-1 because we have to include to the 0 power
        }
        freq[index]++;
    }
}

int Lang::operator[](int i)
{
    return freq[i];
}
