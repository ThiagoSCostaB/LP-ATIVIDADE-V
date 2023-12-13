
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>

struct produto_do_galpao
{
    char nome[200];
    float preco;
    int Estoque;
};

int codigo;
float calculoFinal;
int i;
int j;
int p;
int produtoEncontrado = 0;
char nomeProduto[200];
char resp[200];
int valorEstoque;
int estoque_atualizado;
struct produto_do_galpao produto[200];


float calcularEstoque()
{
    calculoFinal = produto[j].preco * produto[j].Estoque;
    return calculoFinal;
}

int atualizaEstoque()
{
    produto[j].Estoque = produto[j].Estoque + valorEstoque;

    return produto[j].Estoque;
}

float valorDosProdutos(){
   produto[p].preco = produto[p].preco * produto[p].Estoque;

   return produto[p].preco;
}

int main()
{

    setlocale(LC_ALL, "portuguese");

    do
    {
        printf("\n================Menu============\n");
        printf("1-Digite o nome do produto: \n");
        printf("2-Quantidade de produtos comprados: \n");
        printf("3-Calcular o valor dos produtos: \n");
        printf("4-Quantidade estoque :\n");
        printf("5- para sair do programa: \n");
        scanf("%d", &codigo);
        printf("\n");


        switch (codigo)
        {
        case 1:
            do
            {
                p = p + 1;
                fflush(stdin);
                printf("Digite o nome do produto: ");
                gets(produto[p].nome);

                printf("Digite o preço: ");
                scanf("%f", &produto[p].preco);

                printf("Digite a quantidade de produto: ");
                scanf("%d", &produto[p].Estoque);
        
                getchar();

                printf("Continuar cadastrando produto? [S/N] ");
                gets(resp);
                fflush(stdin);

            } while (strcmp(resp, "S") == 0);

            break;
        case 2:

            produtoEncontrado = 0;
            fflush(stdin);
            printf("Digite o nome do produto a ser consultado: ");
            gets(nomeProduto);

            fflush(stdin);
            for (i = 0; i <= p; i++)
            {

                if (strcmp(nomeProduto, produto[i].nome) == 0)
                {
                    produtoEncontrado = 1;
                    j = i;
                    printf("Quantidade ATUAL de ESTOQUE: %d\n", produto[j].Estoque);

                    fflush(stdin);
                    printf("\n Atualizar estoque? [S/N] \n");
                    gets(resp);

                    fflush(stdin);

                    if (strcmp(resp, "S") == 0)
                    {
                        fflush(stdin);
                        printf("Qual valor a adicionado ao estoque? \n");
                        scanf("%d", &valorEstoque);

                        atualizaEstoque();

                        printf("Estoque atualizado!");
                        printf("Estoque atual: %d\n", produto[j].Estoque);
                    }
                }
            }

            if (produtoEncontrado == 0)
            {
                printf("Produto não localizado.\n");
            }

            break;
        
        case 3:
        valorDosProdutos();

        printf("Quantidade de produtos comprados : %.2f",produto[p].preco);
        break;

        case 4:
          printf("Quantidade em estoque 4000...\n");   
        break;
        case 5:

        printf("Saindo do sistema\n");
        break;
        default:
        printf("opçao invalida...\n");
        }
        

         

    } while (codigo != 5);

    return 0;
}
