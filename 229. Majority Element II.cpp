class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        vector<int> ans;
        if(nums.size()==0) return ans;
        int a=floor(nums.size()/3);
        
        int el1=nums[0];
        int count1=1;
        int el2=nums[0];
        int count2=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==el1) count1++;
            else if(nums[i]==el2) count2++;
            else if(nums[i]!=el1 && nums[i]!=el2 && count1>0 && count2>0)
            {
                count1--;
                count2--;
            }
            else
            {
                if(count1==0)
                {
                    el1=nums[i];
                    count1=1;
                }
                
                if(count2==0)
                {
                    el2=nums[i];
                    count2=1;
                }
            }
        }
        
        count1=0, count2=0;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==el1) count1++;
            else if(nums[i]==el2) count2++;
        }
        
        if(count1>a) ans.push_back(el1);
        if(count2>a) ans.push_back(el2);
        
        return ans;
        
    }
};
