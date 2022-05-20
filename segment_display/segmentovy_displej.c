#ifndef __PROGTEST__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#endif /* __PROGTEST__ */


/* 

Tato funkce počítá celkový počet dní od datumu 1.1.1600 - referencni rok 
do datumu, specifikovaného ve funkci energyConsumption

*/
int pocetDni ( int * p_year, int * p_month, int * p_day){
    if ( *p_year <= 1600 || *p_month > 12 || *p_month < 0) return -1;

int rok_reference = 1600;

int pocet_prestupnich_dni = 0;


//tato promenna slouzi k urceni poctu dni v unoru roku p_year
int unor_pyear;

/* Zde kontroluji zda se jedná o přestupný rok či nikoliv */
    if ((*p_year % 4 == 0 && *p_year % 100 != 0) || (*p_year % 400 == 0 && *p_year % 4000 != 0))
    {
        unor_pyear = 29;
    }
    else
    {
        unor_pyear = 28;
    }

int dny_v_mesicich[12]={31,unor_pyear,31,30,31,30,31,31,30,31,30,31};

if(*p_day > dny_v_mesicich[*p_month - 1] || *p_day < 0) return -1;

//tato proměnná bude mít hodnotu dní podle mesice, ktery byl zadan v *p_month -> kdyz *p_month == 2 -> 31 + 28 (nebo 29)
int pocet_dni_v_mesicich = 0;

int rozdil_roku1 = *p_year - rok_reference;


//tento cyklus pocita rozdil v letech 1600 až p_year - 1
for(int i = rok_reference; i < *p_year; i++)
{

    if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0 && i % 4000 != 0)){
        pocet_prestupnich_dni += 1;
    }
}


for(int j = 0; j < *p_month-1; j++)
{
pocet_dni_v_mesicich += dny_v_mesicich[j];
}

int celkovy_pocet_dni = rozdil_roku1 * 365 + pocet_prestupnich_dni + pocet_dni_v_mesicich + *p_day;


    return celkovy_pocet_dni;
}
/*
================================================================================
*/


/*
Krátka funkce na výpočet celkového počtu sekund

*/

int celkovyPocetSekund(int * p_celkovy_pocet_dni, int * p_pocet_hodin, int * p_pocet_minut )
{
int celkovy_pocet_sekund = (*p_celkovy_pocet_dni * 24 * 3600) + (*p_pocet_hodin*3600) + (*p_pocet_minut*60);
return celkovy_pocet_sekund;
}
/*
================================================================================
*/



/*
Funkce na výpočet energie
*/

int vypocetEnergie( long long int * p_rozdil_sekund, int * starting_point_hodin, int * starting_point_minut){


    int rozdil_minut = (*p_rozdil_sekund)/60+*starting_point_minut;
    int rozdil_hodin = rozdil_minut/60;
    long long int energie = 0;
    int list_sekundy[10]={2,4,5,2,3,3,1,5,4,1};
    int list_desitky_sekund[6]={3,4,5,2,3,3};
    int list_desitky_hodin[3]={3,4,5};
    int list_hodiny[24]={3,4,5,2,3,3,1,5,4,1,2,4,5,2,3,3,1,5,4,1,2,4,5,2};  



//sekundy
int pomocna_sekundy = 0;
int pomocna_desitky_sekund = 0;   
   

int pocet_nasobeni = *p_rozdil_sekund/10;
 energie += pocet_nasobeni * 30;

    
    for(int i=0; i < *p_rozdil_sekund%10; i++){
        
        pomocna_sekundy++;

        energie += list_sekundy[pomocna_sekundy];

    }

    int rozdil_desitky_sekund = *p_rozdil_sekund/10;
    energie += rozdil_desitky_sekund/6 * 20;
    int zbytek = rozdil_desitky_sekund - (rozdil_desitky_sekund/6 * 6);
    
    for(int i=0; i < zbytek%6; i++){
       pomocna_desitky_sekund++;
        energie+=list_desitky_sekund[pomocna_desitky_sekund];
    }


//minuty

int pomocna_minuty = 0;
int pomocna_desitky_minut = 0;   
   

int pocet_nasobeni_minuty = (rozdil_minut)/10;
 energie += pocet_nasobeni_minuty * 30;

    
    for(int i=0; i < (rozdil_minut)%10; i++){
        
        pomocna_minuty++;
        energie += list_sekundy[pomocna_minuty];
        }
    // desitky minut
    int rozdil_desitky_minut = (rozdil_minut)/10;
    energie += rozdil_desitky_minut/6 * 20;
    int zbytek_minuty = rozdil_desitky_minut - (rozdil_desitky_minut/6 * 6);
    
    for(int i=0; i < zbytek_minuty%6; i++){
       pomocna_desitky_minut++;
        energie+=list_desitky_sekund[pomocna_desitky_minut];
    }


//TOHLE JE PRO STARTING POINT MINUT

if(starting_point_minut != 0){
int pomocna_minuty_sp = 0;
int pomocna_desitky_minut_sp = 0;   
   

int pocet_nasobeni_minuty_sp = *starting_point_minut/10;
 energie -= pocet_nasobeni_minuty_sp * 30;

    
    for(int i=0; i < *starting_point_minut%10; i++){
        
        pomocna_minuty_sp++;
        energie -= list_sekundy[pomocna_minuty_sp];

        }
    // desitky sekund
    int rozdil_desitky_minut_sp = *starting_point_minut/10;
    energie -= rozdil_desitky_minut_sp/6 * 20;
    int zbytek_minuty_sp = rozdil_desitky_minut_sp - (rozdil_desitky_minut_sp/6 * 6);
    
    for(int i=0; i < zbytek_minuty_sp%6; i++){
       pomocna_desitky_minut_sp++;
        energie-=list_desitky_sekund[pomocna_desitky_minut_sp];
    }
}

int pomocna_hodiny = 0;
int pomocna_desitky_hodin = 0;  
//desitky hodin


   int pocet_nasobeni_hodiny = (rozdil_hodin+*starting_point_hodin) / 24 ;
   int zbytek_hodin = (rozdil_hodin+*starting_point_hodin) - (pocet_nasobeni_hodiny * 24);
   energie +=  (pocet_nasobeni_hodiny * 74);

    for(int i=0; i < zbytek_hodin; i++){
        pomocna_hodiny++;
        energie += list_hodiny[pomocna_hodiny];
    }
    // desitky hodin
    int rozdil_desitky_hodin = (rozdil_hodin+*starting_point_hodin)/24;
    energie += (rozdil_desitky_hodin * 12);
    int zbytek_desitek_hodin = zbytek_hodin/10; 
    
    for(int i=0; i < zbytek_desitek_hodin; i++){
       pomocna_desitky_hodin++;
        energie+=list_desitky_hodin[pomocna_desitky_hodin];
    }
    //TOHLE JE PRO STARTING POINT HODIN

if(starting_point_hodin != 0){
int pomocna_hodiny_sp = 0;
int pomocna_desitky_hodin_sp = 0;   
   

int pocet_nasobeni_hodiny_sp = *starting_point_hodin/24;
 energie -= pocet_nasobeni_hodiny_sp * 74;

    
    for(int i=0; i < *starting_point_hodin%24; i++){
        
        pomocna_hodiny_sp++;
        energie -= list_hodiny[pomocna_hodiny_sp];

        }
    // desitky hodin
    int rozdil_desitky_hodin_sp = *starting_point_hodin/24;
    energie -= rozdil_desitky_hodin_sp * 12;
    int zbytek_hodiny_sp = *starting_point_hodin;
    
    for(int i=0; i < zbytek_hodiny_sp/10; i++){
       pomocna_desitky_hodin_sp++;
        energie-=list_desitky_hodin[pomocna_desitky_hodin_sp];
    }
}
    

return energie;
}

/*
=================================================================================
*/



int energyConsumption ( int y1, int m1, int d1, int h1, int i1,
                        int y2, int m2, int d2, int h2, int i2, 
                        long long int * consumption )
{
    if( h1 > 23 || h1 < 0 || i1 > 59 || i1 < 0) return 0;
    if( h2 > 23 || h2 < 0 || i2 > 59 || i2 < 0) return 0;

    //voláme funkci pocetDni(), která nám vráti počet celkových dni od referencniho roku
    int celkovy_pocet_dni_1 = pocetDni(&y1, &m1, &d1);
    if(celkovy_pocet_dni_1 == -1)return 0;
    int celkovy_pocet_dni_2 =pocetDni(&y2, &m2, &d2);
    if(celkovy_pocet_dni_2 == -1)return 0;

    //pocita celkovy pocet sekund - dny + hodiny + minuty
    long long int celkovy_pocet_sekund_1 = celkovyPocetSekund(&celkovy_pocet_dni_1, &h1, &i1);
    long long int celkovy_pocet_sekund_2 = celkovyPocetSekund(&celkovy_pocet_dni_2, &h2, &i2);
    
    long long int rozdil_sekund = celkovy_pocet_sekund_2 - celkovy_pocet_sekund_1;
    printf("rozdil_sekund = %lld\n", rozdil_sekund);
    if ( rozdil_sekund < 0) return 0;
    *consumption = vypocetEnergie(&rozdil_sekund, &h1, &i1); //dodávám do funkce celkový rozdíl času, k tomu starting point hodin -> na jakých pozicích začínali
    return 1;
}
/*
=================================================================================
*/

#ifndef __PROGTEST__
int main ( int argc, char * argv [] )
{
long long int consumption = 0;

  assert ( energyConsumption ( 2021, 10,  1, 13, 15,
                               2021, 10,  1, 18, 45, &consumption ) == 1
           && consumption == 67116LL );
  assert ( energyConsumption ( 2021, 10,  1, 13, 15,
                               2021, 10,  2, 11, 20, &consumption ) == 1
           && consumption == 269497LL );
  assert ( energyConsumption ( 2021,  1,  1, 13, 15,
                               2021, 10,  5, 11, 20, &consumption ) == 1
           && consumption == 81106033LL );
  assert ( energyConsumption ( 2024,  1,  1, 13, 15,
                               2024, 10,  5, 11, 20, &consumption ) == 1
           && consumption == 81398919LL );
  assert ( energyConsumption ( 1900,  1,  1, 13, 15,
                               1900, 10,  5, 11, 20, &consumption ) == 1
           && consumption == 81106033LL );
  assert ( energyConsumption ( 2021, 10,  1,  0,  0,
                               2021, 10,  1, 12,  0, &consumption ) == 1
           && consumption == 146443LL );
  assert ( energyConsumption ( 2021, 10,  1,  0, 15,
                               2021, 10,  1,  0, 25, &consumption ) == 1
           && consumption == 2035LL );
  assert ( energyConsumption ( 2021, 10,  1, 12,  0,
                               2021, 10,  1, 12,  0, &consumption ) == 1
           && consumption == 0LL );
  assert ( energyConsumption ( 2021, 10,  1, 12,  0,
                               2021, 10,  1, 12,  1, &consumption ) == 1
           && consumption == 204LL );
  assert ( energyConsumption ( 2021, 11,  1, 12,  0,
                               2021, 10,  1, 12,  0, &consumption ) == 0 );
  assert ( energyConsumption ( 2021, 10, 32, 12,  0,
                               2021, 11, 10, 12,  0, &consumption ) == 0 );
  assert ( energyConsumption ( 2100,  2, 29, 12,  0,
                               2100,  2, 29, 12,  0, &consumption ) == 0 );
  assert ( energyConsumption ( 2400,  2, 29, 12,  0,
                               2400,  2, 29, 12,  0, &consumption ) == 1
           && consumption == 0LL );
    assert ( energyConsumption ( 2043, 11, 5, 0, 15,
                               2043, 11, 5, 1, 0, &consumption ) == 1 && consumption == 9153LL);
    assert ( energyConsumption (2000, 11, 30, 0, 0, 2000, 12, 14, 0, 0, &consumption ) == 1 );

  assert( energyConsumption ( 1943, 8, 5, 10, 47, 2003, 6, 27, 1, 40, &consumption ) == 1 );
return 0;
}
#endif /* __PROGTEST__ */