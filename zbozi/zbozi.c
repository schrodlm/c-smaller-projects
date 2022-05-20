#include <stdio.h>
#include <stdlib.h>
#include <string.h> //strcmp

typedef struct{
    char nazev_zbozi[100];
    int pocet_zbozi;
}TZbozi;

typedef struct{
    TZbozi * m_Data;
    int m_Count, m_Size;
}TPole;


//=============================FUNKCE============================//

/*
Tuto funkci vyuziji pro spatne zadany vstup. Exit programu.
*/
int failFunkce(TPole * pole)
{
    printf("Nespravny vstup.\n");
    free(pole->m_Data);
    exit(1);
}


int uniqueCheck(TPole pole[], TZbozi zbozi_value)
{
    int vysledek_porovnani;
    int duplikat_na_miste=-1;

    for( int i = 0; i <= pole->m_Count-1; i++) 
    {
    vysledek_porovnani = strcmp(pole->m_Data[i].nazev_zbozi, zbozi_value.nazev_zbozi); //porovnavám zbozi, které jsem zadal na stdin a vsechno zbozi ktere jiz mam ulozene v poli
        if (vysledek_porovnani == 0)//pokud je nazev zbozi identicky return hodnota strcmp je 0
        { 
            duplikat_na_miste = i; // kde se vyskytl duplikat s stdin
            break;  //muzu vystoupit z loopu protoze vim, ze duplikatu je max 1
        }
    }
    
    
    return duplikat_na_miste;
    
}

/*
Tato funkce pushuje nactene prvky ze zbozi, tedy char nazev_zbozi a int pocet_zbozi do m_Data - coz je 
pole ve strukture pole

Zaroveň tato funkce pole nafukuje exponenciálně pokud není v poli dost místa
*/

void pushDoPole(TPole pole[], TZbozi zbozi_value )
{
    zbozi_value.pocet_zbozi = 1;
    if(pole->m_Count >= pole->m_Size)
    {
        pole->m_Size = pole->m_Size * 2 + 4;
        pole->m_Data =(TZbozi *) realloc(pole->m_Data, pole->m_Size * sizeof(pole->m_Data[0]));
    } //tady se pole nafukuje - pokud je pocet prvku vetsi nez velikost pole, tak se pole zvetsi

    int duplikat_na_miste = uniqueCheck(pole, zbozi_value);
    if(duplikat_na_miste != -1) // duplikat je vzdy max 1, a situace muze nastat i takova ze se rovnaji na pozici pole->m_Data[0] - tudiz se duplikat_na_miste muze rovnat jakkymkoliv pozitivním hodnotam ( kdyz existuje kopie)
        pole->m_Data[duplikat_na_miste].pocet_zbozi = pole->m_Data[duplikat_na_miste].pocet_zbozi + 1;

    else
    {
    pole->m_Data[pole->m_Count] = zbozi_value; //prirazeni hodnoty zbozi do pole
    pole->m_Count++;
    }

}
/*

Tato funkce je soucasti sortCiselPole() -> aby funkce qsort() fungovala jak má tak potřebuje hodnoty 1,0,-1 
tyto hodnoty jí dodáme podle porovnání čísel v našem nafukovací poli m_Data

*/
int compareFunction(const TZbozi * leva, const TZbozi * prava)
{
    int data1 = leva->pocet_zbozi;
    int data2 = prava->pocet_zbozi;
    if(data1 > data2)
        return -1;
    else if (data1 == data2)
        return 0;
    else
        return 1;
}
/*
Tato funkce zesorti pole podle mnozstvi daneho zbozi
*/
void sortCiselPole(TPole * pole)
{
qsort(pole->m_Data, pole->m_Count, sizeof(pole->m_Data[0]), (int (*) (const void *, const void *)) compareFunction );
}



void printSledovanych(int pocet_sledovanych, TPole * pole, int typ)
{
    int poradi = 1;
    int celkove_zbozi = 0;
    int pocet_sledovanych_real = pocet_sledovanych;
    if(pole->m_Count < pocet_sledovanych)
        pocet_sledovanych_real = pole->m_Count;

    for(int i = 0; i < pocet_sledovanych_real; i++)
    {   
        
            
            if (i+1 <= pocet_sledovanych_real && pole->m_Data[i].pocet_zbozi == pole->m_Data[i+1].pocet_zbozi)
            {
                int j_first = poradi;
                int j_last = poradi;
                for(int j = i; pole->m_Data[j].pocet_zbozi == pole->m_Data[j+1].pocet_zbozi; j++ )
                    j_last++;
                if(typ == 1){
                for(int o = (j_first-1); o <= (j_last-1); o++)
                    printf("%d.-%d. %s, %dx\n", j_first, j_last, pole->m_Data[o].nazev_zbozi,pole->m_Data[o].pocet_zbozi);
                }
                i = i + (j_last - j_first);
                poradi = poradi + (j_last - j_first);
                celkove_zbozi += (j_last - j_first) * pole->m_Data[j_first].pocet_zbozi;
            }
            else{
           if (typ == 1) 
            printf("%d. %s, %dx\n", poradi, pole->m_Data[i].nazev_zbozi, pole->m_Data[i].pocet_zbozi);
            }
        poradi ++;
        celkove_zbozi += pole->m_Data[i].pocet_zbozi;
        
    }
    printf("Nejprodavanejsi zbozi: prodano %d kusu\n", celkove_zbozi);
}

int main ( void )
{
    TPole pole= {};
    TZbozi pomocna_zbozi={};
    char c,c2;
    int pocet_sledovanych;
    
    printf("Pocet sledovanych:\n");
    if(scanf("%d", &pocet_sledovanych) != 1 || pocet_sledovanych <= 0)
        failFunkce(&pole);

    printf("Pozadavky:\n");
    while (!feof (stdin))
    {
        if(scanf(" %c", &c) == EOF)
            break; //pokud zaznamename konec stdin, vyhodí nás to z while loopu

        if( c == '+')
        {
            if (scanf("%99s%c", pomocna_zbozi.nazev_zbozi, &c2) != 2 || c2 !='\n')
                failFunkce(&pole);
            pushDoPole(&pole,pomocna_zbozi);

        }
        else if(c == '?') //nejpodavanejsi zbozi
        {
            sortCiselPole(&pole);
            printSledovanych(pocet_sledovanych, &pole, 0);
            
        }
        else if(c == '#')
        {
            sortCiselPole(&pole);
            printSledovanych(pocet_sledovanych, &pole, 1);
        }
        else //selhani nacteni vstupu -> musím ukončit program a uvolnit pamět
        {
            failFunkce(&pole);
        }
    }

    // for( int i = 0; i < pole.m_Count; ++i)
    // {
    //     printf("%s\n%d\n",pole.m_Data[i].nazev_zbozi,pole.m_Data[i].pocet_zbozi );
    // }
    free(pole.m_Data);

    return 0;
}
