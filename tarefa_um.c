#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int validate(){

    int val;
    char *buf = (char *) malloc(10);

    memset(buf,0,10);

    while(fgets(buf, 10, stdin) != NULL ){

            if(buf[0]!='\n') {

                val = atoi(buf);

                    break;
            }
    }

    free(buf);

    return val;
}

int verificar_Tamanho_Matriz(int linha){

    if((linha > 0) && (linha <= 6)){

        return 1;
    }
       return 0;
}


int gerar_Matriz(int LINHA){

    int matriz[LINHA][LINHA],min,flag;
    int pI = 0,pJ = 0;


    printf("\n\n\nInforme %d valores para a matriz:", (LINHA * LINHA));
    printf("\n--------------------------------\n");

    for(int i=0;i<LINHA;i++)
        {
            for(int j=0;j<LINHA;j++)
            {
                printf("Valor[%d][%d]: ",i,j);

                matriz[i][j] = validate();
        }
    }
    printf("\n\nSua Matriz Bidimensional:");
    printf("\n--------------------------------\n");

    min = matriz[0][0];

    for(int i=0;i < LINHA;i++)
        {
            for(int j=0; j< LINHA;j++)
            {
                printf("\t%d",matriz[i][j]);

            if(matriz[i][j] < min)
            {
                min = matriz[i][j];

                pI = i;
                pJ = j;
            }
        }
        printf("\n");
 }

 printf("\n O menor numero e %d e esta na posicao[%d][%d] \n\n",min,pI,pJ);

 return 0;

}

int main()
{
    int flag,linha;

    do{
        printf("Informe o tamanho da matriz:\n");
        printf("-------------------------------\n");

        printf("Linhas: ");
        linha = validate();


        if(verificar_Tamanho_Matriz(linha)== 1)
        {
            gerar_Matriz(linha);

        }else{

            printf("\nA Matriz deve ser quadrada de ate sexta ordem!\n");

            flag = 0;

        }

    }while(flag != 1);
}
