/*
 * Leetcode 430 : https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node* ptr = head;
        flatten_wrapper(head);
        return ptr;
    }

    Node* flatten_wrapper(Node* head) {
        if (head == NULL)
            return head;

        if (head->next == NULL && head->child == NULL) {
            return head;
        }

        if (head->child != NULL) {
            Node* tmp_next = head->next;
            head->next = head->child;
            head->child->prev = head;
            head->child = NULL;

            Node* last = flatten_wrapper(head->next);

            if (tmp_next != NULL) {
                tmp_next->prev = last;
                last->next = tmp_next;
            }

            if (tmp_next != NULL)
                return flatten_wrapper(tmp_next);
        }

        return flatten_wrapper(head->next);
    }
};