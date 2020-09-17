Introducere în Git și GitHub
============================

În multe proiecte la care vom lucra, vom fi parte dintr-o echipă. Cu toții vom lucra la un proiect mai mare care este modificat zilnic.
În mod particular, când vorbim despre un proiect software vrem să avem dezvoltatori, oameni care să lucreze împreună cu noi la proiect.
Dezvoltatorii au nevoie de acces la codul sursă al proiectului software la care lucrăm.
După ce le dăm acces, vrem ca fiecare dezvoltator să știe la ce a lucrat și la ce lucrează ceilalți; ca să nu se suprapună, ca să ajute și ca să ofere feedback.

Pentru a putea rezolva problemele de sincronizare între 2 sau mai mulți colegi de echipă care lucrează la același proiect, ne ajută să avem un **sistem de versionare a codului**, adică să avem un istoric de modificări, adică o listă de versiuni.
Versionarea codului aduce și alte avantaje cum ar fi revenirea la o versiune mai veche a proiectului, găsirea rapidă a autorului unei secvențe de cod sau pur și simplu organizarea unui proiect.

**Git** este un sistem de management și versionare a codului sursă care permite această partajare dorită.

`GitHub <http://www.github.com/>`_ este o platformă online, bazată pe Git, pe care dezvoltatorii o pot folosi pentru a stoca și versiona codul lor sursă.
Git este utilitarul folosit, iar GitHub este serverul și aplicația web pe care rulează acesta, locul în care păstrăm repository-ul remote.

.. note:: 

  Similar cu GitHub există și alte platforme precum `Bitbucket <https://bitbucket.org>`_ sau `GitLab <https://about.gitlab.com>`_.
  Comenzile pe care le vom studia se aplică pentru toate platformele care folosesc ``Git``, doar interfața grafică diferă.

  În această carte vom folosi GitHub ca suport.
  În mare parte acesta nu diferă foarte mult de alte platforme.


Crearea unui cont pe GitHub (dacă nu aveți deja)
------------------------------------------------

Înainte de toate, ne asigurăm că avem cont pe GitHub.
Dacă aveți deja un cont pe GitHub puteți trece la subsecțiunea următoare.

Intrați pe `GitHub <http://www.github.com/>`_.
Pagina de pornire va arăta similar cu cea din imaginea de mai jos.

.. figure:: ./img/GitHub-init-page.png
  :scale: 30%
  :alt: Alternative text

Introduceți un username, adresa voastră de e-mail și o parolă sigură pentru cont.
Pentru validarea contului accesați-vă căsuța de e-mail.
Acolo veți găsi un e-mail în care vi se explică cum se poate valida noul cont creat.
Verificați și căsuța **spam** în caz că nu ați primit nimic în inbox.

.. note::

  **GitHub Student Pack**

  GitHub oferă studenților numeroase beneficii care în mod normal sunt contra cost (plătite). 
  Găsiți mai multe detalii pe site-ul `oficial <https://education.github.com/pack>`_.


Pregătirea inițială a mediului Git
----------------------------------

Ca să utilizăm Git, facem în primă fază niște pași de configurare. Adică vom configura numele și e-mail-ul nostru, ca mai jos:

.. code-block:: bash

    student@uso:~$ git config --global user.name "Prenume Nume"
    student@uso:~$ git config --global user.email "adresa_de_email@example.com"
  
De exemplu, pentru autorul acestei secțiuni comenzile rulate sunt:

.. code-block:: bash

    student@uso:~$ git config --global user.name "Liza Babu"
    student@uso:~$ git config --global user.email "lizababu@example.com"

Crearea primului repository
---------------------------

Pentru a lucra la un proiect software, creăm un **repository software**.
Vom crea unul pe GitHub, unul local, după care le vom interconecta.

.. admonition:: **Repository software**

  Proiectul este stocat într-un **repository software**.
  Repository-ul conține fișierele proiectului: codul sursă, fișiere de configurare.
  De obicei acesta vine însoțit și de un fișier **README.md** în care se găsesc informații despre proiect: care este scopul proiectului, cum se compilează, pe ce platforme rulează.

  Repository-urile sunt de 2 tipuri: **locale** și **remote**.
  Acestea pot fi interconectate și să refere de fapt același proiect.
  Repository-ul local este cel pe care îl avem la noi pe calculator, pe când cel remote este unul stocat pe un server (în cazul nostru **GitHub**).
  Este doar o diferență de perspectivă între cele două, ele nu diferă din punct de vedere tehnic.

  Printre cele mai importante operații cu un repository sunt: init, fork, clone.
  Acești termeni vor fi explicați în momentul care vom avea nevoie de ei.


Crearea unui repository gol pe GitHub 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ne autentificăm pe GitHub.
Apăsăm pe săgeată din meniul din dreapta sus și vedem ceva similar cu imaginea de mai jos.

.. figure:: ./img/Create-new-repo-1.png
  :scale: 45%
  :alt: Alternative text

Apăsați pe ``Your profile`` pentru a merge pe profilul vostru.
Aici este locul în care veți putea vedea contribuțiile voastre pe GitHub.
În partea de sus a ecranului veți vedea un meniu orizonatal care conține 4 opțiuni: ``Overview``, ``Repositories``, ``Projects`` și ``Packages``.

.. figure:: ./img/Create-new-repo-2.png
  :scale: 45%
  :alt: Alternative text

Apăsați pe ``Repositories``.
Acum veți vedea întreaga listă de repository-uri pe care le aveți. Pentru a crea unul nou, apăsați pe butonul verde din dreapta sus pe care scrie ``New``.

.. figure:: ./img/Create-new-repo-3.png
  :scale: 45%
  :alt: Alternative text

Acum este momentul în care veți da un nume proiectului vostru, o descriere succintă a acestuia și veți putea decide dacă să fie public (vizibil tuturor utilizatorilor) sau privat (vizibil doar pentru voi și eventualii colaboratori ai proiectului).
Vă va apărea un formular similar cu cel din imaginea de mai jos.
Pentru acest tutorial vom crea un repository public.
De asemenea, este indicat ca numele repository-ului să descrie bine proiectul.
Descrierea proiectului este opțională, dar e recomandat să o adăugăm pentru a fi ușor de înțeles pentru cei care vor ajunge la proiectul vostru.

TODO: schimbă poza din privat în public

.. figure:: ./img/Create-new-repo-4.png
  :scale: 45%
  :alt: Alternative text

Apăsați pe ``Create repository``.
Vor apărea câteva instrucțiuni pentru crearea unui repository local nou și conectarea celui noi cu cel remote.
Acest lucru este acoperit în secțiunile următoare.

TODO: Adaugă GIF cu cele 4 imagini.

Crearea unui repository gol local
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Primul pas este să alegem un director în care să inițializăm repository-ul.
Navigăm în directorul nou creat.
În acest tutorial creăm directorul ``my-first-repository`` în directorul home (adică ``/home/student`` sau ``~``).

.. code-block:: bash

    student@uso:~$ pwd
    /home/student
    student@uso:~$ mkdir my-first-repository
    student@uso:~$ cd my-first-repository
    student@uso:~/my-first-repository$ git init
    Initialized empty Git repository in /home/student/my-first-repository/.git/
    student@uso:~/my-first-repository$ ls -a
    ./    ../   .git/

Mai sus am inițializat repository-ul local prin comanda ``git init`` dată în directorul ales (``my-first-repository``).

.. admonition:: **Init**

  Operația **init** este una locală și are rolul de a inițializa un repository gol, local.
  Inițializarea repository-ului local presupune crearea, în directorul ales, mediului pentru a putea iniția un proiect versionat Git.
  Această operare duce la crearea unui director numit ``.git`` în care se vor ține ulterior date suplimentare despre repository.


Conectarea celor 2 repository-uri
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Am creat până în acest moment un repository local și unul remote.
Trebuie să le interconectăm pentru a lucra cu ele.

Fiecare coleg care va lucra la acest proiect va trebui să facă acest pas.
Așa va exista un punct de legătură între voi: repository-ul remote.

.. code-block:: bash

    student@uso:~/my-first-repository$  git remote add origin https://github.com/{username}/my-first-repository.git

Conectarea celor 2 repository-uril înseamnă setarea orginului, adică repository-ului remote la care se conectează cel local.
În comanda de mai sus ``{username}`` este numele utilizatorului vostru de pe GitHub.
De exemplu, pentru autorul acestui capitol ``{username}`` se înlocuiește cu ``lizababu``.

TODO: de pus o diagramă de tip before and after cu cele două repository-uri neconectate, apoi conectate.
