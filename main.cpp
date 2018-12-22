//
//  main.cpp
//  Tarea3EstructurasDeDatos
//
//  Created by Filip Cornell on 2017-05-07.
//  Copyright © 2017 Filip Cornell. All rights reserved.
//

#include <iostream>
#include "List.hpp"
#include "Interprete.hpp"
using namespace std;


int main(int argc, const char * argv[]) {
    int cantidadProgramas;
    cin >> cantidadProgramas;
    char c = 'a';
    char** programas = new char*[500];
    for (int i = 0; i < cantidadProgramas; i++) {


        programas[i] = new char[500];
        cin >> programas[i];
    }

    c = ' ';

    Interp* in = Iniciar();

    while (c != 's') {
        cin >> c;

        if (c == 'c') {
            int index;
            cin >> index;

            Load(index, programas[index], in);
        } else if (c == 'e') {

            Execute(in);
        } else if (c == 'm') {
            Show(in);
        } else if (c != 's') {
            cout << "Weird value. It was " << c << endl;
        }

    }
    Finalizar(in);

    for (int i = 0; i < cantidadProgramas; i++) {
        delete programas[i];
    }

    return 0;
}
