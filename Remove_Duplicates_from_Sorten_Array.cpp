/*
Remove Duplicates from Sorted Array


Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].

取两个变量做下标进行比较，i, j初始值j = 0, i = 1。如果两个元素不相同，j++，并将变化后的j由i的元素赋值，同时有一个变量len来记录长度，初始为n，没出现相同的就减一。
*/
class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int j = 0, len = n;
        for(int i = 1; i < n; i++){
            if(A[j] == A[i])
                len--;
            else
                A[++j] = A[i];
        }
        return len;
    }
};
