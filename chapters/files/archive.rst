Arhive
======

Sunt situații în care vrem să trimitem/stocăm o ierarhie de fișiere.
Pentru a ușura acest lucru, folosim arhive.
Arhivele sunt o concatenare a unei ierarhii de fișiere și directoare într-un singur fișier.

Există două motive pentru care am vrea să folosim arhive:

#. Să avem o ierarhie de fișiere și directoare într-un singur fișier - *Arhivare*.
   De exemplu, vrem să trimitem pe mail o ierarhie de directoare cu laboratoarele și resursele materiei USO.
#. Ne dorim ca fișierele să ocupe mai puțin spațiu - *Compresie*.


*Comprimarea* este o arhivare mai specială pentru că micșorează dimensiunea fișierului rezultat.
Rezultatul este similar: agregarea într-un singur fișier.

În acest capitol vom folosi arhive de tipul *zip* și *tar*.
Vom folosi *tar* pentru arhivare și *zip* pentru arhivare comprimată.

Arhivare - **tar**
------------------

Crearea arhivelor
^^^^^^^^^^^^^^^^^

Arhivele sunt utile atunci când vrem să trimitem pe mail sau să încărcăm pe un site o ierarhie de fișiere și directoare.
Pe scurt, atunci când vrem să agregăm totul într-un singur fișier. Acesta poate fi transmis foarte ușor și ulterior dezarhivat.

Creăm o arhivă cu fișierele ``înregistrare_lab01.mov``, ``înregistrare_lab02.mov``, ``înregistrare_lab03.mov`` numită ``înregistrări.tar`` folosind utilitarul ``tar``:

.. code-block:: bash

    student@uso:~$ ls -lh
    total 9.0M
    -rw-r--r-- 1 student student 5.0M Aug 19 11:55 înregistrare_lab01.mov
    -rw-r--r-- 1 student student 3.0M Aug 19 11:55 înregistrare_lab02.mov
    -rw-r--r-- 1 student student 1.0M Aug 19 11:55 înregistrare_lab03.mov
    student@uso:~$ tar cvf înregistrări.tar înregistrare_lab01.mov înregistrare_lab02.mov înregistrare_lab03.mov
    înregistrare_lab01.mov
    înregistrare_lab02.mov
    înregistrare_lab03.mov
    student@uso:~$ ls -lh
    total 19M
    -rw-r--r-- 1 student student 5.0M Aug 19 11:55 înregistrare_lab01.mov
    -rw-r--r-- 1 student student 3.0M Aug 19 11:55 înregistrare_lab02.mov
    -rw-r--r-- 1 student student 1.0M Aug 19 11:55 înregistrare_lab03.mov
    -rw-r--r-- 1 student student 9.1M Aug 19 11:56 înregistrări.tar

Observăm cum după comanda de creare a arhivei *tar* am verificat corectitudinea operației.
Avem cum în directorul curent arhiva ``înregistrări.tar``.


Având trei fișiere pe care vrem să le arhivăm, folosim utilitarul ``tar`` împreună cu parametrii următori:

* c: creează arhiva;
* v: afișează detalii despre operație (verbose);
* f: folosește arhiva dată ca parametru (în cazul de față, numele ei).


Arhiva nou creată ocupă 9.1 MB.
Fișierele ce compun arhiva ocupă 5M, 3M respectiv 1M.

Fișierul de tipul *tar* nou creat nu ocupă mai puțin spațiu; din contră, ocupă mai mult spațiu din cauza metadatelor [#]_ fișierului.

Verificăm tipul fișierului folosind utilitarul ``file``.

.. code-block:: bash

    student@uso:~$ file înregistrări.tar
    înregistrări.tar: POSIX tar archive (GNU)

Fișierul ``înregistrări.tar`` este o arhivă de tip *tar*. 

Exerciții - creare arhive
"""""""""""""""""""""""""

#. * Creați 3 fișiere noi care să conțină pe rând numele, prenumele și anul vostru de naștere.
   * Creați o arhivă de tipul *tar* care să conțină cele trei fișiere și care să aibă  numele ``personal_data.tar``.
   * Verificați corectitudinea operațiilor.
   * Afișați dimensiunea arhivei.
   * Verificați că fișierul nou creat este o arhivă *tar*.


#. * Creați o arhivă a fișierelor din interiorul directorului ``/usr/include/net/`` cu numele ``net.tar``.
   * Verificați corectitudinea operației.
   * Afișați dimensiunea arhivei.
   * Verificați că fișierul nou creat este o arhivă *tar*.


Afișarea conținutului arhivelor
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Există cazuri în care vrem să vedem conținutul unei arhive.
Putem să vedem ce fișiere conține, fără a o deschide.

Facem acest lucru folosind utilitarul ``tar``:

.. code-block:: bash

    student@uso:~$ tar tf înregistrări.tar
    înregistrare_lab01.mov
    înregistrare_lab02.mov
    înregistrare_lab03.mov


Pentru a vizualiza arhiva **fără** dezarhivare am folosit opțiunea **t**.
Folosim opțiunea **f** pentru a specifica ce arhivă vrem să afișăm.

Exercițiu - afișarea conținutului unei arhive
"""""""""""""""""""""""""""""""""""""""""""""

* Afișați conținutul arhivelor create la exercițiul anterior **personal_data.tar** și **net.tar** **fără** dezarhivare.


Extragerea arhivelor
^^^^^^^^^^^^^^^^^^^^^^

Dezarhivarea este procesul opus al arhivării.
Avem deja o arhivă de tip *tar* și vrem să extragem ierarhia din ea.

În momentul în care dezarhivăm un fișier de tip *tar*, fișierele din cadrul arhivei vor fi create în directorul curent (dacă nu se specifică altfel).
Cu alte cuvinte, ierarhia de fișiere pe care am arhivat-o se păstrează, iar în momentul dezarhivării aceasta va arăta la fel ca înainte de arhivare.
Pentru a vedea mai clar efectul operației de dezarhivare, ștergem fișierele ``înregistrare_lab01.mov``, ``înregistrare_lab02.mov``, ``înregistrare_lab03.mov``, adică fișierele care se află în arhiva ``înregistrări.tar``.

.. code-block:: bash

    student@uso:~$ rm înregistrare_lab01.mov înregistrare_lab02.mov înregistrare_lab03.mov
    student@uso:~$ ls
    înregistrări.tar

Am verificat că fișierele nu mai există.

În continuare extragem fișierele din arhivă folosind ``tar``:

.. code-block:: bash

    student@uso:~$ tar xvf înregistrări.tar
    înregistrare_lab01.mov
    înregistrare_lab02.mov
    înregistrare_lab03.mov
    student@uso:~$ ls -lh
    total 19M
    -rw-r--r-- 1 student student 5.0M Aug 19 11:55 înregistrare_lab01.mov
    -rw-r--r-- 1 student student 3.0M Aug 19 11:55 înregistrare_lab02.mov
    -rw-r--r-- 1 student student 1.0M Aug 19 11:55 înregistrare_lab03.mov
    -rw-r--r-- 1 student student 9.1M Aug 19 12:04 înregistrări.tar

Pentru dezarhivare am folosit următorii parametrii ai utiliitarului ``tar``:

* x: extrage arhiva (extract);
* v: afișează detalii despre operație (verbose);
* f: folosește arhiva dată ca parametru (în cazul de față, numele ei).


Extragerea arhivelor la o cale specifică
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Avem următorul scenariu: am descărcat scheletul de temă de la facultate, acesta se află în directorul ``~/Downloads``, iar noi vrem să o dezarhivăm în directorul ``~/facultate/uso/teme/``.

Sau am descărcat în ``~/Downloads/`` de la un prieten o arhivă cu înregistrările video ale laboratoarelor.
Vrem să le dezarhivăm în directorul ``~/facultate/uso/laboratoare/video/``.

Creăm un director ``dezarhivare/tar`` și extragem arhiva acolo folosind ``tar``:

.. code-block:: bash

    student@uso:~$ ls -l
    total 18436
    -rw-r--r-- 1 student student 5242880 Aug 19 11:55 înregistrare_lab01.mov
    -rw-r--r-- 1 student student 3145728 Aug 19 11:55 înregistrare_lab02.mov
    -rw-r--r-- 1 student student 1048576 Aug 19 11:55 înregistrare_lab03.mov
    -rw-r--r-- 1 student student 9439088 Aug 19 12:04 înregistrări.tar
    student@uso:~$ mkdir -p dezarhivare/tar
    student@uso:~$ tree
    .
    |-- dezarhivare
    |   ``-- tar
    |-- înregistrare_lab01.mov
    |-- înregistrare_lab02.mov
    |-- înregistrare_lab03.mov
    ``-- înregistrări.tar

    2 directories, 4 files
    student@uso:~$ tar xvf înregistrări.tar --directory dezarhivare/tar/
    înregistrare_lab01.mov
    înregistrare_lab02.mov
    înregistrare_lab03.mov
    student@uso:~$ tree
    .
    |-- dezarhivare
    |   ``-- tar
    |       |-- înregistrare_lab01.mov
    |       |-- înregistrare_lab02.mov
    |       ``-- înregistrare_lab03.mov
    |-- înregistrare_lab01.mov
    |-- înregistrare_lab02.mov
    |-- înregistrare_lab03.mov
    ``-- înregistrări.tar

    2 directories, 7 files

Observăm că după crearea directoarelor și după extragerea arhivelor am verificat corectitudinea operațiilor.

După cum observăm în exemplu de mai sus, pentru a extrage fișierele către o anumită cale, folosim opțiunea *--directory* (- - d i r e c t o r y):

Putem extrage un singur fișier fără să fim obligați să dezarhivăm tot, folosind comanda ``tar xvf`` astfel:

.. code-block:: bash

    student@uso:~$ rm înregistrare_lab01.mov înregistrare_lab02.mov înregistrare_lab03.mov
    student@uso:~$ ls
    dezarhivare  înregistrări.tar
    student@uso:~$ tar xvf înregistrări.tar înregistrare_lab01.mov
    înregistrare_lab01.mov
    student@uso:~$ ls -l
    total 14344
    drwxr-xr-x 3 student student    4096 Aug 19 12:15 dezarhivare
    -rw-r--r-- 1 student student 5242880 Aug 19 11:55 înregistrare_lab01.mov
    -rw-r--r-- 1 student student 9439088 Aug 19 12:04 înregistrări.tar

Am extras doar fișierul ``înregistrare_lab01.mov`` din arhiva ``înregistrări.tar``.

.. note::
    Obervăm cum după comenzile de ștergere și dezarhivare am verificat corectitudinea operațiilor.
    Este extrem de util acest lucru.

Am pus ca ultim parametru numele fișierului (``înregistrare_lab01.mov``).

Exerciții - extragerea (dezarhivarea) unei arhive
"""""""""""""""""""""""""""""""""""""""""""""""""

#. * Creați un director cu numele ``personal`` și în acest director încă unul cu numele ``documente`` ca în ierarhia de mai sus.
   * Extrageți arhiva ``personal_data.tar`` în directorul ``personal/documente/``.
   * Extrageți *doar* fișierul ``nume`` în directorul curent.
   * Verificați corectitudinea operațiilor afișând conținutul arhivei și directoarelor după dezarhivare.


#. * Extrageți arhiva **net.tar** în directorul ``/tmp/``.
   * Verificați corectitudinea operațiilor afișând conținutul arhivei și directorului după dezarhivare.

Adăugarea de noi fișiere la arhive
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Adăugăm un nou fișier la arhivă folosind comanda ``tar``, astfel:

.. code-block:: bash

    student@uso:~$ tar -tf înregistrări.tar
    înregistrare_lab01.mov
    înregistrare_lab02.mov
    înregistrare_lab03.mov
    student@uso:~$ tar rvf înregistrări.tar înregistrare_lab04.mov
    înregistrare_lab04.mov
    student@uso:~$ tar tf înregistrări.tar
    înregistrare_lab01.mov
    înregistrare_lab02.mov
    înregistrare_lab03.mov
    înregistrare_lab04.mov

În primă fază am verificat că ``înregistrare_lab04.mov`` nu există în arhivă.
În continuare am adăugat ``înregistrare_lab04.mov`` la arhivă.

.. note::
    Observăm cum după comanda de adăugare de fișier la arhivă, am verificat corectitudinea operației.


Exerciții - adăugare de noi fișiere
"""""""""""""""""""""""""""""""""""

* Creați un fișier *UPB*; verificați operația afișând conținutul directorului părinte;
* Adăugați textul *Make UPB Great Again!* în interiorul fișierului; verificați operația afișând conținutul fișierului;
* Adăugați-l la arhiva ``personal_data.tar``, ca în exemplul de mai sus; verificați operația afișând conținutul arhivei. 


Comprimare ``tar.gz``
^^^^^^^^^^^^^^^^^^^^^

Am văzut mai sus că pentru a pune o ierarhie de fișiere într-unul singur, folosim ``tar``.
Pentru a reduce dimensiunea arhivei folosim utilitarul ``tar`` astfel:

.. code-block:: bash

    student@uso:~$ tar -czvf inregistrari.tar.gz inregistrare_lab01.mov inregistrare_lab02.mov inregistrare_lab03.mov
    inregistrare_lab01.mov
    inregistrare_lab02.mov
    inregistrare_lab03.mov
    student@uso:~$ ls -l
    -rw-r--r-- 1 student student   9441280 Sep 29 04:51 inregistrari.tar
    -rw-r--r-- 1 student student   9439133 Oct 12 18:55 inregistrari.tar.gz

Am folosit următorii parametrii:

* c: creează arhiva;
* z: pentru arhivare gzip;
* v: afișează detalii despre operație (verbose);
* f: folosește arhiva dată ca parametru (în cazul de față, numele ei).

Observăm că dimensiunea arhivei comprimate ``inregistrari.tar.gz`` a scăzut față de arhiva originală ``inregistrari.tar``.

Comprimare - ``zip``
--------------------

Acțiunea de comprimare este compusă din doi pași: arhivare și reducerea dimensiunii (comprimare).
Utilitarul ``zip`` face ambii pași simultan.

.. note::
    În continuare în acest capitol vom folosi noțiunea de arhivare, chiar dacă folosim utilitarul ``zip``.

Crearea arhivelor
^^^^^^^^^^^^^^^^^

Putem crea o arhivă folosind utilitarul ``zip``, astfel:

.. code-block:: bash

    student@uso:~$ zip înregistrări.zip înregistrare_lab01.mov înregistrare_lab02.mov înregistrare_lab03.mov
      adding: înregistrare_lab01.mov (deflated 0%)
      adding: înregistrare_lab02.mov (deflated 0%)
      adding: înregistrare_lab03.mov (deflated 0%)
    student@uso:~$ ls -lh
    total 26M
    drwxr-xr-x 3 student student 4.0K Aug 19 12:15 dezarhivare
    -rw-r--r-- 1 student student 5.0M Aug 19 11:55 înregistrare_lab01.mov
    -rw-r--r-- 1 student student 3.0M Aug 19 11:55 înregistrare_lab02.mov
    -rw-r--r-- 1 student student 1.0M Aug 19 11:55 înregistrare_lab03.mov
    -rw-r--r-- 1 student student 7.0M Aug 19 12:35 înregistrare_lab04.mov
    -rw-r--r-- 1 student student 9.1M Aug 19 17:56 înregistrări.tar
    -rw-r--r-- 1 student student 9.1M Aug 19 17:54 înregistrări.zip

Observăm cum după comanda de creare a arhivei ``zip`` am verificat corectitudinea operației.

Sintaxa este în felul următor: ``zip numele_arhivă.zip ierarhia_de_fișiere``

La prima vedere, folosind comanda ``ls -lh``  observăm că fișierul de tipul *zip* nou creat **nu** ocupă mai puțin spațiu decât suma dimensiunilor celor trei fișiere.
Motivul este că în sistemul de fișiere a apărut un nou fișier ce conține arhiva nou creată și sistemul de fișiere stochează informații despre acest fișier.
Exemplu de informații stocate: dimensiune, data creare, permisiuni, utilizatorul deținător.

Observăm că dimensiunea arhivei ``tar`` este aceeași cu aceea a arhivei ``zip``.
De fapt, dacă ne uităm în detaliu, vom vedea că nu este așa.

Mai sus vedeam afișarea dimensiuni în format *human-readable* adică în MegaBytes (MegaOcteți).
Afișăm dimesniunea în octeți:

.. code-block:: bash

    student@uso:~$ ls -l inregistrari.*
    -rw-r--r-- 1 student student 9441280 Sep 29 04:51 înregistrări.tar
    -rw-r--r-- 1 student student 9439072 Sep 29 04:51 înregistrări.zip

Arhiva ``tar`` are 9441280 octeți, iar arhiva ``zip`` are 9439072.
Observăm o mică diferență între cele două, varianta ``zip`` fiind mai mică.

Mergem mai departe cu un experiment.
Facem arhivare și comprimare a ierarhiei de directoare ``/usr/bin`` si comparăm dimensiunea:

.. code-block:: bash

    student@uso:~$ ls -l
    -rw-r--r-- 1 student student 100679680 Sep 29 04:46 usr_bin.tar
    -rw-r--r-- 1 student student  87282498 Sep 29 04:46 usr_bin.zip
    student@uso:~$ ls -lh
    -rw-r--r-- 1 student student 97M Sep 29 04:46 usr_bin.tar
    -rw-r--r-- 1 student student 84M Sep 29 04:46 usr_bin.zip

Observăm deja o diferență mai mare de dimensiune între cele două.

.. note::
    Pentru o mai bună înțelegere a comenzii de creare a arhivelor inspectați manualul: ``man zip``.


Exerciții - creare arhive
"""""""""""""""""""""""""

#. * Creați 3 fișiere noi care să conțină pe rând orașul natal, țara natală și liceul absolvit; verificați crearea fișierelor afișând conținutul directorului părinte.
   * Creați o arhivă de tipul ``zip`` care să conțină cele trei fișiere și care să aibă  numele ``personal_data.zip``; verificați conținutul arhivei.
   * Afișați dimensiunea arhivei.

#. * Creați o arhivă de tipul ``zip`` a fișierelor din interiorul directorului ``/usr/include/net/`` cu numele ``net.zip``.
   * Comparați dimensiunea arhivei ``zip`` cu cea ``tar`` de la exercițiu precendent.

Afișarea conținutului arhivelor
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Putem vizualiza conținutul arhivei astfel:

.. code-block:: bash

    student@uso:~$ zip -sf înregistrări.zip
    Archive contains:
      înregistrare_lab01.mov
      înregistrare_lab02.mov
      înregistrare_lab03.mov

Pentru a vizualiza arhiva **fără** dezarhivare folosim opțiunea **-sf** (prescurtare de la **show-files**).

Exerciții - afișarea conținutului unei arhivei
""""""""""""""""""""""""""""""""""""""""""""""

* Acest exercițiu folosește arhiva creată la exercițiu anterior.
* Afișați conținutul arhivelor ``personal_data.zip`` și ``net.zip`` *fără* dezarhivare.


Dezarhivarea arhivelor
^^^^^^^^^^^^^^^^^^^^^^

În momentul în care dezarhivăm un fișier de tip *zip*, fișierele din cadrul arhivei vor fi create în directorul curent (dacă nu se specifică altfel).
Cu alte cuvinte, ierarhia de fișiere pe care am arhivat-o se păstrează, iar în momentul dezarhivării aceasta va arăta la fel ca înainte de arhivare.
Pentru a vedea mai clar efectul operației de dezarhivare, ștergem fișierele ``înregistrare_lab01.mov``, ``înregistrare_lab02.mov``, ``înregistrare_lab03.mov``, adică fișierele care se află în arhiva *înregistrări.zip*.


.. code-block:: bash

    student@uso:~$ ls -l
    total 29708
    drwxr-xr-x 3 student student    4096 Aug 19 12:15 dezarhivare
    -rw-r--r-- 1 student student 5242880 Aug 19 11:55 înregistrare_lab01.mov
    -rw-r--r-- 1 student student 3145728 Aug 19 11:55 înregistrare_lab02.mov
    -rw-r--r-- 1 student student 1048576 Aug 19 11:55 înregistrare_lab03.mov
    -rw-r--r-- 1 student student 7340032 Aug 19 12:35 înregistrare_lab04.mov
    -rw-r--r-- 1 student student 9441280 Aug 19 17:56 înregistrări.tar
    -rw-r--r-- 1 student student 4195250 Aug 19 18:00 înregistrări.zip
    student@uso:~$ rm înregistrări.zip
    student@uso:~$ zip înregistrări.zip înregistrare_lab01.mov înregistrare_lab02.mov  înregistrare_lab03.mov
      adding: înregistrare_lab01.mov (deflated 0%)
      adding: înregistrare_lab02.mov (deflated 0%)
      adding: înregistrare_lab03.mov (deflated 0%)
    student@uso:~$ ls -l
    total 34828
    drwxr-xr-x 3 student student    4096 Aug 19 12:15 dezarhivare
    -rw-r--r-- 1 student student 5242880 Aug 19 11:55 înregistrare_lab01.mov
    -rw-r--r-- 1 student student 3145728 Aug 19 11:55 înregistrare_lab02.mov
    -rw-r--r-- 1 student student 1048576 Aug 19 11:55 înregistrare_lab03.mov
    -rw-r--r-- 1 student student 7340032 Aug 19 12:35 înregistrare_lab04.mov
    -rw-r--r-- 1 student student 9441280 Aug 19 17:56 înregistrări.tar
    -rw-r--r-- 1 student student 9439072 Aug 19 18:02 înregistrări.zip
    student@uso:~$ rm înregistrare_lab01.mov înregistrare_lab02.mov  înregistrare_lab03.mov
    student@uso:~$ unzip înregistrări.zip
    Archive:  înregistrări.zip
      inflating: înregistrare_lab01.mov
      inflating: înregistrare_lab02.mov
      inflating: înregistrare_lab03.mov
    student@uso:~$ ls -lh
    total 35M
    drwxr-xr-x 3 student student 4.0K Aug 19 12:15 dezarhivare
    -rw-r--r-- 1 student student 5.0M Aug 19 11:55 înregistrare_lab01.mov
    -rw-r--r-- 1 student student 3.0M Aug 19 11:55 înregistrare_lab02.mov
    -rw-r--r-- 1 student student 1.0M Aug 19 11:55 înregistrare_lab03.mov
    -rw-r--r-- 1 student student 7.0M Aug 19 12:35 înregistrare_lab04.mov
    -rw-r--r-- 1 student student 9.1M Aug 19 17:56 înregistrări.tar
    -rw-r--r-- 1 student student 9.1M Aug 19 18:02 înregistrări.zip

.. note::
    Observăm cum după operațiile de ștergere și dezarhivare, verificăm corectitudinea operațiilor.


Pentru a dezarhiva o arhivă folosim utilitarul ``unzip``.
Observați că am șters fișierele existente înainte de extragere.

Putem extrage fișierele către o anumită cale:

.. code-block:: bash

    student@uso:~$ mkdir dezarhivare/zip
    student@uso:~$ unzip înregistrări.zip -d dezarhivare/zip/
    Archive:  înregistrări.zip
      inflating: dezarhivare/zip/înregistrare_lab01.mov
      inflating: dezarhivare/zip/înregistrare_lab02.mov
      inflating: dezarhivare/zip/înregistrare_lab03.mov
    student@uso:~$ tree
    .
    |-- dezarhivare
    |   |-- tar
    |   ``-- zip
    |       |-- înregistrare_lab01.mov
    |       |-- înregistrare_lab02.mov
    |       ``-- înregistrare_lab03.mov
    |-- înregistrare_lab01.mov
    |-- înregistrare_lab02.mov
    |-- înregistrare_lab03.mov
    |-- înregistrare_lab04.mov
    |-- înregistrări.tar
    ``-- înregistrări.zip

    3 directories, 9 files

.. note::
    Observăm că după crearea directoarelor și după extragerea arhivelor am verificat corectitudinea operațiilor.

Am folosit comanda ``unzip -d destinație`` pentru a extrage o arhivă *zip* la calea *destinație*.

Putem dezarhiva *un singur* fișier/director din toată arhiva:

.. code-block:: bash

    student@uso:~$ rm înregistrare_lab03.mov
    student@uso:~$ ls -lh
    total 34M
    drwxr-xr-x 4 student student 4.0K Aug 19 18:05 dezarhivare
    -rw-r--r-- 1 student student 5.0M Aug 19 11:55 înregistrare_lab01.mov
    -rw-r--r-- 1 student student 3.0M Aug 19 11:55 înregistrare_lab02.mov
    -rw-r--r-- 1 student student 7.0M Aug 19 12:35 înregistrare_lab04.mov
    -rw-r--r-- 1 student student 9.1M Aug 19 17:56 înregistrări.tar
    -rw-r--r-- 1 student student 9.1M Aug 19 18:02 înregistrări.zip
    student@uso:~$ unzip înregistrări.zip înregistrare_lab03.mov
    Archive:  înregistrări.zip
    inflating: înregistrare_lab03.mov
    student@uso:~$ ls -lh
    total 35M
    drwxr-xr-x 4 student student 4.0K Aug 19 18:05 dezarhivare
    -rw-r--r-- 1 student student 5.0M Aug 19 11:55 înregistrare_lab01.mov
    -rw-r--r-- 1 student student 3.0M Aug 19 11:55 înregistrare_lab02.mov
    -rw-r--r-- 1 student student 1.0M Aug 19 11:55 înregistrare_lab03.mov
    -rw-r--r-- 1 student student 7.0M Aug 19 12:35 înregistrare_lab04.mov
    -rw-r--r-- 1 student student 9.1M Aug 19 17:56 înregistrări.tar
    -rw-r--r-- 1 student student 9.1M Aug 19 18:02 înregistrări.zip

.. note::
    Obervăm cum după comenzile de ștergere și dezarhivare s-a verificat corectitudinea operațiilor.

Puteți observa că am extras un singur fișier punând ca ultim parametru numele fișierului.


Exerciții - dezarhivarea unei arhive
""""""""""""""""""""""""""""""""""""

#. * Creați un director cu numele ``zip`` în directorului ``dezarhivare`` ca în ierarhia de mai sus; verificați crearea afișând conținutul directorului ``dezarhivare``.
   * Dezarhivați arhiva ``personal_data.zip`` în directorul ``dezarhivare/zip/``; verificați operația de dezarhivare afișând conținutul directorului.
   * Dezarhivați *doar* fișierul oraș natal în directorul curent; verificați operația afișând conținutul directorului curent.

#. * Creați directorul ``my_net`` în directorul ``dezarhivare`` ca în ierarhia de mai sus; verificați crearea afișând conținutul directorului ``dezarhivare``.
   * Dezarhivați arhiva ``net.zip`` în directorul creat anterior ``my_net``; verificați operația de dezarhivare afișând conținutul directorului.

Adăugarea de noi fișiere la arhive
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Putem adăuga un nou fișier la arhivă folosind comanda ``zip -u``:

.. code-block:: bash

    student@uso:~$ zip -u înregistrări.zip înregistrare_lab04.mov
      adding: înregistrare_lab04.mov (deflated 0%)
    student@uso:~$ zip -sf înregistrări.zip
    Archive contains:
      înregistrare_lab01.mov
      înregistrare_lab02.mov
      înregistrare_lab03.mov
      înregistrare_lab04.mov
    Total 4 entries (16777216 bytes)

.. note::
    Observăm cum după comanda de adăugare de fișier la arhivă, am verificat corectitudinea operației folosind comanda ``zip -sf``.

În exemplul de mai sus am adăugat ``înregistrare_lab04.mov`` la arhivă.

Exerciții - adăugarea unui fișier în arhivă
"""""""""""""""""""""""""""""""""""""""""""

* Creați un fișier **UPB** cu conținutul "Make UPB Great Again!";
* Verificați conținutul arhivei **personal_data.zip**;
* Adăugați fișierul **UPB** în arhivă;
* Verificați adăugarea fișierului la arhivă fără dezarhivare;
* Dezarhivați arhiva în directorul **personal_data_zip**.



.. [#] Metadatele sunt modalitatea sistemului de fișiere de a reține informații despre acesta: data creării, dimensiunea, utilizatorul ce deține fișierul, etc.






