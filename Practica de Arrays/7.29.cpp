/*
(Ocho reinas) Modifique el programa Ocho reinas que creó en el ejercicio 7.24 para
 resolver el problema de forma recursiva.
*/
#include <iostream>
#include <vector>

using namespace std;

const int N = 8; // Tamaño del tablero de ajedrez

// Función para imprimir el tablero
void imprimirTablero(const vector<vector<int>>& tablero) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}

// Función para verificar si es seguro colocar una reina en la posición (fila, columna)
bool esSeguro(const vector<vector<int>>& tablero, int fila, int columna) {
    // Verificar fila y columna
    for (int i = 0; i < N; ++i) {
        if (tablero[i][columna] == 1 || tablero[fila][i] == 1) return false;
    }
    // Verificar diagonales
    for (int i = fila, j = columna; i >= 0 && j >= 0; --i, --j) {
        if (tablero[i][j] == 1) return false;
    }
    for (int i = fila, j = columna; i < N && j < N; ++i, ++j) {
        if (tablero[i][j] == 1) return false;
    }
    for (int i = fila, j = columna; i >= 0 && j < N; --i, ++j) {
        if (tablero[i][j] == 1) return false;
    }
    for (int i = fila, j = columna; i < N && j >= 0; ++i, --j) {
        if (tablero[i][j] == 1) return false;
    }
    return true;
}

// Función recursiva para resolver el problema de las ocho reinas
bool resolverOchoReinasUtil(vector<vector<int>>& tablero, int columna) {
    // Caso base: si todas las reinas están colocadas, retornar verdadero
    if (columna >= N) return true;

    // Intentar colocar una reina en cada fila de la columna actual
    for (int i = 0; i < N; ++i) {
        // Verificar si es seguro colocar una reina en la posición (i, columna)
        if (esSeguro(tablero, i, columna)) {
            // Colocar una reina en la posición (i, columna)
            tablero[i][columna] = 1;

            // Llamada recursiva para colocar reinas en las columnas restantes
            if (resolverOchoReinasUtil(tablero, columna + 1)) {
                return true; // Si se encontró una solución, retornar verdadero
            }

            // Si no se encuentra una solución con esta posición, retroceder
            tablero[i][columna] = 0;
        }
    }

    // Si no es posible colocar una reina en ninguna fila de esta columna, retornar falso
    return false;
}

// Función principal para resolver el problema de las ocho reinas
void resolverOchoReinas() {
    vector<vector<int>> tablero(N, vector<int>(N, 0)); // Inicializar el tablero con ceros

    // Llamar a la función utilitaria para resolver el problema
    if (resolverOchoReinasUtil(tablero, 0)) {
        // Imprimir el tablero si se encontró una solución
        imprimirTablero(tablero);
    } else {
        cout << "No hay solución posible." << endl;
    }
}

int main() {
    resolverOchoReinas();
    return 0;
}
