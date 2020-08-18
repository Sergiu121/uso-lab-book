Crearea unui nou commit
=======================

Repetarea pașilor anteriori
---------------------------

Crearea unui branch separat
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Vrem ca următoarele modificări pe care le facem să fie făcute pe un branch diferit, nu pe branch-ul master.
Pentru a crea un nou branch, folosim comanda ``git checkout``.
Opțiunea ``-b`` urmată de un nume pentru branch specifică faptul că trebuie creat un nou branch cu acel nume.

.. code-block:: bash

    student@uso:~/my-first-repository$ git branch
    * master
    student@uso:~/my-first-repository$ git checkout -b my-new-branch
    Switched to a new branch 'my-new-branch'
    student@uso:~/my-first-repository$ git branch
      master
    * my-new-branch

**Exercițiu:** Treceți înapoi pe branch-ul ``master``.
După ce dați comanda, verificați că sunteți într-adevăr sunteți pe branch-ul ``master``.

**Exercițiu:** Reveniți pe branch-ul nou creat.

Modificarea fișierului README
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Vom modifica fișierul README.
Adăugăm o linie la sfârșitul fișierului ``README.md``.
Verificăm starea clonei folosind comanda ``git status``.

.. code-block:: bash

    student@uso:~/my-first-repository$ echo "This line was added through a second branch" >> README.md
    student@uso:~/my-first-repository$ cat README.md
    # My first project ever
    This line was added through a second branch
    student@uso:~/my-first-repository$ git status
    On branch my-new-branch
    Changes not staged for commit:
    (use "git add <file>..." to update what will be committed)
    (use "git checkout -- <file>..." to discard changes in working directory)

        modified:   README.md

    no changes added to commit (use "git add" and/or "git commit -a")

.. note:: Observați că outputul comenzii ``git status`` arată faptul că modificările aduse au fost făcute într-adevăr pe branch-ul nou creat.

**Exercițiu:** Adăugați o nouă linie în fișierul README.md. Puteți folosi orice editor de text doriți.


Revenirea la alt branch fără crearea unui nou commit cu schimbărilor curente
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Mai devreme am modificat un fișier din repository, iar acum vrem să ajungem din nou pe branch-ul ``master`` fără să propagăm noile schimbări.
Dacă vom încerca să schimbăm direct branch-ul pe care lucrăm ca mai devreme folosind comanda ``git checkout`` vedem că outputul ne semnalează ceva diferit.

.. code-block:: bash

    student@uso:~/my-first-repository$ git checkout master
    M	README.md
    Switched to branch 'master'
    Your branch is up to date with 'origin/master'.

.. note:: Observăm că prima linie afișată în urma rulării comenzii ``git checkout master`` indică faptul că fișierul ``README.md`` a fost modificat (``M``).

În mod obișnuit, nu vrem să apară astfel de situații întrucât schimbarea branch-ului se face de obicei când vrem să lucrăm la altă parte a proiectului, fără să ținem cont de modificările făcute pe alt branch.

Reveniți pe branch-ul creat de voi folosind comanda ``git checkout my-new-branch``.

.. code-block:: bash

    student@uso:~/my-first-repository$ git checkout my-new-branch
    Switched to branch 'my-new-branch'

.. note:: Acum branch-ul ``master`` a revenit la starea anterioară (adică nu conține modificările făcute asupra fișierului README), iar branch-ul ``my-new-branch`` conține aceste modificări.

Pentru a evita astfel de probleme folosim o nouă funcționalitatea a utilitarului Git numită ``stash``.
Git are posibilitatea de a păstra o stivă de modificări făcute de către utilizator fără ca acesta să creeze un nou commit.
Fiecare comandă ``git stash`` adaugă în stivă o nouă stare a clonei, iar branch-ul apare ca fiind nealterat.
Astfel, putem să schimbăm branch-ul pe care lucrăm fără să ducem modificările de pe un branch pe altul.

Pentru a putea păstra starea fișierelor modificate, acestea trebuie să fie vizibile de către Git, adică să fie ``staged``.
Fișierele care sunt ``untracked`` nu pot fi salvate în acest fel.
Facem fișierul README vizibil pentru Git.

.. code-block:: bash

    student@uso:~/my-first-repository$ git status
    On branch my-new-branch
    Changes not staged for commit:
    (use "git add <file>..." to update what will be committed)
    (use "git checkout -- <file>..." to discard changes in working directory)

        modified:   README.md

    no changes added to commit (use "git add" and/or "git commit -a")
    student@uso:~/my-first-repository$ git add README.md
    student@uso:~/my-first-repository$ git status
    On branch my-new-branch
    Changes to be committed:
    (use "git reset HEAD <file>..." to unstage)

        modified:   README.md

Acum fișierul README.md este vizibil pentru Git, așadar poate fi păstrat în stiva de modificări.
Folosim comanda ``git stash`` pentru a salva starea fișierului.

.. code-block:: bash

    student@uso:~/my-first-repository$ git stash
    Saved working directory and index state WIP on my-new-branch: 0dfb632 Add README.md and .gitignore

.. note:: Comanda ``git stash`` nu primește ca argument numele unui fișier care să fie păstrat în stivă, ci va păstra la aceeași intrare în stivă toate modificările care sunt vizibile pentru Git la momentul rulării comenzii.

Vizualizăm conținutul stivei de modificări folosind opțiunea ``list`` a comenzii ``git stash``.

.. code-block:: bash

    student@uso:~/my-first-repository$ git stash list
    stash@{0}: WIP on my-new-branch: 0dfb632 Add README.md and .gitignore

Putem verifica ce fișiere sunt modificate din starea salvată vârful stivei folosind opțiunea ``show`` pentru ``git stash``.
Fără nicio altă opțiune, aceasta ne arată câte linii diferă, sunt adăugate și/sau șterse în versiunea salvată față de versiunea curentă.
Pentru a vedea și care sunt acele linii adăugăm opțiunea ``-p`` la această comandă.

.. code-block:: bash

    student@uso:~/my-first-repository$ git stash show
    README.md | 2 ++
    1 file changed, 2 insertions(+)
    student@uso:~/my-first-repository$ git stash show -p
    diff --git a/README.md b/README.md
    index cfc5253..31d5f20 100644
    --- a/README.md
    +++ b/README.md
    @@ -1 +1,3 @@
    # My first project ever
    +This line was added through a second branch
    +This line is also added through a second branch

**Exercițiu:** Verificați starea clonei curente.
Dacă nu apare nicio modificare făcută, atunci puteți să treceți pe branch-ul master.
Dacă apare vreun fișier ca fiind modificați, reluați pașii de mai sus până să schimbați branch-ul de lucru.


Crearea unui al doilea commit pe branch-ul master
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Vrem să creăm un al doilea commit pe branch-ul master.

**Exercițiu:** Modificați titlul fișierului ``README.md`` în ``# My first REAL project ever``.

Verificăm starea clonei după ce facem modificarea titlului.

.. code-block:: bash

    student@uso:~/my-first-repository$ git status
    On branch master
    Your branch is up to date with 'origin/master'.

    Changes not staged for commit:
    (use "git add <file>..." to update what will be committed)
    (use "git checkout -- <file>..." to discard changes in working directory)

        modified:   README.md

    no changes added to commit (use "git add" and/or "git commit -a")

**Exercițiu:** Urmați pașii prezentați anterior pentru a crea un nou commit cu noile modificări.
Țineți cont de bunile practici legate de alegerea mesajului de commit corespunzător.

**Exercițiu:** Publicați commitul și pe repository-ul remote și verificați că acest lucru s-a reflectat și pe GitHub.

Revenirea la branch-ul cu modificări și crearea unui nou commit
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Revenim pe branch-ul secundar creat la începutul acestei secțiuni.

.. code-block:: bash

    student@uso:~/my-first-repository$ git checkout my-new-branch
    Switched to branch 'my-new-branch'

Ne amintim de la subsecțiunile anterioare că am salvat modificările aduse asupra fișierului README.md în stivă.
Așadar, acum la verificarea statusului pare că nu a fost facută de fapt nicio modificare pe acest branch.
Verificăm și stiva de modificări pentru a vedea că schimbările au rămas salvate.

.. code-block:: bash

    student@uso:~/my-first-repository$ git status
    On branch my-new-branch
    nothing to commit, working tree clean
    student@uso:~/my-first-repository$ git stash show -p
    diff --git a/README.md b/README.md
    index cfc5253..31d5f20 100644
    --- a/README.md
    +++ b/README.md
    @@ -1 +1,3 @@
    # My first project ever
    +This line was added through a second branch
    +This line is also added through a second branch

Pentru a reveni la starea repository-ului de dinainte trebuie să aplicăm modificările salvate în stivă pe starea curentă.
Cu alte cuvinte, trebuie să facem operația inversă lui ``git stash`` pentru a scoate modificările din stivă și reveni la starea de dinainte de operația ``stash``.
Facem acest lucru folosind opțiunea ``pop`` a comenzii ``git stash``.

.. code-block:: bash

    student@uso:~/my-first-repository$ git stash pop
    On branch my-new-branch
    Changes not staged for commit:
    (use "git add <file>..." to update what will be committed)
    (use "git checkout -- <file>..." to discard changes in working directory)

        modified:   README.md

    no changes added to commit (use "git add" and/or "git commit -a")
    Dropped refs/stash@{0} (be347fc63e79ece56759fda9b617f03e12b9b93b)
    student@uso:~/my-first-repository$ git stash list
    student@uso:~/my-first-repository$ git stash show
    No stash entries found.

Observăm că operația ``pop`` are ca rezultat scoaterea ultimei intrări din stivă (adică cea din vârf) și revenirea la starea anterioara operației ``stash``. 
În acest moment stiva de modificări s-a golit.

.. note:: Observăm faptul că fișierul readus la starea anterioară nu se află în starea ``staged``.

.. note:: Comanda ``git stash list`` nu produce niciun output dacă stiva este goală.

Git oferă și posibilitatea de a nu scoate din vârful stivei starea salvată, dar totuși starea branch-ului să revină la forma în care se afla înainte de operația ``stash``.
Acest lucru se poate face folosind opțiunea ``apply`` a comenzii ``git stash``.

**Exercițiu:** Faceți o nouă modificare asupra fișierului ``README.md``.

**Exercițiu:** Treceți fișierul ``README.md`` în starea ``staged``.

**Exercițiu:** Folosind comanda ``git stash`` salvați starea curentă a clonei.

În acest moment stiva de modificări ar trebui să conțină o singură intrare.
Folosim opțiunea ``apply`` pentru a readuce branch-ul la starea anterioară și a menține stiva cu o singură intrare care referă această schimbare.

.. code-block:: bash

    student@uso:~/my-first-repository$ git stash list
    stash@{0}: WIP on my-new-branch: 0dfb632 Add README.md and .gitignore
    student@uso:~/my-first-repository$ git stash apply
    On branch my-new-branch
    Changes not staged for commit:
    (use "git add <file>..." to update what will be committed)
    (use "git checkout -- <file>..." to discard changes in working directory)

        modified:   README.md

    no changes added to commit (use "git add" and/or "git commit -a")
    student@uso:~/my-first-repository$ git stash list
    stash@{0}: WIP on my-new-branch: 0dfb632 Add README.md and .gitignore

În stivă se pot afla mai multe intrări simultan, iar noi nu suntem limitați la a reveni la starea aflată în vârful stivei în momentul în care executăm operația ``pop``.

**Exercițiu:** Creați un nou fișier numit ``FakeREADME.md`` care să fie identic cu fișierul ``README.md``.

În acest moment stiva de modificări ar trebui să conțină o singură intrare, iar repository-ul conține 2 fișiere README și unul ``.gitignore``.
Facem ambele fișiere README vizibile pentru Git folosind comanda ``git add``, după care salvăm starea clonei folosind comanda ``git stash``.

.. code-block:: bash

    student@uso:~/my-first-repository$ git stash list
    stash@{0}: WIP on my-new-branch: 0dfb632 Add README.md and .gitignore
    student@uso:~/my-first-repository$ git status
    On branch my-new-branch
    Changes not staged for commit:
    (use "git add <file>..." to update what will be committed)
    (use "git checkout -- <file>..." to discard changes in working directory)

        modified:   README.md

    Untracked files:
    (use "git add <file>..." to include in what will be committed)

        FakeREADME.md

    no changes added to commit (use "git add" and/or "git commit -a")
    student@uso:~/my-first-repository$ git add -A
    On branch my-new-branch
    Changes to be committed:
    (use "git reset HEAD <file>..." to unstage)

        new file:   FakeREADME.md
        modified:   README.md
    
    student@uso:~/my-first-repository$ git stash
    Saved working directory and index state WIP on my-new-branch: 0dfb632 Add README.md and .gitignore

În acest moment în stivă se află 2 intrări, una de mai devreme (pe care doar am aplicat-o) și cea de acum.

.. code-block:: bash

    student@uso:~/my-first-repository$ git stash list
    stash@{0}: WIP on my-new-branch: 0dfb632 Add README.md and .gitignore
    stash@{1}: WIP on my-new-branch: 0dfb632 Add README.md and .gitignore

.. note:: Fiecare intrare în stivă are un index asociat, 0 fiind cea mai recentă intrare.

**Exercițiu:** Inspectați ambele intrări folosind comanda ``git stash show -p``.

.. hint:: O intrare în stivă se referă prin construcția ``stash@{N}``, unde ``N`` este indexul ei în stivă.
          Așadar, pentru intrarea ``stash@{1}`` va trebui să adăugați argumentul ``stash@{1}`` comenzii ``git stash show -p``.

Vrem să revenim la starea indicată de ``stash@{1}``, adică cea care conține un singur fișier README.
Putem face acest lucru folosind opțiunea ``pop`` a comenzii ``git stash``.

.. code-block:: bash

    student@uso:~/my-first-repository$ git stash pop stash@{1}
    On branch my-new-branch
    Changes not staged for commit:
    (use "git add <file>..." to update what will be committed)
    (use "git checkout -- <file>..." to discard changes in working directory)

        modified:   README.md

    no changes added to commit (use "git add" and/or "git commit -a")
    Dropped stash@{1} (972b398a58501c742a349e7eb8a26a5e5c16a892)
    student@uso:~/my-first-repository$ git stash list
    stash@{0}: WIP on my-new-branch: 0dfb632 Add README.md and .gitignore
    student@uso:~/my-first-repository$ ls -a
    ./          ../         .git/       .gitignore  README.md

Am ajuns acum la starea clonei dorită.
Eliminăm acum din stiva de modificări intrarea rămasă (adică cea care conține un al doilea README).

.. code-block:: bash

    student@uso:~/my-first-repository$ git stash list
    stash@{0}: WIP on my-new-branch: 0dfb632 Add README.md and .gitignore
    student@uso:~/my-first-repository$ git stash list
    student@uso:~/my-first-repository$ git stash clear

.. note:: În acest moment stiva este goală și starea repository-ului a revenit la forma dorită.

**Exercițiu:** Creați un commit cu modificările aduse asupra fișierului ``README.md``.
Aveți grijă să îl creați pe branch-ul creat de voi (și nu pe branch-ul ``master``).
Țineți cont de bunile practici legate de alegerea mesajului de commit.
Verificați că noul commit a fost făcut folosind comanda ``git log``.

**Exercițiu:** Publicați pe GitHub noul commit.
Verificați că schimbările sunt vizibile și din interfața grafică.

.. hint:: Branch-ul creat de voi nu există și remote.
          Urmăriți indicațiile utilitarului Git la executarea comenzii ``git push``.

Putem vizualiza branch-urile de pe GitHub din interfața grafică apăsând pe butonul indicat în imagine.

.. figure:: ./img/GitHub-branches.png
  :scale: 45%
  :alt: Alternative text

Modificarea mesajului de commit
-------------------------------

Putem schimba mesajele de commit pentru orice commit făcut, fie că a fost sau nu publicat pe GitHub, fie care este ultimul creat sau nu.

Ultimul commit nepublicat
^^^^^^^^^^^^^^^^^^^^^^^^^

**Exercițiu:** Creați un fișier nou denumit ``error-file.txt``.
Creați un nou commit cu mesajul ``Add eror-file.txt``.
**NU** publicați commitul pe GitHub.

În acest moment ne aflăm în situația în care avem un commit local care nu a fost publicat.
Acesta este ultimul commit și vrem să modificăm mesajul asociat.

.. code-block:: bash

    student@uso:~/my-first-repository$ git log
    commit 196c3061f84c728febbadf03d5ec97d498ef6e3e (HEAD -> my-new-branch)
    Author: Prenume Nume <adresa_de_email@email.com>
    Date:   Thu Aug 20 01:02:40 2020 +0300

        Add eror-file.txt

    commit 4b9ba014d71c020fbb19e0d7240cbe5bd13fe20e (origin/my-new-branch)
    Author: Prenume Nume <adresa_de_email@email.com>
    Date:   Thu Aug 20 00:00:25 2020 +0300

        Update README.md

    commit 0dfb632b9de79f9a25011e8b98be48c7b1a0aad8
    Author: Prenume Nume <adresa_de_email@email.com>
    Date:   Wed Aug 19 17:24:01 2020 +0300

        Add README.md and .gitignore

Rezolvăm această problemă folosind opțiunea ``--amend`` pentru ``git commit``.
La executarea comenzii se va deschire un fișier care conține pe prima linie mesajul de commit ``Add eror-file.txt``.
Modificăm aceasta linie cu mesajul potrivit, după care salvăm fișierul.

.. note:: Editorul text prestabilit este `Vim <https://www.vim.org>`_.
          Pentru a modifica textul apăsați mai întâi tasta ``i``, faceți modificările necesare, după care apăsați ``Esc+w+q`` și apăsați tasta enter.
          Pentru a schimba setarea implicită urmați tutorialul de `aici <https://help.github.jp/enterprise/2.11/user/articles/associating-text-editors-with-git/>`_.

.. code-block:: bash

    student@uso:~/my-first-repository$ git commit --amend

.. code-block:: bash

    Add error-file.txt

    # Please enter the commit message for your changes. Lines starting
    # with '#' will be ignored, and an empty message aborts the commit.
    #
    # Date:      Thu Aug 20 01:02:40 2020 +0300
    #
    # On branch my-new-branch
    # Your branch is ahead of 'origin/my-new-branch' by 1 commit.
    #   (use "git push" to publish your local commits)
    #
    # Changes to be committed:
    #       new file:   error-file.txt
    #

.. code-block:: bash

    student@uso:~/my-first-repository$ git log
    commit 196c3061f84c728febbadf03d5ec97d498ef6e3e (HEAD -> my-new-branch)
    Author: Prenume Nume <adresa_de_email@email.com>
    Date:   Thu Aug 20 01:02:40 2020 +0300

        Add error-file.txt

    commit 4b9ba014d71c020fbb19e0d7240cbe5bd13fe20e (origin/my-new-branch)
    Author: Prenume Nume <adresa_de_email@email.com>
    Date:   Thu Aug 20 00:00:25 2020 +0300

        Update README.md

    commit 0dfb632b9de79f9a25011e8b98be48c7b1a0aad8
    Author: Prenume Nume <adresa_de_email@email.com>
    Date:   Wed Aug 19 17:24:01 2020 +0300

        Add README.md and .gitignore

Acum commitul are mesajul de commit asociat corect.

**Exercițiu:** Publicați commitul pentru a trece la următoarea subsecțiune.

Ultimul commit publicat
^^^^^^^^^^^^^^^^^^^^^^^

În acest moment singura diferență față de exemplul anterior este faptul că avem un commit local care a fost și publicat și vrem să îi schimbăm mesajul de commit.
Repetăm toți pașii de mai devreme.

**Exercițiu:** Modificați mesajul ultimului commit din ``Add error-file.txt`` în ``Add error-file.txt 2``.

Pentru a publica noua schimbare trebuie să folosim comanda ``git push``.

.. code-block:: bash

    student@uso:~/my-first-repository$ git push
    To https://github.com/lizababu/my-first-repository.git
    ! [rejected]        my-new-branch -> my-new-branch (non-fast-forward)
    error: failed to push some refs to 'https://github.com/lizababu/my-first-repository.git'
    hint: Updates were rejected because the tip of your current branch is behind
    hint: its remote counterpart. Integrate the remote changes (e.g.
    hint: 'git pull ...') before pushing again.
    hint: See the 'Note about fast-forwards' in 'git push --help' for details.

.. warning:: Acest mesaj apare din cauza faptului că modificările locale (în acest caz mesajul de commit) nu corespund cu ceea ce se află remote.

Puteam sesiza o problemă și din outputul comenzii ``git status``: ``Your branch and 'origin/my-new-branch' have diverged, and have 1 and 1 different commits each, respectively.``.

.. code-block:: bash

    student@uso:~/my-first-repository$ git status
    On branch my-new-branch
    Your branch and 'origin/my-new-branch' have diverged,
    and have 1 and 1 different commits each, respectively.
    (use "git pull" to merge the remote branch into yours)

    nothing to commit, working tree clean

Pentru a depăși această situație, folosim opțiunea ``--force`` a lui ``git push``.

.. code-block:: bash

    student@uso:~/my-first-repository$ git push --force
    Enumerating objects: 3, done.
    Counting objects: 100% (3/3), done.
    Delta compression using up to 4 threads
    Compressing objects: 100% (2/2), done.
    Writing objects: 100% (2/2), 302 bytes | 302.00 KiB/s, done.
    Total 2 (delta 0), reused 0 (delta 0)
    To https://github.com/{username}/my-first-repository.git
    + 57f911f...483f1a1 my-new-branch -> my-new-branch (forced update)

.. note:: {username} este numele nostru de utilizator de pe GitHub.

.. warning:: Nu se recomandă folosirea opțiunii ``--force`` decât dacă suntem siguri că modificările pe care le facem aduc un beneficiu repository-ului.
             De asemenea, nu este recomandat să folosim această opțiune pe un branch care nu ne aparține.
             Implicit pe branch-ul ``master`` se preferă **evitarea folosirii** acestei opțiuni.

Orice alt commit
^^^^^^^^^^^^^^^^

.. note:: Indiferent dacă ultimele N commit-uri sunt sau nu publicate, pașii de schimbare a mesajului de commit sunt comuni.

În acest moment, outputul comenzii ``git log`` ne arată că avem 3 commit-uri, toate publicate.
Vrem să modificăm mesajul de commit al celui de-al doilea commit.

.. code-block:: bash

    student@uso:~/my-first-repository$ git log
    commit 483f1a1b41c609248d2c15dd9a27ada706be15ef (HEAD -> my-new-branch, origin/my-new-branch)
    Author: Prenume Nume <adresa_de_email@email.com>
    Date:   Thu Aug 20 01:02:40 2020 +0300

        Add error-file.txt 2

    commit 4b9ba014d71c020fbb19e0d7240cbe5bd13fe20e
    Author: Prenume Nume <adresa_de_email@email.com>
    Date:   Thu Aug 20 00:00:25 2020 +0300

        Update README.md

    commit 0dfb632b9de79f9a25011e8b98be48c7b1a0aad8
    Author: Prenume Nume <adresa_de_email@email.com>
    Date:   Wed Aug 19 17:24:01 2020 +0300

        Add README.md and .gitignore

Numărând de la cel mai recent la cel mai vechi, vedem că al doilea commit este cel cu mesajul ``Update README.md``.
Vrem să modificăm acest mesaj în ``Update README.md 2``
Astfel, folosit comanda ``git rebase`` putem să ne situăm, în timp, în momentul în care commitul al doilea era de fapt primul, adică ``HEAD`` referea acel commit.
Ne va apărea din nou un fișier deschis în editorul Vim pe care trebuie să-l modificăm.

.. code-block:: bash

    student@uso:~/my-first-repository$ git rebase -i HEAD~2

Mai jos se poate observa conținutul fișierului ce trebuie modificat.
Primele 2 rânduri conțin mesajele de comit ale celor mai recente N (în cazul acesta 2) commituri.
Îl alegem pe cel pe care vrem să-l modificăm și modificăm keywordul ``pick`` în ``reword`` sau ``r``.
Salvăm fișierul.

.. code-block:: bash    
    
    pick 4b9ba01 Update README.md
    pick 483f1a1 Add error-file.txt 2

    # Rebase 0dfb632..483f1a1 onto 0dfb632 (2 commands)
    #
    # Commands:
    # p, pick <commit> = use commit
    # r, reword <commit> = use commit, but edit the commit message
    # e, edit <commit> = use commit, but stop for amending
    # s, squash <commit> = use commit, but meld into previous commit
    # f, fixup <commit> = like "squash", but discard this commit's log message
    # x, exec <command> = run command (the rest of the line) using shell
    # b, break = stop here (continue rebase later with 'git rebase --continue')
    # d, drop <commit> = remove commit
    # l, label <label> = label current HEAD with a name
    # t, reset <label> = reset HEAD to a label
    # m, merge [-C <commit> | -c <commit>] <label> [# <oneline>]
    # .       create a merge commit using the original merge commit's
    # .       message (or the oneline, if no original merge commit was 
    # .       specified). Use -c <commit> to reword the commit message.
    #
    # These lines can be re-ordered; they are executed from top to bottom.
    #
    # If you remove a line here THAT COMMIT WILL BE LOST.
    #
    # However, if you remove everything, the rebase will be aborted.
    #
    # Note that empty commits are commented out

Se va deschide un al doilea fișier care conține pe prima linie mesajul de commit pe care vrem să-l modificăm.
După ce modificăm mesajul salvăm fișierul.

.. code-block:: bash 

    Update README.md 2

    # Please enter the commit message for your changes. Lines starting
    # with '#' will be ignored, and an empty message aborts the commit.
    #
    # Date:      Thu Aug 20 00:00:25 2020 +0300
    #
    # interactive rebase in progress; onto 0dfb632
    # Last command done (1 command done):
    #    reword 4b9ba01 Update README.md
    # Next command to do (1 remaining command):
    #    pick 483f1a1 Add error-file.txt 2
    # You are currently editing a commit while rebasing branch 'my-new-branch' on '0dfb632'.
    #
    # Changes to be committed:
    #       modified:   README.md
    #

La fel ca mai devreme, trebuie să forțăm publicarea noilor schimbări.

.. note:: În cazul commiturilor care au fost deja publicate, pasul următor este **esențial**.
          
          În cazul commiturilor care **nu** au fost publicate, acest pas se poate înlocui cu executarea comenzii ``git push`` dacă se dorește publicarea commiturilor sau se poate omite în cazul în care vrem ca aceste commituri sa rămână doar în repositoryul local.


.. code-block:: bash 

    student@uso:~/my-first-repository$ git push --force
    Enumerating objects: 7, done.
    Counting objects: 100% (7/7), done.
    Delta compression using up to 4 threads
    Compressing objects: 100% (5/5), done.
    Writing objects: 100% (5/5), 569 bytes | 569.00 KiB/s, done.
    Total 5 (delta 1), reused 0 (delta 0)
    remote: Resolving deltas: 100% (1/1), done.
    To https://github.com/{username}/my-first-repository.git
    + 483f1a1...5de7231 my-new-branch -> my-new-branch (forced update)

.. note:: {username} este numele nostru de utilizator de pe GitHub.

**Exercițiu:** Verificați că modificările au fost făcute cum trebuie atât local, cât și pe GitHub.

.. hint:: ``git log`` și `https://github.com/{username}/my-first-repository/tree/my-new-branch <https://github.com/{username}/my-first-repository/tree/my-new-branch>`_


Operația merge dintre un branch secundar și master
--------------------------------------------------

În acest moment avem 2 branch-uri active: ``master`` și ``my-new-branch``.
Inspectăm fișierul README.md pe ambele branch-uri.

.. code-block:: bash 

    student@uso:~/my-first-repository$ git branch
      master
    * my-new-branch
    student@uso:~/my-first-repository$ cat README.md
    # My first project ever
    This line was added through a second branch
    This line is also added through a second branch
    student@uso:~/my-first-repository$ git checkout master
    Switched to branch 'master'
    Your branch is up to date with 'origin/master'.
    student@uso:~/my-first-repository$ cat README.md
    # My first REAL project ever

Scopul este să aduce modificările făcute pe branch-ul ``my-new-branch`` pe branch-ul ``master``.
Pentru a face acest pas, trebuie să ne asigurăm că branch-ul ``master`` local este sincronizat cu cel remote.
După ce branch-ul master este actualizat la zi, putem efectua operația de ``merge`` cu branch-ul ``my-new-branch``.

.. code-block:: bash 

    student@uso:~/my-first-repository$ git merge my-new-branch
    Auto-merging README.md
    CONFLICT (content): Merge conflict in README.md
    Automatic merge failed; fix conflicts and then commit the result.

.. note:: Git a încercat să facă operația ``merge`` în mod automat, însă din cauza conflictelor nu a reușit.
          Acum trebuie să ne ocupăm de rezolvarea conflictelor.

Fișierul README.md arată acum ca mai jos, însă noi vrem să păstrăm titlul ca pe branch-ul ``master`` adică ``My first REAL project ever``, dar să conțină și cele 2 linii adăugate de pe branch-ul ``my-new-branch``.
Prima linie din fișier (``<<<<<<< HEAD``) ne indică faptul că de acolo până la ``=======`` se află conținutul de pe branch-ul master, iar restul de la ``=======`` până la ``>>>>>>> my-new-branch`` se află conținutul de pe branch-ul ``my-new-branch``.

.. code-block::

    <<<<<<< HEAD
    # My first REAL project ever
    =======
    # My first project ever
    This line was added through a second branch
    This line is also added through a second branch
    >>>>>>> my-new-branch

Edităm fișierul astfel încât să rămânem cu conținutul dorit.
Salvăm fișierul.

.. code-block::

    # My first REAL project ever
    This line was added through a second branch
    This line is also added through a second branch

După ce facem modificările facem un nou commit pentru a încheia procesul de merge.

.. code-block:: bash 

    student@uso:~/my-first-repository$ git status
    On branch master
    Your branch is up to date with 'origin/master'.

    You have unmerged paths.
    (fix conflicts and run "git commit")
    (use "git merge --abort" to abort the merge)

    Changes to be committed:

        new file:   error-file.txt

    Unmerged paths:
    (use "git add <file>..." to mark resolution)

        both modified:   README.md
    student@uso:~/my-first-repository$ git add README.md
    student@uso:~/my-first-repository$ git status
    On branch master
    Your branch is up to date with 'origin/master'.

    All conflicts fixed but you are still merging.
    (use "git commit" to conclude merge)

    Changes to be committed:

        modified:   README.md
        new file:   error-file.txt
    student@uso:~/my-first-repository$ git commit -m "Merge branch my-new-branch into master"
    student@uso:~/my-first-repository$ git push
    Enumerating objects: 7, done.
    Counting objects: 100% (7/7), done.
    Delta compression using up to 4 threads
    Compressing objects: 100% (3/3), done.
    Writing objects: 100% (3/3), 386 bytes | 386.00 KiB/s, done.
    Total 3 (delta 1), reused 0 (delta 0)
    remote: Resolving deltas: 100% (1/1), completed with 1 local object.
    To https://github.com/lizababu/my-first-repository.git
    548723b..5470bd6  master -> master
    student@uso:~/my-first-repository$ git log
    commit 5470bd6601d4315b07fee11623e7e54f6dc498b7 (HEAD -> master, origin/master)
    Merge: 548723b 5de7231
    Author: Prenume Nume <adresa_de_email@email.com>
    Date:   Thu Aug 20 13:22:30 2020 +0300

        Merge branch my-new-branch into master

    commit 5de723172b566fe6a64946c56fcef3c49b9a6108 (origin/my-new-branch, my-new-branch)
    Author: Prenume Nume <adresa_de_email@email.com>
    Date:   Thu Aug 20 01:02:40 2020 +0300

        Add error-file.txt 2

    commit b848deef1ae16fa4d93dabb3c562936b9dc642c5
    Author: Prenume Nume <adresa_de_email@email.com>
    Date:   Thu Aug 20 00:00:25 2020 +0300

        Update README.md 2

    commit 548723be594b1f903168673dc27b0af5f04413fe
    Author: Prenume Nume <adresa_de_email@email.com>
    Date:   Wed Aug 19 23:17:35 2020 +0300

În acest moment branch-ul master conține și modificările făcute pe branch-ul ``my-new-branch``.

Ștergerea unui branch
---------------------

Putem să ștergem branch-ul ``my-new-branch`` deoarece nu mai avem nevoie de el.
Facem acest lucru atât pe repository-ul local, cât și cel de pe GitHub.

.. code-block:: bash 

    student@uso:~/my-first-repository$ git branch -d my-new-branch
    Deleted branch my-new-branch (was 5de7231).
    student@uso:~/my-first-repository$ git push origin --delete my-new-branch
    To https://github.com/lizababu/my-first-repository.git
    - [deleted]         my-new-branch
    student@uso:~/my-first-repository$ git branch
    * master

**Exercițiu:** Verificați că branch-ul nu mai există pe GitHub.
