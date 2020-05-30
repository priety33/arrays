//O(1) space
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size(), mine= INT_MAX;
        bool flag=false;
        for(int i=1; i<n; i++) {
            if(nums[i-1]>nums[i]) flag=true;
            if(flag) mine= min(mine, nums[i]);
        }
        
        flag=false;
        int maxe=INT_MIN;
        for(int i=n-2; i>=0; i--) {
            if(nums[i]>nums[i+1]) flag=true;
            if(flag) maxe=max(maxe, nums[i]);
        }
        
        int l,r;
        for(l=0; l<n; l++) if(mine<nums[l]) break;
        for(r=n-1; r>=0; r--) if(maxe>nums[r]) break;
        return (r-l<0)? 0 : r-l+1;
    }
};

//stack
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        stack<int> s;
        int l=n-1;
        for(int i=0; i<n; i++) {
            while(!s.empty() && nums[s.top()]>nums[i]) {
                l=min(l, s.top());
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        int r=0;
        for(int i=n-1; i>=0; i--) {
            while(!s.empty() && nums[s.top()]<nums[i]) {
                r=max(r, s.top());
                s.pop();
            }
            s.push(i);
        }
        return r-l>0? r-l+1 : 0;
    }
};
