/*
Roman to Integer

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/
int romanToInt(string s) {
        int ans = 0;
        for(int i = s.size() - 1; i >= 0; i--){
            switch(s[i]){
                case 'I':
                    ans += (ans >= 5) ? -1 : 1;
                    break;
                case 'X':
                    ans += 10 * ((ans >= 50) ? -1 : 1);
                    break;
                case 'V':
                    ans += 5;
                    break;
                case 'C':
                    ans += 100 * ((ans >= 500) ? -1 : 1);
                    break;
                case 'L':
                    ans += 50;
                    break;
                case 'M':
                    ans += 1000;
                    break;
                case 'D':
                    ans += 500;
                    break;
            }
        }
        return ans;
    }
