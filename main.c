/*
 * main.c
 *
 *  Created on: 09/04/2018
 *      Author: Léo
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ATTEMPTS 3;

int main(){
	printf("*****************************************\n");
	printf("*** Bem vindo ao Jogo de Adivinhação! ***\n");
	printf("*****************************************\n");

	srand(time(0));
	int secret_number = rand() % 100;
	int guess;
	int hit;
	int i; //bug do Eclipse; lembrar de mudar a especificação para C99 ao invés de C89
	int bigger;
	//int win = 0;
	int attempts = 1;
	double score = 1000;
	double damage;

	//for (int i = 1; i <= 3; i++){
	  //for (i = 1; i <= /*ATTEMPTS*/ 3; i++){ //não usar constantes por enquanto, bug
	while(/*!win*/ 1){
		printf("Qual o seu %dº chute?", attempts, "\n");
		fflush(stdout); //forma de liberar o buffer do Eclipse
		scanf("%d", &guess);
		fflush(stdout);
		printf("Você chutou o número %d!\n", guess);
		hit = guess == secret_number;
		bigger = guess > secret_number;
		if(guess < 0){
			printf("Você não pode chutar números negativos!");
			//i--;
			continue;
		}

		//if (secret_number == guess){
		if (hit){
			printf("Parabéns, você acertou!\n");
			printf("Jogue de novo, você é um bom jogador!\n");
			printf("Você fez %.2f pontos em %d tentativas! \n", score, attempts);
			break;
			//win = 1;
		}else if (bigger){
			printf("Que pena, você errou!\n");
			printf("Dica: seu número foi maior que o número secreto!\n");
		}else{
			printf("Que pena, você errou!\n");
			printf("Dica: seu número foi menor que o número secreto!\n");
		}

		damage = abs(guess - secret_number)/2.0;
		score = score - damage;
		attempts++;
	  }
	return 0;
	}
