//
//  NodeT.h
//  abb
//
//  Created by Pepe Hdez hdez on 10/2/18.
//  Copyright © 2018 Pepe Hdez hdez. All rights reserved.
//

#ifndef NodeT_h
#define NodeT_h
class NodeT{
public:
    NodeT(int data);
    int getData();
    NodeT* getLeft();
    NodeT* getRight();
    void setData(int data);
    void setLeft(NodeT *left);
    void setRight(NodeT *right);
private:
    int data;
    NodeT *left, *right;
};

NodeT:: NodeT(int data)
{
    this-> data = data;
    this-> left = NULL;
    this-> right = NULL;
}

int NodeT::  getData()
{
    return data;
}

 NodeT* NodeT:: getLeft()
{
    return left;
}

NodeT* NodeT:: getRight()
{
    return right;
}

void NodeT:: setData(int data)
{
    this -> data = data;
}

void NodeT:: setLeft(NodeT *left)
{
    this -> left = left;
}

void NodeT:: setRight(NodeT *right)
{
    this -> right = right;
}

#endif /* Node_h */
