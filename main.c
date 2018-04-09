/*
 * main.c
 *
 *  Created on: 09/04/2018
 *      Author: Léo
 */

#include <stdio.h>

#define ATTEMPTS 3;

int main(){
	printf("*****************************************\n");
	printf("*** Bem vindo ao Jogo de Adivinhação! ***\n");
	printf("*****************************************\n");

	int secret_number = 42;
	int guess;
	int hit;
	int i; //bug do Eclipse; lembrar de mudar a especificação para C99 ao invés de C89

	//for (int i = 1; i <= 3; i++){
	  for (i = 1; i <= /*ATTEMPTS*/ 3; i++){ //não usar constantes por enquanto, bug
		printf("Qual o seu %dº chute?", i, "\n");
		fflush(stdout); //forma de liberar o buffer do Eclipse
		scanf("%d", &guess);
		fflush(stdout);
		printf("Você chutou o número %d!\n", guess);
		hit = guess == secret_number;

		//if (secret_number == guess){
		if (hit){
			printf("Parabéns, você acertou!\n");
			printf("Jogue de novo, você é um bom jogador!\n");
			break;
		}else{
			int bigger = guess > secret_number;
			if (bigger){
				printf("Que pena, você errou!\n");
				printf("Dica: seu número foi maior que o número secreto!\n");
			}else{
				printf("Que pena, você errou!\n");
				printf("Dica: seu número foi menor que o número secreto!\n");
			}
		}
	}

	return 0;
}
