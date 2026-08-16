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

    void reverse() // Time complexity : O(N)
    {
        Node * curr = this->head;
        Node * prev = NULL;
        Node * next = NULL;

        this->tail = this->head;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        this->head = prev;
    }

    Node* findMiddle()  // Time complexity : O(N)
    {
        Node * fastPtr = this->head;
        Node * slowPtr = this->head;

        while(fastPtr != NULL && fastPtr->next != NULL)
        {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }

        return slowPtr;
    }

    void createLinkTo ( int to ) {
        Node * toPtr = head;

        while ( toPtr != NULL ) {
            if ( toPtr->val == to ) {
                break;
            }
            toPtr = toPtr->next;
        }
        
        /*
            * Case when no "to" Node is found
            */
        if ( toPtr == NULL ) {
            return;
        }

        tail->next = toPtr;
    }

    void findAndRemoveCycle () {
        Node * fast = head;
        Node * slow = head;

        while ( fast != NULL && fast->next != NULL ) {
            slow = slow->next;
            fast = fast->next->next;

            if ( fast == slow ) {
                cout << "Cycle Found" << endl;
                fast = head;
                break;
            }
        }

        if( fast == NULL || fast->next == NULL ) {
            cout << "No cycle found" << endl;
            return;
        }

        while ( fast != slow ) {
            fast = fast->next;
            slow = slow->next;
        }

        Node * fastPrev = fast;
        while ( fastPrev->next != fast ) {
            fastPrev = fastPrev->next;
        }

        cout << "Cycle Removed" << endl;
        fastPrev->next = NULL;
        tail = fastPrev;
    }

    void mergeToList ( Node * head2 ) {
        this->head = mergeToListWrapper(this->head, head2);

        tail = head;
        while ( tail != NULL && tail->next != NULL ) {
            tail = tail->next;
        }
    }

    Node* mergeToListWrapper ( Node * head1, Node * head2 ) {
        if ( head1 == NULL ) {
            return head2;
        }
        else if ( head2 == NULL ) {
            return head1;
        }

        if ( head1->val < head2->val ) {
            head1->next = mergeToListWrapper(head1->next, head2);
            return head1;
        }
        else {
            head2->next = mergeToListWrapper(head1, head2->next);
            return head2;
        }
    } 
};

int main()
{
    List list;

    list.pushBack(1);
    list.pushBack(3);
    list.pushBack(5);

    cout << "List 1 : ";
    list.print();

    List list2;
    list2.pushBack(2);
    list2.pushBack(4);
    list2.pushBack(6);

    cout << "List 2 : ";
    list2.print();

    list.mergeToList(list2.head);

    cout << "List after merge : ";
    list.print();

    return 0;

}