class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n=A.size();
        int start=0,end=0;
        int i=0;
        while(i<n && A[i]%2==0) i++; //skipping all evens
        start=i;
        end=i;
        while(i<n && A[i]%2==1) i++;  //skipping all odds
        end=i;
        while(start<end && end<n)
        {
            if(A[end]%2==0)
            {
                swap(A[start],A[end]);
                start++;
                end++;
            }
            else end++;
        }
        return A;
    }
};
