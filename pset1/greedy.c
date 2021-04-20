#include <stdio.h>
#include <cc50.h>

int main ()
{
	int greedy;
	int contCoins = 0 , i =0;
//	int coins[] = {25,10,5,1};
// 	comente a linha acima e descomente essa para calcular também das notas	
	int coins[] = {10000,5000,2000,1000,500,200,100,50,10,5,25,1};

	int len = sizeof(coins)/sizeof(coins[0]);

	printf ("%d", len);

	printf("Olá! Quanto de troco você deve?");
	do{
	       	greedy= GetFloat() * 100;
		if (greedy <= 0)
			printf("Desculpe? Quanto você disse?\n");
	}while (greedy <= 0);

	for ( i=0; i<len; i++){

		if (greedy >= coins[i]){
			contCoins += greedy / coins[i];
			printf("%d moedas de %0.2f\n", greedy/coins[i], (float) coins[i]/100);
			greedy = greedy % coins[i];
		}
	}
	
	printf("Número de moedas necessárias: %d", contCoins);
	return 0;
}


