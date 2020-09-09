Lucrul pe branch-uri
====================

TODO git rm, git mv
TODO git -A Q: de ce vrem să adăugăm selectiv și nu cu -A? A: vrem să facem commituri cât mai specifice, câte unul pt fiecare issue rezolvat. Nu vrem să avem mai multe modificări unrelated în aceelași commit pt că nu mai putem să facem revert ușor.
TODO git commit -m

.. admonition:: Problema

    Un colaborator al proiectului vrea să facă schimbări asupra codului sursă, acesta va trebui să facă aceste modificări față de o referință.
    În general, acesta va lua ultima versiune a codului sursă și va începe să facă modificări pe aceasta.

    Un alt colaborator dorește să facă o altă schimbare asupra codului sursă în același timp cu primul.
    La fel ca primul colaborator, acesta va lua ultima versiune a codului sursă și îl va modifica.

    Ambii colaboratori vor face câte un **commit** și un **push** pentru a propaga schimbările.

    Ce se întâmplă în momentul în care modificările celor 2 sunt contradictorii?
    
    Cum alegem care modificare este cea corectă?
    
    Cum alegem ce modificare vrem să păstrăm?

.. admonition:: Soluția

    Folosim branch-uri.
    Fiecare colaborator va crea un nou branch pentru fiecare schimbare pe care vrea să o aducă repository-ului.
    Astfel, atunci când unul dintre colaboratori termină de lucrat va putea integra schimbările în branch-ul master și să țină cont și de schimbările celorlalți.
    Dacă apar situații conflictuale, acestea se rezolvă.
    Vom atinge acest subiect în secțiunea TODO.


TODO: diagramă cu commit-uri pe branch-ul master.

Un **branch** este echivalentul unui fir de evoluție a codului sursă.
Ultima versiune al codului sursă se află uzual pe branch-ul numit **master**.

.. warning::

    Atunci când contribuim la un proiect putem să lucrăm fie branch-ul **master**, fie să creăm un al branch.
    Este considerat **BAD-PRACTICE** să lucrăm pe branch-ul **master** din mai multe motive:

    1. Pe branch-ul **master** se ține întotdeauna o versiune de cod funcțională.
    Astfel, lucrul pe acest branch ar însemna să facem commituri doar atunci când o funcționalitate este finalizată, altfel pe branch-ul **master** vom avea o bucată de cod neterminată care poate să afecteze întreg proiectul.
    
    2. Lucrul pe un singur branch nu se oferă posibilitatea de a da feedback pe schimbările făcute pe repository.
    Dacă nu avem posibilitatea să oferim feedback unui coleg prin intermediul GitHub, atunci vom avea nevoie să comunicăm pe un alt mediu observațiile noastre, iar ei vor trebui să creeze un nou commit pentru rezolvarea problemelor.
    Mult mai simplu este să se realizeze întreaga etapă de feedback, numită **code review** înainte ca schimbările să apară pe **master**.


În acest moment, pe repository-ul vostru aveți un singur branch - **master**.
În continuare vom lucra la proiectul nostru TODO(pune nume), dar vom face schimbări de pe alt branch-uri.

În această secțiune vom adăuga un fișier ``.gitignore`` proiectului, vom adăuga implementarea pentru agloritmul Bubble Sort și vom actualiza fișierul README corespunzător.


Adăugarea unui fișier .gitignore repository-ului
------------------------------------------------

De acum încolo, vom face toate modificările de pe un nou branch, diferit de branch-ul **master**.

.. code-block:: bash

    student@uso:~/my-first-repository$ git branch
    *  master
    student@uso:~/my-first-repository$ git checkout -b add-gitignore
    Switched to a new branch 'add-gitignore'
    student@uso:~/my-first-repository$ git branch
    * add-gitignore
    master

Folosind comanda ``git branch`` verificăm branch-ul pe care ne aflăm.
Observăm caracterul ``*`` în dreptul branch-ului curent.

Mai sus am creat un nou branch cu numele **add-gitignore**.
În acest moment branch-ul **add-gitignore** nu diferă de branch-ul **master**.
Când vom face schimbări, cele două branch-uri vor diverge.

.. note::

    Este **GOOD-PRACTICE** ca fiecare modificare făcută pe un repository să fie făcută pe un branch nou.
    Branch-ul trebuie să aibă un nume sugestiv ca ceilalți să poată înțelege rapid ce schimbări se fac pe el.

În general nu se recomandă publicarea executabilelor (programelor compilate) pe GitHub deoarece executabile sunt dependente de sistemul pe care au fost create.
Este bine ca în cazul proiectelor de pe GitHub să existe instrucțiuni despre cum se poate obține programul final pe propriu sistem pentru a evita astfel de probleme de compatibilitate.
Așadar, pentru a nu publica fișiere executabile, vrem ca ele să nu facă parte din commiturile noastre.
Pentru a fi siguri că anumite fișiere sunt ignorate, putem să le adăugăm într-un fișier ascuns numit ``.gitignore``.

.. code-block:: bash

    student@uso:~/my-first-repository$ touch .gitignore
    student@uso:~/my-first-repository$ ls -a
    ./          ../         .git/       .gitignore  bubble-sort.c   README.md

    student@uso:~/my-first-repository$ git status
    On branch add-gitignore
    Untracked files:
    (use "git add <file>..." to include in what will be committed)
        .gitignore

    nothing added to commit but untracked files present (use "git add" to track)

Aici vom trece, câte una pe fiecare linie, fișierele pe care nu vrem să le publicăm.
Momentan nu avem fișiere pe care vrem să le ignorăm, așa că am creat un fișier ``.gitignore`` gol.

**Exercițiu:** Creați un nou commit prin care să adăugați fișierul **.gitignore** la repository. Folosiți următorul mesaj de commit ``Add .gitignore file``.

.. hint::

    Puteți folosim opțiunea ``-m`` pentru ``git commit``.
    
    Spre exemplu comanda ``git commit -m "Add .gitignore file"`` va crea un nou commit cu mesajul ``Add .gitignore file``.


**Exercițiu:** Publicați commitul și pe GitHub.

**Exercițiu:** Verificați propagarea schimbărilor pe GitHub.

.. note::

    Orice operație trebuie să fie urmată de o operație de verficare.
    Spre exemplu, după crearea unui commit, verificăm **statusul clonei** și **istoricul de commituri**.

Operația **merge** dintre un branch secundar și master
------------------------------------------------------

În secțiunea anterioară (TODO adaugă ref) am adăugat un fișier **.gitignore** la repository.
Ne amintim că am făcut această operație de pe branch-ul **add-gitignore** și nu de pe **master**.

.. note::

    Ne amintim că este **BAD-PRACTICE** să facem modificări direct pe branch-ul **master**.

Vrem ca modificarea făcută de noi, în acest caz, crearea unui fișier **gitignore** să se regăsească și pe branch-ul master.
Facem acest lucru prin intermediul operației ``merge``.
Pentru a face acest lucru trebuie să ne situăm pe branch-ul **master**, adică pe branch-ul în care vrem să integrăm schimbările.

.. note::

    Putem face o operație de **merge** și între 2 branch-uri secundare, nu trebuie să facem neapărat o operație de merge cu branch-ul **master**.
    Aceasta situație nu face obiectul acestei cărți, așadar nu vom insista pe acest lucru.

.. code-block:: bash

    student@uso:~/my-first-repository$ git checkout master
    Switched to branch 'master'
    Your branch is up to date with 'origin/master'.
    student@uso:~/my-first-repository$ git pull --ff-only
    Already up to date.

Observăm că aici lipsește argumentul ``-b`` de la comanda ``git checkout`` deoarece branch-ul **master** deja există, nu este nevoie să-l creăm noi.

.. note:: 

    Trebuie să ne asigurăm că branch-ul **master** local este sincronizat cu cel remote.
    Facem acum operația **pull** menționată în secțiunea TODO.
    
    Este considerat **GOOD-PRACTICE** să folosim opțiunea ``--ff-only`` de fiecare dată când facem operația **pull**.
    Astfel Git se asigură că istoricul local corespunde cu cel remote.
    Foloșiți **Întotdeauna** opțiunea ``--ff-only``.


.. code-block:: bash 

    student@uso:~/my-first-repository$ git merge add-gitignore
    Merge made by the 'recursive' strategy.
    .gitignore | 0
    1 file changed, 0 insertions(+), 0 deletions(-)
    create mode 100644 .gitignore
    student@uso:~/my-first-repository$ git status
    On branch master
    Your branch is ahead of 'origin/master' by 2 commits.
    (use "git push" to publish your local commits)

    nothing to commit, working tree clean
    student@uso:~/my-first-repository$ git push
    Enumerating objects: 4, done.
    Counting objects: 100% (4/4), done.
    Delta compression using up to 4 threads
    Compressing objects: 100% (2/2), done.
    Writing objects: 100% (2/2), 296 bytes | 296.00 KiB/s, done.
    Total 2 (delta 0), reused 0 (delta 0), pack-reused 0
    To https://github.com/lizababu/my-second-repository
    5c982a1..1f553ab  master -> master

După ce branch-ul master este actualizat la zi, putem efectua operația **merge** cu branch-ul ``add-gitignore``.

Atunci când se va deschide editorul de text, pe prima linie veți găsi mesajul ``Merge branch 'add-gitignore' into master``.
Salvați fișierul.

După ce operația s-a finalizat, trebuie să publicăm schimbările.
Observăm mai sus că branch-ul **master** are două commituri în plus față de cel remote (**Your branch is ahead of 'origin/master' by 2 commits.**).
Publicăm commiturile locale.

Ștergerea unui branch
---------------------

După ce terminăm lucrul pe un branch, este bine să îl ștergem.
Orice nouă modificare pe care o vom face va fi diferită, numele branch-ului vechi nu va corespunde, așadar nu mai avem nevoie de el.
Facem acest lucru atât pe repository-ul local, cât și cel de pe GitHub.

.. code-block:: bash 

    student@uso:~/my-first-repository$ git branch
      add-gitignore
    * master
    student@uso:~/my-first-repository$ git branch -d add-gitignore
    Deleted branch my-new-branch (was 5de7231).
    student@uso:~/my-first-repository$ git push origin --delete add-gitignore
    To https://github.com/{username}/my-first-repository.git
    - [deleted]         add-gitignore
    student@uso:~/my-first-repository$ git branch
    * master

.. note::

    În locul ``{username}`` va apărea numele vostru de utilizator de pe GitHub.

    Spre exemplu, pentru autorul acestui capitol apare ``https://github.com/lizababu/my-first-repository.git``.

**Exercițiu:** Verificați că branch-ul nu mai există pe GitHub.