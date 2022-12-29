#include <iostream>
#include "ThreadBinaryTree.h"
#include "ThreadBinaryTree.cpp"
using namespace std;

int main()
{
    ThBiTree<int> x;
    x.Insert(10);
    x.Insert(7);
    x.Insert(11);
    x.Insert(6);
    x.Insert(8);
    x.Insert(5);
    ThBiTree<int>::InorderIterator i = x.begin();

    while (i.Next(x.getRoot()) != 0)
    {
        cout << i.hasNext() << " ";
    }
    cout << endl;
}