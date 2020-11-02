.. _app_dev_simple_make:

Introducere în utilitarul Make și fișiere Makefile
==================================================

În secțiunile anterioare, am compilat fișiere cod sursă C folosind compilatorul GCC.
Dezvoltarea unui program este un proces *continuu*, nu scriem tot codul dintr-o singură iterație și de multe ori ajungem să îl modificăm pe parcurs.
Vrem să testăm schimbările aduse în program.
Pentru aceasta trebuie să *recompilăm* fișierul pe care l-am modificat și să creăm un nou executabil.

Automatizarea procesului de compilare ne ajută să fim eficienți atunci când dezvoltăm un proiect.
În loc să dăm de fiecare dată toate comenzile pentru recompilarea fișierelor, putem să dăm o singură comandă care să le facă pe toate.
Acest proces se numește *build automation*.
Există mai multe soluții de build automation [#build_automation]_.
În această carte vom folosi utilitarul `Make <https://linux.die.net/man/1/make>`_ împreună cu fișiere `Makefile <https://www.gnu.org/software/make/manual/make.html#Makefiles>`_ ca să automatizăm procesul de compilare.

În secțiunile următoare vom folosi vedea cum funcționează utilitarul Make și cum arată un fișier Makefile.
După, vom crea un fișier Makefile pentru un proiect dat.

.. _app_dev_use_makefile:

Folosirea unui Makefile existent
--------------------------------

În această secțiune vom compila programul `Hangman <https://rextester.com/WYT71966>`_ folosind un fișier Makefile.

Întrăm în directorul ``~/support/simple-make`` folosind comanda ``cd``:

.. code-block:: bash

    student@uso:~$ cd ~/support/simple-make
    student@uso:~/support/simple-make$ ls
    hangman.c  Makefile

Avem în director un fișier cod sursă C, ``hangman.c``, și un fișier Makefile.
Ca să compilăm programul, folosim comanda ``make``:

.. code-block:: bash

    student@uso:~/support/simple-make$ make
    gcc -c hangman.c
    gcc -o hangman hangman.o
    student@uso:~/support/simple-make$ ls
    hangman  hangman.c  hangman.o  Makefile

Comanda ``make`` a rulat, de fapt, 2 comenzi:

#. De *compilare*: ``gcc -c hangman.c``, comandă prin care am creat fișierul obiect ``hangman.o``
#. De *legare*: ``gcc -o hangman hangman.o``, comandă prin care am creat executabilul ``hangman``.

Practic, scriind doar comanda ``make``, am trecut fișierul ``hangman.c`` prin toate etapele compilării și am obținut executabilul final, așa cum am făcut în secțiunea :ref:`app_dev_compile_multiple_sources` pentru fișierele ``main.c`` și ``algorithms.c``.

Rulăm executabilul ``hangman`` ca să vedem că funcționează, ca în imaginea de mai jos:

.. figure:: gifs/run-hangman.gif
    :alt: Rularea programului ``hangman``


.. _app_dev_understand_makefile:

Înțelegerea formatului Makefile
-------------------------------

În secțiunea anterioară, :ref:`app_dev_use_makefile`, am folosit fișierul ``Makefile`` ca să compilăm programul Hangman.
Ca să putem crea un Makefile pentru un proiect al nostru, trebuie să înțelegem formatul fișierului Makefile.
În această secțiune vom folosi fișierul Makefile pe care l-am folosit anterior.

Fișierul ``Makefile`` folosit la programul Hangman are următorul conținut:

TODO: adaugă numere la linii

.. code-block:: 

    all: hangman

    hangman: hangman.o
        gcc -o hangman hangman.o

    hangman.o: hangman.c
        gcc -c hangman.c

    clean:
        rm -rf *.o hangman

Liniile din fișier sunt de două tipuri:

#. **Regulă**, care are formatul ``regulă: <dependență>`` (``all: hangman`` sau ``clean:``).
#. **Comandă**, care începe cu un ``Tab`` la începutul rândului, urmat de o comandă (``gcc -o hangman hangman.o``).

O *regulă* din fișierul Makefile este, de fapt, un nume asociat unei *comenzi*. Spunem că rulăm *regula* ``clean`` atunci când vrem să executăm *comanda* ``rm -rf *.o hangman``.
În terminal, facem acest lucru folosind comanda ``make`` urmată de numele regulii, în acest caz ``make clean``:

.. code-block:: bash

    student@uso:~/support/simple-make$ make clean
    rm *.o hangman
    student@uso:~/support/simple-make$ ls
    hangman.c   Makefile


Crearea primului Makefile
-------------------------

Vor crea un Makefile simplu.

Adăugarea targetului all
^^^^^^^^^^^^^^^^^^^^^^^^

Vor adăuga targetul all.

Adăugarea targetului clean
^^^^^^^^^^^^^^^^^^^^^^^^^^

Vor adăuga targetul clean.

Fișiere Makefile cu alte nume
-----------------------------

Aici vor redenumi fișierul Makefile creat anterior și îl vor folosi folosind `make -f`.
De asemenea vor comite această schimbare.

Adăugarea de targeturi pentru crearea fișierelor obiect
-------------------------------------------------------

Vor adăuga câte un target pentru fiecare fișier cod sursă pentru a-l compila până la modul obiect.

Modificarea targetului de creare a executabilului
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Vor modifica targetul existent astfel încât executabilul final să fie 
obținut din module obiect.

Modificarea targetului clean
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Vor adăuga fișierele obiect la targetul clean.

Testarea fișierului Makefile
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Vor testa toate targeturile și vor observa încă de aici că fișierele se recompilează
la fiecare rulare a targetului indiferent dacă fișierul obținut a fost modificat sau nu.

.. rubric:: Note de subsol

.. [#build_automation]

    Exemple de soluții de build automation sunt `Maven <https://maven.apache.org>`_, `Ant <https://ant.apache.org>`_, `Gradle <https://gradle.org>`_.
    
    https://en.wikipedia.org/wiki/Build_automation
    
    https://www.softwaretestinghelp.com/best-build-automation-software-tools/