#ifndef _TIMESTABLE_H
#define _TIMESTABLE_H

#include<iostream>

void timestable(int times, int max_num) 
{
    int initial_value{times};
    int current_num{initial_value};
    while (current_num < max_num) {
        std::cout << current_num << ", ";
        current_num += times;
    }
    std::cout << std::endl;
}
#endif