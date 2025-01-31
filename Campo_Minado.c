//VERSAO 1.0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void imprimir(int TAM,char matriz_jogador[TAM][TAM]){
    for(int i = 0; i<=TAM; i++ ){
        if(i>9){
            printf("%d ",i);
        } else{
        printf("%d  ",i);
        }
    }
    printf("\n");
    for(int i = 0; i < TAM; i++){
        if(i>=9){
           printf("%d",i+1); 
        } else{
            printf("%d ",i+1);
        }
            for(int j = 0; j < TAM; j++){
                printf("[%c]", matriz_jogador[i][j]);
            }
            printf("\n");
        }
}

void clique(int TAM,char matriz_jogador[TAM][TAM],int linha,int coluna, char gabarito[TAM][TAM], int *n_brancovet, int n_branco){
    if(matriz_jogador[linha][coluna]=='-'){
        //preencher(matriz_jogador,linha,coluna,gabarito);
            for(int i = -1; i<2; i++){
                for(int j = -1; j<2; j++){
                    if(((i+linha)<0 || (i+linha)>=TAM || (j+coluna)<0 || (j+coluna)>=TAM)||(i==0 && j==0)){
                        continue;
                    }
                    if((gabarito[linha+i][coluna+j]=='-') && (matriz_jogador[linha+i][coluna+j] == ' ')){
                        matriz_jogador[linha+i][coluna+j]=gabarito[linha+i][coluna+j];
                        *n_brancovet-=1;
                        //imprimir(matriz_jogador);
                        clique(TAM, matriz_jogador,(linha+i) ,(coluna+j), gabarito, &n_branco, n_branco);
                    }else{
                        matriz_jogador[linha+i][coluna+j]=gabarito[linha+i][coluna+j];
                        *n_brancovet-=1;
                        continue;
                    }
                }
            }
            return;
    } else{
        return;
    }
}

void bandeira(int TAM,char matriz_jogador[TAM][TAM],int linha,int coluna, char gabarito[TAM][TAM], int *n_bombas, int *n_branco){
    if(matriz_jogador[linha][coluna]==' '){
        matriz_jogador[linha][coluna]='P';
        *n_branco -=1;
        if(gabarito[linha][coluna]=='*'){
            *n_bombas-=1;
        } else{
            *n_bombas+=1;
        }
        if(gabarito[linha][coluna]=='*'){
            *n_bombas+=1;
        } else{
            *n_bombas-=1;
        }
    }
    //printf("\n Restam %d bombas e %d espacos em branco",*n_bombas,*n_branco);
}

void contador_bombas_brancos(int TAM,char matriz_jogador[TAM][TAM], int *n_branco){
    for(int i = 0; i<TAM; i++){
        for(int j = 0; j<TAM; j++){
             if(matriz_jogador[i][j]==' '){
                *n_branco+=1;
            }
        }
    }
}

void gerador_bombas(int TAM,char gabarito[TAM][TAM], int n_bombas){
    int linha, coluna;
    
    for(int i = 0; i < n_bombas; i++){
        
        linha = rand() % (TAM - 1);
        coluna = rand() % (TAM - 1);
        if(gabarito[linha][coluna] != '*' && gabarito[linha][coluna] != '-'){
            gabarito[linha][coluna] = '*';
        }
    }
}

void gerador_jogador(int TAM,char matriz_jogador[TAM][TAM]){
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            matriz_jogador[i][j] = ' ';
        }
    }
}

void gerador_numeros(int TAM,char gabarito[TAM][TAM]){
    int bombas = 0;
    for(int i = 0; i < TAM; i++){
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

void menu_opcoes(int *n_bombas){
    
    int opcao;

    printf("+-----------------------------------------------+\n");
    printf("|              +-----------------+              |\n");
    printf("|              |      MENU       |              |\n");
    printf("|              +-----------------+              |\n");
    printf("|              +-----------------+              |\n");
    printf("|              |  1-FACIL        |              |\n");
    printf("|              |                 |              |\n");
    printf("|              |  2-NORMAL       |              |\n");
    printf("|              |                 |              |\n");
    printf("|              |  3-DIFCIL       |              |\n");
    printf("|              |                 |              |\n");
    printf("|              |  4-MUITO DIFICIL|              |\n");
    printf("|              |                 |              |\n");
    printf("|              |  5-IMPOSSIVEL   |              |\n");
    printf("|              |                 |              |\n");
    printf("|              |  6-VOLTAR       |              |\n");
    printf("|              +-----------------+              |\n");
    printf("+-----------------------------------------------+\n\n\n");

    printf("Escolha a dificuldade: ");
    scanf("%d", &opcao);

    if(opcao == 1){
        *n_bombas = 10;
        printf("\nA dificuldade foi alterado para: Facil!\n\n");
    }else if(opcao  == 2){
        *n_bombas = 20;
        printf("\nA dificuldade foi alterado para: Normal!\n\n");
    }else if(opcao == 3){
        *n_bombas = 30;
        printf("\nA dificuldade foi alterado para: Dificil!\n\n");
    }else if(opcao == 4){
        *n_bombas = 45;
        printf("\nA dificuldade foi alterado para: Muito Dificil!\n\n");
    }else if(opcao == 5){
        *n_bombas = 70;
        printf("\nA dificuldade foi alterado para: IMPOSSIVEL!\n\n");
    }else{
        return;
    }
}

void menu_creditos(){
    int opcao;
    printf("+---------------------------------------+\n");
    printf("|                                       |\n");
    printf("|     Este programa foi criado por:     |\n");
    printf("|                  Neto                 |\n");
    printf("|                 Otavio                |\n");
    printf("|                                       |\n");
    printf("|           Obrigado por usar!          |\n");
    printf("|                                       |\n");
    printf("|               1-VOLTAR                |\n");
    printf("+---------------------------------------+\n\n\n");

    printf("Digite uma opcao: ");
    scanf("%d", &opcao);
    
    if(opcao == 1){
        return;
    }
}

int main(){
    int TAM = 10;
    char gabarito[TAM][TAM];
    char matriz_jogador[TAM][TAM];
    int linha, coluna;
    int n_bombas = 20, n_branco = 0;
    int escolha;
    char p_ou_x;

    while(1){
        menu();
        printf("O que deseja fazer? ");
        scanf("%d", &escolha);
        
        if(escolha == 1){
            srand(time(NULL));

            gerador_jogador(TAM,matriz_jogador);
            
            //PRIMEIRA JOGADA
            printf("\n");
            imprimir(TAM,matriz_jogador);
            printf("\nDigite a linha: ");
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

            gerador_bombas(TAM, gabarito, n_bombas);
            gerador_numeros(TAM,gabarito);
            
            clique(TAM,matriz_jogador,linha ,coluna, gabarito, &n_branco, n_branco);

            contador_bombas_brancos(TAM,matriz_jogador,&n_branco);

            //JOGADAS
            do{
                //imprimir(gabarito);
                printf("\n");
                imprimir(TAM,matriz_jogador);
                printf("Deseja colocar uma bandeira(P) ou marcar(X)? ");
                scanf(" %c", &p_ou_x);
                printf("\nDigite a linha: ");
                scanf("%d", &linha);
                linha-=1;
                printf("\nDigite a coluna: ");
                scanf("%d", &coluna);
                coluna-=1;
                if(linha<0 || coluna<0){
                    printf("\n Digite um índice válido!");
                    continue;
                } 
                if(p_ou_x=='p' || p_ou_x=='P'){
                    bandeira(TAM,matriz_jogador,linha ,coluna, gabarito, &n_bombas, &n_branco);
                } else if(p_ou_x=='x' || p_ou_x=='X'){
                matriz_jogador[linha][coluna] = gabarito[linha][coluna];
                    if(matriz_jogador[linha][coluna]=='*'){
                        imprimir(TAM,matriz_jogador);
                        printf("Perdeu!!!\n");
                        imprimir(TAM,gabarito);
                        break;    
                    } else{
                    matriz_jogador[linha][coluna] = gabarito[linha][coluna];
                    clique(TAM,matriz_jogador,linha ,coluna, gabarito, &n_branco, n_branco); 
                    }
                }
                if(n_bombas == 0){
                    printf("\n VOCE GANHOU!!!\n");
                    break;
                } else if(n_branco == 0){
                    printf("\n VOCE PERDEU!!! \n");
                    break;
                }
                //printf("\n Restam %d bombas e %d espacos em branco",n_bombas,n_branco);
                
            } while(1);

            
        }
        else if(escolha == 5){
            printf("\nAdeus...\n\n");
        }else if(escolha == 2){
            menu_opcoes(&n_bombas);
            continue;
        }else if(escolha == 3){
            menu_creditos();
            continue;
        }else{
            while (scanf("%d", &escolha) != 1){
                printf("DIGITE APENAS NUMEROS. Digite um numero para retornar: ");
                while(getchar() != '\n');
            }
            continue;
        }
        return 0;
    }
}
