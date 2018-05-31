#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#define Ciclos 10
#define Slots 30
#define Pedras 2500
#define Sono 1
int main()
{
    FILE *fptr;
    int vet[Slots], vetMAX[Slots], i, k, q;
    float media, desvio, vari;

    // "limpando" os vetores
    for(i = 0; i < Slots; i++)
    {
        vetMAX[i] =0;
    }
    // Abrindo o arquivo onde vou gerar a "planilha"
    fptr = fopen("/home/joao/CLionProjects/DepositoAleatorio/teste.txt", "w");
    if (fptr == NULL) {
        printf("Arquivo nao existe! \n");
        return 0;
    }

    media = 0;
    desvio = 0;
    vari = 0;

    while(q < Ciclos) {

        // "limpando" os vetores
        for(i = 0; i < Slots; i++)
        {
            vet[i] = 0;
        }

        q++;

        srand(time(NULL));
        for (i = 0; i < Pedras; i++) {
            k = (rand() % Slots);
            sleep(Sono);
            vet[k] = vet[k] + 1;
        }

        for (i = 0; i < Slots; i++) {
            printf(" %i |", vet[i]);
            media = media + vet[i];
        }

        media = media / Slots;
        printf("\n Média: %.2f \n", media);

        fprintf(fptr,"\n");

        for (i = 0; i < Slots; i++) {
            fprintf(fptr, "%d ", vet[i]);
            vari = vari + (pow((vet[i] - media), 2));
        }

        vari = vari / Slots;
        desvio = (sqrt(vari));
        printf(" Desvio Padrao: %.2f \n", desvio);

        for (int i = 0; i < Slots; ++i) {
            vetMAX[i] = vetMAX[i] + vet[i];
        }
        printf("------------\n");
    }

    for (i = 0; i < Slots; i++) {
        printf("%d ", vetMAX[i]);
    }

    fclose(fptr);
    return 0;
}