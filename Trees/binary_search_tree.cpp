/*
Binary search tree uses the similar concept of binary search with tree structure

insertion - O(logn)
searching - O(logn)
deletion  - O(n)

It follows onr basic condition which is:

root->left < root->data > root->right;

left part must always be smaller than root and
right part must always be greater than root node and
this is applicable for each internal and root nodes in a tree

*/

#include <iostream>
#include <queue>

using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertData(Node *&root, int d)
{
    // base case
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    // others
    if (root->data > d)
    {
        root->left = insertData(root->left, d);
    }
    else
    {
        root->right = insertData(root->right, d);
    }

    return root;
}

void buildTree(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertData(root, data);
        cin >> data;
    }
}

void levelOrder(Node *root)
{

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    inorder(root->left);
    inorder(root->right);
}
void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}

int minVal(Node *root)
{
    Node *temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }

    return temp->data;
}

int maxVal(Node *root)
{
    Node *temp = root;

    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp->data;
}

bool searchBst(Node *root, int x)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == x)
    {
        return true;
    }

    if (root->data < x)
    {
        return searchBst(root->right, x);
    }
    else
    {
        return searchBst(root->left, x);
    }
}

bool searchIterative(Node *root, int x)
{
    Node *temp = root;

    while (temp != NULL)
    {
        if (temp->data == x)
        {
            return true;
        }

        if (temp->data < x)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    return false;
}

Node *deleteNode(Node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {
        // 0 child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child

        // left child
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if (root->left == NULL && root->right != NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int mini = minVal(root->right);
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }
    }
    else
    {
        if (root->data < val)
        {
            root->right = deleteNode(root->right, val);
        }
        else
        {
            root->left = deleteNode(root->left, val);
        }
    }
}

int main()
{

    Node *root = NULL;

    cout << "Enter data to create tree : " << endl;
    buildTree(root);

    cout << "Printing BST : " << endl;
    levelOrder(root);

    cout << "Printing Inorder : " << endl;
    inorder(root);
    cout << endl;

    cout << "Printing preorder : " << endl;
    preorder(root);
    cout << endl;

    cout << "Printing postorder : " << endl;
    postorder(root);
    cout << endl;

    cout << "The mininum value is : " << minVal(root) << endl;
    cout << "The maximum value is : " << maxVal(root) << endl;

    int x;

    cout << "Enter data to search : ";
    cin >> x;

    if (searchBst(root, x))
    {
        cout << "Target acquired" << endl;
    }
    else
    {
        cout << "Target Missing" << endl;
    }

    cout << "Enter data to search Itertively: ";
    cin >> x;

    if (searchIterative(root, x))
    {
        cout << "Target acquired" << endl;
    }
    else
    {
        cout << "Target Missing" << endl;
    }

    cout << "Enter node to delete : " << endl;

    int val;

    cin >> val;

    root = deleteNode(root, val);

    cout << "Printing BST : " << endl;
    levelOrder(root);

    return 0;
}