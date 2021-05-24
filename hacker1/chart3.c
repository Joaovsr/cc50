#include <stdio.h>
#include <string.h>
#include <cc50.h>

void printfchart(int values[], char* names[], int size)
{
	int matriz [size][40];	
	int i, total=0, percentages[size];
	int lin, col;
	int numlin = size;
	int bigger = 0;

	//calculando total
	for(i=0; i< size; i++){
		total += values[i];
	}

	//formatando valores para porcentagens
	for(i=0; i<size; i++){
		printf("%s\t", names[i]);
		percentages[i] = (values[i]*40)/total;
		printf("%d\n", percentages[i]);
		if( percentages[i] > bigger ){
			bigger = percentages[lin];
		}	
	}
	
	for (lin=0; lin<numlin; lin++){
		for( col=0; col<40; col++){
			if(percentages[lin] > col){
				matriz[lin][col] = 1;
			}else{
				matriz[lin][col] = 0 ;
			}
		}

	}

	for (lin=0; lin<numlin; lin++){
		for (col=0; col<40; col++){
			printf("%d", matriz[lin][col]);
		}
		printf("\n");
	}
	
	for(col=39; col>0; col--){
		for (lin=0;lin<numlin; lin++){
			if(matriz[lin][col] == 1)
				printf("%s", "#");
			else	
				if ( matriz[lin][col] == 0)
		
				printf("%s", " ");
		}

		printf("\n");

	}
}

int main () 
{

	int values[4];
	char* names[4] = {"M-F","F-M", "F-F", "M-M" };

	printf("M procurando F: ");
	values[0] = GetInt();
	printf("F procurando M: ");
	values[1] = GetInt();
	printf("F procurando F: ");
	values[2] = GetInt();
	printf("M procurando M: ");
	values[3] = GetInt();

	printfchart(values, names, 4);
	return 0;
}

