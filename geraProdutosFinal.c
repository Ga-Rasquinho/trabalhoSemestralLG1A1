/* Bibliotecas */ 
#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include <string.h>

#include <locale.h>

/* Tipos de dados pr�-definidos */
typedef struct {
    int cod, prodCongelado;
    char descr[20];
    float custo;
}
registro;

/* Vari�veis globais */
registro reg;
FILE * Arq;
char opc;

/* Corpo do programa */
int main() {
    char resposta;
    setlocale(LC_ALL, "");
    do {
        system("cls");
        /* Captura dados do registro do produto */
        printf("\n\nDigite o c�digo do produto: ");
        fflush(stdin);
        scanf("%i", & reg.cod);
        printf("\nDigite a descri��o do produto: ");
        fflush(stdin);
        gets(reg.descr);
        printf("\nDigite o custo do produto: ");
        fflush(stdin);
        scanf("%f", & reg.custo);
        printf("\n� um produto congelado ? [S\\N] ");
        fflush(stdin);
        resposta = getche();
        if (resposta == 's' || resposta == 'S') {
            reg.prodCongelado = 1;
        } else {
            reg.prodCongelado = 0;
        }
        /* Grava o registro no arquivo .DAT */
        Arq = fopen("PRODUTOS.DAT", "a+b");
        if (Arq == NULL) {
            printf("\nErro ao abrir PRODUTOS.DAT");
            getch();
            exit(0);
        }
        fwrite( & reg, sizeof(reg), 1, Arq);
        fclose(Arq);
        /* Pergunta se quer gravar novo registro */
        printf("\nCadastra outro? [n/N = n�o]:");
        fflush(stdin);
        opc = getche();
    }
    while (opc != 'n' && opc != 'N');

    return 0;
}
