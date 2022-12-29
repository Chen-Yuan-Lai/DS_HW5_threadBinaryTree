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
    Node *getRoot() const { return root; }
    // Node *search(T key);
    class InorderIterator;
    InorderIterator begin() const { return InorderIterator(root); }
    Node *InorderSucc(Node *r);
    class InorderIterator
    {
    public:
        InorderIterator(Node *startNode) : current(startNode){};
        Node *Next(Node *ro)
        {

            Node *temp = current->rightChild;
            if (!current->rightThread)
            {
                while (!temp->leftThread)
                    temp = temp->leftChild;
            }
            current = temp;
            if (current == ro)
                return 0;
            else
                return current;
        }
        T hasNext()
        {
            return current->data;
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
                              rightThread(true){};
        T data;
        Node *leftChild;
        Node *rightChild;
        bool leftThread;
        bool rightThread;
    };
    Node *root;
};
#endif