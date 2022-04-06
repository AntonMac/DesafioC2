// Antonio Macena

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
  int i, j, k, m, zumbi=15, obstaculo=19,bala=4, rick=0, saida=1;

  int rX, rY, sX, sY, vit=0;
  char cenario[10][10];

  time_t t;
  srand((unsigned) time(&t));
  
  //============================================<--Iniciando o terreno 10*10 com blocos vazios.
  for(i=0;i<10;i++){
    for(j=0;j<10;j++){
      cenario[i][j]='.';
    }
  }

  //============================================<---Distribuindo pesonagens e itens no terreno.
  while(saida>0){
    i = rand() % 10;
    j = rand() % 10;
    if(cenario[i][j]!='.'){continue;} //<--- Evitar sobrescrever campos não "vazios"
    if(rick<1){cenario[i][j]='R';rick++; rX=i; rY=j;continue;}                         
    if(zumbi>0&&(i>rX+1||i<rX-1)&&(j>rY+1||j<rY-1)){cenario[i][j]='z';zumbi--;continue;} //<--- "Z" para Zumbis
    if(obstaculo>0){cenario[i][j]='O';obstaculo--;continue;}   //<--- Pedras, Carros e Arvores representados por "O" de obstaculos.
    if(bala>0){cenario[i][j]='B';bala--;continue;}             //<--- "B" para balas
    if(i>=rX+6||j>=rY+6||i<=rX-6||j<=rY+6){cenario[i][j]='S';saida--, sX=i; sY=j;break;} // "S" para saida.
    
    
  }
  //==============================<---Casos de Cenario sem solução!
                                                       //Rick nos cantos com passagem bloqueado por obstaculos.
  if(rX==0&&rY==0&&cenario[0][1]=='O'&&cenario[1][0]=='O'){printf("\n\nRick acordou cercado por obstaculos e paredes!");vit=0; goto fim;}
  if(rX==0&&rY==9&&cenario[0][8]=='O'&&cenario[1][9]=='O'){printf("\n\nRick acordou cercado por obstaculos e paredes!");vit=0; goto fim;}
  if(rX==9&&rY==0&&cenario[8][0]=='O'&&cenario[9][1]=='O'){printf("\n\nRick acordou cercado por obstaculos e paredes!");vit=0; goto fim;}
  if(rX==9&&rY==9&&cenario[9][8]=='O'&&cenario[8][9]=='O'){printf("\n\nRick acordou cercado por obstaculos e paredes!");vit=0; goto fim;}

                                                      //Rick de costas para uma parede e rodeado por 3 obstaculos.
  if(rX==0&&cenario[rX+1][rY]=='O'&&cenario[rX][rY+1]=='O'&&cenario[rX][rY-1]=='O'){printf("\n\nRick acordou cercado por obstaculos e paredes!");vit=0; goto fim;}
  if(rX==9&&cenario[rX-1][rY]=='O'&&cenario[rX][rY+1]=='O'&&cenario[rX][rY-1]=='O'){printf("\n\nRick acordou cercado por obstaculos e paredes!");vit=0; goto fim;}
  if(rY==0&&cenario[rX][rY+1]=='O'&&cenario[rX+1][rY]=='O'&&cenario[rX-1][rY]=='O'){printf("\n\nRick acordou cercado por obstaculos e paredes!");vit=0; goto fim;}
  if(rY==9&&cenario[rX][rY-1]=='O'&&cenario[rX+1][rY]=='O'&&cenario[rX-1][rY]=='O'){printf("\n\nRick acordou cercado por obstaculos e paredes!");vit=0; goto fim;}
  
                                                      //Saida nos cantos com passagem bloqueado por obstaculos.
  if(sX==0&&sY==0&&cenario[0][1]=='O'&&cenario[1][0]=='O'){printf("\n\nA saida deste lugar rodeada por obstaculos e paredes!");vit=0; goto fim;}
  if(sX==0&&sY==9&&cenario[0][8]=='O'&&cenario[1][9]=='O'){printf("\n\nA saida deste lugar rodeada por obstaculos e paredes!");vit=0; goto fim;}
  if(sX==9&&sY==0&&cenario[8][0]=='O'&&cenario[9][1]=='O'){printf("\n\nA saida deste lugar rodeada por obstaculos e paredes!");vit=0; goto fim;}
  if(sX==9&&sY==9&&cenario[9][8]=='O'&&cenario[8][9]=='O'){printf("\n\nA saida deste lugar rodeada por obstaculos e paredes!");vit=0; goto fim;}
                                                      
                                                      //Saida em uma parede, bloqueada por 3 obstaculos.
  if(sX==0&&cenario[sX+1][sY]=='O'&&cenario[sX][sY+1]=='O'&&cenario[sX][sY-1]=='O'){printf("\n\nRick acordou cercado por obstaculos e paredes!");vit=0; goto fim;}
  if(sX==9&&cenario[sX-1][sY]=='O'&&cenario[sX][sY+1]=='O'&&cenario[sX][sY-1]=='O'){printf("\n\nRick acordou cercado por obstaculos e paredes!");vit=0; goto fim;}
  if(sY==0&&cenario[sX][sY+1]=='O'&&cenario[sX+1][sY]=='O'&&cenario[sX-1][sY]=='O'){printf("\n\nRick acordou cercado por obstaculos e paredes!");vit=0; goto fim;}
  if(sY==9&&cenario[sX][sY-1]=='O'&&cenario[sX+1][sY]=='O'&&cenario[sX-1][sY]=='O'){printf("\n\nRick acordou cercado por obstaculos e paredes!");vit=0; goto fim;}

  //================================<---- executando as rodadas.
  int rodadas=0, temp;
  char temp2;
  
  while(rick>0){
    //-------------------------Vizualização do mapa
    printf("\n");
    for(i=0;i<10;i++){
      for(j=0;j<10;j++){
        printf("\t%c",cenario[i][j]);
      }
      printf("\n\n");
    }
    printf("\n");
    //-----------------------
    printf("\n Rodada %i\n\n", rodadas);
    rodadas++;
    if(rodadas==1){printf("\nRick acordou Desorientado...Melhor Fugir Rick!\n");}
    
    error1:
    
    printf("\nPara onde ir? (W = Cima; S = Baixo; A = Esquerda; D = Direita)\n");
    scanf("%s", &temp2);
    getchar();
    if(temp2=='W'||temp2=='w'){temp=1;}if(temp2=='S'||temp2=='s'){temp=2;}if(temp2=='A'||temp2=='a'){temp=3;}if(temp2=='D'||temp2=='d'){temp=4;}
    //==========================================Movimentos para Rick======================================
    switch(temp){
      case 1:   if(rX-1<0){printf("\nMovimento Invalido, tem uma parede ai\n"); goto error1; break;}
                if(cenario[rX-1][rY]=='O'){printf("\nTem um obstaculo Ai, Rick vai ficar parado ate a proxima rodada\n"); break;}
                if(cenario[rX-1][rY]=='.'){cenario[rX-1][rY]='R';cenario[rX][rY]='.'; printf("\nAndou 1 metro para cima!\n");rX--; break;}
                if(cenario[rX-1][rY]=='B'){cenario[rX-1][rY]='R';cenario[rX][rY]='.';printf("\nAndou 1 metro para cima e achou uma bala, arma carregada!\n");rX--;bala++; break;}
                if(cenario[rX-1][rY]=='Z'&&bala>0){cenario[rX-1][rY]='R';cenario[rX][rY]='.'; printf("\nAndou 1 metro pra cima e Matou um Zumbi!\n");rX--;bala--; break;}
                if(cenario[rX-1][rY]=='Z'&&bala==0){cenario[rX][rY]='.'; printf("\nTem um Zumbi ai e Rick foi atacado!\n");rX--;rick=0; vit=0; goto fim; break;}
                if(cenario[rX-1][rY]=='S'){cenario[rX][rY]='.'; printf("\nRick Encontrou a Saida!\n");rX--;vit=1; goto fim; break;}
    
      case 2:   if(rX+1>9){printf("\nMovimento Invalido, tem uma parede ai\n"); goto error1; break;}
                if(cenario[rX+1][rY]=='O'){printf("\nTem um obstaculo Ai, Rick vai ficar parado ate a proxima rodada\n"); break;}
                if(cenario[rX+1][rY]=='.'){cenario[rX+1][rY]='R';cenario[rX][rY]='.'; printf("\nAndou 1 metro para baixo!\n");rX++; break;}
                if(cenario[rX+1][rY]=='B'){cenario[rX+1][rY]='R';cenario[rX][rY]='.'; printf("\nAndou 1 metro pra baixo e achou uma bala, arma carregada!\n");rX++;bala++; break;}
                if(cenario[rX+1][rY]=='Z'&&bala>0){cenario[rX+1][rY]='R'; cenario[rX][rY]='.'; printf("\nAndou 1 metro para baixo e Matou um Zumbi!\n");rX++;bala--; break;}
                if(cenario[rX+1][rY]=='Z'&&bala==0){cenario[rX][rY]='.';printf("\nTem um Zumbi ai e Rick foi atacado!\n");rX++;rick=0; vit=0; goto fim; break;}
                if(cenario[rX+1][rY]=='S'){cenario[rX][rY]='.'; printf("\nRick Encontrou a Saida!\n");rY++;vit=1; goto fim; break;}

      case 3:   if(rY-1<0){printf("\nMovimento Invalido, tem uma parede ai\n"); goto error1; break;}
                if(cenario[rX][rY-1]=='O'){printf("\nTem um obstaculo Ai, Rick vai ficar parado ate a proxima rodada\n"); break;}
                if(cenario[rX][rY-1]=='.'){cenario[rX][rY-1]='R';cenario[rX][rY]='.';printf("\nAndou 1 metro para esquerda!\n");rY--; break;}
                if(cenario[rX][rY-1]=='B'){cenario[rX][rY-1]='R';cenario[rX][rY]='.';printf("\nAndou 1 metro para esquerda e achou uma bala, arma carregada!\n");rY--;bala++; break;}
                if(cenario[rX][rY-1]=='Z'&&bala>0){cenario[rX][rY-1]='R';cenario[rX][rY]='.';printf("\nAndou 1 metro pra esquerda e Matou um Zumbi!\n");rY--;bala--; break;}
                if(cenario[rX][rY-1]=='Z'&&bala==0){cenario[rX][rY]='.';printf("\nTem um Zumbi ai e Rick foi atacado!\n");rY--;rick=0; vit=0; goto fim; break;}
                if(cenario[rX][rY-1]=='S'){cenario[rX][rY]='.';printf("\nRick Encontrou a Saida!\n");rY--;vit=1; goto fim; break;}
      
      case 4:   if(rY+1>9){printf("\nMovimento Invalido, tem uma parede ai\n"); goto error1; break;}
                if(cenario[rX][rY+1]=='O'){printf("\nTem um obstaculo Ai, Rick vai ficar parado ate a proxima rodada\n"); break;}
                if(cenario[rX][rY+1]=='.'){cenario[rX][rY+1]='R';cenario[rX][rY]='.'; printf("\nAndou 1 metro para direita!\n");rY++; break;}
                if(cenario[rX][rY+1]=='B'){cenario[rX][rY+1]='R';cenario[rX][rY]='.'; printf("\nAndou 1 metro para direita e achou uma bala, arma carregada!\n");rY++;bala++; break;}
                if(cenario[rX][rY+1]=='Z'&&bala>0){cenario[rX][rY+1]='R';cenario[rX][rY]='.';printf("\nAndou 1 metro para direita e Matou um Zumbi!\n");rY++;bala--; break;}
                if(cenario[rX][rY+1]=='Z'&&bala==0){cenario[rX][rY]='.';printf("\nTem um Zumbi ai e Rick foi atacado!\n");rY++;rick=0; vit=0; goto fim; break;}
                if(cenario[rX][rY+1]=='S'){printf("\nRick Encontrou a Saida!\n");rY++;vit=1; goto fim; break;}
      
      default: {printf("\nVoce digitou um comando invalido! tente de novo"); goto error1; break;}
    
    }
            //============================================Movimentos dos Zumbis.
            
          //Caso Zumbi esteja a 1 metros de Rick e Ataca.
    if(cenario[rX][rY+1]=='Z'&&bala>0){printf("\nRick foi atacado por um Zumbi e O Matou!"); cenario[rX][rY+1]='.';bala--;} // Zumbi 1 metro abaixo de Rick
    if(cenario[rX][rY+1]=='Z'&&bala==0){printf("\nRick foi atacado por um Zumbi!"); cenario[rX][rY+1]='.';cenario[rX][rY]='Z';rick=0; vit=0; goto fim;}
    if(cenario[rX][rY-1]=='Z'&&bala>0){printf("\nRick foi atacado por um Zumbi e O Matou!"); cenario[rX][rY-1]='.';bala--;} // Zumbi 1 metro acima de Rick
    if(cenario[rX][rY-1]=='Z'&&bala==0){printf("\nRick foi atacado por um Zumbi!"); cenario[rX][rY-1]='.';cenario[rX][rY]='Z';rick=0; vit=0; goto fim;}
    if(cenario[rX+1][rY]=='Z'&&bala>0){printf("\nRick foi atacado por um Zumbi e O Matou!"); cenario[rX+1][rY]='.';bala--;} // Zumbi 1 metro a direita de Rick
    if(cenario[rX+1][rY]=='Z'&&bala==0){printf("\nRick foi atacado por um Zumbi!"); cenario[rX+1][rY]='.';cenario[rX][rY]='Z';rick=0; vit=0; goto fim;}
    if(cenario[rX-1][rY]=='Z'&&bala>0){printf("\nRick foi atacado por um Zumbi e O Matou!"); cenario[rX-1][rY]='.';bala--;} // Zumbi 1 metro a esquerda de Rick
    if(cenario[rX-1][rY]=='Z'&&bala==0){printf("\nRick foi atacado por um Zumbi!"); cenario[rX-1][rY]='.';cenario[rX][rY]='Z';rick=0; vit=0; goto fim;}
            //Caso Zumbi esteja a 2 metros de Rick e exista um espaço vazio na direção de Rick.
    if(cenario[rX][rY+2]=='Z' &&  cenario[rX][rY+1]=='.'){cenario[rX][rY+2]='.';cenario[rX][rY+1]='Z';} // Zumbi 2 metros abaixo de Rick
    if(cenario[rX][rY-2]=='Z' &&  cenario[rX][rY-1]=='.'){cenario[rX][rY-2]='.';cenario[rX][rY-1]='Z';} // Zumbi 2 metros acima de Rick
    if(cenario[rX+2][rY]=='Z' &&  cenario[rX+1][rY]=='.'){cenario[rX+2][rY]='.';cenario[rX+1][rY]='Z';} // Zumbi 2 metros a direita de Rick
    if(cenario[rX-2][rY]=='Z' &&  cenario[rX-1][rY]=='.'){cenario[rX-2][rY]='.';cenario[rX-1][rY]='Z';} // Zumbi 2 metros a esquerda de Rick
          //Caso Zumbi esteja a 3 metros de Rick e exista um espaço vazio na direção de Rick.
    if(cenario[rX][rY+3]=='Z' &&  cenario[rX][rY+2]=='.'){cenario[rX][rY+3]='.';cenario[rX][rY+2]='Z';} // Zumbi 3 metros abaixo de Rick
    if(cenario[rX][rY-3]=='Z' &&  cenario[rX][rY-2]=='.'){cenario[rX][rY-3]='.';cenario[rX][rY-2]='Z';} // Zumbi 3 metros acima de Rick
    if(cenario[rX+3][rY]=='Z' &&  cenario[rX+2][rY]=='.'){cenario[rX+3][rY]='.';cenario[rX+2][rY]='Z';} // Zumbi 3 metros a direita de Rick
    if(cenario[rX-3][rY]=='Z' &&  cenario[rX-2][rY]=='.'){cenario[rX-3][rY]='.';cenario[rX-2][rY]='Z';} // Zumbi 3 metros a esquerda de Rick 
           
           
    }

    fim:
    	printf("\n");
    	for(i=0;i<10;i++){
			for(j=0;j<10;j++){
				printf("\t%c",cenario[i][j]);
			}
      		printf("\n\n");
		}
    	printf("\n");
  
  
  	if(vit==1){printf("\n\n\nRick Fugiu!");}
  	if(vit==0){printf("\n\n\nRick Morreu!");}
  
  return 0;
  }