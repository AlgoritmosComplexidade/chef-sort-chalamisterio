#include <stdio.h>
#include <string.h>

// Definição da struct
typedef struct {
    int id;
    char nome[30];
} Prato;

// Função recursiva para inserir o último elemento na parte ordenada
void inserirOrdenado(Prato v[], int n) {
    // Caso base: se o vetor tem apenas 1 elemento ou o elemento anterior é menor/igual
    if (n <= 0) return;

    Prato ultimo = v[n];
    int j = n - 1;

    // Move os elementos que são maiores que o 'ultimo' para uma posição à frente
    if (j >= 0 && v[j].id > ultimo.id) {
        v[j + 1] = v[j];
        v[j] = ultimo; // Troca temporária para continuar a recursão de inserção
        inserirOrdenado(v, n - 1);
    }
}

// Função principal do Insertion Sort Recursivo
void insertionSortRecursivo(Prato v[], int n) {
    // Caso base: vetor com 1 elemento já está ordenado
    if (n <= 1) return;

    // Ordena os primeiros n-1 elementos
    insertionSortRecursivo(v, n - 1);

    // Insere o último elemento na sua posição correta no segmento já ordenado
    Prato ultimo = v[n - 1];
    int j = n - 2;

    while (j >= 0 && v[j].id > ultimo.id) {
        v[j + 1] = v[j];
        j--;
    }
    v[j + 1] = ultimo;
}

void imprimirPratos(Prato v[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("ID: %d | Prato: %s\n", v[i].id, v[i].nome);
    }
}

int main() {
    // Preenchendo a struct com 5 pratos desordenados
    Prato cardapio[5] = {
        {45, "Lasanha"},
        {12, "Sopa de Cebola"},
        {88, "Pudim"},
        {23, "Risoto"},
        {5,  "Salada Caesar"}
    };

    printf("--- Cardápio Original ---\n");
    imprimirPratos(cardapio, 5);

    // Chamada do algoritmo
    insertionSortRecursivo(cardapio, 5);

    printf("\n--- Cardápio Ordenado (ID) ---\n");
    imprimirPratos(cardapio, 5);

    return 0;
                                                                                                                                                                                                                            
}
