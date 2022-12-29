#ifndef THREADBINARYTREE
#define THREADBINARYTREE

template <class T>
class ThBiTree
{
    class Node;

public:
    friend class InorderIterator;
    ThBiTree();
    void RemoveSubtree(Node *Ptr);
    ~ThBiTree();
    bool isEmpty() { return root->leftThread == true && root->rightThread == false; }
    void InsertRight(Node *s, Node *r);
    void InsertLeft(Node *s, Node *r);
    void Insert(T key);
    // Node *search(T key);
    Node *InorderSucc(Node *r);
    class InorderIterator
    {
    public:
        InorderIterator(Node *startNode) : current(startNode){};
        InorderIterator() { current = root; }
        Node *Next()
        {
            Node *ori = root;
            Node *temp = current->rightChild;
            if (!current->rightThread)
            {
                while (!temp->leftThread)
                    temp = temp->leftChild;
            }
            current = temp;
            if (current == ori)
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