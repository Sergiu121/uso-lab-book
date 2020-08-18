Crearea unui Pull Request (PR) pe GitHub
========================================

În momentul în care vrem să adăugăm o funcționalitate nouă unui proiect software pe GitHub este recomandăm printr-un ``Pull Request``, uzual prescurtat ``PR``.
Un ``Pull Request`` este o cerere de modificare a repository-ului. Uzual, alți colaboratori ai proiectului vor recenza modificările și vor aproba, vor sugera schimbări sau vor respinge această cerere.
În momentul în care un Pull Request este aprobat, atunci schimbările propuse în Pull Request poate fi integrat în proiect, adică se va putea face merge între codul sursă curent și noile modificări.

Spunem că deschidem un Pull Request care urmează să fie integrat într-un anumit branch.
De obice acel branch este ``master``, însă acest lucru nu este obligatoriu.
În acest tutorial vom deschide un Pull Request care urmează să fie integrat în branch-ul ``master``.

Clonarea repository-ului
------------------------

În această secțiune vom crea un nou repository pe GitHub.
De data aceasta, vom clona local repository-ul de pe GitHub.

.. note:: Ne amintim faptul că în secțiunea introductivă am creat un repository pe GitHub și am inițializat unul local.
          Ulterior am conectat cele două repository-uri.
          De data aceasta vom clona repository-ul de pe GitHub, fără a fi nevoiți să facem pași în plus.

**Exercițiu:** Creați un nou repository pe contul vostru de GitHub intitulat ``my-second-repository``.
De data aceasta, vrem ca repository-ul să fie înițializat cu un fișier README.
Asigurați-vă că ați bifat checkbox-ul ``Initialize this repository with a README`` ca în imaginea de mai jos.

.. figure:: ./img/GitHub-initialize-README.png
  :scale: 45%
  :alt: Alternative text

.. note:: Așa cum este precizat și pe GitHub, inițializarea unui repository cu un fișier README permite ulterior clonarea repository-ului fără alți pași intermediari.
          
          De fapt, în momentul în care un repository este inițializat cu un fișier README, se face un prim commit pentru a adăuga acest fișier în repository.
          Primul commit duce la crearea banch-ului ``master``, așadar nu mai avem un repository gol.
          Mesajul primul commit este ``Initial commit``.

Vom clona acum repository-ul pe care tocmai l-am creat.
În acest tutorial vom clona repository-ul la calea ``/home/student``.
La terminarea clonării vom intra în directorul ce conține repository-ul.

.. code-block:: bash

    student@uso:~$ pwd
    /home/student
    student@uso:~$ git clone https://github.com/{username}/my-second-repository
    Cloning into 'my-second-repository'...
    remote: Enumerating objects: 3, done.
    remote: Counting objects: 100% (3/3), done.
    remote: Total 3 (delta 0), reused 0 (delta 0), pack-reused 0
    Unpacking objects: 100% (3/3), done.
    student@uso:~$ ls
    my-second-repository/   my-second-repository/
    student@uso:~$ cd my-second-repository/
    student@uso:~/my-second-repository$ ls
    README.md

.. note:: ``{username}`` este numele nostru de utilizator de pe GitHub.

**Exercițiu:** Verificați istoricul de commituri din acest repository.

Crearea unui branch nou
-----------------------

Pentru a putea deschide un Pull Request, trebuie să lucrăm pe un branch diferit dață de cel în care vrem să integrăm schimbările.
În acest caz, vom lucra pe un nou branch, diferit de branch-ul ``master``.

**Exercițiu:** Creați un branch numit ``awesome-feature-branch``.

**Exercițiu:** Verificați ce branch-uri există pe repository-ul curent.

**Exercițiu:** Asigurați-vă că sunteți pe branch-ul nou creat.

**Exercițiu:** Verificați istoricul de commituri din repository.

**Exercițiu:** Verificați statusul noului branch.

Crearea unui commit de pe branch-ul master
------------------------------------------

Înainte de a crea un Pull Request, vom face o modificare pe branch-ul ``master``.
Revenim pe branch-ul ``master`` folosind comanda de mai jos.

.. code-block:: bash

    student@uso:~/my-second-repository$ git checkout master
    Switched to branch 'master'
    Your branch is up to date with 'origin/master'.

**Exercițiu:** Modificați titlul fișierului README în ``# Very good title for a README``.

**Exercițiu:** Creați un commit cu modificarea făcută.

**Exercițiu:** Publicați commitul astfel încât acesta să fie vizibil și din interfața GitHub.

**Exercițiu:** Verificați din interfața grafică GitHub că s-au propagat modificările.


Crearea unui commit pe branch-ul nou creat
------------------------------------------

Revenim pe branch-ul ``awesome-feature-branch`` folosind comanda de mai jos.

.. code-block:: bash

    student@uso:~/my-second-repository$ git checkout master
    Switched to branch 'master'
    Your branch is up to date with 'origin/master'.

Acum putem face modificări asupra fișierului README din nou.
Putem adăuga fișiere și directoare noi.

**Exercițiu:** Modificați de pe acest branch titlul fișierului README în ``# Greatest titles of them all``.

**Exercițiu:** Creați o ierarhie de fișiere și directoare pornind din directorul curent.

.. note:: Dacă veți crea un director nou, însă acesta nu va conține niciun fișier, atunci în momentul în care veți face un commit, acest director va fi omis.

**Exercițiu:** Creați un commit pe acest branch cu noile schimbări.

**Exercițiu:** Publicați schimbările și pe GitHub.

.. hint:: Atenție! Branch-ul ``awesome-feature-branch`` nu există și pe GitHub.
          Urmăriți indicațiile primite la executarea comenzii ``git push``

Crearea Pull Requestului
------------------------

După publicarea schimbărilor anterioare, intrăm pe GitHub.
Vedem că ne apare că a fost creat un nou commit pe branch-ul ``awesome-feature-branch``.

.. figure:: ./img/GitHub-before-PR.png
  :scale: 45%
  :alt: Alternative text

Pentru a crea un Pull Request nou apăsăm pe butonul ``Compare & pull request``.
În acest moment s-a deschis o nouă pagină care arată că în imaginea de mai jos.

.. figure:: ./img/GitHub-create-PR.png
  :scale: 45%
  :alt: Alternative text

Explicăm semnificația celor mai importante componente prezente în imagine.

Descrierea Pull Requestului
^^^^^^^^^^^^^^^^^^^^^^^^^^^

În imaginea de mai jos vedem o parte a interfeței GitHub în care avem posibilitatea de a lăsa un comentariu în care să descriem (chiar și mai în detaliu decât într-un mesaj de commit) ce schimbări am făcut. 

.. figure:: ./img/GitHub-description.png
  :scale: 45%
  :alt: Alternative text

.. warning:: **NU** apăsați pe butonul ``Create pull request`` după ce rezolvați următorul exercițiu.

**Exercițiu:** Scrieți un comentariu în căsuța de text în care să descrieți ce modificări aduceți repository-ului prin acest PR. 

Configurarea branch-ului în care vom integra PR-ul
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Modificările pe care le-am făcut urmează a fi integrate într-un branch.
Uzual, branch-ul ``master`` este cel care conține codul sursă actualizat la zi, deci este branch-ul în care se integrează PR-urile.
Touși, este bine de știut că putem schimba acest branch prin apăsarea butonului ``base: master`` din imaginea de mai jos.
Vor fi afișate toate branch-urile din acest repository și vom putea alege în ce branch să integrăm PR-ul.

În acest tutorial vom folosi branch-ul ``master``.

.. figure:: ./img/GitHub-base-branch.png
  :scale: 45%
  :alt: Alternative text

Recenzii și recenzori
^^^^^^^^^^^^^^^^^^^^^

Motivul principal pentru introducerea PR-urilor este pentru a putea avea posibilitatea de a primi feedback pe modificările aduse.
Din interfața grafică GitHub putem adăuga recenzori care să dea feedback pe modificări.
Recenzorii fac parte din colaboratorii proiectului.

.. figure:: ./img/GitHub-review.png
  :scale: 45%
  :alt: Alternative text

Conflicte
^^^^^^^^^

În imaginea de mai jos vedem că GitHub ne anuță că acest PR nu va putea fi integrat automat în branch-ul ``master``.

.. figure:: ./img/GitHub-conflict-warning.png
  :scale: 45%
  :alt: Alternative text

Ca să înțelegem de ce conflictul nu poate fi rezolvat automat, ne uităm la următoarea diagramă.

TODO: diagramă cu cum arată acum branch-urile și commiturile

Cronologic vorbind, branch-ul ``master`` este primul care a fost creat.
La acel moment acesta conținea un README cu următorul conținut.

.. code-block::

    # my-second-repository
    My second repository

Imediat după a fost creat branch-ul ``awesome-feature-branch`` care la început a fost identic cu branch-ul ``master``.
Pe acest branch am făcut modificări, iar aceste schimbări au fost salvate pe branch-ul ``awesome-feature-branch``.

.. code-block::

    student@uso:~/my-second-repository$ git checkout awesome-feature-branch
    student@uso:~/my-second-repository$ cat README.md
    # Greatest titles of them all
    My second repository

Între timp, pe branch-ul ``master`` au fost făcute schimbări asupra aceluiași fișier ``README.md``.

.. code-block::

    student@uso:~/my-second-repository$ git checkout master
    student@uso:~/my-second-repository$ cat README.md
    # Greatest titles of them all
    # Very good title for a README
    My second repository

La acest moment, fișierul README de pe branch-ul ``master`` este diferit de fișierul README pe care l-am modificat de pe branch-ul ``awesome-feature-branch``.
Cu alte cuvinte, cele două branch-uri nu mai sunt sincronizate și astfel apar conflicte.
Dacă pe branch-ul ``master`` nu am fi făcut nicio schimbare, nu ar fi existat niciun conflict.


**Exercițiu:** cum că am înțeles componentele unui Pull Request, îl putem crea.
Apăsați pe butonul ``Create pull request``

Noi commituri pe același PR
---------------------------

Este important de reținut că dacă vrem să facem și mai multe modificări asupra PR-ului, este suficient să creăm noi commituri pe același branch, iar acestea vor fi automat adăugate la PR-ul nostru.
Putem crea commituri noi complet separate, iar acest lucru îl facem trecând prin pașii deja învățați, sau putem adăuga noi schimbări la **același commit**.
Pentru a face acest lucru folosim comanda ``git commit --amend``.
Când facem acest lucru se va deschide un fișier în Vim care conține pe prima linie mesajul de commit.
Dacă vrem să rămână același mesaj de commit ca înainte, închideți fișierul.

.. code-block:: bash

    student@uso:~/my-second-repository$ git checkout awesome-feature-branch
    student@uso:~/my-second-repository$ echo "Extra line" >> README.md
    student@uso:~/my-second-repository$ cat README.md
    # Greatest titles of them all
    My second repository
    Extra line
    student@uso:~/my-second-repository$
    On branch awesome-feature-branch
    Your branch is up to date with 'origin/awesome-feature-branch'.

    Changes not staged for commit:
    (use "git add <file>..." to update what will be committed)
    (use "git checkout -- <file>..." to discard changes in working directory)

        modified:   README.md

    no changes added to commit (use "git add" and/or "git commit -a")
    student@uso:~/my-second-repository$ git add README.md
    student@uso:~/my-second-repository$ git commit --amend
    (...)
    student@uso:~/my-second-repository$ git status
    On branch awesome-feature-branch
    Your branch and 'origin/awesome-feature-branch' have diverged,
    and have 1 and 1 different commits each, respectively.
    (use "git pull" to merge the remote branch into yours)

    nothing to commit, working tree clean
    student@uso:~/my-second-repository$ git push
    To https://github.com/{username}/my-second-repository
    ! [rejected]        awesome-feature-branch -> awesome-feature-branch (non-fast-forward)
    error: failed to push some refs to 'https://github.com/{username}/my-second-repository'
    hint: Updates were rejected because the tip of your current branch is behind
    hint: its remote counterpart. Integrate the remote changes (e.g.
    hint: 'git pull ...') before pushing again.
    hint: See the 'Note about fast-forwards' in 'git push --help' for details.

.. note:: {username} este numele nostru de utilizator de pe GitHub.

Observăm că nu putem publica commitul.
Acest lucru se întămplă deoarece commitul de pe GitHub nu mai corespunde cu commitul local.
Pentru a rezolva problema folosim opțiunea ``--force`` pentru comanda ``git push``.

.. code-block:: bash

    student@uso:~/my-second-repository$ git push --force
    Enumerating objects: 5, done.
    Counting objects: 100% (5/5), done.
    Delta compression using up to 4 threads
    Compressing objects: 100% (2/2), done.
    Writing objects: 100% (3/3), 324 bytes | 324.00 KiB/s, done.
    Total 3 (delta 0), reused 0 (delta 0)
    To https://github.com/{username}/my-second-repository
    + 5915f2b...47a3069 awesome-feature-branch -> awesome-feature-branch (forced update)

Inspectăm istoricul de commituri și vede că nu a fost creat un commit nou pentru această schimbare.

.. code-block:: bash

    student@uso:~/my-second-repository$ git log
    commit 47a30691437c77c00c54b65055083822472422c5 (HEAD -> awesome-feature-branch, origin/awesome-feature-branch)
    Author: Liza Babu <lizza.babu@gmail.com>
    Date:   Fri Aug 21 13:38:15 2020 +0300

        Change boring README title

    commit 55c3e08a49f34bdf53bfc9656e0870e3f27f6003
    Author: Liza Babu <lizza.babu@gmail.com>
    Date:   Fri Aug 21 12:18:07 2020 +0300

        Initial commit

.. note:: Dacă voiam să creăm un commit nou parte din același PR foloseam comanda ``git commit -m "<Mesajul intră aici>"`` după care dădeam comanda ``git push``.

Rezolvarea conflictelor și integrarea PR-ului
---------------------------------------------

În mod obișnuit, un PR nu se va integra imediat în branch-ul ``master``.
Recenzia acestuia poate dura mai mult timp.
Întrucât acum nu avem recenzori, putem integra acest PR imediat.

Trebuie să rezolvăm conflictele apărute.
Apăsăm pe butonul ``Resolve conflicts``.

.. figure:: ./img/GitHub-mark-as-resolved.png
  :scale: 45%
  :alt: Alternative text

La fel ca în cazul rezolvării conflictelor din linia de comandă, păstrăm în fișier conținutul pe care îl dorim.
Apăsăm pe butonul ``Mark as resolved``, după care pe butonul ``Commit merge``.

.. figure:: ./img/GitHub-resolve-conflicts.png
  :scale: 45%
  :alt: Alternative text

.. figure:: ./img/GitHub-commit-merge-button.png
  :scale: 45%
  :alt: Alternative text

Ultimul pas este să facem operația ``merge`` și să închidem PR-ul.
Avem trei posibilități prin care să efectuăm un ``merge`` din interfața web Github.

.. figure:: ./img/GitHub-merge.png
  :scale: 45%
  :alt: Alternative text

Varianta **Create a merge commit** va lua toate commiturile făcute în acest PR și le va adăuga pe branch-ul ``master``.

Varianta **Squash and merge** va comasa toate commiturile făcute în acest PR într-unul singur și îl va adăuga pe branch-ul ``master``.

Varianta **Rebase and merge** va lua toate commiturle făcute în acest PR și le va pune după restul commiturilor de pe branch-ul ``master``.

În acest tutorial vom folosi prima variantă.
Selectăm ``Create a merge commit`` și apăsăm butonul ``Merge pull request``, după care apăsăm pe butonul ``Confirm merge``.

Ștergerea branch-ului în urma integrării în branch-ul master
------------------------------------------------------------

Odată făcută operația ``merge``, putem șterge branch-ul pe care am lucrat apăsând pe butonul ``Delete branch``.

.. figure:: ./img/GitHub-delete-branch.png
  :scale: 45%
  :alt: Alternative text

Această operație va șterge branch-ul doar pe GitHub.
Trebuie să ștergem și branch-ul din repository-ul local.

**Exercițiu:** Ștergeți branch-ul și din repository-ul local.

**Exercițiu:** Verificați că rămâne un singur branch atât pe GitHub cât și local: branch-ul ``master``.
