#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <crypt.h>
#define _XOPEN_SOURCE
#include <unistd.h>

int
main( int argc, char *argv[])
{
    // Verifica se o usuario passou os parametros corretamente
    if (argc != 3){
	printf("Erro!\nExemplo input: ./crack 50m2tb.6jehfA lista.txt\n");
	if (argc == 2) 
	    printf("Baixe uma lista em: https://wiki.skullsecurity.org/Passwords\n");
	return 1;

    }

    // Abrir arquivo e verificar se foi aberto.
    FILE*  fp = fopen(argv[2], "rb");
    if(fp==NULL) {
	printf("Failed");
	return 1;
    }

    // Pega os dois primeiros digitos para ser usado como salt
    char setting[3]; 
    strncpy(setting, argv[1], 2);

    // loop infinito para ler linha por linha do arquivo
    // caso chegue ao fim do arquivo retorn 1
    // Criptografa a linha e compara se √© igual ao input argv[1]
    // Caso ache a senha correspondente mostra na dela e retorna 0
    
    do{
    	char buff[20];	
	fgets(buff, 20, (FILE*)fp);	
	buff[strcspn(buff, "\n")] = 0;

	if ( strcmp(argv[1],crypt(buff,setting))==0 ){
	    printf("%s\n", buff);	
	    break;
	}else 
	    if ( feof(fp) ){    
    		printf("Desculpe n√o foi possivel crakear est√ senha\n");
    		return 1;
	    }
		
		    
    }while( 0 == 0);

    return 0;
}


