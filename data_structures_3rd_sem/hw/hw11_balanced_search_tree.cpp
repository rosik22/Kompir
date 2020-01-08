#include <iostream>
using namespace std;

typedef struct node *po;
struct node{
    int data;
    po left;
    po right;
};

po build_balanced(int * arr, int beg, int end){
    if(beg>end) return NULL;
    int mid = (beg+end)/2;
    po tree = new node;
    tree->data = arr[mid];
    tree->left = build_balanced(arr,beg,mid-1);
    tree->right = build_balanced(arr, mid+1, end);

    return tree;
}

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

int main(){
    po tree = NULL;
    int num;
    
    int arr[13] = {1,1,2,2,8,9,9,9,9,12,29,91,99};



    tree = build_balanced(arr,0,12);

    print(tree, 0);

    return 0;
}