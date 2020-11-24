#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll arr[200000];
ll seg[400000];

void build(ll ind,ll low,ll high)
{
	if(low==high)
	{
		seg[ind]=arr[low];
		return;
	}
	
	ll mid=(low+high)/2;
	
	build(2*ind+1,low,mid);
	build(2*ind+2,mid+1,high);
	
	
	seg[ind]=seg[2*ind+1]^seg[2*ind+2];
}


ll query(ll ind,ll low,ll high,ll l,ll r)
{
	//if it lies outside
	if(low>r or high<l)
	return 0;
	
	if(low>=l and high<=r)
	return seg[ind];
	
	ll mid=(low+high)/2;
	
	ll left=query(2*ind+1,low,mid,l,r);
	ll right=query(2*ind+2,mid+1,high,l,r);
	
	return left^right;
}

int main()
{
	
	ll n,q;
	cin>>n>>q;
	for(ll i=0;i<n;i++)
	cin>>arr[i];
	
	build(0,0,n-1);
	
	ll l,r;
	while(q--)
	{
		cin>>l>>r;
		l--;
		r--;
		cout<<query(0,0,n-1,l,r)<<endl;
	}
	
	
	return 0;}
