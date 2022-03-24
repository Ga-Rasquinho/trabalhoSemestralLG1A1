/* Bibliotecas */ 
#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include <string.h>

/* Struct para leitura dos registros */
typedef struct {
    int codpagamento;
    char formaPagamento[10];
    float valorPagamento;
}
dadosPagamento;

/* Variáveis globais */
dadosPagamento reg;
FILE * Arq; /* Variável de leitura */

int opc, j;
char select;
float total, quantidade, contapreco = 0;
/* Corpo do programa */
int main() {

    system("cls");
    system("mode 63, 30");
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("\n%c	    	      PAGAMENTOS 	   	    	    %c", 186, 186);
    printf("\n%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    /* Abrir o arquivo .DAT */
    Arq = fopen("PAGAMENTOS.DAT", "r+b");
    if (Arq == NULL) {
        printf("\nErro ao abrir PAGAMENTOS.DAT");
        getch();
        exit(0);
    }
    /* Looping de leitura e exibição em tela */
    while (!feof(Arq)) {
        /* lê dados do arquivo */
        fread( & reg, sizeof(reg), 1, Arq);
        if (!feof(Arq)) {
            /* mostra os dados lidos na tela */

            printf("\n C%cdigo:%i | Forma de pagamento: %-10s | Valor: R$ %.02f", 162, reg.codpagamento, reg.formaPagamento, reg.valorPagamento);
        }
    }

    /* Fecha o arquivo*/
    fclose(Arq);
    /* Aguarda o pressionar de qualquer tecla*/
    getch();
    return 0;
}
