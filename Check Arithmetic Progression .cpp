#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    if(n==1) 
	    {
	        cout<<"YES"<<endl;
	        continue;
	    }
	    int a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    sort(a,a+n);
	    int d=a[1]-a[0];
	    bool print=false;
	    for(int i=1;i<n;i++)
	    {
	        if(a[i]-a[i-1]!=d)
	        {
	            print=true;
	            cout<<"NO"<<endl;
	        }
	    }
	    if(!print) cout<<"YES"<<endl;
	}
	return 0;
}
