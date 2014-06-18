/*
Implement strStr()


Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.

这道题按部就班的做就是从前到后遍历了，但是我建议各位用kmp来做，可以掌握多点知识。
*/
class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int len1 = strlen(haystack), len2 = strlen(needle);
        int *next = new int[len1];
        int i = 0, j = 0, index = 0;
        
        if(haystack == needle || (haystack != NULL && strlen(needle) == 0))
            return haystack;
        
        if(len1 < len2)
            return NULL;
        getnext(needle, next);
        
        while(i < len1 && j < len2){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }else{
                index += j - next[j];
                if(next[j] == -1){
                    j = 0;
                    i++;
                }else
                    j = next[j];
            }
        }
        
        if(needle[j] == '\0')
            return haystack+index;
        else
            return NULL;
    }
private:
    void getnext(char *T, int *next){
        int k = 0, j = -1;
        next[0] = -1;
        while(k < strlen(T) - 1){
            if(j == -1 || T[j] == T[k]){
                j++;
                k++;
                if(T[j] == T[k])
                    next[k] = next[j];
                else
                    next[k] = j;
            }else
                j = next[j];
        }
    }
};
