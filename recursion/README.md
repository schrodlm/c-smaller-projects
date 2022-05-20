# Zadani

## Rekurze

Předpokládáme, že máme k dispozici N kostek různé velikosti. Dále známe velikosti jednotlivých kostek. Z kostek chceme postavit věže. Věž má výšku alepoň jedné kostky. Při stavbě lze kostky stavět nad sebe, ale nelze stavět větší kostku na menší. Úkolem je vypočítat, kolik tvarově různých věží lze postavit a vypsat jejich podoby.

Vstupem programu je počet kostek N následovaný velikostmi jednotlivých kostek.

Výstupem programu je výpis jednotlivých věží, tedy pořadí velikostí kostek, vždy od základny (vlevo) po vrchol (vpravo). Jedna věž je vypsána na jedné řádce. Dále program zobrazí počet nalezených věží.

Program musí ošetřovat vstupní data. Pokud jsou vstupní data nesmyslná, program to musí zjistit, vypsat chybové hlášení a ukončit se. Za chybu je považováno:

-   nečíslelný, záporný nebo nulový počet kostek N,
-   velikost kostky není celé číslo, je záporná nebo nulová.

Program je testován v omezeném prostředí. Je omezen dobou běhu a velikostí dostupné paměti. Úloha není náročná na paměť, pro velké vstupy je ale náročná na dobu běhu. Testované jsou relativně malé objemy dat, které lze zvládnout programem, který rozumně implementuje naivní algoritmus.

**Ukázka práce programu:**

___

```
Pocet kostek:
5
Velikosti:
1 2 3 4 5
5, 4, 3, 2, 1
5, 4, 3, 2
5, 4, 3, 1
5, 4, 3
5, 4, 2, 1
5, 4, 2
5, 4, 1
5, 4
5, 3, 2, 1
5, 3, 2
5, 3, 1
5, 3
5, 2, 1
5, 2
5, 1
5
4, 3, 2, 1
4, 3, 2
4, 3, 1
4, 3
4, 2, 1
4, 2
4, 1
4
3, 2, 1
3, 2
3, 1
3
2, 1
2
1
Celkem: 31

```

___
