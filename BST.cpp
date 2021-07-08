//AUTHOR - NIMISH UPADHYAY
//FROM IIIT ALLAHABAD
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
class node{
    public :
    ll val;
    node *left,*right;
    node(ll val,node *left,node *right){
        this->val=val;
        this->left=left;
        this->right=right;
    }
};
void preorder(node *root){
    if(!root)
        return;
    cout<<root->val<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root){
    if(!root)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
void calculate_next_greater(ll arr[],ll next[],ll n){
    stack<ll>s;
    for(ll i=0;i<n;i++){
        while(!s.empty()){
            if(arr[s.top()]>arr[i])
                break;
            next[s.top()]=i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        next[s.top()]=n;
        s.pop();
    }
}
node *construct(ll l,ll r,ll arr[],ll next[]){
    if(l>r)
        return NULL;
    node *left,*right;
    left=construct(l+1,next[l]-1,arr,next);
    right=construct(next[l],r,arr,next);
    return new node(arr[l],left,right);
}
int main(){
    ll n;
    cin>>n;
    ll arr[n],next[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    calculate_next_greater(arr,next,n);
    node *ans=construct(0,n-1,arr,next);
    //for checking
    //preorder(ans);
    inorder(ans);
}
