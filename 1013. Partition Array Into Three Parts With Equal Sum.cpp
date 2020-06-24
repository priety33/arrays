class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum=0;
        for(auto i:A) sum+=i;
        if(sum%3!=0) return false;
        sum=sum/3;
        int set=0, cursum=0, i;
        for(i=0; i<A.size(); i++) {
            cursum+= A[i];
            if(cursum==sum) {
                cursum=0; set++;
            }
            if(set==3) {
                i++; cursum=0; break;
            }
        }
        while(i<A.size()) cursum+= A[i++]; //edge case-> zeroes sum formed by end elements
        return set==3 && cursum==0;
    }
};
