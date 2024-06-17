#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
    int key;
    int height;
    struct AVLNode *left;
    struct AVLNode *right;
} AVLNode;

AVLNode* createNode(int key) {
    AVLNode* node = (AVLNode*)malloc(sizeof(AVLNode));
    node->key = key;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(AVLNode* node) {
    return node ? node->height : 0;
}

int getBalance(AVLNode* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

AVLNode* rotateRight(AVLNode* y) {
    AVLNode* x = y->left;
    AVLNode* T = x->right;
    
    x->right = y;
    y->left = T;
    
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    
    return x;
}

AVLNode* rotateLeft(AVLNode* x) {
    AVLNode* y = x->right;
    AVLNode* T = y->left;
    
    y->left = x;
    x->right = T;
    
    x->height = 1 + (height(x->left) > height(x->right) ? height(x->left) : height(x->right));
    y->height = 1 + (height(y->left) > height(y->right) ? height(y->left) : height(y->right));
    
    return y;
}

AVLNode* insert(AVLNode* node, int key) {
    if (!node) {
        return createNode(key);
    }
    
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node;
    }
    
    node->height = 1 + (height(node->left) > height(node->right) ? height(node->left) : height(node->right));
    
    int balance = getBalance(node);
    
    if (balance > 1 && key < node->left->key) {
        return rotateRight(node);
    }
    
    if (balance < -1 && key > node->right->key) {
        return rotateLeft(node);
    }
    
    if (balance > 1 && key > node->left->key) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    
    if (balance < -1 && key < node->right->key) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    
    return node;
}

void printInOrder(AVLNode* node) {
    if (node) {
        printInOrder(node->left);
        printf("%d ", node->key);
        printInOrder(node->right);
    }
}

int main() {
    AVLNode* root = NULL;
    
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 10);
    root = insert(root, 25);
    root = insert(root, 35);
    root = insert(root, 50);
    
    printf("Árvore AVL em ordem: ");
    printInOrder(root);
    
    return 0;
}