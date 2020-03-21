class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        
        int ans=0;
        int index=-1; //last index violating property
        int prev=0; //count of total valid arrays before index i
        
        for(int i=0;i<A.size();i++)
        {
            if(A[i]<L)
            {
                ans+=prev;
            }
            else if(A[i]>R)
            {
                index=i;
                prev=0;
            }
            else
            {
                ans+=i-index;
                prev=i-index;
            }
        }
        return ans;
    }
};
