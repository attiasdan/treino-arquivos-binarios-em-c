/*Faça um programa em C que
1.Leia do usuário os seguintes dados de 10 pessoas: nome, idade, número de filhos
2.Escreva em um arquivo os dados lidos
3.Leia do arquivo os dados escritos*/

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

#include <stdio.h>
#include <stdlib.h>
#define N 1  //numero de alunos a serem cadastrados


// estrutura Aluno
typedef struct {
	char nome[20];
	int idade;
	float nota;
} Aluno;

int main() {
	int i;
	Aluno a[N];
	FILE *f;
	
	f = fopen("arq.dat","wt");
	
	if (f == NULL) {
		printf("\nNao foi possivel abrir o arquivo.");
		getchar();
		exit(0);
	}
	
	printf("Programa que le dados de %d alunos e armazena em um arquivo\n\n", N);
	for(i=0;i<N;i++){
		printf("Nome: ");
		scanf("%s",a[i].nome);
		printf("Idade: ");
		scanf("%d", &a[i].idade);
		printf("Nota: ");
		scanf("%f",&a[i].nota);
		printf("\n\n");
	}
	
	// conseguiu abrir o arquivo
	//gravar as informações de a no arquivo f
	for(i=0;i<N;i++){
		fprintf(f,"%s\n",a[i].nome);
		fprintf(f, "%d\n%f\n", a[i].idade,a[i].nota);
	}
	fclose(f);
	printf("\n\nDados registrados com sucesso!");
	getchar();
	return 0;
}
