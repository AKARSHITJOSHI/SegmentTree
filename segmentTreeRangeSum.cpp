#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mod=1e9+7;
ll arr[200000];
ll seg[4*200000];

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
	
	seg[ind]=seg[2*ind+1]+seg[2*ind+2];
	
}

ll query(ll ind,ll low,ll high,ll l,ll r)
{
	if(low>=l and high<=r)
	return seg[ind];
	
	//does not lie
	if(high<l or low>r) return 0;
	
	//it overlaps, we search from it's left and right
	ll mid=(low+high)/2;
	ll left=query(2*ind+1,low,mid,l,r);
	ll right=query(2*ind+2,mid+1,high,l,r);
	
	return left+right;
}

void update(int ind,int low,int high,int node,int val)
{
	if(node<low or node>high)
	return;
	
	seg[ind]+=val;
	
	if(low!=high)
	{
		ll mid=(low+high)/2;
		update(2*ind+1,low,mid,node,val);
		update(2*ind+2,mid+1,high,node,val);
	}
//	seg[ind]=seg[2*ind+1]+seg[2*ind+2];
}
int main(){
		
		ll n,q;
		cin>>n>>q;
		for(ll i=0;i<n;i++)
		cin>>arr[i];
		
		
		build(0,0,n-1);
		
		while(q--)
		{
			ll choice;
			cin>>choice;
			ll l,r;
			cin>>l>>r;
			l--;
			r--;
			if(choice==1)
			{
				ll curr=arr[l];
				ll new_val=r+1;//because r--
				if(new_val>=curr)
				{
					ll diff=new_val-curr;
					update(0,0,n-1,l,diff);
				}
				else
				{
					ll diff=new_val-curr;
					update(0,0,n-1,l,diff);
				}
			}
			else
			cout<<query(0,0,n-1,l,r)<<endl;
		}
	
	return 0;}
