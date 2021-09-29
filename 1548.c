#include <stdio.h>
#include <stdlib.h>


int main()
{
    int casosTeste,  * notasSala, *notasSalaAntigo,qtdAlunosSala, i, naoTrocaDeLugar;
     printf("Casos de teste>");
    scanf("%d", &casosTeste);

    i=0;
    while(i < casosTeste){
        naoTrocaDeLugar=0;
        printf("\nNumero de alunos na sala[%d]", (i+1));
        scanf("%d", &qtdAlunosSala);
        notasSala=(int*)malloc(sizeof(int)*qtdAlunosSala);
        notasSalaAntigo = (int*)malloc(sizeof(int)*qtdAlunosSala);

        for(int j=0; j< qtdAlunosSala; j++){
            printf("\nNota do aluno %d > ", (j+1));
            scanf("%d", &notasSala[j]);
            notasSalaAntigo[j] = notasSala[j];
        }

        printf("\nNotas da sala %d >", (i+1));
        for(int j = 0; j<qtdAlunosSala; j++){
            printf("[%d] ", notasSala[j]);
        }

        for(int x=0; x<qtdAlunosSala; x++){
            for(int y=0; y<qtdAlunosSala; y++){
                if(notasSala[x]>notasSala[y]){
                    int aux = notasSala[x];
                    notasSala[x] = notasSala[y];
                    notasSala[y] = aux;
                }
            }
        }
        naoTrocaDeLugar = 0;
        for(int x =0; x<qtdAlunosSala; x++){
            if(notasSala[x] == notasSalaAntigo[x]){
                naoTrocaDeLugar++;
            }
        }

        printf("\nNotas da sala %d organizado \n>", (i+1));
        for(int j = 0; j<qtdAlunosSala; j++){
            printf("[%d] ", notasSala[j]);
        }

        printf("\n Nao trocou de lugar = %d", naoTrocaDeLugar);
        i++;
    }

     return 0;
}

