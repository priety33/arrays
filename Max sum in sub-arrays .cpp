#include <iostream>
using namespace std;

int main() {
	//code
	int t; cin>>t;
	while(t--)
	{
	    int n; cin>>n;
	    long long a[n];
	    for(int i=0;i<n;i++) cin>>a[i];
	    long long sum=a[0]+a[1];
	    for(int i=2;i<n;i++)
	    {
	        sum=max(sum,a[i]+a[i-1]);
	    }
	    cout<<sum<<endl;
	}
	return 0;
}
