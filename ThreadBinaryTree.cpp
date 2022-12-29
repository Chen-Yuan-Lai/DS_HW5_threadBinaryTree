#include <iostream>
#include "ThreadBinaryTree.h"
using namespace std;

template <class T>
ThBiTree<T>::ThBiTree()
{
    Node *head = new Node;
    head->leftChild = head;
    head->rightChild = head;
    head->rightThread = false;
    root = head;
}

template <class T>
void ThBiTree<T>::RemoveSubtree(Node *Ptr)
{
    if (Ptr->leftThread != true)
        RemoveSubtree(Ptr->leftChild);
    if (Ptr->rightThread != true)
        RemoveSubtree(Ptr->rightChild);
    Ptr->leftChild = 0;
    Ptr->rightChild = 0;
    delete Ptr;
}

template <class T>
ThBiTree<T>::~ThBiTree()
{
    RemoveSubtree(root->leftChild);
}

template <class T>
typename ThBiTree<T>::Node *ThBiTree<T>::InorderSucc(Node *r)
{
    typename ThBiTree<T>::InorderIterator i(r);
    return i.Next(root);
}
// template <class T>
// typename ThBiTree<T>::Node *ThBiTree<T>::search(T key)
// {
//     typename ThBiTree<T>::InorderIterator i;
//     Node *temp;

//     do
//     {
//         temp = i.next();
//     } while (temp->data != key);
//     return temp;
// }

template <class T>
void ThBiTree<T>::InsertRight(Node *s, Node *r)
{
    r->rightChild = s->rightChild;
    r->rightThread = s->rightThread;
    r->leftChild = s;
    r->leftThread = true;
    s->rightChild = r;
    s->rightThread = false;
    if (!r->rightThread)
    {
        Node *temp = InorderSucc(r);
        temp->leftChild = r;
    }
}

template <class T>
void ThBiTree<T>::InsertLeft(Node *s, Node *r)
{
    r->leftChild = s->leftChild;
    r->leftThread = s->leftThread;
    r->rightChild = s;
    r->rightThread = true;
    s->leftChild = r;
    s->leftThread = false;
    if (!r->leftThread)
    {
        Node *temp = InorderSucc(r);
        temp->rightChild = r;
    }
}

template <class T>
void ThBiTree<T>::Insert(T key)
{
    Node *temp = new Node(key);
    Node *current = root->leftChild;
    if (isEmpty())
    {
        InsertLeft(current, temp);
        return;
    }
    // move current node to the leaf
    while (1)
    {
        if (current->data > key && current->rightThread != true)
        {
            current = current->leftChild;
        }
        else if (current->data < key && current->rightThread != true)
        {
            current = current->rightChild;
        }
        else
        {
            break;
        }
    }
    if (current->data > key)
    {
        InsertLeft(current, temp);
    }
    else
    {
        InsertRight(current, temp);
    }
}