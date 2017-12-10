#include "lang.h"
#include <vector>
#include <string>
#include <iostream>

class Analysis 
{
    private:
        std::vector<Lang> training;
        Lang* test;
    public:
        Analysis();
        Analysis(std::vector<std::string>);
        ~Analysis();

        std::string evaluate();
};

Analysis::Analysis() {}

Analysis::Analysis(std::vector<std::string> files)
{
    test = new Lang(files.back());
    files.pop_back();
    for (std::string name : files)
    {
        training.push_back(Lang(name));
    }
    std::cout << "leaving analysis " << std::endl;
}

Analysis::~Analysis()
{
    delete test;
}

std::string Analysis::evaluate()
{
    std::string most_similar;
    double similarity = 0;
    for (Lang x : training)
    {
        double test_similarity = (*test).similarity(x);
        if (test_similarity > similarity) 
        {
            most_similar = x.get_name();
            std::cout << "most sim: " << most_similar << std::endl;
            similarity = test_similarity;
        }
    }
    return most_similar;
}
