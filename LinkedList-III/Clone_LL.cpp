// Copy List with Random Pointer

/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/
#include <bits/stdc++.h> 

// Naive solution: TC->O(n) | SC->O(n)
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
        LinkedListNode<int> *p =head;
        map<LinkedListNode<int>*, LinkedListNode<int>*> mp;
         
        LinkedListNode<int> *temp = new LinkedListNode<int>(-1);
        LinkedListNode<int> *q = temp;
        
        while(p!=NULL)
        {
            LinkedListNode<int> *temp = new LinkedListNode<int>(p->data);
            q->next = temp;
            q = q->next;
            mp[p] = q;
            p = p -> next;
        }
        
        p = head;
        q = temp->next;
        
        while(p!=NULL)
        {
            LinkedListNode<int> *r = p->random;
            q->random = mp[r];
            
            p=p->next;
            q=q->next;
        }
        
        return temp->next;
}


// Efficient Solution:  TC->O(n) | SC->O(1)
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    	// First step is to make copy of each node,
        // and link them together side-by-side in a single list.
       LinkedListNode<int> *iter = head, *front = head;
        
        while(iter != NULL)
        {
            front = iter->next;
            LinkedListNode<int> *copy = new LinkedListNode<int>(iter->data);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }
        
        // Second step is to assign random pointers for the copy nodes.
        iter = head;
        while(iter != NULL)
        {
            iter->next->random = iter->random;
            // points to next original node
            iter = iter->next->next;
        }
    // Third step is to restore the original Linkedlist, and extract the copy Linkedlist.
        iter = head, front = head;
        LinkedListNode<int> *dummyHead = new LinkedListNode<int>(0);
        LinkedListNode<int> *copy = dummyHead;
        while(iter != NULL)
        {
            front = iter->next->next;
            
            // extract the copy Linkedlist
            copy->next = iter->next;
            
            // restore the original Linkedlist
            iter->next = front;
            
            copy = copy->next;
            iter = front;
            
        }
        return dummyHead->next;
}


