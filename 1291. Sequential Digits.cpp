//without sorting
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        queue<int> q;
        for(int i=1; i<=9; i++) q.push(i);
        while(!q.empty()) {
            int f=q.front();
            q.pop();
            if(f<=high && f>=low) ans.push_back(f);
            if(f>high) break;
            int n=f%10;
            if(n<9) q.push(f*10+(n+1));
        }
        return ans;
    }
};

//sorting
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=1; i<=9; i++) {
            long long num=i;
            for(int j=i+1; j<=9; j++) {
                num*=10; num+=j;
                if(num>=low && num<=high) ans.push_back(num);
                if(num>high) break;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
