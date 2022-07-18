/*
Arq 4 - indices_clientes:
    campo '�ndice' � inteiro
    campo 'posi��o que o registro ocupa (inteiro)' � inteiro

Arq 5 - indices_produtos:
    campo '�ndice' � inteiro
    campo 'posi��o que o registro ocupa (inteiro)' � inteiro

Arq 6 - indices_vendas:
    campo '�ndice' � inteiro
    campo 'posi��o que o registro ocupa (inteiro)' � inteiro
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
    int nroVenda; //�ndice
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
//void ordenar(); //ordena��o bolha
//void consultar(); //busca bin�ria

int main()
{
	system("color f0"); //mudan�a nas cores do terminal
	system("title Trabalho de Arquivos Binarios - Disciplina Programacao 1"); //definicao do titulo da janela
    
	menu();

    return 0;
}
int abrirArquivoLeitura(char arquivo[20]) {
	FILE *fp;
	
	fp = fopen(arquivo, "rb");
	
	if (!fp) {
		printf("N�o foi poss�vel abrir o arquivo para leitura");
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

void consultar(int codigo) { //busca por c�digo
	
}
void inserir() {
	//solicitar do usu�rio o c�digo
		//verificar se o c�digo j� existe no respectivo arquivo de �ndice
			//fazer pesquisa bin�ria no pr�prio arquivo:
				//obter o tamanho do arquivo (atributos.c)
				//obter o registro do meio
				//pesquisar chave at� encontrar c�digo ou finalizar a pesquisa
		//caso j� exista o c�digo, informar o c�digo que j� foi cadastrado.
		//n�o existindo o c�digo:
			//solicitar ao usu�rio as demais informa��es
			//inserir no final do arquivo de dados respectivo
			//inserir no arquivo de �ndice informando o c�digo e a posi��o no arquivo de dados
				//inserir no final do arquivo
				//usar o m�todo da bolha para ordena��o do arquivo de �ndice
	
	int codigo = 0;
	printf("Entre com o c�digo do registro:\n> ");
	scanf("%d", &codigo);
}
void atualizar() {
//altera��o de registro
		//solicitar do usu�rio o c�digo
		//verificar se o mesmo j� existe no respectivo arquivo de �ndice
		//caso n�o exista, informar ao usu�rio;
		//existindo o c�digo:
			//mostrar os valores dos campos;
			//perguntar qual campo alterar (s� pode um por vez)
			//pedir a nova informa��o e alterar no arquivo de dados.
}
void excluir() {
/*
Excluir registro:
- Pedir primeiro o c�digo;
- Verificar se o mesmo j� existe no respectivo arquivo de �ndice;
- Caso n�o exista, informar ao usu�rio;
- Existindo o c�digo:
- pedir confirma��o de exclus�o
- excluir o registro do arquivo de dados (vamos discutir em sala)
- recriar o arquivo de �ndice (vamos discutir em sala)
*/
}
