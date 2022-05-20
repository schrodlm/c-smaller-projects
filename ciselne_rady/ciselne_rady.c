#include <stdio.h>
#include<math.h>
#include<string.h>

int main ( void ){
int pozice,soustava,pocetVstupu;
int desetinna_mista=0;
int posun_po_cislech = 0;
int finalni_pozice = 0;
char ukazovatko = '^'; char mezery[20] = {0};

    printf("Pozice a soustava:\n");

    while( (pocetVstupu = scanf("%d %d", &pozice, &soustava)) == 2)
    {
        if( pozice < 0 || soustava > 36 || soustava < 2 )
        {
            printf("Nespravny vstup.\n");
            return 1;
        }
        for(int ciselna_soustava = 0; ciselna_soustava <= pozice; ciselna_soustava++ ){
        
        int temp = ciselna_soustava;
        desetinna_mista = 0;
        for( temp=ciselna_soustava; temp != 0; temp = temp/soustava){  //tento for cyklus resi pocet digitu v cisle podle soustavy ve které pracuji - soustavu oznacuje proměnna soustava
            desetinna_mista++;
        }
    
        posun_po_cislech += desetinna_mista;

        if(  pozice == posun_po_cislech || ((posun_po_cislech - pozice) <= (desetinna_mista-1) && (posun_po_cislech - pozice) > 0 )  ){ //tady dávám hodnotu finalni pozici
            finalni_pozice = ciselna_soustava;
            if(pozice != 0)
            strncpy(mezery, (char  *) "                   ", (desetinna_mista - (posun_po_cislech - pozice)-1) ); //nastavení ukazovatka, aby ukazovalo přesně na číslici

            printf("%d\n", finalni_pozice);
            printf("%s%c\n", mezery, ukazovatko);
            posun_po_cislech = 0;
            memset(mezery,0,strlen(mezery));
            break;

        }
    }
    }
    if (pocetVstupu != -1)
    {
         printf("Nespravny vstup.\n");
         return 1;
    }

    return 0;
}