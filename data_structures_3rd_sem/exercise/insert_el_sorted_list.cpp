#include <iostream>
using namespace std;

typedef struct Element *po;
struct Element{
    int data;
    po next;
};

po push(po na){
   po p;
   for(int i=1; i<11; i++){
        p = new Element;
        p->data = i;
        p->next = na;
        na = p;
   }
   
   return na;
}

int main(){
    po na = NULL,contr;
    int x = 4;
    
    po res = new Element;
    res = push(na);
    na = res;

    po p = new Element;
    p->data = x;
    p->next = na;

    if(na==NULL || na->data <= x)
    {na = p;}
    else{
        do{
            contr = p->next;
            p->next = p->next->next;
        }while(p->next!=NULL&&p->next->data>x);
        contr->next = p;
    }

    po ans = new Element;
    ans = na;
    int i=1;
    while(ans!=NULL){
        cout<<ans->data<<" ";
        ans=ans->next;
    }
    return 0;
}