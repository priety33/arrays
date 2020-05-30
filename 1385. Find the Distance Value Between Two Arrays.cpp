//using binary search find closest element in arr2, to each arr1[i]
class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int n=arr2.size();
        int ans=0;
        for(int i=0; i<arr1.size(); i++) {
            int l=0, h=n-1;
            while(l<h){
                int mid=(l+h)/2;
                if(mid==l) break; //because exact same arr1[i] may not be present, it this will go into infinite loop
                if(arr2[mid]>arr1[i]) h=mid;
                else l=mid;
            }
            if(abs(arr2[l]-arr1[i])<=d || abs(arr2[h]-arr1[i])<=d) ans++;
        }
        return arr1.size()-ans;
    }
};
