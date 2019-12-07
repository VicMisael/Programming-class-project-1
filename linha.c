#include "cidade.h"
#include "linha.h"

struct linha{
char empresa[16];
int hChegada;
int mChegada;
Cidade* primeira;
Cidade* ultima;

};
Linha* criarLinha(Cidade* cidade,int horarioH,int horarioM,char* empresa){
    Linha* l=(Linha*) malloc(sizeof(Linha));
    l->primeira=cidade;
    l->ultima=cidade;
    strcpy(l->empresa,empresa);
    l->hChegada=horarioH;
    l->mChegada=horarioM;
    return l;
}
//adiciona cidade a linha
void adicionarCidade(Linha* linha,Cidade* cidade){
    encadearNoFinal(linha->primeira,cidade);
    linha->ultima=cidade;
}
Cidade* primeiraCidade(Linha* linha){
  return linha->primeira;
}
Cidade* ultimaCidade(Linha* linha){
  return linha->ultima;
}
//retorna a ultima cidade da linha
char* cidadeFinalNome(Linha* linha){
    return obtemNomeCidade(linha->ultima);
}

int horaChegada(Linha* linha){
  return linha->hChegada;
}
int minutoChegada(Linha* linha){
  return linha->mChegada;
}
char* empresa(Linha* l){
  return l->empresa;
}

