Căi în ierarhia de fișiere
==========================

Atunci când folosim un terminal este important să știm unde ne aflăm în ierarhie.
Dacă vrem să jucăm un joc, știm că vrem să ajungem în directorul ``Games``, unde avem jocul preferat, ``Warcraft3``.
Pentru a ajunge în directorul ``Games``, trebuie să știm unde suntem și apoi să navigăm în sistemul de fișiere până acolo.

O ierarhie de fișiere și directoare este o structură de organizare a acestora.
Structura ierarhică permite gruparea acestora în directoare, ce conțin la rândul lor alte directoare sau fișiere.
În acest fel, putem lucra doar cu un subset de fișiere și directoare din totalitatea acestora de pe sistem.


Un astfel de exemplu este următorul:

.. figure:: res/ierarhie.png


În Linux, începutul acestei ierarhii este ``/``, directorul rădăcină al sistemului de fișiere (root directory).
Dacă privim sistemul de fișiere ca un arbore întors, directorul rădăcină este chiar rădăcina acestui arbore.
De acolo cresc ramurile și frunzele sistemului de fișiere, formând ceea ce vom numi căi (paths).

Putem vedea mai jos începutul ierarhiei din Linux:

.. code-block:: bash

    student@uso:/$ tree -L 1 /
    /
    |-- bin
    |-- boot
    |-- dev
    |-- etc
    |-- home
    |-- initrd.img -> /boot/initrd.img-3.16.0-4-586
    |-- lib
    |-- lib64
    |-- libx32
    |-- lost+found
    |-- media
    |-- mnt
    |-- opt
    |-- proc
    |-- root
    |-- run
    |-- sbin
    |-- srv
    |-- sys
    |-- tmp
    |-- usr
    |-- var
    ``-- vmlinuz -> boot/vmlinuz-3.16.0-4-586

Observăm ``/`` (directorul rădăcină) la începutul ierarhiei.
Pe nivelul următor, adică ramuri / copii ai directorului rădăcină, sunt directoarele ``bin``, ``boot``, ``dev`` etc.

Observăm conținutul directorul ``home``:

.. code-block:: bash

    student@uso:/home$ tree -L 1 /home
    .
    |-- student
    ``-- test

Există două directoare ``student`` și ``test``.

.. note::
    Observăm cum se schimbă promptul de terminal:

    * în primul exemplu ``student@uso:/$ tree -L 1 /`` eram în directorul ``/``.
    * în al doilea exemplu ``student@uso:/home$ tree -L 1`` eram în directorul ``/home``.

Avansăm în ierarhia de directoare către ``student``:

.. code-block:: bash

    student@uso:~$ tree
    .
    |-- comenzi
    |   |-- executie
    |   |-- ls
    |   |   ``-- mkdir -> /home/student/comenzi/mkdir/
    |   |-- mkdir
    |   |   |-- Avengers
    |   |   |   |-- Captain\ America
    |   |   |   |-- Iron\ Man
    |   |   |   ``-- Thor
    |   |   ``-- GameOfThrones
    |   |       |-- Arya\ Stark
    |   |       |-- Daenerys\ Targaryen
    |   |       |-- Jon\ Snow
    |   |       ``-- Tyrion\ Lannister
    |   |-- my_ls
    |   ``-- touch
    |       |-- orase
    |       |-- orase\ romania
    |       ``-- romania
    |-- comenzi_redirectare
    |-- continut_materii
    |-- dezarhivare
    |   |-- tar
    |   ``-- zip
    |       |-- fisier1
    |       |-- fisier2
    |       ``-- fisier3
    |-- ELTH
    |-- erori_comenzi
    |-- fisier
    |-- fisier1
    |-- fisier2
    |-- fisier3
    |-- fisier4
    |-- fisiere.zip
    |-- inregistrari.tar
    |-- inregistrari.zip
    |-- materii
    |-- orase
    |-- scurtaturi.save
    |-- test.zip
    |-- USO
    |-- usr_bin.tar
    ``-- usr_bin.zip


Directorul acesta este directorul *home* al utilizatorului *student*.
În rezultatul comenzii ``tree``, vedem întreaga ierarhie a directorului ``/home/student``.

În continuare detaliem conceptul de cale.

Calea curentă
-------------

Pornim de la următoarea analogie: Avem patru puncte pe o dreaptă: A, B, C și D.
Pentru a ajunge de la A la D, trebuie să trecem prin B și C.
Astfel, avem următoarele segmente: AB, BC, CD.

Similar, pentru sistemul de fișiere, pornim de la directorul rădăcină (``/``) și să coborâm în jos pe arbore.


Lista de directoare intermediare de la rădăcina ierarhiei de fișiere (``/``) până la un anumit fișier sau director se numeste *cale*.

*Calea curentă* este pozitia noastră în sistemul de fișiere.

În lina de comandă afișăm calea până la directorul în care ne aflăm (*calea curentă*) folosind comanda ``pwd`` (*print working directory*) :

.. code-block:: bash

    student@uso:~$ pwd
    /home/student

Aceasta afișează poziția noastră în sistemul de fișiere.

Ne mutăm la calea ``/usr/bin`` folosind comanda ``cd`` (*change directory*):

.. code-block:: bash

    student@uso:~$ pwd
    /home/student
    student@uso:~$ cd /usr/bin/
    student@uso:/usr/bin$ pwd
    /usr/bin

Acum ne aflăm la poziția ``/usr/bin`` în sistemul de fișiere.
Observăm cum calea curentă se schimbă atunci când schimbăm directorul în care ne aflăm.
Vom vorbi despre comanda ``cd`` în capitolul *Îmbunătățirea lucrului în linia de comandă*.

Separator de cale
-----------------

În exemplele de mai sus, observăm că există un delimitator între directoare: / (slash).
Atunci când compunem calea, după fiecare nod/director (nivel de arbore) prin care trecem, punem acest delimitator.
Astfel, îi transmitem sistemului de operare că am înaintat în ierarhia de fișiere.

Faptul că și directorul rădăcină (``/``) are același simbol, este doar o coincidență.
În Windows, nodul rădăcină este ``C:``, iar separatorul de cale este \\.

Cale relativă și cale absolută
------------------------------

Atunci când vrem să citim, scriem, ștergem un fișier sau director trebuie să ne referim la acel fișier sau director.
Practic, *orice operație în sistemul de fișiere (arhivare, criptare, ștergere, editare) folosește căi*.
Este impropriu să spunem "deschide fișierul ``/home/student/a.txt``"; tehnic corect este "deschide fișierul de la calea ``/home/student/a.txt``".

În sistemul de fișiere, ne putem referi la un fișier prin 2 modalități: folosind *calea relativă* sau folosind *calea absolută*.

Spre exemplu, luăm un serial pe Netflix. Ne referim la un episod în două moduri:

* Față de început - primul episod (în mod absolut): *În episodul 213 s-a întâmplat ceva.*
* Față de episodul la care ne aflăm (în mod relativ): *În urmă cu 3 episoade s-a întâmplat ceva.*

Similar, ne referim la un fișier:

* Pornind din rădăcina ierarhiei de fișiere (*root*), reprezentat prin simbolul ``/``, numită  *cale absolută*.
* Pornind de la directorul în care ne află (*director curent*), numită *cale relativă*.


Cale absolută
"""""""""""""

După cum am precizat mai sus, calea absolută începe întotdeauna cu caracterul ``/`` (slash), denumit și *director rădăcină*.
Acesta indică începutul ierarhiei de fișiere.

Afișam fișierele ``/usr/bin/touch`` și ``/etc/passwd`` prin cale absolută, folosind ``ls``:

  .. code-block:: bash

      student@uso:~$ ls -l /usr/bin/touch
      lrwxrwxrwx 1 root root 10 Mar 14  2015 /usr/bin/touch -> /bin/touch
      student@uso:~$ ls -l /etc/passwd
      -rw-r--r-- 1 root root 1768 Sep  9 14:07 /etc/passwd

Am folosit opțiunea *-l* a utilitarului ``ls`` pentru a afișa informații suplimentare ale fisierelor.

Observăm că la începutul căilor este întotdeauna caracterul **/** (directorul rădăcină).

Cale relativă
"""""""""""""

Prin calea relativă ne referim la un fișier în funcție de calea curentă.

.. code-block:: bash

    student@uso:~$ ls -l comenzi/mkdir/
    total 8
    drwxr-xr-x 2 student student 4096 Sep 29 18:20 Avengers
    drwxr-xr-x 2 student student 4096 Sep 29 19:21 GameOfThrones

În exemplul de mai sus, ne aflăm la calea ``/home/student`` și am coborât în jos în ierarhia de fișiere către directorul ``comenzi``, apoi directorul ``mkdir``.

Același rezultat îl obținem folosind calea absolută:

.. code-block:: bash

    student@uso:~$ ls -l /home/student/comenzi/mkdir/
    total 8
    drwxr-xr-x 2 student student 4096 Sep 29 18:20 Avengers
    drwxr-xr-x 2 student student 4096 Sep 29 19:21 GameOfThrones

Calea ``/home/student/comenzi/mkdir/`` este validă oricare ar fi calea curentă (oriunde ne-am afla în ierarhia de fișiere).

În acest caz, este mai eficient să folosim *calea relativă*.
În cazul în care putem ajunge mai repede de la directorul rădăcina ``/`` la directorul țintă, este mai utilă *calea absolută*.


Intrarea ``..`` în sistemul de fișiere
""""""""""""""""""""""""""""""""""""""

Referim aceleași fișiere (``/usr/bin/touch`` și ``/etc/passwd``) prin cale relativă, folosind ``ls``:

.. code-block:: bash

    student@uso:~$ pwd
    /home/student
    student@uso:~$ ls -l ../../usr/bin/touch
    lrwxrwxrwx 1 root root 10 Mar 14  2015 ../../usr/bin/touch -> /bin/touch
    student@uso:~$ ls -l ../../etc/passwd
    -rw-r--r-- 1 root root 1768 Sep  9 14:07 ../../etc/passwd

Observăm că ne aflăm la calea ``/home/student`` și urcăm spre vârful ierarhiei de fișiere folosind caracterele ``..``.

Odată ajunși la *directorul rădăcină* ``/``, coborâm spre fișierul ``touch``, trecând prin directoarele ``usr`` și ``bin``.

.. note::
    Este bine să ne referim la ``..`` ca *punct punct*, nu două puncte *:* pentru a elimina confuziile.

Exerciții
"""""""""

* Afișați calea curentă folosind utilitarul ``pwd``.
* Referiți fișirele/directoarele ``/lib/``, ``/home``, ``/bin/cat`` atât prin cale relativă cât și prin cale absolută.
* Referiți directorul părinte (un nivel mai sus față de cel curent).


Schimbarea căii curente
-----------------------

Plasarea noastră într-un alt director decât cel curent înseamnă schimbarea căii curente.
Facem acest lucru folosind comanda ``cd`` (*change directory*):

.. code-block:: bash

    student@uso:/etc$ pwd
    /etc
    student@uso:/etc$ cd /usr
    student@uso:/usr$ pwd
    /usr

Am schimbat calea curentă de la ``/etc`` la ``/usr``.
Această comandă poate fi folosită oriunde ne-am afla deoarece este o *cale absolută*.

.. important::
    În general, comanda ``cd`` schimbă promptul terminalului; aceasta este o indicație a directorului curent în care ne aflăm:

    * în cazul ``student@uso:/etc$ pwd`` ne aflăm în ``etc``
    * în cazul ``student@uso:/usr$ pwd`` ne aflăm în ``pwd``

.. note::
    La fel ca toate comenzile de lucru cu sistemul de fișiere, comanda ``cd`` primește ca parametru o cale. Aceasta poate fi atât *relativă* cât și *absolută*.

Schimbăm calea curentă în ``/home/student``, folosind ``cd``:

.. code-block:: bash

    student@uso:/usr$ cd /home/student
    student@uso:~$ pwd
    /home/student

Fiind la calea ``/usr``, am folosit utilitarul ``cd`` împreună cu o cale *absolută* ``/home/student`` pentru a schimba calea curentă.
Cea de-a doua comanda ``pwd`` confirmă că am schimbat calea curentă.


Acum ne aflăm la calea ``/home/student``.
O alternativă mai puțin eficientă este să facem schimbarea căii curente în doi pași, astfel:

.. code-block:: bash

    student@uso:~$ cd /home
    student@uso:/home$ pwd
    /home
    student@uso:/home$ cd student/
    student@uso:~$ pwd
    /home/student

Schimbăm calea curentă la ``/usr/bin`` folosind cale relativă:

.. code-block:: bash

    student@uso:~$ pwd
    /home/student
    student@uso:~$ cd ../../usr/bin
    student@uso:/usr/bin$ pwd
    /usr/bin

.. important::
    Una dintre cele mai importate informații când lucrăm în sistemul de operare (în special în linia de comandă) este unde ne aflăm.
    Dacă știm unde ne aflăm, ne putem orienta către destinație.
    Știm unde ne aflăm folosind comanda ``pwd``; ne deplasăm în altă parte folosind comanda ``cd``.


Observăm cum am urcat în ierarhie folosind ``..`` până la ``/`` (*directorul rădăcină*) iar apoi am coborât spre ``usr`` și apoi ``bin``.

În exemplul de mai jos, comanda de mai sus nu este valabilă:

.. code-block:: bash

    student@uso:~/comenzi$ pwd
    /home/student/comenzi
    student@uso:~/comenzi$ cd ../../usr/bin
    -bash: cd: ../../usr/bin: No such file or directory

Observăm că suntem la calea ``/home/student/comenzi``.
Executând comanda ``cd ../../usr/bin`` de mai sus, am ajunge la calea ``/home/usr/bin`` care nu există.


Exerciții - schimbarea directorului curent
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Schimbați directorul curent cu directorul de la calea ``/usr/bin``. Folosiți cale absolută.
* Schimbați directorul curent cu directorul de la calea ``/etc/``. Folosiți cale relativă.
* Schimbați directorul curent cu directorul de la calea ``/etc/network/``. Folosiți cale relativă.

TAB completion
--------------

Funcția de *tab completion* este probabil una dintre cele mai utile funcții expuse de către shell.
Prin simpla apăsare a tastei ``Tab`` în timp ce scriem numele unei comenzi, al unei opțiuni a unei comenzi sau calea către un director sau fișier, shellul va completa în mod automat textul sau va sugera opțiuni de auto-complete.

.. figure:: res/tab_completion.gif

Observăm că atunci când calea pe care o scriem se termină cu */* (slash), apăsând de 2 ori pe tasta ``Tab`` ne arată fișierele și directoarele din calea respectivă.
Atunci vrem să ne auto-completeze numele, apăsăm o singură dată pe tasta ``Tab``.

Tasta ``Tab`` este descrisă în detaliu în capitolul *Îmbunătățirea lucrului în linia de comandă*.


Scurtături de căi
-----------------

Pentru o eficiență mai bună, putem folosi simboluri pentru interacțiunea cu utilitarul ``cd``:

* Folosim caracterul (``-``) pentru a referi la *calea anterioară*.


  .. code-block:: bash

    student@uso:~$ pwd
    /home/student
    student@uso:~$ cd /usr/bin/
    student@uso:/usr/bin$ pwd
    /usr/bin
    student@uso:/usr/bin$ cd -
    /home/student
    student@uso:~$ cd -
    /usr/bin
    student@uso:/usr/bin$ cd -
    /home/student
    student@uso:~$ cd -
    /usr/bin

Observăm că, dacă folosim repetat comanda ``cd -`` ,vom face un joc *du-te-vino* (*ping-pong*) între 2 directoare.

* Folosim caracterul (``~``) pentru a referi *directorul home* a utilizatorului.

  .. code-block:: bash

    student@uso:/usr/bin$ cd /tmp/
    student@uso:/tmp$ pwd
    /tmp
    student@uso:/tmp$ cd ~
    student@uso:~$ pwd
    /home/student
    student@uso:~$ cd /usr/bin/X11/
    student@uso:/usr/bin/X11$ pwd
    /usr/bin/X11
    student@uso:/usr/bin/X11$ cd ~
    student@uso:~$ pwd
    /home/student


.. note::
    Atunci când suntem în directorul home, promptul conține caracterul ``~`` pentru a indica acest lucru.
