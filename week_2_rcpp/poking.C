#include <iostream>

int main() {

    int ys{10};
    float *xys;

    xys = ys;

    xys = 11;

    std::cout << "xys: " << xys << std::endl;
    std::cout << "ys: " << ys << std::endl; 

    return 0;
}