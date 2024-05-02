/*
(Ocho reinas) Modifique el programa Ocho reinas que creó en el ejercicio 7.24 para
 resolver el problema de forma recursiva.
*/
#include <iostream>
#include <vector>

using namespace std;

const int N = 8; 
void imprimirTablero(const vector<vector<int>>& tablero) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}

bool esSeguro(const vector<vector<int>>& tablero, int fila, int columna) {
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

bool resolverOchoReinasUtil(vector<vector<int>>& tablero, int columna) {
    if (columna >= N) return true;
    for (int i = 0; i < N; ++i) {
        if (esSeguro(tablero, i, columna)) {
            tablero[i][columna] = 1;

            if (resolverOchoReinasUtil(tablero, columna + 1)) {
                return true;
            }
            tablero[i][columna] = 0;
        }
    }
    return false;
}
void resolverOchoReinas() {
    vector<vector<int>> tablero(N, vector<int>(N, 0)); 
    if (resolverOchoReinasUtil(tablero, 0)) {
        imprimirTablero(tablero);
    } else {
        cout << "No hay solución posible." << endl;
    }
}

int main() {
    resolverOchoReinas();
    return 0;
}
