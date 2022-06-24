// Merge Two Sorted Linked Lists

#include <bits/stdc++.h> 
template <typename T>
class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
};

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here.
    if(first == NULL) return second;
    if(second == NULL) return first;
    
    Node<int>* head = NULL, *tail = NULL;
    if(first->data <= second->data)
    {
        head = tail = first;
        first = first->next;
    }
    else
    {
        head = tail = second;
        second = second->next;
    }
    
    while(first != NULL && second != NULL)
    {
        if(first->data <= second->data)
        {
            tail->next = first;
            tail = first;
            first = first->next;
        }
        else
        {
            tail->next = second;
            tail = second;
            second = second->next;
        }
    }
    if(first == NULL)
          tail->next = second;
     else
          tail->next = first; 
    
    return head;
}