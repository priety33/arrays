int numberOfBits(const int &a){
    int count = 0;
    int n = a;
    
    while(n!=0){
        count++;
        n = n&(n-1);
    }
    
    return count;
}

bool compare(const int &a,const int &b){
    int no_a = numberOfBits(a);
    int no_b = numberOfBits(b);
    
    if(no_a==no_b)
        return a<b;
    
    return no_a<no_b;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        
        if(n==0 || n==1)
            return arr;
        
        sort(arr.begin(),arr.end(),compare);
        
        return arr;
    }
};
