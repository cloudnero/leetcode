/*
Longest Substring Without Repeating Characters

Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
For "bbbbb" the longest substring is "b", with the length of 1.

将元素遍历，并将结果保存在vector里，每次遍历新元素时去vector查找是否存在该元素，如果不存在就将该元素添加，如果存在，查找出存在的元素位置k，并将此时的vector的长度与maxlen作比较，去最大值。然后将vector的头元素到k全部删除掉，并将k添加进vector。
*/
int lengthOfLongestSubstring(string s) {
        vector<char> ans;
        int max_len = 0;      //记录最大长度
        for(int i = 0; i < s.size(); i++){
            vector<char>::iterator it = find(ans.begin(), ans.end(), s[i]);
            if(it != ans.end()){       //如果有重复的元素
                max_len = (ans.size() > max_len) ? ans.size() : max_len;
                ans.erase(ans.begin(), ++it);       //删除掉重复的元素及重复元素之前的元素
            }
            ans.push_back(s[i]);    //无论重复与否，都要把它添加进去
        }
         //这里需要再做一次判断，因为最后一个子串的if语句不会执行，所以需要在做一次判断。
        max_len = (ans.size() > max_len) ? ans.size() : max_len;
         
        return max_len;
    }
