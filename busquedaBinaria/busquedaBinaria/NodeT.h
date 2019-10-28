//
//  NodeT.h
//  busquedaBinaria
//
//  Created by Layla Tame on 3/5/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#ifndef NodeT_h
#define NodeT_h

class NodeT{
private:
    int data;
    NodeT *left;
    NodeT *right;
public:
    NodeT();
    NodeT(int data);
    void setData(int data);
    void setLeft(NodeT *left);
    void setRight(NodeT *right);
    int getData();
    NodeT* getLeft();
    NodeT* getRight();
};

NodeT::NodeT()
{
    this->data = NULL;
    this->left = NULL;
    this->right = NULL;
}

NodeT::NodeT(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
}

void NodeT::setData(int data){
    this->data = data;
}

void NodeT::setLeft(NodeT *left){
    this->left = left;
}

void NodeT::setRight(NodeT *right){
    this->right = right;
}

int NodeT::getData(){
    return this->data; //no es necesario el this
}

NodeT* NodeT::getLeft(){
    return this->left;
}

NodeT* NodeT::getRight(){
    return this->right;
}


#endif /* NodeT_h */
