#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char placa[7];
	char modelo[30];
	char cor[30];
	int ano;
} Carro;

void gravaDados(Carro carros[100]) {
	int i;
	
	FILE *arquivo;
	
	if ((arquivo = fopen("carros1.dat", "w")) == NULL)
	{
		printf("Problemas na abertura do arquivo de carros para gravar!\n");
		exit(-1);
	}
	
	i = 0;
	
	while (i < 100 && strcmp(carros[i].placa, "fim") != 0)
	{
		if (fwrite(&(carros[i]), sizeof(Carro carro), 1, arquivo) == 0)
		{
			printf("Problemas na gravação no arquivo de carros!\n");
			exit(-1);
		}
		i++;
	}
	if (fclose(arquivo) != 0)
	{
		printf("Problemas no fechamento do arquivo de carros!\n");
		exit(-1);
	}
	void le_dados(Carro *carros)
	{
		int i;
		FILE *arquivo;
		Carro *carro;
		
		carro = (Carro *) malloc(sizeof(Carro));
		
		if (arquivo = fopen("carros.dat", "r") == NULL)
		{
			printf("Problemas na abertura do arquivo de carros para leitura!\n");
			exit(-1);
		}
		
		i = 0;
		
		while (i < 100 && !feof(arquivo))
		{
			if (ferror(arquivo))
			{
				printf("Problemas na leitura do arquivo de carros!\n");
				exit(-1);
			} else {
				carros[i].ano = carro->ano;
				strcpy(carros[i].placa, carro->placa);
				strcpy(carros[i].modelo, carro->modelo);
				strcpy(carros[i].cor, carro->cor);
			}
			i++;
			if (fclose(arquivo) != 0)
			{
				printf("Problemas de fechamento do arquivo de carros!\n");
				exit(-1);
			}
		}
	}
}
