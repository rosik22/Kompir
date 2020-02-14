#include <iostream>
using namespace std;

typedef struct Element *po;
struct Element{
    char data;
    po next;
};

void print(po ans){
    while(ans!=NULL){
        cout<<ans->data<<" ";
        ans=ans->next;
    }
}

int main(){
    po na = NULL;

    int answer;
    cout<<"How many characters will your statement contain?";
    cin>>answer;

    po p;
    while(answer > 0){
        char letter;
        cin>>letter;
        p = new Element;
        p->data = letter;
        p->next = na;
        na = p;

        answer--;
    }

    po ans = new Element;
    ans = na;
    print(ans);
    return 0;
}