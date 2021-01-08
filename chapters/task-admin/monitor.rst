Monitorizarea sistemului
========================

Odată ce am început să rulă servicii pe sistem, vrem să vedem în ce parametri rulează, dacă se comportă cum ne-am aștepta.
Din aceste motive noi monitorizăm serviciile folosind diverse metode, în linie de comandă sau grafice.

Monitorizarea sistemului folosind programe în linia de comandă
--------------------------------------------------------------

Pentru început vom vorbi despre metode simple de monitorizarea sistemului, în cazul în care avem vrem să verificăm atribute de rulare cum ar fi cât de încărcat este serverul în momentul curent.

Monitorizarea aplicațiilor în mod interactiv
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Aici voi face referire la capitolul lui RD despre procese și voi prezenta mai multe despre htop, cum ar fi sortările după atribute.

Monitorizarea folosind onelinere
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Cel mai important de prezentat aici este `uptime`, care afișează media de încărcare sistemului de la distanță.

Voi prezenta `df` și `free`.

Folosirea Grafana
-----------------

Monitorizarea folosind Grafana, sau alte aplicații care prezintă grafice, este faptul că acestea îți dau o imagine de ansamblu a sistemului pe o perioadă îndelungată de timp, astfel poți să studiezi evenimente care s-au întâmplat în trecut.

Un alt avantaj al folosirii Grafana în mod particular este că acesta oferă soluții nu numai pentru monitorizarea sistemului, dar și pentru monitorizarea aplicațiilor care rulează pe sistem.
De exemplu, pentru serverul de Minecraft ne poate arăta numărul de jucători curenți în paralel cu gradul de folosire al rețelei, viteza de scriere pe disk și temperatura procesorului, lucru care ne poate ajuta să diagnosticăm probleme de performanță ale sistemului.

Instalarea unui exporter pentru sistem
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Vizualizarea graficelor
^^^^^^^^^^^^^^^^^^^^^^^

Importarea graficelor
"""""""""""""""""""""

Crearea de grafice proprii
""""""""""""""""""""""""""
