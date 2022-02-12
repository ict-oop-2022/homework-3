#include <iostream>
#include <vector>

#include "quicksort.cpp"
#include "lab1_functions.h"

void vector_log(const std::vector<int> &a)
{
    int counter = 0;
    for(auto &vector_el: a)
    {
        std::cout << "Element [" << counter << "] of vector before sort: " << vector_el << "\n";
        ++counter;
    }
}

void sort_vector_log(std::vector<int> &a)
{
    if (a.size() < 2)
    {
        std::cerr << "Error! Size of vec is less than 2!";
        exit(1);
    }

    vector_log(a);

    quicksort(a, 0, a.size() - 1);

    std::cout << "Sorted vec: \n";

    vector_log(a);
}