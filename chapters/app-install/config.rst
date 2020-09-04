.. _app_install_config:

Configurarea aplicațiilor
=========================

Modul în care o aplicație rulează este configurabil.
Adică informațiile afișate, interfața expusă utilizatorului, opțiunile permise utilizatorului pot varia de la o rulare la altă rulare.
Mai mult, o aplicație care rulează (un proces) poate să își modifice comportamentul în timpul rulării.

Configurarea unei aplicații se realizează în diferite moduri.

Configurarea prin argumente
---------------------------

O aplicație se comportă diferit prin transmiterea de opțiuni și argumente în linia de comandă.

De exemplu, utilitarul ``ls``, la fel ca majoritatea utilitarelor în linia de comandă, are comportament diferit în funcție de opțiuni, ca mai jos:

.. code-block:: bash

    student@uso:~$ ls
    Desktop  Documents  Downloads  examples.desktop  Music  Pictures  Public  snap  Templates  uso.git  Videos  vm-actions-log.txt

    student@uso:~$ ls -F
    Desktop/  Documents/  Downloads/  examples.desktop  Music/  Pictures/  Public/  snap/  Templates/  uso.git/  Videos/  vm-actions-log.txt

    student@uso:~$ ls -l
    total 60
    drwxr-xr-x  2 student student 4096 Aug  6  2018 Desktop
    drwxr-xr-x  3 student student 4096 Aug 20  2018 Documents
    drwxr-xr-x  2 student student 4096 Aug  6  2018 Downloads
    -rw-r--r--  1 student student 8980 Aug  6  2018 examples.desktop
    drwxr-xr-x  2 student student 4096 Aug  6  2018 Music
    drwxr-xr-x  3 student student 4096 Aug 25 21:01 Pictures
    drwxr-xr-x  2 student student 4096 Aug  6  2018 Public
    drwxr-xr-x  3 student student 4096 Aug  8 09:02 snap
    drwxr-xr-x  2 student student 4096 Aug  6  2018 Templates
    drwxr-xr-x 14 student student 4096 Aug 20  2018 uso.git
    drwxr-xr-x  2 student student 4096 Aug  6  2018 Videos
    -rw-r--r--  1 student student 4827 Aug 21  2018 vm-actions-log.txt

La o rulare simplă a comenzii ``ls``, se afișează conținutul directorului curent.
Opțiunea ``-F`` adaugă un sufix specific intrărilor pentru a indica tipul lor; de exemplu ``/`` (*slash*) în cazul directoarelor.
Opțiunea ``-l`` afișează detalii despre intrări.

La fel, dacă folosim comanda ``emacs`` pornim aplicația Emacs (în mediul grafic).
Pe când, dacă folosim comanda ``emacs -nw`` aplicația va porni în consolă, cu interfața în linia de comandă.

Exercițiu
^^^^^^^^^

O aplicație poate fi pornită cu argumente în interfața grafică folosind combinația de taste ``Alt+F2``.

Folosiți ``Alt+F2`` și porniți aplicația ``gedit`` ca să deschidă fișierul ``.bashrc``.

Folosiți ``Alt+F2`` și porniți aplicația ``gedit`` ca să deschidă fișierul ``.bashrc`` la linia ``90``.

Configurarea prin fișiere de configurare
----------------------------------------

Fișierele de configurare ale unei aplicații modifică funcționarea acesteia.

De exemplu, shellul Bash este configurat în fișiere de configurare precum ``/etc/profile``, ``/etc/bash.bashrc``, ``~/.profile``, ``~/.bashrc``.
Editorul Vim este configurat în ``/etc/vim/vimrc`` și ``~/.vimrc``.
Browserul web Firefox are fișiere de configurare în directorul ``~/.mozilla/``.
În Linux, multe aplicații au fișiere de configurare în subdirectoare din directorul ``~/.config/``.

Fișierele de configurare sunt adesea text și pot fi modificate cu ajutorul unui editor.
Altfel, sunt modificate de obicei din cadrul aplicației sau cu o aplicație auxiliară de configurare.

.. note::

    În Windows, echivalentul fișierelor de configurare este Windows Registry.

Inspectarea fișierelor de configurare
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Urmăriți conținutul fișierelor de configurare ``.gitconfig``, ``.vimrc``, ``.tmux.conf``.
Aceste fișiere sunt folosite, respectiv pentru a configura Git, Vim sau tmux.

Fișierele de configurare pot fi editate cu un editor.
Alternativ, pot fi editate cu ajutorul unui utilitar dedicat, precum e cazul Git, ca mai jos:

.. code:: bash

    student@uso:~$ cat .gitconfig
    [color]
    	ui = auto
    [user]
    	name = Student USO VM User
    	email = student@stud.acs.upb.ro
    student@uso:~$ git config --global user.email student@example.com
    student@uso:~$ cat .gitconfig
    [color]
    	ui = auto
    [user]
    	name = Student USO VM User
    	email = student@example.com

Mai sus am folosit comanda ``git config`` cu opțiunea ``-global`` pentru a modifica fișierul global de configurare ``~/.gitconfig``.

Modificarea unui fișiere de configurare
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Dorim să configurăm o aplicație din fișierul de configurare.
O aplicație simplă este editorul Nano, care funcționează în linia de comandă, și îl vom folosi pe acesta.
Configurarea editorului Nano se face în fișierul ``~/.nanorc``.

Editați (și creați dacă este cazul) fișierul ``~/.nanorc``.
Puteți folosi chiar Nano ca editor.
Configurați Nano să afișeze numărul liniilor prin adăugarea următoarei linii în fișierul ``~/.nanorc``:

.. code::

    set linenumbers

Salvați fișierul.
Porniți editorul Nano (folosind comanda ``nano``) și verificați că sunt afișate numerele liniilor.

Configurarea clientului SSH
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Configurați utilitarul ``ssh`` (client SSH) astfel încât folosirea comenzii ``ssh fav`` să însemne conectarea la un cont la distanță SSH la care aveți acces.
De exemplu poate fi vorba de contul de pe sistemul ``fep.grid.pub.ro``.

Configurarea clientului SSH se realizează în fișierul ``~/.ssh/config``.
Vedeți și `exemplul de aici <https://linuxize.com/post/using-the-ssh-config-file/#shared-ssh-config-file-example>`_.

Configurarea din aplicație
--------------------------

Modul în care rulează o aplicație poate fi configurat direct din aplicație.

De exemplu, în cadrul interfeței browserul web Firefox putem modifica pagina de start sau putem activa anumite pluginuri sau putem personaliza dispunerea meniurilor sau fonturile folosite.
Aceste opțiuni sunt frecvente în majoritatea aplicațiilor grafice.

Configurări de aplicații din aplicație
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Porniți editorul Gedit și configurați-l, din aplicație (mediu grafic), să afișeze numărul liniilor editate.

Configurați editorul Gedit să folosească fundal închis (*dark background*).

Porniți browserul de sistem de fișiere Nautilus.
Configurați-l, din aplicație (mediu grafic), să afișeze conținutul în formă de listă, nu în formă de icon / *tile*.

Configurați browserul Nautilus să deschidă un fișier / director la un singur click, nu la două clickuri.

Configurarea cu variabile de mediu
----------------------------------

O variabilă de mediu (*environment variable*) este o valoare care poate fi configurată la pornirea unui proces sau în timpul rulării sale pentru a afecta comportamentul procesului.

De exemplu utilitarele ``wget`` și ``curl``, clienți web, folosesc variabilele de mediu ``http_proxy`` și ``https_proxy`` pentru a folosi un proxy web.
Shellul folosește o serie de variabile de mediu pentru a configura funcționarea sa și modul în care pornește alte aplicații.
De exemplu, variabila de mediu ``PATH`` reține căile unde shellul caută fișierul executabil corespunzător unei comenzi.

Folosirea de varabile de mediu
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Putem modifica ordinea afișată de utilitare de afișare (precum ``ls``) folosind variabila de mediu ``LC_ALL``, ca mai jos:

.. code:: bash

    student@uso:~$ LC_ALL=en_US.UTF-8 ls
    Desktop  Documents  Downloads  examples.desktop  Music  Pictures  Public  snap  Templates  test.c  uso.git  Videos  vm-actions-log.txt

    student@uso:~$ LC_ALL=POSIX ls
    Desktop  Documents  Downloads  Music  Pictures  Public  Templates  Videos  examples.desktop  snap  test.c  uso.git  vm-actions-log.txt

Atunci când variabila de mediul ``LC_ALL`` folosește valoarea ``en_US.UTF-8`` se afișează intrările în ordine alfabetică, indiferent dacă numele acestora începe cu literă mare sau literă mică.
Atunci când folosește valoarea ``POSIX`` se afișează întâi intrările al căror nume începe cu literă mare.
