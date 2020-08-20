#include <iostream>
#include <string>
#include <map>

int SocPairs(const std::string& socks)
{
	std::map<char, int> sockPairs;

	int pairs = 0;

	for (auto val : socks)
	{
		sockPairs[val]++;
		if (sockPairs[val] == 2)
		{
			sockPairs[val] = 0;
			pairs++;
		}
	}

	return pairs;
}

int main(int argc, char** argv)
{
	std::cout << SocPairs("AA"); //1
	std::cout << SocPairs("ABABC"); //➞ 2
	std::cout << SocPairs("CABBACCC"); // ➞ 4
}