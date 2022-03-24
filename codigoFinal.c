/* Gabriel Fernandes Rasquinho 
   Prontuário: SP3084094
*/
/* Bibliotecas */ 
#include <stdio.h>

#include <stdlib.h>

#include <conio.h>

#include <string.h>

#include <windows.h>

#define N 3

/* Struct para leitura dos registros */
typedef struct {
    int cod, prodCongelado;
    char descr[20];
    float custo;
}
registro;

/* Início da struct para formas de pagamento */
typedef struct {
    int codpagamento;
    char formaPagamento[10];
    float valorPagamento;
}
dadosPagamento;

dadosPagamento data[N] = {
    {
        1,
        "Dinheiro"
    },
    {
        2,
        "Cheque"
    },
    {
        3,
        "Cartao",
    }
};

/*dadosPagamento pagDinheiro[1] = {
	{1, "Dinheiro"}
};*/
dadosPagamento pagDinheiro = {
    1,
    "Dinheiro"
};
dadosPagamento pagCheque = {
    2,
    "Cheque"
};
dadosPagamento pagCartao = {
    3,
    "Cartao"
};

typedef struct {
    int codCartao;
    char numeroCartaoStruct[16];
}
cartaoNumeroDat;

cartaoNumeroDat cart[1] = {
    {
        3,
        ""
    }
};
/* Fim da struct para formas de pagamentos */

/* Protótipos das funções */
int menu(void);
int verificar(int contadorMenu);
void opcao(int opc);
void formasPagamento(void);
int selecionePagamento(void);
int cartao(int opcFormaPagamento);
void adicionarAsterisco(int i);
void fila(int opc);

FILE * Arq; /* Variável de leitura do menu */
FILE * cartaoArq; /* Variável para abrir o CARTAO.DAT*/
FILE * pagamentoArq; /* Variável para abrir o PAGAMENTOS.DAT*/

registro vet[15]; /* Vetor para armazenar os dados */

/* Variáveis globais */
registro reg;
char selecao; /* Váriavel para saber se o usuário deseja repetir a ação */
float total, quantidade, contapreco;
int contadorMenu, j, opc, contadorFormaPagamento, opcFormaPagamento;
/* Corpo do programa principal */
int main() {
    do {
        /* Essas variáveis precisam ser resetadas para não repetir uma opção do menu */
        contadorMenu = 0;
        opc = 0;
        j = 0;

        menu();
        verificar(contadorMenu);
        opcao(opc);
        contapreco += total;

        printf("\nTotal a pagar: R$ %.02f", contapreco);

        printf("\n\nDeseja escolher mais alguma coisa?(S/N) ");
        fflush(stdin);
        selecao = getche();
    } while (selecao != 'n' && selecao != 'N');

    fila(opc);
    formasPagamento();
    selecionePagamento();
    cartao(opcFormaPagamento);

    getch();
    return 0;
}

int menu(void) {
    system("cls");
    system("mode 50,30");
    printf("    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("\n    %c\t           MENU               %c", 186, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
    printf("\n    %cC%cdigo     Descri%c%co    Valor(R$)%c", 186, 162, 135, 198, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
    /* Abrir o arquivo .DAT */
    Arq = fopen("PRODUTOS.DAT", "r+b");
    if (Arq == NULL) {
        printf("\nErro ao abrir PRODUTOS.DAT");
        getch();
        exit(0);
    }
    /* Looping de leitura e exibição em tela */
    while (!feof(Arq)) {
        /* lê dados do arquivo */
        fread( & reg, sizeof(reg), 1, Arq);
        if (!feof(Arq)) {
            /* mostra os dados lidos na tela */
            vet[contadorMenu] = reg;
            contadorMenu++;
            printf("\n    %c%3i      %-16sR$ %.2f %c", 186, reg.cod, reg.descr, reg.custo, 186);
        }
    }
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    /* Fecha o arquivo*/
    fclose(Arq);
    return contadorMenu;
}

/* Verifica se o usuário digitou apenas números */
int verificar(int contadorMenu) {
    printf("\nSelecione uma op%c%co: ", 135, 198);
    fflush(stdin);
    scanf("%i", & opc);
    while (opc < 1) {
        printf("\nOp%c%co inv%clida, digite novamente: ", 135, 198, 160);
        fflush(stdin);
        scanf("%i", & opc);
    }
    return opc;
}
/* Essa função percorre o vetor para comparar o valor digitado com o código do produto */
void opcao(int opc) {

    for (j = 0; j < contadorMenu; j++) {
        if (vet[j].cod == opc) {
            printf("\nVoc%c selecionou: %s, custo: R$ %.02f", 136, vet[j].descr, vet[j].custo);
            printf("\n\nDigite a quantidade desejada: ");
            fflush(stdin);
            scanf("%f", & quantidade);
            total = vet[j].custo * quantidade;
        }
    }
}

/* Função para percorrer o vetor da struct de dadosPagamento */
void formasPagamento(void) {

    system("cls");
    system("mode 51,12");
    printf("         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("\n         %c    FORMAS DE PAGAMENTO    %c", 186, 186);
    printf("\n         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
    /* For que percorre o vetor */
    for (contadorFormaPagamento = 0; contadorFormaPagamento < N; contadorFormaPagamento++) {
        printf("\n         %c %i   -   %-18s%c", 186, data[contadorFormaPagamento].codpagamento, data[contadorFormaPagamento].formaPagamento, 186);
    }
    printf("\n         %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
}

/* Função para selecionar forma de pagamento */
int selecionePagamento(void) {
    /* Variáveis locais*/
    int selecPagamentoCont;
    pagamentoArq = fopen("PAGAMENTOS.DAT", "a+b");
    if (pagamentoArq == NULL) {
        printf("\nErro ao gravar no arquivo PAGAMENTOS.DAT");
        getch();
        exit(0);
    }
    /* Captura de dados */
    printf("\n\nSelecione uma forma de pagamento: ");
    fflush(stdin);
    scanf("%i", & opcFormaPagamento);

    if (pagDinheiro.codpagamento == opcFormaPagamento) {
        system("cls");
        system("mode 80,8");
        system("color 02");
        printf("	  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        printf("\n	  %cVoc%c selecionou: %s", 186, 136, pagDinheiro.formaPagamento);
        pagDinheiro.valorPagamento = contapreco;
        printf(" | Valor da compra: R$ %.02f %c", pagDinheiro.valorPagamento, 186);
        fwrite( & pagDinheiro, sizeof(pagDinheiro), 1, pagamentoArq);
        printf("\n	  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
        Sleep(1300);
        printf("\n\n 	     ---OBRIGADO POR COMPRAR NO MICKEY & DONALD---");
        Sleep(1300);
        printf("\n\nProssiga para o pr%cximo caixa para realizar o pagamento e retirar o seu pedido.", 162);
    }
    if (pagCheque.codpagamento == opcFormaPagamento) {
        system("cls");
        system("mode 80,8");
        system("color 01");
        printf("	  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        printf("\n	  %c  Voc%c selecionou: %s", 186, 136, pagCheque.formaPagamento);
        pagCheque.valorPagamento = contapreco;
        printf("| Valor da compra: R$ %.02f  %c", pagCheque.valorPagamento, 186);
        fwrite( & pagCheque, sizeof(pagCheque), 1, pagamentoArq);
        printf("\n	  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
        Sleep(1300);
        printf("\n\n 	     ---OBRIGADO POR COMPRAR NO MICKEY & DONALD---");
        Sleep(1300);
        printf("\n\nProssiga para o pr%cximo caixa para realizar o pagamento e retirar o seu pedido.", 162);
    }
    if (pagCartao.codpagamento == opcFormaPagamento) {
        system("cls");
        system("mode 80,20");
        system("color 0D");
        printf(" 	     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
        printf("\n 	     %cVoc%c selecionou: %s", 186, 136, pagCartao.formaPagamento);
        pagCartao.valorPagamento = contapreco;
        printf(" | Valor da compra: R$ %.02f  %c", pagCartao.valorPagamento, 186);
        fwrite( & pagCartao, sizeof(pagCartao), 1, pagamentoArq);
        printf("\n 	     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    }

    fclose(pagamentoArq);
    return opcFormaPagamento;
}

int cartao(int opcFormaPagamento) {
    /* Variável local */
    int tamanho, i;
    char numeroCartao[16];

    cartaoArq = fopen("CARTOES.DAT", "a+b");
    if (cartaoArq == NULL) {
        printf("\nErro ao gravar no arquivo CARTOES.DAT");
        getch();
        exit(0);
    }
    if (opcFormaPagamento == 3) {
        for (i = 0; i < 1; i++) {
            printf("\n\nDigite o n%cmero do cart%co: ", 163, 198);
            fflush(stdin);
            gets(cart[i].numeroCartaoStruct);
            tamanho = strlen(cart[i].numeroCartaoStruct);

            if (tamanho == 16) {
                adicionarAsterisco(i);
            }
            /* Looping caso o usuário digite um cartão inválido */
            while (tamanho != 16) {
                printf("\nCart%co inv%clido, digite novamente: ", 198, 160);
                fflush(stdin);
                gets(cart[i].numeroCartaoStruct);
                tamanho = strlen(cart[i].numeroCartaoStruct);
                 adicionarAsterisco(i);
            }
        }
        fwrite( & cart, sizeof(cart), 1, cartaoArq);
        fclose(cartaoArq);
        printf("\nPagamento realizado com sucesso!");
        Sleep(1300);
        printf("\n\n 	     ---OBRIGADO POR COMPRAR NO MICKEY & DONALD---");
        Sleep(1300);
        printf("\n\n\nRetire seu pedido no pr%cximo caixa.", 162);
    }
    return i;
}
/* Adiciona asterisco no CARTAO.DAT */
void adicionarAsterisco(int i) {
    int contaTamanho1, asterisco, contaTamanho2;
    for (contaTamanho1 = 0; contaTamanho1 < 4 && cart[i].numeroCartaoStruct[contaTamanho1] != '\0'; contaTamanho1++) {

    }
    for (asterisco = 4; asterisco < 12 && cart[i].numeroCartaoStruct[asterisco] != '\0'; asterisco++) {
        cart[i].numeroCartaoStruct[asterisco] = ('*');
    }
    for (contaTamanho2 = 12; contaTamanho2 < 16 && cart[i].numeroCartaoStruct[contaTamanho2] != '\0'; contaTamanho2++) {}
}

/* Função para a contagem da fila */
void fila(int opc) {
    int z, contagemFila, contagemRegressiva;
    for (z = 0; z < contadorMenu; z++) {
        if (vet[z].cod == opc) {
            if (vet[z].prodCongelado == 1) {
                system("cls");
                system("mode 90, 12");
                for (contagemRegressiva = 30; contagemRegressiva > 0; contagemRegressiva--) {
                    printf("Um dos produtos selecionados possui um tempo maior de prepara%c%co, por favor aguarde.\n", 135, 198);
                    printf("\nTempo de espera: %i", contagemRegressiva);
                    Sleep(100);
                    system("cls");
                }
                printf("\nProssiga para o pagamento...");
                Sleep(1500);
            }
        }
    }
}
