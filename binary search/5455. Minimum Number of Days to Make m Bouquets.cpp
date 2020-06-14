class Solution {
public:
    int minDays(vector<int>& b, int m, int k) {
        if(b.size()<m*k) return -1;
        int n=b.size();
        int left=1, right= 1e9;
        while(left < right) {
            int mid=(left+right)/2;
            int count=0, bouq=0;
            for(int j=0; j<n; j++) {
                if(b[j]>mid) count=0;
                else count++;
                
                if(k==count) {
                    bouq++; count=0;
                }
            }
            if(bouq>=m) right=mid;
            else left=mid+1;
        }
        return left;
    }
};
