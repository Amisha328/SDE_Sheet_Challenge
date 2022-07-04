// Min Stack
// TC-> O(N) | SC-> O(1)

// Implement of minStack.
#include<bits/stdc++.h>
class minStack
{
	public:
		
		stack<int> s;
        int minEle; 
		minStack() 
		{ 
			minEle = 0;
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			if(s.empty()){
                s.push(num);
                minEle = num;
            }
            else{
                if(num >= minEle)
                    s.push(num);
                else if(num < minEle){
                    s.push(2*num-minEle);
                    minEle = num;
                }
            }
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
            int val = -1;
			if(s.empty()) return -1;
            else{
                if(s.top() >= minEle){
                    val = s.top();
                    s.pop();
                }     
                else if(s.top() < minEle){
                    val = minEle;
                    minEle = 2*minEle-s.top();
                    s.pop();
                }
            }
            return val;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			if(s.empty()) return -1;
            else{
                if(s.top() >= minEle)
                    return s.top();        
                else if(s.top() < minEle)
                    return minEle;
            }
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
            if(s.empty()) return -1;
			return minEle;
		}
};