.. _improve_cli_inspect_fs:

Inspectarea sistemului de fișiere
=================================


Cea mai importantă comandă
--------------------------

Așa cum spuneam mai devreme, marele avantaj al utilizării terminalului este că ne ajută să rezolvăm sarcini foarte rapid.
Rezolvăm sarcini folosind utilitarele pe care le avem disponibile în linia de comandă, fie că acestea fac parte din sistemul nostru sau le-am instalat.

Cel mai important utilitar pe care îl avem la dispoziție este ``man``.
Utilitarul ``man`` ne deschide pagina de manual în care este documentat un alt utilitar pe care dorim să-l folosim.

.. code-block:: bash

    student@uso:~$ man
    What manual page do you want?

Putem consulta însăși pagina de manual a utilitarului ``man``

.. code-block:: bash

    student@uso:~$ man man

Vom fi întâmpinați de următorul program interactiv:

.. code-block:: bash

    MAN(1)                        Manual pager utils                        MAN(1)

    NAME
           man - an interface to the on-line reference manuals

    SYNOPSIS
           man  [-C  file]  [-d]  [-D]  [--warnings[=warnings]]  [-R encoding] [-L
           locale] [-m system[,...]] [-M path] [-S list]  [-e  extension]  [-i|-I]
           [--regex|--wildcard]   [--names-only]  [-a]  [-u]  [--no-subpages]  [-P
           pager] [-r prompt] [-7] [-E encoding] [--no-hyphenation] [--no-justifi‐
           cation]  [-p  string]  [-t]  [-T[device]]  [-H[browser]] [-X[dpi]] [-Z]
           [[section] page[.section] ...] ...
           man -k [apropos options] regexp ...
           man -K [-w|-W] [-S list] [-i|-I] [--regex] [section] term ...
           man -f [whatis options] page ...
           man -l [-C file] [-d] [-D] [--warnings[=warnings]]  [-R  encoding]  [-L
           locale]  [-P  pager]  [-r  prompt]  [-7] [-E encoding] [-p string] [-t]
           [-T[device]] [-H[browser]] [-X[dpi]] [-Z] file ...
           man -w|-W [-C file] [-d] [-D] page ...
           man -c [-C file] [-d] [-D] page ...
           man [-?V]

     Manual page man(1) line 1 (press h for help or q to quit)

Observăm că ultima linie din terminal, **Manual page man(1) line 1 (press h for help or q to quit)**, ne oferă mai multe informații:

* Ne aflăm pe prima linie din prima pagină a manualului
* Putem apăsa tasta ``h`` pentru a acesa meniul de ajutor
* Putem apăsa tasta ``q`` pentru a ieși din manual

Navigarea prin paginile manualului
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Navigăm cu câte o linie de terminal în joș și în sus folosind folosind tastele ``Ctrl+n`` și ``Ctrl+p``.
Putem folosi tastele ``Ctrl+f`` și ``Ctrl+b`` pentru a naviga, cu câte un ecran de terminal, în jos și în sus în pagină.
Mai simplu, putem folosi tasta ``Enter`` pentru a naviga cu câte o linie în jos și tasta ``Space`` pentru a naviga cu câte un ecran în jos.
Navigăm la începutul paginii folosind tasta ``g``.
Navigăm la sfârșit paginii folosind tasta ``G``.

.. note::

    Putem folosi tastele ``j`` și ``k`` ca alternative pentru ``Arrow Down`` și ``Arrow Up``.
    Astfel suntem mai rapizi pentru că nu ne mai mutăm mâna de pe tastele caractere.

Folosim ``man`` ca să vedem dacă un utilitar oferă o anumită funcționaltiate.
Citim întreaga pagină de manual ca să vedem toate funcționalitățile sau căutăm o funcționalitate folosind cuvinte cheie.
Pașii pentru căutarea unui cuvânt cheie sunt următorii:

#. Pentru a porni funcția de căutare apăsăm tasta ``/`` în sesiunea interactivă din ``man``.
#. În continuare vom introduce textul pe care dorim să-l căutăm: poate să fie un cuvântul cheie pe care îl știm deja sau orice text care sperăm că ne duce la rezultatul dorit.
#. Acum apăsăm tasta ``Enter``.
   Vom fi duși la primul rezultat care se potrivește căutării, dacă acesta există.
#. Dacă vrem să navigăm la următorul rezultat apăsăm tasta ``n``.
   Dacă vrem să navigăm la un rezultat anterior apăsăm tasta ``N``.

Căutarea [#search-case]_ are loc de la poziția curentă în pagină către sfârșitul paginii.
Dacă am navigat deja în interiorul paginii, trebuie să avem în vedere că rezultatul de interes al căutării noastre se poate alfa undeva între începutul paginii și poziția noastră curentă [#rev-search]_.

Interpretarea paginii de manual
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

La o primă vedere, textul paginii de manual poate fi intimidant; unele utilitare au mai multe opțiuni și argumente, unele opționale, altele nu.
O să trecem prin sintaxă și o să vedem că lucrurile sunt mult mai simple decât par.
Să analizăm pagina de manual a utilitarului ``ls``; ``man ls``:

.. code-block:: bash

    LS(1)                            User Commands                           LS(1)

    NAME
           ls - list directory contents

    SYNOPSIS
           ls [OPTION]... [FILE]...

    DESCRIPTION
           List  information  about  the FILEs (the current directory by default).
           Sort entries alphabetically if none of -cftuvSUX nor --sort  is  speci‐
           fied.

           Mandatory  arguments  to  long  options are mandatory for short options
           too.

           -a, --all
                  do not ignore entries starting with .

           -A, --almost-all
                  do not list implied . and ..

           --author
     Manual page ls(1) line 1 (press h for help or q to quit)

#. Prima secțiune care ne interesează este "DESCRIPTION".
   Citim descrierea și ne dăm seama dacă utilitarul ne va ajuta în rezolvarea sarcinii pe care o avem.
   În cazul utilitarului ``ls``, descrierea ne informează că acesta afișează informații despre fișierele din calea indicată, sau din directorul curent atunci când nu specificăm o cale.

#. Cea de-a doua secțiune care ne interesează este "SYNOPSIS".
   Aceasta ne spune cum putem să rulăm utilitarul, ce opțiuni și argumente sunt opționale (pot lipsi) și ce opțiuni și argumente sunt obligatorii.

   .. code-block:: bash

       SYNOPSIS
              ls [OPTION]... [FILE]...

   Sintaxa **[ ]** ne spune că acea categorie este opțională.
   Astfel, pentru ``ls``, deducem că atât opțiunile (``[OPTION]...``) cât și argumentele (``[FILE]...``, calea către fișiere sau directoare) sunt opționale.
   Cele trei puncte ``...`` înseamnă mai multe din categoria precedentă: deci ``[OPTION]...`` înseamnă că nu suntem limitați la o singură opțiune, dar opțiunile pot să și lipsească în totalitate datorită **[ ]**.


   O comandă poate avea atât opțiuni, cât și argumente.
   Opțiunile îi spun unei comenzi cum să își modifice comportamentul, și de obicei sunt precedate de ``-`` (ex. ``-l``, ``--verbose``, etc.).
   Argumentele îi spun unei comenzi pe ce să acționeze.

   În exemplul de mai jos:

   .. code-block:: bash

       student@uso:~$ ls -l Desktop/

   Avem utilitarul ``ls`` care primește opțiunea ``-l`` și argumentul ``Desktop/``.

#. Ultima observație pe care o facem este că opțiunile unei comenzi pot avea o formă prescurtată, ``-a``, sau o formă lungă, ``--all``.
   Nu este obligatoriu ca o opțiune să expună ambele forme, deși majoritatea o fac.
   Opțiunile în formă prescurtată pot fi concatenate și precedate de un singur ``-``, ca în exemplul de mai jos:

   .. code-block:: bash

       student@uso:~$ ls -la Desktop/

Exerciții
"""""""""

Deschideți pagina de manual a utilitarului ``ls``.

#. Căutați opțiunea ``-a``.
   Rulați comanda ``ls -a``.

#. Căutați opțiunea ``-d``.
   Rulați comanda ``ls -d``.

#. Căutați opțiunea ``-F``.
   Rulați comanda ``ls -F``.

#. Căutați cuvântul cheie ``list``.
   Treceți la următoarea apariție a cuvântului cheie până ajungeți la opțiunea ``-l``.

#. Mergeți la finalul paginii folosind tasta ``G``.
   Căutați cuvântul cheie ``color`` până ajungeți la opțiunea ``--color`` (Hint: ``?``).

Extra: Utilizarea secțiunilor din manual
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

În descrierea manualului (``man man``) este specificat faptul că manualul este împărțit în diferite secțiuni:

.. code-block:: bash

    The table below shows the section numbers of the manual followed by the types of pages they contain.

    1   Executable programs or shell commands
    2   System calls (functions provided by the kernel)
    3   Library calls (functions within program libraries)
    4   Special files (usually found in /dev)
    5   File formats and conventions eg /etc/passwd
    6   Games
    7   Miscellaneous (including macro packages and conventions), e.g. man(7), groff(7)
    8   System administration commands (usually only for root)
    9   Kernel routines [Non standard]

Ce este important de reținut aici este că, folosind ``man``, putem afla informații despre funcții de bibliotecă și de sistem, și multe altele, nu doar despre utilitare și comenzi shell.
Totul este mai clar cu un exemplu.
Dacă rulăm comanda ``man printf`` se va deschide pagina următoare din manual:

.. code-block:: bash

    PRINTF(1)                        User Commands                       PRINTF(1)

    NAME
           printf - format and print data

    SYNOPSIS
           printf FORMAT [ARGUMENT]...
           printf OPTION

    DESCRIPTION
           Print ARGUMENT(s) according to FORMAT, or execute according to OPTION:

           --help display this help and exit

           --version
                  output version information and exit

           FORMAT controls the output as in C printf.  Interpreted sequences are:

           \"     double quote

           \\     backslash

     Manual page printf(1) line 1 (press h for help or q to quit)

Această pagină este pentru utilitarul ``printf``.
Observați prima linie:

.. code-block:: bash

    PRINTF(1)                        User Commands                       PRINTF(1)

Textul **PRINTF(1)** ne spune că ne uităm la pagina de manual a utilitarului ``printf`` din secțiunea **(1)** a manualului.
Exact cum ne spune descrierea din manual:

.. code-block:: bash

    1   Executable programs or shell commands

Dacă vrem să accesăm pagina de manual a funcției ``printf`` a bibliotecii standard C, folosim comanda ``man 3 printf`` și vom fi găsi pagina următoare din manual:

.. code-block:: bash

    PRINTF(3)                  Linux Programmer's Manual                 PRINTF(3)

    NAME
           printf,   fprintf,   dprintf,  sprintf,  snprintf,  vprintf,  vfprintf,
           vdprintf, vsprintf, vsnprintf - formatted output conversion

    SYNOPSIS
           #include <stdio.h>

           int printf(const char *format, ...);
           int fprintf(FILE *stream, const char *format, ...);
           int dprintf(int fd, const char *format, ...);
           int sprintf(char *str, const char *format, ...);
           int snprintf(char *str, size_t size, const char *format, ...);

           #include <stdarg.h>

           int vprintf(const char *format, va_list ap);
           int vfprintf(FILE *stream, const char *format, va_list ap);
           int vdprintf(int fd, const char *format, va_list ap);
           int vsprintf(char *str, const char *format, va_list ap);
           int vsnprintf(char *str, size_t size, const char *format, va_list ap);

     Manual page printf(3) line 1 (press h for help or q to quit)

Observăm că s-a căutat în secțiunea **(3)** din manual:

.. code-block:: bash

    3   Library calls (functions within program libraries)

Bonus: Utilizarea pachetului ``tldr``
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Utilitarul ``tldr`` (too long, didn't read) oferă o versiune simplificată a paginilor de manual.
Acesta ne va arăta un rezumat al utilizării unei comenzi cu opțiunile cele mai des folosite în comunitate.

.. code-block:: bash

    student@uso:~$ tldr ls
    ls
    List directory contents.

     - List files one per line:
       ls -1

     - List all files, including hidden files:
       ls -a

     - Long format list (permissions, ownership, size and modification date) of all files:
       ls -la

     - Long format list with size displayed using human readable units (KB, MB, GB):
       ls -lh

     - Long format list sorted by size (descending):
       ls -lS

     - Long format list of all files, sorted by modification date (oldest first):
       ls -ltr

.. note::

    Acesta trebuie tratat ca un cheatsheet accesibil din linie de comandă.
    ``tldr`` nu elimină utilizarea paginilor ``man``, dar ne ajută să găsim rapid opțiunile uzuale.
    Acestea fiind spuse, vă recomandăm ca întotdeaună să citiți și să înțelegeți din paginile ``man`` ce efect au opțiunile unei comenzi înainte de a le folosi.
    Feriți-vă să rulați comenzi orbește, pentru că așa ați găsit pe StackOverflow, tldr, etc.
    Întotdeauna asigurați-vă că ați înțeles cum și de ce rulați comanda și abia apoi treceți la fapte.

Exerciții: Utilizarea pachetului ``tldr``
"""""""""""""""""""""""""""""""""""""""""

Instalați pachetul ``tldr`` pe mașina voastră.

#. Accesați pagina ``tldr`` a utilitarului ``ls``.

#. Accesați pagina ``tldr`` a utilitarului ``zip``.

#. Accesați pagina ``tldr`` a utilitarului ``tar``.

#. Accesați pagina ``tldr`` a utilitarului ``git``.

#. Accesați pagina ``tldr`` a utilitarului ``man``.


Explorarea sistemului de fișiere: comanda ``ls``
------------------------------------------------

În capitolul **Lucrul cu fișiere** am văzut cum folosim comanda ``ls`` pentru a afișa conținutul unui director și pentru a explora sistemul de fișiere.
În continuare vom vedea cum folosim ``ls`` pentru a afișa mai multe informații despre conținutul unui director sau despre fișiere.

Afișarea fișierelor ascunse
^^^^^^^^^^^^^^^^^^^^^^^^^^^

În mediul linux, un fișier este ascuns dacă numele său începe cu caracterul ``.`` (punct).
În mod implicit, utilitarul ``ls`` omite fișierele ascunse.
Pentru a afișa fișierele ascunse folosim opțiunea ``-a`` (all).

.. code-block:: bash

    student@uso:~$ ls -a
    .              .emacs.d         .ssh                       Pictures
    ..             .gconf           .sudo_as_admin_successful  Public
    .ICEauthority  .gitconfig       .tmux                      Templates
    .bash_aliases  .gnome2          .tmux.conf                 Videos
    .bash_history  .gnome2_private  .vim                       examples.desktop
    .bash_logout   .gnupg           .viminfo                   uso.git
    .bashrc        .java            .vimrc                     vm-actions-log.txt
    .cache         .lesshst         Desktop                    workspace
    .config        .local           Documents
    .dbus          .mozilla         Downloads
    .emacs         .profile         Music

Observăm că avem o mulțime de fișiere ascunse prezente în directorul nostru home.
Multe dintre acestea sunt fișiere de configurare (``.bashrc``, ``.vimrc``, etc.) folosite de diferite programe instalate pe sistemul nostru.
Vom vorbi mai multe despre acestea în viitorul apropriat.

Afișarea informațiilor extinse despre fișiere
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

De cele mai multe ori suntem interesați să aflăm mai multe informații despre fișiere: cum ar fi tipul fișierului, permisiuni, ownership, dimensiunea și data ultimei modificări.
Toate acestea sunt afișate prin utilizarea opțiunii ``-l``:

.. code-block:: bash

    student@uso:~$ ls -l
    total 60
    drwxr-xr-x  2 student student 4096 aug  6  2018 Desktop
    drwxr-xr-x  3 student student 4096 aug 20  2018 Documents
    drwxr-xr-x  2 student student 4096 aug 11 19:35 Downloads
    drwxr-xr-x  2 student student 4096 aug  6  2018 Music
    drwxr-xr-x  3 student student 4096 aug 31 23:26 Pictures
    drwxr-xr-x  2 student student 4096 aug  6  2018 Public
    drwxr-xr-x  2 student student 4096 aug  6  2018 Templates
    drwxr-xr-x  2 student student 4096 aug  6  2018 Videos
    -rw-r--r--  1 student student 8980 aug  6  2018 examples.desktop
    drwxr-xr-x 14 student student 4096 aug 20  2018 uso.git
    -rw-r--r--  1 student student 4827 aug 21  2018 vm-actions-log.txt
    drwxr-xr-x  4 student student 4096 aug 13 18:38 workspace

Vom analiza informațiile afișate pentru directorul **Desktop**.

.. code-block:: bash

    drwxr-xr-x  2 student student 4096 aug  6  2018 Desktop

#. Vom începe cu prima coloană din exemplul de mai sus: ``drwxr-xr-x``.
   Aceasta este formată din zece caractere care formează patru grupuri:

   #. Primul grup este format dintr-un singur caracter, și denotă tipul fișierului.
      În cazul de față, caracterul ``d`` ne informează că ne uităm la un fișier de tip director.
      În cazul fișierelor obișnuite (text, imagini, etc.) primul caracter este ``-``, așa cum putem observa în cazul fișierului ``examples.desktop``.

   #. Cel de-al doilea grup este format din următoarele trei caractere și denotă permisiunile pe care le are utilizatorul care deține fișierul asupra fișierului.
      Caracterele sunt în ordine ``r`` (read) permisiuni de citire, ``w`` (write) permisiuni de scriere și ``x`` (execute) permisiuni de rulare.
      Dacă utilizatorul nu are o anumită permisiune, caracterul corespunzător este înlocuit de caracterul ``-``.
      Spunem că aceste permisiuni se aplică pentru **User**.

   #. Cel de-al treilea grup este format din următoarele trei caractere și denotă permisiunile pe care le au membrii grupului care dețin fișierul asupra fișierului.
      Permisiunile rămân din setul ``rwx``.
      Spunem că aceste permisiuni se aplică pentru **Group**.

   #. Cel de-al patrulea grup este format din ultimele trei caractere și denotă permisiunile pe care le are orice utilizator care nu deține fișierul și nici nu face parte din grupul care deține fișierul.
      Permisiunile rămân din setul ``rwx``.
      Spunem că aceste permisiuni se aplică pentru **Others**.

   Acum, pe baza informațiilor din prima coloană, putem spune următoarele despre fișierul Desktop:

   #. Acesta este un fișier de tip director (``d``)
   #. Utilizatorul care îl deține are drepturi de citire (``r``), scriere (``w``) și execuție (``x``)
   #. Grupul care îl deține are drepturi de citire (``r``), **NU** are drepturi de scriere (``-``) și are drepturi de execuție (``x``)
   #. Iar orice alt utilizator are drepturi de citire (``r``), **NU** are drepturi de scriere (``-``) și are drepturi de execuție (``x``).

   .. note::

       Pentru a putea deschide un director este necesar să avem drepturi de execuție (``x``) asupra acestuia.
       Trebuie să avem drepturi de execuție indiferent că vrem să navigăm în interiorul său, să afișăm conținutul directorului sau să creăm noi fișiere și directoare în cadrul acestuia.

#. Cea de-a treia coloană ne spune care este utilizatorul care deține fișierul.
   Astfel observăm că directorul **Desktop** este deținut de către utilizatorul ``student``.
   Asta înseamnă că permisiunile ``rwx`` corespund utilizatorului ``student``.

#. Cea de-a patra coloană ne spune care este grupul care deține fișierul.
   Astfel observăm că directorul **Desktop** este deținut de către grupul ``student``.
   Asta înseamnă că permisiunile ``r-x`` se aplică oricărui utilizator care este membru al grupului ``student``.

#. Cea de-a cincea coloană ne arată dimensiunea fișierului, exprimată în octeți.
   Putem să-i cerem utilitarului ``ls`` să ne afișeze dimensiunea folosind multiplii (K(ilo), M(ega), G(iga), etc) utilizând opțiunea ``-h`` (human readable)

   .. code-block:: bash

       student@uso:~$ ls -lh
       total 60K
       drwxr-xr-x  2 student student 4,0K aug  6  2018 Desktop
       [...]

#. Ultimele coloane ne arată data ultimei modificări, în ordinea lună, zi, an.

Afișarea informațiilor extinse despre un fișier de tip director
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

Am observat că, în mod implicit, utilitarul ``ls`` ne afișază informații despre conținutul unui director atunci când primește calea către un director ca argument:

.. code-block:: bash

    student@uso:~$ ls -l Desktop/
    total 0
    -rw-r--r-- 1 student student 0 sep  2 19:39 todos.txt

Pentru a-i specifica lui ``ls`` că suntem interesați de informații despre fișierul de tip director, și nu despre conținutul său, folosim opțiunea ``-d``.

.. code-block:: bash

    student@uso:~$ ls -ld Desktop/
    drwxr-xr-x 2 student student 4096 sep  2 19:39 Desktop/

#. Afișați conținutul directoarelor ``/home``, ``Downloads`` și ``/tmp``.

#. Aflați care sunt permisiunile pe care le are orice utilizator asupra directoarelor ``/home``, ``/home/student`` și ``/tmp``.

Selectarea multiplor fișiere folosind globbing
----------------------------------------------

Întotdeauna când deschidem un terminal o facem pentru că vrem să realizăm o sarcină: vrem să redenumim rapid ultimele poze făcute cu telefonul de la genericul **DCIM1001** la ceva util **Excursie Sinaia, Ian 2020, 1001**, vrem să ne testăm proiectul și să urcăm modificările pe GitHub, etc.

Până acum am aplicat diferite comenzi fie pe fișiere individuale, fie pe întreg directorul.
Foarte des vom avea nevoie de un mijloc prin care să putem selecta un număr variabil de fișiere care au un nume care corespunde unui tipar (*pattern*) comun.

Să revenim la scenariul prezentat anterior: vrem să selectăm pozele din excursia din Sinaia.
În directorul în care avem pozele din excursie avem și alte poze de la alte evenimente.
Știm că pozele din excursie încep toate cu numele **DCIM** și apoi sunt urmate de un număr.
Ceea ce vrem să facem este să selectăm toate pozele al căror nume corespunde acestui tipar și să le mutăm într-un director separat.
Pentru a face acest lucru, folosim **globbing**, ca în exemplul de mai jos:

.. code-block:: bash

    student@uso:~/Pictures$ mv DCIM* excursie-Sinaia-2020/

Observăm argumentul pe care l-am dat comenzii ``mv``, și anume ``DCIM*``.
Expresia ``DCIM*`` este un exemplu de globbing: adică o expresie care descrie un tipar prin folosirea unor caractere speciale, așa cum este caracterul ``*``.
În cazul de față, expresia ``DCIM*`` înseamnă orice fișier al cărui nume începe cu șirul de caractere ``DCIM``.

Caracterul special ``*``
^^^^^^^^^^^^^^^^^^^^^^^^

În sintaxa globbing, caracterul ``*`` poate fi înlocuit cu orice caracter de oricâte ori, sau poate lipsi cu totul.
În directorul nostru home (``~``), executăm următoarele comenzi:

.. code-block:: bash

    student@uso:~$ ls
    Desktop    Downloads  Pictures  Templates  examples.desktop  vm-actions-log.txt
    Documents  Music      Public    Videos     uso.git           workspace

    student@uso:~$ ls -d D*
    Desktop  Documents  Downloads

    student@uso:~$ ls -d Music*
    Music

Observăm că în expresia ``D*``, caracterul ``*`` înglobează toate caracterele care urmează literei **D**: "esktop", "ocuments" și "ownloads".
Observăm că în cazul expresie ``Music*``, ``*`` nu ține locul nici unui caracter.


Caracterul special ``?``
^^^^^^^^^^^^^^^^^^^^^^^^

În sintaxa globbing, caracterul ``?`` înlocuiește exact un caracter, oricare ar fi acela.
În directorul nostru home (``~``), executăm următoarele comenzi:

.. code-block:: bash

    student@uso:~$ ls -d Musi?
    Music

    student@uso:~$ ls -d Mus??
    Music

    student@uso:~$ ls -d Music?
    ls: cannot access 'Music?': No such file or directory

Observăm că expresiile ``Musi?`` și ``Mus??`` s-au înlocuit cu succes cu numele directorului ``Music``, dar expresia ``Music?`` a generat o eroare deoarece nu există nici un fișier **Music** urmat de un caracter.


Extra: Sintaxa specială ``[]``
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

În sintaxa globbing, folosim sintaxa ``[]`` pentru a defini o listă de caractere care pot fi folosite în înlocuire.
Această sintaxă înlocuiește exact un caracter din lista oferită.
În directorul nostru home (``~``), executăm următoarele comenzi:

.. code-block:: bash

    student@uso:~$ ls -d Mus[ijk]c
    Music

    student@uso:~$ ls -d Mus[abc]c
    ls: cannot access 'Mus[abc]c': No such file or directory

În expresia ``Musi[ijk]c``, i-am "spus" shellului că al patrulea caracter poate să fie oricare din lista ``[ijk]``.
În acest context, globbing a găsit cu succes numele fișierului **Music**.
În expresia ``Musi[abc]c``, i-am "spus" shellului că al patrulea caracter poate să fie oricare din lista ``[abc]``.
Deoarece nu avem niciun fișier numit **Musac**, **Musbc** sau **Muscc**, comanda ne-a afișat mesajul de eroare corespunzător.

Sintaxa ``[]`` nu ne limitează la a oferi enumarații de caractere, așa cum am făcut cu ``[ijk]`` sau ``[abc]``.
Sintaxa accepta și intervale, cum observăm în exemplul de mai jos:

.. code-block:: bash

    student@uso:~$ ls -d Mus[A-Za-z0-9]c
    Music

Citim expresia ``[A-Za-z0-9]`` în următorul mod: această expresie înlocuiește un caracter din intervalul ``A-Z`` sau din intervalul ``a-z`` sau din intervalul ``0-9``; cu alte cuvinte înlocuiește un caracter *alfa-numeric* [#glob-list]_.

.. tip::

    Folosind sintaxa ``[]`` putem rescrie mutarea pozelor a.î. să o facem mai precisă:

    .. code-block:: bash

        student@uso:~/Pictures$ mv DCIM[0-9][0-9][0-9][0-9] excursie-Sinaia-2020/

    Cu expresia de mai sus vom muta toate pozele din intervalul **DCIM0000** - **DCIM9999**.


Extra: Sintaxa specială ``{}``
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

În sintaxa globbing, folosim sintaxa ``{}`` pentru a defini o listă de cuvinte (grupuri de caractere) care pot fi folosite în înlocuire.
Această sintaxă înlocuiește exact un cuvânt din lista oferită.
În directorul vostru home (``~``), executați următoarele comenzi:

.. code-block:: bash

    student@uso:~$ ls -d {Downloads,Music}
    Downloads  Music

    student@uso:~$ ls -d {Down,Mus}*
    Downloads  Music

Citim expresia ``{Downloads,Music}``: în locul acestei expresii poate să existe cuvântul **Downloads** sau cuvântul **Music**.
Observăm că putem să combinăm orice elemente de globbing, așa cum am făcut în expresia ``{Down,Mus}*``.

Extra: Folosirea ad-litteram a caracterelor speciale
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Există cazuri când numele fișierelor conțin caractere speciale.
Unele fișiere pot fi prefixate cu o categorie din care fac parte, ca în exemplul de mai jos:

.. code-block:: bash

    student@uso:~$ ls Documents/uni
    '[PC] Course 01.pdf'  '[USO] Course 01.pdf'  '[USO] Course 02.pdf'

În exemplul de mai sus, fișierele pdf de curs sunt prefixate cu numele materiei: [PC], [USO].
Vrem să îi spunem sintaxei de globbing că în acest caz, șirul **[USO]** nu trebuie tratat ca o expresie, ci ca un șir de caracter normale.
Pentru a face acest lucru, încadrăm șirul între **"**:

.. code-block:: bash

    student@uso:~$ ls Documents/uni/"[USO]"*
    'Documents/uni/[USO] Course 01.pdf'  'Documents/uni/[USO] Course 02.pdf'

Citim expresia ``"[USO]"*``: orice fișier al cărui nume începe cu șirul de caractere **[USO]** și este urmat de orice caracter.
Operația prin care eliminăm semnificația specială a unui caracter poartă numele de **escaping**; cu alte cuvinte, informal, spunem că am făcut escaping semnificației speciale a sintaxei ``[]``.
Termenul vine de la cuvântul **escape** (a scăpa), și exprimă că scăpăm de semnificația specială a unui caracter / set de caractere.

Exerciții
^^^^^^^^^

Pentru exercițiile următoare vom folosi fișierele din directorul de suport ``support-globbing``.

#. Creați un director numit ``pdfs``.
   Mutați toate fișierele cu extensia ``.pdf`` din directorul ``support-globbing`` în directorul ``pdfs``.

#. Creați un director numit ``Excursie Brasov, 2020-2021``.
   Mutați fișierele **DCIM** din intervalul 1400 - 1700 în directorul creat.

#. Creați un director numit ``cursuri/anul-I``.
   Mutați toate fișierele care conțin cuvintele **curs** sau **slide** în directorul creat.
   Extra: Folosiți sintaxa ``*{curs,slide}*``.


Căutarea unui fișier în sistem
------------------------------

De multe ori ne aflăm în situația în care căutăm un fișier pe disc: ex. doar ce am clonat un proiect de pe GitHub și vrem să inspectăm fișierul **Makefile** pentru a vedea cum compilăm și rulăm proiectul.
Un alt exemplu poate fi că vrem să vedem cum arată fișierele de test existente în proiect; de multe ori, ințelegem mai bine proiectul doar prin simpla inspectare a testelor.

Există două utilitare care ne permit să căutăm în cadrul sistemului de fișiere: ``locate`` și ``find``.

Utilitarul ``locate``
^^^^^^^^^^^^^^^^^^^^^

Utilitarul ``locate`` folosește o bază de date pentru a căuta în fișierele de pe sistem.
Inspectăm pagina de manual a utilitarului pentru a vedea cum îl putem folosi, folosind comanda ``man``:

.. code-block:: bash

    student@uso:~$ man locate

    SYNOPSIS
           locate [OPTION]... PATTERN...

Observăm că ``locate`` primește ca argument un șir de caractere, **PATTERN**, care fac parte din numele fișierului pe care în căutăm, dar nu trebuie să-i dăm numele exact:

.. code-block:: bash

    student@uso:~$ locate todos.txt
    /home/student/Desktop/todos.txt
    student@uso:~$ locate todos
    /home/student/Desktop/todos.txt

Putem să folosim și sintaxa globbing pentru a descrie numele fișierului căutat:

.. code-block:: bash

    student@uso:~$ locate "*.txt"
    /home/student/vm-actions-log.txt
    /home/student/.local/lib/python2.7/site-packages/Keras_Applications-1.0.8.dist-info/top_level.txt
    /home/student/.local/lib/python2.7/site-packages/Keras_Preprocessing-1.1.2.dist-info/top_level.txt
    /home/student/.local/lib/python2.7/site-packages/Markdown-3.1.1.dist-info/entry_points.txt
    /home/student/.local/lib/python2.7/site-packages/Markdown-3.1.1.dist-info/top_level.txt
    /home/student/.local/lib/python2.7/site-packages/Werkzeug-1.0.1.dist-info/top_level.txt

Căutările cu ``locate`` sunt foarte rapide.
Acest lucru se datorează utilizării bazei de date pentru a indexa fișierele din sistem.
Într-o configurație implicită (*default*), baza de date se reconstruiește periodic, o dată la 24h.
Asta înseamnă că ``locate`` nu va găsi fișiere care au fost create după reconstrucția bazei de date.
Dacă vrem să reconstruim baza de date, folosim comanda ``updatedb``.

Hai să clonăm repository-ul **TheAlgorithms/C**.
Acesta conține implementările diferitor algoritmi folosind limbajul de programare C.

.. code-block:: bash

    student@uso:~$ cd workspace
    student@uso:~/workspace$ git clone https://github.com/TheAlgorithms/C.git
    student@uso:~/workspace$ cd C

Fiind vorba despre un repository care implementează algoritmi clasici, ne așteptăm să găsim și algoritmi de căutare, cum ar fi binary-search.
Hai să căutăm după cuvântul cheie **search**.

.. code-block:: bash

    student@uso:~/workspace$ locate search | grep workspace/C
    student@uso:~/workspace$ 

Observăm că nu am găsit nici un rezultat.
Cum spuneam mai devreme, trebuie să reconstruim baza de date pentru a căuta în fișierele nou create.

.. code-block:: bash

    student@uso:~/workspace/C$ sudo updatedb
    [sudo] password for student: 

Comanda ``updatedb`` trebuie executată în mod privilegiat, așa că folosim ``sudo``.
Parola utilizatorului **student**, pe mașina noastră virtuală, este **student**.

.. code-block:: bash

    student@uso:~/workspace/C$ locate search | grep workspace/C
    /home/student/workspace/C/searching
    /home/student/workspace/C/data_structures/binary_trees/binary_search_tree.c
    /home/student/workspace/C/searching/CMakeLists.txt
    /home/student/workspace/C/searching/binary_search.c
    /home/student/workspace/C/searching/fibonacci_search.c
    /home/student/workspace/C/searching/interpolation_search.c
    /home/student/workspace/C/searching/jump_search.c
    /home/student/workspace/C/searching/linear_search.c
    /home/student/workspace/C/searching/modified_binary_search.c
    /home/student/workspace/C/searching/other_binary_search.c
    /home/student/workspace/C/searching/pattern_search
    /home/student/workspace/C/searching/ternary_search.c
    /home/student/workspace/C/searching/pattern_search/CMakeLists.txt
    /home/student/workspace/C/searching/pattern_search/boyer_moore_search.c
    /home/student/workspace/C/searching/pattern_search/naive_search.c
    /home/student/workspace/C/searching/pattern_search/rabin_karp_search.c

Exerciții
"""""""""

#. Folosind ``locate`` căutați fișierele care conțin șirul ``bubble_sort`` în nume.

#. Folosind ``locate`` căutați fișierele care conțin șirul ``quick_sort`` în nume.

#. Folosind ``locate`` căutați fișierele care conțin șirul ``merge_sort`` în nume.

#. Folosind ``locate`` căutați fișierele care conțin șirul ``sort`` în nume.

Utilitarul ``find``
^^^^^^^^^^^^^^^^^^^

Utilitarul ``find`` îndeplinește același scop: căuta în fișierele de pe sistem.
``find`` este un utilitar mai complex decât ``locate``.
Acesta ne permite să căutăm fișiere după nume, permisiuni, tipul fișierelor, data ultimei modificări și multe altele.
Inspectăm pagina de manual a utilitarului pentru a vedea cum îl putem folosi.

.. code-block:: bash

    student@uso:~$ man find

    SYNOPSIS
           find  [-H]  [-L]  [-P]  [-D  debugopts]  [-Olevel]  [starting-point...]
           [expression]


La o primă vedere, ``find`` poate părea complex și intimidant, dar lucrurile stau foarte simplu.
Folosim ``find`` cu sintaxa ``find [starting-point] [expression]``, ca în exemplul de mai jos:

.. code-block:: bash

    student@uso:~$ find . -name "*search*"
    ./C/searching
    ./C/searching/linear_search.c
    ./C/searching/other_binary_search.c
    ./C/searching/binary_search.c
    ./C/searching/modified_binary_search.c
    ./C/searching/jump_search.c
    ./C/searching/interpolation_search.c
    ./C/searching/fibonacci_search.c
    ./C/searching/ternary_search.c
    ./C/searching/pattern_searc h
    ./C/searching/pattern_search/naive_search.c
    ./C/searching/pattern_search/boyer_moore_search.c
    ./C/searching/pattern_search/rabin_karp_search.c
    ./C/data_structures/binary_trees/binary_search_tree.c

În exemplul de mai sus observă că am folosit ca **starting-point** ``.`` (căutarea pleacă din directorul curent), iar ca **expression** ``-name "*search*"``.

Utilitarul ``find`` folosește o expresie compusă pentru căutare.
În exemplul anterior am folosit opțiunea ``-name PATTERN``.
Exact ca în cazul utilitarului ``locate``, **PATTERN** poate folosi sintaxa globbing, așa cum am făcut în exemplul de mai sus ``"*search*"``.

.. note::
    Atunci când folosim sintaxa globbing, trebuie să fim atenți să încadrăm **PATTERN** între ``"`` (ghilimele), așa cum am făcut în exemplul de mai sus.
    Trebuie să facem asta pentru ca sintaxa globbing să fie interpretată de către utilitarul ``find`` și nu de către terminalul (``bash``) din care lansăm utilitarul.

Extra: Scenarii complexe de căutare
"""""""""""""""""""""""""""""""""""

Utilitarul ``find`` are o lungă listă de opțiuni pe care le putem folosi în expresii de căutare.
Una din opțiunile mai cunoscute este ``-type`` care ne oferă posibilitatea de a căuta după tipul unui fișier:

.. code-block:: bash

    student@uso:~$ find workspace/C -type f
    workspace/C/leetcode/src/226.c
    workspace/C/leetcode/src/700.c
    workspace/C/leetcode/src/278.c
    [...]

În exemplul de mai sus i-am transmis utilitarului ``find`` că vrem să căutăm în directorul ``~/workspace/C`` toate fișierele text (regular file) ``-type f``.

**Exercițiu:** Accesați pagina de manual a utilitarului find (``man find``) și căutați opțiunea ``-type``.
Căutați în directorul ``workspace/C`` după fiecare tip de fișier pentru care oferă suport opțiunea ``-type``.

.. note::
    Reminder: pentru a căuta în man folosim ``/`` pentru a intra în search mode și apoi introducem textul pe care îl căutam ``-type`` urmat de tasta ``Enter``; pentru a ne duce la următorul rezultat al căutării folosim tasta ``n`` (next).

În cadrul unei căutări putem să combinăm opțiunile de căutare:

.. code-block:: bash

    student@uso:~$ find workspace/C -type f -name "*search*"
    workspace/C/searching/modified_binary_search.c
    workspace/C/searching/ternary_search.c
    workspace/C/searching/jump_search.c
    workspace/C/searching/binary_search.c

În exemplul de mai sus căutăm toate fișierele text care conțin șirul **search** în nume.

Utilitarul ``find`` ne permite să executăm comenzi asupra rezultatelor căutării.
Facem acest cu opțiunea ``-exec command {} ;``.
Atunci când folosim ``-exec``, rezultatul căutării va înlocui șirul **'{}'** în textul comenzii; comanda de executat trebuie să se termine în caracterul ``;``.

Observăm exemplul de mai jos:

.. code-block:: bash

    student@uso:~$ find workspace/C -type f -name "*search*" -exec ls -l {} \;
    -rw-r--r-- 1 student student 3312 sep 17 19:20 workspace/C/searching/modified_binary_search.c
    -rw-r--r-- 1 student student 1782 sep 17 19:20 workspace/C/searching/ternary_search.c
    -rw-r--r-- 1 student student 1624 sep 17 19:20 workspace/C/searching/jump_search.c
    -rw-r--r-- 1 student student 2799 sep 17 19:20 workspace/C/searching/binary_search.c
    -rw-r--r-- 1 student student 867 sep 17 19:20 workspace/C/searching/other_binary_search.c

În exemplul de mai sus, argumetul opțiunii ``exec`` este ``ls -l {} \;``.
În cuvinte, pentru fiecare fișier text care conține șirul **search** vom afișa informații în format lung (``ls -l {}``).
Observăm că ``-exec`` se încheie cu ``\;``: este nevoie să escapăm caracterul ``;`` pentru ca acesta să fie interpretat de către utilitarul ``find`` și nu de către terminalul în care rulăm, exact ca în cazul ``-name PATTERN``.

În secțiunile ce urmează vom vedea cum ne folosim de opțiunea ``exec`` pentru a face recursiv search & replace în fișiere.

Exerciții
"""""""""

#. Folosind ``find`` căutați fișierele care conțin șirul ``bubble_sort`` în nume.

#. Folosind ``find`` căutați fișierele care conțin șirul ``quick_sort`` în nume.

#. Folosind ``find`` căutați fișierele care conțin șirul ``merge_sort`` în nume.

#. Folosind ``find`` căutați fișierele care conțin șirul ``sort`` în nume.

.. rubric:: Note de subsol

.. [#glob-list]

    Folosim forma ``A-Za-z`` pentru a preciza orice caracter din alfabetul englez, indiferent dacă este majusculă sau nu.
    Nu putem folosi forma ``A-z`` datorită reprezentării caracterelor în tabelul ASCII.
    Caracterele **A-Z** sunt reprezentate în intervalul **65-90**, iar caracterele **a-z** în intervalul **97-122** în tabelul ascii.
    Dacă am folosi forma **A-z**, i-am indica expresiei globbing să includă și caracterele din intervalul **91-96** din tabelul ascii în expresia noastră.

.. [#search-case]

    Căutarea este case-sensitive.
    Putem să schimbăm acest comportament prin introducerea opțiunii ``-I`` în sesiunea interactivă, înainte de a porni căutarea.
    Dacă doriți să aflați mai multe despre opțiunile pe care le putem introduce apăsați tasta ``h`` într-o sesiune interactivă și căutați textul "OPTIONS".


.. [#rev-search]

    Putem folosi tasta ``?`` pentru a porni o căutare de la poziția curentă către începutul paginii.
    Alternativ, putem naviga la începutul paginii prin apăsarea unei singure taste (``g``) și apoi pornim căutarea ``/`` de acolo.
