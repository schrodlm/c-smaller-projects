#include <stdio.h>
#include <assert.h>

int dateToIndex (int day, int month, int year, int * idx)
{
    *idx = 0;
    int unor = 0;




/* Zde kontroluji zda se jedná o přestupný rok či nikoliv */
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 4000 != 0))
    {
        unor = 29;
    }
    else
    {
        unor = 28;
    }

int dny_v_mesicich[12]={31,unor,31,30,31,30,31,31,30,31,30,31};

/*Kontrola špatných vstupů*/

if(year < 2000 || month < 1 || month > 12 || day > dny_v_mesicich[month-1] || day <= 0){
    return 0;

} 
/* Tato funkce vynásobí měsíce, které jsme zadali do proměnné int month poctem dni, které k nim náleží viz. proměnná dny_v_mesicich

    (month -1) protoze ten mesic, ktery je zadany jeste probíhá, nemuzeme ho tedy pricist cely */

    for(int i = 0; i < (month - 1); i ++)
    {
        *idx = *idx + dny_v_mesicich[i];
    }
/* Zde jiz mame v promenne *idx obsazene vsechny mesice krome probihajicího tak musíme ještě pricist dny, v kterých se soucasny mesic nachazi*/
    *idx = *idx + day;

    return 1;
}


int main (void) 
{
int days;
assert(dateToIndex( 1,  1, 2000, &days) == 1 && days == 1);


return 0;
}