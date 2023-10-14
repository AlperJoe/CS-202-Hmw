/**
* Title: Binary Search Trees
* Author : Alper Bozkurt
* ID: 21802766
* Section : 2
* Homework : 2
* Description : BST class for creating tree and and some functions to shape the tree
 such as inserting, deleting item etc.
 */


#ifndef BST_h
#define BST_h

#include "BSTNode.h"
#include <stack>

using namespace std;

class BST{
public:
    BST(); //default constructor
    BST(BSTNode* node);  //protected constructor
    BST(const int& rootItem);  //constructor
    BST(const int& rootItem, BST& leftTree, BST& rightTree);  //constructor
    void attachLeftSubtree(BST& leftTree);
    void attachRightSubtree(BST& rightTree);
    BST(const BST& tree); //copy constructor
    void copyTree(BSTNode* treePtr, BSTNode*& newTreePtr)const;
    ~BST();
    bool isEmpty();
    void destruct(BSTNode *node);
    
    //Question 2-a
    void insertItem(int key);
    void insertHelper(BSTNode*& treePtr, const int& newItem);
    void deleteItem(int key);
    void deleteHelper(BSTNode*& treePtr, int key);
    void deleteNodeItem(BSTNode*& treePtr);
    void processLeftMost(BSTNode *&treePtr, int &treeItem);
    void inorderTraversal(int& length);
    void inorder(BSTNode* treePtr, int& length);
    
    //Question 2-b
    bool hasSequence(int* seq, int length);
    int findItem(BSTNode *treePtr, int searchKey);
    int findNextMax(BSTNode* node, int value);

    //Question 2-c
    BSTNode* insertIntoMergedTree(BSTNode* root, int key);
    void insertTreeIntoMergedTree(BSTNode*& root, const BSTNode* tree);
    static BST* mergeHelper(const BST& tree1, const BST& tree2);
    





private:
    BSTNode *root;
};

#endif /* BST_h */
