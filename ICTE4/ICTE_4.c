#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ICTE_4.h"

void insertNode(Node** root, int value){
    if((*root) == NULL){ 
        (*root) = (Node*) malloc(sizeof(Node));
        (*root)->value = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }else if(value < (*root)->value){
        insertNode(&((*root)->left), value);
    }else{
        insertNode(&((*root)->right), value);
    }
}

void deleteNode(Node** root, int value){
    if(*root == NULL) return; 
    if(value < (*root)->value){
        deleteNode(&((*root)->left), value);
    }else if(value > (*root)->value){
        deleteNode(&((*root)->right), value);
    }else{
        if((*root)->left == NULL && (*root)->right == NULL){
            free((*root));
            (*root) = NULL;
        }else if((*root)->left == NULL){
            (*root) = (*root)->right;
        }else if((*root)->right == NULL){
            *root = (*root)->left;
        }
    }
}

Node* searchNode(Node** root, int value){
    if((*root) == NULL) return NULL;
    if(value < (*root)->value){
        return searchNode(&((*root)->left), value);
    }else if(value > (*root)->value){
        return searchNode(&((*root)->right), value); 
    }else{return (*root);}
}

int findMinNode(Node* root){
    if(root == NULL) return 0;
    if(root->left == NULL){
        return root->value;
    }else{return findMinNode(root->left);}
}

int findMaxNode(Node* root){
    if(root == NULL) return 0; 
    if (root->right == NULL){
        return root->value;
    }else{return findMaxNode(root->right);}
}
int isBST(Node* root){
    if(root == NULL) return 0; 
    if(root->left == NULL && root->right == NULL) return 1; 
    Node* rightChild = root->right; 
    Node* leftChild = root->left; 
    int result; 
    if(leftChild == NULL){
        if(rightChild->value >= root->value){
            result = isBST(rightChild);
        }else{result = 0;}
    }else if(rightChild == NULL){
        if(leftChild->value < root->value){
            result = isBST(leftChild);
        }else{result = 0;}
    }else{
        if((rightChild->value >= root->value) && (leftChild->value < root->value)){
            result = (isBST(rightChild) + isBST(leftChild)) / 2; 
        }else{result = 0;}
    }
    free(rightChild);
    free(leftChild);
    return result;
}

void printInOrder(Node* root){
    if(root == NULL) return;
    Node* child = root->left;
    printInOrder(child);
    printf("%d ", root->value);
    child = root->right;
    printInOrder(child);
}

void printPreOrder(Node* root){
    if(root == NULL) return;
    printf("%d ", root->value);
    Node* child = root->left;
    printPreOrder(child);
    child = root->right;
    printPreOrder(child);
}

void printPostOrder(Node* root){
    if(root == NULL) return;
    Node* child = root->left;
    printPostOrder(child);
    child = root->right;
    printPostOrder(child);
    printf("%d ", root->value);
}