Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2

vector<int> twoSum(vector<int> &numbers, int target) {  
        multimap<int, int> maps;  
        multimap<int, int>::iterator it;  
        vector<int> vec;  
        bool check;  
        for(int i = 0; i < numbers.size(); i++){  
            check = false;  
            maps.insert(make_pair(numbers[i], i));  
            it = maps.lower_bound(target - numbers[i]);  
            if(target == 2 * numbers[i]){  
                it++;  
                check = true;  
            }  
            if(it != maps.end()  && it -> first == target - numbers[i]){  
                if(check)  
                    it--;  
                vec.push_back(it->second +1);  
                vec.push_back(i+1);  
                break;  
            }  
        }  
        return vec;  
    }
