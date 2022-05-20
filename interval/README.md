# Zadání

Úkolem je vytvořit program, který vypočte délku časového intervalu.

Na vstupu dostane program čas počátku časového intervalu `t1` a čas konce časového intervalu `t2`. Čas je vždy zadán ve formátu `h:m:s,ms` (hodina, minuta, sekunda, zlomek sekund). Program vypočte délku tohoto časového intervalu a zobrazí ji ve formátu `h:m:s,ms`. Očekávané chování je vidět i z ukázek níže.

Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:

-   nečíselné hodnoty,
-   hodnoty mimo meze (max. 23h, max. 59 min, max. 59 sec, max. 999 ms),
-   chybějící čárka nebo dvojtečka,
-   počáteční čas je větší než koncový čas.

**Ukázky běhu programu:**

___

```
Zadejte cas t1:
11:45:20,456
Zadejte cas t2:
12:07:54,349
Doba:  0:22:33,893

```

___

```
Zadejte cas t1:
15:18:34,232
Zadejte cas t2:
15:18:34,293
Doba:  0:00:00,061

```

___

```
Zadejte cas t1:
12:00:00,000
Zadejte cas t2:
12:00:00,000
Doba:  0:00:00,000

```

___

```
Zadejte cas t1:
01:01:01,001
Zadejte cas t2:
07:07:07,007
Doba:  6:06:06,006

```

___

```
Zadejte cas t1:
 1 : 1 : 1 , 001
Zadejte cas t2:
 7 : 7 : 7 , 007
Doba:  6:06:06,006

```

___

```
Zadejte cas t1:
1:1:1,001
Zadejte cas t2:
17:7:7,007
Doba: 16:06:06,006

```

___

```
Zadejte cas t1:
12:30:00,000
Zadejte cas t2:
12:00:00,000
Nespravny vstup.

```

___

```
Zadejte cas t1:
15:30:34,123
Zadejte cas t2:
15:60:34,123
Nespravny vstup.

```

___

```
Zadejte cas t1:
15:40:21.745
Nespravny vstup.

```

___

