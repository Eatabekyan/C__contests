#include <stdio.h>
#include <stdlib.h>


typedef int Data;

struct Node * tree_add (struct Node * tree, Data x);
void tree_print (struct Node * tree);
void tree_destroy (struct Node * tree);
int tree_height(struct Node * tree);
void print_tree_leaves(struct Node * tree);
int is_balanced(struct Node * tree);


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


int tree_height(struct Node * tree) {
    if(tree == NULL) {
        return 0;
    }
    if(tree_height(tree->left) >= tree_height(tree->right)) {
        return 1 + tree_height(tree->left);
    }
    return 1 + tree_height(tree->right);
}
;


void print_tree_leaves(struct Node * tree) {
    if(tree->left == NULL && tree->right == NULL) {
        printf("%d ", tree->val);
    } else {
        if(tree->left != NULL) {
            print_tree_leaves(tree->left);
        }
        if(tree->right != NULL) {
            print_tree_leaves(tree->right);
        }
    }
};


int is_balanced(struct Node * tree) {
    if(tree == NULL) {
        return 1;
    }
    if(tree_height(tree->left) - tree_height(tree->right) >= -1 && tree_height(tree->left) - tree_height(tree->right) <= 1) {
        return is_balanced(tree->left)*is_balanced(tree->right);
    }
    return 0;
};

int main() {
    struct Node * tree = NULL;
    char x;
    int num ;
    scanf("%d%c", &num, &x);
    while(x != '\n') {
        tree = tree_add(tree, num);
        scanf("%d%c", &num, &x);
    }
    if(is_balanced(tree) == 1) {
        printf("YES");
    } else {
        printf("NO");
    }
    tree_destroy(tree);
    return 0;
}

