Interacțiunea cu fișiere în linia de comandă
============================================

Fișierul este unitatea de bază folosită pentru a stoca informații.
Fie că este vorba despre un document (tema la mate) sau un joc, fie că este vorba de o configurare în sistemul de operare, sau chiar sistemul de operare, folosim fișiere pentru stocare.

Putem interacțioa cu fișiere folosind programe specifice:

* Microsoft Word pentru documente;
* browser (de exemplu, Firefox) pentru o pagină web;
* player audio (de exemplu, Winamp) pentu melodii;
* player video (de exemplu, Vlc) pentru filme.

Acestea au în comun o interfață grafică.
O altă opțiune este să interacționăm cu fișierele în linia de comandă.
Acesta este subiectul acestei sectiuni.

Folosim linia de comandă pentru interacțiunea cu fișierele în mai multe cazuri:

* Atunci când sistemul pe care ne aflăm are **doar** linie de comandă;
* Atunci când putem să facem anumite operații **mai repede** decât în interfața grafică; putem folosi automatizarea unor sarcini (taskuri): scriem un script (un fișier de automatizare) o dată și îl executăm de fiecare dată când este nevoie. Există un capitol întreg *Îmbunătățirea lucrului în linia de comandă* unde vom afla mai multe detalii.

Un motiv în plus pentru a folosi linia de comandă este că folosește mult mai puține resurse decât interfața grafică.
Astfel, putem să facem mai multe cu mai puține resurse.

Componenta ce se ocupă de interpretarea comenzilor se numește *shell*.
Shellul citește comenzile date de utilizator, le interpretează și comunică sisteemului de operare ce are de făcut.

În acest capitol discutăm despre cum interacționăm cu fișierele în linia de comandă.

Ierarhie de fișiere
-------------------

Un exemplu de ierarhie de fișier este în secțiunea *Căi în ierarhia de fișiere*.

Pentru a vedea fișierele sub formă arborescentă, folosim comanda ``tree``.

.. code-block:: bash

    student@uso:~/comenzi/mkdir$ tree -L 1 /
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



Lucrul cu fișiere și directoare
-------------------------------

În această secțiune vom învăța să lucrăm cu fișierele și directoarele în linia de comandă:

* afișarea conținutului fișierelor și directoarelor;
* crearea de fișiere și directoare;
* ștergerea de fișiere și directoare;
* redenumirea fișierelor și directoarelor;
* fișiere și directoare ascunse;
* legături (linkuri);
* execuția programelor.

Afișarea conținutului unui director
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Așa cum un dosar are mai multe foi în el, la fel și directoarele au mai multe fișiere și directoare în ele.

Pentru a afișa conținutul unui director folosim comanda ``ls``:

.. code-block:: bash

    student@uso:~/comenzi/mkdir/Avengers$ ls
    Captain America  Iron Man  Thor

Pentru a vedea mai multe informații despre fișiere și directoare putem folosi opțiunea ``-l`` în felul următor: ``ls -l``.

.. code-block:: bash

    student@uso:~/comenzi/touch$ ls -l
    total 0
    -rw-r--r-- 1 student student 0 Sep 29 17:32 cities
    -rw-r--r-- 1 student student 0 Sep 29 17:25 cities in romania
    -rw-r--r-- 1 student student 0 Sep 29 17:33 romania

.. code-block:: bash

    student@uso:~/comenzi/mkdir$ ls -l
    total 8
    drwxr-xr-x 2 student student 4096 Sep 29 18:20 Avengers
    drwxr-xr-x 2 student student 4096 Sep 29 19:21 GameOfThrones

Interpretăm rezultatele de mai sus:

#. Primul caracter ``-`` ne arată că ``romania`` este un fișier obișnuit. Primul caracter ``d`` ne arată că ``Avengers`` este director.
#. Șirurile ``rw-r--r--`` (pentru ``romania``) și ``rw-r-xr-x`` (pentru ``Avengers``) se referă la permisiuni de acces.
   Vorbim despre permisiuni de acces în capitolul *Îmbunătățirea lucrului în linia de comandă*.
#. Următorul număr îl îgnorăm pentru moment.
#. Următoarele două cuvinte, ``student``, se referă tot la permisiuni și ownership; le vom discuta într-un capitol ulteror.
#. Numărul ``0`` arată dimensiunea fișierului ``romania``.
   Observăm că directorul ``Avengers`` are dimensiunea de 4096 octeți (*bytes*);
#. Urmează 3 coloane ce arată momentul ultimei modificări
   O accesare poate înseamna creare sau modificare.
   Citirea nu schimbă această dată.
#. La final este afișat numele fișierului sau a directorului.


Exerciții - afișarea conținutului directoarelor
"""""""""""""""""""""""""""""""""""""""""""""""

* Afișați conținutul directoarelor **/usr**, **/tmp**, **/etc**, **/home**, **/home/student**.

Crearea fișierelor
^^^^^^^^^^^^^^^^^^

Există situații când vrem să creăm fișiere.
De exemplu vrem să scriem cod sau să luăm notițe la un curs.

Fișierele se creează folosind utilitarul ``touch``.

Creăm un fișier astfel:

.. code-block:: bash

    student@uso:~$ ls cities
    ls: cannot access cities: No such file or directory
    student@uso:~$ touch cities
    student@uso:~$ ls cities
    cities


Dacă vrem să creăm un fișier cu numele ``orașe romania``, adică vrem ca numele fișierului să conțină caracterul *spațiu (space)*, folosim tot comanda ``touch`` ca în exemplul de mai jos:

.. code-block:: bash

    student@uso:~/touch$ touch cities romania
    student@uso:~/touch$ ls -l
    -rw-r--r-- 1 student student 0 Sep 29 17:22 cities
    -rw-r--r-- 1 student student 0 Sep 29 17:22 romania

Observăm că în comanda de mai sus am încercat să creăm un fișier numit ``cities romania``, însă au fost create două fișiere.
Pentru a crea un fișier cu *spații (space)* inclus în nume este nevoie să folosim ghilimelele la începutul și sfârșitul numelui astfel: ``touch "cities romania"``.

.. code-block:: bash

    student@uso:~/touch$ touch "cities in romania"
    student@uso:~/touch$ ls -l
    total 0
    -rw-r--r-- 1 student student 0 Sep 29 17:22 cities
    -rw-r--r-- 1 student student 0 Sep 29 17:25 cities in romania
    -rw-r--r-- 1 student student 0 Sep 29 17:22 romania


Acum avem în directorul ``~`` 3 fișiere: ``cities``, ``cities in romania``, ``romania``.
Zero-ul *(0)* din linia ``-rw-r--r-- 1 student student 0 Sep 29 17:22`` cities ne arată că fișierul cities are 0 bytes, adică este gol.
Toate cele 3 fișiere sunt goale.


Ce se va întâmpla dacă executăm ``touch`` pe un fișier existent?

Creăm un nou fișier cu numele ``romania`` folosind comanda ``touch``:

.. code-block:: bash

    student@uso:~/touch$ ls -l
    total 0
    -rw-r--r-- 1 student student 0 Sep 29 17:32 cities
    -rw-r--r-- 1 student student 0 Sep 29 17:25 cities in romania
    -rw-r--r-- 1 student student 0 Sep 29 17:22 romania
    student@uso:~/touch$ date
    Tue Sep 29 17:32:55 EEST 2020
    student@uso:~/touch$ touch romania
    student@uso:~/touch$ ls -l
    total 0
    -rw-r--r-- 1 student student 0 Sep 29 17:32 cities
    -rw-r--r-- 1 student student 0 Sep 29 17:25 cities in romania
    -rw-r--r-- 1 student student 0 Sep 29 17:33 romania


În continuare avem tot 3 fișiere în directorul ``~``.
Ne uităm la liniile ``-rw-r--r-- 1 student student 0 Sep 29 17:22 romania`` *(de dinainte)* și ``-rw-r--r-- 1 student student 0 Sep 29 17:33 romania`` (**de după**) și vedem că diferă timpul.
Este vorba despre timpul la care a fost ultima dată accesat fișierul ``romania``.

Crearea directoarelor
^^^^^^^^^^^^^^^^^^^^^

Este util să creăm directoarele atunci când vrem să păstrăm fișierele din sistem într-un mod organizat.
De exemplu, putem crea câte un director pentru fiecare an de licență.
Pentru fiecare an/director, cream câte un director pentru fiecare materie si pentru fiecare materie putem să facem directoare pentru teme, laboratoare, cursuri etc.

Creăm directoarele folosind utilitarul ``mkdir``.
Etimologia comenzii provine din limba engleză - *make directory*.

Creăm un director nou în directorul ``~/comenzi/mkdir`` ca în exemplul de mai jos:

.. code-block:: bash

    student@uso:~/comenzi/mkdir$ mkdir GameOfThrones
    student@uso:~/comenzi/mkdir$ mkdir Avengers
    student@uso:~/comenzi/mkdir$ ls -l
    total 8
    drwxr-xr-x 2 student student 4096 Sep 29 17:43 Avengers
    drwxr-xr-x 2 student student 4096 Sep 29 17:43 GameOfThrones

Am creat 2 directoare noi: ``Avengers`` și ``GameOfThrones``.
Pentru crearea directorului ``GameOfThrones`` am folosit ghilimele pentru a înconjura numele ales, la fel ca în cazul creării fișierelor din subsecțiunea :ref:todo_ref_``Crearea fișierelor``.



Exerciții - creare fișiere și directoare
""""""""""""""""""""""""""""""""""""""""

* Creați două directoare: "Avengers", "GameOfThrones"; afișați directoarele;
* Creați fișierele "Iron Man", "Hulk", "Thor", "Captain America" în directorul "Avengers"; afișați fișierele din director;
* Creați fișierele "Arya", "Daenerys Targaryen", "Jon Snow", "Tyrion Lannister" în directorul "GameOfThrones"; afișați fișierele din director.


.. important::
    Este important de reținut: orice comandă executați, aceasta trebuie succedată de o verificare.
    De exemplu, la crearea unui fișier (``touch``) sau director (``mkdir``), executăm comanda de verificare ``ls``.


Afișarea conținutului unui fișier
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Afișăm rapid conținutul fișierului ``Arya`` din directorul ``GameOfThrones`` folosind comanda ``cat``:

.. code-block:: bash

    student@uso:~/comenzi/mkdir$ cat GameOfThrones/Arya
    A girl has no name


.. hint::
    Pentru a adăuga rapid text într-un fișier folosim utilitarul ``echo`` astfel:

    .. code-block:: bash

        student@uso:~$ echo "A girl has no name" > "comenzi/mkdir/GameOfThrones/Arya"
        student@uso:~$ cat "comenzi/mkdir/GameOfThrones/Arya"
        A girl has no name



O altă metodă este de a folosi un editor de text: **vim**, **gedit**, **emacs**, **nano**, **sublime**, etc.
Vom detalia utilizarea unui editor de text în subsectiunea *Editor de text*.


Ștergerea fișierelor
^^^^^^^^^^^^^^^^^^^^

Fișierele se șterg folosind utilitarul ``rm``.

.. code-block:: bash

    student@uso:~/comenzi/mkdir$ ls Avengers/
    Captain America  Hulk  Iron Man  Thor
    student@uso:~/comenzi/mkdir$ rm Avengers/Hulk
    student@uso:~/comenzi/mkdir$ ls Avengers/
    Captain America  Iron Man  Thor

La prima comandă am afișat ce fișiere sunt în directorul ``Avengers``.
Am folosit utiltarul ``rm`` pentru a șterge fișierul ``Hulk`` din directorul ``Avengers``.
În final am verificat că fișierul ``Hulk`` nu mai există în directorul ``Avengers``.

Ștergerea directoarelor
^^^^^^^^^^^^^^^^^^^^^^^

Directoarele se șterg folosind comanda ``rmdir``.
Etimologia comenzii provine din engleză - *remove directory*.

.. code-block:: bash

    student@uso:~/comenzi/mkdir$ mkdir LordOfTheRings
    student@uso:~/comenzi/mkdir$ ls -l
    total 12
    drwxr-xr-x 2 student student 4096 Sep 29 18:02 Avengers
    drwxr-xr-x 2 student student 4096 Sep 29 17:44 GameOfThrones
    drwxr-xr-x 2 student student 4096 Sep 29 18:09 LordOfTheRings
    student@uso:~/comenzi/mkdir$ rmdir "LordOfTheRings"
    student@uso:~/comenzi/mkdir$ ls -l
    total 8
    drwxr-xr-x 2 student student 4096 Sep 29 18:02 Avengers
    drwxr-xr-x 2 student student 4096 Sep 29 17:44 GameOfThrones

Am creat un director ``LordOfTheRings`` folosind utilitarul ``mkdir``.
Am verificat crearea acestuia.
În final l-am șters folosind utilitarul ``rmdir`` și am verificat ștergerea acestuia.

.. important::
    Comanda ``rmdir`` pe un director care nu este gol (care conține cel puțin un alt fișier sau director) nu funcționează.


.. code-block:: bash

    student@uso:~/comenzi/mkdir$ rmdir Avengers/
    rmdir: failed to remove 'Avengers/': Directory not empty


Pentru a șterge un director care **nu** este gol, folosim utilitarul ``rm`` cu opțiunea de recursivitate ``-r``: ``rm -r``.
Aceasta permite parcurgerea în adâncime a întregii ierarhii de fișiere.


.. code-block:: bash

    student@uso:~/comenzi/mkdir$ ls -l
    total 8
    drwxr-xr-x 2 student student 4096 Sep 29 18:02 Avengers
    drwxr-xr-x 2 student student 4096 Sep 29 17:44 GameOfThrones
    student@uso:~/comenzi/mkdir$ rm -r Avengers/
    student@uso:~/comenzi/mkdir$ ls -l
    total 4
    drwxr-xr-x 2 student student 4096 Sep 29 17:44 GameOfThrones


.. important::
    După executarea comenzii, verificăm corectitudinea operației.
    Trebuie să verificăm și să nu presupunem că o comandă s-a executat.
    Lipsa unei verifică poate duce la erori și mult timp pierdut din partea noastră.


Redenumirea și mutarea fișierelor și directoarelor
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Fișierele și directoarele se redenumesc în mod similar, folosind comanda ``mv`` astfel: ``mv nume_actual nume_nou``.

Redenumim fișierele si directoarele folosind comanda ``mv``:

.. code-block:: bash

    student@uso:~/comenzi/mkdir$ ls
    GameOfThrones
    student@uso:~/comenzi/mkdir$ mv GameOfThrones ThroneOfGames
    student@uso:~/comenzi/mkdir$ ls
    ThroneOfGames

Am redenumit fișierul ``GameOfThrones`` în ``ThroneOfGames``.

Un alt rol al comenzii ``mv`` este de a muta fișierele și directoarele, în ierarhia de fișiere, dintr-un loc în altul.

Mutăm directorul ``GameOfThrones`` (cu tot conținutul acestuia) la calea ``/tmp/`` folosind comanda ``mv``:

.. code-block:: bash

    student@uso:~/comenzi/mkdir$ ls
    Avengers  GameOfThrones
    student@uso:~/comenzi/mkdir$ mv GameOfThrones/ /tmp/
    student@uso:~/comenzi/mkdir$ ls /tmp/
    GameOfThrones  ssh-ApUMKI3HSJ
    student@uso:~/comenzi/mkdir$ ls /tmp/
    GameOfThrones  ssh-ApUMKI3HSJ
    student@uso:~/comenzi/mkdir$ ls
    Avengers

Acum directorul ``GameOfThrones`` se află în calea ``/tmp/GameOfThrones``.
Am verificat folosind ``ls`` că nu se mai află în directorul curent și că există în directorul ``/tmp/``.

Mutăm înapoi directorul ``GameOfThrones`` (cu tot conținutul acestuia) folosind cale relativă, pentru a indica directorul, și cale absolută, pentru a indica locul unde vrem să ajungă directorul folosind ``mv``:

.. code-block:: bash

    student@uso:~/comenzi/mkdir$ mv ../../../../tmp/GameOfThrones/ /home/student/comenzi/mkdir/
    student@uso:~/comenzi/mkdir$ ls
    Avengers  GameOfThrones

Am verificat că directorul ``GameOfThrones`` se află la calea indicată (calea curentă).

.. note::

    Observăm că putem folosi atât căi relative cât și căi absolute ca argumente pentru comanda ``mv`` de mutare / redenumire de fișiere și directoare.

Exerciții - redenumire și mutare
""""""""""""""""""""""""""""""""

#. * Creați un director ``Vikings`` în directorul home al vostru;
   * Creați fișierele ``Ragnar``, ``Rollo``, ``Lagertha`` în directorul ``Vikings``;
   * Verificați că directorul și fișierele au fost mutate;
   * Mutati directorul (împreună cu întreaga ierarhie de fișiere) la locația ``/tmp/``;
   * Verificați că directorul și ierarhia de fișiere au fost mutate; 

#. * Creați un director ``NBA`` în directorul home al vostru;
   * Creați fișierele ``MichaelJordan``, ``LeBronJames``, ``DwayneWade`` și ``KobeBryant`` în directorul ``NBA``;
   * Verificați că directorul și fișierele au fost mutate;
   * Mutați directorul ``NBA`` (împreună cu întreaga ierarhie de fișiere) în directorul ``Vikings``;
   * Verificați că directorul și ierarhia de fișiere au fost mutate. 

#. * Redenumiți directorul ``GameOfThrones`` în ``ThronesInTheGame``;
   * Mutați fișierele din interiorul directorului ``ThronesInTheGame`` în ``/tmp``;
   * Verificați operațiile;
   * Mutați directorul înapoi la locatia inițială folosind atât căi relative cât și căi absolute.

Copierea fișierelor și directoarelor
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Copiem fișierul ``Thor`` în directorul ``/tmp/`` folosind ``cp``:

.. code-block:: bash


    student@uso:~/comenzi/mkdir$ cp Avengers/Thor /tmp/
    student@uso:~/comenzi/mkdir$ ls /tmp/
    Thor  ssh-ApUMKI3HSJ

Sintaxa este similară comenzii ``mv``.
Acum fișierul ``Thor`` este atât în ``/home/student/Avengers/Thor``, cât și în ``/tmp/Thor``.

.. code-block:: bash

    student@uso:~/comenzi/mkdir$ cp Avengers/ /tmp/
    cp: omitting directory 'Avengers/'

Observăm că nu se poate copia un director ce conține alte fișiere sau directoare.

Pentru a copia în altă parte un director care nu este gol, trebuie să folosim comanda ``cp -r``:

.. code-block:: bash

    student@uso:~/comenzi/mkdir$ cp -r Avengers/ /tmp/
    student@uso:~/comenzi/mkdir$ ls -l /tmp/
    total 8
    drwxr-xr-x 2 student student 4096 Sep 29 19:06 Avengers
    -rw-r--r-- 1 student student    0 Sep 29 19:04 Thor
    drwx------ 2 student student 4096 Sep 29 13:45 ssh-ApUMKI3HSJ
    student@uso:~/comenzi/mkdir$ ls -l /tmp/Avengers/
    total 0
    -rw-r--r-- 1 student student 0 Sep 29 19:06 Captain America
    -rw-r--r-- 1 student student 0 Sep 29 19:06 Iron Man
    -rw-r--r-- 1 student student 0 Sep 29 19:06 Thor

Am copiat directorul ``Avengers`` și conținutul acestuia din calea curentă în directorul ``/tmp``.
Observăm că s-a copiat întreaga ierarhie de fișiere/directoare de sub directorul ``Avengers``.
Acesta se află acum în ambele locuri.

Fișiere și directoare ascunse
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Un fișier sau director este ascuns atunci când nu apare în mod normal în ierarhia de fișiere.
De exemplu, atunci când executăm într-un director comanda ``ls``, acesta nu apare.

Există câteva motive pentru care vrem să ascundem un fișier sau director:

* Există fișiere pe care nu vrem să le vedem în mod normal (fișiere de configurare; ex: ``.profile``);
* Există comenzi care șterg toate fișierele dintr-un director fără a șterge directorul (``rm Avengers/*``).
  Acestea nu au efect asupra fișierelor ascunse;
* Vrem să facem anumite fișiere puțin mai greu de găsit.

Vedem fișiere și directoare ascunse folosind comanda ``ls -a``:

.. code-block:: bash

    student@uso:~/comenzi/mkdir$ ls -al
    total 8
    drwxr-xr-x 5 student student 4096 Sep 29 18:41 .
    drwxr-xr-x 4 student student 4096 Sep 29 18:35 ..
    drwxr-xr-x 2 student student 4096 Sep 29 18:20 Avengers
    drwxr-xr-x 2 student student 4096 Sep 29 17:44 GameOfThrones

Opțiunea ``-a`` vine de la *all*, adică vrem să vedem toate fișierele: și cele vizibile și cele ascunse.

Observăm două directoare noi ``.`` și ``..``.
Directorul ``.`` este o referință la directorul curent, iar ``..`` este o referință la directorul părinte.

Afișăm conținutul directorului părinte folosind ``ls -l``:

.. code-block:: bash

    student@uso:~/comenzi/mkdir$ ls -l ..
    total 136
    drwxr-xr-x 2 student student   4096 Sep 29 19:25 executie
    drwxr-xr-x 2 student student   4096 Oct  6 17:58 ls
    drwxr-xr-x 5 student student   4096 Sep 29 19:14 mkdir
    -rwxr-xr-x 1 student student 121032 Sep 29 19:25 my_ls
    drwxr-xr-x 2 student student   4096 Oct  6 12:48 touch

Directorul ``..`` este în cazul nostru echivalent cu ``~/comenzi``.


Creăm fișiere ascunse punând un punct *(.)* în fața numelui:

.. code-block:: bash

    student@uso:~/comenzi/mkdir/Avengers$ ls -l
    total 0
    -rw-r--r-- 1 student student 0 Sep 29 18:20 Captain America
    -rw-r--r-- 1 student student 0 Sep 29 18:20 Iron Man
    -rw-r--r-- 1 student student 0 Sep 29 18:20 Thor
    student@uso:~/comenzi/mkdir/Avengers$ touch .Hulk
    student@uso:~/comenzi/mkdir/Avengers$ ls -l
    total 0
    -rw-r--r-- 1 student student 0 Sep 29 18:20 Captain America
    -rw-r--r-- 1 student student 0 Sep 29 18:20 Iron Man
    -rw-r--r-- 1 student student 0 Sep 29 18:20 Thor
    student@uso:~/comenzi/mkdir/Avengers$ ls -al
    total 8
    drwxr-xr-x 2 student student 4096 Oct  6 16:44 .
    drwxr-xr-x 5 student student 4096 Sep 29 19:14 ..
    -rw-r--r-- 1 student student    0 Oct  6 16:44 .Hulk
    -rw-r--r-- 1 student student    0 Sep 29 18:20 Captain America
    -rw-r--r-- 1 student student    0 Sep 29 18:20 Iron Man
    -rw-r--r-- 1 student student    0 Sep 29 18:20 Thor

Am creat fișierul ascuns ``.Hulk``.
Observăm că acesta nu apare la execuția ``ls -l``, dar apare la execuția comenzii ``ls -al``.

Similar, creăm directoare ascunse punând un *(.)* în fața numelui:

.. code-block:: bash

    student@uso:~/comenzi/mkdir$ mkdir .LordOfTheRings
    student@uso:~/comenzi/mkdir$ ls
    Avengers  GameOfThrones
    student@uso:~/comenzi/mkdir$ ls -a
    .  ..  .LordOfTheRings  Avengers  GameOfThrones
    student@uso:~/comenzi/mkdir$ ls -al
    total 20
    drwxr-xr-x 5 student student 4096 Sep 29 18:41 .
    drwxr-xr-x 4 student student 4096 Sep 29 18:35 ..
    drwxr-xr-x 2 student student 4096 Sep 29 18:41 .LordOfTheRings
    drwxr-xr-x 2 student student 4096 Sep 29 18:20 Avengers
    drwxr-xr-x 2 student student 4096 Sep 29 17:44 GameOfThrones

Am creat directorul ascuns ``.LordOfTheRings``.

Exerciții - creare fișiere/directoare ascunse
"""""""""""""""""""""""""""""""""""""""""""""

#. * Creați un director cu numele ``.LordOfTheRings`` în directorul vostru home;
   * Intrați în directorul creat;
   * Creați 3 fișiere ascunse cu numele ``Aragorn``, ``Legolas``, ``Frodo Baggins``;
   * Verificați operațiile de creare (director și fișiere).

#. * Creați un director cu numele ``stiri`` în directorul vostru home;
   * Creați fișierele ``hotnews``, ``biziday``, ``digi24``;
   * Creați fișierul ascuns ``.cancan``;
   * Afișați **toate** fișierele din director;
   * Afișați fișierele din director care **nu** sunt ascunse.

#. * Creați un director ``tv`` în directorul vostru home;
   * Creați fișierele ``ProTV``, ``Digi24``, ``Eurosport``;
   * Creați fișierele ascunse ``Antena3``, ``Romania24``;
   * Afișați **toate** fișierele din director;
   * Afișați fișierele din director care **nu** sunt ascunse.
   * Copiați directorul ``stiri`` împreună cu fișierele de sub acesta în directorul ``tv``;
   * Mutați fișierele ``.Antena3`` și ``.Romania24`` în directorul ``/tmp``.


Afișarea tipului de fișier
^^^^^^^^^^^^^^^^^^^^^^^^^^

O ierarhie de fișiere este formată din directoare și fișiere.
Fișierele pot fi de mai multe tipuri: text, binare, imagini, arhive, etc.

Pentru a afla tipul fișierului folosim comanda ``file``:

.. code-block:: bash

    student@uso:~$ file Picture.abc
    Picture.abc: PNG image data, 742 x 320, 8-bit/color RGBA, non-interlaced
    student@uso:~$ file index.rst
    index.rst: ASCII text
    student@uso:~$ file archive.tar
    archive.tar: POSIX tar archive (GNU) 

Observăm că fișierul ``Picture.abc`` este un fișier de tipul *PNG* în ciuda extensiei, iar ``archive.tar`` este oa rhivă de tipul *tar*.

Vom prezenta mai multe detalii în capitolul *Îmbunătățirea lucrului în linia de comandă*.



Exerciții - ierarhii de fișiere și directoare
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#. * Afișați ierarhia de fișiere pornind de la directorul vostru home (``~``).
   * Creați următoarea ierarhie pornind de la directorul ``/home/student/``:

   .. code-block:: bash

       student@uso:~$ tree
       .
       ├── prime_video
       ├── Hulu
       │   └── Favorite
       ├── Netflix
       │   ├── Filme
       │   │   ├── filme_2020.txt
       │   │   ├── filme_2019.txt
       │   │   ├── filme_vechi
       │   └── Seriale
       │       ├── seriale_2020
       │       ├── seriale_2019.txt
       │       └── seriale_vechi
       ├── HBO_GO
       │   ├── Modern_Family.txt
       │   └── Harry_Potter
       └── YouTubeTV

   * Copiați întreaga ierarhie în calea ``/tmp``. Folosiți comanda ``cp``. (Hint: recursivitate).
   * Confirmați copierea prin afișarea directorului părinte.
   * Ștergeți fișierul ``Favorite`` din directorul ``Hulu``. Confirmați ștergerea prin afișarea directorului părinte.
   * Ștergeți directorul ``prime video``.
   * Confirmați ștergerea prin afișarea directorului părinte.
   * Ștergeți directorul ``HBO GO``.
   * Găsiți parametrii corespunzători ștergerii unui director care nu este gol.
   * Confirmați ștergerea prin afișarea directorului părinte.
   * Ștergeri ierarhia de directoare începând cu directorul ``Netflix``.
   * Confirmați ștergerea prin afișarea directorului părinte.

#. * Creați ierarhia de directoare de mai jos.
   * Căutați parametrul necesar pentru ``mkdir`` pentru a crea toată ierarhia *dintr-o singură executare a comenzii*:

   .. code-block:: bash

       student@uso:~$ tree
       .
       └─── Cale
           └─── Lungă
                └─── De
                     └─── Directoare


   * Mutați ierarhia copiată anterior în ``/tmp`` în directorul ``Directoare``.

Legături (Links)
----------------

O legătură este o scurtătură către un fișier sau un director.
Acestea sunt necesare atunci când nu vrem să parcurgem toată ierarhia de fișiere.
De exemplu, punem executabilul jocului *Warcraft3* pe Desktop pentru a-l accesa rapid.
Mai multe legături pot referi același director/fișier.

Caracteristici:

* Similar *Shortcut* din Windows;
* Orice modificare în fisierul țintă, se vede și în fișierul legătură;
* Este o legătură către numele fișierului și nu către conținut;
* Dacă fișierul este mutat sau redenumit, legătura se pierde;
* Putem crea legături către directoare.

Creăm o legătură simbolică către directorul ``/home/student/comenzi/mkdir/`` folosind comanda ``ln -s``:

.. code-block:: bash

    student@uso:~/comenzi/ls$ ln -s ~/comenzi/mkdir/ .
    student@uso:~/comenzi/ls$ ls -l
    total 0
    lrwxrwxrwx 1 student student 28 Oct  6 17:58 mkdir -> /home/student/comenzi/mkdir/


Observăm că fișierul creat este *link* (are primul caracter ``l``).
Mai mult, observăm că acest link este o scurtătură către calea ``/home/student/comenzi/mkdir/``.

.. code-block:: bash

    student@uso:~/comenzi/ls$ ls -l mkdir/
    total 8
    drwxr-xr-x 2 student student 4096 Oct  6 16:44 Avengers
    drwxr-xr-x 2 student student 4096 Oct  6 16:50 GameOfThrones
    student@uso:~/comenzi/ls$ ls -l mkdir/Avengers/
    total 0
    -rw-r--r-- 1 student student 0 Sep 29 18:20 Captain America
    -rw-r--r-- 1 student student 0 Sep 29 18:20 Iron Man
    -rw-r--r-- 1 student student 0 Sep 29 18:20 Thor

Observăm că putem accesa întreaga ierarhie de fișiere și directoare.

Vedem în continuare ce se întâmplă dacă ștergem un fișier.

.. code-block:: bash

    student@uso:/tmp$ ls -l /home/student/comenzi/mkdir/
    total 8
    drwxr-xr-x 2 student student 4096 Sep 29 18:20 Avengers
    drwxr-xr-x 2 student student 4096 Sep 29 17:44 GameOfThrones
    -rw-r--r-- 1 student student    0 Sep 29 19:04 Thor
    student@uso:/tmp$ ls
    mkdir  ssh-ApUMKI3HSJ
    student@uso:/tmp$ rm mkdir/Thor
    student@uso:/tmp$ ls mkdir/
    Avengers  GameOfThrones
    student@uso:/tmp$ ls -l /home/student/comenzi/mkdir/
    total 8
    drwxr-xr-x 2 student student 4096 Sep 29 18:20 Avengers
    drwxr-xr-x 2 student student 4096 Sep 29 17:44 GameOfThrones

Observăm că dacă am șters un fișier accesându-l prin legătura, s-a șters și la destinație.

Exerciții - legături (linkuri)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Creați o legătură simbolică în directorul vostru ``home`` către directorul ``Netflix``.
* Verificați crearea legăturii prin afișarea conținutului directorului părinte.
* Afișați conținutul legăturii.
* Ștergeți directorul ``Netflix``.
* Afișați conținutul legăturii.

Execuția programelor
--------------------

Execuția unui fișier/program se face folosind calea către fișier în locul unei comenzi pe care am rula-o în mod normal.
Putem rula un executabil folosind o care relativă cum ar fi ``./executabil`` sau ``./director/executabil``, ori folosind o cale absoluta cum ar fi ``/usr/bin/firefox``.

Avem un executabil ``my_ls`` care face același lucru ca și comanda ``ls``:

.. code-block:: bash

    student@uso:~/comenzi$ ./my_ls
    executie  mkdir  my_ls	touch

Putem folosi atât calea relativă cât și absolută:

.. code-block:: bash

    student@uso:~/comenzi$ ls -l
    total 132
    drwxr-xr-x 2 student student   4096 Sep 29 19:25 executie
    drwxr-xr-x 5 student student   4096 Sep 29 19:14 mkdir
    -rwxr-xr-x 1 student student 121032 Sep 29 19:25 my_ls
    drwxr-xr-x 2 student student   4096 Sep 29 17:25 touch
    student@uso:~/comenzi$ ./my_ls
    executie  mkdir  my_ls	touch
    student@uso:~/comenzi$ /home/student/comenzi/my_ls
    executie  mkdir  my_ls	touch

Observăm cum se rulează un executabil atât cu cale relativă (în primul caz) cât și cu cale absolută (în al doilea caz).
