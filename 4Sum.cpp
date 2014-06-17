/*
4Sum


Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:

    Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
    The solution set must not contain duplicate quadruplets.

    For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

    A solution set is:
    (-1,  0, 0, 1)
    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
*/
vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > vecall;
        vector<int> vec;
        sort(num.begin(), num.end());
        for(int i = 0; i < (int)num.size() - 3; i++){
            if(i > 0 && num[i] == num[i-1])
                continue;
            for(int j = i + 1; j < (int)num.size() - 2; j++){
                if(j > i +1 && num[j] == num[j-1])
                    continue;
                int low = j + 1, high = num.size() - 1;
                while(low < high){
                    if(low > j+1 && num[low] == num[low-1]){
                        low++;
                        continue;
                    }
                    if(high < num.size() - 1 && num[high] == num[high+1]){
                        high--;
                        continue;
                    }
                    int check = num[i] + num[j] + num[low] + num[high];
                    if(check == target){
                        vec.push_back(num[i]);
                        vec.push_back(num[j]);
                        vec.push_back(num[low]);
                        vec.push_back(num[high]);
                        vecall.push_back(vec);
                        vec.clear();
                        low++, high--;
                    }else if(check > target)
                        high--;
                    else low++;
                }
            }
        }
        return vecall;
    }
