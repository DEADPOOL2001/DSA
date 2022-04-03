//AUTHOR - NIMISH UPADHYAY
//FROM IIIT ALLAHABAD
// does pattern matching o(n+m) where n is the length of main string and
// m is the length of the pattern string
#include<bits/stdc++.h>
using namespace std;

void Zarray(string s,int z[]){
    int n=s.length(),l=0,r=0;
    z[0]=n;
    for(int i=1;i<n;i++){
        if(i>r){
            l=i,r=i;
            while(r<n && s[r]==s[r-i])
                r++;
            r--;
            z[i]=r-l+1;
        } else {
            if(z[i-l]+i<r+1)
                z[i]=z[i-l];
            else {
                l=i;
                while(r<n && s[r]==s[r-i])
                    r++;
                r--;
                z[i]=r-l+1;
            }
        }
    }
}

int main(){
    string main,pattern;
    cin>>main>>pattern;
    string concate=pattern+"$"+main;
    int n=concate.length(),z[n],k=pattern.length();
    Zarray(concate,z);
    for(int i=k+1;i<n;i++)
        if(z[i]==k)
            cout<<"pattern found at index : "<<i-k-1<<"\n";
}