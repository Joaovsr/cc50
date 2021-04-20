#include <stdio.h>
#include <cc50.h>

void printfchart(int produto, int total, char sentence[])
{
	
	int i, value, sizeScreen = 80;
	value = (produto*sizeScreen)/total;
	
	printf("%d", value);
	
	printf("%s\n", sentence);
	for (i=0; i <=value; i++)
	       printf("#");
	printf("\n");	
}

int main () 
{	
	int MF, FM, FF, MM, total;	
	printf("M procurando F: ");
	MF = GetInt();
	printf("F procurando M: ");
	FM = GetInt();
	printf("F procurando F: ");
	FF = GetInt();
	printf("M procurando M: ");
	MM = GetInt();
	
	total = MF+FM+FF+MM;
	
	printfchart(MF, total, "M procurando F");
	printfchart(FM, total, "F procurando M");
	printfchart(FF, total, "F procurando F");
	printfchart(MM, total, "M procurando M");
}


