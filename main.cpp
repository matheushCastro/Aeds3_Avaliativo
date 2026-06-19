#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <chrono>
/* Matheus Henrique , Plinio Henrique, Marcos Roberto*/
using namespace std;
using namespace std::chrono;

#define TAMANHO_TABELA 100003
#define TOTAL_IPS 500000

typedef struct Node {
    char ip[16];
    int frequencia;
    struct Node* proximo;
} Node;

Node* tabela[TAMANHO_TABELA];

unsigned int funcao_hash(char* ip) {
    unsigned int hash = 2166136261u; // FNV offset basis
    for (int i = 0; ip[i] != '\0'; i++) {
        hash ^= (unsigned char)ip[i];
        hash *= 16777619u; // FNV prime
    }
    return hash % TAMANHO_TABELA;
}

void inserir(char* ip) {
    unsigned int indice = funcao_hash(ip);
    Node* atual = tabela[indice];

    while (atual != NULL) {
        if (strcmp(atual->ip, ip) == 0) {
            atual->frequencia++;
            return;
        }
        atual = atual->proximo;
    }

    Node* novo = (Node*)malloc(sizeof(Node));
    if (novo == NULL) {
        cout << "Erro: Falha na alocacao de memoria." << endl;
        exit(1);
    }
    strcpy(novo->ip, ip);
    novo->frequencia = 1;
    novo->proximo = tabela[indice];
    tabela[indice] = novo;
}

void imprimir_estatisticas(double tempo_ms) {
    int ips_unicos = 0;
    int posicoes_vazias = 0;
    int maior_lista = 0;

    for (int i = 0; i < TAMANHO_TABELA; i++) {
        int comprimento = 0;
        Node* atual = tabela[i];

        if (atual == NULL) posicoes_vazias++;

        while (atual != NULL) {
            comprimento++;
            ips_unicos++;
            atual = atual->proximo;
        }

        if (comprimento > maior_lista) maior_lista = comprimento;
    }

    double fator_carga = (double)ips_unicos / (double)TAMANHO_TABELA;

    cout << "\n===== Estatisticas da Tabela Hash (otimizada) =====" << endl;
    cout << "Tamanho da tabela (m):        " << TAMANHO_TABELA << endl;
    cout << "Total de IPs unicos (n):      " << ips_unicos << endl;
    cout << "Fator de carga (alfa = n/m):  " << fator_carga << endl;
    cout << "Maior comprimento de lista:   " << maior_lista << endl;
    cout << "Posicoes vazias na tabela:    " << posicoes_vazias << endl;
    cout << "Tempo de execucao (insercao): " << tempo_ms << " ms" << endl;
    cout << "=====================================================" << endl;
}

void liberar_tabela() {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Node* atual = tabela[i];
        while (atual != NULL) {
            Node* proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
        tabela[i] = NULL;
    }
}

void gerar_ip(char* buffer) {
    int b3 = (rand() % 254) + 1;
    int b4 = (rand() % 254) + 1;
    sprintf(buffer, "192.168.%d.%d", b3, b4);
}

int main() {
    srand((unsigned int)time(NULL));

    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela[i] = NULL;
    }

    char ip[16];

    auto inicio = high_resolution_clock::now();

    for (int i = 0; i < TOTAL_IPS; i++) {
        gerar_ip(ip);
        inserir(ip);
    }

    auto fim = high_resolution_clock::now();
    double tempo_ms = duration<double, milli>(fim - inicio).count();

    cout << "Total de registros processados: " << TOTAL_IPS << endl;
    imprimir_estatisticas(tempo_ms);

    liberar_tabela();

    return 0;
}