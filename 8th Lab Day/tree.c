#include<stdio.h>
#include<stdlib.h>
struct node{
    char name;
    struct node *left;
    struct node *right;
};
struct node *root = NULL;
struct node *create_node(char x){
    struct node *newnode;
    newnode = (struct node*) malloc (sizeof(struct node));
    newnode -> name = x;
    newnode -> left = NULL;
    newnode -> right = NULL;
    return newnode;
}
void traverse(struct node *root){
    if ( root == NULL)
        return;
    traverse (root -> left);
    printf("%c ", root -> name);
    traverse(root -> right);
}

int main(){
    root = create_node('A');
    root -> left = create_node('B');
    root -> right = create_node('C');
    root -> left -> left = create_node('D');
    root -> left -> right = create_node('E');
    root -> right -> right = create_node('F');
    traverse(root);
    return 0;
}