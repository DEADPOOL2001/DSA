
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
void dfs(ll v,ll u,ll par[],ll hei[],vector<ll>adj[]){
    hei[v]=1+hei[u];
    par[v]=u;
    for(auto it:adj[v])
        if(it!=u)
            dfs(it,v,par,hei,adj);
}
int main(){
    ll t,val=1;
    cin>>t;
    while(t--){
        cout<<"Case "<<val<<":\n";
        val++;
        ll n,q;
        cin>>n;
        vector<ll>v[n];
        ll parent[n],height[n],count=n-1,i,j,dp[n][23];
        memset(dp,0,sizeof(dp));
        height[0]=-1;
        while(count--){
            ll x,y;
            cin>>x>>y;
            v[x].pb(y);
            v[y].pb(x);
        }
        // for(i=0;i<n;i++){
        //     ll x;
        //     cin>>x;
        //     while(x--){
        //         cin>>j;
        //         j--;
        //         v[j].pb(i);
        //         v[i].pb(j);
        //     }
        // }
        dfs(0,0,parent,height,v);
        for(i=0;i<n;i++)
            dp[i][0]=parent[i];
        for(i=1;n>=((ll)1<<i);i++)
            for(j=0;j<n;j++)
                dp[j][i]=dp[dp[j][i-1]][i-1];
        // for(i=0;i<n;i++)
        //    cout<<parent[i]<<" ";
        // cout<<"\n";
        // for(i=0;i<n;i++){
        //    for(j=0;j<5;j++)
        //        cout<<dp[i][j]<<" ";
        //    cout<<"\n";
        // }
        cin>>q;
        while(q--){
            ll x,y;
            cin>>x>>y;
            x--,y--;
            if(height[x]!=height[y]){
                if(height[x]<height[y])
                    swap(x,y);
                ll diff=height[x]-height[y];
                for(i=22;i>=0 && diff>0;i--){
                    ll val=((ll)1<<i);
                    if(val<=diff){
                        diff-=val;
                        x=dp[x][i];
                    }
                }
            }
            for(i=22;i>=0;i--)
                if(dp[x][i]!=dp[y][i])
                    x=dp[x][i],y=dp[y][i];
            if(x!=y)
                cout<<dp[x][0]+1;
            else
                cout<<x+1;
            cout<<"\n";
        }
    }
}
