.. _improve_cli_improve_shell:

O înțelegere mai bună a shellului
=================================


Configurarea shellului bash
---------------------------

Așa cum am menționat în secțiunea Configurarea rulării aplicațiilor, modul în care o aplicație rulează este configurabil.
Fișierul de configurare al shellului **BASH** este ``~/.bashrc``.
În directorul home al fiecărui utilizator se găsește un fișier ``.bashrc``.
Există câte un fișier ``.bashrc`` în directorul home al fiecărui utilizator pentru a le permite utilizatorilor să își personalizeze comportamentul shellului lor bash, fără a intra în conflict cu configurările bash ale altor utilizatori din sistem.
Atunci când un utilizator pornește un shell bash, conținutul fișierului ``~/.bashrc`` este citit și sunt aplicate configurările specifice utilizatorului.

Shellul *bash*, ca majoritatea programelor, vine cu un set de configurări default care poate nu sunt pe placul tuturor utilizatorilor.
Prin fișierul ``.bashrc`` utilizatorul poate modifica setul default a.î. să se potrivească cu stilul său: un exemplu des întâlnit este modificarea dimensiunii isoricului de comenzi.

Modificarea dimensiunii istoricului
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Inspectăm conținutul fișierului ``~/.bashrc`` folosind comanda următoare:

.. code-block:: bash

    student@uso:~$ less ~/.bashrc

În sesiunea interactivă ``less`` căutăm după cuvântul ``HISTSIZE``:

.. code-block:: bash

    [...]
    # for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
    HISTSIZE=1000
    HISTFILESIZE=2000
    [...]

Shellul bash reține istoricul de comenzi în fișierul ``~/.bash_history`` din directorul home al fiecărui utilizator.
Valorile variabilelor ``HISTSIZE`` și ``HISTFILESIZE`` limitează numărul maxim de comenzi, respectiv linii, din fișierul ``~/.bash_history``.
Dacă vrem să avem un istoric nelimitat putem seta valoarea variabilelor la un număr negativ.

**Exercițiu**: Deschideți fișierul ``~/.bashrc`` în editorul preferat și atribuiți valoarea ``-1`` pentru ``HISTSIZE`` și ``HISTFILESIZE``.
Salvați modificările făcute.

.. warning::

    Atenție!
    **Nu** trebuie să existe spațiu între numele variabilei, ``=`` și valoarea atribuită.

.. tip::

    Pentru a afla mai multe despre valorile ``HISTSIZE`` și ``HISTFILESIZE`` accesați pagina de manual a terminalului bash (``man bash``) și căutați după numele variabilelor.


Vizualizarea aliasurilor predefinite
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Pentru a înțelege ce este un **alias**, rulăm comanda de mai jos:

.. code-block:: bash

    student@uso:~$ alias ls
    alias ls='ls --color=auto'

Un alias este un nume (*placeholder*) care înlocuiește un șir de caractere.
Atunci când scriem în terminal numele unei comenzi, dacă numele scris este un alias, numele comenzii va fi înlocuit cu șirul de caractere definit în alias.
Cu alte cuvinte, atunci când executăm comanda ``ls`` în terminalul bash, defapt executăm comanda ``ls --color=auto``.
Opțiunea ``--color=auto`` este cea care ne colorează rezultatul comenzii ``ls``.

Pentru a vedea toate aliasurile definite în instanța curentă de bash, folosim comanda ``alias``, ca în exemplul de mai jos:

.. code-block:: bash

    student@uso:~$ alias
    alias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echo error)" "$(history|tail -n1|sed -e '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'
    alias boot-cli='systemctl set-default multi-user.target'
    alias boot-gui='systemctl set-default graphical.target'
    alias cal='ncal -M'
    alias egrep='egrep --color=auto'
    alias fgrep='fgrep --color=auto'
    alias gigt='git'
    alias gpre='grep'
    alias grep='grep --color=auto'
    alias grpe='grep'
    alias gti='git'
    alias l='ls -CF'
    alias la='ls -A'
    alias ll='ls -alF'
    alias ls='ls --color=auto'
    alias ncal='ncal -M

Observăm că atât ``grep`` cât și ``egrep`` au câte un alias pentru opțiunea ``--color``, care în cazul acesta face highlight expresiei găsite.
Putem defini un alias și pentru un typo pe care îl facem des, așa cum este cazul pentru ``gti``, un alias pentru comanda ``git``.

O parte din aceste aliasuri sunt definite în fișierul ``~/.bashrc``, iar altele în fișierul ``~/.bash_aliases``.
Conținutul fișierului ``~/.bash_aliases`` este inclus de către fișierul ``~/.bashrc`` la pornirea shellului bash.
Astfel, pentru o organizare mai bună, este recomandat ca utilizatorul să-și definească aliasurile în fișierul ``~/.bash_aliases``.

Putem observa asta folosind comanda următoare:

.. code-block:: bash

    student@uso:~$ grep alias ~/.bashrc
    # enable color support of ls and also add handy aliases
        alias ls='ls --color=auto'
        #alias dir='dir --color=auto'
        #alias vdir='vdir --color=auto'
        alias grep='grep --color=auto'
        alias fgrep='fgrep --color=auto'
        alias egrep='egrep --color=auto'
    [...]

    student@uso:~$ cat ~/.bash_aliases
    alias grep='grep --color=auto'
    alias grpe='grep'
    alias gpre='grep'
    alias gti='git'
    [...]

Definirea unui alias
^^^^^^^^^^^^^^^^^^^^

Utilitarul ``xdg-open`` primește calea către un fișier și deschide fișierul respectiv cu aplicația asociată tipului de fișier.
Astfel, comanda ``xdg-open image.png`` va deschide imaginea **image.png** cu aplicația asociată deschiderii formatului **PNG**.
Putem să folosim și un URL ca argument al comenzii ``xdg-open``; astfel, comanda ``xdg-open https://www.google.com`` va deschide pagina Google în browserul vostru implicit.

Ne dorim să definim aliasul ``go`` pentru comanda ``xdg-open``.
Adăugați linia ``alias go='xdg-open'`` în fișierul ``~/.bash_aliases`` și salvați modificările.

Dacă încercăm să folosim aliasul proaspăt definit, vom primi o eroare similară cu cea de mai jos:

.. code-block:: bash

    student@uso:~$ go https://www.google.com

    Command 'go' not found, did you mean:

      command 'go' from snap go (1.15.3)
      command 'mco' from deb mcollective-client
      command 'mgb' from deb mathicgb
      command 'mgp' from deb mgp
      command 'mgt' from deb mgt
    [...]

Acest lucru se întâmplă din cauză că fișierul ``~/.bashrc`` este citit atunci când pornim o instanță de bash (când deschidem un terminal).
Ca să recitim fișierul, și să aplicăm modificările, folosim comanda ``source`` ca în exemplul de mai jos:

.. code-block:: bash

    student@uso:~$ source ~/.bashrc
    student@uso:~$ go https://www.google.com

Comanda ``source ~/.bashrc`` a avut ca efect citirea și aplicarea modificărilor definite în fișierul ``.bashrc`` și fișierele pe care acesta le include.


Execuția comenzilor
-------------------

Încheierea execuției unei comenzi
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Atunci când rulăm o comandă aceasta își poate încheia execuția în două moduri: cu **succes** sau cu **eșec**.
Atunci când își încheie execuția, orice proces întoarce un cod de eroare, care este un număr:

* Dacă numărul întors are valoarea ``0``, procesul și-a încheiat execuția cu succes.
* Dacă numărul întors are orice altă valoare, procesul și-a încheiat execuția cu eroare, iar codul întors poate fi folosit pentru a afla mai multe informații despre eroarea pe care a întors-o procesul.
  În pagina ``man`` a utilitarului ``ls`` este specificat:

  .. code-block:: bash

     Exit status:
            0      if OK,

            1      if minor problems (e.g., cannot access subdirectory),

            2      if serious trouble (e.g., cannot access command-line argument).

Pentru a vedea codul cu care și-a încheiat execuția o comandă folosim sintaxa ``$?``.
Urmărim exemplul de mai jos:

.. code-block:: bash

    student@uso:~$ ls Desktop/
    todos.txt
    student@uso:~$ echo $?
    0
    student@uso:~$ ls non-existent
    ls: cannot access 'non-existent': No such file or directory
    student@uso:~$ echo $?
    2

Observăm că în cazul fișierului inexistet, comanda ``ls non-existent`` a întors valoarea ``2``, așa cum era specificat și în pagina de manual.

.. _improve_cli_improve_shell_oneliners:

Înlănțuirea comenzilor în funcție de succes sau eșec
""""""""""""""""""""""""""""""""""""""""""""""""""""

De multe ori vrem să executăm o succesiune de comenzi pentru a realiza o sarcină.
De exemplu, atunci când vrem să instalăm o aplicație o rulăm trei comenzi:

* O să actualizăm indexul surselor de pachete folosind ``apt update``
* O să instalăm pachetul care conține aplicația folosind ``apt install``
* O să rulăm aplicația pentru a valida că instalarea a fost cu succes.

Preferăm să înlănțuim cele trei comenzi într-una singură pentru că astfel putem să pornim tot acest proces, să plecăm de la calculator, iar când ne întoarcem avem tot sistemul pregătit.

Pentru a înlănțui comenzi în terminalul bash avem trei operatori disponibili:

* Operatorul ``;`` - este folosit pentru separarea comenzilor
  Urmăm exemplul de mai jos:

  .. code-block:: bash

     student@uso:~$ mkdir demo; cd demo; touch Hello; ls
     Hello

  În exemplul de mai sus am creat directorul ``demo``, am navigat în interiorul său, am creat fișierul ``Hello`` și am afișat conținutul directorului.
  Am făcut toate acestea înlănțuind comenzile ``mkdir``, ``cd``, ``touch`` și ``ls`` cu ajutorul operatorului ``;``.

  Operatorul ``;`` este folosit pentru separarea comenzilor, dar nu ține cont dacă comenzile anterioare au fost executate cu succes sau nu.
  Urmăm exemplul de mai jos:

  .. code-block:: bash

     student@uso:~$ mkdir operators/demo; cd operators/demo
     mkdir: cannot create directory ‘operators/demo’: No such file or directory
     -bash: cd: operators/demo: No such file or directory

  În exemplul de mai sus, comanda ``mkdir`` a eșuat deoarece nu a găsit directorul ``operators`` în care să creeze directorul ``demo``. Cu toate acestea, operatorul ``;`` doar separă comenzile între ele, așa că și comanda ``cd operators/demo`` a fost executată, și și aceasta a eșuat deoarece nu există calea ``operators/demo``.

  Folosim operatorul ``;`` pentru a înlănțui comenzi care sunt independente unele de altele, și deci execuția lor nu depinde de succesul unei comenzi precedente.

* Operatorul binar ``&&`` (și logic) - execută a doua comandă doar dacă precedenta s-a executat cu succes.
  Exemplul anterior devine:

  .. code-block:: bash

     student@uso:~$ mkdir operators/demo && cd operators/demo
     mkdir: cannot create directory ‘operators/demo’: No such file or directory

  Observăm că din moment ce comanda ``mkdir`` a eșuat, comanda ``cd`` nu a mai fost executată.

* Operatorul binar ``||`` (sau logic) - execută a doua comandă doar dacă prima s-a terminat cu eșec.
  Urmărim exemplul de mai jos:

  .. code-block:: bash

     student@uso:~$ (ls -d operators || mkdir operators) && ls -d operators
     ls: cannot access 'operators': No such file or directory
     operators
     student@uso:~$ (ls -d operators || mkdir operators) && ls -d operators
     operators
     operators

  În exemplul de mai sus, prima comandă ``ls`` a eșuat, așa că a fost executată comanda ``mkdir`` și apoi a fost executată ultima comandă ``ls``.
  La cea de-a doua rulare, a fost executată cu succes prima comandă ``ls``, așa că comanda ``mkdir`` nu a mai fost executată, și apoi a fost executată ultima comandă ``ls``.

Pentru a rezolva scenariul de la care am plecat inițial, putem rula:

.. code-block:: bash

    sudo apt update && sudo apt install -y cowsay && cowsay "Howdy"

Comanda de mai sus va actualiza indexul pachetelor sursă, va instala pachetul ``cowsay`` și va rula comanda ``cowsay`` pentru a valida instalarea.
O astfel de înlănțuire de comenzi este numită **oneliner**.

Exerciții
"""""""""

#. Scrieți un oneliner cu ajutorul căruia descărcați arhiva tar de la adresa TODO, creați directorul ``~/operators/demo/tar`` și apoi dezarhivați conținutul în directorul creat.
#. Actualizați onelinerul anterior a.î. după dezarhivare să pornească compilarea proiectului folosind comanda ``make build``.

Înlănțuirea comenzilor folosind operatorul ``|`` (pipe)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Așa cum am descoperit în secțiunile și capitolele anterioare, în mediul Linux avem multe utilitare care rezolvă o nevoie specifică: ``ls`` afișează informații despre fișiere, ``ps`` despre procese, ``grep`` filtrează, etc.
Toate acestea au la bază filozofia mediului Linux: "do one thing and do it well".
Ca întodeauna, frumusețea stă în simplitate: avem o suită de unelte la dispoziție, fiecare capabilă să rezolve rapid o sarcină dată; pentru a rezolva o problemă mai complexă trebuie doar să îmbinăm uneltele.

Operatorul ``|`` (pipe) ne ajută să facem acest lucru.
Atunci când folosim operatorul ``|`` preluăm rezultatul comenzii din stânga operatorului și îl oferim ca intrare comenzii aflate în dreapta operatorului.

Am folosit de mai multe ori operatorul ``|`` până acum:

* Am afișat informații despre procesele din sistem și am filtrat după numele unui proces:

  .. code-block:: bash

      student@uso:~$ ps -e | grep firefox
      14912 pts/0    00:00:19 firefox

* Am extras primele zece procese care consumă cel mai mare procent de memorie:

  .. code-block:: bash

      student@uso:~$ ps -e -ouser,uid,pid,%mem,%cpu,rss,cmd --sort=-%mem | head -11
      USER       UID   PID %MEM %CPU   RSS CMD
      student   1000  7938 18.0  0.1 367952 /usr/bin/gnome-shell
      student   1000  8437  8.4  0.0 171916 /usr/bin/gnome-software --gapplication-service
      student   1000  7782  3.9  0.0 81312 /usr/lib/xorg/Xorg vt1 -displayfd 3 -auth /run/user/1000/gdm/Xauthority -background none -noreset -keeptty -verbose 3
      root         0  1338  3.8  0.0 78880 /usr/bin/dockerd -H fd:// --containerd=/run/containerd/containerd.sock
      student   1000  8307  3.1  0.0 64628 /usr/lib/evolution/evolution-calendar-factory
      student   1000  8338  3.0  0.0 61860 /usr/lib/evolution/evolution-calendar-factory-subprocess --factory all --bus-name org.gnome.evolution.dataserver.Subprocess.Backend.Calendarx8307x2 --own-path /org/gnome/evolution/dataserver/Subprocess/Backend/Calendar/8307/2
      root         0   336  2.6  0.0 53612 /lib/systemd/systemd-journald
      student   1000  8274  2.3  0.0 48296 nautilus-desktop
      root         0  1074  2.2  0.0 45460 /usr/bin/containerd
      student   1000 12966  1.8  0.0 38216 /usr/lib/gnome-terminal/gnome-terminal-server

Până acum am efectuat procesări text pe rezultatul unor comenzi.
Folosind operatorul ``|`` și utilitarul ``xargs`` putem să folosim rezultatul pe post de argument pentru altă comandă, ca în exemplul de mai jos:

.. code-block:: bash

    student@uso:~$ find . -maxdepth 1 -type f | xargs ls -l
    -rw------- 1 student student    10992 nov  6 14:56 ./.ICEauthority
    -rw-r--r-- 1 student student      297 nov  7 00:18 ./.bash_aliases
    -rw------- 1 student student    43604 nov  5 02:34 ./.bash_history
    -rw-r--r-- 1 student student      220 aug  6  2018 ./.bash_logout
    -rw-r--r-- 1 student student     3824 aug 13 19:04 ./.bashrc
    -rw-r--r-- 1 student student     3159 aug 20  2018 ./.emacs
    -rw-r--r-- 1 student student       87 aug 21  2018 ./.gitconfig
    -rw------- 1 student student      361 nov  7 02:40 ./.lesshst

Comanda din exemplul de mai sus afișează informații în format lung despre toate fișierele din directorul curent, excluzând directoarele.

Dacă folosim opțiunea ``-p`` a utilitarului ``xargs``, acesta o să ne afișeze ce comandă urmează să execute și așteaptă confirmarea noastră prin apăsarea tastei ``y`` (yes) sau ``n`` (no).
Este recomandat să folosiți opțiunea ``-p`` atunci când vă scrieți onelinerul pentru a verifica că comanda pe care urmează să o executați este corectă.
În exemplul următor ne dorim să mutăm toate arhivele ``.tar`` în directorul ``archives``:

.. code-block:: bash

    student@uso:~$ ls *.tar | xargs -p mv archives
    mv archives courses.tar labhidden.tar uso.tar wiki.tar ?...n

Cu ajutorul opțiunii ``-p`` am putut să observăm că comanda nu are sintaxa dorită și am anulat execuția ei.
Problema este că avem destinația (``archives``) înaintea arhivelor care trebuie mutate.

Pentru a rezolva această problemă folosim opțiunea ``-I str``, ca mai jos:

.. code-block:: bash

    student@uso:~$ ls *.tar | xargs -I str -p mv str archives
    mv courses.tar archives ?...n
    mv labhidden.tar archives ?...n
    mv uso.tar archives ?...n
    mv wiki.tar archives ?...n

Opțiunea ``-I`` va înlocui șirul de caractere ``str`` cu numele arhivelor primite din pipe, așa cum observăm mai sus.
Șirul de caractere placeholder poate să fie orice, nu neapărat ``str``; comanda ``ls *.tar | xargs -I {} -p mv {} archives`` produce aceelași rezultat.

Redirectări
^^^^^^^^^^^

Majoritatea utilitarelor pe care le folosim afișează rezultatele operațiilor pe care le aplică la ieșirea standard, adică pe ecran.
În continuare vom aprofunda ceea ce am discutat despre redirectări în capitolul **Lucrul cu Fișiere**.
Anterior am mai menționat și termenul de intrare standard; în această secțiune ne vom clarifica ce înseamnă, ce rol îndeplinesc și cum ne folosim de aceste cunoștințe.

Orice proces folosește implicit trei fluxuri (streams) de date:

* **STDIN** - fluxul de intrare standard, referit și ca "citit de la tastatură".
  Spunem că un program care citește date de intrare din linie de comandă, deci așteaptă de la utilizator, citește de la intrarea standard; de aici și denumirea "citit de la tastatură".
  Complementul citirii de la tastatură este citirea datelor dintr-un fișier.

* **STDOUT** - fluxul de ieșire standard, referit și ca "afișare pe ecran".
  Spunem că un program afișează datele de ieșire pe ecran, adică scrie rezultatele procesărilor efectuate la ieșirea standard.
  Complementul afișării pe ecran este scrierea rezultatelor într-un fișier.

* **STDERR** - fluxul de ieșire standard al erorilor.
  Un program corect scris o să scrie erorile în fluxul de ieșire al erorilor.
  Acest lucru permite filtrarea erorilor.

În linie de comandă, atât STDOUT cât și STDERR vor apărea pe ecran.
Datorită faptului că informațiile sunt scrise în două fluxuri distincte, utilizatorul are posibilitatea de a separa rezultatele de erori.
Utilizatorul face aceasta folosind redirectări.

Redirectarea ieșirilor standard
"""""""""""""""""""""""""""""""

Cum spuneam mai sus, majoritatea programelor pe care le folosim vor afișa rezultatele pe ecran.
Acest comportament este bun atunci când ne scriem onelinerul care ne extrage informațiile căutate, dar cel mai probabil o să vrem să salvăm rezultatul procesării într-un fișier.

Folosim operatorul ``>`` pentru a redirecta **STDOUT** sau **STDERR** într-un fișier.
Pentru fiecare flux de date avem un număr, numit descriptor de fișier, asociat:

* **STDIN** are asociat descriptorul de fișier 0
* **STDOUT** are asociat descriptorul de fișier 1
* **STDERR** are asociat descriptorul de fișier 2

Pentru a redirecta ieșirea standard folosim sintaxa ``cmd 1> nume-fișier``.
Pentru a redirecta ieșirea standard a erorilor folosim sintaxa ``cmd 2> nume-fișier``.

.. warning::

    **Atenție!**
    În cazul în care fișierul destinație nu există, operatorul ``>`` îl va crea.
    Dacă fișierul destinație există, operatorul ``>`` va șterge conținutul acestuia.

Urmăm exemplul de mai jos:

.. code-block:: bash

    student@uso:~$ ps -e -ouser,uid,pid,%mem,%cpu,rss,cmd --sort=-%mem | head -11
    USER       UID   PID %MEM %CPU   RSS CMD
    student   1000  7938 18.0  0.1 367952 /usr/bin/gnome-shell
    student   1000  8437  8.4  0.0 171916 /usr/bin/gnome-software --gapplication-service
    student   1000  7782  3.9  0.0 81312 /usr/lib/xorg/Xorg vt1 -displayfd 3 -auth /run/user/1000/gdm/Xauthority -background none -noreset -keeptty -verbose 3
    root         0  1338  3.8  0.0 78880 /usr/bin/dockerd -H fd:// --containerd=/run/containerd/containerd.sock
    student   1000  8307  3.1  0.0 64628 /usr/lib/evolution/evolution-calendar-factory
    student   1000  8338  3.0  0.0 61860 /usr/lib/evolution/evolution-calendar-factory-subprocess --factory all --bus-name org.gnome.evolution.dataserver.Subprocess.Backend.Calendarx8307x2 --own-path /org/gnome/evolution/dataserver/Subprocess/Backend/Calendar/8307/2
    root         0   336  2.6  0.0 53612 /lib/systemd/systemd-journald
    student   1000  8274  2.3  0.0 48296 nautilus-desktop
    root         0  1074  2.2  0.0 45460 /usr/bin/containerd
    student   1000 12966  1.8  0.0 38216 /usr/lib/gnome-terminal/gnome-terminal-server
    student@uso:~$ ps -e -ouser,uid,pid,%mem,%cpu,rss,cmd --sort=-%mem | head -11 1> top10-consumers
    student@uso:~$ less top10-consumers

Am scris, prin încercări succesive, onelinerul care ne afișează primele zece procese care consumă cea mai multă memorie.
Apoi am folosit sintaxa ``1> top10-consumers`` pentru a redirecta rezultatul în fișierul **top10-consumers**.

Urmăm exemplul de mai jos pentru a redirecta erorile:

.. code-block:: bash

    student@uso:~$ ls D* F* > out 2> errs
    student@uso:~$ cat out
    Desktop:
    todos.txt

    Documents:
    snippets.git
    uni
    uso.tar

    Downloads:
    courses.tar
    uso.tar
    student@uso:~$ cat errs
    ls: cannot access 'F*': No such file or directory

Observăm că am folosit sintaxa ``2> errs`` pentru a redirecta erorile în fișierul **errs**.
Observăm că pentru a redirecta ieșirea standard putem omite descriptorul de fișier, așa cum am făcut cu ``> out``.

Atunci când rulăm o comandă, redirectăm erorile într-un fișier pentru că vrem să verificăm că totul s-a executat cu succes.
De cele mai multe ori suntem în rumătorul scenariu:

#. Urmează să executăm o comandă care durează mai mult timp și pentru care nu putem să ținem pasul, cu ochiul liber, cu fluxul de afișare a datelor pe ecran.
   Un exemplu este compilarea unui proiect mai mare.
#. O să pornim procesul și o să redirectăm STDOUT și STDERR în două fișiere, de ex. ``out`` și ``err``.
#. În timpul cât rulează noi putem să facem altceva: ne ocupăm de altă sarcină, ne facem o cafea, etc.
#. La finalul execuției inspectăm fișierele ``out`` și ``err`` pentru a vedea dacă au existat erori și le rezolvăm.

.. note::

    Acum înțelegem cum funcționează operatorul ``|`` (pipe).
    Acesta conectează fluxul de ieșire (STDOUT) al comenzii din stânga sa cu fluxul de intrare (STDIN) al comenzii din dreapta.

Redirectarea în mod *append*
""""""""""""""""""""""""""""

Implicit, operatoru ``>`` șterge (trunchează) conținutul fișierului destinație.
Dacă vrem să păstrăm conținutul fișierului și să adăugăm rezultatul redirectării în continuarea acestuia, folosim operatorul ``>>``.

Rulați din nou exemplele de mai sus folosind operatorul ``>>`` în locul operatorului ``>``.
Folosiți less pentru a inspecta fișierele de ieșire și de erori.

Redirectarea erorilor la ieșirea standard
"""""""""""""""""""""""""""""""""""""""""

Motivul pentru care redirectăm erorile într-un fișier este pentru că vrem să analizăm mesajele de eroare.
Avem și scenarii în care rulăm un program care afișează mesaje, la STDOUT și STDERR, de care nu suntem interesați.

Un astfel de scenariu întâlnim atunci când pornim browserul ``firefox`` în linia de comandă: acesta afișează din când în când mesaje de care nu suntem interesați.
Ne dorim să pornim procesul ``firefox`` în background și să redirectăm STDOUT și STDERR a.î. să nu ne polueze inutil consola.
Urmăm exemplul de mai jos:

.. code-block:: bash

    student@uso:~$ firefox &> firefox-ignore &
    [1] 10349
    student@uso:~$ firefox > firefox-ignore 2>&1 &
    [2] 10595

Cele două comenzi de mai sus produc aceelași efect: redirectează atât STDOUT, cât și STDERR în fișierul **firefox-ignore**.
Efectul este produs prin două metode diferite:

* Sintaxa ``&> cale/către/nume-fișier`` - operatorul ``&>`` va unifica fluxul STDERR cu STDOUT și va redirecta către fișierul primit ca argument.
* Sintaxa `` > cale/către/nume-fișier 2>&1`` - operatorul ``2>&1`` folosește descriptori de fișier și redirectează STDERR (descriptorul 2) în STDOUT (descriptorul 1).
  Această sintaxă trebuie precedată de ``> cale/către/nume-fișier``, pe care o citim: ceea ce se găsește pe fluxul de ieșire STDOUT va fi scris în fișierul **cale/către/nume-fișier**.

Fișiere speciale
""""""""""""""""

Pe sistemele Linux găsim un număr de fișiere speciale pe care le putem folosim în diferite scopuri:

* Fișierul ``/dev/null`` este un fișier care ignoră orice este scris în el.
  Este echivalentul unei găuri negre în sistemul nostru.
  Cu ajutorul său, putem rescrie exemplul de mai sus în modul următor:

  .. code-block:: bash

      student@uso:~$ firefox &> /dev/null &
      [1] 10349
      student@uso:~$ firefox > /dev/null 2>&1 &
      [2] 10595

  Acum orice va genera ``firefox`` va fi scris în ``/dev/null``, care va consuma textul primit fără a ocupa spațiu pe disc.

* Fișierul ``/dev/zero`` este un generator de octeți.
  Acesta generează atâția octeți cu valoarea zero (**0**) [#dev-zero]_ cât îi sunt ceruți.
  Urmăm exemplul:

  .. code-block:: bash

      student@uso:~$ cat /dev/zero | xxd
      00000000: 0000 0000 0000 0000 0000 0000 0000 0000  ................
      00000010: 0000 0000 0000 0000 0000 0000 0000 0000  ................
      00000020: 0000 0000 0000 0000 0000 0000 0000 0000  ................
      00000030: 0000 0000 0000 0000 0000 0000 0000 0000  ................
      00000040: 0000 0000 0000 0000 0000 0000 0000 0000  ................
      00000050: 0000 0000 0000 0000 0000 0000 0000 0000  ................
      00000060: 0000 0000 0000 0000 0000 0000 0000 0000  ................
      00000070: 0000 0000 0000 0000 0000 0000 0000 0000  ................
      00000080: 0000 0000 0000 0000 0000 0000 0000 0000  ................
      [...]
      ^C

  Deoarece citim din generator, comanda ``cat`` va afișa o infinitate de octeți cu valoarea zero.
  Utilitarul ``xxd`` afișează în hexazecimal textul primit la STDIN.
  Trecem rezultatul lui ``cat`` prin ``xxd`` deoarece valoarea **0** nu este un caracter printabil.
  Cu alte cuvinte nu este un caracter obișnuit, ca cele de pe tastatură, deoarece nu are un echivalent grafic.
  Folosim ``Ctrl+c`` pentru a opri execția.

  **Exercițiu**: Rulați comanda ``cat /dev/zero`` pentru a înțelege nevoia utilitarului ``xxd`` din exemplul de mai sus.

    * Fișierul ``/dev/urandom`` este un alt generator de octeți.
  Acesta generează atâția octeți cu valoare random cât îi sunt ceruți.

  **Exercițiu**: Rulați comenzile din exemplul anterior, dar acum citiți din ``/dev/urandom``.

Generatoarele de octeți sunt utile pentru a testa aplicațiile pe care le dezvoltăm.
Majoritatea aplicațiilor pe care le vom scrie, ca și cele pe care le utilizăm, citesc și prelucrează informații.
Testăm o aplicație pentru că vrem să verificăm că nu avem buguri.
Pentru aceasta putem să folosim seturi de date de intrare cât mai variate și mai aleatoare, adică inputuri random.
Folosim utilitarul ``dd`` pentru a genera un fișier de 100 MB cu octeți random, ca în exemplul de mai jos:

.. code-block:: bash

    student@uso:~$ dd if=/dev/urandom of=rand-100mb count=100 bs=1M
    100+0 records in
    100+0 records out
    104857600 bytes (105 MB, 100 MiB) copied, 1,11416 s, 94,1 MB/s
    student@uso:~$ ls -lh rand-100mb
    -rw-rw-r-- 1 student student 100M nov  8 17:49 rand-100mb

Am folosit următoarele opțiuni ale utilitarului ``dd``:

* ``if`` - input file - calea către fișierul de unde citim
* ``of`` - output file - calea către fișierul unde scriem
* ``bs`` - block size - dimensiunea unui block citit din **if**
* ``count`` - block count - numărul de block-uri citite

**Exercițiu**: Folosiți fișierul generat și utilitarul ``tar`` pentru a testa diferite metode de compresie a arhivelor.
Creați câte o arhivă pentru fiecare din următoarele opțiuni de compresie: **Z** (compress), **z** (gzip) și **j** (bzip2).
Comparați dimensiunile arhivelor obținute.

.. note::

    Un caz uzual de utilizare a ``dd`` este suprascrierea unui disc cu informații aleatoare.
    Această metodă este utilizată ca o formă de securitate atunci când vrem să ștergem informații de pe un disc.
    Astfel suprascriem datele șterse pentru a preveni posibilitatea recuperării datelor de pe disc.
    Mai multe informații găsiți `aici <https://uwnthesis.wordpress.com/2014/07/26/kali-how-to-use-dd-to-wipe-your-usb-pen-the-visual-guide/>`_.

Exerciții
"""""""""

#. Afișați primele zece procese sortate în funcție de memoria ocupată (Hint: RSS).
   Nu uitați să includeți antetul.
   Redirectați rezultatul în fișierul **top10-rss-consumers**.
   Modificați comanda astfel încât rezultatul redirectării să nu șteargă conținutul existent.

#. Afișați ultimele zece procese sortate în funcție de utilizarea procesorului (Hint: CPU).
   Nu uitați să includeți antetul.
   Redirectați rezultatul în fișierul **top10-cpu-consumers**.
   Modificați comanda astfel încât rezultatul redirectării să nu șteargă conținutul existent.

.. rubric:: Note de subsol

.. [#dev-zero]

    Valoarea **0** nu înseamnă cifra **0**.
    Valoarea **0** înseamnă caracterul **(null)** din tabelul `ASCII <http://www.asciitable.com/>`_.
    Caracterul **0** are valoarea **48** în tabelul ASCII.
