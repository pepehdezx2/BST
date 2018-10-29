//
//  BST.h
//  abb
//
//  Created by Pepe Hdez hdez on 10/2/18.
//  Copyright © 2018 Pepe Hdez hdez. All rights reserved.
//

#ifndef BST_h
#define BST_h
#include <queue>
#include <stack>
#include "NodeT.h"
using namespace std;
class BST{
public:
    BST();
    ~BST();
    void copy(NodeT *a, NodeT *b);
    void add(int data);
    bool search(int data);
    void remove(int data);
    void print(int c);
    void ancestors(int data);
    int whatLevelamI(int data);
    int nearstRelative(int a, int b);
    int height();
    int count();
    int maxWidth();
    bool operator == (const BST &tb);
    void mirror();
    int howmanynodes(int data);
    int lowest();
    int descendants(int data);
private:
    NodeT *root;
    int howManyChildren(NodeT *r);
    int pred(NodeT *r);
    int suce(NodeT *r);
    void preOrder(NodeT *r);
    void inOrder(NodeT *r);
    void postOrder(NodeT *r);
    void levelxlevel(NodeT *r);
    void liberar(NodeT *r);
    int heightr(NodeT *r);
    int cuenta(NodeT *r);
    int width(NodeT* r, int data);
    bool compare(NodeT *a, NodeT *b);
    void mirrorr(NodeT *r);
    NodeT* low(NodeT *r);
    int countDescendants(NodeT *curr);
};

BST::BST() {
    root=NULL;
}

BST::~BST(){
    liberar(root);
}

void BST::liberar(NodeT *r){
    if (r!=NULL){
        liberar(r->getLeft());
        liberar(r->getRight());
        delete r;
    }
}

int BST::howManyChildren(NodeT *r){
    int cont=0;
    if(r->getLeft() != NULL){
        cont++;
    }
    if(r->getRight() != NULL){
        cont++;
    }
    return cont;
}

int BST::pred(NodeT *r){
    NodeT *aux=r->getLeft();
    while (aux->getRight()!=NULL){
        aux=aux->getRight();
    }
    return aux->getData();
}

int BST::suce(NodeT *r){
    NodeT *aux=r->getRight();
    while (aux->getLeft()!=NULL){
        aux=aux->getLeft();
    }
    return aux->getData();
}

void BST::preOrder(NodeT *r){
    if (r!=NULL){
        cout << r->getData() << " ";
        preOrder(r->getLeft());
        preOrder(r->getRight());
    }
}

void BST::inOrder(NodeT *r){
    if (r!=NULL){
        inOrder(r->getLeft());
        cout << r->getData() << " ";
        inOrder(r->getRight());
    }
}

void BST::postOrder(NodeT *r){
    if (r!=NULL){
        postOrder(r->getLeft());
        postOrder(r->getRight());
        cout << r->getData() << " ";
    }
}

void BST::levelxlevel(NodeT *r){
    if (r != NULL){
        queue<NodeT *> q;
        q.push(r);
        while (!q.empty()){
            NodeT *lxl=q.front();
            q.pop();
            cout << lxl->getData() << " ";
            if (lxl->getLeft()){
                q.push(lxl->getLeft());
            }
            if (lxl->getRight()){
                q.push(lxl->getRight());
            }
        }
    }
    }

bool BST::search(int data){
    NodeT*curr=root;
    while(curr!=NULL)
    {
        if(curr->getData()==data)
        {
            return true;
        }
        curr=(curr->getData() > data) ?
        curr->getLeft() : curr->getRight();
    }
    return false;
}

void BST::add(int data){
    NodeT *curr=root;
    NodeT *father=NULL;
    while (curr!=NULL){
        if(curr->getData()==data){
            return;
        }
        father=curr;
        curr=(curr->getData() > data) ?
        curr->getLeft() : curr->getRight();
    }
    if (father==NULL){
        root = new NodeT(data);
    }
    else{
        if (father->getData() > data){
            father->setLeft(new NodeT(data));
        }
        else{
            father->setRight(new NodeT(data));
        }
    }
}

void BST::ancestors(int data){
    if (search(data)==false){
        cout << "no existe el numero en el abb" << endl;
        return;
    }
    NodeT *curr=root;
    stack<int> s;
    while (curr != NULL){
        if (curr->getData() > data){
            s.push(curr->getData());
            curr=curr->getLeft();
        }
        else
        if (curr->getData() < data){
            s.push(curr->getData());
            curr=curr->getRight();
    }
        else
            if (curr->getData() == data){
                curr=NULL;
            }
        }
    if(s.empty()==true){
        cout << "no tiene ancestros" << endl;
        return;
    }
    else{
    while (!s.empty()){
        cout << s.top() << " ";
        s.pop();
    }
        cout << endl;
    }
    return;
}

int BST::whatLevelamI(int data){
    if (search(data)==false){
        return -1;
    }
    else{
    NodeT *curr=root;
    int c=0;
    while (curr != NULL){
        if (curr->getData() > data){
            c++;
            curr=curr->getLeft();
        }
        else
            if (curr->getData() < data){
                c++;
                curr=curr->getRight();
            }
            else
                if (curr->getData() == data){
                    curr=NULL;
                }
    }
        return c;
    }
}

void BST::remove(int data){
    NodeT *father=NULL;
    NodeT *curr=root;
    while (curr!=NULL && curr->getData() != data){
        father= curr;
        curr=(curr->getData()>data) ?
        curr->getLeft() : curr->getRight();
    }
    if (curr==NULL){
        return;
    }
    int c= howManyChildren(curr);
    switch (c){
        case 0: if (father==NULL){
            root=NULL;
        }
        else{
            if (father->getData() > data){
                father->setLeft(NULL);
            }
            else{
                father->setRight(NULL);
            }
        }
            delete curr;
            break;
        case 1: if (father==NULL){
            if (curr->getLeft()!=NULL){
                root=curr->getLeft();
            }
            else{
                root=curr->getRight();
            }
        }
        else{
            if (father->getData() > data){
                if (curr->getLeft()!=NULL){
                    father->setLeft(curr->getLeft());
                }
                else
                    father->setRight(curr->getRight());
            }
            else{
                if (curr->getLeft()!=NULL){
                    father->setLeft(curr->getLeft());
                }
                else
                    father->setRight(curr->getRight());
            }
        }
            delete curr;
            break;
        case 2: int x = suce(curr);
            remove(x);
            curr->setData(x);
            break;
    }
}

int BST::heightr(NodeT *r){
    if(r==NULL){
        return 0;
    }
    else{
        return  (1 + heightr(r->getLeft())>=1 + heightr(r->getRight())) ?
        1 + heightr(r->getLeft()): 1 + heightr(r->getRight());
    }
}

int BST::height(){
    return heightr(root);
}

void BST::print(int c){
    switch(c){
        case 1: preOrder(root);
            cout << endl;
            break;
        case 2: inOrder(root);
            cout << endl;
            break;
        case 3: postOrder(root);
            cout << endl;
            break;
        case 5: levelxlevel(root);
            cout << endl;
            break;
    }
}

int BST::cuenta(NodeT *r){
    if (r==NULL){
        return 0;
    }
    return 1+cuenta(r->getLeft())+cuenta(r->getRight());
}

int BST::count(){
    return cuenta(root);
}

int BST::width(NodeT* r, int data){
    if(r == NULL){
        return 0;
    }
    if(data == 0){
        return 1;
    }
    else
        if(data > 0){
        return width(r->getLeft(), data -1) + width(r->getRight(), data -1);
    }
    return -1;
}

//int BST::getWidth(NodeT* r, int data)
//{
//    if(r == NULL)
//    {
//        return 0;
//    }
//
//    if(data == 0)
//    {
//        return 1;
//    }
//
//    else if(data >= 1)
//    {
//        return getWidth(r->getLeft(), data -1) + getWidth(r->getRight(), data -1);
//    }
//
//    return -1;
//}
//
//int BST::getNumDenNodes(int data)
//{
//    return getWidth(root, data);
//}

int BST::maxWidth(){
    int max, hgt, wth;
    max=0;
    hgt=heightr(root);
    for(int i=1 ; i<=hgt; i++){
        wth=width(root, i);
        if(wth > max){
            max = wth;
        }
    }
    return max;
}

int BST::nearstRelative(int a, int b){
    int mayor = (a>b) ? a : b;
    int menor = (a<b) ? a : b;
    int father;
    
    if(root->getData()==mayor || root->getData()==menor){
        cout << "No hay relativo más cercano" << endl;
        return -1;
    }
    NodeT *curr = root;
    if(menor > root->getData()){
        curr = root->getRight();
    }
    else
        if(mayor < root->getData()){
        curr = root->getLeft();
    }
    
    while(!(menor < curr->getData() && mayor > curr->getData())){
        father = curr->getData();
        if(menor > curr->getData()){
            curr = curr->getRight();
        }
        if(mayor < curr->getData()){
            curr = curr->getLeft();
        }
        if(menor == curr->getData() || mayor == curr->getData()){
            return father;
        }
    }
    return curr->getData();
}

bool BST::compare(NodeT *a, NodeT *b){
    if(a==NULL && b==NULL){
        return true;
    }
    else
        if(a!=NULL && b!= NULL){
        if(a->getData() != b->getData()){
            return false;
        }
        else
        {
            return compare(a->getLeft(),b->getLeft()) && compare(a->getRight(),b->getRight());
        }
    }
    else
    {
        return false;
    }
}

bool BST::operator == (const BST &tB){
    return compare(this->root,tB.root);
}

void BST::mirrorr(NodeT *r){
    if(r != NULL){
        NodeT * temp = r->getLeft();
        r->setLeft(r->getRight());
        r->setRight(temp);
        mirrorr(r->getLeft());
        mirrorr(r->getRight());
    }
}

void BST::mirror(){
    mirrorr(root);
}

void BST::copy(NodeT *a, NodeT *b){
    if(b->getLeft()!= NULL){
        a->setLeft(new NodeT(b->getLeft()->getData()));
        copy(a->getLeft(), b->getLeft());
    }
    if(b->getRight()!= NULL){
        a->setRight(new NodeT(b->getRight()->getData()));
        copy(a->getRight(), b->getRight());
    }
}

int BST::howmanynodes(int data){
    return width(root, data);
}

int BST::lowest(){
    NodeT* nod=low(root);
    return nod->getData();
}
NodeT* BST::low(NodeT *r){
    if(r->getLeft()!=NULL){
        return low(r->getLeft());
    }
    else
        return r;
}

int BST::countDescendants(NodeT *curr){
    if(curr == NULL){
        return 0;
    }
    return countDescendants(curr->getLeft()) + countDescendants(curr->getRight()) + 1;
}

int BST::descendants(int data){
    if(root == NULL){
        return -1;
    }
    
    NodeT *curr = root;
    while(curr!= NULL && curr->getData() != data){
        curr = (data > curr->getData()) ? curr->getRight() : curr->getLeft();
    }
    
    return countDescendants(curr) - 1;
}


#endif /* BST_h */
