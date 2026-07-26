#include<iostream>
using namespace std;

class Node{
public:
    int val;
    Node * next;

    Node (int val){
        this->next = NULL;
        this->val = val;
    }
};

class List{
public:
    Node * head;
    Node * tail;

    List(){
        this->head = NULL;
        this->tail = NULL;
    }

    void pushFront(int val){
        Node * newNode = new Node(val);

        if (head == NULL){
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void pushBack(int val){
        Node * newNode = new Node(val);

        if (head == NULL){
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print(){
        Node * tmp = head;
        while(tmp != NULL){
            cout << tmp->val << " -> ";
            tmp = tmp->next;
        }
        cout << "NULL" << endl;
    }

    void popFront(){
        if (head == NULL)
            return;
        
        Node * tmp = head;
        head = head->next;
        tmp->next = NULL;

        delete tmp;
    }

    void popBack(){
        if (head == NULL)
            return;
        if (head == tail){
            delete head;
            head = tail = NULL;
        }
        
        Node * tmp = head;
        while (tmp->next != tail){
            tmp = tmp->next;
        }
        tail = tmp;
        tmp = tmp->next;
        tail->next = NULL;

        delete tmp;
    }

    void insert(int val, int pos){
        if (pos < 0){
            return;
        }
        if (pos == 0){
            pushFront(val);
            return;
        }

        Node * tmp = head;
        while (tmp != NULL && pos > 1){
            pos --;
            tmp = tmp->next;

        }
        if (tmp == NULL)
            return;

        Node * newNode = new Node(val);

        if (tmp->next == NULL){
            tail = newNode;
        }
        
        newNode->next = tmp->next;
        tmp->next = newNode;
    }
};

int main()
{
    List list;

    list.pushFront(2);
    list.pushFront(1);

    list.pushBack(3);
    list.pushBack(4);

    list.insert(100, 2);

    list.popFront();
    list.popBack();

    list.print();
    
    return 0;
}