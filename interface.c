#include "cidade.h"
#include "linha.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#ifdef _linux_
#define clear() system("cls")
#else
#define clear() system("clear")
#endif

void toLowerString(char* string){
  for(int i=0;i<strlen(string);++i){
    string[i]=tolower(string[i]);
  }
  //return string;
}

int temEspaco(const char *input){
  int espacos=0;

  for (int i = 0; i<strlen(input); i++) {
    if (isspace((unsigned char) input[i])) {
      espacos++;
    }
  }
  return espacos;
}
void exibirCidade(Cidade* c){
  printf("Cidade:%s \n",obtemNomeCidade(c));
  printf("Descrição:%s\n",obtemDescCidade(c));
}
void navegarRotas(Cidade* cid){
  int q=1;
  char op;
  Cidade* ant=NULL;
  printf("Para navegar pelas rotas \n digite p para proximo a parar anteriror,s para sair:");
  while(q){  
    scanf("%c",&op);
    switch(tolower(op)){
      case'p':
     
        if(obterProxima(cid)==NULL){
          exibirCidade(cid);
          printf("Não há mais cidades\n");
        }else{
          exibirCidade(cid);
          cid=obterProxima(cid);
        }
      break;
      case 'a':
    
       if(cid==NULL){
          printf("Não há mais cidades\n");
        }else{
          exibirCidade(cid);
          cid=obterAnterior(cid);
        }
      break;
      case 's':
        q=0;
      break;
    }


  }
}
void mostrarDadosLinha(Linha* linha){
  printf("|%s| ",cidadeFinalNome(linha));
  printf("Horário de Chegada: %.2d:%.2d",horaChegada(linha),minutoChegada(linha));
  printf("\n");
}

void inicializar(Cidade** cidades,int csize,Linha** linhas,int lsize){

    printf("----------------------------------\n");
    printf("Bem vindo \n");
    printf("Lista de cidades disponíveis: \n");
    for(int i=0;i<lsize;i++){
      mostrarDadosLinha(linhas[i]);
    }
    char destino[45];
    printf("Digite o nome da cidade destino:");
    scanf("%s",destino);
   // printf("%s",destino);
    clear();
    int indices[10];
    printf("Rotas disponíveis: \n");
    int g=0;
    for(int i=0;i<lsize;i++){
      //(temEspaco(cidadeFinalNome(linhas[i])))
      if((!strcasecmp(cidadeFinalNome(linhas[i]),destino))){
        indices[g]=i;
        ++g;
        printf("%d:",g);
        mostrarDadosLinha(linhas[i]);
        
      }else if(temEspaco(cidadeFinalNome(linhas[i]))){
        if(!strncasecmp(cidadeFinalNome(linhas[i]),destino,strlen(destino))){
          indices[g]=i;
          ++g;
          printf("%d:",g);
          mostrarDadosLinha(linhas[i]);        
        }
      }
    }
    if(g==1){
      navegarRotas(primeiraCidade(linhas[indices[0]]));
      return;
    }else if(g>1){
      while(1){
        printf("Digite o número da rota desejada:");
        int d;
        scanf("%d",&d);
        if(d<=g){
          navegarRotas(primeiraCidade(linhas[indices[d-1]]));
          return;
        }else{
          printf("opção inválida");
        }
      }
    }else{
      printf("Opção inválida");
    }
    

}

