/*
 * main.c
 *
 *  Created on: 09/04/2018
 *      Author: L�o
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ATTEMPTS 3;

int main(){
	printf("*****************************************\n");
	printf("*** Bem vindo ao Jogo de Adivinha��o! ***\n");
	printf("*****************************************\n");

	srand(time(0));
	int secret_number = rand() % 100;
	int guess;
	int hit;
	int i; //bug do Eclipse; lembrar de mudar a especifica��o para C99 ao inv�s de C89
	int bigger;
	//int win = 0;
	int attempts = 1;
	double score = 1000;
	double damage;

	//for (int i = 1; i <= 3; i++){
	  //for (i = 1; i <= /*ATTEMPTS*/ 3; i++){ //n�o usar constantes por enquanto, bug
	while(/*!win*/ 1){
		printf("Qual o seu %d� chute?", attempts, "\n");
		fflush(stdout); //forma de liberar o buffer do Eclipse
		scanf("%d", &guess);
		fflush(stdout);
		printf("Voc� chutou o n�mero %d!\n", guess);
		hit = guess == secret_number;
		bigger = guess > secret_number;
		if(guess < 0){
			printf("Voc� n�o pode chutar n�meros negativos!");
			//i--;
			continue;
		}

		//if (secret_number == guess){
		if (hit){
			printf("Parab�ns, voc� acertou!\n");
			printf("Jogue de novo, voc� � um bom jogador!\n");
			printf("Voc� fez %.2f pontos em %d tentativas! \n", score, attempts);
			break;
			//win = 1;
		}else if (bigger){
			printf("Que pena, voc� errou!\n");
			printf("Dica: seu n�mero foi maior que o n�mero secreto!\n");
		}else{
			printf("Que pena, voc� errou!\n");
			printf("Dica: seu n�mero foi menor que o n�mero secreto!\n");
		}

		damage = abs(guess - secret_number)/2.0;
		score = score - damage;
		attempts++;
	  }
	return 0;
	}
