#include "ICTE_4.h"
#include "gtest/gtest.h"

namespace {
    /* "insertNode" function tests */
    // 1. Inserts value into an empty BST, i.e. creates BST
    TEST(Node, insertEmpty) {
        Node* pEmptyBST = NULL;
        Node** ppEmptyBST = &pEmptyBST;
        int value = 5;
        printf("\nEmpty BST before insertion\nRoot:\nValue = NULL, Address = %p\n", pEmptyBST);
        insertNode(ppEmptyBST, value);
        printf("\nEmpty BST after insertion\nRoot:\nValue = %i, Address = %p\n\n", pEmptyBST->value, pEmptyBST);
        EXPECT_EQ((*ppEmptyBST)->value, value);
        EXPECT_EQ((*ppEmptyBST)->left, nullptr);
        EXPECT_EQ((*ppEmptyBST)->right, nullptr);
    }
    // 2. Inserts smaller/bigger values into non-empty BST
    TEST(Node, insert) {
        Node* pBST = (Node*) malloc(sizeof(Node));
        Node** ppBST = &pBST;
        *pBST = { .value = 3, .left = (Node*) NULL, .right = (Node*) NULL};
        // Inserts smaller value
        int value = 1;
        printf("\nBST before insertion (smaller value)\n");
        printf("Root:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = NULL, Address = %p\n", pBST->left);
        printf("Right Child:\nValue = NULL, Address = %p\n", pBST->right);

        insertNode(ppBST, value);
        printf("\nBST after insertion (smaller value)\n");
        printf("Root:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Right Child:\nValue = NULL, Address = %p\n\n", pBST->right);
        EXPECT_EQ((pBST->left)->value, value);
        EXPECT_EQ((pBST->left)->left, nullptr);
        EXPECT_EQ((pBST->left)->right, nullptr);
        // Inserts bigger value
        value = 6;
        printf("\nBST before insertion (bigger value)\n");
        printf("Root:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Right Child:\nValue = NULL, Address = %p\n", pBST->right);

        insertNode(ppBST, value);
        printf("\nBST after insertion (smaller value)\n");
        printf("Root:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Right Child:\nValue = %i, Address = %p\n\n", (pBST->right)->value, pBST->right);
        EXPECT_EQ((pBST->right)->value, value);
        EXPECT_EQ((pBST->right)->left, nullptr);
        EXPECT_EQ((pBST->right)->right, nullptr);
    }

    /* "deleteNode" function tests */
    // 1. Deletes value from empty BST, i.e. does noting
    TEST(Node, deleteEmpty) {
        Node* pEmptyBST;
        Node** ppEmptyBST = &pEmptyBST;
        int value = 5;
        printf("\nEmpty BST before deletion\nRoot:\nValue = NULL, Address = %p\n", pEmptyBST);
        deleteNode(ppEmptyBST, value);
        printf("\nEmpty BST after deletion\nRoot:\nValue = NULL, Address = %p\n\n", pEmptyBST);
        EXPECT_EQ(*ppEmptyBST, nullptr);
    }
    // 2. Deletes the last node down in BST (without replace)
    TEST(Node, deleteWithOutReplace) {
        Node* pBST = NULL;
        Node** ppBST = &pBST;
        int value = 15;
        insertNode(ppBST, value);
        value = 5;
        insertNode(ppBST, value);
        value = 17;
        insertNode(ppBST, value);
        printf("\nBST before deletion (without replace)\n");
        printf("Root:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Right Child:\nValue = %i, Address = %p\n", (pBST->right)->value, pBST->right);

        deleteNode(ppBST, value);
        printf("\nBST after deletion (without replace)\n");
        printf("Root:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Right Child:\nValue = NULL, Address = %p\n\n", pBST->right);
        EXPECT_EQ((*ppBST)->right, nullptr);
    }
    // 3. Deletes node before the last node down in BST (with replace of both cases: left and right children)
    TEST(Node, deleteWithLeftReplace) {
        Node* pBST = NULL;
        Node** ppBST = &pBST;
        int value = 15;
        insertNode(ppBST, value);
        value = 5;
        insertNode(ppBST, value);
        value = 7;
        insertNode(ppBST, value);
        value = 21;
        insertNode(ppBST, value);
        value = 17;
        insertNode(ppBST, value);
        printf("\nBST before deletion (with replace)\n");
        printf("Root:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Left's Right Child:\nValue = %i, Address = %p\n", ((pBST->left)->right)->value, (pBST->left)->right);
        printf("Right Child:\nValue = %i, Address = %p\n", (pBST->right)->value, pBST->right);
        printf("Right's Left Child:\nValue = %i, Address = %p\n", ((pBST->right)->left)->value, (pBST->right)->left);        

        value = 5;
        deleteNode(ppBST, value);
        value = 21;
        deleteNode(ppBST, value);        
        printf("\nBST after deletion (with replace)\n");
        printf("Root:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Right Child:\nValue = %i, Address = %p\n\n", (pBST->right)->value, pBST->right);
        EXPECT_EQ(((*ppBST)->left)->value, 7);
        EXPECT_EQ(((*ppBST)->left)->left, nullptr);
        EXPECT_EQ(((*ppBST)->left)->right, nullptr);
        EXPECT_EQ(((*ppBST)->right)->value, 17);
        EXPECT_EQ(((*ppBST)->right)->left, nullptr);
        EXPECT_EQ(((*ppBST)->right)->right, nullptr);
    }

    /* "searchNode" function tests */
    // 1. Searches node in empty BST, i.e. returns NULL pointer of Node* type
    TEST(Node, searchNodeEmpty) {
        Node* pEmptyBST = NULL;
        Node** ppEmptyBST = &pEmptyBST;
        Node* pSearchNode;
        int value = 5;
        printf("\nMin Node Address before search: %p", pSearchNode);
        pSearchNode = searchNode(ppEmptyBST, value);
        printf("\nMin Node Address after search: %p\n\n", pSearchNode);
        EXPECT_EQ(pSearchNode, nullptr);
    }
    // 2. Searches node in non-empty BST (no recurring values)
    TEST(Node, searchNodeRegular) {
        Node* pBST = NULL;
        Node** ppBST = &pBST;
        Node* pSearchNode;
        int value = 15;
        insertNode(ppBST, value);
        value = 5;
        insertNode(ppBST, value);
        value = 7;
        insertNode(ppBST, value);
        value = 21;
        insertNode(ppBST, value);
        value = 17;
        insertNode(ppBST, value);
        printf("\nBST\nRoot:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Left's Right Child:\nValue = %i, Address = %p\n", ((pBST->left)->right)->value, (pBST->left)->right);
        printf("Right Child:\nValue = %i, Address = %p\n", (pBST->right)->value, pBST->right);
        printf("Right's Left Child:\nValue = %i, Address = %p\n", ((pBST->right)->left)->value, (pBST->right)->left);        

        value = 21;
        pSearchNode = searchNode(ppBST, value);      
        printf("\nFound Node:\nValue = %i, Address = %p\n", pSearchNode->value, pSearchNode);
        printf("Left Child:\nValue = %i, Address = %p\n", (pSearchNode->left)->value, pSearchNode->left);
        printf("Right Child:\nValue = NULL, Address = %p\n\n", pSearchNode->right);
        EXPECT_EQ(pSearchNode->value, 21);
        EXPECT_EQ(pSearchNode->left, ((*ppBST)->right)->left);
        EXPECT_EQ(pSearchNode->right, nullptr);
    }
    // 3. Searches node in non-empty BST (recurring values)
    TEST(Node, searchNodeRecurring) {
        Node* pBST = NULL;
        Node** ppBST = &pBST;
        Node* pSearchNode;
        int value = 15;
        insertNode(ppBST, value);
        value = 5;
        insertNode(ppBST, value);
        value = 7;
        insertNode(ppBST, value);
        value = 21;
        insertNode(ppBST, value);
        value = 21;
        insertNode(ppBST, value);
        printf("\nBST\nRoot:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Left's Right Child:\nValue = %i, Address = %p\n", ((pBST->left)->right)->value, (pBST->left)->right);
        printf("Right Child:\nValue = %i, Address = %p\n", (pBST->right)->value, pBST->right);
        printf("Right's Right Child:\nValue = %i, Address = %p\n", ((pBST->right)->right)->value, (pBST->right)->right);        

        value = 21;
        pSearchNode = searchNode(ppBST, value);      
        printf("\nFound Node:\nValue = %i, Address = %p\n", pSearchNode->value, pSearchNode);
        printf("Left Child:\nValue = NULL, Address = %p\n", pSearchNode->left);
        printf("Right Child:\nValue = %i, Address = %p\n\n", (pSearchNode->right)->value, pSearchNode->right);
        EXPECT_EQ(pSearchNode->value, 21);
        EXPECT_EQ(pSearchNode->left, nullptr);
        EXPECT_EQ(pSearchNode->right, ((*ppBST)->right)->right);
    }
    // 4. Searches nonexistent node in non-empty BST
    TEST(Node, searchNodeNonExistent) {
        Node* pBST = NULL;
        Node** ppBST = &pBST;
        Node* pSearchNode;
        int value = 15;
        insertNode(ppBST, value);
        value = 5;
        insertNode(ppBST, value);
        value = 7;
        insertNode(ppBST, value);
        value = 21;
        insertNode(ppBST, value);
        value = 21;
        insertNode(ppBST, value);
        printf("\nBST\nRoot:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Left's Right Child:\nValue = %i, Address = %p\n", ((pBST->left)->right)->value, (pBST->left)->right);
        printf("Right Child:\nValue = %i, Address = %p\n", (pBST->right)->value, pBST->right);
        printf("Right's Right Child:\nValue = %i, Address = %p\n", ((pBST->right)->right)->value, (pBST->right)->right);        

        value = 25;
        pSearchNode = searchNode(ppBST, value);      
        printf("\nFound Node:\nValue = %i, Address = %p\n\n", value, pSearchNode);
        EXPECT_EQ(pSearchNode, nullptr);
    }

    /* "findMinNode" function tests */
    // 1. Finds min value node in empty BST, i.e. returns 0 (all nodes valid values are positive)
    TEST(Node, findMinEmpty) {
        Node* pEmptyBST = NULL;
        int minNode;
        minNode = findMinNode(pEmptyBST);
        printf("\nEmpty BST\nNode with Min Value = %i\n\n", minNode);
        EXPECT_EQ(minNode, 0);
    }
    // 2. Finds min value node in non-empty BST
    TEST(Node, findMin) {
        Node* pBST = NULL;
        Node** ppBST = &pBST;
        int minNode;
        int value = 15;
        insertNode(ppBST, value);
        value = 5;
        insertNode(ppBST, value);
        value = 7;
        insertNode(ppBST, value);
        value = 21;
        insertNode(ppBST, value);
        value = 17;
        insertNode(ppBST, value);
        printf("\nBST\nRoot:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Left's Right Child:\nValue = %i, Address = %p\n", ((pBST->left)->right)->value, (pBST->left)->right);
        printf("Right Child:\nValue = %i, Address = %p\n", (pBST->right)->value, pBST->right);
        printf("Right's Left Child:\nValue = %i, Address = %p\n", ((pBST->right)->left)->value, (pBST->right)->left);        

        minNode = findMinNode(pBST);      
        printf("\nNode with Min Value = %i\n\n", minNode);
        EXPECT_EQ(minNode, 5);
    }

    /* "findMaxNode" function tests */
    // 1. Finds min value node in empty BST, i.e. returns 0 (all nodes valid values are positive)
    TEST(Node, findMaxEmpty) {
        Node* pEmptyBST = NULL;
        int maxNode;
        maxNode = findMinNode(pEmptyBST);
        printf("\nEmpty BST\nNode with Max Value = %i\n\n", maxNode);
        EXPECT_EQ(maxNode, 0);
    }
    // 2. Finds min value node in non-empty BST
    TEST(Node, findMax) {
        Node* pBST = NULL;
        Node** ppBST = &pBST;
        int maxNode;
        int value = 15;
        insertNode(ppBST, value);
        value = 5;
        insertNode(ppBST, value);
        value = 7;
        insertNode(ppBST, value);
        value = 21;
        insertNode(ppBST, value);
        value = 17;
        insertNode(ppBST, value);
        printf("\nBST\nRoot:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Left's Right Child:\nValue = %i, Address = %p\n", ((pBST->left)->right)->value, (pBST->left)->right);
        printf("Right Child:\nValue = %i, Address = %p\n", (pBST->right)->value, pBST->right);
        printf("Right's Left Child:\nValue = %i, Address = %p\n", ((pBST->right)->left)->value, (pBST->right)->left);        

        maxNode = findMaxNode(pBST);      
        printf("\nNode with Min Value = %i\n\n", maxNode);
        EXPECT_EQ(maxNode, 21);
    }

    /* "isBST" function tests */
    // 1. Checks whether empt BST (Node* NULL) is BST, i.e. returns 0 (Not BST)
    TEST(Node, isBST_Empty) {
        Node* pEmptyBST = NULL;
        int status;
        status = isBST(pEmptyBST);
        printf("\nEmpty BST\nIs BST? - %s\n\n", status ? "Yes" : "No");
        EXPECT_EQ(status, 0);
    }
    // 2. Checks whether no child BST is BST, i.e. returns 1 (BST)
    TEST(Node, isBST_No_Child) {
        Node* pBST = NULL;
        Node** ppBST = &pBST;
        int status;
        int value = 15;
        insertNode(ppBST, value);
        printf("\nBST\nRoot:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = NULL, Address = %p\n", pBST->left);
        printf("Right Child:\nValue = NULL, Address = %p\n", pBST->right);     

        status = isBST(pBST);     
        printf("\nNo Child BST\nIs BST? - %s\n\n", status ? "Yes" : "No");
        EXPECT_EQ(status, 1);
    }
    // 3.1. Checks whether BST with True Left Child is BST, i.e. returns 1 (BST)
    TEST(Node, isBST_T_Left_Child) {
        Node* pBST = NULL;
        Node** ppBST = &pBST;
        int status;
        int value = 15;
        insertNode(ppBST, value);
        value = 5;
        insertNode(ppBST, value);
        printf("\nBST\nRoot:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Right Child:\nValue = NULL, Address = %p\n", pBST->right);     

        status = isBST(pBST);     
        printf("\nBST with True Left Child\nIs BST? - %s\n\n", status ? "Yes" : "No");
        EXPECT_EQ(status, 1);
    }
    // 3.2. Checks whether BST with False Left Child is BST, i.e. returns 0 (Not BST)
    TEST(Node, isBST_F_Left_Child) {
        Node* pBST = NULL;
        Node** ppBST = &pBST;
        int status;
        int value = 15;
        insertNode(ppBST, value);
        pBST->left = (Node*) malloc(sizeof(Node));
        *(pBST->left) = { .value = 20, .left = (Node*) NULL, .right = (Node*) NULL};
        printf("\nBST\nRoot:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Right Child:\nValue = NULL, Address = %p\n", pBST->right);     

        status = isBST(pBST);     
        printf("\nBST with False Left Child\nIs BST? - %s\n\n", status ? "Yes" : "No");
        EXPECT_EQ(status, 0);
    }
    // 4.1. Checks whether BST with True Right Child is BST, i.e. returns 1 (BST)
    TEST(Node, isBST_T_Right_Child) {
        Node* pBST = NULL;
        Node** ppBST = &pBST;
        int status;
        int value = 15;
        insertNode(ppBST, value);
        value = 25;
        insertNode(ppBST, value);
        printf("\nBST\nRoot:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = NULL, Address = %p\n", pBST->left);
        printf("Right Child:\nValue = %i, Address = %p\n", (pBST->right)->value, pBST->right);     

        status = isBST(pBST);     
        printf("\nBST with True Right Child\nIs BST? - %s\n\n", status ? "Yes" : "No");
        EXPECT_EQ(status, 1);
    }
    // 4.2. Checks whether BST with False Right Child is BST, i.e. returns 0 (Not BST)
    TEST(Node, isBST_F_Right_Child) {
        Node* pBST = NULL;
        Node** ppBST = &pBST;
        int status;
        int value = 15;
        insertNode(ppBST, value);
        pBST->right = (Node*) malloc(sizeof(Node));
        *(pBST->right) = { .value = 10, .left = (Node*) NULL, .right = (Node*) NULL};
        printf("\nBST\nRoot:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = NULL, Address = %p\n", pBST->left);
        printf("Right Child:\nValue = %i, Address = %p\n", (pBST->right)->value, pBST->right);    

        status = isBST(pBST);     
        printf("\nBST with False Right Child\nIs BST? - %s\n\n", status ? "Yes" : "No");
        EXPECT_EQ(status, 0);
    }
    // 5.1. Checks whether BST with True Right and Left Children is BST, i.e. returns 1 (BST)
    TEST(Node, isBST_T_Right_T_Left_Child) {
        Node* pBST = NULL;
        Node** ppBST = &pBST;
        int status;
        int value = 15;
        insertNode(ppBST, value);
        value = 25;
        insertNode(ppBST, value);
        value = 2;
        insertNode(ppBST, value);
        printf("\nBST\nRoot:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Right Child:\nValue = %i, Address = %p\n", (pBST->right)->value, pBST->right);     

        status = isBST(pBST);     
        printf("\nBST with True Right and True Left Children\nIs BST? - %s\n\n", status ? "Yes" : "No");
        EXPECT_EQ(status, 1);
    }
    // 5.2. Checks whether BST with False Right and True Children is BST, i.e. returns 0 (Not BST)
    TEST(Node, isBST_F_Right_T_Left_Child) {
        Node* pBST = NULL;
        Node** ppBST = &pBST;
        int status;
        int value = 15;
        insertNode(ppBST, value);
        value = 2;
        insertNode(ppBST, value);        
        pBST->right = (Node*) malloc(sizeof(Node));
        *(pBST->right) = { .value = 10, .left = (Node*) NULL, .right = (Node*) NULL};
        printf("\nBST\nRoot:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Right Child:\nValue = %i, Address = %p\n", (pBST->right)->value, pBST->right);     

        status = isBST(pBST);     
        printf("\nBST with False Right and True Left Children\nIs BST? - %s\n\n", status ? "Yes" : "No");
        EXPECT_EQ(status, 0);
    }
    // 5.3. Checks whether BST with True Right and False Children is BST, i.e. returns 0 (Not BST)
    TEST(Node, isBST_T_Right_F_Left_Child) {
        Node* pBST = NULL;
        Node** ppBST = &pBST;
        int status;
        int value = 15;
        insertNode(ppBST, value);
        value = 22;
        insertNode(ppBST, value);        
        pBST->left = (Node*) malloc(sizeof(Node));
        *(pBST->left) = { .value = 35, .left = (Node*) NULL, .right = (Node*) NULL};
        printf("\nBST\nRoot:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Right Child:\nValue = %i, Address = %p\n", (pBST->right)->value, pBST->right);     

        status = isBST(pBST);     
        printf("\nBST with True Right and False Left Children\nIs BST? - %s\n\n", status ? "Yes" : "No");
        EXPECT_EQ(status, 0);
    }
    // 5.4. Checks whether BST with True Right and False Children is BST, i.e. returns 0 (Not BST)
    TEST(Node, isBST_F_Right_F_Left_Child) {
        Node* pBST = NULL;
        Node** ppBST = &pBST;
        int status;
        int value = 15;
        insertNode(ppBST, value);     
        pBST->right = (Node*) malloc(sizeof(Node));
        *(pBST->right) = { .value = 10, .left = (Node*) NULL, .right = (Node*) NULL}; 
        pBST->left = (Node*) malloc(sizeof(Node));
        *(pBST->left) = { .value = 35, .left = (Node*) NULL, .right = (Node*) NULL};
        printf("\nBST\nRoot:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Right Child:\nValue = %i, Address = %p\n", (pBST->right)->value, pBST->right);     

        status = isBST(pBST);     
        printf("\nBST with False Right and False Left Children\nIs BST? - %s\n\n", status ? "Yes" : "No");
        EXPECT_EQ(status, 0);
    }

    /* "printInOrder" function tests */
    TEST(Node, printInOrder) {
        Node* pBST = NULL;
        Node** ppBST = &pBST;
        int value = 15;
        insertNode(ppBST, value);
        value = 5;
        insertNode(ppBST, value);
        value = 7;
        insertNode(ppBST, value);
        value = 1;
        insertNode(ppBST, value);
        value = 21;
        insertNode(ppBST, value);
        value = 17;
        insertNode(ppBST, value);
        value = 89;
        insertNode(ppBST, value);
        printf("\nBST\nRoot:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Left's Right Child:\nValue = %i, Address = %p\n", ((pBST->left)->right)->value, (pBST->left)->right);
        printf("Left's Left Child:\nValue = %i, Address = %p\n", ((pBST->left)->left)->value, (pBST->left)->left);
        printf("Right Child:\nValue = %i, Address = %p\n", (pBST->right)->value, pBST->right);
        printf("Right's Right Child:\nValue = %i, Address = %p\n", ((pBST->right)->right)->value, (pBST->right)->right);  
        printf("Right's Left Child:\nValue = %i, Address = %p\n", ((pBST->right)->left)->value, (pBST->right)->left);

        printf("\n");
        printInOrder(pBST);
        printf("\n\n");
    }

    /* "printPreOrder" function tests */
    TEST(Node, printPreOrder) {
        Node* pBST = NULL;
        Node** ppBST = &pBST;
        int value = 15;
        insertNode(ppBST, value);
        value = 5;
        insertNode(ppBST, value);
        value = 7;
        insertNode(ppBST, value);
        value = 1;
        insertNode(ppBST, value);
        value = 21;
        insertNode(ppBST, value);
        value = 17;
        insertNode(ppBST, value);
        value = 89;
        insertNode(ppBST, value);
        printf("\nBST\nRoot:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Left's Right Child:\nValue = %i, Address = %p\n", ((pBST->left)->right)->value, (pBST->left)->right);
        printf("Left's Left Child:\nValue = %i, Address = %p\n", ((pBST->left)->left)->value, (pBST->left)->left);
        printf("Right Child:\nValue = %i, Address = %p\n", (pBST->right)->value, pBST->right);
        printf("Right's Right Child:\nValue = %i, Address = %p\n", ((pBST->right)->right)->value, (pBST->right)->right);  
        printf("Right's Left Child:\nValue = %i, Address = %p\n", ((pBST->right)->left)->value, (pBST->right)->left);

        printf("\n");
        printPreOrder(pBST);
        printf("\n\n");
    }

   /* "printPostOrder" function tests */
    TEST(Node, printPostOrder) {
        Node* pBST = NULL;
        Node** ppBST = &pBST;
        int value = 15;
        insertNode(ppBST, value);
        value = 5;
        insertNode(ppBST, value);
        value = 7;
        insertNode(ppBST, value);
        value = 1;
        insertNode(ppBST, value);
        value = 21;
        insertNode(ppBST, value);
        value = 17;
        insertNode(ppBST, value);
        value = 89;
        insertNode(ppBST, value);
        printf("\nBST\nRoot:\nValue = %i, Address = %p\n", pBST->value, pBST);
        printf("Left Child:\nValue = %i, Address = %p\n", (pBST->left)->value, pBST->left);
        printf("Left's Right Child:\nValue = %i, Address = %p\n", ((pBST->left)->right)->value, (pBST->left)->right);
        printf("Left's Left Child:\nValue = %i, Address = %p\n", ((pBST->left)->left)->value, (pBST->left)->left);
        printf("Right Child:\nValue = %i, Address = %p\n", (pBST->right)->value, pBST->right);
        printf("Right's Right Child:\nValue = %i, Address = %p\n", ((pBST->right)->right)->value, (pBST->right)->right);  
        printf("Right's Left Child:\nValue = %i, Address = %p\n", ((pBST->right)->left)->value, (pBST->right)->left);

        printf("\n");
        printPostOrder(pBST);
        printf("\n\n");
    }
}
