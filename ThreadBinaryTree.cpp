#include <iostream>
#include "ThreadBinaryTree.h"
using namespace std;

template <class T>
ThBiTree<T>::ThBiTree()
{
    Node *head = new Node;
    head->leftChild = head;
    head->rightChild = head;
    root = head;
}

template <class T>
void ThBiTree<T>::RemoveSubtree(Node *Ptr)
{
    if (Ptr->leftThread != true && Ptr->rightThread != true)
    {
        if (Ptr->leftThread != true)
            RemoveSubtree(Ptr->leftChild);
        if (Ptr->rightThread != true)
            RemoveSubtree(Ptr->rightChild);
        delete Ptr;
    }
}

template <class T>
ThBiTree<T>::~ThBiTree()
{
    RemoveSubtree(root);
}

template <class T>
typename ThBiTree<T>::Node *ThBiTree<T>::InorderSucc(Node *r)
{
    typename ThBiTree<T>::InorderIterator i(r);
    return i.next();
}

template <class T>
void ThBiTree<T>::InsertRight(Node *s, Node *r)
{
    r->rightChild = s->rightChild;
    r->rightThread = s->rightThread;
    r->leftChild = s;
    r->leftChild = s;
    r->leftThread = true;
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