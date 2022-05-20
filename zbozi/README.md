# Zadani
Úkolem je vytvořit program, který bude zpracovávat provedené nákupy a analyzovat prodejnost zboží.

Předpokládáme že zaznamenáváme jednotlivé prodeje zboží. Zajímá nás zejména to zboží, které se prodává nejvíce. Proto program bude umět vypočítat N druhů zboží, kterého se prodalo nejvíce kusů. Hodnota N (počet druhů zboží, které se prodává nejvíce) bude zadán na vstupu programu jako první údaj.

Zboží je identifikováno svým jménem - řetězcem. Jméno musí být nejvýše 99 znaků dlouhé a neobsahuje bílé znaky. Na vstupu se o prodeji zboží program dozví pomocí zadání \+ jméno-zboží. Na vstupu dále mohou být příkazy, kterými lze zobrazit analýzu prodeje. Konkrétně:

-   příkaz # zobrazí přehled N druhů zboží, kterého se dosud prodalo nejvíce. Výpis bude mít podobu podle ukázky níže, pro každý druh zboží bude uvedeno jméno a počet prodaných kusů. Dále bude zobrazen i celkový součet (součty prodaných kusů pro zobrazené nejvíce prodávané zboží).
-   příkaz ? zobrazí pouze celkový součet.

Fungování programu se trochu komplikuje pro vstupy, kde se pro dva a více různých druhů zboží prodal stejný počet kusů:

-   jednodušší situace je vidět v první ukázce. Ve výpisu jsou 4 kusy prodaných vajíček a mouky. Proto toto zboží má shodně 2. až 3. místo ve výpisu a odpovídá tomu i formát výpisu. Zároveň tím není určeno přesné pořadí ve výpisu. Testovací prostředí proto akceptuje obě (všechny) možnosti, tedy zde by konkrétně bylo správně jak:
    
    ```
       1. Milk, 5x
       2.-3. Eggs, 4x
       2.-3. Flour, 4x
       4. Beer, 3x
       
    ```
