#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "set_log.h"
#include "api/API_net.h"

int main(int argc, char **argv){
	set_log("\n\nEXEC");
	bool isCaseInsensitive = false;
	int opt,i;
	char *entrada=NULL;
	char *rede=NULL;
	char *saida=NULL;
	char tmp[100];

	int numero_layers,*layers,atalhos,*func_ativ;
	while ((opt = getopt(argc, argv, "e:s:r:")) != -1) {
		switch (opt) {

			case 's':
				saida=optarg;
				printf("Nome do arquivo de saida: %s\n", saida);
				break;

			case 'e':
				entrada=optarg;
				printf("Nome do arquivo de entrada: %s\n", entrada);
				break;

			case 'r':
				rede=optarg;
				printf("Nome do arquivo da rede: %s\n", rede);
				break;
			default:
				fprintf(stderr, "%s \nparametros:\n-e arquivo de entrada\n-s arquivo de saida\n-r arquivo com a rede\n", argv[0]);
				exit(EXIT_FAILURE);
		}

	}
	if(opterr){
				fprintf(stderr, "%s \nparametros:\n-e arquivo de entrada\n-s arquivo de saida\n-r arquivo com a rede\n", argv[0]);
		exit(EXIT_FAILURE);

	}
	sprintf(tmp,"\narquivo de entrada %s",entrada);
	set_log(tmp);

	sprintf(tmp,"\narquivo de saida %s",saida);
	set_log(tmp);
	
	sprintf(tmp,"\narquivo de rede %s",rede);
	set_log(tmp);
	
	sprintf(tmp,"\n executando... ");
	set_log(tmp);
	
	exec_neural_net(entrada, load_neural_net_from_file(rede),saida);
	
	sprintf(tmp,"\nFIM EXEC\n ");
	set_log(tmp);
	free(entrada);
	entrada = NULL;
	free(saida);
	saida = NULL;
	free(rede);
	rede = NULL;

}

