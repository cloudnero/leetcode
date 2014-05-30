/*
 The string "PAYPALISHIRING" is written in a zigzag pattern on a given
 number of rows like this: (you may want to display this pattern in a
 fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);

convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
*/

string convert(string s, int nRows) {
        if(nRows == 1)
            return s;
            
        vector<string> ans(nRows, "");
        bool check = true;
        
        for(int i = 0, j = 0; i < s.size(); i++){
            ans[j] += s[i];
            if(check){
                j++;
            }else{
                j--;
            }
            if(j == 0 || j == nRows - 1){
                check = !check;
            }
        }
        string s2 = "";
        for(int i = 0; i < nRows; i++)
            s2 += ans[i];
            
        return s2;
    }
