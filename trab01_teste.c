#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Linha 5
#define Coluna 15
#define clrsrc() printf("\e[1;1H\e[2J");

void sortearPalavra(char palavras_candidatas[Linha][Coluna], char *p, int tam)
{
    int i = 0, sorteado = 0;
    char palavra_sorteada[Coluna];

    srand(time(NULL));
    sorteado = rand() % 5;

    for (i = 0; i < Coluna; i++)
    {
        palavra_sorteada[i] = palavras_candidatas[sorteado][i];
    }

    strncpy(p, palavra_sorteada, tam);
}

void esconderPalavra(char palavra[Coluna], char *p_escondida, size_t tam)
{
    int i = 0, len = 0;
    char palavra_escondida[Coluna] = {};

    len = strlen(palavra);
    for (i = 0; i < len; i++)
    {
        palavra_escondida[i] = '-';
    }

    strncpy(p_escondida, palavra_escondida, tam);
}

int chutarLetra(char sorteada[Coluna], char *p_escondida)
{
    int i = 0, len = 0, acerto = 0;
    char letra;

    printf("\n Chute: ");
    scanf("%c", &letra);

    len = strlen(sorteada);
    for (i = 0; i < len; i++)
    {
        if (letra == sorteada[i])
        {
            p_escondida[i] = letra;
            acerto = 1;
        }
    }

    return acerto;
}

void main()
{
    int i = 0, tentativas = 10, chute = 0;
    char sorteada[Coluna] = {}, escondida[Coluna] = {};
    char banco_de_palavras[Linha][Coluna] = {
        "zebra",
        "camaleao",
        "quarto",
        "ornitorinco",
        "pedregulho"};

    sortearPalavra(banco_de_palavras, sorteada, Coluna);
    esconderPalavra(sorteada, escondida, Coluna);

    clrsrc();
    // printf("\n -> %s ", sorteada);
    printf("\n -> %s ", escondida);

    while (i < tentativas)
    {
        printf("\n Voce tem %d tentativas", tentativas);

        chute = chutarLetra(sorteada, escondida);
        printf("Chute - %d", chute);
        if (chute)
        {
            printf("\n Acertou! \n %s", escondida);
        }
        else
        {
            printf("\n Errou!");
            tentativas--;
        }
    }
}
