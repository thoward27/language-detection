
#include "lang.h"
#include <stdexcept>
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc < 3) 
    {
        std::cerr << "Usage: " << argv[0] << " <TRAINING DATA>+ <TESTING DATA>" << std::endl;
        return 1;
    }

    
    return 0;
}