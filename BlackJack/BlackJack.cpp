// BlackJack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>

bool overTwentyOne(std::vector<std::string> cards) 
{
    int count = 0;

    for (std::string card : cards)
    {
        if (std::isdigit(card[0]))
        {
            count += (int)(card[0] -'0');
        }
        else
        {
            if (card[0] == 'A')
            {
                if ((count + 10) > 21) count += 1;
                else count += 10;
            }
            else count += 10;
        }

        
        if (count > 21) return true;
    }

    return false;
}

int main()
{
    std::cout << overTwentyOne({ "2", "8", "J" }) << std::endl; // false
    std::cout << overTwentyOne({"A", "J", "K"}) << std::endl; // true
    std::cout << overTwentyOne({"5", "5", "3", "9"}) << std::endl; // true
    std::cout << overTwentyOne({"2", "6", "4", "4", "5"}) << std::endl; // false
    std::cout << overTwentyOne({"J", "Q", "K"}) << std::endl; // true
}