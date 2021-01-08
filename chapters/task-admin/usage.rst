Folosirea stației la distanță
=============================

Folosirea tmux
--------------

Atunci când ne conectăm la un calculator prin SSH și rulăm comenzi, acestea vor rula în foreground.

Dacă avem o aplicație care rulează mult timp, cum ar fi un find, și coexiunea SSH se întrerupe, se va întrerupe și execuția comenzii find.
Pentru a rezolva această problemă, vom folosi aplicația tmux.

Aceasta ne pornește o sesiune de shell care este independentă de terminalul în care rulează, astfel, putem să ne conectăm și să ne deconectăm de la ea. (nu știu cum o să fac un demo rezonabil cu tmux, dar vedem)

Crearea unei sesiuni tmux
^^^^^^^^^^^^^^^^^^^^^^^^^

Detașarea de la o sesiune tmux
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Reatașarea la o sesiune tmux
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Scenarii de folosire a sistemului la distanță
---------------------------------------------
