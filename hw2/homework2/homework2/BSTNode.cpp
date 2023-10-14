//
//  BSTNode.cpp
//  homework2
//
//  Created by Alper Bozkurt on 18.03.2023.
//

#include <stdio.h>
#include "BSTNode.h"


BSTNode::BSTNode():item(0), leftChildPtr(NULL), rightChildPtr(NULL){

}

BSTNode::BSTNode(const int& nodeItem, BSTNode *left, BSTNode *right):item(nodeItem), leftChildPtr(left), rightChildPtr(right){

}

BSTNode::BSTNode(const BSTNode &node):item(node.item), leftChildPtr(node.leftChildPtr), rightChildPtr(node.rightChildPtr){
}
