class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n=A.size();
        int sum=0, pos=INT_MIN, tsum=0;
        for(int i=0; i<n; i++) {
            if(sum<0) sum=0;
            sum+=A[i];
            tsum+=A[i];
            pos=max(pos, sum);
        }
        sum=0;
        int neg=INT_MIN; //finding maximum negative sum of the ring - subtract this from total sum to get maximum positive sum
        for(int i=0; i<n; i++) {
            if(sum<0) sum=0;
            sum-=A[i];
            neg=max(neg, sum);
        }
        return (neg==abs(tsum))? pos : max(pos, tsum+neg);
    }
};
