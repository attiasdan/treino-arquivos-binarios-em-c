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

//Protótipos das Funções de Produto:
void inserirProduto(); //funcionando parcialmente
void excluirProduto();
void consultarProduto();
void editarProduto();
void exibirIndiceProdutos();
void exibirProdutos(); //100% funcionando

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

void ordenar(); //ordenacao bolha

int tamanhoArquivo(const char *filename);

int consultaProduto(const char *filename, int chave);


#endif
