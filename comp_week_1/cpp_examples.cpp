// Push values into a vector

#include <iostream>
#include <vector>

int main()
{
    // Declare vector with some elements
    std::vector<int> vec{1,2,3};

    // Add more elements to the vector
    for (int i{4}; i < 10; i++) {
        vec.push_back(i);
    } 

    // Output the vector
    for (int i{0}; i < vec.size(); i++) {
        std::cout << vec[i] << ", ";
    }
}