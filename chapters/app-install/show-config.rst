.. _app_install_view_config:

Vizualizarea configurației sistemului
=====================================

Un sistem de operare are preinstalate și preconfigurate aplicații.
Utilizatorul va dori să adauge noi aplicații pentru nevoile sale, extinzând funcționalitățile de bază ale sistemului de operare.
Înainte de a adăuga noi aplicații, utilizatorul va trebui să știe ce sistem de operare are, ce distribuție, ce versiune de distribuție, ce versiune de sistem de operare.
Fără aceste informații, nu va ști ce utilitare să folosească pentru gestiunea aplicațiilor, nu va ști ce aplicații sunt disponibile, nu va ști unde sunt plasate fișierele de configurare.

În general utilizatorul va fi preocupat să afle:

* Ce sistem de operare rulează pe sistemul de calcul? (Windows, Linux, macOS, FreeBSD, Android, iOS etc.)
* Ce versiune a acestui sistem de operare rulează? (Windows 7, Windows 10, iOS 13, iOS 14 etc.)
  În Linux întrebarea este: Ce distribuție de Linux rulează (și ce versiune a sa)? (Ubuntu 18.04, Debian 10, Fedora 29 etc.)
* Ce arhitectură de procesor are sistemul de calcul? (x86, ARM, MIPS, PowerPC etc.)

Determinarea sistemului de operare
----------------------------------

Sistemul de operare este determinat, în general, din interfața grafică, din particularitățile sale: formatul iconurilor, a barelor, aplicații prezente.

În linia de comandă, diferența poate fi văzută prin mesajele afișate la promptul de login.
Promptul de login afișează, în general, sistemul de operare și versiunea sa.

În Linux, promptul de login este dat de conținutul fișierului ``/etc/issue`` care afișează distribuția și versiunea ei:

.. code-block:: bash

    student@uso:~$ cat /etc/issue
    Ubuntu 18.04.1 LTS \n \l

Dacă promptul nu este prezent, sau dacă nu este afișată informația, se folosesc comenzi sau fișiere specifice pentru aflarea sistemului de operare.

Altfel, aflarea sistemului de operare / distribuției și versiunii se poate face prin accesarea site-ului https://whatsmyos.com/.

Determinarea distribuției
-------------------------

Pentru a determina distribuția Linux care rulează în sistem (și versiunea acesteia), putem folosi fișierul ``/etc/issue`` așa cum am precizat mai sus.
Alternativ, urmărim conținutul fișierului ``/etc/os-release``:

.. code-block:: bash

    student@uso:~$ cat /etc/os-release
    NAME="Ubuntu"
    VERSION="18.04.1 LTS (Bionic Beaver)"
    ID=ubuntu
    ID_LIKE=debian
    PRETTY_NAME="Ubuntu 18.04.1 LTS"
    VERSION_ID="18.04"
    HOME_URL="https://www.ubuntu.com/"
    SUPPORT_URL="https://help.ubuntu.com/"
    BUG_REPORT_URL="https://bugs.launchpad.net/ubuntu/"
    PRIVACY_POLICY_URL="https://www.ubuntu.com/legal/terms-and-policies/privacy-policy"
    VERSION_CODENAME=bionic
    UBUNTU_CODENAME=bionic

În rezultatul de mai sus observăm că distribuția folosită este ``Ubuntu`` versiunea ``18.04`` (``Bionic Beaver``).

Un alt mod este folosirea comenzii ``lsb_release`` cu opțiunea ``-a``:

.. code-block:: bash

    student@uso:~$ lsb_release -a
    No LSB modules are available.
    Distributor ID:	Ubuntu
    Description:	Ubuntu 18.04.1 LTS
    Release:	18.04
    Codename:	bionic

sau consultarea fișierului ``/etc/lsb-release``:

.. code-block:: bash

    student@uso:~$ cat /etc/lsb-release
    DISTRIB_ID=Ubuntu
    DISTRIB_RELEASE=18.04
    DISTRIB_CODENAME=bionic
    DISTRIB_DESCRIPTION="Ubuntu 18.04.1 LTS"

La fel ca mai sus, observăm că distribuția folosită este ``Ubuntu`` versiunea ``18.04`` [#release]_.

Aflarea versiunii nucleului
---------------------------

În Linux, anumite aplicații au nevoie de o anumită versiune a nucleului sistemului de operare (*kernel*).
În general, atunci când parcurgem cerințele unei aplicații, vom întâlni o precizare de forma ``required: Linux kernel >= 3.2``, adică este nevoie de o versiune de nucleu mai mare decât versiunea ``3.2``.
Pentru a afla această versiune și, astfel, pentru a valida că aplicația poate fi instalată, putem investiga fișierul ``/proc/version``:

.. code-block:: bash

    student@uso:~$ cat /proc/version
    Linux version 4.15.0-115-generic (buildd@lgw01-amd64-037) (gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04)) #116-Ubuntu SMP Wed Aug 26 14:04:49 UTC 2020

sau putem folosi comanda ``uname`` cu opțiunea ``-a``:

.. code-block:: bash

    student@uso:~$ uname -a
    Linux uso 4.15.0-115-generic #116-Ubuntu SMP Wed Aug 26 14:04:49 UTC 2020 x86_64 x86_64 x86_64 GNU/Linux

În ambele cazuri, observăm că versiunea nucleului este ``4.15.0``.
Dacă cerința ar fi fost să avem o versiune de nucleu mai mare decât versiunea ``3.2``, atunci această cerință ar fi îndeplinită.

Aflarea arhitecturii procesorului
---------------------------------

Sistemele desktop / laptop folosesc, în zilele noastre, procesoare cu arhitectură x86 / x86_64.
Sistemele de tip smartphone sau alte dispozitive folosesc arhitectură ARM.
Pot exista și alte arhitecturi de procesor precum MIPS sau PowerPC.
Utilizatorul este, în general, nepreocupat de arhitectură, rareori având nevoie să știe acest lucru pentru o nevoie anume.
Dacă, totuși, dorim să aflăm arhitectura procesorului sistemului, putem folosi comanda ``arch``:

.. code-block:: bash

    student@uso:~$ arch
    x86_64

Vedem în rezultatul comenzii că arhitectura procesorului/procesoarelor sistemului este ``x86_64``, arhitectura clasică pe sisteme desktop / laptop.

O altă comandă pentru aflarea arhitecturii procesorului sistemului, folosită și pentru a afla informații detaliate despre procesor, este ``lscpu``:

.. code-block:: bash

    student@uso:~$ lscpu
    Architecture:        x86_64
    CPU op-mode(s):      32-bit, 64-bit
    Byte Order:          Little Endian
    CPU(s):              1
    On-line CPU(s) list: 0
    Thread(s) per core:  1
    Core(s) per socket:  1
    [...]

La fel ca în cazul comenzii ``arch``, observăm ca arhitectura procesorului/procesoarelor sistemului este ``x86_64``.


.. rubric:: Note de subsol

.. [#release]

     Distribuțiile Linux pot avea fișiere (și comenzi) specifice pentru afișarea informațiilor despre distribuția folosită, precum cele de `aici <http://linuxmafia.com/faq/Admin/release-files.html>`_.
