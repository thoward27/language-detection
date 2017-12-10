
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
    std::cerr << (int)c << std::endl;
    throw std::invalid_argument(std::string("Your language file has this invalid character in it: ") + c);
}

Lang::Lang(string language)
{
    name = language;
    std::cout << "lang : " << language << std::endl;
    freq = new int[len]();  // Create the frequency array.
    compute_freq(language); // Fill the frequency array.
}

Lang::~Lang()
{
    // Free mem
    delete[] freq;
}

int Lang::get_index(int a, int b)
{
    // Return a * power of the ascii range to the current base.
    return a * power(ascii_range, b);
}

int Lang::power(int n, int p)
{
    if (n == 0)
        return 0;
    // Returns a static cast int from the power function.
    return static_cast<int>(std::pow(static_cast<float>(n), p));
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
    std::cout << infile.good() << std::endl;
    if (infile.good())
    {
        for (string line; std::getline(infile, line); )
        {
            std::cout << line.size() << std::endl;
            for (int i = 0; i < static_cast<int>(line.size()) - 2; i++)
            {
                int index = 0;
                index += (get_val(line[i + 0]) * 27 * 27);
                index += (get_val(line[i + 1]) * 27);
                index += get_val(line[i + 2]);

                freq[index]++;
            }
        }
        std::cout << "Leaving " << std::endl;
    }
    else 
        throw std::invalid_argument("Can't open that file");
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
    l.get_name();
    return 1.0;
}