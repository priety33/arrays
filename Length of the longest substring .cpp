#include <bits/stdc++.h>
using namespace std;

int main() {
	int t; cin>>t;
	while(t--)
	{
	    string s; cin>>s;
	    int index[26]; //holds the latest index of each char in the current window
	    for(int i=0;i<26;i++) index[i]=-1;
	    int len=0, start=-1; //start of the current substring window
	    
	    for(int i=0;i<s.length();i++)
	    {
	        if(start<=index[s[i]-'a']) //when start of window already contains same char, update start to remove this char from window.
	        {
	            start=index[s[i]-'a']+1;
	        }
	        index[s[i]-'a']=i;
	        len=max(len,i-start+1);
	    }
	    cout<<len<<endl;
	}
	return 0;
}
