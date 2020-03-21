class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1) return n;
        int j=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]!=nums[i+1])
            {
                nums[j]=nums[i];
                j++;
            }
        }
        nums[j++]=nums[n-1]; //last occurence if element is duplicate or not, will not get copied, so here it is copied.
        return j;
}};
