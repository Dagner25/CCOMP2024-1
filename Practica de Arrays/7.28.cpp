/*(Oraciones palindrómicas) Un palíndromo es una cuerda que se escribe de la misma manera hacia adelante y hacia atrás.
Ejemplos de palíndromos incluyen "radar" y "Podía antes de ver a Elba". Una oración palindrómica es un palíndromo si se 
ignoran los signos de puntuación y los espacios. Escribe una función recursiva testPalindrome que devuelve verdadero si una 
cadena es un palíndromo y falso en caso contrario. Ignora todos los espacios, comas, puntos y signos de interrogación en 
la oración. De ahí que “las rosas rojas no corren ningún riesgo, señor, por orden de las enfermeras”. Se considera un palíndromo.
Tenga en cuenta que, al igual que una matriz, el operador de corchetes ([]) se puede utilizar para recorrer los 
caracteres de una cadena.
*/

#include <iostream>
#include <string>
#include <cctype> // Para usar la función std::isalnum

bool testPalindrome(const std::string& str, int start, int end) {
    // Caso base: si el índice de inicio supera al de fin, la cadena es un palíndromo
    if (start >= end) {
        return true;
    }
    
    // Ignoramos los signos de puntuación y los espacios
    while (!std::isalnum(str[start])) {
        start++;
    }
    while (!std::isalnum(str[end])) {
        end--;
    }
    
    // Si los caracteres en los índices start y end son diferentes, no es un palíndromo
    if (std::tolower(str[start]) != std::tolower(str[end])) {
        return false;
    }
    
    // Llamada recursiva con los índices ajustados
    return testPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(const std::string& str) {
    // Llamada inicial a la función recursiva
    return testPalindrome(str, 0, str.length() - 1);
}

int main() {
    std::string sentence = "Somos o no somos";
    if (isPalindrome(sentence)) {
        std::cout << "La oración es palindromo." << std::endl;
    } else {
        std::cout << "La oración no palíndromo." << std::endl;
    }
    return 0;
}
