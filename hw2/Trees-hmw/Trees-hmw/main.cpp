/**
* Title: Binary Search Trees
* Author : Alper Bozkurt
* ID: 21802766
* Section : 2
* Homework : 2
* Description : Analysis class for measure time in the process of
 inserting and deleting element time and display it.
 */

#include <iostream>
#include "BST.h"
#include "BSTNode.h"
#include "analysis.h"

using namespace std;


BST* merge(const BST& tree1, const BST& tree2){
    return tree1.mergeHelper(tree1,tree2);
}


int main() {
    
    //variables
    int length;
    BST tree;

    
    //question 2-a
    cout<<"Question 2 - a ----------------------------------"<<endl;
    cout<<endl;

    length = 12;
    
    tree.insertItem(1);
    tree.insertItem(2);
    tree.insertItem(3);
    tree.insertItem(4);
    tree.insertItem(5);
    tree.insertItem(6);
    
    tree.insertItem(7);
    tree.deleteItem(7);

    tree.insertItem(8);
    tree.insertItem(10);
    tree.insertItem(12);
    tree.insertItem(13);
    tree.insertItem(14);
    tree.insertItem(15);
    
    tree.inorderTraversal(length);
    
    cout<<endl;
    
    //question 2-b
    cout<<"Question 2 - b ----------------------------------"<<endl;
    cout<<endl;

    int sequence1[6] = {1,2,3,4,5,6};
    int sequence2[4] = {10,12,13,15};
    int sequence3[3] = {10,11,12};

    tree.hasSequence(sequence1, 6);
    tree.hasSequence(sequence2, 4);
    tree.hasSequence(sequence3, 3);

    cout<<endl;

    
    //question 2-c
    cout<<"Question 2 - c ----------------------------------"<<endl;
    cout<<endl;

    BST tree2;
    int ultimateLength = 19;
    
    tree2.insertItem(7);
    tree2.insertItem(9);
    tree2.insertItem(11);
    tree2.insertItem(13);
    tree2.insertItem(13);
    tree2.insertItem(16);
    tree2.insertItem(17);
    
    BST* ptr = merge(tree,tree2);
    ptr->inorderTraversal(ultimateLength);
    cout<<endl;
    
    //question 2-e
    cout<<"Question 2 - e ----------------------------------"<<endl;
    cout<<endl;

    timeAnalysis();
    return 0;
}


