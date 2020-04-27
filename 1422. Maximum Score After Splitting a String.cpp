class Solution {
public:
    int maxScore(string s) {
        int n=s.length();
        int c1=0, c0=0, ans=0;
        for(int i=0;i<n;i++)
        {
            c1+=s[i]=='1';
        }
        for(int i=0;i<n-1;i++)
        {
            c1-=s[i]=='1';
            c0+=s[i]=='0';
            ans=max(ans, c0+c1);
        }
        return ans;
    }
};
