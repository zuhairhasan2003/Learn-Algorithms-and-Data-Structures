#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node ( int val ) {
        this->val = val;
        next = NULL;
        random = NULL;
    }
};

class List {
public:
    Node* head;

    List() {
        head = NULL;
    }

    Node* pushBack( int val ) {
        Node * newNode  = new Node(val);

        if( head == NULL ) {
            head = newNode;
            return newNode;
        }

        Node * tmp = head;
        while( tmp->next != NULL ) {
            tmp = tmp->next;
        }

        tmp->next = newNode;
        return newNode;
    }

    void print(){
        Node * tmp = head;

        while( tmp != NULL ){
            cout << tmp->val;
            if ( tmp->random != NULL ) {
                cout << "(" << tmp->random->val << ")";
            }
            cout << " --> ";
            tmp = tmp->next;
        }

        cout << "NULL" << endl;
    }

    void printAddr(){
        Node * tmp = head;

        while( tmp != NULL ){
            cout << tmp;
            if ( tmp->random != NULL ) {
                cout << "(" << tmp->random << ")";
            }
            cout << " --> ";
            tmp = tmp->next;
        }

        cout << "NULL" << endl;
    }

    void createRandomConnection( int from, int to ) {
        Node* fromPtr = NULL;
        Node* toPtr = NULL;
        Node* tmp = head;

        while ( tmp != NULL )
        {
            if ( from == tmp->val ) {
                fromPtr = tmp;
            }
            if ( to == tmp->val ) {
                toPtr = tmp;
            }
            tmp = tmp->next;
        }

        if ( fromPtr == toPtr || fromPtr == NULL || 
             toPtr == NULL )
        {
            cout << "Error making connection" << endl;
            return;
        }   

        fromPtr->random = toPtr;
    }

    void copyListWithRandomPointers( List * list ) {
        Node* tmp = head;
        unordered_map<Node* , Node*> map;

        while ( tmp != NULL ) {
            Node* nodePushed = list->pushBack ( tmp->val );

            map.insert({tmp, nodePushed});

            tmp = tmp->next;
        }

        tmp = head;
        Node* tmpList = list->head;

        while ( tmp != NULL ) {
            if ( tmp->random != NULL ) {
                tmpList->random = map[tmp->random];
            }
            tmp = tmp->next;
            tmpList = tmpList->next;
        }
    }
};

int main () {
    List list1;

    list1.pushBack(7);
    list1.pushBack(13);
    list1.pushBack(11);
    list1.pushBack(10);
    list1.pushBack(1);

    list1.createRandomConnection(13, 7);
    list1.createRandomConnection(11, 1);
    list1.createRandomConnection(10, 11);
    list1.createRandomConnection(1, 7);

    List list2;
    list1.copyListWithRandomPointers(&list2);

    cout << "List 2 after copy : " ;
    list2.print();

    cout << "List 1 : ";
    list1.printAddr();

    cout << "List 2 : ";
    list2.printAddr();

    return 0;
}