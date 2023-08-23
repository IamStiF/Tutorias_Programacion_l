#include "Array.h"
#include <cstdlib> // Necesario para la función rand()
#include <ctime>   // Necesario para inicializar la semilla de los números aleatorios
#include <iostream>

using namespace std;

int main() {
    int n = 5;
    int m = 3;

    // Inicializar la semilla de los números aleatorios
    srand(time(nullptr));

    Array* miArray = new Array(n, m);

    // Generar números aleatorios para array1
    for (int i = 0; i < n; ++i) {
        miArray->setArray1Value(i, rand() % 100);  // Genera un número aleatorio entre 0 y 99
    }

    // Generar números aleatorios para array2
    for (int i = 0; i < m; ++i) {
        miArray->setArray2Value(i, rand() % 100);  // Genera un número aleatorio entre 0 y 99
    }

    cout << "Arrays antes de ordenar:" << endl;
    cout << miArray->toString() << endl << endl;

    miArray->ordenarArrays();

    cout << "Arrays ordenados:" << endl;
    cout << miArray->toString() << endl;

    delete miArray; // Liberar memoria asignada

    return 0;
}