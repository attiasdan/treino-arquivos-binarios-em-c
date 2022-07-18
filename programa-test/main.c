/*
Arq 4 - indices_clientes:
    campo 'Ã­ndice' â€“ inteiro
    campo 'posiÃ§Ã£o que o registro ocupa (inteiro)' â€“ inteiro

Arq 5 - indices_produtos:
    campo 'Ã­ndice' â€“ inteiro
    campo 'posiÃ§Ã£o que o registro ocupa (inteiro)' â€“ inteiro

Arq 6 - indices_vendas:
    campo 'Ã­ndice' â€“ inteiro
    campo 'posiÃ§Ã£o que o registro ocupa (inteiro)' â€“ inteiro
*/

//F6 para compilar no vscode
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
//#include "funcoes.c"

#define MAX_CLIENTE 100
#define MAX_PRODUTO 100
#define MAX_VENDA 100

typedef struct {
    int id; //ok
    char nome[100]; //ok
    char telefone[13]; //ok
    char endereco[100]; //ok
} Cliente;

typedef struct {
    int id; //ok
    char nome[50]; //ok
    int quantidade; //ok
    float valor; //ok
} Produto;

typedef struct {
    int nroVenda; //índice
    char dataVendas[10]; //ok
    
    int codCliente; //ok
    int codProduto; //ok
    
    int qtdProdutos; //ok
	float valorTotal; //ok
} Venda;

Cliente clientes[MAX_CLIENTE];
Produto produtos[MAX_PRODUTO];
Venda vendas[MAX_VENDA];

void menu();
void cadastrarVenda();
//void ordenar(); //ordenação bolha
//void consultar(); //busca binária

int main()
{
	system("color f0");
	system("title Trabalho de Arquivos Binários - Disciplina Programação 1");
    
	menu();

    return 0;
}

void menu()
{
    system("cls");
    int op;
    
    do {
    	printf("Bem vindo(a)!\n\nSelecione uma opcao do menu, digitando o numero e, logo em seguida, pressione a tecla ENTER\n\n");
        printf("1 - Cadastrar 1(um) produto\n");
        printf("2 - Excluir 1(um) produto	\n");
        printf("3 - Consultar 1(um) produto\n");
        printf("4 - Editar 1(um) produto	\n\n");
        
		printf("5 - Cadastrar 1(um) cliente\n");
        printf("6 - Excluir 1(um) cliente	\n");
        printf("7 - Consultar 1(um) cliente\n");
        printf("8 - Editar 1(um) cliente	\n\n");
        
		printf("9 - Cadastrar 1(uma) venda	\n");
        printf("10 - Excluir 1(uma) venda	\n");
        printf("11 - Consultar 1(uma) venda	\n");
        printf("12 - Editar 1(uma) venda	\n\n");
    	
        printf("0 - FECHAR PROGRAMA\n\n");
        
        printf("OPCAO?\n> ");
        scanf("%d", &op);
        
        switch (op)
        {
            case '1':
//                cadastrarVenda();
                break;
            case '2':
                break;
        }
    } while(op!=0);
}
void cadastrarVenda()
{
    system("cls");
    char datavendas[10];
    int qtdproduto;
    float valorvenda;
    int op;

    do {
        printf("\nInforme a data da venda: ");
//        scanf("%s", &ptr_Venda->datavenda);
        printf("\nInforme a quantidade de produtos: ");
//        scanf("%d", &ptr_Venda->qtdproduto);
        printf("\nInforme o valor da venda: ");
//        scanf("%.2f", &ptr_Venda->valorvenda);

//        for(int i = 0, i < MAX_VENDA;++i)
//        {
//            if(vendas[i].identificador==0)
//			{
//                vendas[i].datavenda;
//                vendas[i].qtdproduto;
//                vendas[i].valorvenda;
//                break;
//            }
//        }
        printf("\nPara continuar - pressione 1\nPara sair - Pressione 0");
        scanf("%d",&op);
    } while(op!=0);

}//cadastrarVenda

void consultar(int codigo) { //busca por código
	
}
void inserir() {
	//solicitar do usuário o código
		//verificar se o código já existe no respectivo arquivo de índice
			//fazer pesquisa binária no próprio arquivo:
				//obter o tamanho do arquivo (atributos.c)
				//obter o registro do meio
				//pesquisar chave até encontrar código ou finalizar a pesquisa
		//caso já exista o código, informar o código que já foi cadastrado.
		//não existindo o código:
			//solicitar ao usuário as demais informações
			//inserir no final do arquivo de dados respectivo
			//inserir no arquivo de índice informando o código e a posição no arquivo de dados
				//inserir no final do arquivo
				//usar o método da bolha para ordenação do arquivo de índice
	
	int codigo = 0;
	printf("Entre com o código do registro:\n> ");
	scanf("%d", &codigo);
}
void atualizar() {
//alteração de registro
		//solicitar do usuário o código
		//verificar se o mesmo já existe no respectivo arquivo de índice
		//caso não exista, informar ao usuário;
		//existindo o código:
			//mostrar os valores dos campos;
			//perguntar qual campo alterar (só pode um por vez)
			//pedir a nova informação e alterar no arquivo de dados.
}
void excluir() {
/*
Excluir registro:
- Pedir primeiro o código;
- Verificar se o mesmo já existe no respectivo arquivo de índice;
- Caso não exista, informar ao usuário;
- Existindo o código:
- pedir confirmação de exclusão
- excluir o registro do arquivo de dados (vamos discutir em sala)
- recriar o arquivo de índice (vamos discutir em sala)
*/
}
