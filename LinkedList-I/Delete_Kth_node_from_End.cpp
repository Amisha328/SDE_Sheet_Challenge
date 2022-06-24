// Delete Kth node From End

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

#include <bits/stdc++.h> 
LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int K)
{
    if(head == NULL || K == 0) return head;
    LinkedListNode<int> *dummy = new LinkedListNode<int>(1);
    LinkedListNode<int> *fast = dummy;
    LinkedListNode<int> *slow = dummy;
    dummy->next = head;
    // Let fast pointer take a n node lead in the beginning
    for(int i = 1; i <= K; i++)
    {
        fast = fast->next;
    }
    // Now, let both slow and fast travel forward until fast->next == NULL
    while(fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = slow->next->next;
    return dummy->next;
}