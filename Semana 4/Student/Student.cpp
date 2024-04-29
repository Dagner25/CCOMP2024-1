#include "Student.h"
#include <iostream>
#include <string>

int main() {
  std::string name1, name2;
  int age1, age2;

  std::cout << "Ingrese el nombre del primer estudiante: ";
  getline(std::cin, name1);
  std::cout << "Ingrese la edad del primer estudiante: ";
  std::cin >> age1;
  std::cout << std::endl;

  Student student1(name1, age1);

  std::cout << std::endl;

  std::cout << "Ingrese el nombre del segundo estudiante: ";
  getline(std::cin, name2);
  std::cout << std::endl;
  std::cout << "Ingrese la edad del segundo estudiante: ";
  std::cin >> age2;

  Student student2(name2, age2);

  std::cout << "\nDatos del primer estudiante:" << std::endl;
  std::cout << "Nombre: " << student1.getName() << std::endl;
  std::cout << "Edad: " << student1.getAge() << std::endl;
  if (student1.isOlder()) {
    std::cout << "Es mayor de edad." << std::endl;
  } else {
    std::cout << "No es mayor de edad." << std::endl;
  }

  std::cout << "\nDatos del segundo estudiante:" << std::endl;
  std::cout << "Nombre: " << student2.getName() << std::endl;
  std::cout << "Edad: " << student2.getAge() << std::endl;

  if (student2.isOlder()) {
    std::cout << "Es mayor de edad." << std::endl;
  } else {
    std::cout << "No es mayor de edad." << std::endl;
  }

  return 0;
}