class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int l=0, h=nums[n-1]-nums[0];
        int ans=0;
        while(l<=h)
        {
            int mi=(l+h)/2;
            int count=0, left=0;
            for(int right=0; right<n; right++)
            {
                while(nums[right]-nums[left]>mi) left++;
                count+=right-left; //number of elements that have distance <= mid, with right
            }
            if(count>=k)
            {
                ans=mi; //possible(guess) be true if and only if there are k or more pairs with distance less than or equal to guess
                h=mi-1;
            }
            else l=mi+1;
        }
        return ans;
    }
};

/*
 how do you guarantee there will be a distance equals to the mi ?
 
  Say if mi is not an actual distance between any pairs in the array and count(mi) >= k, 
  this would mean that count(mi - 1) >= k also since mi doesn't exist in the solution space, 
  and therefore mi would not be the first value to satisfy the condition count >= k.
*/
 