// Add Two Numbers As Linked Lists

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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    Node *dummy = new Node(0);
    Node *temp = dummy;
    
    int carry = 0;
    while(head1 || head2 || carry)
    {
        int sum = 0;
        if(head1)
        {
            sum += head1->data;
            head1 = head1->next;
        }
        if(head2)
        {
            sum += head2->data;
            head2 = head2->next;
        }
        sum += carry;
        carry = sum/10;
        Node *newNode = new Node(sum%10);
        temp->next = newNode;
        temp = temp->next;
    }
    return dummy->next;
}