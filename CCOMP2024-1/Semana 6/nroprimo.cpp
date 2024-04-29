#include <iostream>
using namespace std;

bool esPrimo(int n) {
    if( n % 2 == 0 || n == 0 || n == 1) return false;
    for(int i = 2; i <= n/2; i++){
        if( n % i == 0){
            return false;
        }
    }
    return true;
}

/*
* Implemente una función que reciba un entero n e imprima
* los n primeros nros primos.
*/
void printNPrimos(int n) {
    /*
    contador = 1
    MIENTRAS contador < n
        SI contador es primo
            imprime contador    
            contador = contador + 1        
    */

    int counter = 0, tmp = 2;
    while(counter <= n){
        if(esPrimo(tmp)){
            cout<< tmp<<" ";
            counter++;
        }
        tmp++;
    }

}

int main(){

    long long numero;
    bool noEsPrimo = false;

    cout<<"Introduce el numero: ";cin>>numero;

    if( esPrimo(numero) ) {
        cout << numero << " ES PRIMO" << endl;
    }else{
        cout << numero << " NO ES PRIMO" << endl;
    }

    return 0;
    }