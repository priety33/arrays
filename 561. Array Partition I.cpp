/*
In short, the sum of all number is fixed, to maximize the sum of smaller group, you want to minimize the diff of the sum of 2 groups.
And the best way to do that is to pair the numbers that are next to each other in sorted order.
*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum=0;
        for(int i=0;i<nums.size()-1;i=i+2) sum+=nums[i];
        return sum;
    }
};
