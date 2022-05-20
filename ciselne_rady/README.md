# Zadání

<p>Úkolem je vytvořit program, který bude rozebírat sekvenci čísel.</p><p>Předpokládáme sekvenci nezáporných celých čísel (0, 1, 2, ...). Sekvence začíná číslem 0, jednotlivá čísla jsou zapsaná ve vzestupném pořadí bez vložených mezer a zbytečných nul. Sekvence bude začínat takto:</p><pre>01234567891011121314151617181920...
</pre>Pro člověka je takový zápis obtížně čitelný, proto jej uvedeme ještě v obarvené podobě:<pre><span>0</span><span>1</span><span>2</span><span>3</span><span>4</span><span>5</span><span>6</span><span>7</span><span>8</span><span>9</span><span>10</span><span>11</span><span>12</span><span>13</span><span>14</span><span>15</span><span>16</span><span>17</span><span>18</span><span>19</span><span>20</span>...
</pre>Úkolem programu je přečíst ze vstupu pozici (pořadové číslo od počátku) a určit, jaká číslice kterého čísla je na zadané pozici sekvence. Například:<ul><li>na pozici 0 je číslice 0 čísla 0,</li><li>na pozici 15 je pak číslice 2 čísla 12,</li><li>na pozici 2021 je číslice 1 čísla 710, ...</li></ul><p>Aby byl program univerzálnější, dokáže zadaný problém řešit pro různé číselné soustavy. Například pro zápis čísel ve dvojkové soustavě by sekvence vypadala takto:</p><pre><span>0</span><span>1</span><span>10</span><span>11</span><span>100</span><span>101</span><span>110</span><span>111</span><span>1000</span><span>1001</span>...
</pre>Pro dvojkovou soustavu např. bude na pozici 14 číslice 0 čísla 110. Program bude mít na svém vstupu zadané jednotlivé problémy k vyřešení. Každý problém bude zadaný jako dvě celá desítková čísla. První z čísel udává pozici v sekvenci, druhé číslo pak základ soustavy, pro kterou problém řešíme. Pro každý takto zadaný problém program vypočte výsledek a zobrazí jej ve formátu podle ukázky (číslo s vyznačením vybrané číslice). Zadávání problémů skončí v okamžiku, kdy program dosáhne konce vstupu (je signalizován aktivní EOF).<p>Pokud je vstup neplatný, program to musí detekovat a zobrazit chybové hlášení. Chybové hlášení zobrazujte na standardní výstup (ne na chybový výstup). Za chybu považujte:</p><ul><li>pozice v sekvenci je neplatná (neplatný zápis čísla, záporná hodnota),</li><li>základ číselné soustavy je neplatný (nečíselné zadání, mimo uzavřený interval &lt; 2 ; 36 &gt;).</li></ul><b>Ukázka práce programu:</b><br><hr><pre><b>Pozice a soustava:</b>
0 10
<b>0</b>
<b>^</b>
3 10
<b>3</b>
<b>^</b>
9 10
<b>9</b>
<b>^</b>
10 10
<b>10</b>
<b>^</b>
11 10
<b>10</b>
<b> ^</b>
12 10
<b>11</b>
<b>^</b>
13 10
<b>11</b>
<b> ^</b>
189 10
<b>99</b>
<b> ^</b>
190 10
<b>100</b>
<b>^</b>
191 10
<b>100</b>
<b> ^</b>
192 10
<b>100</b>
<b>  ^</b>
193 10
<b>101</b>
<b>^</b>
</pre><hr><pre><b>Pozice a soustava:</b>
42 10
<b>26</b>
<b>^</b>
666 10
<b>258</b>
<b>  ^</b>
1889 10
<b>666</b>
<b> ^</b>
12345 10
<b>3363</b>
<b>   ^</b>
1000000 10
<b>185185</b>
<b>^</b>
1234321 10
<b>224238</b>
<b>   ^</b>
</pre><hr><pre><b>Pozice a soustava:</b>
abc 10
<b>Nespravny vstup.</b>
</pre><hr><pre><b>Pozice a soustava:</b>
12 37
<b>Nespravny vstup.</b>
