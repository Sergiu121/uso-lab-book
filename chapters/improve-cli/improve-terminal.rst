.. _improve_cli_improve_terminal:

Îmbunătățirea lucrului în linia de comandă
==========================================

Principalul atu al utilizării aplicațiilor în linie de comandă, și nu în mediul grafic, este viteza cu care rezolvăm anumite sarcini.
Această viteză este dată de posibilitatea de a combina utilitare în linia de comandă pentru a automatiza procese manuale, repetitive.
Întotdeauna ne dorim să fim mai rapizi și să automatizăm cât mai mult din sarcinile noastre, deoarece cu cât ne terminăm treaba mai repede, cu atât avem mai mult timp liber la dispoziție.

De regulă, cu cât petrecem mai mult timp cu mâna pe tastatură și mai puțin pe mouse, cu atât suntem mai rapizi.
Aliniate la această idee, aplicațiile ne pun la dispoziție scurtături pe care suntem încurajați să le folosim pentru a ne utiliza timpul mai eficient.

Scurtături în terminal
----------------------

Tab completion
^^^^^^^^^^^^^^

Funcția de **tab completion** este probabil una dintre cele mai utile funcții expuse de către terminal.
Prin simpla apăsare a tastei ``Tab`` în timp ce scriem numele unei comenzi, al unei opțiuni a unei comenzi sau calea către un director sau fișier, terminalul va completa în mod automat textul.
În cazul în care există mai multe opțiuni pentru auto-complete, prin dubla apăsare a tastei ``Tab`` ne va sugera opțiunile de auto-complete.

În imaginea de mai jos putem observa că pentru comanda ``cd D`` funcția de ``Tab`` completion a găsit mai multe opțiuni valide pentru auto-complete.
În astfel de scenarii, cu mai multe opțiuni valide, apăsarea tastei ``Tab`` o singură dată nu produce niciun rezultat; trebuie să apăsăm tasta ``Tab`` de două ori consecutiv pentru a genera afișarea opțiunilor de auto-complete.

.. code-block:: bash

    student@uso:~$ cd D
    Desktop/   Documents/ Downloads/
    student@uso:~$ cd D

Funcția de auto-complete este extrem de utilă și îmbunătățește semnificativ viteza cu care realizăm acțiuni în terminal.

Funcția este extrem de utilă atunci când lucrăm cu nume de fișiere, directoare și căi din sistem.
În loc să scriem manual o cale către un nume foarte lung, lăsăm tasta ``Tab`` să facă asta pentru noi.

Atunci când avem o eroare în comandă (am scris greșit o anumită parte din numele comenzii sau al fișierului, fișierul nu există, etc.), tasta ``Tab`` nu produce nici un rezultat.
Acesta este un alt motiv pentru care să folosim tasta ``Tab``.

Folosiți funcția de ``Tab`` completion cât mai des cu putință [#clear]_.

.. _improve_cli_history_nav:

Navigarea în istoricul unei comenzi
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Shellul implementează funcția de a reține istoricul comenzilor pe care le-am executat.
Pentru a vedea istoricul curent putem rula comanda ``history``.
Vom obține un rezultat asemănător cu cel de mai jos:

.. code-block:: bash

    student@uso:~$ history
    [...]
    21  ls
    22  cd sorting/
    23  ls -l
    24  ls
    25  cd
    26  ls ~/Desktop ~/Documents ~/Downloads
    27  ls ~/Desktop
    28  ls Desktop/todos.txt
    29  cp Desktop/todos.txt cp
    30  ls
    31  rm cp
    [...]

Ciclăm prin comenzile date anterior folosind combinația de taste ``Arrow Up`` sau ``Ctrl+p``, respectiv ``Arrow Down`` sau ``Ctrl+n``.

**Exercițiu**: Ciclați prin istoricul de comenzi folosind combinația de taste ``Ctrl+p``, respectiv ``Ctrl+n``.

Căutarea în istoricul comenzilor
""""""""""""""""""""""""""""""""

Terminalul ne pune la dispoziție un mod mai inteligent de a căuta în istoricul comenzilor prin combinația de taste ``Ctrl+r``, ordinea căutării fiind de la cea mai recentă comandă la cea mai veche.
Funcția este cunoscută sub numele de **history search**.

Pentru a porni căutarea, apăsați combinația de taste ``Ctrl+r`` și începeți să scrieți o parte din textul comenzii pe care o căutați, de exemplu ``cd``.

.. code-block:: bash

    (reverse-i-search)`cd': cd workspace/hello

De aici, avem următoarele opțiuni:

* Căutăm în continuare o comandă care conține șirul ``cd``, folosind combinația de taste ``Ctrl+r``
* Rulăm comanda pe care am găsit-o, folosind combinația de taste ``Ctrl+o``
* Anulăm căutarea comenzii și revenim la starea inițială, folosind combinația de taste ``Ctrl+g``

Căutarea este incrementală.
Adică se rafinează pe măsură ce tastăm un caracter.
Orice caracter apăsat rafinează căutarea.

.. note::

    Textul căutat se poate afla oriunde în interiorul comenzii; nu trebuie să fie primele litere din comandă.
    Pentru exemplul de mai sus, căutarea folosind textul ``work`` ar fi produs același rezultat

    .. code-block:: bash

        (reverse-i-search)`work': cd workspace/hello

Expandarea comenzilor anterioare
""""""""""""""""""""""""""""""""

Terminalul ne pune la dispoziție și alte moduri prin care putem reutiliza comenzile din istoric.

Atunci când rulăm comanda ``history``, ca în subsecțiunea :ref:`improve_cli_history_nav` , vedem că fiecare comandă din istoric este precedată de un număr:

.. code-block:: bash

    23  ls -l

Acest număr funcționează ca un index pe care îl putem folosi pentru a executa comanda care îi corespunde:

.. code-block:: bash

    student@uso:~$ !23
    ls -l
    total 60
    drwxr-xr-x  2 student student 4096 aug  6  2018 Desktop
    drwxr-xr-x  3 student student 4096 aug 20  2018 Documents
    drwxr-xr-x  2 student student 4096 aug 11 19:35 Downloads
    drwxr-xr-x  2 student student 4096 aug  6  2018 Music
    drwxr-xr-x  2 student student 4096 aug 11 21:08 Pictures
    drwxr-xr-x  2 student student 4096 aug  6  2018 Public
    drwxr-xr-x  2 student student 4096 aug  6  2018 Templates
    drwxr-xr-x  2 student student 4096 aug  6  2018 Videos
    -rw-r--r--  1 student student 8980 aug  6  2018 examples.desktop
    drwxr-xr-x 14 student student 4096 aug 20  2018 uso.git
    -rw-r--r--  1 student student 4827 aug 21  2018 vm-actions-log.txt
    drwxr-xr-x  3 student student 4096 aug 11 20:28 workspace

Observăm că ``!23`` a fost înlocuit (expandat, în abuz de limbaj) cu comanda ``ls -l`` care corespundea indexului **23**.

Un caz particular, foarte des folosit, este ``!!``, care se va înlocui textual cu ultima comandă executată:

.. code-block:: bash

    student@uso:~$ ls
    Desktop    Downloads  Pictures  Templates  examples.desktop  vm-actions-log.txt
    Documents  Music      Public    Videos     uso.git           workspace
    student@uso:~$ !! -l workspace
    ls -l workspace
    total 4
    drwxr-xr-x 2 student student 4096 aug 11 21:32 hello

În exemplul de mai sus observăm că ``!!`` a fost înlocuit cu ``ls`` în textul comenzii, pentru ca apoi să se execute comanda ``ls -l workspace``.
Sintaxa ``!!`` este echivalentă cu ``!-1``.

**Exercițiu**: Rulați trei comenzi din istoricul vostru folosind atât înlocuirea numerică (``!2``), cât și înlocuirea ultimei comenzi (``!!``).
Folosiți-vă de faptul că această înlocuire are loc înaintea executării comenzii pentru a adăuga argumente comenzilor, similar exemplului de mai sus.

Reutilizarea argumentelor comenzii anterioare
"""""""""""""""""""""""""""""""""""""""""""""""

Terminalul ne oferă și o sintaxă prin care avem posibilitatea de a reutiliza argumentele comenzii anterioare în corpul comenzii curente.
Acest lucru este util în reutilizarea argumentelor lungi sau complicate, pentru că evităm rescrierea lor.
Astfel nu doar că suntem mai rapizi, dar evităm și apariția unor probleme din categoria typourilor.

Executăm următorul șir de comenzi:

.. code-block:: bash

    student@uso:~$ touch a/very/long/path/that-you-dont-want-to-retype
    student@uso:~$ ls -l !$
    ls -l a/very/long/path/that-you-dont-want-to-retype

Observăm că șirul ``!$`` din comanda ``ls -l !$`` a fost înlocuit cu ultimul argument al comenzii, anterioare, ``touch``.

Executăm următoarele comenzi:

.. code-block:: bash

    student@uso:~$ ls ~/Desktop ~/Documents ~/Downloads
    student@uso:~$ ls -l !^

Observăm că șirul ``!^`` din comanda ``ls -l !^`` a fost înlocuit cu primul argument al comenzii, anterioare, ``~/Desktop``.

Exerciții
"""""""""

#. Afișați istoricul vostru de comenezi.
   Rulați a zecea comandă din istoric, folosind sintaxa ``!#num``.

#. Rulați comanda ``ls -lh``.
   Acum rulați comanda anterioară, folosind sintaxa ``!!``, cu argumentul ``~/Downloads``.

#. Navigați către directorul ``~/Downloads``, folosit ca argument în exercițiul anterior, folosind sintaxa ``!$``.

#. Navigați către directorul ``~/Downloads``, folosit ca argument în exercițiul anterior, folosind sintaxa ``!^``.

Navigarea în interiorul unei comenzi
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ne găsim des în situația în care căutăm o comandă în istoric folosind funcția de history search, modificăm un argument al comenzii și apoi o executăm.
Pentru navigarea în cadrul textului comenzii putem folosi ``Arrow Keys``, iar pentru ștergeri putem folosi tasta ``Backspace`` sau ``Del``.

Terminalul ne pune la dispoziție și o serie de scurtături cu ajutorul cărora putem face realiza aceeași acțiune mai rapid.
Dacă vreți să vă impresionați prietenii, acesta este un mod simplu, dar eficient, de a o face.

Pentru a naviga în istoricul de comenzi putem folosi combinațiile de taste:

* ``Ctrl+p`` - accesăm ultima comandă dată; prin apăsări succesive ciclăm prin istoricul de comenzi, de la ultima la prima comandă dată
* ``Ctrl+n`` - accesăm comenzile în sens invers față de ``Ctrl+p``, de la comanda actuală până la ultima comandă dată

Pentru a naviga în corpul textului putem folosi combinațiile de taste:

* ``Ctrl+a`` - mută cursorul la începutul liniei
* ``Ctrl+e`` - mută cursorul la sfârșitul liniei
* ``Ctrl+f`` - mută cursorul cu un caracter înainte
* ``Ctrl+b`` - mută cursorul cu un caracter înapoi
* ``Alt+f`` - mută cursorul cu un cuvânt înainte
* ``Alt+b`` - mută cursorul cu un cuvânt înapoi

Pentru a efectua ștergeri în corpul textului putem folosi combinațiile de taste:

* ``Ctrl+k`` - șterge tot textul de la cursor până la sfârșitul liniei
* ``Ctrl+u`` - șterge tot textul de la cursor până la începutul liniei
* ``Alt+d`` - șterge tot textul de la cursor până la sfârșitul cuvântului

.. tip::

    Textul șters este salvat într-un registru și poate fi folosit folosind combinația de taste ``Ctrl+y``.
    Funcționalitatea este similară cu procesul de **Cut** (``Ctrl+k``, ``Ctrl+u`` sau ``Alt+d``) și **Paste** (``Ctrl+y``).

Exerciții
"""""""""

Rulați comanda ``ls Documents/ Downloads/ Desktop/ Pictures/ Music/`` înainte de a vă apuca de exerciții.

#. Apăsați tasta ``Ctrl+p`` pentru a accesa comanda rulată anterior.

#. Plasați-vă la începutul comenzii folosind combinația de taste ``Ctrl+a``.

#. Plasați-vă la sfârșitul comenzii folosind combinația de taste ``Ctrl+e``.

#. Mergeți, cuvânt cu cuvânt, la începutul comenzii folosind combinația de taste ``Alt+b``.

#. Mergeți, cuvânt cu cuvânt, la sfârșitul comenzii folosind combinația de taste ``Alt+f``.

#. Rulați comanda ``ls Docuents/ Downlads/ Dektop/ Pitures/ Muic/``.

#. Apăsați tasta ``Ctrl+p`` pentru a accesa comanda rulată anterior.
   Corectați typourile (greșelile de scriere) din comanda anterioară.
   Folosiți combinațiile de taste ``Ctrl+f``, ``Ctrl+b`` pentru a deplasa cursorul în cadrul comenzii.

#. Apăsați tasta ``Ctrl+p`` pentru a accesa comanda rulată anterior (comanda corectată).
   Avansați până la începutul cuvântului ``Desktop/``.
   Ștergeți tot până la final folosind combinația de taste ``Ctrl+k``.
   Acum anulați comanda curentă apăsând combinația de taste ``Ctrl+c``.
   În acest moment, textul pe care l-ați șters folosind ``Ctrl+k`` (**Desktop/ Pictures/ Music/**) se află într-un buffer.
   O să rulați comanda ``ls`` pe textul din buffer.
   Scrieți comanda ``ls`` și apoi apăsați combinația de taste ``Ctrl+y``.
   Textul a fost scris din buffer în continuarea comenzii ``ls`` (scrisă de voi).

#. Rulați comanda ``ls Documents/ Downloads/ Desktop/ Pictures/ Music/``.
   Apăsați tasta ``Ctrl+p`` pentru a accesa comanda rulată anterior (comanda corectată).
   Avansați până la începutul cuvântului ``Pictures/``.
   Ștergeți cuvântul folosind combinația de taste ``Alt+d``.
   Acum anulați comanda curentă apăsând combinația de taste ``Ctrl+c``.
   În acest moment, textul pe care l-ați șters folosind ``Alt+d`` (**Pictures**) se află într-un buffer.
   O să rulați comanda ``ls`` pe textul din buffer.
   Scrieți comanda ``ls`` și apoi apăsați combinația de taste ``Ctrl+y``.
   Textul a fost scris din buffer în continuarea comenzii ``ls`` (scrisă de voi).

.. rubric:: Note de subsol

.. [#clear]

    Putem să ne găsim în situația în care ecranul terminalului nostru este plin cu rezultatele comenzilor rulate anterior sau cu opțiuni afișate de către auto-complete.
    Putem să curățăm ecranul folosind comanda ``clear``.
    O alternativă mai rapidă este să folosim combinația de taste ``Ctrl+l``.
    Aceasta va produce același rezultat (va curăța ecranul) și are avantajul că poate fi folosită în timp ce scriem deja o comandă.

