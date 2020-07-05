class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int dis=0;
        for(auto i: left) dis= max(dis, i);
        for(auto i: right) dis= max(dis, n-i);
        return dis;
    }
};
