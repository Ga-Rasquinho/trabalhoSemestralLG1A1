/* Bibliotecas */ 
#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include <string.h>

/* Struct para leitura dos registros */
typedef struct {
    int codCartao;
    char numeroCartaoStruct[16];
}
cartaoNumeroDat;

/* Variáveis globais */
cartaoNumeroDat reg;
FILE * Arq; /* Variável de leitura */

int opc, j;
char select;
float total, quantidade, contapreco = 0;
/* Corpo do programa */
int main() {

    system("cls");
    system("mode 40,25");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("\n%c	       CART%cES 		    %c", 186, 229, 186);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
    /* Abrir o arquivo .DAT */
    Arq = fopen("CARTOES.DAT", "r+b");
    if (Arq == NULL) {
        printf("\nErro ao abrir CARTOES.DAT");
        getch();
        exit(0);
    }
    /* Looping de leitura e exibição em tela */
    while (!feof(Arq)) {
        /* lê dados do arquivo */
        fread( & reg, sizeof(reg), 1, Arq);
        if (!feof(Arq)) {
            /* mostra os dados lidos na tela */

            printf("\n%cC%cdigo:%3i N%cmero: %-15s%c", 186, 162, reg.codCartao, 163, reg.numeroCartaoStruct, 186);
        }
    }
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);

    /* Fecha o arquivo*/
    fclose(Arq);
    /* Aguarda o pressionar de qualquer tecla*/
    getch();
    return 0;
}
