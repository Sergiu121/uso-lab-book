Crearea unui Pull Request (PR) pe GitHub
========================================

În momentul în care vrem să adăugăm o funcționalitate nouă unui proiect software pe GitHub este recomandat să o facem printr-un **Pull Request**, prescurtat **PR**.
Un **Pull Request** este o cerere de modificare a repository-ului.
Alți colaboratori ai proiectului vor recenza modificările și vor aproba, vor sugera schimbări sau vor respinge această cerere.
În momentul în care un Pull Request este aprobat, atunci schimbările propuse în Pull Request pot fi integrate în proiect, adică se va putea face merge între codul sursă curent și noile modificări.

Spunem că deschidem un Pull Request care urmează să fie integrat într-un anumit branch.
De obice acel branch este **master**, însă acest lucru nu este obligatoriu.
În acest tutorial vom deschide un Pull Request care urmează să fie integrat în branch-ul **master**.

.. note::

  Alternativa la a crea un **Pull Request** ar fi să lucrăm direct pe branch-ul **master**.

  Așa cum am menționat și în secțiunile anterioare, este **BAD-PRACTICE** să lucrăm direct pe branch-ul **master** din mai multe motive:

  #. Pe branch-ul **master** se ține întotdeauna o versiune de cod funcțională. Astfel, lucrul pe acest branch ar însemna să facem commituri doar atunci când o funcționalitate este finalizată, altfel pe branch-ul **master** vom avea o bucată de cod neterminată care poate să afecteze întreg proiectul.
  #. Lucrul pe un singur branch nu se oferă posibilitatea de a da feedback pe schimbările făcute pe repository. Dacă nu avem posibilitatea să oferim feedback unui coleg prin intermediul GitHub, atunci vom avea nevoie să comunicăm pe un alt mediu observațiile noastre, iar ei vor trebui să creeze un nou commit pentru rezolvarea problemelor. Mult mai simplu este să se realizeze întreaga etapă de feedback, numită **code review** înainte ca schimbările să apară pe **master**.
  #. În unele situații nici nu vom avea drepturi să scriem pe branch-ul **master**, astfel devenind obligatoriu lucrul pe un alt branch și integrarea codului în branch-ul **master** printr-un **Pull Request**.


În secțiunea anterioară (TODO adaugă ref) am adus modificările de pe branch-ul TODO pe branch-ul **master** prin operația **merge**.
Acum vom integra schimbările prin intermediul unui **Pull Request** urmând pașii enumerați mai sus.

.. note::

  Folosirea unui **Pull Request** în loc de a efectua o operație **merge** vine cu mai multe beneficii:

  #. În general, schimbările nu pot fi integrate fără ca PR-ul să fie aprobat. Aprobarea vine în mod normal de la un alt coleg de echipă.
  #. Recenzia codului sursă se face ușor pe un Pull Request. Vom vedea în secțiunea TODO cum putem adăuga recenzenți.


.. admonition:: Pași Pull Request

  Ca să avem o contribuție prin Pull Request în mod uzual se urmează pașii:

  #. Se realizează un fork sau o clonă a repository-ului. Noi vom folosi în continuare repository-ul TODO.
  #. Creăm un branch nou.
  #. Realizăm commit pe noul branch și îl publicăm pe GitHub.
  #. Creăm un PR în interfața GitHub.
  #. Ulterior, un maintainer al repository-ului va recenza PR-ul. Dacă e nevoie de modificări, vom face actualizări pe care le vom adăuga (prin operația **push**) din nou în branch-ul nou creat, PR-ul fiind actualizat.
  #. După un număr dat de iterații, PR-ul va fi definitivat. Atunci maintainerul va integra branch-ul în master (operația **merge**).

În următoarele subsecțiuni vom implementa algoritmul Bubble Sort și vom contribui la repository-ul TODO prin intermediul unui **Pull Request**.

Crearea unui branch nou
-----------------------

Pentru a putea deschide un Pull Request, trebuie să lucrăm pe un branch diferit dață de cel în care vrem să integrăm schimbările.
În acest caz, vom lucra pe un nou branch, diferit de branch-ul **master**.

Creăm un branch numit **bubble-sort-implementation**.

.. code-block:: bash

    student@uso:~/my-first-repository$ git branch
    *  master
    student@uso:~/my-first-repository$ git branch bubble-sort-implementation
    student@uso:~/my-first-repository$ git checkout bubble-sort-implementation
    Switched to a new branch 'bubble-sort-implementation'
    student@uso:~/my-first-repository$ git branch
    * bubble-sort-implementation
    master


.. note::

  La începutul aceste subsecțiui repository-ul avea un singur branch, cel **master**.
  Ne amintim că în secțiunea anterioară (TODO adaugă ref) am șters branch-ul **add-gitignore**.

.. note::

  Simbolul ``*`` din outputul comenzii ``git branch`` ne indică pe ce branch de aflăm.
  În acest caz este vorba despre branch-ul **bubble-sort-implementation**.

Până la acest moment am făcut deja o serie de commituri pe repository-ul nostru. 

TODO: output git log

Același istoric de commituri îl putem vedea și prin intermediul interfeței grafice GitHub.

TODO: adaugă GIF cum navighezi pe GitHub spre toate commiturile

Crearea unui commit pe branch-ul nou creat
------------------------------------------

Vom actualiza fișierul ``bubble-sort.c`` cu implementarea algoritmului ales.
Modificăm fișierul ``bubble-sort.c`` astfel încât conținutul său să fie următorul:

.. code-block:: c

  #include <stdio.h> 
  
  #define MAX_LEN 100

  void swap(int *x, int *y) { 
      int tmp = *x; 
      *x = *y; 
      *y = tmp; 
  } 
    
  void bubble_sort(int *arr, int len) { 
    int i, j;

    for (i = 0; i < len - 1; i++)
        for (j = 0; j < len - 1; j++)  
            if (arr[j] > arr[j + 1]) 
                swap(&arr[j], &arr[j + 1]); 
  }

  void print_array(int *arr, int len) {
    int i;
    
    for (i = 0; i < len; i++) {
      printf("%d ", arr[i]);
    }
    printf("\n");
  }

  int main() {
      int arr[MAX_LEN], len, i;
      
      printf("What's the length of the array? Maximum lenght is %d\n", MAX_LEN);
      scanf("%d", &len);

      printf("Gimme the %d elements\n", len);
      for (i = 0; i < len; i++) {
        scanf("%d", &arr[i]);
      }

      printf("Nonsorted array: ");
      print_array(arr, len);

      bubble_sort(arr, len);

      printf("Sorted array: ");
      print_array(arr, len);

      return 0; 
  } 

.. note::

  Algoritmul de mai sus sortează crescător un vector de numere întregi citit de la tastatură.
  Trebuie să precizăm acest lucru și în fișierul ``README.md``

Modificăm fișierul ``README.md`` astfel încât el să aibă următorul conținut:

.. code-block:: bash

  student@uso:~/my-first-repository$ cat README.md
  TODO: adaugă conținut potrivit

  Sorts a integer array in ascending order.

  The algoritm is implemented in C.

.. note::

  În acest moment noi am implementat funcționalitatea principală a proiectului.
  
  Așa cum am precizat și în secțiunea TODO, fișierul README trebuie să conțină informații despre proiect.
  Așadar, am actualizat și fișierul README în acest caz.


Acum trebuie să creăm un **commit** cu schimbările făcute.

.. code-block:: bash

  student@uso:~/my-first-repository$ git status
  On branch bubble-sort-implementation
  Changes not staged for commit:
    (use "git add <file>..." to update what will be committed)
    (use "git restore <file>..." to discard changes in working directory)
    modified:   README.md
    modified:   bubble-sort.c

  no changes added to commit (use "git add" and/or "git commit -a")
  student@uso:~/my-first-repository$ git add README.md
  student@uso:~/my-first-repository$ git add bubble-sort.c
  student@uso:~/my-first-repository$ git status
  On branch bubble-sort-implementation
  Changes to be committed:
    (use "git restore --staged <file>..." to unstage)
    modified:   README.md
    modified:   bubble-sort.c

Comitem modificările.
Folosim o descriere succintă care să descrie ce modificări aducem asupra repository-ului.

.. code-block:: bash

  student@uso:~/my-first-repository$ git commit -m "Add Bubble Sort implementation, update README accordingly"
  [bubble-sort-implementation 2a476f4] Add Bubble Sort implementation, update README accordingly
  2 files changed, TODO insertions(+), TODO deletions(-)

  student@uso:~/my-first-repository$ git log
  commit 2a476f44aaca87fd17cef2af134d64f9e1b674ff (HEAD -> bubble-sort-implementation)
  Author: Liza Babu <lizababu@example.com>
  Date:   Thu Sep 10 12:17:51 2020 +0300

      Add Bubble Sort implementation, update README accordingly
  TODO: adaugă mai mult output ?

.. note::

  TODO: discuție pe git log

Pentru a putea crea un **PR** trebuie să publicăm noul commit.

.. code-block:: bash

  student@uso:~/my-first-repository$ git push origin bubble-sort-implementation
  Enumerating objects: 3, done.
  Counting objects: 100% (3/3), done.
  Delta compression using up to 4 threads
  Compressing objects: 100% (2/2), done.
  Writing objects: 100% (2/2), 267 bytes | 267.00 KiB/s, done.
  Total 2 (delta 0), reused 0 (delta 0), pack-reused 0
  remote: 
  remote: Create a pull request for 'bubble-sort-implementation' on GitHub by visiting:
  remote:      https://github.com/{username}/my-second-repository/pull/new/bubble-sort-implementation
  remote: 
  To https://github.com/{username}/my-second-repository
  * [new branch]      bubble-sort-implementation -> bubble-sort-implementation
  Branch 'bubble-sort-implementation' set up to track remote branch 'bubble-sort-implementation' from 'origin'.


.. note::

  Linkul ``https://github.com/{username}/my-second-repository/pull/new/bubble-sort-implementation`` ne este de folos în secțiunea următoare (TODO adaugă ref).

  În loc de ``{username}`` veți avea username-ul vostru de pe GitHub.
  Pentru autorul acestui capitol este ``lizababu``.


Crearea Pull Requestului
------------------------

TODO: adaugă screenshoturi noi pentr subsecțiunea asta

După publicarea schimbărilor anterioare, intrăm pe GitHub.
Vedem că ne apare că a fost creat un nou commit pe branch-ul ``bubble-sort-implementation``.

.. figure:: ./img/GitHub-before-PR.png
  :scale: 45%
  :alt: Alternative text

Pentru a crea un Pull Request nou avem două variante:

#. Accesăm linkul ``https://github.com/{username}/my-second-repository/pull/new/bubble-sort-implementation``, unde ``{username}`` este username-ul vostru de pe GitHub.
#. Apăsăm pe butonul ``Compare & pull request``

În acest moment s-a deschis o nouă pagină care arată că în imaginea de mai jos.

.. figure:: ./img/GitHub-create-PR.png
  :scale: 45%
  :alt: Alternative text

Mai jos explicăm semnificația celor mai importante componente prezente în imagine.

Descrierea Pull Requestului
^^^^^^^^^^^^^^^^^^^^^^^^^^^

În imaginea de mai jos vedem o parte a interfeței GitHub în care avem posibilitatea de a lăsa un comentariu în care să descriem (chiar și mai în detaliu decât într-un mesaj de commit) ce schimbări am făcut. 

.. figure:: ./img/GitHub-description.png
  :scale: 45%
  :alt: Alternative text

.. warning:: **NU** apăsați incă butonul ``Create pull request``.

În cazul nostru, comentariul poate conține detalii despre implementarea algoritmului.
O descriere potrivită poate fi:

.. code-block::

  I implemented a non-optimized Bubble Sort algorithm in C.
  The program sorts an integer array in ascending order.


TODO: adaugă GIF: fără și cu descrierea de mai sus

Configurarea branch-ului în care vom integra PR-ul
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Modificările pe care le-am făcut urmează a fi integrate într-un branch.
În general, branch-ul ``master`` este cel care conține codul sursă actualizat la zi, deci este branch-ul în care se integrează PR-urile.

.. note::

  Totuși, este bine de știut că putem schimba acest branch prin apăsarea butonului ``base: master`` din imaginea de mai jos.
  Vor fi afișate toate branch-urile din acest repository și vom putea alege în ce branch să integrăm PR-ul.

În acest tutorial vom folosi branch-ul ``master``.

.. figure:: ./img/GitHub-base-branch.png
  :scale: 45%
  :alt: Alternative text

Acum creăm **Pull Requestul** apăsând pe butonul ``Create pull request``.

Recenzii și recenzenți
^^^^^^^^^^^^^^^^^^^^^^

Motivul principal pentru introducerea PR-urilor este pentru a putea avea posibilitatea de a primi feedback pe modificările aduse.
Din interfața grafică GitHub putem adăuga recenzenți care să dea feedback pe modificări.
Recenzenții fac parte din colaboratorii proiectului.

.. figure:: ./img/GitHub-review.png
  :scale: 45%
  :alt: Alternative text

În acest tutorial nu vom adăuga recenzenți la PR-ul creat.

Integrarea PR-ului
------------------

Așa cum am precizat în secțiunea TODO, unul sau mai mulți recenzenți se vor ocupa de recenzarea schimbărilor propuse în PR-ul nostru.
După mai multe runde de feedback și aplicarea acestuia, PR-ul va fi gata de integrat în branch-ul **master**.

.. note::

  După ce aplicați feedbackul de la recenzenți veți crea un nou commit local pe același branch, în acest caz pe branch-ul **bubble-sort-implementation**.

  Commitul trebuie să fie publicat folosind comanda ``git push``, la fel ca până acum.

  După ce faceți acești pași, recenzenții pot începe să dea feedback pe noile modificări.

  Acest scenariu *ping-pong* se va repeta până când voi, împreună cu recenzenții ajungeți la concluzia că schimbările pot fi integrate.

Acum vom face operația **merge** a PR-ului.
Apăsăm mai întâi butonul ``Merge pull request`` după care butonul ``Confirm merge`` ca în GIF-ul de mai jos.

TODO: adaugă GIF 

Ștergerea branch-ului în urma integrării în branch-ul master
------------------------------------------------------------

Odată făcută operația ``merge``, putem șterge branch-ul pe care am lucrat apăsând pe butonul ``Delete branch``.

.. figure:: ./img/GitHub-delete-branch.png
  :scale: 45%
  :alt: Alternative text

Această operație va șterge branch-ul doar pe GitHub.
Trebuie să ștergem și branch-ul din repository-ul local.

.. code-block:: bash

  student@uso:~/my-first-repository$ git checkout master
  Switched to branch 'master'
  Your branch is up to date with 'origin/master'.
  student@uso:~/my-first-repository$ git branch -d bubble-sort-implementation
  Deleted branch bubble-sort-implementation (was TODO).
  student@uso:~/my-first-repository$ git branch
  * master
  student@uso:~/my-first-repository$ git log
  TODO

În final am ajuns să integrăm modificările de pe branch-ul **bubble-sort-implementation** în branch-ul **master** prin intermediul unui **Pull Request**.
Am șters branch-ul **bubble-sort-implementation**.


Exercițiu practic - Crearea unui PR
-----------------------------------

Creați un nou repository pe GitHub cu numele TODO și clonați-o la voi pe calculator.
Veți folosi acest repository pentru rezolvarea acestui exercțiu.

Creați un **Pull Request** urmând pașii descriși mai sus în care să adăugați un nou algoritm de sortare al unui vector: TODO.
De această dată veți crea un nou fișier numit TODO cu următorul conținut:

TODO conținut

Pe parcursul creării acestui Pull Request țineți cont de următoarele:

#. Alegeți nume relevante pentru branch-uri și fișiere.
#. Adăugați un fișier README în repository.
#. Dați un mesaj de commit și o descriere potrivită PR-ului vostru.
#. Nu uitați să verificați pe tot parcursul dezvoltării starea clonei (``git status``) și istoricul de commituri (``git log``).
