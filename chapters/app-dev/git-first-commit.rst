Primul commit
=============

Odată creat repository-ul, putem să începem să lucrăm la proiect.

De fiecare dată când facem o modificare vrem să salvăm starea proiectului print-un **commit**.
Același lucru îl fac și ceilalți colegi care lucrează la același proiect.
Fiecare commit referă o versiune a proiectului.
Git se ocupă de păstrarea istoricului repository-ului nostru prin păstrarea listei de commituri făcute.

Vrem să avem posibilitatea de a reveni la o versiune anterioară a codului sursă sau să putem verifica cine a făcut o anumită modificare, de aceea avem nevoie să salvăm stările intermediare ale proiectului la care lucrăm.

.. note::

    Ne amintim însă că scopul nostru este să lucrăm împreună la același proiect.

Crearea unui commit presupune actualizarea repository-ului **local**, nu și aceluia **remote**.
Fără a actualiza și repository-ul remote, ceilalți colegi nu vor putea vedea schimbările făcute de noi.
Spunem că publicăm modificările făcute în repository-ul local prin operația **push**.

Vom vedea în următoarele secțiuni care sunt pașii pentru a crea un commit și pentru a-l publica.

În următoarele secțiuni vom contribui la repository-ul creat în secțiunea anterioară (TODO adaugă ref).
Vom crea pas cu pas un proiect care conține mai mulți algoritmi de sortare al unui vector de elemente întregi.

Punctual, în această secțiune vom crea fișierul README al proiectului și scheletul de cod pentru algoritmii de sortare **Bubble Sort**, **Merge Sort** și **Radix Sort**.
Vom crea commituri pentru fiecare schimbare, după care vom publica commiturile astfel încât schimbările să fie vizibile și pe GitHub.

Adăugarea unui fișier README
----------------------------

.. admonition:: Reamintire

    Pe lângă codul sursă se recomandă adăugarea unui fișier (de obicei intitulat README) în care se află informații despre un proiect.
    Spre exemplu în README se află informații despre ce funcționalități are proiectul nostru, cum se compilează un proiect, cum se rulează, pe ce tip de platforme poate fi rulat etc.

Adăugăm un fișier README folosind următoarele comenzi:

.. code-block:: bash

    student@uso:~/my-first-repository$ echo "# Sorting Algorithms for Beginners" > README.md
    student@uso:~/my-first-repository$ ls -a
    ./         ../        .git/      README.md

.. note::

    Folosim extensia ``.md`` care semnalează un fișier de tip `Markdown <https://www.markdownguide.org>`_.
    Facem acest lucru deoarece pe GitHub fișierele README sunt afișate în format Markdown.
    Acest format este simplu de înțeles, însă nu face obiectul acestei cărți, deci nu vom insista pe înțelegerea lui.


Crearea primului commit
-----------------------

Prin **commituri** actualizăm istoricul unui repository.
Aceasta este modalitatea prin care propagăm modificărule făcute de noi în proiect.
Astfel, Git păstrează un istoric al modificărilor făcute.


Verificarea stării clonei
^^^^^^^^^^^^^^^^^^^^^^^^^

.. admonition:: **Clonare**

    O copie locală a unui repository deja existent pe GitHub se numește **clonă**.

    Operația **clone** realizează o copie locală a unui repository.
    Această copie poate fi acum actualizată după bunul plac.

Ne interesează întotdeauna starea clonei pe care lucrăm.
Prin **starea clonei** înțelegem forma la care am adus proiectul prin modificările noastre.
Aceasta include ce fișiere am creat, modificat sau șters de la ultima sincronizare cu repository-ul remote.

.. code-block:: bash

    student@uso:~/my-first-repository$ git status
    On branch master

    No commits yet

    Untracked files:
    (use "git add <file>..." to include in what will be committed)

        README.md

Pentru a verifica starea clonei folosim comanda ``git status``.


Prima linie afișată ``On branch master`` se referă la branch-ul master local.
Ne indică faptul că modificările făcute, adică crearea fișierelor ``README.md`` și ``.gitignore`` au fost făcute pe branch-ul master.

A doua linie afișată ``No commits yet`` se referă la faptul că nu am făcut până acum niciun commit, adică am pornit de la un repository gol.

În ultima parte a outputului se află o listă de fișiere ``untracked``, adică lista fișierelor pe care Git le vede ca nou adăugate în repository-ul curent, dar pe care nu le monitorizează încă.
Asta înseamnă că deocamdată orice modificare făcută asupra acestor fișiere nu va fi urmărită de Git.

.. note::

    Este datoria noastră de a adăuga fișierele în zona de lucru pentru Git.

Adăugarea unui fișier (în staging area)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Adăugăm fișierul **README.md** în zona de lucru pentru Git, adică în **staging area**.
În **staging area** adăugăm fișierele pe care le pregătim pentru un commit.

.. code-block:: bash

    student@uso:~/my-first-repository$ git add README.md
    student@uso:~/my-first-repository$ git status
    On branch master

    No commits yet

    Changes to be committed:
    (use "git rm --cached <file>..." to unstage)

        new file:   README.md

În urma adăugării în staging, comanda ``git status`` va produce un nou output. Haideți să-l interpretăm.

Primele 2 mesaje afișate au rămas neschimbate.
Partea interesantă apare la ultima parte a outputului.
Vedem că mesajul a devenit ``Changes to be commited``.
Asta înseamnă că acum Git știe de noile modificări și așteaptă ca modificările să fie adunate într-un commit.

Crearea commitului local cu un mesaj corespunzător
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Următorul pas în etapa de dezvoltare este chiar crearea unui nou commit cu modificările făcute.

.. code-block::

    student@uso:~/my-first-repository$ git commit -m "Add README file"
    [master (root-commit) 0dfb632] Add README.md
    1 file changed, 1 insertion(+)
    create mode 100644 README.md  
    student@uso:~/my-first-repository$ git status
    On branch master
    nothing to commit, working tree clean  

Am folosit descrierea ``Add README file`` drept **mesaj de commit**.
Aceasta este o descriere succintă a modificările făcute prin acest commit.

.. note:: 

    Mesajele de commit trebuie să fie punctuale și ușor de înțeles.
    Trebuie să ne asigurăm că altcineva care va vedea acest mesaj înțelege exact ce schimbări am adus proiectului prin acest commit.

Exerciții practice
""""""""""""""""""

#. Creați un nou fișier numit ``bubble-sort.c`` cu următorul conținut:

    .. code-block:: c

        #include <stdio.h>

        void sort() {
            // TODO: add bubble sort algorithm here
        }

        int main() {
            return 0;
        }

#. Comiteți schimbarea făcută. Folosiți următorul mesaj de commit: ``Add Bubble Sort algorithm skeleton``.

#. Creați un nou fișier numit ``bubble-sort.c`` cu următorul conținut:

    .. code-block:: c

        #include <stdio.h>

        void sort() {
            // TODO: add radix sort algorithm here
        }

        int main() {
            return 0;
        }

#. Comiteți schimbarea făcută. Folosiți următorul mesaj de commit: ``Add Radix Sort algorithm skeleton``.

#. Creați un nou fișier numit ``merge-sort.c`` cu următorul conținut:

    .. code-block:: c

        #include <stdio.h>

        void sort() {
            // TODO: add merge sort algorithm here
        }

        int main() {
            return 0;
        }

#. Comiteți schimbarea făcută. Folosiți următorul mesaj de commit: ``Add Merge Sort algorithm skeleton``.

#. Adăugați propoziția "We implement 3 sorting algorithms for integer arrays." pe a doua linie din fișierul ``README.md``.

#. Comiteți schimbarea făcută. Folosiți următorul mesaj de commit: ``Update README with project explanation``.

#. Modificați titlul fișierului ``README.md`` în ``# Sorting Algorithm for Integer Arrays``.

#. Comiteți schimbarea făcută. Folosiți următorul mesaj de commit: ``Update README title``.


Verificarea istoricului de commituri
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

La orice pas al dezvoltării proiectului vrem să știm în ce stadiu ne aflăm.
De aceea folosim un sistem de versionare a codului, în cazul nostru ``Git``.
Git ne permite să vedem un istoric al modificărilor făcute în repository, adică un istoric al commiturilor.

În cazul autorului acestui capitol, numele, prenumele și emailul sunt ``Liza Babu <lizababu@example.com>`` ca mai jos.
.. code-block::

    student@uso:~/my-first-repository$ git log
    commit 0dfb632b9de79f9a25011e8b98be48c7b1a0aad8 (HEAD -> master)
    Author: Liza Babu <lizababu@example.com>
    Date:   Wed Aug 19 17:24:01 2020 +0300

        Update README title
    TODO: adaugă restul de commituri
    (..)

.. note::

    Navigați prin outputul comenzii ``git log`` prin intermediul săgeților sus/jos.
    Apăsați tasta **q** când ați terminat de inspectat.

Pentru verificarea istoricului de commituri din repository am folosit comanda ``git log``.

Fiecare commit are un hash asociat care identifică unic commitul.
Discutăm în continuare despre ultimul commit din listă.
Acesta are hash-ul ``0dfb632b9de79f9a25011e8b98be48c7b1a0aad8`` și mesajul de commit ``Update README title``.

Acum vedem că repository-ul indică spre acest nou commit.
Ne dăm seama de acest lucru pentru că ``HEAD`` se află în dreptul commitului tocmai făcut.

Publicarea commitului pe repository-ul remote
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Vrem să publicăm toate schimbările făcute și pe repository-ul remote.

.. code-block::

    student@uso:~/my-first-repository$ git push origin master
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

Am publicat commitul folosind comanda ``git push origin master``.
Acum am publicat schimbări pe **branch-ul master**.
Vorbim despre **branch-uri** în secțiunea următoare (TODO adaugă ref la secțiunea următoare).

Întrăm pe GitHub să vedem că schimbările au fost propagate.

TODO: fă și adaugă screenshot nou

.. figure:: ./img/GitHub-first-commit.png
  :scale: 45%
  :alt: Alternative text


Bune practici
-------------

Există câteva bune practici de care trebuie să ținem întotdeauna cont.

E bine ca atunci când ne apucăm de lucru să avem în vedere să sincronizăm din când în când repository-ul local cu cel remote.
Pot apărea diferențe în momentul în care altcineva a publicat schimbări remote după ce am făcut noi ultima sincronizare.
În momentul în care cineva a publicat modificări asupra unei secvențe de cod pe care și noi o modificăm, apar conflicte.
Conflictele trebuie rezolvate.

Putem face acest lucru în două moduri.
Operația ``fetch`` are rolul de a aduce local toate schimbările, însă nu va face și operația de ``merge`` care presupune rezolvarea conflictelor și ajungerea a un front comun.
Operația ``pull`` face, de fapt, un ``fetch`` și un ``merge``, adică va aduce local toate modificările și va încerca să rezolve conflicetele în mod automat.
Dacă rezolvarea conflictelor nu se poate face automat, trebuie să ne ocupăm de acest pas.

.. note::
    Noi am pornit de la un repository gol, așadar operațiile ``fetch``, ``merge`` și ``pull`` nu au fost necesare.

TODO: de integrat următoarele unde își vor avea locul.
``git pull`` + explicații (de ce trebuie să dăm mai întâi pull și după aceea push)