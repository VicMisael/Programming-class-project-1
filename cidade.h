#include <string.h>
#include <stdlib.h>
typedef struct cidade Cidade;



//cria uma variavel do tipo cidade
Cidade* criarVarCidade(char* nome,char* descricao);

//Encadeia duas cidades
void encadearCidade(Cidade* cidade,Cidade* CidadeE);
//Encadea no final da lista
void encadearNoFinal(Cidade* cidade,Cidade* add);
//Obtem proxima cidade
Cidade* obterProxima(Cidade* cidade);
//Obtem a cidade anterior
Cidade* obterAnterior(Cidade* cidade);
//Obtem nome da cidade
char* obtemNomeCidade(Cidade* cidade);
//Obtem a descrição
char* obtemDescCidade(Cidade* cidade);
//Copia dados de um ponteiro de cidade para outro novo
Cidade* copiarCidade(Cidade* cidade);
