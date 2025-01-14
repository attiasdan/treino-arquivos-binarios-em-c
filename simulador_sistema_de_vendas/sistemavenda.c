#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>
#include "sistemavenda.h"

const char *arqProdutos = "produtos.dat";
const char *arqClientes = "clientes.dat";
const char *arqVendas = "vendas.dat";
const char *arqIndiceProdutos = "indice_produtos.dat";
const char *arqIndiceClientes = "indice_clientes.dat";
const char *arqIndiceVendas = "indice_vendas.dat";

Cliente clientes[MAX_CLIENTE];
Produto produtos[MAX_PRODUTO];
Venda vendas[MAX_VENDA];

int qtdProdutosCadastrados = 0;
int codAux = -1;

void menu()
{
    int op;
	int tam = -1;
	int codBusca, posicao;
	
    do {
    	system("cls");
    	printf("Bem vindo(a)!\n\nSelecione uma opcao do menu, digitando o numero e, logo em seguida, pressione a tecla ENTER\n\n");
        printf("(ok) 1 - Cadastrar 1(um) produto\n");
//        printf("2 - Excluir 1(um) produto\n");
        printf("(ok) 3 - Consultar 1(um) produto\n");
        printf("(ok) 4 - Editar 1(um) produto\n");
//		printf("5 - Cadastrar 1(um) cliente\n");
//        printf("6 - Excluir 1(um) cliente\n");
//        printf("7 - Consultar 1(um) cliente\n");
//        printf("8 - Editar 1(um) cliente\n");
//		printf("9 - Cadastrar 1(uma) venda\n");
//        printf("10 - Excluir 1(uma) venda\n");
//        printf("11 - Consultar 1(uma) venda\n");
//        printf("12 - Editar 1(uma) venda\n");
    	printf("(ok) 13 - Exibir todos os produtos cadastrados\n\n");
    	printf("(ok) 14 - Exibir indices dos produtos cadastrados\n\n");
    	printf("(ok) 16 - Consultar produto pelo codigo no arquivo 'indice_produtos.dat'\n\n");
    	printf("(ok) 20 - Exibir tamanho do arquivo de �produtos.dat� em Bytes e quantidade de registros\n\n");
        printf("(ok) 0 - FECHAR PROGRAMA\n\n");
        printf("OPCAO?\n> ");
        scanf("%d", &op);
        
        switch (op)
        {
            case 1:
                inserirProduto();
                break;
            case 3:
            	consultarProduto();
            	break;
            case 4:
            	editarProduto();
                break;
            case 13:
            	exibirProdutos();
            	break;
            case 14:
            	exibirIndiceProdutos();
            	break;
            case 16:
            	printf("Qual o codigo do produto que busca:\n> ");
            	scanf("%d", &codBusca);
            	
            	posicao = consultarIndiceProduto(codBusca);
            	
            	if (posicao != -1) {
            		printf("\nProduto cadastrado, encontra-se na posicao: %d\n\n", posicao);
				}
				else {
					printf("Produto nao cadastrado, codigo nao encontrado");
				}
				system("pause");
            	break;
            case 20:
            	tam = tamanhoArquivo(arqProdutos);
            	if (tam != -1) {
            		printf("Tamanho do arquivo �produtos.dat� em Bytes: %d\n", tam);
            		printf("Quantidade de Registros: %d\n\n", (tam / sizeof(Produto)) );
				}
				system("pause");
				break;
        }
    } while(op != 0);
    
}
FILE *abrirArquivoLeitura(const char *filename) {
	FILE *fp = fopen(filename, "rb");
	if (!fp)
		printf("Nao foi possivel abrir o arquivo");
	return fp;
}
FILE *abrirArquivoEscrita(const char *filename) {
	FILE *fp = fopen(filename, "ab+");
	if (!fp)
		printf("Nao foi possivel abrir o arquivo");
	return fp;
}

void editarProduto()
{
	int posicao = consultarProduto();
	
	if (posicao != -1)
	{ //permitido editar
		FILE *arquivo = fopen(arqProdutos, "rb+");
		Produto auxProduto;
		
		rewind(arquivo);
	
		//posiciona ponteiro a partir de onde ler:
		fseek(arquivo, posicao, SEEK_SET);
		
		//Novos dados:
		auxProduto.codigo = codAux;
		printf("Nome do Novo Produto:\n> ");
		fflush(stdin);
		gets(auxProduto.nome);
		
		printf("Quantidade do Novo Produto:\n> ");
		fflush(stdin);
		scanf("%d", &auxProduto.quantidade);
		
		printf("Preco do Novo Produto:\n> ");
		fflush(stdin);
		scanf("%f", &auxProduto.valor);
		
		//grava os dados:
		fwrite(&auxProduto, sizeof(Produto), 1, arquivo);
		
		fclose(arquivo);
	}
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

void ordenar(int *V  , int N) {
    int i, continua, aux;
    do{
        continua = 0;
        for(i = 0; i < N-1; i++){
            if (V[i] > V[i+1]){
                aux = V[i];
                V[i] = V[i+1];
                V[i+1] = aux;
                continua = 1;
            }
        }
    }while(continua);
}
int tamanhoArquivo(const char *filename)
{
	struct stat sb;

    if (stat(filename, &sb) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }
	return sb.st_size;
}
int solicitarCodigo() {
	int cod = -1;
	printf("Entre com o codigo do registro:\n> ");
	scanf("%d", &cod);
	return cod;
}
int consultarIndiceProduto(int chave)
{//busca binaria por indice

	FILE *fp = abrirArquivoLeitura(arqIndiceProdutos);
		
	//busca:
	int inicio, meio, fim;
	inicio = 0;
	Indice aux;
	
	fim = (tamanhoArquivo(arqIndiceProdutos) / sizeof(Indice)) - 1;
	
	while (inicio <= fim)
	{
		meio = (inicio + fim) / 2;

		fseek(fp, meio * sizeof(Indice), SEEK_SET);
		
		fread(&aux, sizeof(Indice), 1, fp);
		
		if (chave > aux.indice) {
			inicio = meio + 1;
		}
		else {
			if (chave < aux.indice) {
				fim = meio - 1;
			}
			else {
				return aux.posicao;
			}
		}
	}
	return -1;
}
int consultarProduto() {
	int cod = solicitarCodigo();
	codAux = cod;
	int posicao = -1;
	FILE *arquivo = abrirArquivoLeitura(arqProdutos);
	Produto auxProduto;
	
	posicao = consultarIndiceProduto(cod);
	
	if (posicao == -1) {
		printf("Codigo inexistente, impossivel editar.");
		return ;
	}
	
	printf("Posicao = %d\n", posicao);
	
	rewind(arquivo);
	
	//posiciona ponteiro a partir de onde ler:
	fseek(arquivo, posicao, SEEK_SET);
	
	fflush(stdin);
	//le dados:
	fread(&auxProduto, sizeof(Produto), 1, arquivo);
	
	exibirProduto(auxProduto);
	
	fflush(stdin);
	system("pause");
	fclose(arquivo);
	
	return posicao;
}
void exibirProduto(Produto p) {
	printf("Codigo do produto = %d\n", p.codigo);
	printf("Nome do produto = %s\n", p.nome);
	printf("Quantidade do produto = %d\n", p.quantidade);
	printf("Preco do produto = %.2f\n\n", p.valor);
}
void inserirProduto() {
	Produto auxProduto;
	Indice auxIndice;
	
	FILE *arquivo;
	FILE *arquivo_indice;
	
	arquivo = abrirArquivoEscrita(arqProdutos);
	arquivo_indice = abrirArquivoEscrita(arqIndiceProdutos);
	
	qtdProdutosCadastrados = tamanhoArquivo(arqProdutos) / sizeof(Produto);
	system("cls");
	
	if (!arquivo || !arquivo_indice) {
		printf("Nao foi possivel abrir o arquivo �produtos.dat� ou �indice_produtos.dat� para escrita");
		return ;
	}
	
	printf("Voce escolheu a opcao de inserir dados para novo Produto\n\n");
	
	int volta = 1;
	do {
		printf("\nCodigo do Novo Produto:\n> ");
		fflush(stdin); //limpar buffer do teclado
		scanf("%d", &auxProduto.codigo);
		
		if (consultarIndiceProduto(auxProduto.codigo) != -1) {
			printf("Codigo indisponivel, tente outro...\n");
			volta = 1;
		} else {
			volta = 0;
		}
	} while (volta);
	
	printf("Nome do Novo Produto:\n> ");
	fflush(stdin);
	gets(auxProduto.nome);
	
	printf("Quantidade do Novo Produto:\n> ");
	fflush(stdin);
	scanf("%d", &auxProduto.quantidade);
	
	printf("Preco do Novo Produto:\n> ");
	fflush(stdin);
	scanf("%f", &auxProduto.valor);
	
	//gravando os dados no arquivo 'produtos.dat'
	fwrite(&auxProduto, sizeof(Produto), 1, arquivo);

	//gravando os dados no arquivo 'indice_produtos.dat'
	auxIndice.indice = auxProduto.codigo;
	qtdProdutosCadastrados = tamanhoArquivo(arqProdutos) / sizeof(Produto);
	
	if (qtdProdutosCadastrados == 0) {
		auxIndice.posicao = 0;
	}
	else {
		auxIndice.posicao = (qtdProdutosCadastrados * sizeof(Produto));
	}
	fwrite(&auxIndice, sizeof(Indice), 1, arquivo_indice);
	
	//liberando os ponteiros do arquivos
	fclose(arquivo);
	fclose(arquivo_indice);
	
	//usar o metodo da bolha para ordenacao do arquivo de indice
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
void exibirIndiceProdutos()
{
	FILE *arquivo;
	arquivo = fopen(arqIndiceProdutos, "rb");
	
	Indice auxIndice;

	system("cls");
	
	fseek(arquivo, 0L, SEEK_SET); //posiciona o ponteiro no inicio do arquivo
	
	while (fread(&auxIndice, sizeof(Indice), 1, arquivo) > 0)
	{
		printf("Indice: %d\n", auxIndice.indice);
		printf("Posicao: %d\n\n",auxIndice.posicao);
	}
	system("pause");
	fclose(arquivo);
}
void exibirProdutos()
{ //exibicao sequencial
	FILE *arquivo = fopen(arqProdutos, "rb");
	
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
void exibirClientes()
{ //exibicao sequencial
	FILE *arquivo = fopen(arqClientes, "rb");
	
	if (!arquivo) {
		printf("Nao foi possivel abrir o arquivo para leitura");
	}
	
	Cliente auxCliente;
	
	system("cls");
	
	fseek(arquivo, 0L, SEEK_SET); //posiciona o ponteiro no inicio do arquivo
	
	while (fread(&auxCliente, sizeof(Cliente), 1, arquivo) > 0)
	{
		printf("Codigo do Cliente: %d\n", auxCliente.codigo);
		printf("Nome do Cliente: %s\n",auxCliente.nome);
		printf("Endereco do Cliente: %s\n",auxCliente.endereco);
		printf("Telefone do Cliente: %s\n\n",auxCliente.telefone);
	}
	fclose(arquivo);
	system("pause");
}
