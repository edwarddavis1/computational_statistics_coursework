#include <iostream>
#include "timestable.h"

int main() 
{
    std::cout << "Five times table" << std::endl;
    timestable(5,100);

    std::cout << "Twelve times table" << std::endl;
    timestable(12, 100);

    return 0;
}
