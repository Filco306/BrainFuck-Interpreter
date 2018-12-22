//
//  Interprete.hpp
//  Tarea3EstructurasDeDatos
//
//  Created by Filip Cornell on 2017-05-11.
//  Copyright © 2017 Filip Cornell. All rights reserved.
//

#ifndef Interprete_hpp
#define Interprete_hpp

#include <stdio.h>
#include <iostream>
#include "List.hpp"
using namespace std;
struct Interp {
    Node* instrucciones;
    Node* salida;
};
int getValue(char);
char getChar(int);
Interp* Iniciar();
void Load(int index, char*, Interp*);
void Show(Interp*);
void Execute(Interp*);
Interp* Finalizar(Interp*);
#endif /* Interprete_hpp */
