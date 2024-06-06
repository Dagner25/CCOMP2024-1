#include <iostream>
#include "Persona.h"
using namespace std;

int main() {
    Persona* arr = new Persona[10]{
        {"Juan", 20}, {"Ana", 25}, {"Luis", 22}, {"Maria", 30}, {"Pedro", 28},
        {"Lucia", 24}, {"Carlos", 26}, {"Elena", 27}, {"Alvaro", 23}, {"Sofia", 29}
    };

    Persona* ptr = arr;
    cout << "Impresión desde el último hasta el primero:" << endl;
    for (int i = 9; i >= 0; --i) {
        ptr[i].print();
    }

    cout << "Impresión de elementos con índice impar:" <<endl;
    for (int i = 1; i < 10; i += 2) {
        ptr[i].print();
    }

    std::cout << "Arreglo ordenado por edad:" <<endl;
    ordenarPorEdad(arr, 10);
    imprimirArreglo(arr, 10);

    cout << "Arreglo ordenado por nombre:" <<endl;
    ordenarPorNombre(arr, 10);
    imprimirArreglo(arr, 10);

    delete[] arr;
    return 0;
}