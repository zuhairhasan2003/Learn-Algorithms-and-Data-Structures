class Node{
public:
    int val;
    Node * next;

    Node (int val);
};

class List{
private:
    Node* reverseKGroupWrapper(Node* head, int k);

public:
    Node * head;
    Node * tail;

    List();

    void pushFront(int val);
    void pushBack(int val);
    void print();
    void popFront();
    void popBack();

    void reverseKGroup(int k);
};