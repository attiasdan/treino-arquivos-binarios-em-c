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

//Prot�tipos da Fun��es de Produto:
void inserirProduto();
void excluirProduto();
void consultarProduto();
void editarProduto();

//Prot�tipos da Fun��es de Cliente:
void inserirCliente();
void excluirCliente();
void consultarCliente();
void editarCliente();

//Prot�tipos da Fun��es de Venda:
void inserirVenda();
void excluirVenda();
void consultarVenda();
void editarVenda();

void ordenar(); //ordenacao bolha

int buscaBinariaPorId(FILE *fp, int chave, Produto *p); //busca binaria por codigo

int main()
{
	system("color 0e"); //mudan�a nas cores do terminal
	system("title Trabalho de Arquivos Binarios - Disciplina Programacao 1"); //definicao do titulo da janela
    
	menu();

    return 0;
}
int abrirArquivoLeitura() {
	FILE *fp;
	
	fp = fopen("credit.dat", "rb");
	
	if (!fp) {
		printf("N�o foi poss�vel abrir o arquivo para leitura");
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
void exibirProdutos()
{ //exibicao sequencial
	FILE *arquivo;
	
	arquivo = fopen("produtos.dat", "rb");
	
	if (!arquivo) {
		printf("Nao foi possivel abrir o arquivo para leitura");
	}
	
	Produto auxProduto;
	
	system("cls");
	fseek(arquivo, 0L, SEEK_SET); //posiciona o ponteiro no inicio do arquivo
	while (fread(&auxProduto, sizeof(Produto), 1, arquivo) > 0)
	{
		printf("Codigo de Produto: %d\n", auxProduto.codigo);
		printf("Nome do Produto: %s\n",auxProduto.nome);
		printf("Quantidade do Produto: %d\n",auxProduto.quantidade);
		printf("Preco do Produto: %.2f\n\n",auxProduto.valor);
	}
	fclose(arquivo);
	system("pause");
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
    	
    	printf("13 - Exibir todos os produtos cadastrados\n\n");
    	
    	printf("20 - Exibir tamanho do arquivo de �produtos.dat� e quantidade de registros\n\n");
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
            case 13:
            	exibirProdutos();
            	break;
            	
            case 20:
            	
//            	FILE *f;
//            	
//            	Produto auxProduto;
//            	
//            	f = fopen("produtos.dat", "rb");
//            	
//				fseek(f, 0L, SEEK_END);//posiciona o ponteiro para final do arquivo
//				
//				size_t fSize = ftell(f);
//				
//				printf("Tamanho do arquivo [produtos.dat]: %d (Bytes)", fSize);
//				printf("Nr. registros: %d\n\n", (fSize/sizeof(Produto)));
//				
//				fclose(f);
				
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
	
//	fim = (tamanhoArquivo(fp) / sizeof(Produto)) - 1;
	
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
//fazer pesquisa binaria no proprio arquivo de indice:
	//obter o registro do meio
	//pesquisar chave ate encontrar c�digo ou finalizar a pesquisa
//caso ja exista o codigo, informar o c�digo que j� foi cadastrado.
//nao existindo o codigo:
	//solicitar ao usu�rio as demais informa��es
	//inserir no final do arquivo de dados respectivo
	//inserir no arquivo de �ndice informando o c�digo e a posi��o no arquivo de dados
		//inserir no final do arquivo
		//usar o m�todo da bolha para ordenacao do arquivo de indice
	Produto auxProduto;
	
	FILE *arquivo;
	FILE *arquivo_indice;
	arquivo = fopen("produtos.dat", "ab+");
	arquivo_indice = fopen("indice_produtos.dat", "ab+");
	
	if (!arquivo || !arquivo_indice) {
		printf("Nao foi possivel abrir o arquivo �produtos.dat�");
		return ;
	}
	
	system("cls");
	printf("Voce escolheu a opcao de inserir dados para novo Produto\n\n");
	
	fflush(stdin); //limpar buffer do teclado
	printf("Codigo do Novo Produto:\n> ");
	scanf("%d", &auxProduto.codigo);
	
	//verificar se o codigo ja existe no arquivo 'indice_produtos.dat'
	//se existir informar que ja existe um produto com esse codigo
	
	fflush(stdin);
	printf("Nome do Novo Produto:\n> ");
	gets(auxProduto.nome);
	
	fflush(stdin);
	printf("Quantidade do Novo Produto:\n> ");
	scanf("%d", &auxProduto.quantidade);
	
	fflush(stdin);
	printf("Preco do Novo Produto:\n> ");
	scanf("%f", &auxProduto.valor);
	
	fwrite(&auxProduto, sizeof(Produto), 1, arquivo);
	
	fclose(arquivo);
	fclose(arquivo_indice);
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
- recriar o arquivo de �ndice (vamos discutir em sala)
*/
}
