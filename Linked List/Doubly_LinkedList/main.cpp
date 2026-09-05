#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node( int val ) {
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() {
        head = NULL;
    }

    void PushBack( int val ) {
        Node* newNode = new Node(val);

        if ( head == NULL ) {
            head = newNode;
            return;
        }
        
        Node* tmp = head;
        while ( tmp->next != NULL ) {
            tmp = tmp->next;
        }

        tmp->next = newNode;
        newNode->prev = tmp;
    }

    void Print() {
        Node* tmp = head;
        while ( tmp != NULL ) {
            cout << tmp->val << " <=> ";
            tmp = tmp->next;
        }
        cout << "NULL" << endl;
    }

    void PushFront( int val ) {
        Node* newNode = new Node(val);

        if ( head == NULL ) {
            head = newNode;
            return;
        }
        
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void PopFront () {
        if ( head == NULL )
            return;

        Node* tmp = head;
        head = head->next;
    
        if (head != NULL)
            head->prev = NULL;

        delete tmp;
    }

    void PopBack () {
        if ( head == NULL )
            return;

        Node* tmp = head;

        while ( tmp->next != NULL )
        {
            tmp = tmp->next;
        }

        // case of only 1 node in LL
        if ( tmp->prev == NULL ) {
            head = NULL;
            delete tmp;
            return;
        }

        tmp->prev->next = NULL;
        delete tmp;
    }
};

int main() {
    DoublyLinkedList list;

    list.PushFront(1);
    list.PushFront(2);
    list.PushFront(3);

    list.PopBack();

    list.Print();
    
    return 0;
}