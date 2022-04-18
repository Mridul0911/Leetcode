#include <bits/stdc++.h>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	int n;
	cin>>n;
	vector<int> inp(n);
	for(int i=0;i<n;i++)
	{
	    cin>>inp[i];
	}
	for(int i=n-1;i>=0;i--)
	{
	    cout<<inp[i]<<" ";
	}
	cout<<endl;
	}
	return 0;
}