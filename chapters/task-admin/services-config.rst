.. _task_admin_services_config:

Configurarea și administrarea serviciilor
=========================================

Scopul serviciilor este să ruleze în continuu și să primească cereri de la aplicații client, cum ar fi un client SSH, și să răspundă la aceste cereri.
Serviciile sunt aplicații care rulează în continuu pe stație, spre deosebire de comenzi, cum ar fi ``find`` sau ``ls``, care rulează cât timp se execută comanda.
Deoarece ne dorim să avem majoritatea timpului conectivitate la mașină, sau ne dorim să avem acces la paginile web folosite, serverele rulează fără oprire și servesc cereri venite de la clienți.
Un sever / serviciu este oprit explicit de utilizator prin comenzi specifice sau este oprit la oprirea sistemului.
Fără o intervenție explicită și fără oprirea sistemului, un server / serviciu va rula nedefinit.

Vrem să pornim și să configurăm servicii instalate în sistem, precum:

* un server web;

* un server SSH, pentru a ne conecta la stație;

* un serviciu care ține un tunel SSH deschis către stație

Avem nevoie de o interfață unică, cu o sintaxă minimală, care ne permite să gestionăm serviciile pe sistem, și care ne permite sa generăm noi propriile servicii.

.. _task_admin_services_config_usage:

Lucrul cu serviciile în Linux
-----------------------------

Comanda folosită pentru gestionarea serviciilor este ``systemctl``.
Aceasta se regăsește pe majoritatea distribuțiilor moderne de Linux.

.. _task_admin_services_config_usage_status:

Verificarea stării unui serviciu
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Atunci când instalăm o aplicație care rulează sub forma unui serviciu, vom putea să îi verificăm starea folosind comanda ``systemctl status``.

.. code-block::

    student@uso:~$ systemctl status ssh
    ● ssh.service - OpenBSD Secure Shell server
         Loaded: loaded (/lib/systemd/system/ssh.service; enabled; vendor preset: enabled)
         Active: active (running) since Sat 2021-01-09 04:22:11 EET; 1min 17s ago
           Docs: man:sshd(8)
                 man:sshd_config(5)
        Process: 639 ExecStartPre=/usr/sbin/sshd -t (code=exited, status=0/SUCCESS)
       Main PID: 657 (sshd)
          Tasks: 1 (limit: 4656)
         Memory: 4.8M
         CGroup: /system.slice/ssh.service
                 └─657 sshd: /usr/sbin/sshd -D [listener] 0 of 10-100 startups

    ian 09 04:22:11 uso systemd[1]: Starting OpenBSD Secure Shell server...
    ian 09 04:22:11 uso sshd[657]: Server listening on 0.0.0.0 port 22.
    ian 09 04:22:11 uso sshd[657]: Server listening on :: port 22.
    ian 09 04:22:11 uso systemd[1]: Started OpenBSD Secure Shell server.
    ian 09 04:23:25 uso sshd[1821]: Accepted password for student from 192.168.56.1 port 33714 ssh2
    ian 09 04:23:25 uso sshd[1821]: pam_unix(sshd:session): session opened for user student by (uid=0)

Mai sus am afișat starea serviciului SSH.
Observăm că acesta este activ și putem urmări ce procese a generat și ce mesaje de diagnosticare afișează.

Programul ``systemd`` se ocupă de pornirea, oprirea și gestionarea serviciilor folosite în sistem pe baza unor fișiere numite fișiere unitate.
Fișierul care gestionează serviciul SSH este ``/lib/systemd/system/ssh.service``.
Îl putem identifica din rezultatul comenzii ``systemctl status``.

Atunci când un serviciu este instalat, acesta vine la pachet cu fișierul cu extensia ``.service`` cu care acesta va fi gestionat de ``systemd``, după cum putem vedea în rezultatul comenzii de mai jos:

.. code-block::

    student@uso:~$ sudo apt install ntp
    [...]
    Setting up ntp (1:4.2.8p12+dfsg-3ubuntu4) ...
    Created symlink /etc/systemd/system/network-pre.target.wants/ntp-systemd-netif.path → /lib/systemd/system/ntp-systemd-netif.path.
    Created symlink /etc/systemd/system/multi-user.target.wants/ntp.service → /lib/systemd/system/ntp.service.
    ntp-systemd-netif.service is a disabled or a static unit, not starting it.
    [...]

.. addmonition:: Observație

    Serviciul ``ntp`` este folosit pentru sincronizarea ceasului cu surse precise de timp din Internet.
    Acesta este un serviciu important pentru buna funcționare a aplicațiilor în Internet, deoarece o configurare a timpului pentru o stație poate duce la o funcționare incorectă a acesteia în comunicare.

.. _task_admin_services_config_usage_status_ex:

Exercițiu: Afișarea stării serviciilor
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Afișați starea serviciului ``thermald``, care gestionează senzorii de temperatură ai sistemului.

.. _task_admin_services_config_usage_stop:

Oprirea unui serviciu
^^^^^^^^^^^^^^^^^^^^^

Pentru a opri un serviciu vom folosi comanda ``systemctl stop`` în felul următor:

.. code-block::

    student@uso:~$ sudo netstat -tlpn
    [sudo] password for student: 
    Active Internet connections (only servers)
    Proto Recv-Q Send-Q Local Address           Foreign Address         State       PID/Program name    
    tcp        0      0 127.0.0.53:53           0.0.0.0:*               LISTEN      501/systemd-resolve 
    tcp        0      0 0.0.0.0:22              0.0.0.0:*               LISTEN      4425/sshd: /usr/sbi 
    tcp        0      0 127.0.0.1:631           0.0.0.0:*               LISTEN      541/cupsd           
    tcp6       0      0 :::22                   :::*                    LISTEN      4425/sshd: /usr/sbi 
    tcp6       0      0 ::1:631                 :::*                    LISTEN      541/cupsd           
    student@uso:~$ sudo systemctl stop ssh
    [sudo] password for student:
    student@uso:~$ sudo systemctl status ssh
    ● ssh.service - OpenBSD Secure Shell server
         Loaded: loaded (/lib/systemd/system/ssh.service; enabled; vendor preset: e>
         Active: inactive (dead) since Sat 2021-01-09 04:58:28 EET; 9s ago
           Docs: man:sshd(8)
                 man:sshd_config(5)
        Process: 640 ExecStartPre=/usr/sbin/sshd -t (code=exited, status=0/SUCCESS)
        Process: 660 ExecStart=/usr/sbin/sshd -D $SSHD_OPTS (code=exited, status=0/>
       Main PID: 660 (code=exited, status=0/SUCCESS)

    ian 09 04:57:29 uso systemd[1]: Starting OpenBSD Secure Shell server...
    ian 09 04:57:29 uso sshd[660]: Server listening on 0.0.0.0 port 22.
    ian 09 04:57:29 uso sshd[660]: Server listening on :: port 22.
    ian 09 04:57:29 uso systemd[1]: Started OpenBSD Secure Shell server.
    ian 09 04:58:28 uso sshd[660]: Received signal 15; terminating.
    ian 09 04:58:28 uso systemd[1]: Stopping OpenBSD Secure Shell server...
    ian 09 04:58:28 uso systemd[1]: ssh.service: Succeeded.
    ian 09 04:58:28 uso systemd[1]: Stopped OpenBSD Secure Shell server.

Pentru a verifica dacă mai funcționează serviciul SSH vom folosi comanda ``netstat`` pentru a verifica dacă mai ascultă serverul SSH pe portul ``22``.

.. code-block::

    student@uso:~$ sudo netstat -tlpn
    Active Internet connections (only servers)
    Proto Recv-Q Send-Q Local Address           Foreign Address         State       PID/Program name
    tcp        0      0 127.0.0.53:53           0.0.0.0:*               LISTEN      501/systemd-resolve
    tcp        0      0 127.0.0.1:631           0.0.0.0:*               LISTEN      541/cupsd
    tcp6       0      0 ::1:631                 :::*                    LISTEN      541/cupsd

Observăm că nu ascultă niciun program pe portul ``22``.

Recapitulare: Afișarea stării serviciilor
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Afișați starea serviciului ``ssh``.

.. _task_admin_services_config_usage_start:

Pornirea unui serviciu
^^^^^^^^^^^^^^^^^^^^^^

Pornirea unui serviciu se face folosind comanda ``systemctl start`` în felul următor:

.. code-block::

    student@uso:~$ systemctl start ssh
    student@uso:~$ systemctl status ssh
    ● ssh.service - OpenBSD Secure Shell server
         Loaded: loaded (/lib/systemd/system/ssh.service; enabled; vendor preset: enabled)
         Active: active (running) since Sat 2021-01-09 05:05:30 EET; 2min 30s ago
           Docs: man:sshd(8)
                 man:sshd_config(5)
        Process: 4408 ExecStartPre=/usr/sbin/sshd -t (code=exited, status=0/SUCCESS)
       Main PID: 4425 (sshd)
          Tasks: 1 (limit: 4656)
         Memory: 3.4M
         CGroup: /system.slice/ssh.service
                 └─4425 sshd: /usr/sbin/sshd -D [listener] 0 of 10-100 startups

    ian 09 05:05:30 uso systemd[1]: Starting OpenBSD Secure Shell server...
    ian 09 05:05:30 uso sshd[4425]: Server listening on 0.0.0.0 port 22.
    ian 09 05:05:30 uso sshd[4425]: Server listening on :: port 22.
    ian 09 05:05:30 uso systemd[1]: Started OpenBSD Secure Shell server.
    ian 09 05:05:54 uso sshd[4477]: Accepted password for student from 192.168.56.1 port 34852 ssh2
    ian 09 05:05:54 uso sshd[4477]: pam_unix(sshd:session): session opened for user student by (uid=0)

Dacă serviciul nu pornește cu succes, aceasta va afișa un mesaj de avertizare.

.. _task_admin_services_config_usage_restart:

Repornirea unui serviciu
^^^^^^^^^^^^^^^^^^^^^^^^

Pe parcursul rulării serviciilor pe un sistem, vom dori să schimbăm configurația unui serviciu sau să adăugăm parametri de rulare în plus.
Majoritatea aplicațiilor citesc fișierele de configurare o singură dată, atunci când sunt pornite, deci orice modificare ulterioară a fișierelor de configurare nu va fi sesizată de serviciu.
Din acest motiv, avem nevoie să repornim servicii.

De exemplu, vrem să permitem utilizatorilor să se autentifice ca utilizatorul ``root`` pe sistemul nostru.
Acest lucru este dezactivat în mod predefinit de serviciu din motive de securitate.

.. code-block::

    student@uso:~$ ssh root@localhost
    root@localhost's password: 
    Permission denied, please try again.
    [...]

Observăm că inițial nu puteam să ne conectăm la mașina locală ca utilizatorul ``root``, cu toate că introduceam parola corectă.

.. code-block::

    student@uso:~$ sudo su -c 'echo "PermitRootLogin yes" >> /etc/ssh/sshd_config'
    student@uso:~$ systemctl restart ssh
    student@uso:~$ ssh root@localhost
    root@localhost's password:
    [...]
    root@uso:~#

Pentru a face acest lucru, avem nevoie să reconfigurăm serviciul SSH.
Odată ce am adăugat opțiunea ``PermitRootLogin yes`` în fișierul de configurare al serviciului și am repornit serviciului, am reușit să ne autentificăm ca utilizatorul ``root``.

.. _task_admin_services_config_usage_enable:

Pornirea unui serviciu la startup
"""""""""""""""""""""""""""""""""

Atunci când configurăm un sistem și vrem să definim servicii care rulează pe el, ne dorim ca serviciile să fie ``setup and forget``, să nu fie necesar să le supraveghem și să le monitorizăm prea mult.
Un mod de a ne ușura lucrul cu serverul este pornirea serviciilor la startup, ca să nu fie nevoie sa intervenim noi după secvența de pornire a sistemului, ca să le pornim de mână, folosind comanda ``systemctl start``

Putem să vedem dacă un sistem pornește automat la startup din rezultatul comenzii ``systemctl status`` pe linia care începe cu ``Loaded:``.
Dacă rezultatul conține șirul de caractere ``enabled``, atunci serviciul pornește la startup, iar dacă aceasta conține șirul ``disabled``, atunci serviciul nu va porni la startup.

Pentru a dezactiva un serviciu la startup vom folosi comanda ``systemctl disable`` în felul următor:

.. code-block::

    student@uso:~$ sudo systemctl disable ntp
    Synchronizing state of ntp.service with SysV service script with /lib/systemd/systemd-sysv-install.
    Executing: /lib/systemd/systemd-sysv-install disable ntp
    Removed /etc/systemd/system/multi-user.target.wants/ntp.service.
    student@uso:~$ sudo systemctl status ntp
        ● ntp.service - Network Time Service
         Loaded: loaded (/lib/systemd/system/ntp.service; disabled; vendor preset: enabled)
         Active: active (running) since Sat 2021-01-09 05:18:49 EET; 27min ago
           Docs: man:ntpd(8)
       Main PID: 9756 (ntpd)
          Tasks: 2 (limit: 4656)
         Memory: 1.3M
         CGroup: /system.slice/ntp.service
                 └─9756 /usr/sbin/ntpd -p /var/run/ntpd.pid -g -u 127:134

    ian 09 05:18:55 uso ntpd[9756]: Soliciting pool server 185.173.16.132
    ian 09 05:24:31 uso ntpd[9756]: kernel reports TIME_ERROR: 0x2041: Clock Unsynchronized
    ian 09 05:28:41 uso ntpd[9756]: 91.189.91.157 local addr 10.0.2.15 -> <null>
    ian 09 05:29:00 uso ntpd[9756]: 85.204.240.2 local addr 10.0.2.15 -> <null>
    ian 09 05:29:04 uso ntpd[9756]: 188.213.49.35 local addr 10.0.2.15 -> <null>
    ian 09 05:29:05 uso ntpd[9756]: 86.124.75.41 local addr 10.0.2.15 -> <null>
    ian 09 05:29:08 uso ntpd[9756]: 85.204.240.1 local addr 10.0.2.15 -> <null>
    ian 09 05:29:09 uso ntpd[9756]: 195.135.194.3 local addr 10.0.2.15 -> <null>
    ian 09 05:29:52 uso ntpd[9756]: 91.189.89.198 local addr 10.0.2.15 -> <null>
    ian 09 05:38:03 uso ntpd[9756]: 93.190.144.28 local addr 10.0.2.15 -> <null>

Observăm că pe linia care conține șirul de caractere ``Loaded``, mesajul este ``disabled``, dar serviciul funcționează în continuare.

Pentru a activa un serviciu la startup vom folosi comanda ``systemctl enable``:

.. code-block::

    student@uso:~$ sudo systemctl enable ntp
    Synchronizing state of ntp.service with SysV service script with /lib/systemd/systemd-sysv-install.
    Executing: /lib/systemd/systemd-sysv-install enable ntp
    Created symlink /etc/systemd/system/multi-user.target.wants/ntp.service → /lib/systemd/system/ntp.service.
    student@uso:~$ sudo systemctl status ntp
    ● ntp.service - Network Time Service
         Loaded: loaded (/lib/systemd/system/ntp.service; enabled; vendor preset: enabled)
         Active: active (running) since Sat 2021-01-09 05:18:49 EET; 30min ago
           Docs: man:ntpd(8)
       Main PID: 9756 (ntpd)
          Tasks: 2 (limit: 4656)
         Memory: 1.3M
         CGroup: /system.slice/ntp.service
                 └─9756 /usr/sbin/ntpd -p /var/run/ntpd.pid -g -u 127:134

    ian 09 05:18:55 uso ntpd[9756]: Soliciting pool server 185.173.16.132
    ian 09 05:24:31 uso ntpd[9756]: kernel reports TIME_ERROR: 0x2041: Clock Unsynchronized
    ian 09 05:28:41 uso ntpd[9756]: 91.189.91.157 local addr 10.0.2.15 -> <null>
    ian 09 05:29:00 uso ntpd[9756]: 85.204.240.2 local addr 10.0.2.15 -> <null>
    ian 09 05:29:04 uso ntpd[9756]: 188.213.49.35 local addr 10.0.2.15 -> <null>
    ian 09 05:29:05 uso ntpd[9756]: 86.124.75.41 local addr 10.0.2.15 -> <null>
    ian 09 05:29:08 uso ntpd[9756]: 85.204.240.1 local addr 10.0.2.15 -> <null>
    ian 09 05:29:09 uso ntpd[9756]: 195.135.194.3 local addr 10.0.2.15 -> <null>
    ian 09 05:29:52 uso ntpd[9756]: 91.189.89.198 local addr 10.0.2.15 -> <null>
    ian 09 05:38:03 uso ntpd[9756]: 93.190.144.28 local addr 10.0.2.15 -> <null>

Observăm că pe linia care conține șirul de caractere ``Loaded``, mesajul s-a schimbat în ``enabled``.

.. _task_admin_services_config_config:

Configurarea unui serviciu
^^^^^^^^^^^^^^^^^^^^^^^^^^

În majoritatea cazurilor, serviciile sunt configurate prin fișiere de configurare.
Acestea se pot găsi în mai multe locuri:

* ``/etc/default/``, unde sunt fișiere care permit modificarea opțiunilor de rulare a unei comenzi, ca și cum am adăuga noi opțiuni la rularea unei comenzi.
  Aceste fișiere sunt citite de ``systemd``, înainte să pornească serviciul;
* directorul ``/etc/nume_serviciu/`` , unde se află fișierele de configurare sau direct fișierul ``/etc/nume_serviciu``.
  Aceste fișiere sunt citite și interpretate de servici.
  De exemplu, pentru configurarea serviciului NTP, există fișierul ``/etc/ntp.conf``, iar pentru configurarea serviciului SSH folosim fișierele din directorul ``/etc/ssh/``.

.. _task_admin_services_config_ex:

Exerciții: Gestiunea serviciilor
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#) Configurați serviciul SSH pentru a permite autentificarea ca utilizatorul ``root`` folosind numai autentificare bazată pe chei.

#) Instalați serviciul ``vsftpd``. Acesta este un serviciu de transfer de fișiere.

    #) Realizați modificările necesare astfel încât acest serviciu să **NU** pornească la startup;

    #) Dezactivați funcționalitatea bazată pe IPv6 a serviciului. **Hint**: ``listen_ipv6``, ``listen``.

    #) Asigurați-vă că serviciul rulează.
       Acest serviciu ascultă pe portul ``21``.

.. _task_admin_services_config_custom:

Definirea unui serviciu personalizat
------------------------------------

Atunci când vrem să ne conectăm la Internet printr-un proxy, avem nevoie ca proxy-ul să fie deschis în permanență și să redeschidă conexiunea în cazul în care aceasta este întreruptă.
Putem să facem acest lucru folosind servicii ``systemd`` pe care să le gestionăm noi folosind suita de comenzi ``systemctl``.

Ne propunem să găzduim propriul proxy care va trimite mesaje criptate prin SSH către o altă stație, de unde vor fi trimise mesaje în Internet.
Astfel vom putea trece peste anumite filtre care țin cont de poziția geografică.

Un serviciu în ``systemd`` se definește printr-un fișier de configurare în directorul ``/lib/systemd/system/libvirtd.service``.
Pentru serviciul nostru vom genera fișierul la calea ``/lib/systemd/system/libvirtd.service/auto-proxy.service``.
Acest fișier va avea următorul conținut:

.. code-block::

    [Unit]
    Description=Keeps a proxy to 'fep.grid.pub.ro' open
    After=network-online.target ssh.service

    [Service]
    User=student
    ExecStart=/usr/bin/ssh -D 1337 -q -C -N <username-acs>@fep.grid.pub.ro
    ExecStop=/usr/bin/pkill -f '/usr/bin/ssh -D 1337 -q -C -N'
    KillMode=process
    Type=simple
    Restart=always
    RestartSec=10

    [Install]
    WantedBy=multi-user.target

Acesta este un șablon pe care putem să îl folosim pentru multe tipuri de servicii. Opțiunile relevante pentru înțelegerea formatului sunt:

* ``ExecStart``, comanda care se va executa pentru a porni serviciul;
* ``ExecStop``, comanda care se va executa pentru a opri serviciul

.. addmonition:: Atenție

    Pentru ca acest serviciu să funcționeze, este necesar să copiați cheia stației ``uso`` pe mașina ``fep.grid.pub.ro``.

Putem să verificăm dacă a pornit proxy-ul verificând dacă ascultă vreun serviciu pe mașina locală pe portul ``1337``:

.. code-block::

    student@uso:~$ sudo netstat -tlpn
    Active Internet connections (only servers)
    Proto Recv-Q Send-Q Local Address           Foreign Address         State       PID/Program name    
    tcp        0      0 127.0.0.1:1337          0.0.0.0:*               LISTEN      32177/ssh           
    tcp        0      0 0.0.0.0:21              0.0.0.0:*               LISTEN      15794/vsftpd        
    tcp        0      0 127.0.0.53:53           0.0.0.0:*               LISTEN      7088/systemd-resolv 
    tcp        0      0 0.0.0.0:22              0.0.0.0:*               LISTEN      10459/sshd: /usr/sb 
    tcp        0      0 127.0.0.1:631           0.0.0.0:*               LISTEN      541/cupsd           
    tcp6       0      0 ::1:1337                :::*                    LISTEN      32177/ssh           
    tcp6       0      0 :::22                   :::*                    LISTEN      10459/sshd: /usr/sb 
    tcp6       0      0 ::1:631                 :::*                    LISTEN      541/cupsd           

.. _task_admin_services_config_custom_ex:

Exercițiu: Definirea unui serviciu personalizat
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Realizați configurația necesară astfel încât să creați un tunel deschis permanent de pe stația ``uso``, care primește mesaje din portul ``4242`` al stației de la adresa ``10.10.10.3`` și le trimite către portul ``22`` al mașinii locale.
