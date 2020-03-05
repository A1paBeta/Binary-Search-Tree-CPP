
#ifndef _H_STDLIB
#include <stdlib.h>
#define _H_STDLIB
#endif

#ifndef _H_IOSTREAM
#include <iostream>
using namespace std;
#define _H_IOSTREAM
#endif


typedef struct NODE{
    int data;
    NODE *l_Node, *r_Node;
}Node;

Node* allocNewNode(int mData){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = mData;
    newNode->l_Node = newNode->r_Node = NULL;

    return newNode;
}

class BinarySearchTree{
    private:
        Node * root;
        int size;
        Node * doInsert(Node *mRoot, int mData){
            if(mRoot == NULL) mRoot = allocNewNode(mData);
            else {
                if(mRoot->data < mData){ mRoot->r_Node = doInsert(mRoot->r_Node, mData); }
                else if(mRoot->data > mData) { mRoot->l_Node = doInsert(mRoot->l_Node, mData); }
            }

            return mRoot;
        }
        
        void doShowAllNode(Node *mRoot){
            if(mRoot == NULL) return;

            doShowAllNode(mRoot->l_Node);
            cout << mRoot->data << " ";
            doShowAllNode(mRoot->r_Node);
        }
    
    public:
        BinarySearchTree(){
            root = NULL;
            size = 0;
        }

        void insertNode(int mData){
            root = doInsert(root, mData);
            ++size;
        }

        void showAllNode(){
            doShowAllNode(root);
        }

        int getSize(){
            return size;
        }
};
