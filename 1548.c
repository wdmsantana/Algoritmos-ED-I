#include <stdio.h>
#include <stdlib.h>


int main()
{
    int casosTeste,  * notasSala, *notasSalaAntigo,qtdAlunosSala, i, naoTrocaDeLugar;
    scanf("%d", &casosTeste);

    i=0;
    while(i < casosTeste){
        naoTrocaDeLugar=0;

        scanf("%d", &qtdAlunosSala);
        notasSala=(int*)malloc(sizeof(int)*qtdAlunosSala);
        notasSalaAntigo = (int*)malloc(sizeof(int)*qtdAlunosSala);

        for(int j=0; j< qtdAlunosSala; j++){
            scanf("%d", &notasSala[j]);
            notasSalaAntigo[j] = notasSala[j];
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
        printf("%d\n", naoTrocaDeLugar);
        i++;
    }

     return 0;
}
