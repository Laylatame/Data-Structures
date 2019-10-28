//
//  BST.h
//  busquedaBinaria
//
//  Created by Layla Tame on 3/5/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#ifndef BST_h
#define BST_h

#include "NodeT.h"
using namespace std;

class BST{
private:
    NodeT *root;
    //int iNodes = 0;
    int howManyChildren(NodeT *r);
    int pred(NodeT *r);
    int succ(NodeT * r);
    void preOrder(NodeT *r);
    void inOrder(NodeT *r);
    void postOrder(NodeT *r);
    void libera(NodeT *r);
    void despliegaHojas(NodeT *r);
    int iCount(NodeT *r);
    int height(NodeT *r);
    bool ancestors(NodeT *r, int node);
    int findDepth(int x, NodeT *nodeSearch, int depth);
    void levelByLevel(NodeT *r);
    unsigned long findMaxWidth(NodeT *r);
    //pair<bool,queue<int>> queueAncestors(int node, NodeT *r);
    int nearestRelativeAux(int node1, int node2, NodeT *r);
    NodeT* copyConstructor(NodeT *r);
    bool checkEqual(NodeT *tree1, NodeT *tree2);
    void mirrorAux(NodeT *r);

public:
    BST();
    ~BST();
    void add(int data);
    bool search(int data);
    void remove(int data);
    void print(int c);
    void printLeaves();
    void count();
    int getHeight();
    void printAncestors(int node);
    int whatLevel(int x);
    unsigned long maxWidth();
    int nearestRelative(int node1, int node2);
    BST(const BST &entryTree);
    bool operator==(const BST &tree1);
    void mirror();
};

BST::BST(){
    root = NULL;
}

BST::~BST()
{
    libera(root);
}

void BST::add(int data){
    NodeT* father = NULL;
    NodeT* curr = root;
    
    while (curr != NULL){
        if (curr->getData() == data){
            return;
        }
        father = curr;
        curr = (curr->getData() > data ?
                curr->getLeft() : curr->getRight());
    }
    if (father == NULL){
        root = new NodeT(data);
    }
    else{
        if(father->getData() > data){
            father->setLeft(new NodeT(data));
        }
        else{
            father->setRight(new NodeT(data));
        }
    }
}

bool BST::search(int data){
    NodeT *curr = root;
    while(curr != NULL)
    {
        if(curr->getData() == data)
        {
            return true;
        }
        curr = (curr->getData() > data ?
                curr->getLeft() : curr->getRight());
    }
    return false;
}

int BST::howManyChildren(NodeT *r)
{
    int iCount = 0;
    if(r->getLeft() != NULL)
    {
        iCount++;
    }
    if(r->getRight() != NULL)
    {
        iCount++;
    }
    return iCount;
}

int BST::pred(NodeT *r)
{
    NodeT* curr = r->getLeft();
    while(curr->getRight() != NULL)
    {
        curr = curr->getRight();
    }
    return curr->getData();
}

int BST::succ(NodeT *r)
{
    NodeT* curr = r->getRight();
    while(curr->getRight() != NULL)
    {
        curr = curr->getLeft();
    }
    return curr->getData();
}

void BST::remove(int data)
{
    NodeT *curr = root;
    NodeT *father = NULL;
    
    while(curr != NULL && curr->getData() != data)
    {
        father = curr;
        curr = (curr->getData() > data ?
                curr->getLeft() : curr->getRight());
    }
    if(curr == NULL)
    {
        return;
    }
    int c = howManyChildren(curr);
    switch (c)
    {
        case 0:
            if(father == NULL)
            {
                root = NULL;
            }
            else
            {
                if(father->getData() > data)
                {
                    father->setLeft(NULL);
                }
                else
                {
                    father->setRight(NULL);
                }
            }
            delete curr;
            break;
            
        case 1:
            if(father == NULL)
            {
                if(curr->getLeft() != NULL)
                {
                    root = curr->getLeft();
                }
                else
                {
                    root = curr->getRight();
                }
            }
            else //el padre no es null
            {
                if(father->getData() > data)
                {
                    if(curr->getLeft() != NULL)
                    {
                        father->setLeft(curr->getLeft());
                    }
                    else
                    {
                        father->setLeft(curr->getRight());
                    }
                }
                else
                {
                    if(curr->getLeft() != NULL)
                    {
                        father->setRight(curr->getLeft());
                    }
                    else
                    {
                        father->setRight(curr->getRight());
                    }
                }
            }
            break;
        case 2:
            int x = succ(curr);
            remove(x);
            curr->setData(x);
            break;
    }
}

void BST::preOrder(NodeT *r)
{
    if(r != NULL)
    {
        cout << r->getData() << " ";
        preOrder(r->getLeft());
        preOrder(r->getRight());
    }
}

void BST::inOrder(NodeT *r)
{
    if(r != NULL)
    {
        inOrder(r->getLeft());
        cout << r->getData() << " ";
        inOrder(r->getRight());
    }
}

void BST::postOrder(NodeT *r)
{
    if(r != NULL)
    {
        postOrder(r->getLeft());
        postOrder(r->getRight());
        cout << r->getData() << " ";
    }
}

void BST::libera(NodeT *r)
{
    if(r != NULL)
    {
        libera(r->getLeft());
        libera(r->getRight());
        delete r;
    }
}

void BST::print(int c)
{
    switch(c)
    {
        case 1:
            preOrder(root);
            break;
        case 2:
            inOrder(root);
            break;
        case 3:
            postOrder(root);
            break;
        case 5:
            levelByLevel(root);
            break;
    }
    cout << endl;
}

void BST::despliegaHojas(NodeT *r)
{
    if(r != NULL)
    {
        if(r->getLeft() == NULL && r->getRight() == NULL)
        {
            cout << r->getData() << " ";
        }
        
        despliegaHojas(r->getLeft());
        despliegaHojas(r->getRight());
    }
    
}

void BST::printLeaves()
{
    despliegaHojas(root);
    cout << endl;
}

int BST::iCount(NodeT *r)
{
    if(r != NULL)
    {
        int iNodes = 0;
        int nodesLeft = iCount(r->getLeft());
        int nodesRight = iCount(r->getRight());
     
        iNodes += nodesLeft + nodesRight + 1;

        return iNodes;
    }
    return 0;
}

void BST::count()
{
    cout << iCount(root) << endl;
}

int BST::height(NodeT *r)
{
    if (r == NULL)
        return 0;
    else
    {
        int depth1 = height(r->getLeft());
        int depth2 = height(r->getRight());
        
        return (depth1 > depth2 ? depth1+1 : depth2+1);
    }
    
    return 0;
}

int BST::getHeight()
{
    return height(root);
}

bool BST::ancestors(NodeT *r, int node)
{
    bool findLeft= false, findRight = false;
    /* base cases */
    if (r == NULL)
    {
        return false;
    }
    
    if (r->getData() == node)
    {
        return true;
    }
    
    findLeft = ancestors(r->getLeft(), node);
    if(findLeft == false)
    {
        findRight = ancestors(r->getRight(), node);
    }
    
    if(findLeft == true || findRight == true)
    {
        cout << r->getData() << " ";
        return true;
    }
    
    return false;
}

void BST::printAncestors(int node)
{
    ancestors(root, node);
    cout << endl;
}

int BST::findDepth(int x, NodeT *nodeSearch, int depth)
{
    //Buscar si existe el número y encontrar en que nivel está
    if(nodeSearch == NULL)
    {
        return 0;
    }
    
    if(nodeSearch->getData() == x)
    {
        return depth;
    }
    else
    {
        int tempNode1 = findDepth(x, nodeSearch->getLeft(), depth+1);
        if(tempNode1 != 0)
        {
            return tempNode1;
        }
        int tempNode2 = findDepth(x, nodeSearch->getRight(), depth+1);
        if(tempNode2 != 0)
        {
            return tempNode2;
        }
    }
    return 0;
}

int BST::whatLevel(int x)
{
    if(search(x))
    {
        int depth = 0;
        return findDepth(x, root, depth);
    }
    else
    {
        return -1;
    }
}

void BST::levelByLevel(NodeT *r)
{
    NodeT *aux;
    queue<NodeT*> binTree;
    
    binTree.push(r);
    while(!binTree.empty())
    {
        aux = binTree.front();
        binTree.pop();
        
        if(aux != NULL)
        {
            if(aux->getLeft() != NULL)
            {
                binTree.push(aux->getLeft());
            }
            if(aux->getRight() != NULL)
            {
                binTree.push(aux->getRight());
            }
        
            cout << aux->getData() << " ";
        }
    }
}

unsigned long BST::findMaxWidth(NodeT *r)
{
    if(r == NULL)
    {
        return 0;
    }
    
    unsigned long iWith = 0, tempWith;
    NodeT *aux;
    queue<NodeT*> binTree;
    
    binTree.push(r);
    while(!binTree.empty())
    {
        tempWith = binTree.size();
        iWith = (tempWith > iWith ? tempWith : iWith);

        while(tempWith > 0)
        {
            aux = binTree.front();
            
            if(aux->getLeft() != NULL)
            {
                binTree.push(aux->getLeft());
            }
            
            if(aux->getRight() != NULL)
            {
                binTree.push(aux->getRight());
            }
            
            binTree.pop();
            tempWith--;
        }
    }
    
    return iWith;
}

unsigned long BST::maxWidth()
{
    return findMaxWidth(root);
}

/*int BST::queueAncestors(int node, NodeT *r)
{
    queue<int> ancestors;
    if(r == NULL)
    {
        return make_pair(false,ancestors);
    }
    
    if(r->getData() ==  node)
    {
        ancestors.push(r->getData());
        return make_pair(true,ancestors);
    }
    
    pair<bool,queue<int>> findLeft, findRight;
    findLeft.first = false;
    findRight.first = false;
    
    findLeft = queueAncestors(node, r->getLeft());
    
    if(findLeft.first == false)
    {
        findRight = queueAncestors(node, r->getRight());
    }
    
    if(findLeft.first == true || findRight.first == true)
    {
        ancestors.push(r->getData());
        return make_pair(true,ancestors);
    }
    return make_pair(false, ancestors);
}*/

int BST::nearestRelativeAux(int node1, int node2, NodeT *r)
{
    if(r == NULL)
    {
        return NULL;
    }
    int tempData = r->getData();
    
    if(tempData < node1 && tempData < node2)
    {
        return nearestRelativeAux(node1, node2, r->getRight());
    }
    else if(tempData > node1 && tempData > node2)
    {
        return nearestRelativeAux(node1, node2, r->getLeft());
    }
    
    return tempData;
}

int BST::nearestRelative(int node1, int node2)
{
    return nearestRelativeAux(node1, node2, root);
}

NodeT* BST::copyConstructor(NodeT *r)
{
    NodeT *aux = new NodeT;
    
    aux->setData(r->getData());
    if(r->getLeft() != NULL)
    {
        aux->setLeft(copyConstructor(r->getLeft()));
    }
    if(r->getRight() != NULL)
    {
        aux->setRight(copyConstructor(r->getRight()));
    }
    
    return aux;
}

BST::BST(const BST &entryTree)
{
    root = copyConstructor(entryTree.root);
}

void BST::mirrorAux(NodeT *r)
{
    if(r == NULL)
    {
        return;
    }
    
    NodeT *aux;
    
    mirrorAux(r->getLeft());
    mirrorAux(r->getRight());
    
    aux = r->getRight();
    r->setRight(r->getLeft());
    r->setLeft(aux);
}

void BST::mirror()
{
    mirrorAux(root);
}

bool BST::checkEqual(NodeT *tree1, NodeT *tree2)
{
    if(tree1 == NULL && tree2 == NULL)
    {
        return true;
    }
    else if(tree1 != NULL && tree2 != NULL)
    {
        if(tree1->getData() == tree2->getData())
        {
            if (checkEqual(tree1->getLeft(), tree2->getLeft()) && checkEqual(tree1->getRight(), tree2->getRight()))
            {
                return true;
            }
            return false;
        }
    }
    return false;
}

bool BST::operator==(const BST &tree1)
{
    if(iCount(root) != iCount(tree1.root))
    {
        return false;
    }
    return checkEqual(tree1.root, root);
}

#endif /* BST_h */
