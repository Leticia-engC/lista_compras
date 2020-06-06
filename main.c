#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct // Cria uma STRUCT para armazenar os dados de um item
{
    char nome[25];   // define o campo Nome
    int  numeroItens;  // define o campo Numero De Itens
} Categoria;

typedef struct // Cria uma STRUCT para armazenar os dados de um item
{
    char  descricao[15];   // define o campo Descricao
    int   quantidade;    // define o campo Quantidade
    char  unidadeMed[3]; // define o campo Medida
    char  unidadeMon[2]; // define Unidade Monetaria
    float valorUni; // define Valor Unitario
} Item;

void completaCategoria(Categoria *cat, int i){
    printf("Digite o nome da %da categoria\n", i+1);
    scanf("%s", &cat->nome); //lê o nome da categoria
    printf("Digite o numero de  itens da categoria %s\n", cat->nome);
    scanf("%d", &cat->numeroItens);
}

void completaItem(Item *item, char nomeCategoria, int j){
     scanf ("%s %f", &item->descricao, &item->quantidade);
    scanf("%s %s %f", &item->unidadeMed, &item->unidadeMon, &item->valorUni);

    printf("%s %.3f %s %s %.2f\n", item->descricao, item->quantidade, item->unidadeMed, item->unidadeMon, item->valorUni);
}
//imprime as informações do item

int main() {
    int nCat, categorias[99], itens[99][99];
    scanf("%d", &nCat); //lê o número de categorias
    for(int i = 0; i < nCat; i++){ //loop for para as CATEGORIAS
        Categoria cat;
        categorias[i] = &cat;
        completaCategoria(&cat, i);
        for(int j = 0; j < cat.numeroItens; j++){//loop for para itens
            Item item;
            itens[i][j] = &item;
            completaItem(&item, cat.nome, j);
        }
    }
    return 0;
}