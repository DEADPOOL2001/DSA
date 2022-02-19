//AUTHOR - NIMISH UPADHYAY
//FROM IIIT ALLAHABAD
#include<bits/stdc++.h>
using namespace std;
#define NIMISH ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define UPADHYAY int t;cin>>t;while(t--)
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define ll long long int 
#define ld long double
#define ya "YES\n"
#define na "NO\n"
#define b1(con) ((con)?ya:na)
#define cr(k) cout << fixed << setprecision(10) << k; 
#define pr pair<ll,ll>
#define ff first
#define ss second
ld pi=3.14159265358979323846;
 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
 
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
 
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
 
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...) 20
#endif

const ll mex=1e5+6;
ll bit[33][mex],arr[mex],n,q;

void update(ll bits,ll ind,ll change){
    for(;ind<=n;ind+=(ind&(-ind)))
        bit[bits][ind]+=change;
}

ll sum(ll bits,ll ind){
    ll ans=0;
    for(ll i=ind;i>0;i-=(i&(-i)))
        ans+=bit[bits][i];
    return ans;
}

int main(){
    NIMISH
    cin>>n>>q;
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
        for(ll j=0;j<33;j++){
            ll po=((ll)1<<j);
            if((arr[i]&po)>0) update(j,i,1);
        }
    }
    while(q--){
        ll type;
        cin>>type;
        if(type==1){
            ll value,ind;
            cin>>value>>ind;
            for(ll j=0;j<33;j++){
                ll a=0,b=0,po=((ll)1<<j);
                if((value&po)>0)
                    a++;
                if((arr[ind]&po)>0)
                    b++;
                if(a-b!=0) update(j,ind,a-b);
            }
            arr[ind]=value;
        } else {
            string s;
            ll l,r;
            cin>>s>>l>>r;
            ll ans=0;
            for(ll j=0;j<33;j++){
                ll po=((ll)1<<j),tot=sum(j,r)-sum(j,l-1),rest=r-l+1-tot;
                // cout<<po<<" "<<tot<<"\n";
                if(s=="AND")
                    ans+=(po*((tot-1)*tot))/2;
                else if(s=="OR")
                    ans+=po*(((tot-1)*tot)/2+rest*tot);
                else
                    ans+=po*tot*rest;
            }
            cout<<ans<<"\n";
        }
    }
}