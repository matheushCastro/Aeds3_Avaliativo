#include <iostream>
using namespace std;

void insertionSort(int v[], int n) {
    int i = 0;

    while (i < n) {

        if (i == n - 1) {
            int chave = v[i];
            int j = i - 1;

            while (j >= 0 && v[j] > chave) {
                v[j + 1] = v[j];
                j--;
            }
            v[j + 1] = chave;
            break;
        }

        int a = v[i];
        int b = v[i + 1];

        cout << "Par analisado: " << a << " e " << b << endl;

        // Garantir ordem: a <= b
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }

        // 🔹 Inserir primeiro o MENOR (a)
        int j = i - 1;
        while (j >= 0 && v[j] > a) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = a;


        j = i; // começa depois do a inserido
        while (j >= 0 && v[j] > b) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = b;

        i += 2;
    }
}

int main() {
    int v[] = {7, 2, 5, 4, 9, 1};
    int n = sizeof(v) / sizeof(v[0]);

    insertionSort(v, n);

    cout << "Vetor ordenado: ";
    for (int i = 0; i < n; i++) {
        cout << v[i] << " ";
    }

    return 0;
}
