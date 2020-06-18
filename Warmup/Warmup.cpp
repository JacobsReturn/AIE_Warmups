#include <iostream>
#include <string>
std::string isIsogram(const std::string& word)
{
    std::string display = word + ": Is Isogram.";
    int duplicates = 1;
    // Grabbing all the words. Minusing one as we are adding one later.
    for (int i = 0; i < word.length() - 1; i++) {
        // Grabbing then again and checking the other loop for the same instance.
        for (int j = i + 1; j < word.length(); j++) {
            if (tolower(word[i]) == tolower(word[j])) {
                display = word + ": Not Isogram.";
                duplicates++;
            }
        }
    }
    display = display + " (Dupe Count: " + std::to_string(duplicates) + ")";
    return display;
}
std::string words[11] = {
    "Aaron", "Bake", "Lay", "Issue", "Wood", "Swop", "Coup", "Trouser", "Superior", "History", "Disclose",
};
int main(int argc, char** argv)
{
    // random words from a random word generator :P
    // 
    // I made it better >:) This is sufficiency. Sufficiency == Quality.
    for (int i = 0; i < sizeof(words) / sizeof(std::string); i++)
    {
        std::cout << isIsogram(words[i]) << std::endl;
    }
    return 0;
}