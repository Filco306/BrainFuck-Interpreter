//
//  Interprete.cpp
//  Tarea3EstructurasDeDatos
//
//  Created by Filip Cornell on 2017-05-11.
//  Copyright © 2017 Filip Cornell. All rights reserved.
//

#include "Interprete.hpp"
#include "List.hpp"
#include <iostream>
using namespace std;
int getValue(char s) {
    const char c[72] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', ':', '+', '{', '<', '>', '[', ']', '!'};
    for (int i = 0; i < 72; i++) {
        if (s == c[i]) {
            return i;
        }
    }
    
    return -1;
}



char getChar(int i) {
    int nr = i;
    if (i < 0) {
        nr = -1*i;
    }
    
    nr = nr % 72;
    const char c[72] = {' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', ':', '+', '{', '<', '>', '[', ']', '!'};
    return c[nr];
}

Interp* Iniciar() {
    Interp* i = new Interp;
    i->instrucciones = NULL;
    
    return i;
}

void Load(int index, char* s, Interp* in) {
    if (!Empty(in->instrucciones)) {
        Eliminate(in->instrucciones);
        delete in->instrucciones;
    }
    in->instrucciones = Crear();
    Assign(in->instrucciones, getValue(s[0]));
    int i = 1;
    
    while (s[i] != '!') {
        
        int a = getValue(s[i]);
        if (a == -1) {
            a = 66;
        }
        Add(in->instrucciones,a,true);
        Move(in->instrucciones,true);
        i++;
    }
    
    Add(in->instrucciones, getValue(s[i]),true);
}
void Show(Interp* in) {
    if (in->instrucciones == NULL) {
        cout << "sin instrucciones" << endl;
    } else {
        while (Move(in->instrucciones,false)) {
            
        }
        int v = Obtain(in->instrucciones);
        char c = getChar(v);
        cout << c;
        while (Move(in->instrucciones,true)) {
            cout << getChar(Obtain(in->instrucciones));
        }
        
        cout << endl;
    }
    
    
}


void Execute(Interp* in) {
    
    
    if (!Empty(in->instrucciones)) {
        while (Move(in->instrucciones,false)) {
            
        }
        
        in->salida = Crear();
        
        do {
            int c = Obtain(in->instrucciones);
            
            
            if (c == 63) {
                cout << Obtain(in->salida);
            } else if (c == 64) {
                cout << getChar(Obtain(in->salida));
            } else if (c == 65) {
                
                int v = Obtain(in->salida)+1;
                
                Assign(in->salida, v);
                
            } else if (c == 66) {
                Assign(in->salida, Obtain(in->salida)-1);
            } else if (c == 67) {
                if (!Move(in->salida, false)) {
                    Add(in->salida, 0, false);
                    Move(in->salida,false);
                }
            } else if (c == 68) {
                if (!Move(in->salida, true)) {
                    Add(in->salida, 0, true);
                    Move(in->salida, true);
                }
            } else if (c == 69) {
                Move(in->instrucciones,true);
                bool interrupt = false;
                while (!interrupt) {
                    c = Obtain(in->instrucciones);
                    if (c == 63) {
                        cout << Obtain(in->salida);
                    } else if (c == 64) {
                        cout << getChar(Obtain(in->salida));
                    } else if (c == 65) {
                        Assign(in->salida, Obtain(in->salida)+1);
                    } else if (c == 66) {
                        Assign(in->salida, Obtain(in->salida)-1);
                    } else if (c == 67) {
                        if (!Move(in->salida, false)) {
                            Add(in->salida, 0, false);
                            Move(in->salida,false);
                        }
                    } else if (c == 68) {
                        if (!Move(in->salida, true)) {
                            Add(in->salida, 0, true);
                            Move(in->salida, true);
                        }
                    } else if (c == 70) {
                        if (Obtain(in->salida) != 0) {
                            while (Move(in->instrucciones,false)) {
                                if (Obtain(in->instrucciones) == 69) {
                                    break;
                                }
                            }
                        } else {
                            interrupt = true;
                        }
                    }
                    if (!interrupt) {
                        Move(in->instrucciones, true);
                    }
                }
                
            }  else if (c == 71) {
                break;
            }
            
        } while (Move(in->instrucciones,true));
        
        while (Move(in->salida,false)) {
            
        }
        
        
        cout << endl;
        
    }
}
Interp* Finalizar (Interp* N) {
    delete N->instrucciones;
    delete N->salida;
    delete N;
    return NULL;
}


