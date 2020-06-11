class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return false;
        vector<int> f, s;
        for(int i=0; i<n; i++) {
            if(f.size()==0 || (f.size()==1 && f[0]<nums[i])) f.push_back(nums[i]);
            else if(f[0]>nums[i] && f.size()==1) f[0]=nums[i];
            else if(f.size()==2 && f[1]>nums[i] && f[0]<nums[i]) f[1]=nums[i];
            else if(f.size()==2 && nums[i]>f[1]) return true;
            else if(s.size()==0 || (s.size()==1 && s[0]<nums[i])) s.push_back(nums[i]);
            else if(s[0]>nums[i] && s.size()==1) s[0]=nums[i];
            else if(s.size()==2 && s[1]>nums[i] && s[0]<nums[i]) s[1]=nums[i];
            
            if(s.size()==2 && f[1]>s[1]) {
                f.swap(s);
                s.erase(s.begin(), s.end());
            }
        }
        return false;
    }
};

//less space and loops
/*
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3) return false;
        int f=nums[0],s;
        bool first = true;
        for(int i=1;i<nums.size();i++){
            if(nums[i] <= f) f=nums[i];
            else if(first && nums[i] > f) first=false,s=nums[i];
            else if(nums[i] > f && nums[i] <= s) s=nums[i];
            else if(nums[i]>s) return true;
        }
        return false;
    }
};
*/
