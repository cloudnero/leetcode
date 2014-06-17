/*
Valid Parentheses


Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
bool isValid(string s) {
        stack<char> sta;
        char c;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                sta.push(s[i]);
                continue;
            }
            if(sta.empty())
                return false;
            c = sta.top();
            if((c == '(' && s[i] == ')') || (c == '[' && s[i] == ']') || (c == '{' && s[i] == '}')){
                sta.pop();
                continue;
            }else
                return false;
        }
        if(sta.empty())
            return true;
        else
            return false;
    }
