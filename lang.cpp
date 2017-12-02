
#include "lang.h"
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

using std::string;

int power(int c, int b)
{
    // Returns a static cast int from the power function. 
    return static_cast<int>(std::pow(static_cast<float>(c), b));
}

struct VALS_TABLE
{
    // Setting all chars to 0 means for any valid ascii character we can filter and decide 
    // if we do want to use it, or not just by asking is the lookup value > 0. 
    int arr[256] = {-2};
    VALS_TABLE()
    {
        // Skips
        arr['\n'] = -1;
        
        // Valid Chars
        int c=1;
        for (int i='a'; i<='z'; i++)
            arr[i] = c++;
        
        arr[' '] = 0;
    }
};

Lang::Lang(string language, int n_gram):n(n_gram),len(power(asccii_range, n))
{
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
    VALS_TABLE vals;
    for (int i=0; i < static_cast<int>(language.size())-n; i++)
    {
        // Filter the character for bad chars, and newlines.
        if (vals.arr[(int)language[i]] < -1) throw std::invalid_argument("Your language file has an unkown character in it!");
        if (vals.arr[(int)language[i]] == -1) continue;
        // Otherwise, get the index to increment.
        int index=0;
        for (int j=0; j<n; j++)
        {
            index += power(vals.arr[(int)language[i+j]], n-j-1); // n-j-1 because we have to include to the 0 power
        }
        
        freq[index]++;
    }
}

int Lang::operator[](int i)
{
    return freq[i];
}
