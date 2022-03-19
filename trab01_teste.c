#include <stdio.h>
#include <string.h>

#define Linha 5
#define Coluna 15

char sortea_palavra(char banco[Linha][Coluna],*c) {
    char palavra_sorteada[Coluna];
    int i=0;
    int sorteado=0;
    srand(time(NULL));
    sorteado= rand() % 5;

    for(i=0;i<Coluna;i++){
        palavra_sorteada[i] = banco[sorteado][i];
    }
    printf("teste funcao %s", palavra_sorteada);
    return palavra_sorteada;
}

void main () {
    int i=0;
    char sorteada[Coluna];
    char banco [Linha][Coluna] ={
        "zebra",
        "camaleao",
        "quarto",
        "ornitorinco",
        "pedregulho"};


    printf("Teste main %s",teste);
}
