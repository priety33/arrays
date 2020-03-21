class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n=A.size();
        int index=n-1;
        int i=0, j=n-1;
        vector<int> ans(n,0);
        while(i<=j)
        {
            if(abs(A[i])>abs(A[j]))
            {
                ans[index]=A[i]*A[i];
                index--;
                i++;
            }
            else
            {
                ans[index]=A[j]*A[j];
                index--;
                j--;
            }
        }
        return ans;
    }
};
