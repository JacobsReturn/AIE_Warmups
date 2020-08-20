// FibonacciSequence.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

int GenerateFib(int n)
{
    std::vector<int> sequence;

    int i;

    /* 0th and 1st number of the series are 0 and 1*/
    sequence.push_back(0);
    sequence.push_back(1);

    for (i = 2; i <= n; i++)
    {
        /* Add the previous 2 numbers in the series
           and store it */
        sequence[i] = sequence[i - 1] + sequence[i - 2];
    }
}
int main(int argc, char** argv)
{
    std::cout << GenerateFib(13) << std::endl;
    std::cout << GenerateFib(17) << std::endl;
    std::cout << GenerateFib(45) << std::endl;
    std::cout << GenerateFib(55) << std::endl;
}