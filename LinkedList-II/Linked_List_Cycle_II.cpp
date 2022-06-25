// Find the starting point of the Loop of LinkedList

#include <bits/stdc++.h> 
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

Node *firstNode(Node *head)
{
        if(head == NULL) return NULL;
        
        Node *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) break;
        }
        
        if (!(fast && fast->next)) return NULL;
        if(slow == head)  // 1 1 1 -1 pos = 0 
        {
            while(fast->next != slow)
                fast = fast->next;
                
            return fast->next;
        }
        fast = head;
        while(slow->next != fast->next)
        {
             slow = slow->next;
             fast = fast->next;
        }
        return slow->next;
}