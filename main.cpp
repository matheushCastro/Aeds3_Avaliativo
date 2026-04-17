#include <iostream>
using namespace std;
/*Matheus Henrique, Marcos Roberto ,Plinio Henrique*/
void ordenarInsercao(int vetor[], int tamanho) {
    int i = 0;

    while (i < tamanho) {

        if (i == tamanho - 1) {
            int valorAtual = vetor[i];
            int j = i - 1;

            while (j >= 0 && vetor[j] > valorAtual) {
                vetor[j + 1] = vetor[j];
                j--;
            }

            vetor[j + 1] = valorAtual;
            break;
        }

        
        int primeiro = vetor[i];
        int segundo = vetor[i + 1];

        cout << "Par analisado: " << primeiro << " e " << segundo << endl;

        
        int menor, maior;

        if (primeiro <= segundo) {
            menor = primeiro;
            maior = segundo;
        } else {
            menor = segundo;
            maior = primeiro;
        }

        int j = i - 1;
        while (j >= 0 && vetor[j] > menor) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = menor;

        
        j = i;
        while (j >= 0 && vetor[j] > maior) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = maior;

        i += 2;
    }
}

int main() {
    int vetor[] = {7, 2, 5, 4, 9, 1,2};

    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    ordenarInsercao(vetor, tamanho);

    cout << "Vetor ordenado: ";

    for (int i = 0; i < tamanho; i++) {
        cout << vetor[i] << " ";
    }

    cout << endl;

    return 0;
}
