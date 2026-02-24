#include<iostream>
using namespace std;

class Node
{
    public:
    int val;
    Node* right;
    Node* left;

    Node(int val)
    {
        this->val = val;
        right = NULL;
        left = NULL;
    }
};

class BinarySearchTree
{
    Node* head;

    public:

    BinarySearchTree()
    {
        head = NULL;
    }

    void Build (int * arr, int size)
    {
        for(int i = 0 ; i <  size ; i++)
        {
            head = insertNode(head, arr[i]);
        }
    }

    void InOrder()
    {
        cout << "In Order traversal : ";
        inOrder(head);
        cout << endl;
    }   

    void Search(int toFind) // Time complexity = O(height) ; For a balanced tree it becomes O(log N)
    {
        Node * node = search(head, toFind);

        if(node == NULL)
        {
            cout << "Node not found with value : " << toFind << endl;
        }
        else
        {
            cout << "Node found with value : " << toFind << endl;
        }
    }

    private:

    Node * search(Node * node, int toFind)
    {
        if(node == NULL)
        {
            return NULL;
        }

        if(node->val == toFind)
        {
            return node;
        }

        if(node->val > toFind)
        {
            return search(node->left, toFind);
        }
        return search(node->right, toFind);
    }

    void inOrder(Node * node)
    {
        if (node == NULL)
        {
            return;
        }

        inOrder(node->left);
        cout << node->val << "         ";
        inOrder(node->right);
    }
    
    Node * insertNode(Node * node , int val)
    {
        if(node == NULL)
        {
            Node * tempNode = new Node(val);
            return tempNode;
        }

        if(val > node->val)
        {
            node->right = insertNode(node->right , val);
        }
        else
        {
            node->left = insertNode(node->left , val);
        }

        return node;
    }
};

int main()
{
    BinarySearchTree tree;

    int arr [] = {2,3,1,4,5,6};

    tree.Build(arr , sizeof(arr) / sizeof(int));

    tree.InOrder();

    tree.Search(10);
    tree.Search(2);

    return 0;
}