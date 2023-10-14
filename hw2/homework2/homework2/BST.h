//
//  BST.h
//  homework2
//
//  Created by Alper Bozkurt on 19.03.2023.
//

#ifndef BST_h
#define BST_h

#include "BSTNode.h"

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
    
    void insertItem(int key);
    void insertHelper(BSTNode*& treePtr, const int& newItem);
    void deleteItem(int key);
    void deleteHelper(BSTNode*& treePtr, int key);
    void deleteNodeItem(BSTNode*& treePtr);
    void processLeftMost(BSTNode *&treePtr, int &treeItem);
    void inorderTraversal(int& length);
    void inorder(BSTNode* treePtr, int length);
    
private:
    BSTNode *root;
    
};

#endif /* BST_h */
