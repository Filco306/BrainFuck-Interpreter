//
//  List.cpp
//  Tarea3EstructurasDeDatos
//
//  Created by Filip Cornell on 2017-05-11.
//  Copyright © 2017 Filip Cornell. All rights reserved.
//

#include "List.hpp"
#include <iostream>
using namespace std;
Node* Crear() {

    Node* r = new Node;



    r->left = NULL;
    r->right = NULL;
    return r;
}
void Add(Node* currentNode, int v, bool right) {
    Node* t = new Node;
    t->value = v;
    t->left = NULL;
    t->right = NULL;
    if (right) {
        if (currentNode->right == NULL) {
            currentNode->right = t;
            t->left = currentNode;
        } else {
            Node* tmp = currentNode->right;
            currentNode->right = t;
            t->left = currentNode;
            t->right = tmp;
            tmp->left = t;
        }
    } else {
        if (currentNode->left == NULL) {
            currentNode->left = t;
            t->right = currentNode;
        } else {
            Node* tmp = currentNode->left;
            currentNode->left = t;
            t->right = currentNode;
            t->left = tmp;
            tmp->right = t;
        }
    }

}
bool Move(Node *&list, bool right) {
    if (right) {
        if (list->right != NULL) {
            list = list->right;
            return true;
        } else {
            return false;
        }
    } else {
        if (list->left != NULL) {
            list = list->left;
            return true;
        } else {
            return false;
        }
    }


}

void Assign (Node*& n,int v) {

    n->value = v;
}

int Obtain(Node* n) {

    return n->value;
}

void Eliminate(Node*& n) {

    if (n->left != NULL) {
        Node* tmp = n;
        n = n->left;
        n->right = tmp->right;
    } else if (n->right != NULL) {
        Node* tmp = n;
        n = n->right;
        n->left = tmp->left;

    }



}
bool Empty(Node* l) {
    return (l == NULL);
}
