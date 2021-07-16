#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mex=1e5+7;
vector<ll>adj[mex];
ll intime[mex],Time,ans[mex],low[mex];
void dfs(ll child,ll par){
    intime[child]=Time++;
    low[child]=intime[child];
    ll children=0;
    for(auto it:adj[child]){
        if(it==par)
            continue;
        if(intime[it]!=-1){
            low[child]=min(low[child],intime[it]);
        } else {
            children++;
            dfs(it,child);
            low[child]=min(low[child],low[it]);
            if(intime[child]<=low[it] && par!=-1)
                ans[child]=1;
        }
    }
    // cout<<child<<" "<<intime[child]<<" "<<low[child]<<"\n";
    if(par==-1 && children>1)
        ans[child]=1;
}
int main(){
    ll test;
    cin>>test;
    while(test--){
        ll n,e;
        cin>>n>>e;
        for(ll i=0;i<n;i++){
            adj[i].clear();
            intime[i]=-1;
            ans[i]=-1;
        }
        while(e--){
            ll x,y;
            cin>>x>>y;
            x--,y--;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        Time=0;
        for(ll i=0;i<n;i++)
            if(intime[i]==-1)
                dfs(i,-1);
        for(ll i=0;i<n;i++)
            if(ans[i]==1)
                cout<<i+1<<" ";
        cout<<"\n";
    }
}
