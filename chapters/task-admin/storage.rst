.. _task_admin_storage:

Gestionarea spațiului de stocare partajat
=========================================

.. note::

    Pentru a parcurge această secțiune este recomandat să descărcați ultima versiune a respository-ului laboratorului.
    Pentru a descărca ultima versiune a repository-ului, rulați comanda ``git pull`` în directorul ``~/uso-lab/labs/10-tasks-admin/lab-containers/``.

    Infrastructura laboratorului este bazată pe containere Docker ale căror imagini vor fi generate pe propriul calculator.
    Dacă nu aveți deja instalat Docker Engine pe sistem, scriptul ``~/uso-lab/labs/10-tasks-admin/lab-containers/lab_prepare.sh`` vă va instala aplicația.

    După ce ați terminat de lucrat, vă recomandăm să opriți containerele rulând comanda ``./lab-prepare.sh delete`` în directorul ``~/uso-lab/labs/10-tasks-admin/lab-containers/``.

O componentă importantă a mediului de lucru este spațiul de stocare.
Cu toate că vom rula aplicații pe serverul de la distanță, avem nevoie de acces la spațiul de stocare al acestuia, deoarece vrem ca, într-un final, să urmărim rezultatul procesării și, eventual, să îl analizăm folosind utilitare grafice dedicate.
O altă nevoie pe care o avem este editarea codului la distanță, deoarece majoritatea programatorilor folosesc IDE-uri în mediu grafic, care nu pot rula mereu eficient de la distanță.
Soluția la această nevoie este să partajăm spațiul de stocare între serverul ``remote`` și stația ``local`` de pe care lucrăm.

.. _task_admin_storage_sshfs:

Stocare partajată folosind SSHFS
--------------------------------

.. note::

    Pentru rularea acestui demo, rulați în directorul ``~/uso.git/labs/03-user/lab-containers/`` comanda ``./lab_prepare.sh install remote`` și comanda ``./lab_prepare.sh install ssh-server``.
    Pentru a ne conecta la infrastructura pentru această secțiune, vom folosi comanda ``./lab_prepare.sh connect local``.

SSHFS este o soluție de stocare partajată care permite montarea unui sistem de fișiere care nu este legat fizic la stația ``local``, ci se folosește de protocolul SSH pentru a transmite operațiile asupra fișierelor prin rețea către un sistem de fișiere conectat prin rețea.

Avantajul folosirii SSHFS este că nu necesită descărcarea sistemului de fișiere de la distanță, deci nu duce la duplicarea fișierelor.
Dezavantajul acestei abordări este că dacă pierdem conexiunea la sistemul de fișiere de la distanță, nu mai avem acces la fișiere.

.. _task_admin_storage_sshfs_mount:

Montarea temporară a unui sistem de fișiere
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Pentru a monta sistemul de fișiere de pe un alt sistem, vom folosi comanda ``sshfs``

.. code-block::

    root@local:~# ls /mnt/

    root@local:~# sshfs root@10.11.11.2:/ /mnt/
    The authenticity of host '10.11.11.2 (10.11.11.2)' can't be established.
    ECDSA key fingerprint is SHA256:xV1orHYj4fhkc5HE91sfh8QhaVqke/AEMa8mYI423HY.
    Are you sure you want to continue connecting (yes/no)? yes
    root@10.11.11.2's password:

    root@local:~# df -h
    Filesystem         Size  Used Avail Use% Mounted on
    overlay             16G   14G  539M  97% /
    tmpfs               64M     0   64M   0% /dev
    tmpfs              2.0G     0  2.0G   0% /sys/fs/cgroup
    /dev/sda5           16G   14G  539M  97% /etc/hosts
    shm                 64M     0   64M   0% /dev/shm
    root@10.11.11.2:/   16G   14G  539M  97% /mnt

    root@local:~# ls /mnt/
    bin  boot  dev  etc  home  lib  lib64  media  mnt  opt  proc  root  run  sbin  srv  sys  tmp  usr  var

Comanda de mai sus a montat ierarhia de fișiere cu rădăcina în directorul ``/`` de pe sistemul de la adresa IP ``10.11.11.2`` în directorul ``/mnt`` de pe stația locală, cu numele ``local``, autentificându-se ca utilizatorul ``root``.

Am folosit comanda ``df`` pentru a afișa informații despre toate sistemele de fișiere montate pe stația locală.
Observăm că pe ultima linie apare conexiunea către stația de la adresa ``10.11.11.2``.

.. admonition:: Observație

    Sintaxa comenzii ``sshfs`` se aseamănă cu sintaxa comenzii ``scp``.

Acest mod de montare a sistemului de fișiere este temporară.
Atunci când vom opri stația, sistemul de fișiere va fi demontat.

.. _task_admin_storage_sshfs_mount_ex:

Exercițiu: Montarea temporară a unui sistem de fișiere
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#) Montați temporar sistemul de fișiere cu rădăcina în directorul ``/`` de pe stația ``10.11.11.2`` în directorul ``/mnt/vol1``.
#) Montați temporar sistemul de fișiere cu rădăcina în directorul ``/home/student`` de pe stația ``10.11.11.2`` în directorul ``/mnt/vol2``.

.. _task_admin_storage_sshfs_fstab:

Montarea persistentă a unui sistem de fișiere
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Deoarece nu ne dorim să rulăm comanda ``sshfs`` atunci când vrem să folosim un sistem de fișiere la distanță, vrem să montăm persistent sistemul de fișiere de la distanță, astfel încât această montare să persiste după oprirea stației locale.

Ca să montăm persistent sistemul de fișiere avem nevoie să copiem cheia SSH pe stația de la distanță, deoarece montarea se va face în mod neinteractiv, deci nu vom avea posibilitatea de a introduce parola. <TODO REF NETWORKING>

Pentru a monta persistent sistemul de fișiere, vom scrie o intrare în fișierul ``/etc/fstab``, care va conține detalii despre sistemul de fișiere pe care vrem să îl montăm.
Pentru a monta sistemul de fișiere ``/``` de pe sistemul de la adresa IP ``10.11.11.2`` în directorul ``/mnt`` de pe stația locală, autentificându-ne ca utilizatorul ``root``, vom folosi următoarele comenzi:

.. code-block::

    root@local:~# ssh-keygen
    [...]
    root@local:~# ssh-copy-id root@10.11.11.2
    [...]
    root@local:~# echo "root@10.11.11.2:/  /mnt  fuse.sshfs  defaults  0  0" >> /etc/fstab

    root@local:~# mount -a

    root@local:~# df -h
    Filesystem         Size  Used Avail Use% Mounted on
    overlay             16G   14G  539M  97% /
    tmpfs               64M     0   64M   0% /dev
    tmpfs              2.0G     0  2.0G   0% /sys/fs/cgroup
    /dev/sda5           16G   14G  539M  97% /etc/hosts
    shm                 64M     0   64M   0% /dev/shm
    root@10.11.11.2:/   16G   14G  539M  97% /mnt

Am scris în fișierul ``/etc/fstab`` folosind comanda ``echo``, iar pentru a monta sistemul de fișiere am folosit comanda ``mount`` cu opțiunea ``-a`` pentru montarea sistemelor de fișiere descrise în fișierul ``/etc/fstab``.

.. admonition:: Atenție!:

    În mod normal am scrie în fișierul ``/etc/fstab`` folosind un editor de text.
    Vă recomandăm să nu scrieți în fișiere critice sistemului folosind redirectări, deoarece orice greșeală poate șterge conținutul fișierului.

.. _task_admin_storage_sshfs_fstab_ex:

Exercițiu: Montarea persistentă a unui sistem de fișiere
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#) Montați persistent sistemul de fișiere cu rădăcina în directorul ``/`` de pe stația ``10.11.11.2`` în directorul ``/mnt/vol1``.
#) Montați persistent sistemul de fișiere cu rădăcina în directorul ``/home/student`` de pe stația ``10.11.11.2`` în directorul ``/mnt/vol2``.

.. _task_admin_storage_online:

Stocare partajată folosind aplicații online
-------------------------------------------

SSHFS nu este o soluție bună pentru a face backup fișierelor deoarece, existând o singură replică, ștergerea locală a unui fișier duce la ștergerea sa și de pe stația remote și, astfel, la pierderea sa.
Pe lângă aceasta, dacă stația locală are conexiune slabă la Internet, accesul la fișiere este greoi și neresponsiv.
Suplimentar, trebuie configurată o conexiune SSH, care poate necesita la rândul ei existența unui tunel etc.

O alternativă la folosirea SSHFS sunt soluții cum ar fi GoogleDrive, Dropbox, ownCloud sau One Drive.
Aceste soluții stochează o replică a fișierului pe toate calculatoarele autentificate de pe un anumit cont.
Un alt avantaj al acestora este că oferă suport pentru controlul versiunilor pentru a șterge modificarea anterioară.
Cu dezavantajul că trebuie configurate și cu riscul apariției conflictelor la modificări simultane pe noduri diferite.
Și cu dezavantajul că acum informația este duplicată: dublu spațiu ocupat și pot apărea conflicte la modificări.

.. _task_admin_storage_online_dropbox:

Stocarea partajată folosind Dropbox
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. note::

    Pentru rularea acestui demo vom folosi direct mașina virtuală ``uso``,

Dropbox este o soluție care se folosește de un server în Internet care stochează fișierele, ca apoi acestea să fie replicate pe fiecare calculator client.

Este necesară crearea și activarea un cont pentru a folosi serviciul Dropbox.

Dropbox oferă o aplicație care rulează în linie de comandă pe care o vom descărca pentru a sincroniza sistemul de fișiere de pe serverele Dropbox într-un director local.

Vom descărca aplicația Dropbox folosind comanda ``wget`` și o vom instala folosind comanda ``dpkg`` împreună cu parametrul ``-i``.

.. code-block::

    student@uso:~$ wget https://www.dropbox.com/download?dl=packages/ubuntu/dropbox_2020.03.04_amd64.deb -O dropbox.deb
    [...]
    student@uso:~$ sudo dpkg -i dropbox.deb 
    Starting Dropbox...
    Dropbox is the easiest way to share and store your files online. Want to learn more? Head to https://www.dropbox.com/

    In order to use Dropbox, you must download the proprietary daemon. [y/n] y
    [...]
    student@uso:~$ dropbox start
    To link this computer to a Dropbox account, visit the following url:
    https://www.dropbox.com/cli_link_nonce?nonce=ffd7d648a2ca2302d1177c0c389e87bd

.. admonition:: Observație

    Am folosit opțiunea ``-O`` a comenzii ``wget`` pentru a salva fișierul descărcat cu numele ``dropbox.deb``.

Pentru a instala ultimele componente ale clientului Dropbox este necesar să rulăm comanda ``dropbox start -i``.
După ce am ponit aplicația, este necesar să înregistrăm stația online la contul nostru.
Vom face acest lucru accesând linkul afișat de aplicație.

.. _task_admin_storage_online_dropbox_ex:

Exercițiu: Stocarea partajată folosind Dropbox
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. note::

    Pentru rezolvarea acestui exercițiu, rulați în directorul ``~/uso.git/labs/03-user/lab-containers/`` comanda ``./lab_prepare.sh install dropbox``.
    Pentru a ne conecta la infrastructura pentru această secțiune, vom folosi comanda ``./lab_prepare.sh connect dropbox``.
    Aplicația dropbox este deja descărcată, trebuie doar să o porniți.

#) Conectați-vă la stația ``dropbox`` și porniți aplicația Dropbox pe aceasta.

#) Creați un fișier numit ``hello.txt`` în directorul ``~/Dropbox``, partajat de cele două mașini.
   Scrieți în fișier mesajul ``Hello from remote`` pe stația ``dropbox``.
   Verificați că există fișierul ``hello.txt`` în directorul ``~/Dropbox`` pe stația ``uso``.

.. _task_admin_storage_online_private:

Extra: Stocarea partajată folosind un server privat
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Îi vom pune să instaleze un container cu ownCloud și să îl configureze astfel încât să îl folosească ca o alternativă la Dropbox.
