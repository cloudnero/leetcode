/*
Remove Element


Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.

遍历对比elem，用变量记录下第一个element的下标，之后如果发现两元素不同，将该元素赋值给记录的下标位置。思路同Remove Duplicates from Sorted Array
*/
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int len = n, j = -1;
        for(int i = 0; i < n; i++){
            if(A[i] == elem){
                len--;
                if(j < 0)
                    j = i;
            }else if(j >= 0){
                A[j++] = A[i];
            }
        }
        return len;
    }
};
