class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0], pos=nums[0], neg=nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]>0)
            {
                pos=max(pos*nums[i], nums[i]);
                neg=min(neg*nums[i], nums[i]);
            }
            else
            {
                pos=max(neg*nums[i], nums[i]);
                neg=min(pos*nums[i], nums[i]);
            }
            ans=max(ans, max(pos, neg));
        }
        return ans;
    }
};

//product maximise- max positive*positive  or  max negative*negative  or  onlt nums[i]
// therefore we are maximising positive at each step and minimising negative, and comparing them with answer at each iteration 
to check if we can form max product till here, and if product is less we drop previous subarray product and start from nums[i]
