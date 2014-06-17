/*
3Sum Closest


Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

 For example, given array S = {-1 2 1 -4}, and target = 1.

    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/
int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());
        int check = 0, low, high, min_ = num[1] + num[0] + num.back();
        for(int i = 0; i < (int)num.size() - 2; i++){
            low = i+1, high = (int)num.size() - 1;
            while(low < high){
                check = num[i] + num[low] + num[high];
                if(check == target){
                    return target;
                }else{
                    if(check > target)
                        high--;
                    else
                        low++;
                    if(abs(min_ - target) > abs(check - target))
                        min_ = check;
                }
            }
        }
        return min_;
    }
