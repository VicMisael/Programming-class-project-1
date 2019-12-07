#include <string.h>
#include <stdlib.h>
#include "cidade.h"
struct cidade{
  char* nome;
  char* descricao;
  Cidade* proximo;
  Cidade* anterior;
};

Cidade* criarVarCidade(char* nome,char* descricao){

  Cidade* cidade= (Cidade*) malloc(sizeof(Cidade));
  cidade->nome=(char*)malloc(sizeof(char));
  cidade->descricao=(char*)malloc(sizeof(char)*(strlen(descricao)+1));
  strcpy(cidade->nome,nome); 
  strcpy(cidade->descricao,descricao);
  cidade->proximo=NULL;
  cidade->anterior=NULL;
  return cidade;

}

void encadearCidade(Cidade* cidade,Cidade* cidadeE){
  cidade->proximo=cidadeE;
  cidadeE->anterior=cidade;  

}
void encadearNoFinal(Cidade* cidade,Cidade* add){
  if(cidade->proximo!=NULL){
      encadearNoFinal(cidade->proximo,add);  
  }else{
    encadearCidade(cidade,add);
  }

}

Cidade* obterProxima(Cidade* cidade){
return cidade->proximo;
}

Cidade* obterAnterior(Cidade* cidade){
return cidade->anterior;
}


char* obtemNomeCidade(Cidade* cidade){
  return cidade->nome;

}
char* obtemDescCidade(Cidade* cidade){
  return cidade->descricao;
}
Cidade* obterUltima(Cidade* cidade){
  if(cidade->proximo!=NULL){
    return obterUltima(cidade->proximo);
  }
  return cidade;
}
//Cria uma copia de uma cidade excluindo pra onde ela aponta
Cidade* copiarCidade(Cidade* cidade){
  Cidade* novaCidade= (Cidade*) malloc(sizeof(Cidade));
  novaCidade->nome=(char*)malloc(sizeof(char));
  novaCidade->descricao=(char*)malloc(sizeof(char)*(strlen(cidade->descricao)+1));
  strcpy(novaCidade->nome,cidade->nome); 
  strcpy(novaCidade->descricao,cidade->descricao);
  return novaCidade;

}