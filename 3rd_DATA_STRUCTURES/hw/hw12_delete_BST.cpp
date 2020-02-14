#include <iostream>
using namespace std;

typedef struct node *po;
struct node
{
    int data;
    po left;
    po right;
};

po search(po tree, int num)
{
    int counter = 0;
    po last = NULL;
    po temp = tree;
    while (temp != NULL && temp->data != num)
    {
        counter++;
        last = temp;
        if (num < temp->data)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->right;
        }
    }

    if (temp == NULL)
    {
        temp = new node;
        temp->data = num;
        temp->left = NULL;
        temp->right = NULL;
        if (last != NULL)
        {
            if (last->data > num)
                last->left = temp;
            else
                last->right = temp;
        }
        cout << num << " wasn't found, but it was inserted" << endl;
    }
    else if (temp->data == num)
    {
        cout << num << " was found after " << counter << " searches" << endl;
    }
    return temp;
}

po minValueNode(po node){
    po temp = node;

    while (temp && temp->left != NULL)
        temp = temp->left;

    return temp;
}

po deleteNode(po root, int num)
{
    if (root == NULL)
        return root;

    if (num < root->data)
        root->left = deleteNode(root->left, num);

    else if (num > root->data)
        root->right = deleteNode(root->right, num);

    else
    {
        if (root->left == NULL)
        {
            po temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            po temp = root->left;
            free(root);
            return temp;
        }

        po temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void infix(po tree)
{
    if (tree)
    {
        infix(tree->left);
        cout << tree->data << " ";
        infix(tree->right);
    }
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

int main()
{
    po tree = NULL;
    int num;

    int arr[13] = {9, 1, 2, 9, 8, 91, 29, 9, 9, 1, 2, 99, 12};
    tree = search(tree, arr[0]);
    for (int i=1; i<13; i++){
        search(tree, arr[i]);
    }

    cout << "infix: ";
    infix(tree);
    cout << endl;
    print(tree, 0);

    cout<<"Now to delete some nodes (take a note that: \nif you insert a number which is not present in the tree, the number will be ignored)\n--> choose 5 numbers: ";
    int del = 0;
    for(int i=0; i<5; i++){
        cin>>del;
        deleteNode(tree, del);
    }

    print(tree, 0);

    return 0;
}