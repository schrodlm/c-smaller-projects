# Zadání

<p>Úkolem je vytvořit program, který převede barvu z RGB zápisu do hexadecimálního formátu.</p><p>Na vstupu dostanete definici barvy v podobě <code>rgb ( x, y, z )</code>. <code>x</code>, <code>y</code> a <code>z</code> jsou celá čísla v intervalu od 0 do 255 včetně a reprezentují barevnou složku. Cílem je převést tento formát na formát začínající znakem <code>#</code> a následně bez mezer pro každou barevnou složku hexadecimální zápis na dvě pozice například pro hodnotu <code>12</code> vypíšete dvě hodnoty <code>0C</code>. Formát vstupu a výstupu je vidět níže na ukázce práce programu.</p><p>Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:</p><ul><li>vstup neobsahuje řetězec <code>rgb</code>,</li><li>chybějící čárka nebo závorka,</li><li>chybějící barevná složka,</li><li>barevná složka není validní číslo,</li><li>barevná složka není v rozmezí 0 až 255.</li></ul><p><strong>Ukázky běhu programu:</strong></p><hr><pre><b>Zadejte barvu v RGB formatu:</b>
rgb ( 255, 0, 0 )
<b>#FF0000</b>
</pre><hr><pre><b>Zadejte barvu v RGB formatu:</b>
    rgb(  0  ,   255  ,   0   )
<b>#00FF00</b>
</pre><hr><pre><b>Zadejte barvu v RGB formatu:</b>
rgb(0,0,255)
<b>#0000FF</b>
</pre><hr><pre><b>Zadejte barvu v RGB formatu:</b>
rgb ( 127, 127, 0 )
<b>#7F7F00</b>
</pre><hr><pre><b>Zadejte barvu v RGB formatu:</b>
hsl ( 0, 127, 0 )
<b>Nespravny vstup.</b>
</pre><hr><pre><b>Zadejte barvu v RGB formatu:</b>
rgb ( 255, 0 )
<b>Nespravny vstup.</b>
</pre><hr><pre><b>Zadejte barvu v RGB formatu:</b>
rgb ( 1000, 127, 0 )
<b>Nespravny vstup.</b>
</pre><hr><pre><b>Zadejte barvu v RGB formatu:</b>
RGB ( 100, 200, 0 )
<b>Nespravny vstup.</b>
