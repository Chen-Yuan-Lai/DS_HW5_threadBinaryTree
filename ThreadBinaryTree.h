#ifndef THREADBINARYTREE
#define THREADBINARYTREE

template <class T>
class ThBiTree
{
    class Node;

public:
    ThBiTree();
    void RemoveSubtree(Node *Ptr);
    ~ThBiTree();
    bool isEmpty();
    void InsertRight(Node *s, Node *r);
    void InsertLeft(Node *s, Node *r);
    typename ThBiTree<T>::Node *InorderSucc(Node *r);
    template <typename U>
    friend ostream &operator<<(ostream &os, cirChain<U> &s);
    class InorderIterator
    {
    public:
        InorderIterator() { current = root; }
        InorderIterator(Node *startNode) : current(startNode){};
        Node *Next()
        {
            Node *temp = current->rightChild;
            if (!current->rightThread)
            {
                while (!temp->leftThread)
                    temp = temp->leftChild;
            }
            current = temp;
            if (current == root)
                return 0;
            else
                return current;
        }

    private:
        Node *current;
    };

private:
    class Node
    {
    public:
        Node(T element = 0) : data(element), leftChild(0),
                              rightChild(0), leftThread(true),
                              rightThread(false){};
        T data;
        Node *leftChild;
        Node *rightChild;
        bool leftThread;
        bool rightThread;
    };
    Node *root;
};
#endif