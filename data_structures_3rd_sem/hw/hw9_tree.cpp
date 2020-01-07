#include <iostream>
using namespace std;

/*
Фак. номер - 91298
съответно създавам дърво с l = 89 възела и дърво с m = 21 възела;
*/

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

int main(){
    int l = 89, m = 21;
    po root1 = ibd(l);
    print(root1, l);

    cout<<endl;

    po root2 = ibd(m);
    print(root2, m);
    
    return 0;
}