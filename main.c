/*
 * main.c
 *
 *  Created on: 09/04/2018
 *      Author: L�o
 */

#include <stdio.h>

#define ATTEMPTS 3;

int main(){
	printf("*****************************************\n");
	printf("*** Bem vindo ao Jogo de Adivinha��o! ***\n");
	printf("*****************************************\n");

	int secret_number = 42;
	int guess;
	int hit;
	int i; //bug do Eclipse; lembrar de mudar a especifica��o para C99 ao inv�s de C89

	//for (int i = 1; i <= 3; i++){
	  for (i = 1; i <= /*ATTEMPTS*/ 3; i++){ //n�o usar constantes por enquanto, bug
		printf("Qual o seu %d� chute?", i, "\n");
		fflush(stdout); //forma de liberar o buffer do Eclipse
		scanf("%d", &guess);
		fflush(stdout);
		printf("Voc� chutou o n�mero %d!\n", guess);
		hit = guess == secret_number;

		//if (secret_number == guess){
		if (hit){
			printf("Parab�ns, voc� acertou!\n");
			printf("Jogue de novo, voc� � um bom jogador!\n");
			break;
		}else{
			int bigger = guess > secret_number;
			if (bigger){
				printf("Que pena, voc� errou!\n");
				printf("Dica: seu n�mero foi maior que o n�mero secreto!\n");
			}else{
				printf("Que pena, voc� errou!\n");
				printf("Dica: seu n�mero foi menor que o n�mero secreto!\n");
			}
		}
	}

	return 0;
}
