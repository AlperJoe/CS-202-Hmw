/**
* Title: Binary Search Trees
* Author : Alper Bozkurt
* ID: 21802766
* Section : 2
* Homework : 2
* Description : BSTNode class that consist three constructor to create a node for BST. 
 */

#include <stdio.h>
#include "BSTNode.h"


BSTNode::BSTNode():item(0), leftChildPtr(NULL), rightChildPtr(NULL){

}

BSTNode::BSTNode(const int& nodeItem, BSTNode *left, BSTNode *right):item(nodeItem), leftChildPtr(left), rightChildPtr(right){

}

BSTNode::BSTNode(const BSTNode &node):item(node.item), leftChildPtr(node.leftChildPtr), rightChildPtr(node.rightChildPtr){
}
