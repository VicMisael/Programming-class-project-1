
#include  "linha.h"
#include  "cidade.h"
#include  "interface.h"
#include  <stdlib.h>
#include  <stdio.h>
#include  <math.h>
#include  <time.h>

#ifdef _linux_
#define clear() system("cls")
#else
#define clear() system("clear")
#endif
int main(){
//Ideia basica vai ser criar o vetor de linhas na main,cada linha vai apontar pro inicio da rota
//Separando em funções fica mais interessante de se implementar aqui na main
//Vou adicionar todas as cidades que preciso na lista no main
  //Criar o vetor com cidades desencadeadas
  int o=1;
  //printf("Digite 1 para ler as cidades internas,2 para as externas:");
  //scanf("%d",&o);

  if(o==1){
    Cidade* listaCidades[12];
    listaCidades[0]=criarVarCidade("Fortaleza","Capital,Tem umas praia show,muito quente");
    listaCidades[1]=criarVarCidade("Quixada","TEm uma pedra show, muito quente");
    listaCidades[2]=criarVarCidade("Maranguape","Tem uma Serra, uns traficante");
    listaCidades[3]=criarVarCidade("Sobral","Quente,Terra do Ciro Gomes");
    listaCidades[4]=criarVarCidade("Guaramiranga","Suiça Cearense, Frio");
    listaCidades[5]=criarVarCidade("Pacoti","Frio, tem uns rios,e umas cachoeiras");
    listaCidades[6]=criarVarCidade("Tiangua","Serra,parece cidade colonial");
    listaCidades[7]=criarVarCidade("Cascavel","Tem a praia da Caponga");
    listaCidades[8]=criarVarCidade("Aquiraz","Tem o Beach Park");
    listaCidades[9]=criarVarCidade("Aracati","Tem umas praia show,muito quente");
    listaCidades[10]=criarVarCidade("Caninde","Cidade bem religiosa");
    listaCidades[11]=criarVarCidade("Paracuru","Tem um carnaval daora");
    
    //Testes
    // for(int i=0;i<12;i++){
    //   printf("Nome:%s \n",obtemNomeCidade(listaCidades[i]));
    //   printf("Descriçao:%s \n",obtemDescCidade(listaCidades[i]));

    // }
    Linha* ls[10];
    srand(time(NULL));
    for(int j=0;j<10;j++){
      ls[j]=criarLinha(copiarCidade(listaCidades[0]),rand()%23,15*(rand()%4),"Fretcar");
      
      for(int i=0;i<2+rand()%8;i++){
        adicionarCidade(ls[j],copiarCidade(listaCidades[1+rand()%11]));
      }
      
      printf("Empresa:%s \n",empresa(ls[j]));
      printf("Horario de chegada %d:%d \n",horaChegada(ls[j]),minutoChegada(ls[j]));
      Cidade* c=primeiraCidade(ls[j]);

      while(c!=NULL){
          printf("|Nome:%s |%s| \n",obtemNomeCidade(c),obtemDescCidade(c));
          c=obterProxima(c); 
      }
      
      printf("A última cidade da rota é:%s\n",cidadeFinalNome(ls[j]));
    }
    clear();
    inicializar(listaCidades,12,ls,10);
  }
  else if(o==2){
    FILE* cidades=fopen("cidades.txt","r");
    FILE* cidadesDes=fopen("desCidades.txt","r");

  }
}
