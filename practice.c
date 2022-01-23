#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *binary(struct node *root, int n)
{
    if (root == NULL)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));

        newnode->data = n;
        newnode->left = NULL;
        newnode->right = NULL;

        return newnode;
    }
    if (n < root->data)
    {
        root->left = binary(root->left, n);
    }
    if (n > root->data)
    {
        root->right = binary(root->right, n);
    }
    return root;
}

void print(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d\t", root->data);

    print(root->left);

    print(root->right);
}
struct node *succesor(struct node *p)
{
    if (p->left == NULL)
    {
        return p;
    }
  return  succesor(p->left);
}

struct node *delete (struct node *root, int key)
{
    struct node *t = succesor(root->right);
    root->data = t->data;
    free(t);
    return root;
}

struct node *search(struct node *root, int key)
{

    struct node *s;
    if (root == NULL)
        return NULL;
    if (root->data == key)
    {
        s = delete (root, key);

        return s;
    }
    else if (root->data > key)
        return search(root->left, key);
    else if (key > root->data)
        return search(root->right, key);

        return root;
}
int sum_of_nodes(struct node *root, int sum)
{

    {
        if (root->left == NULL && root->right == NULL)
        {
            return sum = sum + root->data;
        }
        sum = sum_of_nodes(root->left, sum);
        sum = sum_of_nodes(root->right, sum);
    }
    return sum;
}

int main()
{
    struct node *root = NULL;
    root = binary(root, 10);
    binary(root, 5);
    binary(root, 12);
    binary(root, 4);

    binary(root, 11);
    binary(root, 16);

    int sum = 0;
    //printf("%d",sum_of_nodes(root,sum));
    root = delete (root, 5);
    print(root);
    // printf("%d",search(root,4));
    // printf("\n%d",search(root,14));
}
