Conectarea la rețea și la Internet
==================================

Pentru identificarea și repararea problemelor de conectivitate la rețea (sau,
mai pe scurt, rezolvarea problemei "nu-mi merge Internetul") este necesar să
parcurgem toate nivelurile de rețea prin care trec datele pentru a fi trimise.
În continuare vom prezenta pașii pe care îi urmăm ca să verificăm verificăm
funcționalitatea nivelului de rețea și cum putem să îl configurăm sumar.

Interacţiunea cu nivelul fizic
------------------------------

Primul nivel cu care noi interacționăm este nivelul fizic. Nivelul fizic este
reprezentat de cablul UTP pentru o rețea cu fir <insert poză>, sau de undele
radio ale unei rețele wireless. Acestea sunt mediul prin care informația este
transferată.

O altă componentă a nivelului fizic este placa de rețea a sistemului. Aceasta
va trimite mesaje prin mediu de transmisie, fie acesta cablu de cupru, fibră sau
unde radio.

Majoritatea timpului problemele de conexiune la Internet vin de la faptul că nu
este cablul de Internet la placa de rețea, sau de la faptul că avem conexiune
slabă la rețeaua wireless.

La nivel fizic, putem verifica conexiunea și funcționalitatea unei plăci de
rețea uitându-ne la ledurile care reprezintă conexiunea la mediul fizic.
Observăm în GIF-ul <TODO> cum arată ledurile unei plăci de rețea funcționale.
Dacă acestea nu sunt aprinse, atunci nu vom avea conectivitate la rețea.

Investigarea nivelului fizic al rețelei
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

NOTĂ

În general, în Linux asociem fiecărei interfețe de rețea o placă de rețea.

La nivelul sistemului de operare putem verifica dacă o placă de rețea este
activă folosind comanda următoare:

.. code-block::

    student@uso:~$ ip link show
    1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN mode DEFAULT group default qlen 1000
        link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    2: eno2: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc fq_codel state DOWN mode DEFAULT group default qlen 1000
        link/ether c8:f7:50:78:a1:a7 brd ff:ff:ff:ff:ff:ff
    3: wlo1: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc noqueue state UP mode DORMANT group default qlen 1000
        link/ether a0:51:0b:68:3d:55 brd ff:ff:ff:ff:ff:ff

Starea fiecărei interfețe de rețea este reprezentată pe câte o linie împreună cu
parametrii săi de rulate. Majoritatea informațiilor afișate de comanda de mai
sus nu relevante pentru noi. Singurul șir de caractere care ne este ``state``,
urmat de starea interfeței de rețea, care poate să fie ``UP``, ``DOWN`` sau
``UNKNOWN``.

Observăm că interfața de rețea cu numele ``wlo1`` este pornită, deoarece linia
asociată interfeței conține șirul de caractere ``state UP``. În
același timp observăm că interfața de rețea ``eno2`` nu este activă deoarece pe
linia sa observăm șirul de caractere ``state DOWN``.

Pentru a porni interfața ``eno2`` vom folosi următoarea comandă:

.. code-block::

    student@uso:~$ ip link set up dev eno2

Mereu după ce rulăm o comandă trebuie să verificăm că s-a efectuat comanda cu
succes folosind o comandă de verificare. În cazul de față vom folosi tot
comanda ``ip link show``:

.. code-block::

    student@uso:~$ ip link show
    1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN mode DEFAULT group default qlen 1000
        link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
    2: eno2: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc fq_codel state DOWN mode DEFAULT group default qlen 1000
        link/ether c8:f7:50:78:a1:a7 brd ff:ff:ff:ff:ff:ff
    3: wlo1: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc noqueue state UP mode DORMANT group default qlen 1000
        link/ether a0:51:0b:68:3d:55 brd ff:ff:ff:ff:ff:ff

Configurarea reţelei în mediul grafic
-------------------------------------

Le vom arăta cum să se conecteze la o rețea folosind interfaţa vizuală a unui
Desktop Environment, probabil GNOME

Configurarea nivelului Internet
-------------------------------

Identificarea adresei de Internet
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Pentru comunicare între două stații din Internet, trebuie ca cele două stații să
fie conectate la Internet. Și apoi cele două stații să se poată adresa una
alteia. Adică fiecare stație are nevoie de un identificator, o adresă.

Pentru identificarea stațiilor folosim o adresă numită adresa IP (Internet
Protocol). Fiecare interfață de rețea are nevoie de o adresă IP să fie
configurată.

Pentru a vedea adresele IP configurate pe interfețele de rețea folosim
următoarea comandă:

.. code-block::

    student@uso:~$ ip address show
    1: lo: <LOOPBACK,UP,LOWER_UP> mtu 65536 qdisc noqueue state UNKNOWN group default qlen 1000
        link/loopback 00:00:00:00:00:00 brd 00:00:00:00:00:00
        inet 127.0.0.1/8 scope host lo
           valid_lft forever preferred_lft forever
        inet6 ::1/128 scope host 
           valid_lft forever preferred_lft forever
    2: eno2: <NO-CARRIER,BROADCAST,MULTICAST,UP> mtu 1500 qdisc fq_codel state DOWN group default qlen 1000
        link/ether c8:f7:50:78:a1:a7 brd ff:ff:ff:ff:ff:ff
    3: wlo1: <BROADCAST,MULTICAST,UP,LOWER_UP> mtu 1500 qdisc noqueue state UP group default qlen 1000
        link/ether a0:51:0b:68:3d:55 brd ff:ff:ff:ff:ff:ff
        inet 192.168.1.103/24 brd 192.168.1.255 scope global dynamic noprefixroute wlo1
           valid_lft 6478sec preferred_lft 6478sec
        inet6 fe80::3849:c687:463f:5508/64 scope link noprefixroute 
           valid_lft forever preferred_lft forever

Adresele IP ale interfețelor sunt scrise pe liniile care conțin ``inet``.
Observăm că există două tipuri de adrese IP, în funcție de parametrul ``inet``:

* Adrese IPv4 care sunt de forma ``A.B.C.D``, unde A, B, C și D sunt numere cu
  valori între 1 si 255;

* Adrese IPv6, care sunt de forma ``A:B:C:D:E:F:G:H``, unde A-H sunt numere în
  format hexazecimal care pot lua valori de la ``0x0000" la ``0xFFFF``.

Configurarea unei adrese IP
^^^^^^^^^^^^^^^^^^^^^^^^^^^

RECAPITULARE:

Faceți modificările necesare astfel încât interfața ``eno2`` să fie în starea
``UP``.

Există două metode pentru configurarea unei adrese IP pe o interfață:

* configurare statică, prin care noi configurăm manual adresa IP pe interfață de
  rețea, implică să cunoaștem din ce rețea face parte interfața
  pe care vrem să o configurăm și ce adrese IP sunt libere;

* configurare dinamică, obținută automat, care nu presupune cunoașterea
  informațiilor despre rețea, deoarece acestea vor fi primite automat de pe
  rețea.

Vom insista pe configurarea dinamică, deoarece este mai simplă. În plus,nu avem
cum să aflam informațiile despre rețea înainte de a configura interfața de
rețea.

Pentru a obține dinamic o adresă IP în mod dinamic pe o interfață
folosim comanda ``dhclient``:

.. code-block::

    student@uso:~$ dhclient eno2

Mai sus am rulat comanda pentru a obține o adresă IP pentru interfața ``eno2``.

Comanda ``dhclient`` este bazată pe protocolul DHCP (Dynamic Host Configuration
Protocol). Acesta presupune că există un server pe rețea care cunoaște ce IP-uri
sunt folosite pe rețea și care poate să ofere adrese IP calculatoarelor care fac
cereri pe rețea. ``dhclient`` face o cerere de rezervare a unui IP către
serverul DHCP de pe rețea.

TASK DE RECAPITULARE:

Afișați adresele IP de pe toate interfețele.

Observați că am obținut o adresă IP pe interfața ``eno2``.

Pentru șterge o adresă IP de pe o interfața folosim comanda ``ip address flush`` în felul următor:

.. code-block::

    student@uso:~$ ip address flush eno2
    student@uso:~$ ip address show
    <TODO>

TASK DE RECAPITULARE:

Configurați adresa IP pe interfața ``eno3``.


Verificarea conectivității la o altă stație
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Pentru a verifica conexiunea dintre două stații folosim comanda ``ping``. Această
comandă trimite mesaje către o stație și așteaptă un răspuns de la ea.

Atunci când testăm conexiunea la internet, vrem să verificăm câteva aspecte,
odată ce am obținut o adresă IP de la serverul DHCP:

* verificăm dacă putem să ne conectăm la alte calculatoare din aceeași rețea

* verificăm dacă putem să comunicăm cu stații din afara rețelei

De exemplu, dacă vrem să verificăm conectivitatea la serverul ``8.8.8.8`` (un
server public din Internet), folosim comanda:

.. code-block::

    student@uso:~$ ping 8.8.8.8
    <TODO>

Atunci când nu pot fi trimise mesaje către stația identificată prin adresa IP,
mesajul de eroare va arăta în felul următor:

.. code-block::

    student@uso:~$ ping <TODO>
    <TODO>

Pentru verificarea conectivității în interiorul rețelei trebuie să verificăm că
putem să trimitem mesaje folosind ping unui calculator din rețea.

O țintă bună de testare pentru trimiterea mesajelor în rețea este (default)
gateway-ul. Un gateway este un dispozitiv de rețea care se ocupă de
interconectarea rețelelor și care primește mesaje de la toate stațiile din
rețea pentru a le trimite în Internet.

Gateway-ul este configurat static sau dinamic, cum este configurată și adresa IP a unei interfețe.

Pentru a identifica gateway-ul folosim comanda ``ip route show`` în felul următor:

.. code-block::

    student@uso:~$ ip route show default
    <TODO>

Observăm că adresa IP a gateway-ului este <TODO>.

RECAPITULARE:

Aflați adresa de rețea de pe interfața <TODO>.

OBSERVAȚIE:

După cum putem să observăm, adresa IP a gateway-ului și adresa IP a interfeței
<TODO> sunt foarte similare. Asta se întâmplă deoarece stațiile se află în
aceeași rețea.

EXERCIȚIU:

Verificați conexiunea cu gateway-ul folosind comanda ``ping``.

Pentru verificarea conexiunii la Internet este bine să verificăm cu o adresă
consacrată, care avem încredere că nu va avea probleme tehnice. Un astfel de
exemplu este server-ul oferit de Google de la adresa IP ``4.4.4.4``.

EXERCIȚIU:

Verificați conexiunea la server-ul ``8.8.8.8`` oferit de Google folosind comanda
``ping``.

Investigarea serviciului DNS
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

După cum ați observat, până acum am lucrat numai cu adrese IP, dar noi lucrăm
în viața de zi cu zi cu numele site-urilor, deoarece ne este mai ușor să
reținem nume decât adrese IP.

Pentru a rezolva această necesitate folosim serviciul DNS. Acesta este oferit de
un server către care noi trimitem cereri de ``lookup`` pentru o adresa
``hostname`` cum ar fi ``www.google.com``. Serverul DSN va răspunde cu adresa IP
asociată cu adresa cerută.

Ne dorim să avem un serviciu DNS funcțional în permanență pe sistemul pe care lucrăm.

În mod implicit serviciul DNS este configurat prin DHCP.

.. code-block::

    student@uso:~$ nmcli dev show | grep DNS
    <TODO>

RECAPITULARE:

Afișați adresa IP a gateway-ului.

OBSERVAȚIE:

Observați că adresa gateway-ului este aceeași cu adresa DNS-ului. De obicei
gateway-ul este configurat ca server DNS, iar acesta va trimite cererile
mai departe către un alt server DNS.

Pentru a verifica funcționalitatea serviciului DNS, putem să facem o cerere DNS
folosind comanda ``host`` în felul următor.

.. code-block::

    student@uso:~$ host google.com
    <TODO>

Cererile DNS nu trebuie să fie făcute direct de noi atunci când încercăm să
accesăm o resursă din Internet folosind un nume, deoarece aplicațiile fac cereri
în mod implicit.

EXEMPLU:

.. code-block::

    student@uso:~$ ping google.com
    <TODO>

Observați că aplicația ping a aflat de una singură care este adresa IP asociată
numelui ``google.com`` și a făcut cererea în fundal.

În caz că vrem să schimbăm temporar DNS-ul pe care îl folosim trebuie să
modificăm fișierul ``/etc/resolv.conf``. Acest fișier specifică DNS-ul care va fi
folosit pentru cereri pe linia care conține cuvântul nameserver, după cum
puteți vedea mai jos.

.. code-block::

    student@uso:~$ cat /etc/resolv.conf
    <TODO>

Dacă schimbăm adresa DNS-ului cu altă adresă, cum ar fi cea a DNS-ului oferit
de Google, putem să vedem o schimbare în răspunsurile de la serverul DNS.


.. code-block::

    student@uso:~$ dig google.com
    <modificăm /etc/resolv.conf>
    student@uso:~$ cat /etc/resolv.conf
    <TODO>
    student@uso:~$ dig google.com
    <TODO>

ATENȚIE:

Acestea sunt modificări temporare folosite pentru depanarea problemelor cu
serviciul DNS.

EXERCIȚIU:

Realizați modificările necesare astfel încât cererile de tip DNS să fie trimise
către serverul de DNS oferit de CloudFlare de la adresa ``1.1.1.1``.

Configurarea nivelului Transport
--------------------------------

Atunci când folosim Internetul ce facem de fapt este că ne conectăm la
aplicații care rulează și noi pornim la rândul nostru aplicații care așteaptă
conexiuni din exterior.

Pentru a distinge aplicațiile și destinația mesajelor, folosim conceptul de
porturi. Astfel, fiecare aplicație deschide un port pentru a comunica cu exteriorul.

Portul este o adresă locală unei stații. Dacă adresa IP identifică stația,
portul identifică aplicația de rețea de pe stație. Astfel putem avea mai multe
aplicații rețea pe o stație.

Există două tipuri de porturi care pot fi deschise, în funcție de protocolul folosit:

* porturi TCP, folosite de aplicații care depind de trimiterea corectă și în
  ordine a informației, cum ar fi servere web;

* porturi UDP, folosite de aplicații care trebuie să trimită informație repede
  și care sunt rezistente la greșeli de trimitere ale pachetelor, cum ar fi
  aplicații de video streaming

Conectivitatea între aplicații de rețea folosind porturi
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Pentru afișarea porturilor deschide, pe care comunica o aplicație, folosim comanda `netstat`:

.. code-block::

    student@uso:~$ netstat -tlpn
    <TODO>

OBSERVAȚIE:

Pentru comanda de mai sus folosim următoarele opțiuni pentru filtrarea afișării:

* `-t` afișează doar porturile TCP deschise

* `-l` afișează doar porturile deschise care ascultă mesaje, nu și cele deschide pentru trimiterea mesajelor

* `-p` afișează programul care a deschis portul

* `-n` afișează IP-ul pe care se ascultă după conexiuni

EXERCIȚIU:

Afișați porturile UDP deschise pe stația pe care lucrați.

După cum observăm, există un server HTTP care rulează pe mașină și ascultă pe portul TCP 80.

Conectarea TCP la o aplicație
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Vrem să observăm cum răspunde serverul HTTP la mesaje. De regula un server HTTP răspunde printr-un mesaj în format HTML.

Pentru a trimite mesaje, indiferent de tipul aplicației care primește mesajul folosim comanda `nc` în felul următor

.. code-block::

    student@uso:~$ nc 127.0.0.1 80
    lala
    HTTP/1.1 400 Bad Request
    Server: nginx/1.18.0
    Date: Tue, 01 Sep 2020 21:46:35 GMT
    Content-Type: text/html
    Content-Length: 157
    Connection: close
    
    <html>
    <head><title>400 Bad Request</title></head>
    <body>
    <center><h1>400 Bad Request</h1></center>
    <hr><center>nginx/1.18.0</center>
    </body>
    </html>

OBSERVAȚI:

Mesajul primit este un răspuns de tipul "Bad Request", deoarece am trimis un
mesaj care nu este în formatul așteptat de serverul HTTP.

EXERCIȚIU:

Trimiteți un mesaj către programul care ascultă pe portul 8080 pe mașina locală
(cu IP-ul 127.0.0.1).
