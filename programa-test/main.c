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
    int codigo; //identificador
    char nome[100]; //ok
    char telefone[13]; //ok
    char endereco[100]; //ok
} Cliente;

typedef struct {
    int codigo; //identificador
    char nome[50]; //ok
    int quantidade; //ok
    float valor; //ok
} Produto;

typedef struct {
    int nroVenda; //identificador
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

//Protótipos da Funções de Produto:
void inserirProduto();
void excluirProduto();
void consultarProduto();
void editarProduto();

//Protótipos da Funções de Cliente:
void inserirCliente();
void excluirCliente();
void consultarCliente();
void editarCliente();

//Protótipos da Funções de Venda:
void inserirVenda();
void excluirVenda();
void consultarVenda();
void editarVenda();

void ordenar(); //ordenacao bolha

int buscaBinariaPorId(FILE *fp, int chave, Produto *p); //busca binaria por codigo

int main()
{
	system("color f0"); //mudança nas cores do terminal
	system("title Trabalho de Arquivos Binarios - Disciplina Programacao 1"); //definicao do titulo da janela
    
	menu();

    return 0;
}
int abrirArquivoLeitura() {
	FILE *fp;
	
	fp = fopen("credit.dat", "rb");
	
	if (!fp) {
		printf("Não foi possível abrir o arquivo para leitura");
		return;
	}
	fclose(fp);
}
int abrirArquivoEscrita() {
	FILE *fp;
	
	fp = fopen("credit.dat", "ab");
	
	if (!fp) {
		printf("Nao foi possivel abrir o arquivo para escrita");
	}
	fclose(fp);
	
	return 0;
}
void printarTodoArquivo()
{
	FILE *arquivo;
	
	arquivo = fopen("credit.dat", "rb");
	
	if (!arquivo) {
		printf("Nao foi possivel abrir o arquivo para leitura");
	}
	
	Cliente auxCliente;
	
	while ( fread(&auxCliente, sizeof(Cliente), 1, arquivo) > 0 ) {
		printf("%d", auxCliente.codigo);
		printf("%s", auxCliente.nome);
		printf("%s", auxCliente.telefone);
		printf("%s", auxCliente.endereco);
	}
	fclose(arquivo);
}
void menu()
{
    int op;
    
    do {
    	system("cls");
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
            case 1:
                inserirProduto();
                break;
            case 2:
                break;
        }
    } while(op!=0);
}

void inserirVenda()
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
//            if(vendas[i].codigoentificador==0)
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

void consultar(int codigo) { //busca por codigo
	
}

int buscaBinariaPorId(FILE *fp, int chave, Produto *p)
{//busca binaria por codigo
	int inicio, meio, fim;
	
	inicio = 0;
	
	fim = (tamanhoArquivo(fp) / sizeof(Produto)) - 1;
	
	while (inicio <= fim) {
		meio = (inicio + fim) / 2;
		
		fseek(fp, meio * sizeof(Produto), SEEK_SET);
		
		fread(p, sizeof(Produto), 1, fp);
		
		if (chave > p->codigo) {
			inicio = meio + 1;
		}
		else {
			if (chave < p->codigo) {
				fim = meio - 1;
			}
			else {
				return 1; //achou
			}
		}
	}
	return 0;
}

void inserirProduto() {
	//1º solicitar o codigo
		//2º verificar se o codigo ja existe no respectivo arquivo de indice
			//fazer pesquisa binaria no proprio arquivo:
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
	int continuar;
	Produto auxProduto;
	FILE *arquivo;
	
	arquivo = fopen("produtos.dat", "ab");
	
	if (!arquivo) {
		printf("Nao foi possivel abrir o arquivo 'produtos.dat' ");
		return ;
	}

	printf("Entre com o codigo do registro de produto:\n> ");
	scanf("%d", &codigo);
	
	do {
		fflush(stdin); //limpar buffer do teclado
		
		system("cls");
		
		printf("Nome: ");
		gets(auxProduto.nome);
		
		fwrite(&auxProduto, sizeof(Produto), 1, arquivo);
	} while(continuar);
}
void atualizar() {
//alteracao de registro
		//solicitar do usuario o codigo
		//verificar se o mesmo ja existe no respectivo arquivo de indice
		//caso nao exista, informar ao usuario;
		//existindo o codigo:
			//mostrar os valores dos campos;
			//perguntar qual campo alterar (so pode um por vez)
			//pedir a nova informacao e alterar no arquivo de dados.
}
void excluir() {
/*
Excluir registro:
- Pedir primeiro o codigo;
- Verificar se o mesmo ja existe no respectivo arquivo de indice;
- Caso nao exista, informar ao usuario;
- Existindo o codigo:
- pedir confirmacao de exclusivo
- excluir o registro do arquivo de dados (vamos discutir em sala)
- recriar o arquivo de ï¿½ndice (vamos discutir em sala)
*/
}
