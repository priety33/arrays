//same characters should be present in both arrays
//either use map or,

class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
       int res = 0;
        for (int i = 0; i < target.size(); i++) {
            res ^= target[i]; 
            res ^= arr[i];
        }
        
        return res == 0;
    }
};
