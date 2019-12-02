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
       // cout<<na->data;
   }
   return na;
}

int main(){
    po na;
    na = NULL;
    
    po res = new Element;
    res = push(na);

    int i=1;
    while(res!=NULL){
        cout<<res->data<<" ";
        res=res->next;
    }
    return 0;
}