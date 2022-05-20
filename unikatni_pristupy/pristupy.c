#include <stdio.h>
#include <stdlib.h>
#define MAX_POCET_UNIKATNICH_PRISTUPU 99'999
#define MAX_POCET_PRISTUPU 1'000'000


/*

Tato funkce funkce se spustí po zadání scanfu + x 
p_x = uzivatel, ktery se pripojil např. 12
pocet_pristupu max 99 999

*/


int navsteva(int* p_x, int* pocet_pristupu, int navsteva_array[], int pocet_navstev_uzivatele_array[], int uzivatele_postupne_array[]){

if(navsteva_array[*p_x] == *p_x)
{
    pocet_navstev_uzivatele_array[*p_x]+=1;
    printf("> navsteva #%d\n", pocet_navstev_uzivatele_array[*p_x]);
}
else
{
    navsteva_array[*p_x] = *p_x;
    pocet_navstev_uzivatele_array[*p_x]+=1;
    printf("> prvni navsteva\n");
}
uzivatele_postupne_array[*pocet_pristupu]=*p_x;
*pocet_pristupu = *pocet_pristupu + 1;

return 1;
}
//==========================================================//
/*
    Tato funkce se bere hodnoty from,to a předává pointer na pole uzivatele_postupne_array, které obsahuje vsechny dosud prihlasene id, 
    vytvoří dalsi pole, které se na kazdem spusteni funkce vynuluje. Pokud je fromTo_array[uzivatele_postupne_array[i]] != uzivatele_postupne_array[i], tak se tato hodnota
    pripise do fromTo_array a zaroven se pripocita pocet_unikatnich_uzivatelu. Pokud by se tato hodnota objevila znovu tak již neplatí podmínka 
    fromTo_array[uzivatele_postupne_array[i]] != uzivatele_postupne_array[i] a víme, že se jedná o duplicitní prvek, pole je inicializováno na {1,0}-> ,aby 0 byla také jedinečná hodnota
*/

int fromTo(int* p_from, int* p_to, int uzivatele_postupne_array[]){
    
int fromTo_array[MAX_POCET_UNIKATNICH_PRISTUPU+1] = {1,0};
int id_v_array = 0;
int pocet_unikatnich_uzivatelu_interval = 0;
    for(int i = *p_from; i <= *p_to; i++ )
    {
        if(fromTo_array[uzivatele_postupne_array[i]] != uzivatele_postupne_array[i])
        {
            pocet_unikatnich_uzivatelu_interval += 1;
            fromTo_array[uzivatele_postupne_array[i]] = uzivatele_postupne_array[i];
        }
        id_v_array ++;
    }
     
    printf("> %d / %d\n", pocet_unikatnich_uzivatelu_interval,id_v_array); 
    return 1;

}
//=====================================================================================

int failFunkce(void)
{
    printf("Nespravny vstup.\n");
    exit(1);
}

int main ( void ){

int navsteva_array[MAX_POCET_UNIKATNICH_PRISTUPU+1] = {1,0}; // tento array skladuje unikatni uzivatele - uzivatel 12 se ulozi do do navsteva_array[12]=12   +1 je pro /0 (ukoncovaci znak)
int pocet_navstev_uzivatele_array[MAX_POCET_UNIKATNICH_PRISTUPU+1] = {0}; // tento array skladuje kolikrat se unikatni uzivatel pripojil - pripejeni uzivatele 12 podruhy pocet_navstev_uzivatele_array_array[12] = 1
int uzivatele_postupne_array[MAX_POCET_PRISTUPU+1] = {0}; //tento array skladuje kolikrat se unikatni uzivatel pripojil, akorat postupne takze např. [20,21,37,20,9999,6000]
int pocet_pristupu = 0; // jelikoz je maximální pocet pripojení uživatelů 99 999 tak se scanf pro uzivatele spusti max 99 999x
int x=0, to=0; // x muze predstavovat hodnotu ID uzivatele, ale zároveň i hodnoty from
char c; // muze predstavovat '+' ci '?' a podle toho poznáme o jaký vstup se jedná
int scan;

    printf("Pozadavky:\n");
    
    while( !feof ( stdin )){

    scan = scanf(" %c %d", &c, &x);
            
        if (scan == -1)
            return 0;

        else if(scan != 2 || x < 0 || x > MAX_POCET_PRISTUPU || (pocet_pristupu+1 > MAX_POCET_PRISTUPU && c!='?'))
            failFunkce();

        // rozhodne o jaký vstup se jedná a jaké operace s ním provést
        else if( c == '+')
        {
            if (x > MAX_POCET_UNIKATNICH_PRISTUPU)
                failFunkce();
            navsteva(&x, &pocet_pristupu, navsteva_array, pocet_navstev_uzivatele_array, uzivatele_postupne_array);
        }
        // druhá možnost vstupu  
        else if (c == '?')
        {
            if(scanf("%d", &to) != 1 || to > MAX_POCET_PRISTUPU)//tady kontroluju jestli je from validni, nesmi byt vetsi nebo rovno poctu pristupu
                failFunkce();
            else if ( pocet_pristupu <= to ||  x > to)
                failFunkce();
            
            else
                fromTo(&x, &to, uzivatele_postupne_array);
        }

        else
        failFunkce();
    }
}