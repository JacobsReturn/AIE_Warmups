// Pyramid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

void print_pyramid(int height)
{  
    int i, j, space;

    // Invert
    if (height < 0)
    {
        for (i = height; i < 0; i++)
        {
            for (space = 0; space < (i - height); space++)
            {
                std::cout << " ";
            }

            for (j = (2 * i + 1); j < 0; j++)
            {
                std::cout << "*";
            }

            std::cout << "\n";
        }
    }
    else // Normal
    {
        for (i = 1; i <= height; i++)
        {
            for (space = i; space < height; space++)
            {
                std::cout << " ";
            }

            for (j = 1; j <= (2 * i - 1); j++)
            {
                std::cout << "*";
            }

            std::cout << "\n";
        }
    }
}

int main(int argc, char** argv)
{
    std::cout << "=======================================" << std::endl;
    print_pyramid(6);
    std::cout << "=======================================" << std::endl;
    print_pyramid(7);
    std::cout << "=======================================" << std::endl;
    print_pyramid(-1);
    std::cout << "=======================================" << std::endl;
    print_pyramid(-6);
}