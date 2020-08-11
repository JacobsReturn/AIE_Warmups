// Parse Points string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

struct Point { int x; int y; };
std::vector<Point> ParsePointString(const std::string& sPoints)
{
    std::vector<Point> vector;

    bool isX = true; // Is it X or Y

    std::string x, y;

    Point p;
    p.x = NULL; p.y = NULL;

    for (char point : sPoints)
    {
        if (point == ',' || point == ' ')
        {
            if (isX) p.x = std::stoi(x);
            else p.y = std::stoi(y);

            x = ""; y = "";

            if (p.x != NULL && p.y != NULL)
            {
                vector.push_back(p);
                p.x = NULL; p.y = NULL;
            }

            isX = !isX;
        }
        else if (isX) x = x + point;
        else if (!isX) y = y + point;
    }

    return vector;
}

int main(int argc, char** argv)
{
    std::string sPoints = "0,0 -3,-214 187,-422 196,-862 -95,-1044 -461,-1219 -732,-1310 -950,-1338 -1213,-1339";

    auto points = ParsePointString(sPoints);

    for (auto& point : points)
    {
        std::cout << point.x << "\t" << point.y << std::endl;
    }
    return 0;
}