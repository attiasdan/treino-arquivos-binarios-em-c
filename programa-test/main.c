/*
Arq 4 - indices_clientes:
    campo 'índice' – inteiro
    campo 'posição que o registro ocupa (inteiro)' – inteiro

Arq 5 - indices_produtos:
    campo 'índice' – inteiro
    campo 'posição que o registro ocupa (inteiro)' – inteiro

Arq 6 - indices_vendas:
    campo 'índice' – inteiro
    campo 'posição que o registro ocupa (inteiro)' – inteiro
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

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
    int nroVenda; //ï¿½ndice
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
//void ordenar(); //ordenaï¿½ï¿½o bolha
//void consultar(); //busca binï¿½ria

int main()
{
	system("color f0"); //mudança nas cores do terminal
	system("title Trabalho de Arquivos Binarios - Disciplina Programacao 1"); //definicao do titulo da janela
    
	menu();

    return 0;
}
int abrirArquivoLeitura(char arquivo[20]) {
	FILE *fp;
	
	fp = fopen(arquivo, "rb");
	
	if (!fp) {
		printf("Não foi possível abrir o arquivo para leitura");
		return;
	}
	fclose(fp);
}
int abrirArquivoEscrita(char arquivo[20]) {
	FILE *fp;
	
	fp = fopen(arquivo, "ab");
	
	if (!fp) {
		printf("Nao foi possivel abrir o arquivo para escrita");
	}
	fclose(fp);
}
void printarTodoArquivo(char arquivo[20])
{
	FILE *fp;
	
	fp = fopen(arquivo, "rb");
	
	if (!fp) {
		printf("Nao foi possivel abrir o arquivo para leitura");
	}
	
	Cliente auxCliente;
	
	while ( fread(&auxCliente, sizeof(Cliente), 1, arquivo) ) {
		printf("%d", auxCliente.id);
		printf("%s", auxCliente.nome);
		printf("%s", auxCliente.telefone);
		printf("%s", auxCliente.endereco);
	}
	fclose(fp);
}
void menu()
{
    system("cls");
    int op;
    
    do {
    	printf("Bem vindo(a)!\n\nSelecione uma opcao do menu, digitando o numero e, logo em seguida, pressione a tecla ENTER\n\n");
        printf("1 - Cadastrar 1(um) produto\n");
        printf("2 - Excluir 1(um) produto\n");
        printf("3 - Consultar 1(um) produto\n");
        printf("4 - Editar 1(um) produto\n\n");
        
		printf("5 - Cadastrar 1(um) cliente\n");
        printf("6 - Excluir 1(um) cliente\n");
        printf("7 - Consultar 1(um) cliente\n");
        printf("8 - Editar 1(um) cliente\n\n");
        
		printf("9 - Cadastrar 1(uma) venda\n");
        printf("10 - Excluir 1(uma) venda\n");
        printf("11 - Consultar 1(uma) venda\n");
        printf("12 - Editar 1(uma) venda\n\n");
    	
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

void consultar(int codigo) { //busca por cï¿½digo
	
}
void inserir() {
	//solicitar do usuï¿½rio o cï¿½digo
		//verificar se o cï¿½digo jï¿½ existe no respectivo arquivo de ï¿½ndice
			//fazer pesquisa binï¿½ria no prï¿½prio arquivo:
				//obter o tamanho do arquivo (atributos.c)
				//obter o registro do meio
				//pesquisar chave atï¿½ encontrar cï¿½digo ou finalizar a pesquisa
		//caso jï¿½ exista o cï¿½digo, informar o cï¿½digo que jï¿½ foi cadastrado.
		//nï¿½o existindo o cï¿½digo:
			//solicitar ao usuï¿½rio as demais informaï¿½ï¿½es
			//inserir no final do arquivo de dados respectivo
			//inserir no arquivo de ï¿½ndice informando o cï¿½digo e a posiï¿½ï¿½o no arquivo de dados
				//inserir no final do arquivo
				//usar o mï¿½todo da bolha para ordenaï¿½ï¿½o do arquivo de ï¿½ndice
	
	int codigo = 0;
	printf("Entre com o cï¿½digo do registro:\n> ");
	scanf("%d", &codigo);
}
void atualizar() {
//alteraï¿½ï¿½o de registro
		//solicitar do usuï¿½rio o cï¿½digo
		//verificar se o mesmo jï¿½ existe no respectivo arquivo de ï¿½ndice
		//caso nï¿½o exista, informar ao usuï¿½rio;
		//existindo o cï¿½digo:
			//mostrar os valores dos campos;
			//perguntar qual campo alterar (sï¿½ pode um por vez)
			//pedir a nova informaï¿½ï¿½o e alterar no arquivo de dados.
}
void excluir() {
/*
Excluir registro:
- Pedir primeiro o cï¿½digo;
- Verificar se o mesmo jï¿½ existe no respectivo arquivo de ï¿½ndice;
- Caso nï¿½o exista, informar ao usuï¿½rio;
- Existindo o cï¿½digo:
- pedir confirmaï¿½ï¿½o de exclusï¿½o
- excluir o registro do arquivo de dados (vamos discutir em sala)
- recriar o arquivo de ï¿½ndice (vamos discutir em sala)
*/
}
