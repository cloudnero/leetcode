/*
3Sum


Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.

For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());
        set<int> sets;
        vector<int> vec;
        vector<vector<int> > vecall;
        for(int i = 0; i < (int)num.size() - 2; i++){
            if(i > 0 && num[i] == num[i-1])   //不是第一个遍历的值且和前一个值相等，就跳过
                continue;
            for(int j = i + 1; j < (int)num.size() - 1; j++){
                if(j > i+1 && num[j] == num[j-1])
                    continue;
                for(int k = j + 1; k < num.size(); k++){
                    if(k > j+1 && num[k] == num[k-1])
                        continue;
                    if(num[i] + num[j] + num[k] == 0){
                        vec.push_back(num[i]);
                        vec.push_back(num[j]);
                        vec.push_back(num[k]);
                        vecall.push_back(vec);
                        vec.clear();
                        break;
                    }
                }
            }
        }
        return vecall;
    }
