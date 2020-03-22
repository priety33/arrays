#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    long long n; cin>>n;
	    bool a[n+1];
	    for(int i=0;i<=n;i++) a[i]=true;
	    for(int i=2; i<=floor(sqrt(n)); i++)
	    {
	        if(a[i])
	        {
	                for(int j=i*i;j<=n;j=j+i)
	            {
	                a[j]=false;
	            }
	        }
	    }
	    for(int i=2;i<=n;i++) if(a[i]) cout<<i<<" ";
	    cout<<endl;
	}
	return 0;
}
