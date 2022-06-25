// Reverse Nodes in k-Group

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
 
Node *getListAfterReverseOperation(Node *head, int n, int b[]){
	Node *curr = head, *prevFirst = NULL;
    bool firstPass = true;
    int k = 0;
    while(curr != NULL)
    {
        if(b[k] == 0 && k == n-1)
                return head;
        Node *prev = NULL, *next = NULL;
        Node *first = curr;
        int count = 0;
        while(curr != NULL && count < b[k])
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        if(firstPass)
        {
            head = prev;
            firstPass = false;
        }
        else
           prevFirst->next = prev;

        prevFirst = first;
        
        if(k < n-1){
            k++;
            while(b[k] == 0 && k < n-1)
                k++;
        }
        else{
            prevFirst->next = curr;
            return head;
        }
    }
    return head;
}