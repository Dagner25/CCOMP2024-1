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

// Función para resolver el problema de las ocho reinas
bool resolverOchoReinasUtil(vector<vector<int>>& tablero, int columna) {
    // Si todas las reinas están colocadas, retornar verdadero
    if (columna >= N) return true;
    // Intentar colocar una reina en cada fila de la columna actual
    for (int i = 0; i < N; ++i) {
        if (esSeguro(tablero, i, columna)) {
            tablero[i][columna] = 1; // Colocar una reina en la posición (i, columna)
            // Recursivamente intentar colocar reinas en las columnas restantes
            if (resolverOchoReinasUtil(tablero, columna + 1)) return true;
            // Si no es posible colocar una reina en esta fila, retroceder
            tablero[i][columna] = 0;
        }
    }
    // Si no es posible colocar una reina en ninguna fila de esta columna, retornar falso
    return false;
}

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



