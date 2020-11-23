#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod=1e9+7;
ll arr[200000];
ll seg[400000];

ll min(ll left,ll right)
{return (left<right)?left:right;}

void build(ll ind,ll low,ll high)
{
	if(low==high)
	{seg[ind]=arr[low];
		return;}
	
	ll mid=(low+high)/2;
	
	build(2*ind+1,low,mid);
	build(2*ind+2,mid+1,high);
	
	seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
}

ll query(ll ind,ll low,ll high,ll l,ll r)
{
	//if segment lie within range
	if(low>=l and high<=r)
	return seg[ind];
	
	if(high<l or low>r)
	return 999999999;
	
	ll mid=(low+high)/2;
	
	ll left=query(2*ind+1,low,mid,l,r);
	ll right=query(2*ind+2,mid+1,high,l,r);
	
	return min(left,right);
}


void update(ll ind,ll low,ll high,ll node,ll val)
{
	if(node<low or node>high)
	return;
	
	if(low==high and node==low)
	{seg[ind]=val;}
	
	
	if(low!=high)
	{
		ll mid=(low+high)/2;
		
		update(2*ind+1,low,mid,node,val);
		update(2*ind+2,mid+1,high,node,val);
		
		seg[ind]=min(seg[2*ind+1],seg[2*ind+2]);
	}
	
}

int main()
{
	
	ll n,q;
	cin>>n>>q;
	
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	build(0,0,n-1);
	
	ll l,r;
	while(q--)
	{
		ll choice;
		cin>>choice;
		cin>>l>>r;
		l--;
		r--;
		
		if(choice==1)
		{
			update(0,0,n-1,l,r+1);
		}
		else
		cout<<query(0,0,n-1,l,r)<<endl;
	}

return 0;}
