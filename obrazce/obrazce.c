#include<stdio.h>
#include<math.h>
#include<string.h>
#include<float.h>


char typ_obrazce1,typ_obrazce2, znamenko_obvod, znamenko_obsah;
char obrazec1[20] = {0};
char obrazec2[20] = {0};

//x používám u while loopu jako počet scanu, s1 = polovina obvodu u počítáni obsahu trojuhelniku Heronovým vzorcem
double stranaA1, stranaB1, stranaC1, x, obvod1, obsah1,s1;


double stranaA2, stranaB2, stranaC2, x2, obvod2, obsah2,s2;
int tvar_obrazce1 = 0;
int tvar_obrazce2 = 0;

int main ( void ){

//========================================NAČÍTÁNÍ PRVNÍHO OBRAZCE=============================//
printf("%s\n", "Obrazec #1");

if (scanf(" %c \n", &typ_obrazce1) != 1){
    
    printf ("Nespravny vstup.\n");
    return 1;
};

  while ( scanf ( "%lf", &x ) == 1 )
  {
//Kdyz je nactene cislo zaporne
      if (x < 0){
            printf ( "Nespravny vstup.\n" );
            return 1;
      }

    switch (tvar_obrazce1){
       
       case 0:
            stranaA1=x;
            break;

        case 1:
            stranaB1=x;
            break;

        case 2:
            stranaC1=x;
            break;

        case '\n':
            break;
         
         //Když je zadaných čísel v obrazci 1 více než tři
        default:
            printf ( "Nespravny vstup.\n" );
            return 1;
    }
    tvar_obrazce1 ++;


    }
//========================POČÍTÁNÍ OBSAHU A OBVODU PRVNÍHO OBRAZCE A JEJICH KONTROLA==================/
    switch(typ_obrazce1){
    // u trojuhelniku jeste cekuju jestli vubec z tri stran vznikne trojuhelnik
        case 'T':
        if(tvar_obrazce1 != 3 || (stranaA1 + stranaB1) - stranaC1 < 128 * DBL_EPSILON * ( stranaA1 + stranaB1 + stranaC1 ) 
        || (stranaA1 + stranaC1) - stranaB1 < 128 * DBL_EPSILON * (stranaA1 + stranaB1 + stranaC1) 
        || (stranaC1 + stranaB1 - stranaA1) < 128 * DBL_EPSILON * (stranaA1 + stranaB1 + stranaC1)|| stranaA1 == 0 || stranaB1 == 0 || stranaC1 == 0){
            printf("Nespravny vstup.\n");
            return 1;
        }
        else{ 
            obvod1 = stranaA1 + stranaB1 + stranaC1;
            s1 = obvod1/2; //Používám Heronův vzorec
            obsah1 = sqrt(s1 * (s1-stranaA1) * (s1-stranaB1) * (s1-stranaC1));
            strncpy(obrazec1, (char  *) "trojuhelnik", 12);
        }
        break;

        case 'R':
        if(tvar_obrazce1 != 2 || stranaA1 == stranaB1 || stranaA1 == 0 || stranaB1 == 0){
            printf("Nespravny vstup.\n");
            return 1;
        }
        else{ 
            obvod1 = 2*(stranaA1 + stranaB1);
            obsah1 = stranaA1*stranaB1;
            strncpy(obrazec1, (char  *)"obdelnik", 9);
        }
        break;

        case 'S':
        if(tvar_obrazce1 != 1 || stranaA1 == 0){
            printf("Nespravny vstup.\n");
            return 1;
        }
        else{ 
            obvod1 = stranaA1 * 4;
            obsah1 = stranaA1 * stranaA1;
            strncpy(obrazec1, (char  *)"ctverec", 8);
        }
        break;

        default: 
            printf ("Nespravny vstup.\n");
            return 1;
    } 
//==========================================KONEC POCITANI PRVNIHO TVARU===========================//
//=================================================================================================//
//========================================NAČÍTÁNÍ DRUHEHO OBRAZCE================================//
printf("%s\n", "Obrazec #2");

if (scanf(" %c \n", &typ_obrazce2) != 1){
    printf ( "Nespravny vstup.\n" );
    return 1;
}

  while ( scanf ( "%lf", &x2 ) == 1 )
  {

      //Kdyz je nactene cislo zaporne
      if (x2 < 0){
            printf ( "Nespravny vstup.\n" );
            return 1;
      }

    switch (tvar_obrazce2){
       
       case 0:
            stranaA2=x2;
            break;

        case 1:
            stranaB2=x2;
            break;

        case 2:
            stranaC2=x2;
            break;
         
         //Když je zadaných čísel v obrazci 1 více než tři
        default:
            printf ( "Nespravny vstup.\n" );
            return 1;
    }
    tvar_obrazce2 ++;
    }

//========================POČÍTÁNÍ OBSAHU A OBVODU DRUHEHO OBRAZCE A JEJICH KONTROLA==================/
    switch(typ_obrazce2){
 // u trojuhelniku jeste cekuju jestli vubec z tri stran vznikne trojuhelnik
        case 'T':
        if(tvar_obrazce2 != 3  || (stranaA2 + stranaB2) - stranaC2 < 128 * DBL_EPSILON * ( stranaA2 + stranaB2 + stranaC2 ) || 
        (stranaA2 + stranaC2) - stranaB2 < 128 * DBL_EPSILON * (stranaA2 + stranaB2 + stranaC2) || (stranaC2 + stranaB2 - stranaA2) < 128 * DBL_EPSILON * (stranaA2 + stranaB2 + stranaC2) || stranaA2 == 0
        || stranaB2 == 0 || stranaC2 == 0){
            printf("Nespravny vstup.\n");
            return 1;
        }
        else{ 
            obvod2 = stranaA2 + stranaB2 + stranaC2;
            s2 = obvod2/2; //Používám Heronův vzorec
            obsah2 = sqrt(s2 * (s2-stranaA2) * (s2-stranaB2) * (s2-stranaC2));
            strncpy(obrazec2, (char  *) "trojuhelnik", 12);
        }
        break;

        case 'R':
        if(tvar_obrazce2 != 2 || stranaA2 == stranaB2 || stranaA2 == 0 || stranaB2 ==0){
            printf("Nespravny vstup.\n");
            return 1;
        }
        else{ 
            obvod2 = 2*(stranaA2 + stranaB2);
            obsah2 = stranaA2*stranaB2;
            strncpy(obrazec2, (char  *) "obdelnik", 9);
        }
        break;

        case 'S':
        if(tvar_obrazce2 != 1 || stranaA2 == 0){
            printf("Nespravny vstup.\n");
            return 1;
        }
        else{ 
            obvod2 = stranaA2 * 4;
            obsah2 = stranaA2 * stranaA2;
            strncpy(obrazec2, (char  *) "ctverec", 8);
        }
        break;

        default: 
            printf ( "Nespravny vstup.\n" );
            return 1;
    } 
if ( ! feof ( stdin ) )
  {
    printf ( "Nespravny vstup.\n" );
    return 1;
  }
  //====================POROVNÁVÁNÍ OBVODŮ======================//
  if ( fabs( obvod1 - obvod2) < 128 * DBL_EPSILON * (obvod1+obvod2) ){
        znamenko_obvod = '=';
  }
  else if(obvod1 > obvod2){
        znamenko_obvod = '>';
  }
  else if(obvod1 < obvod2)
        znamenko_obvod = '<' ;

//======================POROVNÁVÁNÍ OBSAHŮ======================//

  if(fabs(obsah1 - obsah2) < 128 * DBL_EPSILON * (obsah2+obsah1)){
      znamenko_obsah = '=';
  }
  else if(obsah1 > obsah2) {
      znamenko_obsah = '>';
  }

  else if(obsah1 < obsah2) {
      znamenko_obsah = '<';

  }


    // printf ( "n = %d, obrazec= %c Strana A = %f ,Strana B = %f, Strana C = %f, obvod = %0.f obsah=%0f  nazev obrazce:%s,rozdil obsahu:%e\n", tvar_obrazce1, typ_obrazce1 , stranaA1, stranaB1, stranaC1, obvod1, obsah1, obrazec1, fabs(obsah1-obsah2));
    //  printf ( "n = %d, obrazec= %c Strana A = %f ,Strana B = %f, Strana C = %f, obvod = %0.f obsah=%0f nazev obrazce:%s, rozdil obvodu:%e tolerance:%e\n", tvar_obrazce2, typ_obrazce2 , stranaA2, stranaB2, stranaC2, obvod2, obsah2, obrazec2, fabs(obvod1-obvod2),(128 * DBL_EPSILON * (obsah2+obsah1)));

    printf("Obvod: %s #1 %c %s #2\n", obrazec1,znamenko_obvod, obrazec2);
    printf("Obsah: %s #1 %c %s #2\n", obrazec1,znamenko_obsah, obrazec2);

  return 0;
}


