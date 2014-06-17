/*
Integer to Roman

Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/
string intToRoman(int num) {
        map<int,string> roman;
        roman.insert(make_pair(1000,"M"));
        roman.insert(make_pair(900,"CM"));
        roman.insert(make_pair(500,"D"));
        roman.insert(make_pair(400,"CD"));
        roman.insert(make_pair(100,"C"));
        roman.insert(make_pair(90,"XC"));
        roman.insert(make_pair(50,"L"));
        roman.insert(make_pair(40,"XL"));
        roman.insert(make_pair(10,"X"));
        roman.insert(make_pair(9,"IX"));
        roman.insert(make_pair(5,"V"));
        roman.insert(make_pair(4,"IV"));
        roman.insert(make_pair(1,"I"));
        
        string ans;
        for(map<int,string>::reverse_iterator it = roman.rbegin(); it != roman.rend(); it++){  //因为要从高位开始，所以这里用reverse_iterator
            while(num >= it -> first){
                ans += it -> second;
                num -= it -> first;
            }
        }
        return ans;    
    }
