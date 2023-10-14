/**
* Title: Binary Search Trees
* Author : Alper Bozkurt
* ID: 21802766
* Section : 2
* Homework : 2
* Description : BSTNode class that consist three constructor to create a node for BST.
 */

#ifndef BSTNode_h
#define BSTNode_h

using namespace std;

class BSTNode {
private:
    
    BSTNode();
    BSTNode(const int& nodeItem, BSTNode *left = NULL, BSTNode *right = NULL);
    BSTNode(const BSTNode& node);
    int item;
    BSTNode *leftChildPtr;
    BSTNode *rightChildPtr;
    friend class BST;
};
 

#endif /* BSTNode_h */
