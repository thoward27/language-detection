
#include "lang.h"
#include <stdexcept>
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        std::cerr << "Usage: " << argv[0] << " <TRAINING DATA>+ <TESTING DATA>" << std::endl;
        return 1;
    }

    // Setup testing data
    std::string file(argv[argc - 1]);
    Lang target(file);

    // Find similarities
    std::string result;
    double similarity = 0.0;
    for (int i = 1; i < argc - 1; i++)
    {
        file = argv[i];
        Lang language(file);
        double test_sim = target.similarity(language);
        if (test_sim > similarity)
        {
            result = language.get_name();
            similarity = test_sim;
        }
    }
    std::cout << result << std::endl;
    return 0;
}