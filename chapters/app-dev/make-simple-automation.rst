Introducere în utilitarul Make și fișiere Makefile
==================================================

Folosirea unui Makefile existent
--------------------------------

Aici vor avea la dispoziție un director cu cod sursă și Makefile și vor 
rula toate targeturile din Makefile, pe rând, și vor observa care este efectul fiecăreia.
Abia după ce se acomodează cu acest lucru își vor crea propriul Makefile.

Crearea primului Makefile
-------------------------

Vor crea un Makefile simplu.

Adăugarea targetului all
^^^^^^^^^^^^^^^^^^^^^^^^

Vor adăuga targetul all.

Adăugarea targetului clean
^^^^^^^^^^^^^^^^^^^^^^^^^^

Vor adăuga targetul clean.

Adăugarea fișierului Makefile în repository
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Vor comite modificările făcute anterior.

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

Crearea unui nou commit cu modificărilor făcute
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Vor comite modificările aduse asupra fișierului Makefile.

Wildcards
^^^^^^^^^^

Acum că ați înțeles importanța compilării separate, cum am proceda 
pentru un proiect care are sute de fișiere sursă? Goto wildcards.
