#include <stdio.h>

#include <stdlib.h>
#include <cc50.h>
#include <time.h>

int main ()
{
	//seed do PRNG
	srand(time(NULL));

	//escolhe o número pseudo-aleatório entre [0,1023]
	int skittles = rand() % 1024;
	printf ("%d", skittles);

	int bet = 0;

	//números de apostas feitas
	int contBets = 1;

	printf ("Olá! Eu sou uma máquina de balas falante!\nAdivinhe quantos Skittles têm dentro de mim. Dica: Estou pensando em um número entre 0 e 1023. Qual é ele?\n:");

	bet = GetInt();

	while (skittles != bet ) {
		if (bet < skittles)
			printf("Haha! Tenho muito mais Skittles do que isso. Tente novamente.\n:");
		else
			printf("Não tente ser difícil... Adivinhe novamente\n:");
		
		bet = GetInt();
		contBets++;
	}
	
	printf("\n Certa Resposta (Voz Do Silvio Santos)\n");
	printf("Você precisou de %d apostas", contBets);
	return 0;
}

