// Intersection of Two Linked Lists

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

int findIntersection(Node *head1, Node *head2)
{
    //Write your code here
       if(head1 == NULL && head2 == NULL) return -1;
        
        Node *dummy1 = head1, *dummy2 = head2;
        
        // dummy node will only meet at intersection or at NULL when there is no intersection
        while(dummy1 != dummy2)
        {
            (dummy1 == NULL)? dummy1 = head2 : dummy1 = dummy1->next;
            (dummy2 == NULL)? dummy2 = head1 : dummy2 = dummy2->next;
        }
        
        if(dummy1 == NULL && dummy2 == NULL) return -1;
        return dummy1->data;
}