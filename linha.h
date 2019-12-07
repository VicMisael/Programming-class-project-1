#include "cidade.h"

typedef struct linha Linha;

//Cria a linha e retorna seu ponteiro 
//Sempre passar um ponteiro pra Fortaleza
Linha* criarLinha(Cidade* cidade,int horarioH,int horarioM,char* empresa);

//Adiciona uma cidade a rota
void adicionarCidade(Linha* linha,Cidade* cidade); 
//Retorna o ponteiro pra primeira cidade
Cidade* primeiraCidade(Linha* linha);
//Retorna um ponteiro pra ultima Cidade
Cidade* ultimaCidade(Linha* linha);
//Retorna o nome do destino final da linha;
char* cidadeFinalNome(Linha* linha);
//Retorna a hora de chegada
int horaChegada(Linha* linha);
//Retorna o minuto de chegada
int minutoChegada(Linha* linha);
//Retorna um ponteiro pro nome da empresa
char* empresa(Linha* l); 

