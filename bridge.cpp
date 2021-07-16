#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll mex=1e5+7;
vector<ll>adj[mex];
vector<pair<ll,ll>>bridge;
ll intime[mex],Time=0,ans[mex],low[mex];
void dfs(ll child,ll par){
    if(par==-1)
        Time=0;
    intime[child]=Time++;
    low[child]=intime[child];
    for(auto it:adj[child]){
        if(it==par)
            continue;
        if(intime[it]!=-1){
            low[child]=min(low[child],intime[it]);
        } else {
            dfs(it,child);
            low[child]=min(low[child],low[it]);
            if(intime[child]<low[it])
                bridge.push_back({it+1,child+1});
        }
    }
    // cout<<child<<" "<<intime[child]<<" "<<low[child]<<"\n";
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
        for(auto it:bridge){
            cout<<it.first<<" "<<it.second<<"\n";
        }
    }
}
