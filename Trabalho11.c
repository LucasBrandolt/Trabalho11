#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"
//Cria o vetor ordenado usando os parametros o tamanho
VETORORD* VETORD_create(int n, COMP* compara){
    VETORORD* vetorord = malloc(sizeof(VETORORD));      //Faz a alocação de memoria necessaria para o vetor
    vetorord->comparador = compara;                     //Define o comparador
    vetorord->N = n;                                    //Define o N
    vetorord->P = 0;                                    //Define o P
    vetorord->elems = malloc(n * sizeof(void *));       //Aloca memoria para o vetor
    for(int i = 0;i<n;i++){
        vetorord->elems[i] = NULL;                      //Define todos as posições como NULL
    }
    return vetorord;                                    //retorna o ponteiro vetorord
}
//Função para adicionar um elemento no vetor ordenado
void VETORD_add(VETORORD* vetor, void* newelem){
    if (vetor->P < vetor->N) {                                              //faz a verificação para saber se tem espaço no vetor
        if (vetor->P == 0) {
            vetor->elems[0] = newelem;                                      //adiciona um novo elemento no vetor
        }
        else if (                                                           //Compara o novo elemento com os elementos presentes no vetor e se pode ser adicionado no final
                vetor->comparador(newelem, vetor->elems[vetor->P-1]) == -1 ||
                vetor->comparador(newelem, vetor->elems[vetor->P-1]) == 0
        ) {
            vetor->elems[vetor->P] = newelem;                               
        }else {
            for (int i = vetor->P-1; i > -1; i--) {                         //Serve para caminhar pelos elementos do vetor
                if (vetor->comparador(newelem, vetor->elems[i]) == 1) {     //Define em qual posição o for vai parar para entrar o novo elemento
                    vetor->elems[i+1] = vetor->elems[i];
                    vetor->elems[i] = newelem;                              
                }
                else break;
            }
        }
        vetor->P++;
    }
}
//Função de remover no vetor ordenado
void* VETORD_remove(VETORORD* vetor){
    void* aux = vetor->elems[0];                    //define um auxiliar para fazer a remoção
    for(int i = 0;i<vetor->P;i++){                  //Caminha pelos elementos do vetor
        vetor->elems[i] = vetor->elems[i+1];        //faz o deslocamento de todos os elementos
    }
    vetor->P--;
    return aux;                                     //retorna o valor de AUX
}
