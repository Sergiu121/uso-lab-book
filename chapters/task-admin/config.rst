.. _task_admin_config:

Configurarea stației la distanță
================================

După ce am realizat o conexiune către stația pe care vom lucra, trebuie să ne pregătim mediul de lucru.
Configurația mediului de lucru depinde de propriile gusturi și aplicațiile pe care le folosește fiecare.

Configurarea mediului de lucru este recomandată pentru a adapta sistemul la propriile nevoi.
De exemplu, o persoană care va lucra foarte mult cu repository-uri de tip Git, probabil va avea nevoie de un prompt care să îi afișeze pe ce branch lucrează, astfel încât să gestioneze mai ușor branchurile.
Aceste modificări au rolul de a reduce acțiunile repetitive pe care le facem sau de a pregăti aplicații pe care le vom folosi mai departe.

Această secțiune cuprinde recomandări de configurare a sistemului de la distanță.
Au formă de sugestii, nu sunt obligații, pe baza cărora fiecare poate decide pentru configurarea propriului mediu de lucru.

.. _task_admin_config_shell:

Configurarea shellului
----------------------

Primul aspect pe care îl vom modifica la mediul de lucru este shellul în care rulăm comenzi, deoarece acesta este cea mai folosită unealtă.
Fie că că edităm cod, sau administrăm sisteme, acesta este locul unde rulăm comenzi.

Modificările la nivelul shellului se fac schimbând variabile de mediu sau rulând comenzi înainte de rularea efectivă a shellului.

Modificarea mediului shellului o realizăm într-un fișier de configurare.
Vom folosi fișierul ``~/.profile``, deoarece acesta este citit și rulat de toate implementările de shell majorore, cum ar fi ``dash``, ``csh``, ``bash`` sau ``zsh``, astfel oferă intercompatibilitate între shelluri.

.. _task_admin_config_shell_change:

Modificarea shellului predefinit
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ne dorim să modificăm shellul predefinit pe care îl folosește sistemul, deoarece fiecare implementare de shell oferă propriile funcționalități.
De exemplu, fiecare dintre shellurile ``csh``, ``bash`` și ``zsh`` implementează un mecanism de auto-completion diferit, astfel completarea se face în mod diferit atunci când apăsăm tasta ``Tab``.

Pentru a modifica shellul predefinit al unui utilizator folosim comanda ``usermod`` cu opțiunea ``-s`` în felul următor:

.. code-block::

    student@uso:~$ sudo apt-get install zsh
    [...]
    student@uso:~$ sudo usermod -s /bin/zsh student
    student@uso:~$ su - student
    This is the Z Shell configuration function for new users,
    [...]
    --- Type one of the keys in parentheses --- 2
    /home/student/.zshrc:15: scalar parameter HISTFILE created globally in function zsh-newuser-install
    (eval):1: scalar parameter LS_COLORS created globally in function zsh-newuser-install
    student@uso ~ % echo $SHELL
    /bin/zsh



Rulând comanda de mai sus, am modificat shellul predefinit al utilizatorului ``student`` în ``/bin/zsh``.
Pentru verificare, ne-am autentificat ca utilizatorul ``student``.
La prima autentificare ``zsh`` ne-a întrebat ce fel de configurare vrem, iar noi am folosit opțiunea ``2``, pentru generarea automată a unei configurări.
Am afișat valoarea variabilei ``SHELL`` pentru a afișa calea către shellul folosit.

.. _task_admin_config_shell_change_ex:

Exercițiu: Modificarea shellului predefinit:
""""""""""""""""""""""""""""""""""""""""""""

Modificați shellul predefinit al utilizatorului ``student`` cu shellul ``/bin/bash``.
Încercați să folosiți funcționalitatea de auto-complete. Ce observați?

.. _task_admin_config_shell_alias:

Configurarea aliasurilor
^^^^^^^^^^^^^^^^^^^^^^^^

Există comenzi pe care le rulăm frecvent.
Totuși, unele comenzi sunt lungi și durează mult timp să le tastăm de fiecare dată atunci când vrem să le rulăm.
Pentru a rezolva această problemă, putem folosi aliasuri.
Un alias este o prescurtare pentru o comandă.

Vom folosi comanda ``alias`` pentru defini un alias.

.. code-block::

    student@uso:~$ alias gs="git status"
    student@uso:~$ cd uso-lab/
    student@uso:~/uso-lab$ gs
    On branch master
    Your branch is up to date with 'origin/master'.

    nothing to commit, working tree clean
    student@uso:~/uso-lab$ alias
    [...]
    alias gs='git status'
    alias gti='git'
    alias l='ls -CF'
    alias la='ls -A'
    alias ll='ls -alF'
    alias ls='ls --color=auto'

Am definit aliasul ``gs`` pentru comanda ``git status`` și am verificat-o în repository-ul ``uso-lab``.

Pentru a verifica ce aliasuri sunt definite, vom folosi comanda ``alias`` fără parametri.

Definirea de mai sus a unui alias nu este persistentă, ci acesta va fi definit cât timp shellul curent este deschis.
Pentru a defini un alias în mod persistent, trebuie să îl definim, folosind comanda ``alias`` într-un fișier de configurare, cum ar fi ``.profile``.

.. _task_admin_config_shell_alias_ex:

Exercițiu: Configurarea aliasurilor
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#) Configurați aliasul ``gcs`` pentru comanda ``git commit --signnoff``.
#) Configurați aliasul ``glog`` pentru comanda ``git log --oneline``.

.. _task_admin_config_shell_history:

Modificarea dimensiunii istoricului de comenzi
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Fișierul de istoric al unui shell este locul unde sunt salvate comenzile rulate într-un shell până la închiderea sesiunii de shell.
Acest fișier este folositor pentru repetarea acțiunilor.

De exemplu, funcționalitatea de căutare inversă din shell bazată pe ``Ctrl+r`` caută în istoricul shellului, așa că este de preferat să avem un istoric complet în care să căutăm pentru a avea mai multe intrări în care să căutăm.

Pentru a mări dimensiunea istoricului shellului, este suficient să setăm variabila de mediu ``HISTSIZE`` într-un fișier de configurare.
Vom folosi fișierul de configurare ``.profile`` din motivele enumerate mai sus, aflat în directorul home al utilizatorului ``student``.
Această modificare va fi valabilă doar pentru utilizatorul ``student``.

.. code-block::

    student@uso:~$ echo HISTSIZE=20000 >> /home/student/.profile

.. _task_admin_config_shell_history_ex:

Exercițiu: Modificarea dimensiunii istoricului de comenzi
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Modificarea de mai sus nu este suficientă, deoarece aceasta schimbă doar dimensiunea istoricului din shell, care este salvat în fișierul de istoric la închiderea sesiunii de shell.
La pornirea shellului, dimensiunea fișierului de istoric este concatenată folosind variabila ``HISTFILESIZE``.
Valoarea predefinită a acestei variabile este ``500``.

Faceți modificările necesare astfel încât fișierul de istoric să fie concatenat la ``20000`` de comenzi la pornirea shellului.

.. _task_admin_config_shell_prompt:

Configurarea promptului
^^^^^^^^^^^^^^^^^^^^^^^

După cum am învățat în capitolul <TODO>, atunci când am început să lucrăm cu shellul prima oară, promptul este o sursă importantă de informații.
Acesta ne poate oferi mai multă informație și ne eliberează din a rula anumite comenzi.
Practic, noi putem obține mai mult informații rulând mai puține comenzi.

De exemplu, dacă lucrăm foarte des cu repository-uri de Git, vrem să avem un mod cât mai facil de a vedea pe ce branch lucrăm. Această informație poate fi adăugată în prompt.

Promptul shellului ``bash`` este setat folosind variabila ``PS1``.
Orice șir de caractere va fi scris în variabila ``PS1`` și va fi afișat înainte de zona în care introducem comenzi.
Dacă modificăm variabila ``PS1`` vom vedea că promptul se modifică:

.. code-block::

    student@uso:~$ echo $PS1
    \[\e]0;\u@\h: \w\a\]${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$
    student@uso:~$ PS1="president@white-house:~$ "
    president@white-house:~$ hostname
    uso
    president@white-house:~$ id
    uid=1000(student) gid=1000(student) groups=1000(student),4(adm),24(cdrom),27(sudo),30(dip),46(plugdev),120(lpadmin),131(lxd),132(sambashare),997(docker)
    president@white-house:~$ 

După cum observăm în rezultatul primei comenzi rulate mai sus, valoarea variabilei ``PS1``  este un șir de caractere complex, dar noi putem să îl suprascriem.
Odată suprascrisă variabila ``PS1``, promptul se schimbă în valoarea din variabilă.
Totuși, am rulat comenzi de verificare pentru a vedea că utilizatorul cu care suntem autentificați este în continuare ``student`` și stația la care suntem conectați este ``uso``

Putem să generăm propriul prompt complex folosind utilitare online.
Recomandăm `EZPrompt <https://ezprompt.net/>`_ .
Acest site are funcționalitatea de a genera un prompt modificat.
Vrem să generăm un prompt de forma ``username@hostname:path_to_current_dir-git_branch``.
EZPrompt a generat următoarele comenzi pentru a modifica promptul, pe care le vom adăuga la finalul fișierului ``.profile``:

.. code-block::

    # get current branch in git repo
    function parse_git_branch() {
    	BRANCH=`git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/\1/'`
    	if [ ! "${BRANCH}" == "" ]
    	then
    		STAT=`parse_git_dirty`
    		echo "[${BRANCH}${STAT}]"
    	else
    		echo ""
    	fi
    }
    # get current status of git repo
    function parse_git_dirty {
    	status=`git status 2>&1 | tee`
    	dirty=`echo -n "${status}" 2> /dev/null | grep "modified:" &> /dev/null; echo "$?"`
    	untracked=`echo -n "${status}" 2> /dev/null | grep "Untracked files" &> /dev/null; echo "$?"`
    	ahead=`echo -n "${status}" 2> /dev/null | grep "Your branch is ahead of" &> /dev/null; echo "$?"`
    	newfile=`echo -n "${status}" 2> /dev/null | grep "new file:" &> /dev/null; echo "$?"`
    	renamed=`echo -n "${status}" 2> /dev/null | grep "renamed:" &> /dev/null; echo "$?"`
    	deleted=`echo -n "${status}" 2> /dev/null | grep "deleted:" &> /dev/null; echo "$?"`
    	bits=''
    	if [ "${renamed}" == "0" ]; then
    		bits=">${bits}"
    	fi
    	if [ "${ahead}" == "0" ]; then
    		bits="*${bits}"
    	fi
    	if [ "${newfile}" == "0" ]; then
    		bits="+${bits}"
    	fi
    	if [ "${untracked}" == "0" ]; then
    		bits="?${bits}"
    	fi
    	if [ "${deleted}" == "0" ]; then
    		bits="x${bits}"
    	fi
    	if [ "${dirty}" == "0" ]; then
    		bits="!${bits}"
    	fi
    	if [ ! "${bits}" == "" ]; then
    		echo " ${bits}"
    	else
    		echo ""
    	fi
    }
    export PS1="\u@\h:\w-\`parse_git_branch\` "

Pornind un nou shell, vedem că promptul s-a schimbat, acum nu mai este colorat.
Când schimbăm directorul curent într-un repository Git, în prompt va apărea și branch-ul pe care este setată replica repository-ului

.. code-block::

    student@uso:~- cd uso-lab/
    student@uso:~/uso-lab-[master !?] check-language-support ^C

.. _task_admin_config_shell_prompt_ex:

Exercițiu: Configurarea promptului
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Se întâmplă ca atunci când lucrăm cu ierarhii de fișiere cu multe directoare, să nu încapă comenzile pe un singur rând.
Acest lucru este deranjant, deoarece comenzile devin greu de urmărit.

Pentru a rezolva această problemă, vrem să avem promptul pe un rând și spațiul unde introducem textul pe următorul rând.

Modificați promptul astfel încât comenzile rulate să apară pe următorul rând față de prompt.

.. _task_admin_config_apps:

Configurarea aplicațiilor de bază
---------------------------------

După ce am configurat mediul de lucru, vrem să configurăm și aplicațiile pe care le vom folosi.

.. _task_admin_config_git:

Configurarea Git
^^^^^^^^^^^^^^^^

.. _task_admin_config_vim:

Configurarea Vim
^^^^^^^^^^^^^^^^
