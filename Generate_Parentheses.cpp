/*
Generate Parentheses


Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

递归，用变量str来保存当前的括号样式，之后str会有两种变化，一种后边跟（，一种后边跟）。用两个数l，r记录左右括号的个数，如果l<r说明是非法的，如果l=r=n，说明是成功的，将str存入。
*/
vector<string> generateParenthesis(int n) {
        vector<string> vec;
        findit(n, 0, 0, "", vec);
        return vec;
    }

    void findit(int n, int l, int r, string str, vector<string> &vec){
        if(l < r)
            return;
        if(l + r == n * 2){
            if(l == n)
                vec.push_back(str);
            return;
        }
        findit(n, l+1, r, str+"(", vec);
        findit(n, l, r+1, str+")", vec);
    }
