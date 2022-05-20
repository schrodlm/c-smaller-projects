# Zadani

Úkolem je realizovat funkci (ne celý program, pouze funkci), která bude počítat spotřebu el. energie v digitálních hodinách.

Evropská unie správně chápe, že energií je potřeba šetřit, ať to stojí, co to stojí. Zatím se to týká žárovek, výbojek, vysavačů, ale dá se očekávat, že tento progresivní trend zasáhne i další energeticky náročná zařízení. Abychom náročné práci euroúředníků pomohli, poskytneme jim v této úloze analytický nástroj, kterým půjde v dlouhodobém horizontu zkoumat energetickou náročnost digitálních hodin s mechanickým sedmisegmentovým displejem.

Hodiny zobrazují čas na sedmisegmentovém displeji. Čas je zobrazován ve 24 hodinovém formátu, tedy 00 00 00 až 23 59 59. Displej je mechanický, číslice je tvořena ze 7 segmentů, každý segment je buď světlý nebo tmavý obdélník. Pokud je nedochází ke změně daného segmentu, není potřeba dodávat žádnou energii. Naopak, změna tmavého segmentu na světlý nebo opačná stojí energii, pro jednoduchost předpokládáme 1J na změnu jednoho segmentu. Cifry na sedmisegmentovém displeji mají standardní tvar, tedy:

```
 -         -    -         -    -    -    -    -                                                                     
| |    |    |    |  | |  |    |      |  | |  | |                                                                       
           -    -    -    -    -         -    -                                                                     
| |    |  |      |    |    |  | |    |  | |    |                                                                       
 -         -    -         -    -         -    -                                                                     

```

Naše funkce dostane parametrem dva časové údaje - počátek a konec časového intervalu. Počátek i konec je dán rokem, měsícem, dnem, hodinou a minutou. Funkce spočítá, kolik energie hodiny za tuto dobu spotřebují.

Požadovaná funkce má rozhraní:

```
int energyConsumption ( int y1, int m1, int d1, int h1, int i1,
                        int y2, int m2, int d2, int h2, int i2, 
                        long long int * consumption )

```

y1, m1, d1, h1, i1

jsou vstupní parametry, které představují rok, měsíc, den, hodinu a minutu počátku intervalu,

y2, m2, d2, h2, i2

jsou vstupní parametry, které představují rok, měsíc, den, hodinu a minutu konce intervalu,

consumption

je výstupní parametr, do kterého funkce uloží vypočtenou spotřebu v zadaném období. Spotřebu vracejte v joulech (J). Parametr bude funkce nastavovat pouze pokud jsou zadané správné vstupní parametry. Pokud jsou zadané nesprávné vstupy, nelze hodnotu určit. V takovém případě funkce signalizuje neúspěch a ponechá tento výstupní parametr beze změn. Vypočtená hodnota zahrnuje spotřebu na všechny změny obsahu displeje provedené mezi prvním a posledním zobrazeným časovým údajem. Tedy např. pro ukázkové zadání:

```
     assert ( energyConsumption ( 2400,  2, 29, 12,  0,
                             2400,  2, 29, 12,  1, &consumption ) == 1
              && consumption == 204LL );
   
```

Během této doby proběhlo 60 změn zobrazovaných sekund (200J) a změna minut z 00 na 01 (4J)..

návratová hodnota funkce

bude nastavena na hodnotu 1 pro úspěch (správné vstupní parametry) nebo 0 pro neúspěch (nesprávné vstupní parametry).

Pokud jsou zadané nesprávné vstupní parametry, je potřeba vrátit hodnotu 0 (neúspěch). Správné hodnoty vstupních parametrů musí splňovat:

-   rok je větší roven 1600,
-   měsíc je platný (1 až 12),
-   den je platný (1 až počet dní v měsíci),
-   hodina je platná (0 až 23),
-   minuta je platná (0 až 59),
-   zadaný okamžik počátku intervalu nenastane až po zadaném okamžiku konce intervalu.
