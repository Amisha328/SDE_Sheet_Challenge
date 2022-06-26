// Rotate Linked List
// Explantion: https://rb.gy/b1ujrz

#include <bits/stdc++.h> 
/********************************

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

********************************/
// TC-> O(N) + O(N-(k%N)) = O(N) | SC-> O(1)
Node *rotate(Node *head, int k) {
    
         if (head == NULL || head->next == NULL || k == 0) return head;
        
        // compute the length
        Node *cur = head;
        int len = 1;
        while (cur->next)
        {
            len++;
            cur = cur->next;
        }
            
        // go till that node
        cur->next = head;
        k = k % len; 
        k = len - k;
        while (k--) 
            cur = cur->next;
        
        // make the node head and break connection 
        head = cur->next;
        cur->next = NULL;
        
        return head; 
}