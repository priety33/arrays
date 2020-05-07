class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        int ans=0, i=0;
        for(i;i<f.size();i++) if(f[i]) break;
        ans=i/2;
        int start=i, end=i+1;
        while(start<end && end<f.size())
        {
            while(end<f.size() && !f[end]) end++;
            if((end-start-1)%2==0 && end!=f.size()) ans+=(end-start-2)/2; //even number of 0's in between
            else ans+=(end-start-1)/2;
            start=end;
            end++;
        }
        if(i==f.size()) //array of all 0's
        {
            int a=f.size();
            if(a%2) a++;
            return a/2>=n;
        }
        return ans>=n;
    }
};
