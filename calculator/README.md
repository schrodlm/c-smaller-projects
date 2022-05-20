# Zadání

<p>Úkolem je vytvořit program, který bude zpracovávat jednoduché matematické vzorce.</p><p>Na vstupu dostanete dvě desetinná čísla oddělená znakem operace a zakončená znakem rovná se. Vaším úkolem je vypočítat hodnotu podle zadaného operátoru:</p><ul><li>pro <code>+</code> určit součet,</li><li>pro <code>-</code> určit rozdíl,</li><li>pro <code>*</code> určit součin,</li><li>pro <code>/</code> určit celočíselný podíl (např. <code>3.5 / 1.5 = 2</code>, kolikrát se do dělence vejde <em>celý</em> dělitel).</li></ul><p>Jiné operace program nebude umět a vypíše pro ně chybové hlášení. Formát vstupu a výstupu je vidět níže na ukázce práce programu.</p><p>Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:</p><ul><li>zadané číslo není validní desetinné číslo,</li><li>dělitel je 0 pro operaci <code>/</code>,</li><li>čísla nejsou oddělena validním operátorem (<code>+</code>, <code>-</code>, <code>*</code> nebo <code>/</code>),</li><li>za posledním číslem se nenachází znak <code>=</code>.</li></ul><p><strong>Ukázka práce programu:</strong></p><hr><pre><b>Zadejte vzorec:</b>
3.5 + 1.5 =
<b>5</b>
</pre><hr><pre><b>Zadejte vzorec:</b>
3.5 / 1.5 =
<b>2</b>
</pre><hr><pre><b>Zadejte vzorec:</b>
1000000 * 1.5e+8 =
<b>1.5e+14</b>
</pre><hr><pre><b>Zadejte vzorec:</b>
7 / -1 =
<b>-7</b>
</pre><hr><pre><b>Zadejte vzorec:</b>
abc / 1 =
<b>Nespravny vstup.</b>
</pre><hr><pre><b>Zadejte vzorec:</b>
4 &amp; 10 =
<b>Nespravny vstup.</b>
