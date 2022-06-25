// Flattening of a Linked List

/*
Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
          (i) a next pointer to the next node,
          (ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
Note: The flattened list will be printed using the bottom pointer instead of next pointer
*/

/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};

*****************************************************************/
#include <bits/stdc++.h> 
Node *mergeTwoLinkedList(Node *a, Node *b)
{
    Node *temp = new Node(0);
    Node *res = temp;
    
    while(a != NULL && b != NULL)
    {
        if(a->data < b->data)
        {
            temp->child = a;
            temp = temp->child;
            a = a->child;
        }
        else
        {
            temp->child = b;
            temp = temp->child;
            b = b->child;
        }
        temp->next = NULL;
    }
    while(a)
    {
        temp->child = a;
        temp = temp->child;
        a = a->child;
    }
    while(b)
    {
        temp->child = b;
        temp = temp->child;
        b = b->child;
    }
    
    res->next = NULL;
    return res->child;
}
Node* flattenLinkedList(Node* head) 
{
    if(head == NULL || head->next == NULL)
        return head;
    
    // recur till the last node
    head->next = flattenLinkedList(head->next);
    
    head = mergeTwoLinkedList(head, head->next);
    
    return head;
}
