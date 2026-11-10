#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <pthread.h>

#define TOTAL_QUESTIONS 100

//
typedef struct player {
  int player_id;
  int score;
  // int multiplier;
  // int num_right_guesses;
  // int num_wrong_guesses;
  // int num_faster_buzzes;
} P;

// Uma pergunta é composta de id, enunciado (achar outro nome em inglês ou traduzir td para ptbr) e resposta;
typedef struct question {
  int question_id;
  char *enunciado;
  int answer;
} Q;

// Como será respondida apenas uma pergunta por vez, manteremos apenas uma struct alocada para a pergunta, que será desalocada somente quando o usuário fechar o jogo.
Q* init_question() {
  Q *question = (Q *)malloc(sizeof(Q));
  return question;
}

char *get_enunciado(int q_id);

int get_answer(int q_id);

// Gera um id aleatório que será o id da pergunta desta rodada.
void rand_question(Q* question) {
  int q_id = rand() % TOTAL_QUESTIONS;
  question->question_id = q_id;
  question->enunciado = get_enunciado(q_id);
  question->answer = get_answer(q_id);
}

// Região Crítica: apenas o usuário que apertou o buzzer primeiro pode acessar para tentativa de resposta.
bool answer_question(Q *question) {
  
  int answer;
  scanf("%d", &answer);

  if(answer == question->answer) {

  }
}

// Laço na thread de aguardar o sinal do buzzer dos jogadores.
void *await_signal(void *player_id) {
  int *p_id = (int *) player_id;
  

}

int main() {
  // printf("");
  pthread_t player1_buzzer;
  pthread_t player2_buzzer;
  P player1;
  P player2;

  pthread_create(player1_buzzer, NULL, await_signal, (void *) player1.player_id);
  pthread_create(player2_buzzer, NULL, await_signal, (void *) player2.player_id);

  return 0;
}