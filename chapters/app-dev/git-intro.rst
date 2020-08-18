Introducere în Git și GitHub
============================

În majoritatea proiectelor la care vom lucra nu vom fi singuri, ci vom contribui la un proiect mai mare care este modificat zilnic de mai mulți oameni.
În mod particular, când vorbim despre un proiect software avem nevoie de un mod de a împarți codul și de a urmări în același timp cine ce modificări a adus programului.

.. admonition:: Example

          Astăzi la ora 13:00 voi vă apucați de implementat o funcționalitate pentru proiectul la care lucrați.
          Luați întregul cod sursă și îl modificați după cum aveți nevoie.
          Colegul vostru de echipă mai experimentat se apucă, să zicem, tot la ora 13:00 de rezolvat o problemă descoperită în cod.
          Acesta a reușit să rezolve problema înainte ca voi să terminați de implementat noua funcționalitate, așadar el a suprascris codul sursă inițial (cu probleme) cu cel modificat.
          În momentul acesta, voi încă lucrați la funcționalitate, însă codul sursă pe care îl modificați voi a rămas cu problema nerezolvată.
          Trebuie să faceți cumva să actaulizați codul vostru sursă cu noile modificări ale colegului vostru.
        
          Cum ați face acest lucru?
          
          Acum extindeți problema și gândiți-vă că sunteți 10 colegi de echipă care lucrează la același proiect.
          Cum rezolvați problema acum?

          Veți avea nevoie întotdeauna să rezolvați astfel de situații, iar acest proces devine anevoios.

Pentru a putea rezolva problemele de sincronizare între 2 sau mai mulți colegi de echipă care lucrează la același proiect, este util să avem o gestiune versionată a codului, adică să avem un istoric de modificări, adică o listă de versiuni.
Versionarea codului aduce și alte avantaje precum posibilitatea de a reveni la o versiune mai veche a proiectului, găsirea rapidă a autorului unei secvențe de cod sau pur și simplu organizarea facilă a unui proiect.

**Git** este un sistem de management și versionare a codului sursă care permite această partajare dorită.

`GitHub <http://www.github.com/>`_ este o platformă online, bazată pe Git, pe care dezvoltatorii o pot folosi pentru a stoca și versiona codul lor sursă.
Git este utilitarul folosit, iar GitHub este serverul și aplicația web pe care rulează acesta, locul în care păstrăm repository-ul remote.
Similar cu GitHub există și alte platforme precum `Bitbucket <https://bitbucket.org>`_ sau `GitLab <https://about.gitlab.com>`_.
În această carte vom folosi GitHub ca suport.
În mare parte acesta nu diferă foarte mult de alte platforme.

Atunci când lucrăm cu Git și GitHub, este esențial să știm la ce se referă anumiți termeni.
Așadar, până a începe parcurgerea secțiunilor acestui capitol, trebuie să ne familiarizăm cu câțiva dintre ei.
Vom prezenta în acest breviar o parte dintre termeni, restul rămânând să fie introduși pe parcurs.

**Repository software**

Proiectul este stocat într-un **repository software**.
Repository-ul conține fișierele efective ale proiectului și informații despre acesta.
Uzual acesta vine însoțit de un fișier **README.md** în care se găsesc mai multe informații despre proiect.
Repository-urile sunt de 2 tipuri: locale și remote.
Acestea pot fi interconectate și să refere de fapt același proiect.

Există câteva operații ce pot fi făcute asupra unui repository.

**Init**

Operația de **init** este una locală și are rolul de a inițializa un repository gol, local.
Inițializarea repository-ului local presupune crearea, în directorul specificat, structurii necesară pentru a putea iniția un proiect versionat Git.
Această inițializare presupune crearea unui director numit ``.git`` în care se vor ține ulterior metadate despre repository.

**Fork**

Operația **fork** are rolul de a crea o copie a unui repository deja existent.
Copia se realizează doar pe GitHub, nu și local.
În general, această operație se realizează în momentul în care vreți să aduceți modificări asupra unui repository deja existent sau dacă vreți să experimentați.
Puteți ulterior să publicați schimbările făcute în repository-ul inițial, însă doar după obținerea unor aprobări de la deținătorul proiectului.

**Clone**

Operația **clone** realizează o copie locală a unui repository.
Această copie poate fi acum actualizată după bunul plac.


Crearea unui cont pe GitHub (dacă nu aveți deja)
------------------------------------------------

Până a trece mai departe, trebuie să ne asigurăm că avem cont pe GitHub.
Dacă aveți deja un cont pe GitHub puteți trece la subsecțiunea următoare.

Intrați pe `GitHub <http://www.github.com/>`_.
Pagina de pornire va arăta similar cu cea din imaginea de mai jos.

.. figure:: ./img/GitHub-init-page.png
  :scale: 30%
  :alt: Alternative text

Introduceți un username, adresa voastră de e-mail și o parolă sigură pentru cont.
Pentru validarea contului accesați-vă căsuța de e-mail.
Acolo veți găsi un e-mail în care vi se explică cum se poate valida noul cont creat.

**GitHub Student Pack**

GitHub oferă celor care sunt încă studenți numeroare benificii (pe care în mod normal utilizatorii nu le au decât contra cost) studenților. 
Găsiți mai multe detalii pe site-ul `oficial <https://education.github.com/pack>`_.

Pregătirea inițială a mediului Git
----------------------------------

Primul pas care trebuie făcut este să configurați local câteva informații despre voi.
Acesta vor fi de folos în momentul în care veți contribui la un proiect.
Practic aceste informații vor ajuta la identificarea voastră și astfel ceilalți contribuitori vor putea ști cine a făcut o anumită schimbare în repository.

Pentru configurarea numelui și adresei de e-mail rulați comenzile de mai jos.

.. code-block:: bash

    student@uso:~$ git config --global user.name "Prenume Nume"
    student@uso:~$ git config --global user.email "adresa_de_email@email.com"


Crearea primului repository
---------------------------

Mai întâi trebuie să avem un repository în care să lucrăm.
Vom crea unul pe GitHub, unul local, după care le vom interconecta.

Crearea unui repository gol pe GitHub 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Autentificați-vă (dacă nu sunteți deja) pe contul vostru de GitHub.
Odată autentificat, vă va apărea în dreapta sus un meniu.
Veți apăsa pe săgeată și veți obține ceva similar cu vedeți în imaginea de mai jos.

.. figure:: ./img/Create-new-repo-1.png
  :scale: 45%
  :alt: Alternative text

Apăsați pe ``Your profile`` pentru a merge pe profilul vostru.
Aici este locul în care veți putea contribuțiile voastre pe GitHub, proiectele la care lucrați, informațiile despre voi pe care le faceți publice.
În partea de sus a ecranului veți vedea un meniu orizonatal care conține 4 opțiuni: ``Overview``, ``Repositories``, `` Projects`` și ``Packages``.

.. figure:: ./img/Create-new-repo-2.png
  :scale: 45%
  :alt: Alternative text

Apăsați pe ``Repositories``.
Acum veți vedea întreaga listă de repository-uri pe care le aveți. Pentru a crea unul nou, apăsați pe butonul verde din dreapta sus pe care scrie ``New``.

.. figure:: ./img/Create-new-repo-3.png
  :scale: 45%
  :alt: Alternative text

Acum este momentul în care veți da un nume proiectului vostru, o descriere succintă al acestuia și veți putea decide dacă să fie public (vizibil tuturor utilizatorilor) sau privat (vizibil doar pentru voi și eventualii colaboratori ai proiectului).
Vă va apărea un form similar cu cel din imaginea de mai jos.
Pentru acest tutorial vom crea un repository public.
De asemenea, este indicat ca numele repository-ului să descrie bine proiectul.
Descrierea proiectului este opțională, însă nicio informație în plus nu strică.

TODO: schimbă poza din privat în public

.. figure:: ./img/Create-new-repo-4.png
  :scale: 45%
  :alt: Alternative text

Apăsați pe ``Create repository``.
Vor apărea câteva instrucțiuni pentru crearea unui repository local noi și conectarea celui noi cu cel remote.
Acest lucru este acoperit în secțiunile următoare.

Crearea unui repository gol local
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Primul pas pentru a crea un repository local este să alegeți un director în care să inițializați repository-ul.
Navigați către acea cale.
În acest tutorial noi vom crea acest director la calea ``/home/student``, adică ``~``, numit ``my-first-repository.git``.

.. code-block:: bash

    student@uso:~$ pwd
    /home/student
    student@uso:~$ mkdir my-first-repository
    student@uso:~$ cd my-first-repository
    student@uso:~/my-first-repository$

Următorul pas este de a inițializa repository-ul folosind opțiunea ``init``. Observați că se crează directorul ``.git`` în directorul nostru.

.. code-block:: bash

    student@uso:~/my-first-repository$ git init
    Initialized empty Git repository in /home/student/my-first-repository/.git/
    student@uso:~/my-first-repository$ ls -a
    ./    ../   .git/


Conectarea celor 2 repository-uri
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Ultimul pas rămas este să conectăm repository-urile proaspăt create.
Acest lucru presupune setarea orginului, adică repository-ului remote la care se conectează cel local.
În comanda de mai jos ``{username}`` este numele utilizatorului nostru de pe GitHub.

TODO: de pus o diagramă de tip before and after cu cele două repository-uri neconectate, apoi conectate.

.. code-block:: bash

    student@uso:~/my-first-repository$  git remote add origin https://github.com/{username}/my-first-repository.git

Pentru verificarea originului unui repository local folosiți comanda următoare:

.. code-block:: bash

    student@uso:~/my-first-repository$ git remote show origin
    * remote origin
    Fetch URL: https://github.com/{username}/my-first-repository.git
    Push  URL: https://github.com/{username}/my-first-repository.git
    HEAD branch: (unknown)

Vom detalia în următoarele secțiuni ce este un ``branch`` și de ce acum apare ``HEAD branch`` ca fiind necunoscut (``unknown``).