#include <stdio.h>
#include <stdlib.h>

int compareFunction(const int *a, const int *b)
{
    return (*b - *a);
}

void kombinaceRekurze(int * array_velikosti,int * kombinace,int zacatek, int konec, int index, int velikost_kombinace, int **celkovy_pocet){

    //trivialni pripad
    if(index == velikost_kombinace)
    {
        for(int i = 0; i < velikost_kombinace; i++)
        if( i == 0 )
            printf("%d", kombinace[i]);
        else
            printf(", %d", kombinace[i]);
        printf("\n");
        **celkovy_pocet = **celkovy_pocet + 1;
        return;
    }
    //podproblemy
    for(int j = zacatek; j <= konec; j++)
    {   
        kombinace[index] = array_velikosti[j];
        kombinaceRekurze(array_velikosti, kombinace, j+1, konec, index+1, velikost_kombinace, celkovy_pocet);


        // toto se stará o duplikáty -> tedy když je array např [1,2,2,3,8]
        if(j+1 <= konec) // tohle je tu kvůli buffer overflow
        while (array_velikosti[j] == array_velikosti[j+1])
            j++;
    }

}

//============================================================================================================
void printKombinace(int * array_velikosti, int pocet_kostek, int velikost_kombinace, int *celkovy_pocet){

    int * kombinace;
    kombinace = (int*) malloc( pocet_kostek * sizeof(int));

    for(int i = 0; i < velikost_kombinace; velikost_kombinace--)
        kombinaceRekurze(array_velikosti, kombinace, 0, pocet_kostek-1, 0, velikost_kombinace, &celkovy_pocet);
    free(kombinace);
}

//=============================================================================================================
int main ( void ){

    int pocet_kostek;
    int * array_velikosti;
    int celkovy_pocet = 0;

    printf("Pocet kostek:\n");
    if(scanf("%d", &pocet_kostek) != 1 || pocet_kostek <= 0)
    {
        printf("Nespravny vstup.\n");
        exit(1);
    }
    int velikost_kombinace = pocet_kostek;

    array_velikosti = (int*) malloc( pocet_kostek * sizeof(int));
    printf("Velikosti:\n");
    
    for(int i = 0; i < pocet_kostek; i++)
        if(scanf("%d", &array_velikosti[i]) != 1 || array_velikosti[i] <= 0)
            {
                printf("Nespravny vstup.\n");
                free(array_velikosti);
                exit(1);
            }

    qsort((void *)array_velikosti, pocet_kostek, sizeof(array_velikosti[0]), (int (*) (const void *, const void *)) compareFunction );

    printKombinace(array_velikosti, pocet_kostek, velikost_kombinace, &celkovy_pocet);
    printf("Celkem: %d\n", celkovy_pocet);
    free (array_velikosti);
    
}