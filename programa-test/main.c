#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>
#include "sistemavenda.h"

int main()
{
	system("color 0e"); //mudança nas cores do terminal
	system("title Trabalho de Arquivos Binarios - Disciplina Programacao 1"); //definicao do titulo da janela
    
	menu();

    return 0;
}
