// Middle Of Linked List

#include <bits/stdc++.h> 
class Node 
{ 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
};

Node *findMiddle(Node *head) {
    // Write your code here
    Node *fast = head, *slow = head;
    while(fast != NULL && fast-> next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}