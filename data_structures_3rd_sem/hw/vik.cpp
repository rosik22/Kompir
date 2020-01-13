#include <iostream>
using namespace std;

typedef struct node *po;
struct node
{
    int data;
    po left;
    po right;
};

class Heap
{
public:
    po build(int num);
    void infix(po help);
    /* left(p);
    right(p);
    parent(p);
    root();
    last();
    isRoot(p);
    hasLeft(p);
    hasRight(p);
    add(e);
    remove();*/
protected:
    int data;
    po left;
    po right;
};

po Heap::build(int num)
{
    po temp;
    int c;
    if (num > 0)
    {
        int nl = num / 2;
        int nd = num - nl - 1;
        cin >> c;
        temp = new node;
        temp->data = c;
        temp->left = build(nl);
        temp->right = build(nd);
        return temp;
    }
    else
        return NULL;
}

void Heap::infix(po help)
{
    if (help)
    {
        infix(help->left);
        cout << help->data << " ";
        infix(help->right);
    }
}

/*
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
}*/

int main()
{
    int num;
    cin >> num;
    Heap *root = new Heap();
    root->build(num);

    cout << endl
         << "infix: ";
    infix(root);
    return 0;
}