//
//  List.hpp
//  Tarea3EstructurasDeDatos
//
//  Created by Filip Cornell on 2017-05-11.
//  Copyright © 2017 Filip Cornell. All rights reserved.
//

#ifndef List_hpp
#define List_hpp
#include <iostream>
#include <stdio.h>
struct Node{
    int value;
    Node* left;
    Node* right;
};
Node* Crear();
void Add(Node*, int, bool);
bool Move(Node*&,bool);
void Assign(Node*&,int);
int Obtain(Node*);
void Eliminate(Node*&);
bool Empty(Node*);

#endif /* List_hpp */
