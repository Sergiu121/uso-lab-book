.. _app_install_app_list:

Investigarea aplicațiilor instalate
===================================

Având acces la un sistem de calcul, suntem interesați de ce aplicații rulează pe acesta și de versiunile acestor aplicații.
Acest lucru ne va ajuta să ne dăm seama ce aplicații să (mai) instalăm, sau dacă e nevoie de o actualizare a versiunilor.

Listarea aplicațiilor instalate
-------------------------------

Atunci când afișăm aplicațiile instalate, vedem dacă o aplicație este absentă din sistem; sau vedem care aplicații sunt instalate, pentru a replica instalarea pe un al sistem.

Dacă folosim ``apt`` pentru gestiunea pachetelor, folosim comanda de mai jos pentru afișarea pachetelor instalate:

.. code-block:: bash

    student@uso:~$ dpkg -l '*' | grep ^ii
    ii  accountsservice                            0.6.45-1ubuntu1                                  amd64        query and manipulate user account information
    ii  acl                                        2.2.52-3build1                                   amd64        Access control list utilities
    ii  acpi-support                               0.142                                            amd64        scripts for handling many ACPI events
    ii  acpid                                      1:2.0.28-1ubuntu1                                amd64        Advanced Configuration and Power Interface event daemon
    ii  adduser                                    3.116ubuntu1                                     all          add and remove users and groups
    ii  adium-theme-ubuntu                         0.3.4-0ubuntu4                                   all          Adium message style for Ubuntu
    ii  adwaita-icon-theme                         3.28.0-1ubuntu1                                  all          default icon theme of GNOME (small subset)
    ii  aisleriot                                  1:3.22.5-1                                       amd64        GNOME solitaire card game collection
    ii  alacarte                                   3.11.91-3                                        all          easy GNOME menu editing tool
    ii  alsa-base                                  1.0.25+dfsg-0ubuntu5                             all          ALSA driver configuration files
    [...]

Afișarea pachetelor o facem folosind comanda ``dpkg -l '*'``.
Această comandă afișează toate pachetele.
Ca să afișăm doar pachetele instalate, filtrăm rezultatul cu ajutorul comenzii ``grep ^ii``.

.. important::

    Același lucru îl putem obține folosind comanda ``apt list`` ca mai jos.
    Doar că e o comandă mai nouă, marcată în manual ca ``work-in-progress``; motiv pentru care, pe moment, preferăm folosirea comenzii ``dpkg -l`` ca mai sus.

    .. code-block:: bash

        student@uso:~$ apt list --installed
        Listing...
        accountsservice/bionic,now 0.6.45-1ubuntu1 amd64 [installed]
        acl/bionic,now 2.2.52-3build1 amd64 [installed]
        acpi-support/bionic,now 0.142 amd64 [installed]
        acpid/bionic,now 1:2.0.28-1ubuntu1 amd64 [installed]
        adduser/bionic,bionic,now 3.116ubuntu1 all [installed]
        adium-theme-ubuntu/bionic,bionic,now 0.3.4-0ubuntu4 all [installed]
        adwaita-icon-theme/bionic,bionic,now 3.28.0-1ubuntu1 all [installed]
        aisleriot/bionic,now 1:3.22.5-1 amd64 [installed]
        alacarte/bionic,bionic,now 3.11.91-3 all [installed,automatic]
        [...]

Pentru afișarea pachetelor Snap instalate, folosim comanda:

.. code-block:: bash

    student@uso:~$ snap list
    Name                  Version                     Rev   Tracking         Publisher   Notes
    core                  16-2.46.1                   9993  latest/stable    canonical✓  core
    core18                20200724                    1885  latest/stable    canonical✓  base
    gnome-3-26-1604       3.26.0.20200529             100   latest/stable/…  canonical✓  -
    gnome-3-28-1804       3.28.0-17-gde3d74c.de3d74c  128   latest/stable    canonical✓  -
    gnome-3-34-1804       0+git.3009fc7               36    latest/stable    canonical✓  -
    gnome-calculator      3.38.0+git7.c840c69c        826   latest/stable/…  canonical✓  -
    gnome-characters      v3.34.0+git9.eeab5f2        570   latest/stable/…  canonical✓  -
    gnome-logs            3.34.0                      100   latest/stable/…  canonical✓  -
    gnome-system-monitor  3.36.0-12-g35f88a56d7       148   latest/stable/…  canonical✓  -
    gtk-common-themes     0.1-36-gc75f853             1506  latest/stable/…  canonical✓  -
    [...]

Atât în cazul pachetelor ``apt`` cât și în cazul pachetelor Snap, atunci când pachetele sunt afișate, se afișează și versiunea fiecărui pachet.

Metadatele unei aplicații instalate
-----------------------------------

Când avem o aplicație instalată sau când dorim să o instalăm, ne interesează să știm informații despre acea aplicație: descriere, versiune, pachete de care depinde, ce fișiere sunt conținute, cât spațiu ocupă după instalare, aplicații similare.
Sistemul de gestiune a pachetelor ne oferă comenzi pentru acest lucru.

Astfel, pentru ``apt`` și Snap, avem comenzile de mai jos pentru fiecare tip de informație dorită:

* Pentru afișarea descrierii, versiunii, pachetelor dependente folosim comenzile, respectiv ``apt show`` și ``snap info``, urmate de numele pachetelui:

  .. code-block:: bash

      student@uso:~$ apt show firefox
      Package: firefox
      Version: 81.0+build2-0ubuntu0.18.04.1
      Priority: optional
      Section: web
      Origin: Ubuntu
      Maintainer: Ubuntu Mozilla Team <ubuntu-mozillateam@lists.ubuntu.com>
      Bugs: https://bugs.launchpad.net/ubuntu/+filebug
      Installed-Size: 216 MB
      Provides: gnome-www-browser, iceweasel, www-browser
      Depends: lsb-release, libatk1.0-0 (>= 1.12.4), libc6 (>= 2.27), libcairo-gobject2 (>= 1.10.0), libcairo2 (>= 1.10.0), libdbus-1-3 (>= 1.9.14), libdbus-glib-1-2 (>= 0.78), libfontconfig1 (>= 2.12), libfreetype6 (>= 2.3.5), libgcc1 (>= 1:3.3), libgdk-pixbuf2.0-0 (>= 2.22.0), libglib2.0-0 (>= 2.37.3), libgtk-3-0 (>= 3.4), libpango-1.0-0 (>= 1.22.0), libpangocairo-1.0-0 (>= 1.14.0), libpangoft2-1.0-0 (>= 1.14.0), libstdc++6 (>= 6), libx11-6, libx11-xcb1, libxcb-shm0, libxcb1, libxcomposite1 (>= 1:0.3-1), libxcursor1 (>> 1.1.2), libxdamage1 (>= 1:1.1), libxext6, libxfixes3, libxi6, libxrender1, libxt6
      Recommends: xul-ext-ubufox, libcanberra0, libdbusmenu-glib4, libdbusmenu-gtk3-4
      Suggests: fonts-lyx
      Replaces: kubuntu-firefox-installer
      Task: ubuntu-desktop, kubuntu-desktop, kubuntu-full, xubuntu-desktop, lubuntu-gtk-desktop, lubuntu-desktop, ubuntustudio-desktop, ubuntukylin-desktop, ubuntu-mate-core, ubuntu-mate-desktop
      Xul-Appid: {ec8030f7-c20a-464f-9b0e-13a3a9e97384}
      Supported: 5y
      Download-Size: 55.9 MB
      APT-Manual-Installed: yes
      APT-Sources: http://ro.archive.ubuntu.com/ubuntu bionic-updates/main amd64 Packages
      Description: Safe and easy web browser from Mozilla
       Firefox delivers safe, easy web browsing. A familiar user interface,
       enhanced security features including protection from online identity theft,
       and integrated search let you get the most out of the web.

      N: There is 1 additional record. Please use the '-a' switch to see it


      student@uso:~$ snap info pdftk
      name:      pdftk
      summary:   command-line tool for working with PDF files
      publisher: Scott Moser (smoser)
      store-url: https://snapcraft.io/pdftk
      contact:   smoser@brickies.net
      license:   unset
      description: |
        pdftk is a command-line tool for working with PDF files. It is commonly
        used for client-side scripting or server-side processing of PDF files.

        This snap is an unmodified Ubuntu 16.04 binary package that is
        re-packaged as a snap.

        More info at https://www.pdflabs.com/tools/pdftk-server/ .

        If you have issues with the snap, please feel free to file them at
         https://github.com/smoser/pdftk/issues
      snap-id: LTZvYybwMaNBk5uA3k1lN6ycmsAZq82i
      channels:
        latest/stable:    2.02-4 2018-09-05  (9) 18MB -
        latest/candidate: 2.02-4 2020-06-11 (23) 18MB -
        latest/beta:      2.02-4 2018-09-05  (9) 18MB -
        latest/edge:      2.02-4 2020-06-11 (23) 18MB -

  Mai sus, am afișat informații despre pachetul ``firefox`` instalabil cu ``apt``, respectiv pachetul ``pdftk`` instalabil cu Snap.
  Pachetele afișate nu trebuie să fie instalate; putem folosi comenzile ``apt show``, respectiv ``snap info`` fără a fi nevoie să instalăm pachetele.

* Pentru afișarea conținutului unui pachet instalat, folosim comenzile, respectiv, ``dpkg -L``, sau comanda de afișare a directorului ce conține fișierele Snap:

  .. code-block:: bash

      student@uso:~$ dpkg -L nmap
      /.
      /usr
      /usr/bin
      /usr/bin/ncat
      /usr/bin/nmap
      /usr/bin/nping
      /usr/share
      /usr/share/doc
      /usr/share/doc/nmap
      /usr/share/doc/nmap/3rd-party-licenses.txt.gz
      [...]

      student@uso:~$ tree /snap/pdftk/
      /snap/pdftk/
      |-- 9
      |   |-- command-pdftk.wrapper
      |   |-- lib
      |   |   `-- x86_64-linux-gnu
      |   |       |-- ld-2.23.so
      |   |       |-- ld-linux-x86-64.so.2 -> ld-2.23.so
      |   |       |-- libanl-2.23.so
      |   |       |-- libanl.so.1 -> libanl-2.23.so
      |   |       |-- libBrokenLocale-2.23.so
      [...]

  Mai sus, am afișat conținutul pachetului ``nmap``, instalat folosind ``apt``, respectiv conținutul pachetului ``pdftk``, instalat folosind Snap.
  Pentru pachetul ``pdftk`` (Snap) nu există comandă de instalare; urmărim conținutul directorului unde este instalat pachetul folosind Snap, adică ``/snap/pdftk/``.

* Pentru a replica instalarea pe un alt sistem, ne interesează să știm ce pachet conține un anumit fișier.
  Adică știm fișierul dorit, dar ne interesează ce pachet îl conține.

  În Snap, această informație se obține ușor: conținutul unui pachet este în directorul ``/snap/<nume_pachet>/``; având calea completă către un fișier, identificăm pachetul din numele subdirectorului din cale.

  În ``apt``, folosim comanda ``dpkg -S`` urmată de numele fișierului:

  .. code-block:: bash

      student@uso:~$ dpkg -S /bin/ls
      coreutils: /bin/ls
      student@uso:~$ dpkg -S /usr/include/stdio.h
      libc6-dev:amd64: /usr/include/stdio.h
      student@uso:~$ dpkg -S /etc/NetworkManager/NetworkManager.conf
      network-manager: /etc/NetworkManager/NetworkManager.conf

  Mai sus am identificat, respectiv, pachetele care conțin fișierele ``/bin/ls``, ``/usr/include/stdio.h`` și ``/etc/NetworkManager/NetworkManager.conf``.
  Adică pachetele ``coreutils``, ``libc6-dev:amd64`` și ``network-manager``.

Exerciții
^^^^^^^^^

#. Afișați versiunea, descrierea, dependențele și dimensiunea pachetelor ``hevea``, ``imagemagick``, ``ffmpeg``, ``vlc``.
   Sunt pachete ``apt``.
#. Afișați versiunea, descrierea și dimensiunea pachetelor ``rambox``, ``android-studio``, ``warzone2100``.
   Sunt pachete Snap.
#. Afișați conținutul pachetelor ``libreoffice-core``, ``firefox``, ``shutter``.
   Sunt pachete ``apt``.
#. Afișați pachetele ``apt`` care conțin, respectiv, fișierele ``/bin/ps``, ``/etc/hdparm.conf``, ``/usr/share/pixmaps/gvim.svg``.
