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
#define EASY 20;
#define NORMAL 10;
#define HARD 5;

int main(){
	int play = 0;
	while(play == 0){
		printf("\n\n");
		printf("          P  /_\\  P                              \n");
		printf("         /_\\_|_|_/_\\                            \n");
		printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
		printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinha��o! \n");
		printf("    |\" \"  |  |_|  |\"  \" |                     \n");
		printf("    |_____| ' _ ' |_____|                         \n");
		printf("          \\__|_|__/                              \n");
		printf("\n\n\n");

		int begin_limit;
		int end_limit;
		printf("Determine o limite inicial do n�mero secreto: ");
		fflush(stdout);
		scanf("%d", &begin_limit);
		fflush(stdout);
		printf("Determine o limite final do n�mero secreto: ");
		fflush(stdout);
		scanf("%d", &end_limit);
		fflush(stdout);

		srand(begin_limit);
		int secret_number = rand() % end_limit;
		int guess;
		int hit;
		int i; //bug do Eclipse; lembrar de mudar a especifica��o para C99 ao inv�s de C89
		int bigger;
		//int win = 0;
		//int attempts = 1;
		double score = 1000;
		double damage;
		int level;
		int total_attempts;
		int last_number = NULL;

		printf("Qual o n�vel de dificuldade?\n");
		fflush(stdout);
		printf("[1] F�cil [2] Normal [3] Dif�cil\n\n");
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
				total_attempts = EASY;
				break;
			case 2:
				total_attempts = NORMAL;
				break;
			default:
				total_attempts = HARD;
				break;
		}

		//for (int i = 1; i <= 3; i++){
		  for (i = 1; i <= /*ATTEMPTS*/ total_attempts; i++){ //n�o usar constantes por enquanto, bug
		//while(/*!win*/ 1){
			printf("Chute um n�mero:\n");
			fflush(stdout); //forma de liberar o buffer do Eclipse
			scanf("%d", &guess);
			fflush(stdout);
			printf("Voc� chutou o n�mero %d!\n", guess);
			if(last_number != guess){
				last_number = guess;
			}else{
				printf("Voc� j� chutou este n�mero na �ltima tentativa!");
				i--;
				continue;
			}
			hit = guess == secret_number;
			bigger = guess > secret_number;
			if(guess < 0){
				printf("Voc� n�o pode chutar n�meros negativos!");
				i--;
				continue;
			}

			//if (secret_number == guess){
			if (hit){
				break;
				//win = 1;
			}else if (bigger){
				printf("ERROU!\n");
				printf("Dica: seu n�mero foi maior que o n�mero secreto!\n");
			}else{
				printf("ERROU!\n");
				printf("Dica: seu n�mero foi menor que o n�mero secreto!\n");
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
			  printf("Parab�ns, voc� ACERTOU!\n");
			  printf("Jogue de novo, voc� � um bom jogador!\n");
			  printf("Voc� fez %.2f pontos em %d tentativas! \n", score, i);
			  printf("Deseja jogar novamente?");
			  fflush(stdout);
			  printf("Sim(1)  N�o(0)\n");
			  fflush(stdout);
			  scanf("%d", &play);
		  }else{
			  printf("       \\|/ ____ \\|/    \n");
			  printf("        @~/ ,. \\~@      \n");
			  printf("       /_( \\__/ )_\\    \n");
			  printf("          \\__U_/        \n");
			  printf("Game Over! Voc� perdeu, ent�o tente novamente!\n");
			  printf("Voc� fez %2.f pontos. O n�mero secreto era %d!\n", score, secret_number);
			  printf("Deseja jogar novamente?\n");
			  fflush(stdout);
			  printf("Sim(1)  N�o(0)\n");
			  fflush(stdout);
			  scanf("%d", &play);
		  }
		}
		return 0;
	}
