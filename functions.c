#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "functions.h"

void chamaMenu ()
{

    printf("\n\n\n\n\n\n\t\t\t\t\t1-Cadastrar novos produtos\n");
    printf("\t\t\t\t\t2-Consultar Estoque \n");
    printf("\t\t\t\t\t3-Editar produtos \n");
    printf("\t\t\t\t\t4-Remover produtos \n");
    printf("\t\t\t\t\t5-Exibir relatorio geral \n");

}

void cadastraProduto()
{
    FILE *pont_arq;

    char nome[20];
    int quantidade;
    float valor;

    printf("\n\n\n\n\n\n\t\t\t\t\t Escreva o nome do produto\n");
    scanf("%s", nome);

    printf("\t\t\t\t\t Digite a quantidade\n");
    scanf("%d", &quantidade);

    printf("\t\t\t\t\t Diite o valor\n");
    scanf("%f", &valor);

    fprintf(pont_arq,"\n%s\t", nome);
    fprintf(pont_arq,"%d\t", quantidade);
    fprintf(pont_arq,"%.2f\n", valor);

    printf("\t\t\t\t\tProduto gravado com sucesso!");

    fclose(pont_arq);
}


void categorias ()
{

    FILE *pont_arq;

    int opcao;
    printf("\t\t\t\t\t1-Camiseta\n");
    printf("\t\t\t\t\t2-Calca\n");
    printf("\t\t\t\t\t3-Tenis\n");
    printf("\t\t\t\t\tSelecione a categoria:\n");
    scanf("%d", &opcao);

    switch(opcao)
    {

    case 1:
        pont_arq = fopen("camisetas.txt", "a");

        break;

    case 2:
        pont_arq = fopen("calcas.txt", "a");
        break;

    case 3:
        pont_arq = fopen("tenis.txt", "a");
        break;

    }

}

void categoriasLeitura()
{

    FILE *pont_arq;

    int opcao;
    printf("\n\t\t\t\t1- Lista de camisetas\n");
    printf("\n\t\t\t\t2- Lista de calcas\n");
    printf("\n\t\t\t\t3- Lista de Tenis\n");
    printf("\n\t\t\t\tSelecione a lista que deseja consultar:\n");
    scanf("%d", &opcao);

    switch(opcao)
    {

    case 1:
        pont_arq = fopen("camisetas.txt","r");

        break;

    case 2:
        pont_arq = fopen("calcas.txt", "r");

        break;

    case 3:
        pont_arq = fopen("tenis.txt", "r");

        break;
    }
}

void mostraProduto()
{
    char leitura;

    FILE *pont_arq;


    do
    {
        leitura = fgetc(pont_arq);
        printf("%c", leitura);

    }
    while (leitura!= EOF); //enquanto não for final de arquivo

    fclose(pont_arq);

}

void editaProduto()
{
    FILE *pont_arq;

    int opcaoTxt=0;
    printf("\n\t\t\t\t1- Lista de camisetas\n");
    printf("\n\t\t\t\t2- Lista de calcas\n");
    printf("\n\t\t\t\t3- Lista de Tenis\n");
    printf("\n\t\t\t\tSelecione a lista que deseja editar:\n");
    scanf("%d", &opcaoTxt);

    switch(opcaoTxt)
    {

    case 1:
        pont_arq = fopen("camisetas.txt","r");

        break;

    case 2:
        pont_arq = fopen("calcas.txt", "r");

        break;

    case 3:
        pont_arq = fopen("tenis.txt", "r");

        break;
    }

    int i = 3, aux = 0;
    int c = 1;
    int j;
    int opcao;
    char dados[99][999];

    while(fscanf(pont_arq, "%s%s%s", dados[i], dados[i + 1], dados[i + 2]) != -1)
    {

        i+=3;

    }
    fclose(pont_arq);

    for(j = 3; j < i; j+=3 )
    {
        printf ("\n\t\t\t\tNome: %s\n\t\t\t\tQuantidade: %s\n\t\t\t\tValor: %s\n", dados[j],dados[j + 1], dados[j + 2]);

    }

    printf ("\n\t\t\t\tdigite qual produto voce quer alterar (1, 2, 3..?\n");
    scanf ("%d", &opcao);


    if (opcao != 0)
    {
        opcao = opcao*3;

        printf ("\n\t\t\t\tNome: %s, quantidade: %s, valor: %s \n", dados[opcao], dados[opcao+1],dados[opcao+2]);

        printf ("\n\t\t\t\tdigite o novo nome \n");
        scanf ("%s",dados[opcao]);

        printf ("\n\t\t\t\tdigite a nova quantidade\n");
        scanf ("%s",dados[opcao+1]);

        printf ("\n\t\t\t\tdigite o novo valor \n");
        scanf ("%s",dados[opcao+2]);

    }

    FILE * ponteiroEdita;

    switch(opcaoTxt)
    {

    case 1:
        ponteiroEdita = fopen("camisetas.txt","w");

        break;

    case 2:
        ponteiroEdita = fopen("calcas.txt", "w");

        break;

    case 3:
        ponteiroEdita = fopen("tenis.txt", "w");

        break;
    }


    for(int k = 3; k < i; k+=3)
    {

        fprintf(ponteiroEdita,"%s\t %s\t %s\t", dados[k],dados[k + 1], dados[k + 2]);

    }

    fclose(ponteiroEdita);

}
void removeProduto()
{

    char aux [99][999];
    int j, k;
    char dados [99][999];
    int opcao;
    int i= 3;
    int opcaoTxt;

    FILE *pont_remove;

    printf("\n\t\t\t\t1- Lista de camisetas\n");
    printf("\n\t\t\t\t2- Lista de calcas\n");
    printf("\n\t\t\t\t3- Lista de Tenis\n");
    printf("\n\t\t\t\tSelecione a lista que deseja remover:\n");
    scanf("\n\t\t\t\t%d", &opcaoTxt);


    switch(opcaoTxt)
    {

    case 1:
        pont_remove = fopen("camisetas.txt","r");

        break;

    case 2:
        pont_remove = fopen("calcas.txt", "r");

        break;

    case 3:
        pont_remove = fopen("tenis.txt", "r");
        break;
    }



    while(fscanf(pont_remove, "%s%s%s", dados[i], dados[i + 1], dados[i + 2]) != -1)
    {

        i+=3;

    }
    fclose(pont_remove);

    for(j = 3; j < i; j+=3 )
    {
        printf ("\n\t\t\t\tNome: %s\n\t\t\t\tQuantidade: %s\n\t\t\t\tValor: %s\n", dados[j],dados[j + 1], dados[j + 2]);

    }
    printf("\n\t\t\t\tdigite qual voce deseja remover");
    scanf("%d", &opcao);

    for(j = 3; j < i; j+=3)
    {

        if(j != opcao*3)
        {

            strcpy(aux[j], dados[j]);
            strcpy(aux[j+1], dados[j+1]);
            strcpy(aux[j+2], dados[j+2]);
        }
    }

    FILE * ponteiroEdita;

    switch(opcaoTxt)
    {

    case 1:
        ponteiroEdita = fopen("camisetas.txt","w");

        break;

    case 2:
        ponteiroEdita = fopen("calcas.txt", "w");

        break;

    case 3:
        ponteiroEdita = fopen("tenis.txt", "w");

        break;
    }


    for(int k = 3; k < i; k+=3)
    {

        fprintf(ponteiroEdita,"%s\t %s\t %s\t", aux[k],aux[k + 1], aux[k + 2]);

    }

    fclose(ponteiroEdita);

}

void ordenaProduto()
{
    FILE *pontCamisetas;
    pontCamisetas = fopen("camisetas.txt","r");

    FILE *pontTenis;
    pontTenis = fopen("tenis.txt","r");

    FILE *pontCalcas;
    pontCalcas = fopen("calcas.txt","r");

    int i = 3;
    int c = 1;
    int j;

    char aux[20];
    char aux1[20];
    char aux2[20];
    char dados[99][999];

    while(fscanf(pontCamisetas, "%s%s%s", dados[i], dados[i + 1], dados[i + 2]) != -1)
    {
        i+=3;
    }

    while(fscanf(pontTenis, "%s%s%s", dados[i], dados[i + 1], dados[i + 2]) != -1)
    {
        i+=3;
    }

    while(fscanf(pontCalcas, "%s%s%s", dados[i], dados[i + 1], dados[i + 2]) != -1)
    {
        i+=3;

    }

    fclose(pontCalcas);
    fclose(pontTenis);
    fclose(pontCamisetas);

    for (int k = 3; k < i-2; k+=3)   //i= qtde de palavras */

    {
        for (j = k; j < i-2; j+=3)

        {
            if (strcmp(dados[k], dados[j]) > 0)   //3 em 3
            {
                strcpy(aux, dados[k]);
                strcpy(dados[k], dados[j]);
                strcpy(dados[j], aux);

                strcpy(aux2, dados[k+1]);
                strcpy(dados[k+1], dados[j+1]);
                strcpy(dados[j+1], aux2);

                strcpy(aux2, dados[k+2]);
                strcpy(dados[k+2], dados[j+2]);
                strcpy(dados[j+2], aux2);
            }
        }
    }

    for (int m = 3 ; m < i; m+=3)
    {
        printf("\n\t\t\t\tNome: %s\n\t\t\t\tQuantidade: %s\n\t\t\t\tValor: %s\n", dados[m], dados[m+1], dados[m+2]);
    }

    int quantidade=0;

    for(int a= 4; a < i; a+=3 )
    {
        quantidade += atoi(dados[a]);

    }
    printf("\n\t\t\t\t\t\tQuantidade de produtos em estoque: %d", quantidade);

    double valor=0;
    char str[99];

    for(int v= 5; v < i; v+=3 )
    {

        strcpy(str, dados[v]);
        valor += atof(str);
    }

    printf("\n\t\t\t\t\t\tValor em estoque = %.2f\n", valor);

}
