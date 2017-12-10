
#include "lang.h"
#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include <fstream>

using std::string;

int get_val(char c)
{
    // If it's a lowercase letter, val is c-96, otherwise if it's a space val is 0, otherwise invalid character.
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
    name = "Blank";
    freq = new int[len]();
}

Lang::~Lang()
{
    // Free mem
    delete[] freq;
}

void Lang::print() const
{
    // Prints entire frequency vector
    for (int i = 0; i < len; i++)
        std::cout << freq[i] << " ";
    std::cout << std::endl;
}

void Lang::compute_freq(string language)
{
    // Compute Frequency.
    // From 0-length-n compute n_gram value and increment the frequency table by 1.
    string line;
    std::ifstream infile(language);
    if (infile.good())
    {
        for (string line; std::getline(infile, line); )
        {
            for (int i = 0; i < static_cast<int>(line.size()) - 2; i++)
            {
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
    return freq[i];
}

string Lang::get_name() const
{
    return name;
}

double Lang::similarity(Lang& l) const
{
    double product = 0;
    double sqrt_a = 0;
    double sqrt_b = 0;
    for (int i=0; i<len; i++)
    {
        product += freq[i] * l[i];
        sqrt_a += std::sqrt(static_cast<double>(std::pow(freq[i], 2)));
        sqrt_b += std::sqrt(static_cast<double>(std::pow(l[i], 2)));
    }
    return (product / (sqrt_a * sqrt_b));
}