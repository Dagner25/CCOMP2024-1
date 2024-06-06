#include <string>

class Persona {
protected:
    std::string nombre;
    int edad;

public:
    Persona(std::string n, int e) : nombre(n), edad(e) {}

    std::string getNombre() const { return nombre; }
    void setNombre(std::string n) { nombre = n; }
    int getEdad() const { return edad; }
    void setEdad(int e) { edad = e; }

    void print() const {
        std::cout << "Nombre: " << nombre << ", Edad: " << edad << std::endl;
    }
};

void imprimirArreglo(Persona* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i].print();
    }
}

void ordenarPorEdad(Persona* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j].getEdad() > arr[j + 1].getEdad()) {
                Persona temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void ordenarPorNombre(Persona* arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j].getNombre() > arr[j + 1].getNombre()) {
                Persona temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
