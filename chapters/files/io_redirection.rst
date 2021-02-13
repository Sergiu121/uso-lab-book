Redirectări
===========

Până acum am dat comenzi în terminal și am urmărit outputul (rezultatul) lor. Outputul este afișat în terminal.
Dacă voiam să salvăm outputul undeva (*de obicei într-un fișier*) trebuia să copiem outputul, să creăm un fișier nou sau să folosim unul deja existent, să îl deschidem, să lipim textul în el și să salvăm modificările.
Trecerea prin toți acești pași durează și devenim ineficienți în lucrul în terminal.

Interpretorul de comenzi (*shellul*) are opțiunea de a direcționa afișarea rezultatului direct într-un fișier.

Rezultatul unei comenzi este format din două fluxuri de informații: informații de ieșire (*standard output, stdout*) și de eroare (*standard error, stderr*).
Avem opțiunea de a direcționa (*redirecta*) doar ieșirea, doar eroarea sau ambele fluxuri într-un fișier.

Redirectări simple
------------------

În directorul ``/home/student`` (``~``) avem mai multe fișiere, câte unul pentru fiecare materie.
Afișăm fișierele folosind comanda ``ls``:

.. code-block:: bash

    student@uso:~$ ls -lh
    total 9.0M
    -rw-r--r-- 1 student student 5.0M Aug 19 11:55 USO
    -rw-r--r-- 1 student student 3.0M Aug 19 11:55 RL
    -rw-r--r-- 1 student student 1.0M Aug 19 11:55 EGC


Salvăm outputul comenzii ``ls -lh`` de mai sus folosind caracterul ``>``, astfel:

.. code-block:: bash

    student@uso:~$ ls -lh > lista_materii
    student@uso:~$ ls
    USO RL EGC lista_materii

Observăm că acțiunea de mai sus a făcut două lucruri: a creat fișierul ``lista_materii`` și a introdus în conținutul fișierului rezultatul comenzii ``ls -lh``.

Caracterul ``>`` așteaptă un șir de caractere după el care este numele fișierului în care vrem să scriem outputul.
Șirul este de fapt calea către un fișier.
Șirul ``lista_materii`` este calea relativă până la fișierul ``lista_materii`` care se află în directorul curent ``/home/student``.

Fișierul ``lista_materii`` nu exista. Prin direcționarea outputului am creat fișierul ``lista_materii``.

Vizualizăm conținutul fișierului lista_materii folosind comanda cat:

.. code-block:: bash

    student@uso:~$ cat lista_materii
    -rw-r--r-- 1 student student 5.0M Aug 19 11:55 USO
    -rw-r--r-- 1 student student 3.0M Aug 19 11:55 RL
    -rw-r--r-- 1 student student 1.0M Aug 19 11:55 EGC


.. note::
    Odată direcționat într-un fișier, fluxul de informații nu mai apare la ecran.

Folosirea caracterului ``>`` suprascrie conținutul fișierului:

.. code-block:: bash

    student@uso:~/comenzi/mkdir$ cat lista_materii
    cat: lista_materii: No such file or directory
    student@uso:~$ ls -l /usr/ > lista_materii
    student@uso:~$ cat lista_materii
    total 72
    drwxr-xr-x   2 root root  32768 Sep  9 14:07 bin
    drwxr-xr-x   2 root root   4096 Aug 31  2015 games
    drwxr-xr-x  34 root root   4096 Sep  9 14:06 include
    drwxr-xr-x  74 root root   4096 Sep  9 14:07 lib
    drwxr-xr-x   3 root root   4096 Nov 21  2015 lib64
    drwxr-xr-x   3 root root   4096 Nov 21  2015 libx32
    drwxrwsr-x  10 root staff  4096 Nov 21  2015 local
    drwxr-xr-x   2 root root   4096 Sep  9 14:07 sbin
    drwxr-xr-x 137 root root   4096 Sep  9 14:07 share
    drwxr-xr-x   2 root root   4096 Aug 31  2015 src

Fișierul ``lista_materii`` nu era crea inițial.
În urma comenzii ``ls -l /usr/ > lista_materii``, fișierul ``lista_materii`` a fost creat și populat cu ieșirea comenzii ``ls -l /usr/``.

Exerciții - redirectări simple
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Folosiți ``tree`` pentru a afișa ierarhia de fișiere pornind de la **/home/student**;
* Folosiți ``tree`` pentru afișarea aceleiași ierarhii, dar de data asta direcționați-o în fișierul ``ierarhie_student``;
* Inspectați fișierul pentru a demonstra corectitudinea operației.

Redirectări prin anexare
------------------------

Putem direcționa rezultatul comenzii, *fără* a suprascrie fișierul.
Face acest lucru folosim caracterele ``>>``:

.. code-block:: bash

    student@uso:~$ ls >> lista_materii
    student@uso:~$ ls
    USO RL EGC lista_materii
    student@uso:~$ cat lista_materii
    -rw-r--r-- 1 student student 5.0M Aug 19 11:55 USO
    -rw-r--r-- 1 student student 3.0M Aug 19 11:55 RL
    -rw-r--r-- 1 student student 1.0M Aug 19 11:55 EGC
    USO RL EGC lista_materii

Acum avem în fișierul ``lista_materii``, pe lângă conținutul vechi, și outputul comenzii ``ls``.

Exerciții - direcționări prin anexare
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#. * Folosiți ``tree`` pentru a afișa ierarhia de fișiere pornind de la ``/tmp``;
   * Folosiți ``tree`` pentru a afișa aceeași ierarhie, dar de data asta direcționați-o prin anexare la fișierul ``ierarhie_student`` creat anterior;
   * Afisați conținutul fișierului ``ierarhie_student`` folosind comanda ``cat``.


#. * Folosiți ``tree`` pentru a afișa ierarhia de fișiere pornind de la ``/usr``;
   * Repetați comanda anterioara, dar de data asta direcționați-o *fără* anexare la fișierul ``ierarhie_student`` folosit anterior;
   * Afisați conținutul fișierului ``ierarhie_student`` folosind comanda ``cat``.
     Mai exista conținutul inițial al fișierului?


Redirectări de eroare
---------------------

Atunci când direcționăm ieșirea unei comenzi folosind ``>`` sau ``>>``, ne referim *doar* la ieșirea standard, nu și la erori.

Folosim caracterele ``2>`` pentru a direcționa ieșirea de eroare către un fișier:

.. code-block:: bash

    student@uso:~$ ls
    USO RL EGC lista_materii
    student@uso:~$ cat lista_materie
    cat: lista_materie: No such file or directory

Am vrut să afișăm conținutul fișierului *lista_materie*, însă acest fișier nu există.
Am primit informația *No such file or directory*, și aceasta este afișată *sub formă de eroare*.

Direcționăm conținutul fișierului ``SO2`` în fișierul *materii*:

.. code-block:: bash

    student@uso:~$ cat SO2 > materii
    cat: SO2: No such file or directory

Vedem că dacă folosim direcționarea simplă ``>``, eroarea tot este afișată.

.. note::
    Chiar dacă comanda de interes eșuează, direcționarea este făcută. În cazul de mai sus, fișierul ``materii`` este creat.

.. code-block:: bash

    student@uso:~$ cat SO2 2> materii
    student@uso:~$ cat materii
    cat: SO2: No such file or directory

Observăm că nu am primit eroare la prima comandă unde am încercat să afișăm conținutul unui fișier inexistent.
Informațiile de eroare au fost direcționate în fișier.


Redirectările de eroare și ieșire pot fi folosite simultan folosind caracterele specifice ``>`` pentru ieșire și ``2>`` pentru eroare.
Putem folosi sintaxa ``comanda > fișier_ieșire 2> fișier_erori`` pentru a face acest lucru..

Ca să redirectăm și outputul și erorile de la o comandă folosim și ``>`` și ``2>`` ca mai jos:

.. code-block:: bash

    student@uso:~$ cat ELTH USO SO2
    ELTH is the b3st
    USO RULLZ
    cat: SO2: No such file or directory

În exemplul de mai sus încercăm să afișăm conținutul fișierelor ``ELTH``, ``USO`` și ``SO2``, dar cu fișierul ``SO2`` neexistent.
Liniile ``ELTH is the b3st`` și ``USO RULLZ`` sunt conținutul fișierelor ``ELTH`` și ``USO``.
Comanda ``cat`` ne-a arătat conținutul celor 2 fișiere.
Tot comanda ``cat`` a încercat să afișeze conținutul fișierului ``SO2``, însă el nu există și a afișat eroarea ``Not such file or directory``.


În continuare vom face o separare a fluxurilor: direcționăm ieșirea în fișierul ``continut_materii`` și erorile în fișierul ``erori_comenzi``:

.. code-block:: bash

    student@uso:~$ cat ELTH USO SO2 > continut_materii 2> erori_comenzi
    student@uso:~$ cat continut_materii
    USO is the b3st
    USO RULLZ
    student@uso:~$ cat erori_comenzi
    cat: SO2: No such file or directory

Observăm cum după executarea primei comenzi, la ecran nu mai apare nimic; atât ieșirea standard cât și erorile au fost direcționate în fișiere.
În continuare am verificat conținutul acestor fișiere pentru a demonstra corectitudinea operației.
