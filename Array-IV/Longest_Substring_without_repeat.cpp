// Longest Substring Without Repeating Characters
// Problem tags:
// Hast Set ; String ; Sliding Window


#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
       int n = s.length();
       int l = 0, r = 0, max_len = 0;
        set<char> st;
        while(r < n)
        {
           // If the character does not in the set
            if(st.find(s[r]) == st.end())
            {
                // Insert the character in set and update the r counter
                st.insert(s[r]);
                r++;
                // Check if the new distance is longer than the current distance
                max_len = max(max_len, r-l);
            }
            else
            {
                // If character exist in the set, i.e., it is a repeated character, 
	      // we update the left side counter l, and continue with the checking for substring.
                st.erase(s[l]);
                l++;
            }
        }
        return max_len;
}