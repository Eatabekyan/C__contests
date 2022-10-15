#include <stdio.h>
#include <stdlib.h>

typedef int Data;


struct Node * tree_add (struct Node * tree, Data x);
void tree_print (struct Node * tree);

struct Node {
    Data val;            // данные в узле
    struct Node * left;  // левый ребенок
    struct Node * right; // правый ребенок
};

struct Node * tree_add(struct Node * tree, Data x){
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
int main() {
    struct Node * tree = NULL;
    tree = tree_add(tree, 7);
    tree = tree_add(tree, 3);
    tree = tree_add(tree, 2);
    tree = tree_add(tree, 1);
    tree = tree_add(tree, 9);
    tree = tree_add(tree, 5);
    tree = tree_add(tree, 4);
    tree = tree_add(tree, 6);
    tree = tree_add(tree, 8);
    tree_print(tree); // напечатает 1 2 3 4 5 6 7 8 9
    
    return 0;
}
