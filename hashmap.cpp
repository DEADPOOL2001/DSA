
#include<bits/stdc++.h>
using namespace std;
struct link{
    int val;
    link *next;
};
link *create(int x){
    link *temp =new link();
    temp->val=x;
    temp->next=NULL;
    return temp;
}
int func(int val){
    return val%200;
}
class hashmap{
    private :
    int capa=200;
    link *List[200];
    public :
    hashmap(){
        for(int i=0;i<200;i++)
            List[i]=NULL;
    }
    void insert(int x){
        int val=func(x);
        link *temp=create(x),*last=NULL,*curr=List[val];
        while(curr){
            if(curr->val==x)
                return;
            last=curr;
            curr=curr->next;
        }
        if(!last){
            List[val]=temp;
        } else {
            last->next=temp;
        }
    }
    void search(int x){
        int val=func(x);
        link *temp=List[val];
        while(temp){
            if(temp->val==x){
                cout<<"FOUND "<<x<<"\n";
                return;
            }
            temp=temp->next;
        }
        cout<<"NOT FOUND "<<x<<"\n";
    }
    void Delete(int x){
        int val=func(x);
        link *temp=List[val],*last=NULL;
        while(temp){
            if(temp->val==x){
                if(!last)
                    List[val]=temp->next;
                else
                    last->next=temp->next;
                delete temp;
                cout<<"DELETED "<<x<<"\n";
                return;
            }
            last=temp;
            temp=temp->next;
        }
        cout<<"NOT FOUND "<<x<<"\n";
    }
};
int main(){
    hashmap mymap=hashmap();
    int q;
    cin>>q;
    while(q--){
        int x,y;
        cin>>x>>y;
        if(x==1)
            mymap.insert(y);
        else if(x==2)
            mymap.search(y);
        else
            mymap.Delete(y);
    }
}
