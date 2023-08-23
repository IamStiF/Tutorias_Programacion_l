#include "Array.h"

Array::Array(int n, int m):tamN(n),tamM(m)
{
	array1 = new int[tamN];
	array2 = new int[tamM];
}

Array::~Array()
{
	delete[] array1;
	delete[] array2;
}

void Array::orderBurbuja(int* arr, int size)
{
    for (int i = 0; i < size - 1; ++i) {

        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }

    }
}

void Array::ordenarArrays()
{
    orderBurbuja(array1, tamN);

    int pos = 0;
    bool flag = false;
    int aux = 0;

    for (int i = 0; i < tamN; i++) {
        aux = array1[i];

        for (int j = 0; j < tamM; j++) {

            if(array1[i] >= array2[j] && aux >= array2[j]) {
                aux = array2[j];
                pos = j;
                flag = true;
            }

        }

        if(flag) {
            aux = array2[pos];
            array2[pos] = array1[i];
            array1[i] = aux;
            flag = false;
        }

    }

    orderBurbuja(array2, tamM);

}

void Array::setArray1Value(int index, int value) {
    if (index >= 0 && index < tamN) {
        array1[index] = value;
    }
}

void Array::setArray2Value(int index, int value) {
    if (index >= 0 && index < tamM) {
        array2[index] = value;
    }
}

string Array::toString()
{
    stringstream s;

    s << "Array1 y Array2: ";
    for (int i = 0; i < tamN; ++i) {
        s << array1[i] << " ";
    }
    s << " - ";
    for (int i = 0; i < tamM; ++i) {
        s << array2[i] << " ";
    }

    return s.str();
}
