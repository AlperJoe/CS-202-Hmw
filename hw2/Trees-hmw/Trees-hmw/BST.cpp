/**
* Title: Binary Search Trees
* Author : Alper Bozkurt
* ID: 21802766
* Section : 2
* Homework : 2
* Description : BST class for creating tree and and some functions to shape the tree
 such as inserting, deleting item etc.
 */

#include <stdio.h>
#include <iostream>
#include "BSTNode.h"
#include "BST.h"
#include <stdexcept>
#include <stack>

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


void BST::insertItem(const int key){
    insertHelper(root, key);
}
void BST::insertHelper(BSTNode*& treePtr, const int& newItem){
    
    if(treePtr == NULL){
        treePtr = new BSTNode(newItem, NULL, NULL);
        if(treePtr == NULL)
            return;
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
    cout<<length<<" items are: "<<endl;
    inorder(root, length);
}

void BST::inorder(BSTNode* treePtr, int& length){
    
    if(treePtr != nullptr){

        inorder(treePtr -> leftChildPtr, length);
        
        if(length == 0) return;
        length--;

        cout<<treePtr -> item <<endl;
        
        inorder(treePtr -> rightChildPtr, length);
    }
}


int BST::findNextMax(BSTNode* root, int target) {
    BSTNode* curr = root;
    BSTNode* prev = NULL;

    // Find the node with the given value
    while (curr != NULL && curr->item != target) {
        if (curr->item > target) {
            prev = curr;
            curr = curr->leftChildPtr;
        }
        else {
            curr = curr->rightChildPtr;
        }
    }

    // If the target node has a right subtree, find the leftmost node in that subtree
    if (curr != NULL && curr->rightChildPtr != NULL) {
        curr = curr->rightChildPtr;
        while (curr->leftChildPtr != NULL) {
            curr = curr->leftChildPtr;
        }
        return curr->item;
    }
    
    // If the target node does not have a right subtree, return the parent node whose left subtree contains the target
    return prev->item;
}

bool BST::hasSequence(int* seq, int length){
    
    int treeElement;
    
    if(findItem(root, seq[0]) == -1){
        return false;
    }
    else{
        treeElement = findItem(root, seq[0]);
    }
    
    for(int i = 0; i < length; i++){
        if(treeElement != seq[i]){
            cout<<"false because "<<seq[i]<<" supposed to be "<<treeElement<<endl;
            return false;
        }
        treeElement = findNextMax(root, treeElement);
    }
    cout<<"true"<<endl;
    return true;
}

int BST::findItem(BSTNode *treePtr, int searchKey){
    BSTNode *temp = new BSTNode;
    temp = treePtr;
    
    while(temp != NULL){
        if(temp -> item == searchKey){
            return searchKey;
        }
        else if(temp -> item > searchKey){
            temp = temp -> leftChildPtr;
        }
        else{
            temp = temp -> rightChildPtr;
        }
    }
    return -1;
}




BSTNode*  BST::insertIntoMergedTree(BSTNode* root, int key) {
   
    if (root == nullptr) {
        return new BSTNode(key);
    } else if (key <= root->item) {
        root->leftChildPtr = insertIntoMergedTree(root->leftChildPtr, key);
    } else if (key > root->item) {
        root->rightChildPtr = insertIntoMergedTree(root->rightChildPtr, key);
    }
    return root;
}


void BST::insertTreeIntoMergedTree(BSTNode*& root, const BSTNode* tree) {
    if (tree != nullptr) {
        insertTreeIntoMergedTree(root, tree->leftChildPtr);
        root = insertIntoMergedTree(root, tree->item);
        insertTreeIntoMergedTree(root, tree->rightChildPtr);
    }
}

BST* BST::mergeHelper(const BST& tree1, const BST& tree2) {
   // Create a new empty BST
   BST* mergedTree = new BST();

   // Insert all elements from the first tree into the new BST
   mergedTree->insertTreeIntoMergedTree(mergedTree->root, tree1.root);

   // Insert all elements from the second tree into the new BST
   mergedTree->insertTreeIntoMergedTree(mergedTree->root, tree2.root);

   return mergedTree;
}

/*
BST BST::mergeHelper(const BST& tree1, const BST& tree2) {
   // Create a new empty BST
   BST mergedTree;

   // Insert all elements from the first tree into the new BST
   mergedTree.insertTreeIntoMergedTree(mergedTree.root, tree1.root);

   // Insert all elements from the second tree into the new BST
   mergedTree.insertTreeIntoMergedTree(mergedTree.root, tree2.root);

   return mergedTree;
}
*/
