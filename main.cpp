
#include "lang.h"
#include <stdexcept>
#include <iostream>

int main(int argc, char* argv[])
{
    if (argc != 2) 
    {
        std::cerr << "Usage: " << argv[0] << " <STRING>" << std::endl;
        return 1;
    }

    Lang l(argv[1]);
    l.print();
    return 0;
}