#include <stdio.h>
#include <stdlib.h>


typedef int Data;

struct Node * tree_add (struct Node * tree, Data x);
void tree_print (struct Node * tree);
void tree_destroy (struct Node * tree);

struct Node {
    Data val;            // данные в узле
    struct Node * left;  // левый ребенок
    struct Node * right; // правый ребенок

};

struct Node * tree_add(struct Node * tree, Data x) {
    if (tree == NULL) {
        tree = malloc(sizeof(struct Node));
        tree->val = x;
        tree->left = NULL;
        tree->right = NULL;
        return tree;
    } else {
        if(tree->val > x) {
            tree->left = tree_add(tree->left, x);
            return tree;
        } else if(tree->val < x) {
            tree->right = tree_add(tree->right, x);
            return tree;
        } else {
            return tree;
        }
    }

};

void tree_print (struct Node * tree) {
    if (tree->left != NULL) {
        tree_print(tree->left);
    } 
    printf("%d ", tree->val);
    if (tree->right != NULL) {
        tree_print(tree->right);
    }

};

void tree_destroy (struct Node * tree) {
    if (tree->left != NULL) {
        tree_destroy(tree->left);
    } 
    if (tree->right != NULL) {
        tree_destroy(tree->right);
    }
    free(tree);

};

int main() {
    struct Node * tree = NULL;
    int x;
    scanf("%d", &x);
    while(x > 0) {
        tree = tree_add(tree, x);
        scanf("%d", &x);
    }
    tree_print(tree);
    tree_destroy(tree);
    return 0;
}

