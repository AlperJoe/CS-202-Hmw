//
//  BST.cpp
//  homework2
//
//  Created by Alper Bozkurt on 19.03.2023.
//

#include <stdio.h>
#include <iostream>
#include "BSTNode.h"
#include "BST.h"
#include <stdexcept>

using namespace std;

// default constructor
BST::BST() :root(NULL) {
    
}

// protected constructor
BST::BST(BSTNode *nodePtr) :root(nodePtr) {
    
}

// constructor
BST::BST(const int& rootItem){
    root = new BSTNode(rootItem,NULL,NULL);
}

// constructor
BST::BST(const int& rootItem, BST& leftTree, BST& rightTree) {
    root = new BSTNode(rootItem, NULL, NULL);
    attachLeftSubtree(leftTree);
    attachRightSubtree(rightTree);
}

void BST::attachLeftSubtree(BST& leftTree) {
    if (!isEmpty() && (root->leftChildPtr == NULL)) {
        root->leftChildPtr = leftTree.root;
        leftTree.root = NULL;
        
    }
}

void BST::attachRightSubtree(BST& rightTree) {
    if(!isEmpty() && (root -> rightChildPtr == NULL)){
        root -> rightChildPtr = rightTree.root;
        rightTree.root = NULL;
    }
}

// copy constructor
BST :: BST(const BST& tree){
    copyTree(tree.root, root);
}

void BST::copyTree(BSTNode* treePtr, BSTNode*& newTreePtr)const{
    
    if(treePtr != NULL){  //copy node
        newTreePtr = new BSTNode(treePtr -> item);
        copyTree(treePtr -> leftChildPtr, newTreePtr -> leftChildPtr);
        copyTree(treePtr -> rightChildPtr, newTreePtr -> rightChildPtr);
    }else{
        newTreePtr = NULL;  //copy empty tree
    }
}

// destructor
BST::~BST() {
    destruct(root);
}

void BST::destruct(BSTNode* treePtr){
    if(treePtr != NULL){
        destruct(treePtr -> leftChildPtr);
        destruct(treePtr -> rightChildPtr);
        delete treePtr;
        treePtr = NULL;
    }
}

bool BST::isEmpty(){
    return root == NULL;
}


void BST::insertItem(int key){
    insertHelper(root, key);
}
void BST::insertHelper(BSTNode*& treePtr, const int& newItem){
    if(treePtr == NULL){
        treePtr = new BSTNode(newItem,  NULL, NULL);
    }
    else if(newItem < treePtr -> item){
        insertHelper(treePtr -> leftChildPtr, newItem);
    }else{
        insertHelper(treePtr -> rightChildPtr, newItem);
    }
}

void BST::deleteItem(int key){
    deleteHelper(root, key);
}

void BST::deleteHelper(BSTNode*& treePtr, int key){
    if(treePtr == NULL){
        throw "Delete Failed";
    }
    else if(key == treePtr -> item){
        deleteNodeItem(treePtr);
    }
    else if(key < treePtr -> item){
        deleteHelper(treePtr -> leftChildPtr, key);
    }
    else{
        deleteHelper(treePtr -> rightChildPtr, key);
    }
}

void BST::deleteNodeItem(BSTNode*& treePtr){
    BSTNode *deletePtr;
    int replacementItem;
    
    if((treePtr -> leftChildPtr == NULL) &&(treePtr -> rightChildPtr == NULL)){
        delete treePtr;
        treePtr = NULL;
    }
    else if(treePtr -> leftChildPtr == NULL){
        deletePtr = treePtr;
        treePtr = treePtr->rightChildPtr;
        deletePtr->rightChildPtr = NULL;
        delete deletePtr;
    }
    else if(treePtr -> rightChildPtr == NULL){
        deletePtr = treePtr;
        treePtr = treePtr->leftChildPtr;
        deletePtr->leftChildPtr = NULL;
        delete deletePtr;
    }
    else{
        processLeftMost(treePtr -> rightChildPtr, replacementItem);
        treePtr -> item = replacementItem;
    }
}

void BST:: processLeftMost(BSTNode *&treePtr, int &treeItem){
    if(treePtr -> leftChildPtr == NULL){
        treeItem = treePtr -> item;
        BSTNode *deletePtr = treePtr;
        treePtr = treePtr->rightChildPtr;
        deletePtr->rightChildPtr = NULL;
        delete deletePtr;
    }
    else{
        processLeftMost(treePtr -> leftChildPtr, treeItem);
    }
}

void BST::inorderTraversal(int& length){
    inorder(root, length);
    cout<<"asdf";
}
void BST::inorder(BSTNode* treePtr, int length){
    if(treePtr != NULL){
        inorder(treePtr -> leftChildPtr, length);
        cout<<treePtr -> item <<endl;
        inorder(treePtr -> leftChildPtr, length);
    }
}


