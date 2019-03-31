
#include "lang.h"
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <fstream>

using std::string;

int get_val(char c)
{
    // If it's a lowercase letter, val is c-96, 
    // otherwise if it's a space val is 0, 
    // otherwise invalid character.
    if (c >= 'a' && c <= 'z')
        return c - 96;
    else if (c == ' ')
        return 0;
    else
        throw std::invalid_argument(std::string("Your language file has this invalid character in it: ") + c);
}

Lang::Lang(string language)
{
    name = language;
    freq = new int[len]();  // Create the frequency array.
    compute_freq(language); // Fill the frequency array.
}

Lang::Lang()
{
    // Default name, and empty table. 
    name = "Blank";
    freq = new int[len]();
}

Lang::~Lang()
{
    // Free mem.
    delete[] freq;
}

void Lang::print() const
{
    // Prints contents of the frequency array. 
    for (int i = 0; i < len; i++)
        std::cout << freq[i] << " ";
    std::cout << std::endl;
}

void Lang::compute_freq(string language)
{
    std::ifstream infile(language);
    if (infile.good())
    {
        // For each string in the file:
        for (string line; std::getline(infile, line); )
        {
            // Go to 2 off the end of the string, which prevents us from taking
            // partial trigrams. 
            for (int i = 0; i < static_cast<int>(line.size()) - 2; i++)
            {
                // Trigrams read left to right, rightmost being the highest value. 
                int index = 0;
                index += (get_val(line[i + 0]) * 27 * 27);
                index += (get_val(line[i + 1]) * 27);
                index += get_val(line[i + 2]);
                
                freq[index]++;
            }
        }
    }
    else 
        throw std::invalid_argument("Can't open that file");
    
    infile.close();
}

int Lang::operator[](int i) const
{
    // Return i-th position in the frequency array. 
    return freq[i];
}

string Lang::get_name() const
{
    return name;
}

long double Lang::similarity(Lang& l) const
{
    // cos similarity
    long double product = 0;
    long double sqrt_a = 0;
    long double sqrt_b = 0;
    for (int i=0; i<len; i++)
    {
        product += freq[i] * l[i];
        sqrt_a += std::sqrt(static_cast<long double>(std::pow(freq[i], 2)));
        sqrt_b += std::sqrt(static_cast<long double>(std::pow(l[i], 2)));
    }
    return (product / (sqrt_a * sqrt_b));
}