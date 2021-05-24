#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crypt.h>
#define _XOPEN_SOURCE
#include <unistd.h>

#define FILENAME "list.txt"	// lista usada. Precisa estar na mesma pasta que o script

int
main(int argc, char *argv[])
{
    // Verifica se o usuario passou os parametros corretamente
    if (argc != 2){
	printf("Criptografia Falhou!\nTente novamente com outra chave.\n");
	return 1;
    }

    // Abrir arquivo e verificar se foi aberto.
    FILE*  fp = fopen(FILENAME, "rb");
    if(fp==NULL) {
	printf("Failed");
	return 1;
    }

    // Pega os dois primeiros digitos para ser usado como salt
    char setting[3]; 
    strncpy(setting, argv[1], 2);

    // loop para ler linha por linha do arquivo list.txt
    // Criptografa a linha e compara se Ã© igual ao input argv[1]
    // Caso ache a senha correspondente mostra na dela
    
    for (int i = 0; i < 120000000 ; i++){
    	char buff[20];	
	fgets(buff, 20, (FILE*)fp);	
	buff[strcspn(buff, "\n")] = 0;

//	printf("%s\n", buff);
	
	// Verifica se o fim do arquivo
	if (feof(fp)){
	    printf("Desculpe nÃo foi possivel crakear estÃ senha\n");
	    fclose (fp);
	    break;
	}
	// Se 
	if (strcmp(argv[1],crypt(buff,setting))==0){
	    printf("%s\n", buff);	
	    break;
	}
    }

    return 0;
}


