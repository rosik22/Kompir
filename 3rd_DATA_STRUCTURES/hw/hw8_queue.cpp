#include <iostream>
#include <string>
using namespace std;

typedef struct Element * po;
struct Element{
    char data;
    po next;
};

void print (po q){
    while(q!=NULL){
        cout<<q->data;
        q = q->next;
    }
}

int main(){
    string name = "Rositsa Karapetrova";
    po p, beg = NULL, end = NULL;

    for(int i=0; i<name.length(); i++){
        if(beg==NULL){
            p = new Element;
            p->data = name[i];
            p->next = NULL;
            end = p;
            beg = p;
        }
        else{
            p = new Element;
            p->data = name[i];
            p->next = NULL;
            end->next = p;
            end = p;
        }
    }
    
    po q = new Element;
    q = beg;
    print(q);

    delete q;
    delete p;
    return 0;
} 
