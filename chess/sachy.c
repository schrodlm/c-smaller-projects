#include <stdio.h>



int main ( void ) {

    int pocet_poli;
    int velikost_pole;
    int pomocna_promenna = 0;
    int pomocna_promenna2 = 0;
    printf("%s\n", "Zadejte pocet poli:");
    if(scanf("%d", &pocet_poli) != 1 || pocet_poli <= 0)
    {
        printf("Nespravny vstup.\n");
        return 1;
    }
    printf("%s\n","Zadejte velikost pole:" );
    if(scanf("%d", &velikost_pole) != 1 || velikost_pole <= 0)
    {
        printf("Nespravny vstup.\n");
        return 1;
    }


printf("+");

for(int i = 0; i < pocet_poli * velikost_pole; i++){
    printf("-");
}
printf("+");
printf("\n");

for(int i = 0; i < pocet_poli; i++){
  
    
for(int i = 0; i < velikost_pole; i++){
printf("|");
pomocna_promenna = pomocna_promenna2;
for(int i = 0; i < pocet_poli; i++){
    pomocna_promenna ++;


    for(int i = 0; i < velikost_pole; i++)
    {     
        if(pomocna_promenna % 2 != 0)
        printf(" ");

        if(pomocna_promenna % 2 == 0)
        printf("X");
    }


}
printf("|");
printf("\n");
}
  pomocna_promenna2 ++;
}
printf("+");
for(int i = 0; i < pocet_poli * velikost_pole; i++){
    printf("-");
}
printf("+");
printf("\n");
return 0;
}