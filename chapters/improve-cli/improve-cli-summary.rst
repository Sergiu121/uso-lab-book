.. _improve_cli_summary:

Sumar: Îmbunătățirea lucrului în linia de comandă
=================================================

Sumar: Scurtături în terminal
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Funcția de auto-complete este extrem de utilă și îmbunătățește în mod dramatic viteza cu care realizăm acțiuni în terminal.
    * Funcția de auto-complete nu ne face doar mai rapizi, dar putem folosi tasta ``Tab`` și pt a confirma că comanda este validă.
* Consultăm istoricul comenzilor folosind comanda ``history``.
    * Navigăm prin istoricul comenzilor folosind ``Arrow Keys``, ``Ctrl+r``, expandarea comenzilor anterioare sau chiar expandarea argumentelor comenzii anterioare.
    * Navigăm în interiorul unei comenzi (``Ctrl+a``, ``Ctrl+e``, ``Alt+f``, ``Alt+b``), putem efectua modificări (``Ctrl+k``, ``Ctrl+u``, ``Alt+d``) și putem insera textul șters (``Ctrl+y``).

Sumar: Inspectarea sistemului de fișiere
========================================

Inspectarea paginilor de manual
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Navigarea prin paginile manualului:

  * ``Ctrl+n``/``Ctrl+p`` sau ``j``/``k`` pentru a naviga, cu câte o linie, în jos, respectiv în sus; recomandăm utlizarea tastelor ``j``/``k`` pentru a fi mai eficienți
  * Search (``/``, ``?``, ``n``, ``N``)
  * Go up (``g``), go down (``G``)
  * Help (``h``) pentru a afla mai multe despre cum putem folosi mai bine sesiunea interactivă
  * Quit (``q``) pentru a ieși din sesiunea interactivă

* Prezentarea secțiunilor din manual: ``man printf`` vs ``man 3 printf``.

* Prezentarea pachetului ``tldr`` - poate fi util pentru cazurile uzuale, dar nu trebuie să ne fie frică să căutăm în ``man`` pentru detalii

Selectarea multiplor fișiere folosind globbing
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Folosim *globbing* pentru a selecta mai multe fișiere al căror nume corespunde unui tipar:

* Caracterul ``*`` poate fi înlocuit cu orice caracter de oricâte ori, sau poate lipsi cu totul.
* Caracterul ``?`` înlocuiește exact un caracter, oricare ar fi acela.
* Folosim sintaxa ``[]`` pentru a defini o listă de caractere care pot fi folosite în înlocuire.
* Folosim sintaxa ``{}`` pentru a defini o listă de cuvinte (grupuri de caractere) care pot fi folosite în înlocuire.
* Scăpăm de semnificația specială a unei expresii încadrând-o între ``"`` (ghilimele).

Căutarea unui fișier în sistem
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Utilitarul ``locate``
"""""""""""""""""""""

Folosim utilitarul ``locate`` pentru a căuta un fișier în întreg sistemul de fișiere.

Are avantajul că este foarte rapid, deoarece folosește o bază de date pentru a indexa fișierele.

Are două dezavantaje:
    #. Baza de date trebuie reconstruită periodic.
       Dacă vrem să reconstruim manual baza de date, avem nevoie de drepturi privilegiate pentru a rula comanda ``updatedb``.
    #. Utilitarul caută în tot sistemul de fișiere: nu putem să specificăm un punct de start pentru căutare.
       Este necesar să filtrăm rezultatul căutării cu punctul de start dorit, așa cum am făcut în exemplul de mai sus: ``| grep workspace/C``.

Utilitarul ``find``
"""""""""""""""""""

Folosim ``find`` pentru a căuta după criterii mai complexe decât numele fișierului, cum ar fi tipul fișierului, data ultimei modificări, etc.

De cele mai multe ori vom folosi ``find`` în conjuncție cu opțiunea ``-exec`` pentru a rula o comandă asupra fișierelor găsite.

Utilitarul ``find`` este mai lent decât ``locate``, dar nu necesită o bază de date care trebuie actualizată periodic.
``locate`` este probabil suficient pentru majoritatea cazurilor când suntem interesați de căutarea unui fișier.
j

Sumar: Inspectarea fișierelor
=============================

Inspectarea rapida a conținutului fișierelor
--------------------------------------------

Pentru a vedea rapid conținutul unui fișier folosim utlitarul ``less``.
În cadrul unei sesiuni ``less`` putem folosi aceeleași taste ca în cadrul sesiunii interactive ``man`` pentru navigarea în pagină:

* ``Ctrl+n``/``Ctrl+p`` sau ``j``/``k`` pentru a naviga, cu câte o linie, în jos, respectiv în sus; recomandăm utlizarea tastelor ``j``/``k`` pentru a fi mai eficienți
* ``Ctrl+f``/``Ctrl+b`` pentru a naviga, cu câte o pagină de terminal, în jos, respectiv în sus
* Search (``/``, ``?``, ``n``, ``N``)
* Go up (``g``), go down (``G``)
* Help (``h``) pentru a afla mai multe despre cum putem folosi mai bine sesiunea interactivă
* Quit (``q``) pentru a ieși din sesiunea interactivă

Pentru a afișa pe ecran conținutul unui fișier folosim utlitarul ``cat``.

Pentru a afișa parțial conținutul unui fișier sau a extrage rezultatul unei comenzi folosim utilitarele ``head`` și ``tail``.

Căutarea în fișiere
-------------------

Folosim comanda ``grep`` pentru a căuta un *pattern* într-un fișier sau în rezultatul unei comenzi (cum ar fi ``cat``).
Modul de folosire este ``grep PATTERN cale/către/fișier`` sau ``cmd | grep PATTERN``.

Opțiuni uzuale ale ``grep``
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Folosim opțiunea ``-n`` pentru a afișa și numărul liniei care conține patternul căutat.

Implicit, grep caută în mod case-sensitive patternul.
Folosim opțiunea ``-i`` pentru a căuta patternul în mod case-insensitive.

Pentru a afișa toate liniile, mai puțin pe cele care conțin pattern, folosim opțiunea ``-v``.

Pentru a efectua o căutare recursivă folosim opțiunea ``-r``.

De cele mai multe ori vom folosi opțiunile ``-n``, ``-i`` și ``-r`` în aceelași timp.
Astfel avem o căutare cât mai cuprinzătoare și putem folosi funcția de căutare în sesiunea interactivă ``less`` pentru a găsi linia și fișierul care ne interesează.

Extra: Dacă dorim să căutăm cuvântul **search** folosim opțiunea ``-w`` (word) pentru a trata patternul ca un cuvânt, ca în exemplul următor: ``grep -nri -w "search" workspace/C/ | less``.

Compararea fișierelor
---------------------

Comparăm două fișiere, octet cu octet, folosind utilitarul ``cmp``.

Comparăm textual două fișiere folosind utilitarul ``diff``.

Sumar: O înțelegere mai bună a shellului
========================================

Configurarea shellului bash
---------------------------

Fișierul de configurare al shellului **BASH** este ``~/.bashrc``.
Atunci când un utilizator pornește un shell bash, conținutul fișierului ``~/.bashrc`` este citit și sunt aplicate configurările specifice utilizatorului.

Valorile variabilelor ``HISTSIZE`` și ``HISTFILESIZE`` limitează numărul maxim de comenzi, respectiv linii, din fișierul ``~/.bash_history``.

Un alias este un nume (*placeholder*) care înlocuiește un șir de caractere.
Pentru o organizare mai bună, este recomandat ca utilizatorul să-și definească aliasurile în fișierul ``~/.bash_aliases``.

Execuția comenzilor
-------------------

Înlănțuirea comenzilor
^^^^^^^^^^^^^^^^^^^^^^

Atunci când își încheie execuția, orice proces întoarce un cod de eroare, care este un număr: valoarea ``0`` semnifică că acesta și-a încheiat execuția cu succes, iar orice ală valoare indică o eroare.


Pentru a înlănțui comenzi în terminalul bash avem trei operatori disponibili:

* Operatorul ``;`` - este folosit pentru separarea comenzilor, indiferent de cum s-au executat acestea.
* Operatorul binar ``&&`` (și logic) - execută a doua comandă doar dacă precedenta s-a executat cu succes.
* Operatorul binar ``||`` (sau logic) - execută a doua comandă doar dacă prima s-a terminat cu eșec.

Atunci când folosim operatorul ``|`` preluăm rezultatul comenzii din stânga operatorului și îl oferim ca intrare comenzii aflate în dreapta operatorului.
Operatorul ``|`` ne permite să prelucrăm datele de interes, trecându-le prin mai multe utilitare, fiecare cu un scop bine definit.

Redirectări
^^^^^^^^^^^

Folosim operatorul ``>`` pentru a redirecta **STDOUT** sau **STDERR** într-un fișier.
Pentru a redirecta ieșirea standard folosim sintaxa ``cmd > nume-fișier``.
Pentru a redirecta ieșirea standard a erorilor folosim sintaxa ``cmd 2> nume-fișier``.

Implicit, operatoru ``>`` șterge (trunchează) conținutul fișierului destinație.
Dacă vrem să păstrăm conținutul fișierului și să adăugăm rezultatul redirectării în continuarea acestuia, folosim operatorul ``>>``.

Folosim sintaxa ``&> cale/către/nume-fișier`` pentru a redirecta atât STDERR, cât și STDOUT, în fișierul primit ca argument.

Fișiere speciale
""""""""""""""""

* Fișierul ``/dev/null`` este un fișier care ignoră orice este scris în el.

* Fișierul ``/dev/zero`` este un generator de octeți.
  Acesta generează atâția octeți cu valoarea zero (**0**) [#dev-zero]_ cât îi sunt ceruți.

* Fișierul ``/dev/urandom`` este un alt generator de octeți.
  Acesta generează atâția octeți cu valoare random cât îi sunt ceruți.
