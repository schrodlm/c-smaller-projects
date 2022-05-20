#include <stdio.h>

int main ( void ){
    int x,y,z;
    char c;
    printf ("%s\n", "Zadejte barvu v RGB formatu:" );
    if( scanf(" rgb ( %d , %d , %d %c", &x, &y, &z, &c) != 4 || x > 255 || x < 0 || y > 255 || y < 0 || z > 255 || z < 0 || c != ')'){ 
        printf("%s\n", "Nespravny vstup.");
        return 1;
    }

    printf("#%02X%02X%02X\n",x,y,z);
    }