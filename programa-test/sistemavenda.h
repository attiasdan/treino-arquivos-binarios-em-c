//#ifndef SISTEMAVENDA_H_INCLUDED
//#define SISTEMAVENDA_H_INCLUDED
//#endif

#define MAX_CLIENTE 100
#define MAX_PRODUTO 100
#define MAX_VENDA 100

const char *arqProdutos = "produtos.dat";
const char *arqClientes = "clientes.dat";
const char *arqVendas = "vendas.dat";

const char *arqIndiceProdutos = "indice_produtos.dat";
const char *arqIndiceClientes = "indice_clientes.dat";
const char *arqIndiceVendas = "indice_vendas.dat";

void menu();

//Prot�tipos das Fun��es de Produto:
void inserirProduto();
void excluirProduto();
void consultarProduto();
void editarProduto();
void exibirIndiceProdutos();
void exibirProdutos();

//Prot�tipos das Fun��es de Cliente:
void inserirCliente();
void excluirCliente();
void consultarCliente();
void editarCliente();

//Prot�tipos das Fun��es de Venda:
void inserirVenda();
void excluirVenda();
void consultarVenda();
void editarVenda();

void ordenar(); //ordenacao bolha

int tamanhoArquivo(const char *filename);

int consultaProduto(const char *filename, int chave);
