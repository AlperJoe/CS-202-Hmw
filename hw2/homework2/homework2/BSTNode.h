//
//  BSTNode.h
//  homework2
//
//  Created by Alper Bozkurt on 18.03.2023.
//

#ifndef BSTNode_h
#define BSTNode_h


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
