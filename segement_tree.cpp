//AUTHOR - NIMISH UPADHYAY
//FROM IIIT ALLAHABAD
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define NIMISH ios_base::sync_with_stdio(false);cin.tie(NULL);
#define UPADHYAY int t;cin>>t;while(t--)
ll n,c[300001],ans[300001*4],q;
ll build(ll x,ll y,ll i){
    if(x==y){
        ans[i]=c[x];
        return ans[i];
    }
    ll mid=x+(y-x)/2;
    return ans[i]=build(x,mid,2*i+1)^build(mid+1,y,2*i+2);
}
ll update(ll x,ll y,ll i,ll value,ll index){
    if(x==y){
        ans[i]=ans[i]^value;
        return ans[i];
    }
    ll mid=x+(y-x)/2;
    if(index<=mid)
        update(x,mid,2*i+1,value,index);
    else
        update(mid+1,y,2*i+2,value,index);

    return ans[i]=ans[2*i+1]^ans[2*i+2];
}
ll query(ll x,ll y,ll i,ll j,ll p){
    if(i<=x && j>=y)
        return ans[p];
    if(i>y || j<x)
        return 0;
    ll mid = x+(y-x)/2;
    return query(x,mid,i,j,2*p+1)^query(mid+1,y,i,j,2*p+2);
}
int main(){
    NIMISH;
    cin>>n>>q;
    ll i,j,x;
    for(i=0;i<n;i++)
        cin>>c[i];
    build(0,n-1,0);
    while(q--){
        cin>>x>>i>>j;
        i--;
        if(x==1)
        update(0,n-1,0,j,i);
        else{
            j--;
            cout<<query(0,n-1,i,j,0)<<"\n";
        }
    }
}
