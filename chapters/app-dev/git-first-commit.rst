Primul commit
=============

Odată creat repository-ul, putem să începem să aducem modificări asupra lui.
Atunci când vrem să salvăm (în Git, nu doar în editorul text) modificările făcute local spunem că facem un **commit**.
Starea proiectului se modifică local, fără acțiuni ulterioare aceasta nu va fi făcută publică.
Dacă starea proiectului nu se publică, atunci ceilalți colaboratori nu vor putea vedea modificările tale.
Pentru a putea publica o schimbare trebuie să faceți operația **push**.
Vom vedea în următoarele secțiuni care sunt pașii pentru a crea un commit și pentru a-l publica.

Branch-ul master
----------------

Un **branch** este echivalentul unui fir de evoluție a codului sursă.
Prin analogie, branch-ul ``master`` este firul principal de evoluție al codului sursă.
Cu alte cuvinte, uzual, branch-ul master este cel care va conține codul sursă la zi.

.. admonition:: Example

    Un colaborator al proiectului vrea să facă schimbări asupra codului sursă, acesta va trebui să facă aceste modificări față de o referință.
    În general, acesta va lua ultima versiune a codului sursă și va începe să facă modificări pe acesta.
    După cum am menționat mai devreme, ultima versiune se află pe branch-ul master.
    Așadar putem spune că acest colaborator **lucrează pe branch-ul master**.

    Un alt colaborator dorește să facă o altă schimbare asupra codului sursă în același timp cu primul.
    La fel ca primul colaborator, acesta va lua ultima versiune a codului sursă și îl va modifica.

    Ambii colaboratori vor face câte un **commit** și un **push** pe branch-ul **master** pentru a propaga schimbările.

    Ce se întâmplă în momentul în care modificările celor 2 sunt contradictorii?
    Cum alegem care modificare este cea corectă?
    Cum alegem ce modificare vrem să păstrăm?

În realitate, situația prezentată mai sus se rezolvă rapid.
Unul dintre colaboratori va publica schimbările la un moment ``T`` de timp.
În acel moment, branch-ul master este actualizat astfel încât cea mai nouă versiune de cod este cea modificată de cel care a efectuat primul un commit.
La momentul ``T+x``, celălalt colaborator publică și el schimbările sale și acum branch-ul master va referi codul sursă ce conține schimbările aduse de cel de-al doilea commit.
Practic, toate modificările aduse pe branch (în acest caz master) sunt ordonate cronologic.

TODO: diagramă cu commit-uri pe branch-ul master.

Problema este rezolvată, însă ce se întâmplă dacă al doilea commit nu este tocmai în regulă, iar primul da?
Avem nevoie de o modalitate de "a da timpul înapoi".
Din fericire, există o modalitate de a face asta, însă nu este foarte eficientă în cazul proiectelor cu mulți colaboratori care aduc multe schimbări.


Branch-uri secundare
^^^^^^^^^^^^^^^^^^^^

Pe lângă branch-ul master, pot exista mai multe branch-uri secundare.
Acestea ajută rezolvarea problemelor precum cea descrisă mai sus.
Se recomandă folosirea unui branch pentru fiecare modificare a codului în parte.
Astfel, în situația de mai sus, fiecare colaborator ar crea un nou branch (care inițial va fi identic cu cel master) și vor lucra în continuare pe acel fir de evoluție.
În momentul în care unul a terminat de lucrat, acesta poate publica modificările pe branch-ul său.
Astfel branch-ul master rămăne neatins.
În acest moment, codul sursă de pe branch-ul secundar poate fi revizuit și ulterior publicat în branch-ul master dacă se decide că totul este în regulă.
Vom vedea care sunt pașii pentru a face acest lucru într-o secțiune viitoare.

În terminal putem verifica rapid pe ce branch ne aflăm folosind comanda ``git branch``.
În acest moment comanda nu va arăta nimic pentru că nu am făcut niciun commit și deci, nu avem niciun fir de evoluție al codului sursă.
De aceea, în secțiunea anterioară am văzut că ``HEAD branch`` este unknown.

.. code-block:: bash

    student@uso:~/my-first-repository$ git branch
    student@uso:~/my-first-repository$


Adăugarea unui README și a unui fișier .gitignore
-------------------------------------------------

Am stabilit mai devreme că într-un repository se află întreg codul sursă al unui proiect.
Pe lângă codul sursă se recomandă adăugarea unui fișier (de obicei intitulat README) în care se află diverse informații despre un proiect.
Spre exemplu în README se află informații despre cum se compilează un proiect, cum se rulează, ce funcționalități are proiectul, pe ce tip de platforme poate fi rulat etc.

Haide să adăugăm proiectului nostru un fișier ``README.md``.
Folosim extensia ``.md`` care semnalează un fișier de tip Markdown.
Facem acest lucru deoarece pe GitHub fișierele README sunt afișate în format Markdown.

.. code-block:: bash

    student@uso:~/my-first-repository$ echo "# My first project ever" >> README.md
    student@uso:~/my-first-repository$ ls -a
    ./         ../        .git/      README.md


În general nu se recomandă publicarea executabilelor (programelor compilate) pe GitHub deoarece executabile sunt dependente de sistemul pe care au fost create.
Este bine ca în cazul proiectelor de pe GitHub să existe instrucțiuni despre cum se poate obține programul final pe propriu sistem pentru a evita astfel de probleme de compatibilitate.
Așadar, pentru a nu publica fișiere executabile, vrem ca ele să nu facă parte din commiturile noastre.
Pentru a fi siguri că anumite fișiere sunt ignorate, putem să le adăugăm într-un fișier numit ``.gitignore``.
Aici vom trece, câte una pe fiecare linie, fișierele pe care nu vrem să le publicăm.
Momentan nu avem fișiere pe care vrem să le ignorăm, așa că vom crea un fișier ``.gitignore`` gol.

.. code-block:: bash

    student@uso:~/my-first-repository$ touch .gitignore
    student@uso:~/my-first-repository$ ls -a
    ./          ../         .git/       .gitignore  README.md


Crearea primului commit
-----------------------

Verificarea stării clonei
^^^^^^^^^^^^^^^^^^^^^^^^^

Starea unei clone este dată de fapt de starea branch-ului pe care ați lucrat.
În cazul vostru este vorba de branch-ul master.
Pentru a verifica starea clonei folosiți comanda ``git status``.

.. code-block:: bash

    student@uso:~/my-first-repository$ git status
    On branch master

    No commits yet

    Untracked files:
    (use "git add <file>..." to include in what will be committed)

        .gitignore
        README.md

Prima linie afișată ``On branch master`` se referă la branch-ul master local.
Ne indică faptul că modificările făcute, adică crearea fișierelor ``README.md`` și ``.gitignore`` au fost făcute pe branch-ul master.

A doua linie afișată ``No commit yet`` se referă la faptul că nu am făcut până acum niciun comit, adică am pornit de la un repository gol.

În ultima parte a outputului vedem că se află o listă de fișiere ``untracked``, adică lista fișierelor pe care Git le vede ca modificate/nou adăugate, însă nu știe cum să le catalogheze.
Este datoria noastră de a adăuga fișierele în aria de vizibilitate pentru Git.

Adăugarea fișierelor (în staging)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Pentru a adăuga fișierele în ``staging``, adică pentru a le face vizibile pentru Git, folosim comanda ``git add``.
Avem două variante pentru a adăuga ambele fișiere.

Prima variantă presupune folosirea opțiunii ``-A`` care va pune în staging toate fișierele modificate (include fișierele deja existente modificate, fișierele nou create și fișierele șterse). 
Opțiunea ``.`` va ignora fișierele șterse, iar opțiunea ``-u`` va ignora fișierele nou create.

.. code-block:: bash

    student@uso:~/my-first-repository$ git add -A
    student@uso:~/my-first-repository$ 

A doua variantă presupunerea adăugării fișierelor individual.
Această variantă este de folos atunci când avem mai multe fișiere modificate, însă nu vrem să facem un commit decât cu o parte dintre ele.

.. code-block:: bash

    student@uso:~/my-first-repository$ git add .gitignore README.md
    student@uso:~/my-first-repository$

Ambele situații de mai sus produc, în acest caz același efect.
În urma stagingului, comanda ``git status`` va produce un nou output. Haideți să-l interpretăm.

.. code-block:: bash

    student@uso:~/my-first-repository$ git status
    On branch master

    No commits yet

    Changes to be committed:
    (use "git rm --cached <file>..." to unstage)

        new file:   .gitignore
        new file:   README.md

Primele 2 mesaje afișate au rămas neschimbate.
Partea interesantă apare la ultima parte a outputului.
Vedem că mesajul a devenit ``Changes to be commited``.
Asta înseamnă că acum Git știe de noile modificări și așteaptă ca modificările să fie adunate într-un commit.


Crearea commitului local cu un mesaj corespunzător
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Următorul pas în etapa de dezvoltare este chiar crearea unui nou commit cu modificările făcute.
Până atunci însă, există câteva bune practici de care ar trebui să țineți întotdeauna cont.

.. note::
    E bine ca atunci când ne apucăm de lucru să avem în vedere să sincronizăm din când în când repository-ul local cu cel remote.
    Pot apărea diferențe în momentul în care altcineva a publicat schimbări remote după ce am făcut noi ultima sincronizare.
    În momentul în care cineva a publicat modificări asupra unei secvențe de cod pe care și noi o modificăm, apar conflicte.
    Conflictele trebuie rezolvate.

Putem face acest lucru în două moduri.
Operația ``fetch`` are rolul de a aduce local toate schimbările, însă nu va face și operația de ``merge`` care presupune rezolvarea conflictelor și ajungerea a un front comun.
Operația ``pull`` face, de fapt, un ``fetch`` și un ``merge``, adică va aduce local toate modificările și va încerca să rezolve conflicetele în mod automat.
Dacă rezolvarea conflictelor nu se poate face automat, trebuie să ne ocupăm de acest pas.

.. note:: În acest moment repository-ul remote este gol, nu are niciun branch activ și niciun commit, iar operația de sincronizare nu își are rostul.
          Vom ține cont însă de acest aspect în secțiunile următoare.

Crearea unui commit nou se face prin intermediul comenzii ``git commit`` ca în exemplul de mai jos.

.. code-block::

    student@uso:~/my-first-repository$ git commit -m "Add README.md and .gitignore"
    [master (root-commit) 0dfb632] Add README.md and .gitignore
    2 files changed, 1 insertion(+)
    create mode 100644 .gitignore
    create mode 100644 README.md  
    student@uso:~/my-first-repository$ git status
    On branch master
    nothing to commit, working tree clean  

.. note:: Fiecare commit trebuie să vină cu un mesaj alăturat în care se explică pe scurt ce modificări aduce acesta.

TODO: de integrat următoarele unde își vor avea locul.
``git pull --ff-only`` la bune practici
``git pull`` + explicații (de ce trebuie să dăm mai întâi pull și după aceea push)

Verificarea istoricului de commituri
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Pentru verificarea istoricului de commituri din repository folosim comanda ``git log``.

.. code-block::

    student@uso:~/my-first-repository$ git log
    commit 0dfb632b9de79f9a25011e8b98be48c7b1a0aad8 (HEAD -> master)
    Author: Prenume Nume <adresa_de_email@email.com>
    Date:   Wed Aug 19 17:24:01 2020 +0300

        Add README.md and .gitignore

Fiecare commit are un hash asociat care identifică unic commitul.
Aici este vorba despre ``0dfb632b9de79f9a25011e8b98be48c7b1a0aad8``.
Acum vedem că repository-ul indică spre acest nou commit.
Ne dăm seama de acest lucru pentru că ``HEAD`` se află în dreptul commitului tocmai făcut.

Publicarea commitului pe repository-ul remote
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Vrem să publicăm noile schimbări și pe repository-ul remote.
Pentru a face acest lucru folosim comanda ``git push``.
Output-ul acestei comenzi ne indică faptul că în repository-ul remote nu avem niciun branch numit ``master``.
Remediem această situație folosind indicațiile din mesaj.
După ce am creat branch-ul master, îl putem identifica și din linia de comandă.

.. code-block::

    student@uso:~/my-first-repository$ git push
    fatal: The current branch master has no upstream branch.
    To push the current branch and set the remote as upstream, use

        git push --set-upstream origin master
    student@uso:~/my-first-repository$ git push --set-upstream origin master
    Enumerating objects: 4, done.
    Counting objects: 100% (4/4), done.
    Delta compression using up to 4 threads
    Compressing objects: 100% (2/2), done.
    Writing objects: 100% (4/4), 299 bytes | 299.00 KiB/s, done.
    Total 4 (delta 0), reused 0 (delta 0)
    To https://github.com/{username}/my-first-repository.git
    * [new branch]      master -> master
    Branch 'master' set up to track remote branch 'master' from 'origin'.
    student@uso:~/my-first-repository$ git branch
    * master

Întrăm pe GitHub să vedem că schimbările au fost propagate.

.. figure:: ./img/GitHub-first-commit.png
  :scale: 45%
  :alt: Alternative text