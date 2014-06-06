/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

spoilers alert... click to show requirements for atoi.
Requirements for atoi:

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/


int atoi(const char *str) {
        int len = strlen(str);
        set<char> sets;
        sets.insert('0');
        sets.insert('1');
        sets.insert('2');
        sets.insert('3');
        sets.insert('4');
        sets.insert('5');
        sets.insert('6');
        sets.insert('7');
        sets.insert('8');
        sets.insert('9');
        
        long long ans = 0;
        int a = 0, b = 0;
        bool isfalse = false;
        int i = 0, j = len-1;
        while(str[i] == ' '){
            i++;
            if(i == len)
                break;
        }
        
        while(str[j] == ' '){
            j--;
            if(j < 0)
            break;
        }
        
        for(; i <= j; i++){
            if(sets.count(str[i])){
                ans *= 10;
                ans += str[i] - '0';
                continue;
            }
                
            if(str[i] == '+')
                a++;
            else if(str[i] == '-'){
                isfalse = true;
                b++;
            }else
                break;
                
            if(a+b>1)
                break;
        }
        if(isfalse)
            ans = -ans;
        if(ans > INT_MAX)
            ans = INT_MAX;
        else if(ans < INT_MIN)
            ans = INT_MIN;
            
        return ans;
    }
