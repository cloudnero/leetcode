/*
Given a string S, find the longest palindromic substring in S. You may
 assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

string longestPalindrome(string s) {
        
        string s2 = "#";
        for(int i = 0; i < s.size(); i++)
            s2 = s2 + s[i] + "#";
            
        int mx = 0, mid = 0;
        int *p = new int[s2.size()];
        
        for(int i = 0; i < s2.size(); i++){
            p[i] = mx > i ? (p[2 * mid - i] > mx - i+1 ? mx - i+1 : p[2 * mid - i]) : 1;
            while(i - p[i] >= 0 && s2[p[i] + i] == s2[i - p[i]])
                p[i]++;
            
            if(p[i] + i - 1 > mx){
                mx = p[i] + i - 1;
                mid = i;
            }
        }
        int max = 0, index = 1;
        for(int i = 0; i < s2.size(); i++){
            max = (p[i] > max) ? p[index = i] : max;
        }
        delete[] p;
        
        return s.substr((index - max + 1) / 2, max - 1);
    }
