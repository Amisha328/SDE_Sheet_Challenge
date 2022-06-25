// Palindrome Linked List

#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/
LinkedListNode<int>* reverseList(LinkedListNode<int>* head)
{
        LinkedListNode<int>* prev = NULL, *nxt = NULL, *curr = head;
        if(head == NULL) return NULL;
        while(curr != NULL)
        {
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;   
}
bool isPalindrome(LinkedListNode<int> *head) {
	if(head == NULL)
            return true;
        
        LinkedListNode<int> *s = head, *f = head;
        // Find the middle of LL
        while(f->next != NULL && f->next->next != NULL)
        {
            s = s->next;
            f = f->next->next;
        }
        // reverse the second half of the LL
        LinkedListNode<int> *rev = reverseList(s->next);
        LinkedListNode<int>* curr = head;
        while(rev != NULL)
        {
            if(curr->data != rev->data)
                return false;
            
            rev = rev->next;
            curr = curr->next;
        }
         return true;
}