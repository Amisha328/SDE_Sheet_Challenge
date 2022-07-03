// Implement Stack using Queue
// Using a single queue

// TC-> O(N) | SC-> O(N)
#include <bits/stdc++.h> 
class Stack {
    public:
    queue<int> q;
    Stack() {
        
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        return q.size();
    }

    bool isEmpty() {
        return (q.size() == 0);
    }

    void push(int element) {
        q.push(element);
        for(int i = 0; i < q.size()-1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        if(isEmpty()) return -1;
        int val = q.front();
        q.pop();
        return val;
    }

    int top() {
        if(isEmpty()) return -1;
        return q.front();
    }
};