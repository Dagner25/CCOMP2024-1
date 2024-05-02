/*Otro enigma para los aficionados al ajedrez es el problema de las ocho reinas. Indicado simplemente:
¿Es posible colocar ocho reinas en un tablero de ajedrez vacío de modo que ninguna reina “ataque” a otra,
 es decir, que no haya dos reinas en la misma fila, en la misma columna o en la misma diagonal? Utilice el
  pensamiento desarrollado en el ejercicio 7.22 para formular una heurística para resolver el problema de 
  las ocho reinas. Ejecute su programa. [Pista: Es posible asignar un valor a cada casilla del tablero indicando
   cuántas casillas de un tablero vacío se “eliminan” si se coloca una reina en esa casilla. A cada una de las esquinas 
   se le asignaría el valor 22, como en la figura 7.26. Una vez que estos “números de eliminación” se colocan en las 64 
   casillas, una heurística adecuada podría ser: colocar la siguiente reina en la casilla con el número de eliminación más pequeño
   . ¿Por qué esta estrategia es intuitivamente atractiva?]
*/
#include <iostream>
#include <vector>
#include <cmath>

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
    for (int i = fila, j = columna; i >= 0 && j >= 0; --i, --j) {   //verifica las diagonales
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
            if (resolverOchoReinasUtil(tablero, columna + 1)) return true;
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



