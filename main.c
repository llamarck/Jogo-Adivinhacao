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
    printf("\n\n");
    printf("          P  /_\\  P                              \n");
    printf("         /_\\_|_|_/_\\                            \n");
    printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
    printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
    printf("    |\" \"  |  |_|  |\"  \" |                     \n");
    printf("    |_____| ' _ ' |_____|                         \n");
    printf("          \\__|_|__/                              \n");
    printf("\n\n");

	srand(time(0));
	int secret_number = rand() % 100;
	int guess;
	int hit;
	int i; //bug do Eclipse; lembrar de mudar a especificação para C99 ao invés de C89
	int bigger;
	//int win = 0;
	//int attempts = 1;
	double score = 1000;
	double damage;
	int level;
	int total_attempts;

	printf("Qual o nível de dificuldade?\n");
	fflush(stdout);
	printf("[1] Fácil [2] Normal [3] Difícil\n\n");
	fflush(stdout);
	printf("Escolha: \n");
	fflush(stdout);
	scanf("%d", &level);
	fflush(stdout);

	/*if(level == 1){
		total_attempts = 20;
	}else if(level == 2){
		total_attempts = 10;
	}else{
		total_attempts = 5;
	}*/

	switch(level){
		case 1:
			total_attempts = 20;
			break;
		case 2:
			total_attempts = 10;
			break;
		default:
			total_attempts = 5;
			break;
	}

	//for (int i = 1; i <= 3; i++){
	  for (i = 1; i <= /*ATTEMPTS*/ total_attempts; i++){ //não usar constantes por enquanto, bug
	//while(/*!win*/ 1){
		printf("Chute um número:\n");
		fflush(stdout); //forma de liberar o buffer do Eclipse
		scanf("%d", &guess);
		fflush(stdout);
		printf("Você chutou o número %d!\n", guess);
		hit = guess == secret_number;
		bigger = guess > secret_number;
		if(guess < 0){
			printf("Você não pode chutar números negativos!");
			i--;
			continue;
		}

		//if (secret_number == guess){
		if (hit){
			break;
			//win = 1;
		}else if (bigger){
			printf("ERROU!\n");
			printf("Dica: seu número foi maior que o número secreto!\n");
		}else{
			printf("ERROU!\n");
			printf("Dica: seu número foi menor que o número secreto!\n");
		}

		damage = abs(guess - secret_number)/2.0;
		score = score - damage;
		i++;
	  }
	  if(hit){
		  printf("             OOOOOOOOOOO               \n");
		  printf("         OOOOOOOOOOOOOOOOOOO           \n");
		  printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
		  printf("    OOOOOO      OOOOO      OOOOOO      \n");
		  printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
		  printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
		  printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
		  printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
		  printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
		  printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
		  printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
		  printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
		  printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
		  printf("         OOOOOO         OOOOOO         \n");
		  printf("             OOOOOOOOOOOO              \n");
		  printf("Parabéns, você ACERTOU!\n");
		  printf("Jogue de novo, você é um bom jogador!\n");
		  printf("Você fez %.2f pontos em %d tentativas! \n", score, i);
	  }else{
		  printf("       \\|/ ____ \\|/    \n");
		  printf("        @~/ ,. \\~@      \n");
		  printf("       /_( \\__/ )_\\    \n");
		  printf("          \\__U_/        \n");
		  printf("Game Over! Você perdeu, então tente novamente!\n");
		  printf("Você fez %2.f pontos. O número secreto era %d!\n", score, secret_number);
	  }
	return 0;
	}
