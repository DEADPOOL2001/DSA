//Author - Nimish Upadhyay
//Trie Template
#include<bits/stdc++.h>
using namespace std;
struct trie{
    bool plz;
    trie *child[2];
};
trie *create(){
    trie *root=new trie();
    root->plz=false;
    root->child[0]=NULL;
    root->child[1]=NULL;
    return root;
}
void insert(int key,trie *root){
    int val=30;
    while(val>=0){
        int curr=(1<<val);
        if((key&curr)){
            if(!root->child[1])
                root->child[1]=create();
            root=root->child[1];
        } else {
            if(!root->child[0])
                root->child[0]=create();
            root=root->child[0];
        }
        val--;
    }
    root->plz=true;
}
void search(int xr,trie *root,int &ans){
    int val=30,curr=0;
    while(val>=0){
        int pow=(1<<val);
        if(!root->child[0] && !root->child[1])
            return;
        if(xr&pow){
            if(root->child[0])
                root=root->child[0];
            else
                root=root->child[1],curr+=pow;
        } else {
            if(root->child[1])
                root=root->child[1],curr+=pow;
            else
                root=root->child[0];
        }
        if(root->plz)
            ans=max(ans,(curr^xr));
        val--;
    }
}
int main() {
    int n,ans=0,curr_xor=0;
    trie *root=create();
    cin>>n;
    int c[n];
    for(int i=0;i<n;i++)
        cin>>c[i];
    insert(0,root);
    for(int i=0;i<n;i++){
        curr_xor=(curr_xor^c[i]);
        search(curr_xor,root,ans);
        insert(curr_xor,root);
    }
    cout<<ans<<"\n";
}
