#include <stdio.h>

char Matrix[3][3];

typedef struct{
    char username[10];
    unsigned short points;
    unsigned short pos;
} Player;

void printMatrix()
{
    for(int i = 0; i < 3; i++){
        printf("{");
        for(int j = 0; j < 3; j++){
            printf("[%c]", Matrix[i][j]);
        }
        printf("}\n");
    }
}

void initMatrix()
{
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            Matrix[i][j] = ' ';
        }
    }  
}

int isFinished() // são 8 possíveis casos de vitória (2 diagonais e 4 lados e 2 meios) além  de dar velha
{
    short velha = 0;
    // lados
    for(int i = 0; i < 3; i++){
        if((Matrix[i][0] != ' ') && (Matrix[i][0] == Matrix[i][1]) && (Matrix[i][1]== Matrix[i][2])) return 1; 
    }
    // colunas
    for(int i = 0; i < 3; i++){
        if((Matrix[0][i] != ' ') && (Matrix[0][i] == Matrix[1][i]) && (Matrix[1][i] == Matrix[2][i])) return 1; 
    }
    // diagonais
    if((Matrix[2][0] != ' ') && (Matrix[2][0] == Matrix[1][1])&& (Matrix[1][1]== Matrix[0][2]))return 1; 
    if((Matrix[0][0] != ' ') && (Matrix[0][0] == Matrix[1][1]) && (Matrix[1][1]== Matrix[2][2]))return 1;

    // deu velha?
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(Matrix[i][j] != ' ') velha++;
        }
    }
    if(velha == 9) return 2;
    return 0;
}

void getPlayerMove(short player)
{
    int line, col, jog = 0;
    do{
        printf("Digite a linha e a coluna que deseja jogar: \n");
        scanf("%d %d", &line, &col);
        if(line > 3 || line < 0 || col > 3 || col < 0){
            printf("Digite um valor válido! \n");
        }
        else if(Matrix[line - 1][col - 1] != ' ') {
            printf("Você não pode jogar nesse lugar!\n");
        } else {
            Matrix[line - 1][col - 1] = player == 0 ? 'X' : 'O';
            jog = 1;
        }
    } while(!jog);
    
}

int main()
{
    short player = 0;
    char wantPlay;
    do{
        printf("=============\n");
        printf("Jogo da Velha\n");
        printf("=============\n");
        printf("Quer jogar? (y/n)");
        initMatrix();
        scanf("%c", &wantPlay);
        getchar();
        do{
            printMatrix();
            getPlayerMove(player);
            player = !player;
        }while(!isFinished());
        isFinished() == 1 ? printf("Player %d ganhou!\n", player) : printf("Deu velha!\n");
        printMatrix();

    } while(wantPlay == 'y');

    return 0;
}