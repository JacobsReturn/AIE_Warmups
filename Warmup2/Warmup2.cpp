#include <iostream>
#include <string>
#include <vector>
std::vector<std::string> Explode(char seperator, const char* str)
{
    std::vector<std::string> result;

    std::string message;

    int len = strlen(str);

    for (int i = 0; i <= len + 1; i++)
    {
        if ((str[i] == seperator || i == len) && message != "")
        {
            result.push_back(message);
            message = "";
        }
        else if (str[i] != seperator) message = message + str[i];
    }

    // TODO: write code that "splits" the input string by the sperator
    // store each word in the resuts.

    return result;
}

int main(int argc, char* argv)
{
    std::cout << "---------------------------------------------------------" << std::endl;
    auto words = Explode(' ', "the quick brown fox jumps over the lazy dog");
    std::cout << "There are: " << words.size() << std::endl << std::endl;
    for (auto& w : words) {
        std::cout << w << std::endl;
    }
    std::cout << "---------------------------------------------------------" << std::endl;

    std::cout << "---------------------------------------------------------" << std::endl;
    auto kvp = Explode('&', "aaa:10&bbb:20ccc:30&&&&&ddd:30");
    std::cout << "There are: " << kvp.size() << std::endl << std::endl;
    for (auto& w : kvp) {
        std::cout << w << std::endl;
    }
    std::cout << "---------------------------------------------------------" << std::endl;

    return 0;
}