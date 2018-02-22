#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


struct node
{
    int data;
    struct node* left;
    struct node* right;
};

int getHeight(node* root) {
    if(root == NULL) return 0;
    int leftHt = getHeight(root->left);
    int rightHt = getHeight(root->right);
    return (leftHt > rightHt? leftHt : rightHt) + 1;
}

int getDiameter(node* root) {
    int diameter = 0;
    if(root->left) diameter += getDiameter(root->left)+1;
    if(root->right) diameter += getDiameter(root->right)+1;
    return diameter;
}


struct node* newNode(int data)
{
  struct node* node = (struct node*) malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return(node);
}


int main()
{
  struct node *root = newNode(4);
  root->left        = newNode(2);
  root->right       = newNode(5);
  root->left->left  = newNode(1);
  root->left->left->left = newNode(3);
  printf("Height: %d\n",getHeight(root));
  printf("Diameter: %d\n",getDiameter(root));

  return 0;
}