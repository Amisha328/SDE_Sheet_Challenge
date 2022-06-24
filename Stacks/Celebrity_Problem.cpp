// Celebrity Problem
/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

// TC-> O(n) | SC-> O(1)
#include <bits/stdc++.h> 
int findCelebrity(int n) {
    int c = 0;
    for(int i = 1; i < n; i++){
        // if c knows any i person then it can't be the Celebrity person
        if(knows(c,i))
            c = i;
    }
    for(int i = 0; i < n; i++){
        // i != c is used to avoid person knowing itself condition
        // c knows i or i does not know c
        // then c can't be a celebrity
        if(i != c and (knows(c,i)))
           return -1;
       }
   return c;
}