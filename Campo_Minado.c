#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define TAM 6


void imprimir(char matriz_jogador[TAM][TAM]){
    for(int i = 0; i < TAM; i++){
            for(int j = 0; j < TAM; j++){
                printf("[%c]\t", matriz_jogador[i][j]);
            }
            printf("\n\n\n");
        }
}
void preencher(char matriz_jogador[TAM][TAM],int linha,int coluna, char gabarito[TAM][TAM]){
   for(int i = -1; i<=1; i++){
        for(int j = -1; j<=1; j++){
            if((i+linha)<0 || (i+linha)>=TAM || (j+coluna)<0 || (j+coluna)>=TAM){
                continue;
            }
            matriz_jogador[linha+i][coluna+j]=gabarito[linha+i][coluna+j];
        }
    }

}
void clique(char matriz_jogador[TAM][TAM],int linha,int coluna, char gabarito[TAM][TAM]){
    if(matriz_jogador[linha][coluna]=='-'){
        //preencher(matriz_jogador,linha,coluna,gabarito);
            for(int i = -1; i<2; i++){
                for(int j = -1; j<2; j++){
                    if(((i+linha)<0 || (i+linha)>=TAM || (j+coluna)<0 || (j+coluna)>=TAM)||(i==0 && j==0)){
                        continue;
                    }
                    if((gabarito[linha+i][coluna+j]=='-') && (matriz_jogador[linha+i][coluna+j] == ' ')){
                        matriz_jogador[linha+i][coluna+j]=gabarito[linha+i][coluna+j];
                        //imprimir(matriz_jogador);
                        clique(matriz_jogador,(linha+i) ,(coluna+j), gabarito);
                    }else{
                        matriz_jogador[linha+i][coluna+j]=gabarito[linha+i][coluna+j];
                        continue;
                    }
                }
            }
            return;
    } else{
        return;
    }
}
void bandeira(int linha_bandeira, int coluna_bandeira, char matriz_jogador[TAM][TAM]){

    printf("Digite o numero da linha: ");
    scanf("%d", &linha_bandeira);
    printf("Digite o numero da coluna: ");
    scanf("%d", &coluna_bandeira);

    linha_bandeira -= 1;
    coluna_bandeira -= 1;

    if(matriz_jogador[linha_bandeira][coluna_bandeira] == ' '){
        matriz_jogador[linha_bandeira][coluna_bandeira] = 'P';
    }
    else{
        printf("Posicao ja ocupada.");
        imprimir(matriz_jogador);
    }

}
void menu(){
    printf("+-----------------------------------------------+\n");
    printf("|              +-----------------+              |\n");
    printf("|              |      MENU       |              |\n");
    printf("|              +-----------------+              |\n");
    printf("|              +-----------------+              |\n");
    printf("|              |   1-JOGAR       |              |\n");
    printf("|              |                 |              |\n");
    printf("|              |   2-OPCOES      |              |\n");
    printf("|              |                 |              |\n");
    printf("|              |   3-CREDITOS    |              |\n");
    printf("|              |                 |              |\n");
    printf("|              |   4-ESTATISTICA |              |\n");
    printf("|              |                 |              |\n");
    printf("|              |   5-SAIR        |              |\n");
    printf("|              +-----------------+              |\n");
    printf("+-----------------------------------------------+\n\n");
}
int main(){
    
    menu();
    
    char gabarito[TAM][TAM];
    char matriz_jogador[TAM][TAM];
    int linha;
    int coluna;
    int bombas;
    int resposta_bandeira;
    int escolha;
    printf("O que deseja fazer: ");
    scanf("%d", &escolha);

    srand(time(NULL));

    //GERADOR DE BOMBAS
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            if(rand() % 10 > 8){
                gabarito[i][j] = '*';
            }
        }
    }
    //GERADOR DA MATRIZ DO JOGADOR
     for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            matriz_jogador[i][j] = ' ';
        }
    }
    //PRIMEIRA JOGADA
    printf("\n");
    imprimir(matriz_jogador);
    printf("Digite a linha: ");
    scanf("%d", &linha);
    linha-=1;
    printf("\nDigite a coluna: ");
    scanf("%d", &coluna);
    coluna-=1;
    gabarito[linha][coluna] = '-';
    matriz_jogador[linha][coluna] = gabarito[linha][coluna];
    for(int i = -2; i<=2; i++){
        for(int j = -2; j<=2; j++){
            if((i+linha)<0 || (i+linha)>=TAM || (j+coluna)<0 || (j+coluna)>=TAM){
                continue;
            }
            gabarito[linha+i][coluna+j]='-';
        }
    }
    //imprimir(gabarito)


    //GERADOR DOS NÚMEROS
    int i;
    for( i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            bombas =0;
            if(gabarito[i][j]=='*'){
                continue;
            }
            for(int k =-1; k<=1;k++){
                for(int l =-1; l<=1;l++){
                    if((l ==0 && k ==0) || (i+k)<0 || (i+k)>=TAM || (j+l)<0 || (j+l)>=TAM){
                        continue;
                    }
                    if(gabarito[i+k][j+l]=='*'){
                        bombas+=1;
                    }
                }
            }
            if(bombas==0){
                gabarito[i][j] = '-';
            } else{
                gabarito[i][j] = bombas+48; 
            }
        }
    }
    clique(matriz_jogador,linha ,coluna, gabarito);

    

    //JOGADAS
    do{
        printf("\n\n");
        imprimir(matriz_jogador);
        
       //pergunta se quer colocar bandeira
        while(1){
            printf("Deseja posicionar uma bandeira (1-Sim, 2-Nao): ");
            scanf("%d", &resposta_bandeira);
            if(resposta_bandeira == 1){
                bandeira(linha, coluna, matriz_jogador);
                break;
            }else if(resposta_bandeira == 2){
                break;
            }else{
                printf("Digite somente 1 ou 2: ");
                }
            }
        printf("\n\n");
        imprimir(matriz_jogador);

        printf("Digite a linha: ");
        scanf("%d", &linha);
        linha-=1;
        printf("\nDigite a coluna: ");
        scanf("%d", &coluna);
        coluna-=1;
        
        matriz_jogador[linha][coluna] = gabarito[linha][coluna];
        if(matriz_jogador[linha][coluna]=='*'){
            imprimir(matriz_jogador);
            printf("Perdeu!!!\n");
            imprimir(gabarito);
            break;    
        } else{
        matriz_jogador[linha][coluna] = gabarito[linha][coluna];
        clique(matriz_jogador,linha ,coluna, gabarito);
        }
        
    } while(1);
    return 0;
}
