#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    int arr[n],dep[n];
	    for(int i=0;i<n;i++) cin>>arr[i];
	    for(int i=0;i<n;i++) cin>>dep[i];
	    
	    sort(arr,arr+n);
	    sort(dep,dep+n);
	    
	    int platform=1;
	    int ans=1;
	    int i=1,j=0;
	    while(i<n && j<n)
	    {
	        if(arr[i]<dep[j])
	        {
	            platform++;
	            ans=max(ans,platform);
	            i++;
	        }
	        else
	        {
	            platform--;
	            j++;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
