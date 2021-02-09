.. _improve_cli_inspect_sys:

Inspectarea sistemului
======================

În cariera noastră o să ajungem des în situația în care o să folosim un sistem de operare pe care nu l-am instalat noi.
Trebuie să știm cum putem să inspectăm sistemul astfel încât să avem un minim de informații despre mașina și sistemul pe care lucrăm.

De regulă, suntem interesați de două categorii de informații:

#. Din punct de vedere al sistemului de operare, vrem să aflăm distribuția pe care rulăm (Ubuntu), versiunea distribuției (18.04) și versiunea de kernel a sistemului (4.15.0-118-generic).
   Vrem să știm dacă sistemul nostru are aplicate ultimele patch-uri de securitate sau nu.

#. Din punctul de vedere al specificațiilor hardware ale mașinii pe care rulăm suntem interasați să aflăm modelul și arhitectura procesorului pe care rulăm și cantitatea memoriei RAM de pe sistem.
   Vrem să știm dacă putem rula o anumită aplicație pe sistemul nostru sau nu.

Inspectarea sistemului de operare
---------------------------------

Afișarea informațiilor despre distribuție
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Pentru a afișa informații despre numele și versiunea distribuției avem două opțiuni:

#. Folosind utilitarul ``lsb_realease``:

   .. code-block:: bash

       student@uso:~$ lsb_release -a
       No LSB modules are available.
       Distributor ID: Ubuntu
       Description:    Ubuntu 18.04.5 LTS
       Release:        18.04
       Codename:       bionic

#. Afișând conținutul fișierului ``/etc/os-release``, folosind comanda ``cat``:

   .. code-block:: bash

       student@uso:~$ cat /etc/os-release
       NAME="Ubuntu"
       VERSION="18.04.5 LTS (Bionic Beaver)"
       ID=ubuntu
       ID_LIKE=debian
       PRETTY_NAME="Ubuntu 18.04.5 LTS"
       VERSION_ID="18.04"
       HOME_URL="https://www.ubuntu.com/"
       SUPPORT_URL="https://help.ubuntu.com/"
       BUG_REPORT_URL="https://bugs.launchpad.net/ubuntu/"
       PRIVACY_POLICY_URL="https://www.ubuntu.com/legal/terms-and-policies/privacy-policy"
       VERSION_CODENAME=bionic
       UBUNTU_CODENAME=bionic

Observăm că ambele metode produc rezultatul dorit: rulăm o distribuție Ubuntu, versiunea 18.04.

**Exercițiu:** Căutați pe Internet distribuția voastră și versiunea de kernel și vedeți dacă există patch-uri de securitate ce pot fi aplicate.

Afișarea informațiilor despre kernel
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

**Kernelul** (sau *core-ul*) unui sistem de operare intermediază interacțiunea dintre aplicațiile utilizatorului și componetele fizice (hardware) ale mașinii pe care rulează sistemul de operare.
Un sistem de operare este format din kernel peste care se adaugă aplicații și servicii: *mediu grafic (GUI)*, *file explorer*, *serviciu de ssh*, etc.

Aproape orice acțiune efectuată de utilizator va trece la un moment dat prin kernel.
Să luăm următorul scenariu: vrem să deschidem un fișier de pe disc.
O să deschidem aplicația de tip file explorer și o să dăm open pe un fișier.
Conținutul fișierului se află stocată fizic pe discul din calculator.
Aplicația din mediul grafic va face o cerere kernelului să îi ofere conținutul fișierului de pe discul fizic.

Aceelași lucru se întâmplă când navigăm pe o pagină pe internet: biții de date ajung pe placa de rețea din calculatorul nostru, apoi trec prin kernel și apoi ajung în aplicația de tip browser web pentru a ne afișa conținutul paginii.

Acesta este fluxul simplificat de acțiuni: utilizatorul cere ceva de la aplicație, aplicația de la sistemul de operare, sistemul de operare de la kernel, iar kernelul comunică cu componenta hardware pentru a satisface cererea.

Am făcut acest context pentru a evidenția:

#. Distincția dintre kernel și sistem de operare
#. Importanța kernelului
#. Importanța menținerii securității kernelului: dacă kernelul este compromis de un atacator, întreg sistemul este compromis.

Pentru a afișa versiunea de kernel folosită, folosim utilitarul ``uname``.

.. code-block:: bash

    student@uso:~$ uname -r
    4.15.0-118-generic

Folosind opțiunea ``-r``, ca în exemplul de mai sus, uname ne va afișa versiunea kernelului de Linux folosită de sistemul nostru.

**Exercițiu:** Rulați comanda ``uname -a``.
Folosiți pagina de manual (``man uname``) pentru a interpreta rezultatul comenzii.

Afișarea specificațiilor hardware ale mașinii
---------------------------------------------

Afișarea informațiilor despre procesor
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Pentru a afișa informații despre tipul și arhitectura procesorului pe care îl folosim avem două opțiuni:

#. Utilitarul ``lscpu``

   .. code-block:: bash

       student@uso:~$ lscpu
       Architecture:        x86_64
       CPU op-mode(s):      32-bit, 64-bit
       Byte Order:          Little Endian
       CPU(s):              2
       On-line CPU(s) list: 0,1
       Thread(s) per core:  1
       Core(s) per socket:  1
       Socket(s):           2
       NUMA node(s):        1
       Vendor ID:           GenuineIntel
       CPU family:          6
       Model:               78
       Model name:          Intel(R) Core(TM) i5-6200U CPU @ 2.30GHz
       Stepping:            3
       CPU MHz:             2400.000

#. Afișarea conținutului fișierului ``/proc/cpuinfo``

   .. code-block:: bash

       student@uso:~$ cat /proc/cpuinfo
       processor       : 0
       vendor_id       : GenuineIntel
       cpu family      : 6
       model           : 78
       model name      : Intel(R) Core(TM) i5-6200U CPU @ 2.30GHz
       stepping        : 3
       microcode       : 0xffffffff
       cpu MHz         : 2400.000
       cache size      : 3072 KB
       [...]

Observăm că ambele metode afișează aceeleași informații.
Pentru a afla dacă putem rula o aplicație, de interes pentru noi este arhitectura procesorului, care în exemplul de mai sus este **x86_64**.

Afișarea informațiilor despre memorie
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Pentru a afișa informații despre cantitatea de memorie instalată și memorie disponibilă putem folosi:

#. Utilitarul ``free``

   .. code-block:: bash

       student@uso:~$ free -h
                     total        used        free      shared  buff/cache   available
       Mem:           1,9G        853M        284M         17M        855M        951M
       Swap:          759M         27M        731M

    Opțiunea ``-h`` este folosită pentru a afișa cantitățile în mod human readable.

#. Afișarea conținutului fișierului ``/proc/meminfo``

   .. code-block:: bash

       student@uso:~$ cat /proc/meminfo
       MemTotal:        2041248 kB
       MemFree:          291528 kB
       MemAvailable:     973992 kB
       Buffers:           91052 kB
       Cached:           696336 kB
       SwapCached:         1344 kB
       Active:           972540 kB
       [...]

Utilitarul ``free`` parsează și afișază conținutul fișierului ``/proc/meminfo``.
Este de preferat utilizarea utilitarului deoarece putem folosi opțiunea ``-h``.

.. note::

    Informațiile aișate prin oricare din cele două metode reprezintă un snap shot al stării sistemului în momentul în care am executat una din cele două metode.
    Pentru a obține informații în mod interactiv putem folosi utilitarul ``top`` sau ``htop``.