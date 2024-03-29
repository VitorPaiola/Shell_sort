#include <iostream>
#include <stdlib.h>
#include <string>
#define TAM 10

using namespace std;

void imprimeVetor(int vetor[]) {
    int i;
    cout << "\n";
    for (i = 0; i < TAM; i++) {
        cout << " |" << vetor[i] << "| ";
    }
}

static void shell_sort(int vetor[TAM]) {

    int i, j, atual;
    int h = 1;

    // De quanto em quanto ser� o pulo entre an�lises
    while (h < TAM) {
        h = 3 * h + 1;
    }

    while (h > 1) {

        // Reduz a dist�ncia entre as an�lises
        h = h / 3;

        for (i = h; i < TAM; i++) {

            // Elemento atual em an�lise
            atual = vetor[i];

            // Elemento anterior ao analisado
            j = i - h;

            while ((j >= 0) && (atual < vetor[j])) {

                // Posiciona os elementos uma posi��o para frente
                vetor[j + h] = vetor[j];

                // Faz o j andar para tr�s
                j = j - h;

            }

            // Agora que o espa�o foi aberto, colocamos o atual (Menor n�mero) na posi��o correta
            vetor[j + h] = atual;

            imprimeVetor(vetor);

        }

    }

}

int main() {

    int vetor[TAM] = { 10,9,8,7,6,5,4,3,2,1 };

    shell_sort(vetor);

    imprimeVetor(vetor);

    return 0;
}