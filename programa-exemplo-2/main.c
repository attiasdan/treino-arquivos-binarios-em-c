/*Programa que lï¿½ dados do arquivo e imprime na tela
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[20];
	int idade;
	float nota;
} Aluno;

int main() {
	FILE *f;
	int n = 0;
	Aluno a;
	
	f = fopen("arq.dat","r");
	if(f==NULL){
		printf("\nNao foi possivel abrir o arquivo!\n");
		getchar();
		exit(0);
	}
	printf("\nEntrou\n");
	//ler os dados do arquivo e exibir na tela
	while(!feof(f)){
	
		fscanf(f,"%s\n",a.nome);
		fscanf(f,"%d\n",&a.idade);
		fscanf(f,"%f\n",&a.nota);
		
		//exibir na tela
		printf("Aluno %d\n",++n);
		printf("Nome: %s\n",a.nome);
		printf("Idade: %d\n",a.idade);
		printf("Nota: %.1f\n\n",a.nota);
	}
	getchar();
	return 0;
}


/*
int i = 0;
Aluno a[N];
FILE *f;

Aluno b;
int bufferTamNome[N];
int bufferTamEndereco[N];
int bufferTamCurso[N];
int n=0;
*/