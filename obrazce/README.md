# Zadani

<p>Úkolem je vytvořit program, který bude porovnávat dvojice geometrických obrazců. Porovná jejich obsah a obvod.</p><p>Na vstupu programu je dvojice geometrických obrazců v rovině. Pro každý obrazec je zadaná jeho velikost. Obrazcem může být:</p><ul><li>trojúhelník - na vstup je identifikace obrazce (písmeno T) následovaná trojicí desetinných čísel (délky stran),</li><li>obdélník - na vstup je identifikace obrazce (písmeno R) následovaná dvojicí desetinných čísel (délky stran) nebo</li><li>čtverec - na vstup je identifikace obrazce (písmeno S) následovaná jedním desetinným číslem (délka strany).</li></ul><p>Program určí, zda mají zadané obrazce stejný obsah/obvod a výsledek zobrazí dle formátu podle ukázky (viz níže).</p><p>Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:</p><ul><li>nebyl zadaný žádný povolený obrazec (trojúhelník/obdélník/čtverec),</li><li>nebyl zadaný potřebný počet desetinných čísel - rozměrů obrazce,</li><li>zadaný rozměr byl neplatný, neměl podobu platného čísla, byl záporný nebo nulový,</li><li>zadané velikosti stran netvoří trojúhelník nebo</li><li>obdélník má obě strany stejně dlouhé (měl být zadaný jako čtverec).</li></ul><b>Ukázka práce programu:</b><br><hr><pre><b>Obrazec #1</b>
S 4.5
<b>Obrazec #2</b>
R 2 10.125
<b>Obvod: ctverec #1 &lt; obdelnik #2</b>
<b>Obsah: ctverec #1 = obdelnik #2</b>
</pre><hr><pre><b>Obrazec #1</b>
R 4 5
<b>Obrazec #2</b>
T 4.5 6 7.5
<b>Obvod: obdelnik #1 = trojuhelnik #2</b>
<b>Obsah: obdelnik #1 &gt; trojuhelnik #2</b>
</pre><hr><pre><b>Obrazec #1</b>

   T
 1
 1
 1
<b>Obrazec #2</b>
 S
 2
<b>Obvod: trojuhelnik #1 &lt; ctverec #2</b>
<b>Obsah: trojuhelnik #1 &lt; ctverec #2</b>
</pre><hr><pre><b>Obrazec #1</b>
T 7.981 8.899 2.996
<b>Obrazec #2</b>
R 2.959 6.979
<b>Obvod: trojuhelnik #1 = obdelnik #2</b>
<b>Obsah: trojuhelnik #1 &lt; obdelnik #2</b>
</pre><hr><pre><b>Obrazec #1</b>
R 6.474 0.559
<b>Obrazec #2</b>
T 0.507 14.276 14.285
<b>Obvod: obdelnik #1 &lt; trojuhelnik #2</b>
<b>Obsah: obdelnik #1 = trojuhelnik #2</b>
</pre><hr><pre><b>Obrazec #1</b>
T 20 30 50
<b>Nespravny vstup.</b>
</pre><hr><pre><b>Obrazec #1</b>
S -4
<b>Nespravny vstup.</b>
</pre><hr><pre><b>Obrazec #1</b>
R 20 30
<b>Obrazec #2</b>
T 0.444 0.521 0.965
<b>Nespravny vstup.</b>
</pre><hr><pre><b>Obrazec #1</b>
R 12 12
<b>Nespravny vstup.</b>
</pre><hr><pre><b>Obrazec #1</b>
R 1 abcd
<b>Nespravny vstup.</b>
