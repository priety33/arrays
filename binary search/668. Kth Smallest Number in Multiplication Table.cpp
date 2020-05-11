class Solution {
public:
    
    int findKthNumber(int m, int n, int k) {
        int l=1, h=m*n;
        int ans=0;
        while(l<=h)
        {
            int mid=(l+h)/2;
            int count=0;
            for(int i=1; i<=m && i<=mid ; i++)
            {
                count+= min(mid/i, n);
            }
            cout<<l<<" "<<h<<" "<<count<<" ";
            if(count>=k)
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return l;
    }
};