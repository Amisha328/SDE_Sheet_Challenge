// Cycle Detection in a Singly Linked List
// Explantion:
// https://rb.gy/s8ohr1

/****************************************************************

    Following is the class structure of the Node class:

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

*****************************************************************/

// TC-> O(n) | SC-> O(1)
#include <bits/stdc++.h> 
bool detectCycle(Node *head)
{
       if(head == NULL) return false;
        Node *slow = head, *fast = head;
        
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        
        return false;
}