class Solution {
public:
    
    int count(vector<vector<int>>& mat, int m, int n, int target, int sum, int r, int k) //r is row number
    {
        if(sum>target) return 0;
        if(r==m) return 1;
        int ans=0;
        for(int c=0; c<n; c++) //c is col
        {
            int ways= count(mat, m, n, target, sum+mat[r][c], r+1, k-ans);
            if(ways==0) break;
            ans+=ways;
            if(ans>k) break;
        }
        return ans;
    }
    
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        int l=m, h=m*5000;
        int ans=0;
        while(l<=h)
        {
            int mid=(l+h)/2;
            int cnt= count(mat, m, n, mid, 0, 0, k); cout<<mid<<" "<<cnt<<" ";
            if(cnt>=k)
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }
};
