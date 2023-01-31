#ifndef ICTE_4_H
#define ICTE_4_H

/*! @file */

/*! \brief Binary Search Tree (BST) Node and Operations Definitions
 *
 * Node has integer value (positive), 
 * pointers to left and right child nodes
 */
typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} Node;

/*! Insert a new node into BST
 *  If there is no node at all, creates one
 *  \param root The starting node in BST
 *  \param value The node's value
 */
void insertNode(Node** root, int value);

/*! Deletes a node from BST
 *  If there is no such node, retruns nothing
 *  \param root The starting node in BST
 *  \param value The node's value
 */
void deleteNode(Node** root, int value);

/*! Searches a node in BST, returns pointer to that node
 *  If there is no such node, retruns NULL pointer
 *  If there are two or more nodes with the same value, returns pointer for the first-met from the root 
 *  \param root The starting node in BST
 *  \param value The node's value
 */
Node* searchNode(Node** root, int value);

/*! Finds a node with the smallest value, returns that value
 *  If there is no node, returns 0
 *  \param root The starting node in BST
 */
int findMinNode(Node* root);

/*! Finds a node with the biggest value, returns that value
 *  If there is no node, returns 0 (all valid nodes values are positive)  
 *  \param root The starting node in BST
 */
int findMaxNode(Node* root);

/*! Checks whether a given object is BST or not
 *  If it is, returns 1. Otherwise 0
 *  \param root The starting node in BST
 */
int isBST(Node* root);

/*! Prints nodes of BST in "In-Order" traversal 
 *  (non-decreasing, mountain hills, 
 *  traverse left-subtree -> root -> right-subtree)
 *  \param root The starting node in BST
 */
void printInOrder(Node* root);

/*! Prints nodes of BST in "Pre-Order" traversal 
 *  (copy-tree, 
 *  traverse root -> left-subtree -> right-subtree)
 *  \param root The starting node in BST
 */
void printPreOrder(Node* root);

/*! Prints nodes of BST in "Post-Order" traversal 
 *  (delete-tree, 
 *  traverse left-subtree -> right-subtree -> root)
 *  \param root The starting node in BST
 */
void printPostOrder(Node* root);

#endif