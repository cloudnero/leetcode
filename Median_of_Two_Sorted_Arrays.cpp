/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

简单的来说就是找出A，B中第k小的元素。可以在A中寻找第p的元素，然后在B寻找k-p的元素，如果A[p-1] == B[k-p-1]，说明找到了并返回。

如果找到的A > B, 在A+p与B中寻找第k-p元素，如果A<B,在A，B+k-p寻找第p元素。
*/

double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int c = m + n;
        if(c % 2 == 0)
            return (findkth(A,m, B, n, c/2) + findkth(A, m, B, n, c/2 +1) ) /2;
        else
            return findkth(A, m, B, n, c / 2 + 1);
}
//下面的函数最开始用递归写的，改了下，保证在O(log (m+n))
double findkth(int A[], int m, int B[], int n, int k){
       while(1){
            if(n < m){
                int *c = B;
                B = A;
                A = c;
                int d = m;
                m = n;
                n = d;
            }
                //return findkth(B, n, A, m, k);
            //对边界的判断
            if(m == 0)
                return B[k-1];
            if(k == 1)
                return min(A[0], B[0]);
            
            int pa = min(m, k/2);     //这里关于k/2的取值，其实只要保证pa>1且不超过m且pb大于1.所以还可以改成k-1,k/3+1，等等
            int pb = k - pa;
            if(A[pa-1] < B[pb-1]){
                A += pa;
                m -= pa;
                k = pb;
            }
                //return findkth(A+pa, m-pa, B, n, pb);
            else if(A[pa-1] > B[pb-1]){
                B += pb;
                n -= pb;
                k = pa;
            }
                //return findkth(A, m, B+pb, n - pb, pa);
            else
                return A[pa-1];
       } 
    }

