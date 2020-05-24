/*
Given an unsorted array A. Find the minimum number of removals required such that twice of minimum element
in the array is greater than the maximum in the array.-> removal can be from anywhere in the array
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--) {
	    int n; cin>>n; vector<int> v(n); 
	    for(int i=0;i<n;i++) cin>>v[i];
	    sort(v.begin(), v.end());
	    int i=n-1, j=n-1, ans=INT_MAX;
	    while(i>=0){
	        while(i>=0 && v[i]*2>=v[j]) i--;
	        ans=min(ans, n-(j-i));
	        j--;
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
