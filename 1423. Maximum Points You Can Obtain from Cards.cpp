class Solution {
public:
    
    int maxScore(vector<int>& card, int k) {
        int n=card.size();
        int ps[n+1];
        ps[0]=0;
        for(int i=1;i<=n;i++) ps[i]=ps[i-1]+card[i-1];
        int ans=0;
        for(int i=0;i<=k;i++)
        {
            ans=max(ans, ps[i]+ps[n]-ps[n-(k-i)]);
        }
        return ans;
    }
};
