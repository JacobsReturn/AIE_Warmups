#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int data, Node* left = nullptr, Node* right = nullptr) :
        data(data), left(left), right(right) {}
};

int BranchCount(Node* root, int count)
{
    if (root->left != nullptr)
    {
        count++;
        return BranchCount(root->left, count);
    }
    else
    {
        return count;
    }
}

void SetCursorPOS(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE),
        coord
    );
}

void PrintTree(Node* root, int branch, int branches, int line)
{
    /*for (int i = 0; i < branch; i++)
    {
        std::cout << " ";
    }*/

    bool bounce = false;

    int x, y;

    if (branch == 0)
    {
        bounce = true;

        for (int i = 0; i < (10 * branches) * 2; i++)
        {
            std::cout << "*";
        }
        
        line++;

        SetCursorPOS(0, line); std::cout << "*";
        SetCursorPOS((10 * branches) * 2 - 1, line); std::cout << "*";

        x = (10 * branches);
    }
    else
    {
        SetCursorPOS(0, line); std::cout << "*";
        SetCursorPOS((10 * branches) * 2 - 1, line); std::cout << "*";

        x = (10 * branches) - branch;
    }

    y = line;

    SetCursorPOS(x, y);

    std::cout << root->data;

    if (root->left != nullptr)
    {
        line++;
        if (bounce) branch = branch + branches * 2;

        PrintTree(root->left, branch + 3, branches, line);
    }

    if (root->right != nullptr)
    {
        if (bounce) branch = branch - branches * 4;

        PrintTree(root->right, branch - 3, branches, line);
    }

    if (line == branches)
    {
        SetCursorPOS(0, line + 1);

        for (int i = 0; i < (10 * branches) * 2; i++)
        {
            std::cout << "*";
        }
    }
}

void PrintTree(Node* root)
{
    PrintTree(root, 0, BranchCount(root, 1), 0);
}

void DeleteTree(Node* root)
{
    Node* left = root->left;
    Node* right = root->right;

    delete root;

    if (left != nullptr)
    {
        DeleteTree(left);
    }

    if (right != nullptr)
    {
        DeleteTree(right);
    }
}

int main(int argc, char** argv)
{

    /************************
               50
       20             70
     10   30        60  80
    ************************/
    //Node* root = new Node(50,
    //    new Node(20, new Node(10), new Node(30)),
    //    new Node(70, new Node(60), new Node(80))
    //);

    Node* root = new Node(50, new Node(40, new Node(20, new Node(40, new Node(20, new Node(14), new Node(230)), new Node(50, new Node(13), new Node(312))), new Node(40, new Node(20, new Node(14), new Node(230)), new Node(50, new Node(13), new Node(312)))), new Node(50, new Node(40, new Node(20, new Node(14), new Node(230)), new Node(50, new Node(13), new Node(312))), new Node(40, new Node(20, new Node(14), new Node(230)), new Node(50, new Node(13), new Node(312))))), new Node(40, new Node(20, new Node(40, new Node(20, new Node(14), new Node(230)), new Node(50, new Node(13), new Node(312))), new Node(40, new Node(20, new Node(14), new Node(230)), new Node(50, new Node(13), new Node(312)))), new Node(50, new Node(40, new Node(20, new Node(14), new Node(230)), new Node(50, new Node(13), new Node(312))), new Node(40, new Node(20, new Node(14), new Node(230)), new Node(50, new Node(13), new Node(312))))));

    PrintTree(root);

    DeleteTree(root);

    return 0;
}