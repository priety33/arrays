class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int before[n];
        before[0]= (nums[0]==0)? 0:1;
        for(int i=1;i<n;i++)
        {
            before[i]=before[i-1]*nums[i-1];
        }
        vector<int> ans;
        ans.push_back(before[n-1]);
        int after=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            ans.insert(ans.begin(), before[i]*after);
            after*=nums[i];
        }
        return ans;
    }
};
