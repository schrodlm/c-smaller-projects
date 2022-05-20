#include <stdio.h>
#include <math.h>
int main ( void ){
    double x,y;
    double vysledek;
    char c, rovnaSe;

    printf("%s\n", "Zadejte vzorec:");
    if(scanf("%le %c %le %c", &x, &c, &y, &rovnaSe) != 4 || rovnaSe != '='){
        printf("%s\n", "Nespravny vstup.");
        return 1;
    }


    switch( c ){
        case '+':
        vysledek = (x+y);
        break;

        case '-':
        vysledek = (x-y);
        break;

        case '*':
        vysledek = (x*y);
        break;

        case '/':
        if(y == 0){
            printf("%s\n", "Nespravny vstup.");
            return 1;
        }
        vysledek = (x/y);
        if(vysledek < 0)
        vysledek = round(vysledek);
        else
        vysledek = floor(vysledek);
        printf("%.10lg\n", vysledek);
        return 0;
        break;

        default:
        printf("%s\n", "Nespravny vstup.");
        return 1;

}


    printf("%g\n", vysledek);
}