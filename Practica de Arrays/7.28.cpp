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
#include <cctype> 

bool testPalindrome(const std::string& str, int start, int end) {
    if (start >= end) {
        return true;
    }
    while (!std::isalnum(str[start])) {
        start++;
    }
    while (!std::isalnum(str[end])) {
        end--;
    }
    if (std::tolower(str[start]) != std::tolower(str[end])) {
        return false;
    }
    return testPalindrome(str, start + 1, end - 1);
}

bool isPalindrome(const std::string& str) {
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
