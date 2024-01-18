#include <iostream>
#include <cstdlib>

using namespace std;

const int MAX_NUMBERS = 50;

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j) {
        quickSort(arr, left, j);
    }
    if (i < right) {
        quickSort(arr, i, right);
    }
}

int main() {
    int n;
    int arr[MAX_NUMBERS];

    cout << "Determine el tamanio del arreglo: ";
    cin >> n;

    if (n < 1 || n > 50) {
        cout << "Valores no permitidos" << endl;
        return 0;
    }

    cout << "Ingresa los datos separados: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Números ordenados: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}