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

Node *createTree(Node *root)
{
    cout << "Enter data at root: " << endl;
    int data;
    cin >> data;

    root = new Node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter left of data " << data << endl;
    root->left = createTree(root->left);

    cout << "Enter right of data " << data << endl;
    root->right = createTree(root->right);

    return root;
}

void levelOrderTraversal(Node *root)
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

void buildFromLevel(Node *&root)
{
    queue<Node *> q;
    cout << "Enter data:" << endl;
    int data;
    cin >> data;
    root = new Node(data);
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        cout << "Enter left of " << temp->data << endl;
        int ldata;
        cin >> ldata;

        if (ldata != -1)
        {
            temp->left = new Node(ldata);
            q.push(temp->left);
        }

        cout << "Enter right of " << temp->data << endl;
        int rdata;
        cin >> rdata;

        if (rdata != -1)
        {
            temp->right = new Node(rdata);
            q.push(temp->right);
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
    cout << root->data;
    inorder(root->right);
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data;
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
    cout << root->data;
}

int main()
{
    Node *root = NULL;

    // input : 10 30 -1 60 -1 -1 40 50 -1 -1 -1

    // root = createTree(root);

    buildFromLevel(root);

    levelOrderTraversal(root);

    cout << endl;
    inorder(root);

    cout << endl;
    preorder(root);

    cout << endl;
    postorder(root);

    return 0;
}