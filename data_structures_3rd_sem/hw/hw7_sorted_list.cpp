#include <iostream>
using namespace std;
/*
Задачата за сортиран линеен списък е направена,
така че при въвеждане на данната да ѝ бъде намерено точното място 
и тогава тя да бъде записана в списъка. 
При въвеждане на стойности 40 9 1 2 9 8, 
програмата ще отпечата линейния списък - 1 2 8 9 9 40.
*/
typedef struct Element *po;
struct Element{
    int data;
    po next;
};

void print(po ans){
    while(ans!=NULL){
        cout<<ans->data<<" ";
        ans=ans->next;
    }
}

po insert(po na, po contr, po p){
    int x, n=6;
    while(n > 0){
        if(na == NULL){
            cin>>x;
            p = new Element;
            p->data = x;
            p->next = na;
            na = p;
        }

        else{
            cin>>x;
            p = new Element;
            p->data = x;
            p->next = na;
            
            if(p->next->data>x){
                na = p;
            }

            else{
                do{
                    contr = p->next;
                    p->next = p->next->next;
                }while(p->next!=NULL&&p->next->data<x);
                contr->next = p;
            }
        }
        n--;
    }
    po filled = new Element;
    filled = na;
    return filled;
}

int main(){
    po na = NULL,contr,p;
    
    po filled = new Element;
    filled = insert(na,contr,p);

    po ans = new Element;
    ans = filled;
    print(ans);

    return 0;
}