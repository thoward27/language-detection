#pragma once

#include "lang.h"
#include <vector>
#include <string>

class Analysis 
{
    private:
        std::vector<Lang> training;
        Lang* test;
    public:
        Analysis();
        Analysis(char* files[], int n);
        ~Analysis();

        std::string evaluate();
};

Analysis::Analysis() {}

Analysis::Analysis(char* files[], int n)
{
    for (int i=0; i<n-1; i++)
    {
        training.push_back(Lang(files[i], 3));
    }
    test = new Lang(files[n-1], 3);

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
            similarity = test_similarity;
        }
    }
    return most_similar;
}
