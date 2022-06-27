// Sort a Stack
// Problem tag: Stack, Recursion
// Explantion:
// https://rb.gy/dndys7

#include<bits/stdc++.h>
void insertNum(stack<int> &s, int x)
{
    if(s.empty() || (!s.empty() && s.top() <= x))
    {
         s.push(x);
         return;
    }
    
    int topEle = s.top();
    s.pop();
    
    insertNum(s, x);
    s.push(topEle);
}
void sortStack(stack<int> &s)
{
   if(s.empty())
        return;
   int num = s.top();
   s.pop();
   
   sortStack(s);
   insertNum(s, num);
}