#ifndef SISTEMAVENDA_H_INCLUDED
#define SISTEMAVENDA_H_INCLUDED

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

typedef struct {
	int indice; //aponta (semelhante a chave estrangeira) 
	int posicao;
} Indice;

void menu();

int tamanhoArquivo(const char *filename); //100% funcionando

void ordenar(int *V  , int N); //nao esta funcionando

FILE *abrirArquivoLeitura(const char *filename);
FILE *abrirArquivoEscrita(const char *filename);

//Protótipos das Funções de Produto:
void inserirProduto(); //100% funcionando
void exibirIndiceProdutos(); //100% funcionando
void exibirProdutos(); //100% funcionando
int consultarIndiceProduto(int chave); //100% funcionando
int solicitarCodigo(); //100% funcionando
int consultarProduto(); //100% funcionando
//void excluirProduto();
void editarProduto(); //fazendo

//Protótipos das Funções de Cliente:
void inserirCliente();
void excluirCliente();
void consultarCliente();
void editarCliente();

//Protótipos das Funções de Venda:
void inserirVenda();
void excluirVenda();
void consultarVenda();
void editarVenda();

#endif
