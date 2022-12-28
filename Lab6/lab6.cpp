#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *left, *right;
};

void insert(Node *&root, int data)
{
    if (root == NULL)
    {
        root = new Node;
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return;
    }

    Node *current = root;

    while (true)
    {
        if (data < current->data)
        {
            if (current->left == NULL)
            {
                current->left = new Node;
                current->left->data = data;
                current->left->left = NULL;
                current->left->right = NULL;
                
                return;
            }
            else
            {
                current = current->left;
            }
        }
        else
        {
            if (current->right == NULL)
            {
                current->right = new Node;
                current->right->data = data;
                current->right->left = NULL;
                current->right->right = NULL;
                return;
            }
            else
            {
                current = current->right;
            }
        }
    }
}
void printCurrentLevel(Node* root, int level);
int height(Node* Node);
Node* newNode(int data);

void printLevelOrder(Node* root)
{
  int h = height(root);
  int i;
  for (i = 1; i <= h; i++)
  {
    printCurrentLevel(root, i);
    cout << endl;
  }
}

void printCurrentLevel(Node* root, int level)
{
  if (root == NULL)
    return;
  if (level == 1)
    cout << root->data << " ";
  else if (level > 1) {
    printCurrentLevel(root->left, level - 1);
    printCurrentLevel(root->right, level - 1);
  }
}

int height(Node* Node)
{
  if (Node == NULL)
    return 0;
  else {
    int lheight = height(Node->left);
    int rheight = height(Node->right);

    if (lheight > rheight) {
      return (lheight + 1);
    }
    else {
      return (rheight + 1);
    }
  }
}

Node* newNode(int data)
{
  Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return (node);
}

int main()
{
  Node* root = NULL;
  insert(root, 5);
  insert(root, 7);
  insert(root, 57);
  insert(root, 202);
  insert(root, 13);
  insert(root, 22);


  cout << "Level Order traversal of binary tree is \n";
  printLevelOrder(root);


  return 0;
}