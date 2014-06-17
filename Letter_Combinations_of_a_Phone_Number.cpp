/*
Letter Combinations of a Phone Number


Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/
vector<string> letterCombinations(string digits) {
        vector<string> vec, phone(10);
        phone[2] = "abc";
        phone[3] = "def";
        phone[4] = "ghi";
        phone[5] = "jkl";
        phone[6] = "mno";
        phone[7] = "pqrs";
        phone[8] = "tuv";
        phone[9] = "wxyz";
        letters(phone, 0, "", vec, digits);
        return vec;
    }

    void letters(vector<string> &phone, int num, string str, vector<string> &vec, string digits){
        if(num == digits.size()){
            vec.push_back(str);
            return;
        }
        int c = digits[num] - '0';
        for(int i = 0; i < phone[c].size(); i++){
            letters(phone, num+1, str + phone[c][i], vec, digits);
        }
    }
