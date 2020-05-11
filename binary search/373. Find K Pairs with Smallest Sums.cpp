class Solution {
public:
    
    static bool compare(vector<int>a, vector<int>b)
    {
        return a[0]+a[1]<b[0]+b[1];
    }
    
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        vector<vector<int>> res;
        int n=a.size(), m=b.size();
        if(k>=m*n)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++) res.push_back({a[i], b[j]});
            }
            return res;
        }
        int l=a[0]+b[0], h=a[n-1]+b[m-1];
        int ans=0;
        while(l<=h)
        {
            int mid=(l+h)/2;
            int right=m-1, count=0;
            for(int left=0; left<n; left++)
            {
                while(right>=0 && a[left]+b[right]>mid) right--;
                count+= right+1;
            }
            if(count>=k)
            {
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        cout<<ans;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(a[i]+b[j]>ans) break;
                res.push_back({a[i],b[j]});
            }
        }
        sort(res.begin(), res.end(), compare);
        res.erase(res.begin()+k, res.end());
        return res;
    }
};