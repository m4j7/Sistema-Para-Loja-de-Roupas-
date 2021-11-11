#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "functions.h"

int main()
{
    int controle= 0;
    char leitura;

    do
    {
        do
        {
            chamaMenu();
            scanf("%d", &controle);
            system("cls");

        }
        while(controle == 6);


        switch(controle)
        {

        case 1:
            printf("\n\t\t\t\tCadastro de novos produtos \n\n");

            categorias();
            cadastraProduto();

            printf ("\n\t\t\t\tPara voltar digite 6\n\n");
            scanf("%d", &controle);
            system("cls");

            break;

        case 2:
            printf("\n\t\t\t\tConsulta de estoque\n\n");

            categoriasLeitura();
            mostraProduto(leitura);

            printf ("\n\t\t\t\tPara voltar digite 6\n\n");

            scanf("%d", &controle);
            system("cls");

            break;

        case 3:
            printf("\n\t\t\t\tEditar produtos\n\n");
            editaProduto(leitura);
            printf ("\n\t\t\t\tPara voltar digite 6\n\n");
            scanf("%d", &controle);
            system("cls");
            break;

        case 4:
            printf ("\n\t\t\t\tRemover Produtos\n\n");
            removeProduto();
            printf ("\n\t\t\t\tPara voltar digite 6");
            scanf("%d", &controle);
            system("cls");
            break;

        case 5:
            printf ("\t\t\t\t\t\tRelatorio Completo\n\n");

            ordenaProduto();

            printf ("\n\t\t\t\tPara voltar digite 6");
            scanf("%d", &controle);
            system("cls");
            break;

        case 6:
            printf ("\t\t\t\t\t\tEfetuar Compra\n\n");


        }

    }
    while(controle != 0);

    return 0;
}
