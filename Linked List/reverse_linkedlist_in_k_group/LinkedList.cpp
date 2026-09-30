#include<iostream>
#include "LinkedList.h"
using namespace std;

Node::Node(int val) {
    this->next = NULL;
    this->val = val;
}

List::List() {
    this->head = NULL;
    this->tail = NULL;
}

void List::pushFront(int val) {
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

void List::pushBack(int val) {
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

void List::print() {
    Node * tmp = head;
    while(tmp != NULL){
        cout << tmp->val << " -> ";
        tmp = tmp->next;
    }
    cout << "NULL" << endl;
}

void List::popFront() {
    if (head == NULL)
        return;
    
    Node * tmp = head;
    head = head->next;
    tmp->next = NULL;

    delete tmp;
}

void List::popBack() {
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

Node* List::reverseKGroupWrapper(Node* head, int k) {
    // Check if k nodes exists in this group
    // if not, then no need to reverse
    Node* temp = head;
    
    if( temp == NULL )
        return temp;
    
    int count = 1;
    while( temp->next != NULL && count < k )
    {
        temp = temp->next;
        count++;
    }

    if( count < k )
        return head;

    // recurssive call, sort the later list first
    Node* result = reverseKGroupWrapper(temp->next, k);
    Node* newHead = temp;

    // reverse current group
    count = 1;
    Node* headNext = head->next;
    head->next = result;
    while( count < k ) {
        Node* prevHead = head;
        head = headNext;
        headNext = head->next;
        head->next = prevHead;
        count ++;
    }

    // return new head
    return newHead;
}

void List::reverseKGroup(int k) {
    this->head = reverseKGroupWrapper(this->head, k);
}