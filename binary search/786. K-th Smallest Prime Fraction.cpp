class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        int n=A.size();
        double l= 1/(double)A[n-1]; //smallest fraction, can also take l=0
        double h= 1.0, ans=0;
        
        //step 1: find the approximate value of p/q = ans
        while(h-l  >= 0.00000001)
        {
            double mid= (l+h)/2;
            int count=0, right=0;
            for(int left=0; left<n; left++)
            {
                while(right<n && A[left]/(double)A[right]>mid) right++;
                count+= n-right;
            }
            if(count>=K)
            {
                ans=mid; //here we cant do mid+1 or -1 because we are dealing with values<0
                h=mid;
            }
            else l=mid;
        }
        
        //step 2: find a (p, q) pair in array A with the value of p/q nearest to 'ans' 
        set<int> set1(A.begin(), A.end());
		double diff = INT_MAX;
        vector<int> res;
        for (int i = A.size() - 1; i >= 0; i--) {
            int d = A[i] * ans + 0.5; //find the nearst integer d with d / A[i] == mid
            if (set1.find(d) != set1.end()) {
                double cur_diff = fabs((double) d / (double) A[i] - ans);
                if (diff > cur_diff) {
                    res = {d, A[i]};
                    diff = cur_diff;
                }
            }
        }
        return res;
    }
};