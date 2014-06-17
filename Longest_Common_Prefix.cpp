/*
Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.
*/
string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() == 0)
            return "";
        string str = strs[0];
        for(int i = 1; i < strs.size(); i++){
            str = commonpre(str, strs[i]);
        }
        return str;
    }

    string commonpre(string str1, string str2){
        int len = min(str1.size(), str2.size());
        int i;
        for(i = 0; i < len; i++){
            if(str1[i] != str2[i]){
                return str1.substr(0,i);
            }
        }
        return str1.substr(0, len);
    }
