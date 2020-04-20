class Solution {
public:
    
    int binary(vector<int>& nums, int l, int h, int target)
    {
        if(l>h) return -1;
        
        int mid=(l+h)/2;
        
        if(nums[mid]==target) return mid;
        else if(nums[mid]<nums[h])
        {
            if(target<=nums[h] && target>nums[mid]) return binary(nums, mid+1, h, target); //RHS of mid will always be greater than mid here, but LHS will be mixed
            return binary(nums, l, mid-1, target);
        }
        else
        {
            if(target>=nums[l] && target<nums[mid]) return binary(nums, l, mid-1, target); //LHS of mid will always be less than mid here, but RHS will be mixed
            return binary(nums, mid+1, h, target);
        }
    }
    
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        return binary( nums, 0, n-1, target);
    }
};
