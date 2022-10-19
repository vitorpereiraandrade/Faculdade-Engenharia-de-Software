QUESTÃO 1
Um motorista de aplicativo recebeu uma corrida para realizar. A localização atual do motorista é representada a seguir pelo vértice número 1 (um) e a corrida está no vértice de número 5 (cinco). 

 

O grafo acima exibe todas as rotas para alcançar o destino a partir do ponto de partida. O destino da corrida é o vértice indicado pelo número 5 (cinco). As possíveis rotas são representadas pelos demais vértices que vão de 1 (um), que é a origem, a 4 (quatro).  

Desenvolva um algoritmo que ajude o motorista de aplicativo a tomar a melhor decisão de rota, pois devido ao aumento consecutivo do valor do combustível, o motorista quer uma estimativa de qual é a melhor rota até o destino da corrida. Para isso, foi feito um levantamento histórico do consumo médio das viagens passando por cada ponto de origem até o destino final.   

Na figura do grafo, os vértices 1, 2, 3, 4 e 5 representam, respectivamente as rotas em que o motorista deve passar para chegar ao destino. O trajeto é representado pelas arestas que liga (1 a 2), (1 a 3), (2 a 4), (2 a 5), e assim por diante. O consumo médio (peso) entre cada conexão está representado por X. Você deve substituir o X pelos 7 primeiros dígitos do seu RA (indo da esquerda para direita) multiplicado por 6,596, que é o valor do litro da gasolina nesse momento, na sequência: (1-2), (1-3), (2-4), (2-5), (3-2), (3-5), (4-5).   

  

Exemplo:   

  

RA 2045703-5 = Será utilizado os seguintes números do seu RA 2045703   

RA 204570-5 = Em caso de 6 dígitos, acrescentar o dígito 1 ao final 2045701   

  

(1-2) = 2 * 6,596 = 13,192 

(1-3) = 0 * 6,596 = 0 

(2-4) = 4 * 6,596 = 26,384 

......   

Utilize o algoritmo de Dijkstra para resolver o problema e informe o caminho de menor custo saindo de 1 (que é o ponto de partida da corrida) e chegando em 5 (que é o destino da corrida). O resultado do seu programa deverá indicar as rotas que poderão ser utilizadas pelo motorista e o seu respectivo peso.   

 

Passos para realizar o Mapa:   

 

1. Desenvolva um programa em linguagem C, salvar com a extensão (.c) que informe os caminhos saindo de 1 e chegando em 5.   

1.1. Neste código, usuário deverá excetuar as seguintes ações: 

   - informar o número de vértices (ponto de rota), 

   - informar as arestas com suas respectivas rotas de origem e destino, 

   - informar o custo correspondente ao seu RA para todas as rotas. 

1.2. Calcular rotas.   

1.3. Apresentar na tela todos os destinos com os seus respectivos pesos. 







//////////// Código em C //////////////////////////////

#include<stdio.h>
#define QTD 9999
#define MAX 5

void dijkstra(float G[MAX][MAX],int n,int inicial);

int main(){
  int i,j,u,l,p;
  float G[MAX][MAX];

  for(l=0 ;l < MAX; l++){
    for( p=0; p< MAX; p++){
      G[l][p] = -1;
    }
  }

  G[0][1]=13.192;
  G[0][2]=0;
  G[1][3]=6.596;
  G[1][4]=6.596;
  G[2][1]=59.364;
  G[2][4]=6.596;
  G[3][4]=13.192;

  for(l=0 ;l < MAX; l++){
    for( p=0; p< MAX; p++){
      printf("%.3f,",G[l][p]);
    }
    printf("\n");
  }

  printf("\nInforme o node inicial:");
  scanf("%d",&u);
  dijkstra(G,MAX,u-1);

  return 0;
}

void dijkstra(float G[MAX][MAX],int n,int inicial)
{
  float custo[n][n],distancia[n],pred[n],distanciamin;
  int visitado[n],cont,proxno,i,j;

  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      if(G[i][j]==-1)
        custo[i][j]=QTD;
      else
        custo[i][j]=G[i][j];

  for(i=0;i<n;i++){
    distancia[i]=custo[inicial][i];
    pred[i]=inicial;
    visitado[i]=0;
  }

  distancia[inicial]=0;
  visitado[inicial]=1;
  cont=1;

  while(cont<n-1){
    distanciamin=QTD;
    for(i=0;i<n;i++)
      if(distancia[i]<distanciamin&&!visitado[i]){
        distanciamin=distancia[i];
        proxno=i;
      }

    
    visitado[proxno]=1;
    for(i=0;i<n;i++){
      if(!visitado[i])
        if(distanciamin+custo[proxno][i]<distancia[i]){
          distancia[i]=distanciamin+custo[proxno][i];
          pred[i]=proxno;
        }
      }
      cont++;
    }

    
    for(i=0;i<n;i++)
      if(i!=inicial){
        printf("\nDistancia do no %d = %.3f",i,distancia[i]);
        printf("\nCaminho = %d",i);

        j=i;
        do{
          j=pred[j];
          printf("<-%d",j);
        }while(j!=inicial);
      }
}