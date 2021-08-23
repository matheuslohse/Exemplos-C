// Jogo da Velha
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void JogaComputador(char t[3][3]){
    srand(time(NULL));
    int i, j;
    do{
        i = rand()%3;
        j = rand()%3;
    }while(t[i][j]!='.');
    t[i][j]= 'O';
}

void Inicializa(char t [3][3]){
    int i, j;
    for(i =0; i<3; i++){
        for(j =0; j<3; j++){
            t[i][j] = '.';
            }
    }
    printf("\n");
}

void Escreve(char t[3][3]){
    int i, j;
    char temp [3];
    printf("\nJogo da Velha\n\n");
    printf("  0 1 2\n");
    for(i=0; i<3;i++){
        printf("%i ",i);
        for(j=0; j<3;j++){
            temp[i] = t[i][j];
            printf("%c ",t[i][j]);
            }
        printf("\n");
    }
}

void JogaUsuario(char t[3][3]){
    int x, y;

    printf("\nInsira a linha:");
    scanf("%i", &x);

    while(x<0 || x>2){
        printf("\nERRO. VALOR INVALIDO.\nInsira a linha novamente:");
        scanf("%i", &x);
        }

    printf("\nInsira a coluna:");
    scanf("%i", &y);

    while(y>=3 || y<0){
        printf("\nERRO. VALOR INVALIDO.\nInsira a coluna novamente:");
        scanf("%i", &y);
        }

    while(t[x][y]!='.'){
        printf("\nErro. Digite um local valido.\nLinha: ");
        scanf("%i", &x);
        printf("\nColuna: ");
        scanf("%i", &y);
    }
    t[x][y] = 'X';
    printf("\n");
}

void FimJogo(char t[3][3]){
    char temp [3];

    for(int j=0;j<3;j++){
        for(int i=0;i<3;i++){
            temp[i] = t[i][j];
            printf("\n -> %c %f %f",&temp[i], &i, &j);
        }
        if(temp[1]==temp[2] && temp[2]==temp[3]){
            if(temp[1]=='X') printf("Parabens! Voce venceu!! :)");
            if(temp[1]=='O') printf("Que pena! Voce perdeu!! :(");
            break;
        }
    }
}

main(){
    char tabuleiro[3][3], temp[3];
    int cont, i = 0;

    Inicializa(tabuleiro);
    Escreve(tabuleiro);

    for(cont = 0; cont<=3; cont++){
        JogaUsuario(tabuleiro);
        Escreve(tabuleiro);
        JogaComputador(tabuleiro);
        Escreve(tabuleiro);
    }
}
