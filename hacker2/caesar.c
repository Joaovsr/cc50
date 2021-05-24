#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cc50.h>
    int
main(int argc, char *argv[])
{
    int k = atoi(argv[1])%26;
    if (k <= 0){
	printf("Criptografia Falhou!\nTente novamente com outra chave.\n");
	return 1;
    }

    int buffer[1000];
    char filename[20];

    printf("Forneça o nome do arquivo\n");
    strcpy(filename, GetString());
    FILE* fp = fopen(filename, "rb");

    if (fp == NULL) {
	printf("Failed to open file '%s'\n", filename);
	return 2;
    }
    for (int i = 0; i < 1000; i++) {
	char rc = getc(fp);
	if (rc == EOF) {
	    buffer[i] = '\0';
	    break;
	}
	buffer[i] = rc;
    }
    // Após guardar frase no buffer fecha arquivo.
    fclose(fp);

    for (int i=0, c=0;buffer[i] != '\0'; i++){
	//tratamento letras maiusculas	
	if(buffer[i]>=65 && buffer[i]<=90)
	{
	    c = (buffer[i]+k)%90;
	    if (c<65)
		c+=64;
	    printf("%c",c);
	}else 
	    //tratamento letras minusculas
	    if(buffer[i]>=97 && buffer[i]<=122) 
	    {
		c = (buffer[i]+k)%122;		
		if (c<97)
		    c+=96;
		printf("%c",c);
	    }else
		printf("%c", buffer[i]);
    } 

    return 0;
}


