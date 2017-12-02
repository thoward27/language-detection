
#include "lang.h"
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>

using std::string;

int Lang::power(int c, int b)
{
    // Returns a static cast int from the power function. 
    if (c == 0) return 0;
    return c * static_cast<int>(std::pow(static_cast<float>(ascii_range), b));
}

Lang::Lang(string language, int n_gram):n(n_gram),len(power(ascii_range, n))
{
    freq = new int[len]; // Frequency array
    compute_freq(language); // Fill the frequency array
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

int get_val(char c)
{
    if (c >= 'a' && c <= 'z')
        return c-96;
    else if (c == ' ')
        return 0;
    else
        throw std::invalid_argument("Your language file has an unkown charcter in it!");
}


void Lang::compute_freq(string language)
{
    for (int i=0; i <= static_cast<int>(language.size())-n; i++)
    {
        // Otherwise, get the index to increment.
        int index=0;
        for (int j=0; j<n; j++)
        {
            index += power(get_val(language[i+j]), n-j-1); // n-j-1 because we have to include to the 0 power
        }
        
        freq[index]++;
    }
}

int Lang::operator[](int i)
{
    return freq[i];
}
