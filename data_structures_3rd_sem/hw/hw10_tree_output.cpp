#include <iostream>
using namespace std;

typedef struct node * po;
struct node{
    int data;
    po left;
    po right;
};

void print(po root, int space)
{
    int COUNT = 5;
	if (root == NULL)
		return;

	space += COUNT;
	print(root->right, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->data << "\n"; 
	print(root->left, space);
}

po ibd(int x){
    po temp; int c;
    if(x>0){
        int nl = x/2;
        int nd = x-nl-1;
        cin>>c;
        temp = new node;
        temp -> data = c;
        temp -> left = ibd(nl);
        temp -> right = ibd(nd);
        return temp;
    }
    else return NULL;
}

void infix (po help){
    if(help){
        infix(help->left);
        cout<<help->data<<" ";
        infix(help->right);
    }
}

void prefix(po help){
    if(help){
        cout<<help->data<<" ";
        prefix(help->left);
        prefix(help->right);
    }
}

void postfix(po help){
    if(help){
        postfix(help->left);
        postfix(help->right);
        cout<<help->data<<" ";
    }
}

int main(){
    int x;
    cin>>x;
    po root = ibd(x);
    print(root,x);
    
    cout<<endl<<"infix: ";
    infix(root);
    cout<<endl<<"prefix: ";
    prefix(root);
    cout<<endl<<"postfix: ";
    postfix(root);
    return 0;
}