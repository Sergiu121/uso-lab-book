Servicii și clienți de rețea
============================

Dispozitivele pe care le folosim noi devin din ce în ce mai mici, mai eficiente
și ieftine. Asta se întâmplă deoarece multe dintre aplicațiile care până nu de
curând rulau pe calculatorul propriu s-au mutat în spațiu online. De exemplu, în
loc să descărcăm filme și să le urmărim de pe calculator, folosim o aplicație
cum ar fi Netflix pentru a transmite prin Internet filmul pe care vrem să îl
urmărim. Un alt exemplu relevant este Google Drive, care ne permite să stocăm,
să replicăm și să edităm documente într-o interfață web, în loc să le păstrăm
local pe calculatorul pe care îl folosim. Toată puterea de procesare și tot
spațiul de stocare s-a mutat de pe calculatorul propriu pe servere aflate în
Internet.

Vom numi aceste aplicații care rulează în Internet servicii.

Un serviciu este o aplicație care oferă o funcționalitate utilizatorilor care
apelează la ele. Serviciile în domeniul calculatoarelor lucrează folosind
paradigma server-client. Un avantaj major al acestei abordări este că reduce
puterea de calcul necesară pentru rularea aplicațiilor de către utilizatori,
aceștia au nevoie doar de o aplicație client care știe să comunice cu serverul.
Astfel, aplicația client trimite o cerere către aplicația server, serverul
primește cererea, procesează cererea și servește răspunsul aplicației client
care a făcut cererea.

Această paradigmă poate fi observată în schema <TODO>.

CAPTION SCHEMĂ:

Atunci când noi vrem să urmărim un film pe Netflix aplicația client Netflix de
pe calculator sau telefon va trimite o cerere de descărcare a filmului de pe
serverul Netflix aflat la distanță.

Clienţi web în linia de comandă
--------------------------------

În viață de zi cu zi aplicația pe care o folosim cel mai mult este browserul
web, deoarece majoritatea aplicațiilor pe care le folosim au fost transformate
în pagini web cu care noi interacționăm. Browserul web este o aplicație care
execută o cerere HTTP către un server web, identificat printr-o adresă, un link,
prin care face o acțiune și primește un răspuns. De exemplu, când accesăm pagina
``www.facebook.com`` se execută o acțiune de tip GET, browserul primește ca
răspuns o pagină web, în formatul HTML, pe care o afișează.

Pentru interacțiunea cu serverele web putem folosi și clienți web în linie de
comandă. Clienții web folosiți în linie de comandă sunt folositori atunci când
nu avem acces la o interfață GUI, sau încercăm să automatizăm un proces. De
exemplu, pentru a verifica automat starea unui site avem nevoie să descărcăm
pagina site-ului.

Există mai multe implementări de clienți web în linie de comandă. Vom folosi
comanda ``wget`` pentru descărcarea unei pagini web.

.. code-block::

    student@uso:~$ wget <link>

EXERCIȚIU

Deschideți în browser pagina web descărcată pentru a vedea conținutul său.

EXERCIȚIU

Deschideți într-un editor de text pagina web descărcată pentru a vedea
conținutul HTML.

OBSERVAȚIE:

Clienții web nu sunt folosiți doar pentru accesarea paginilor web. Putem folosi
clienți web pentru a descărca fișiere indiferent de tipul acestora.

EXERCIȚIU 1:

Descărcați fișierul <insert link>.

Unele fișiere sunt pro
Descărcați fișierul <insert link>.

NOTĂ:

Observați că descărcarea nu funcționează, deoarece aceasta necesită
autentificarea utilizatorului.

HINT:

Căutați în pagina de manual a utilitarului ``wget`` (``man wget``), pentru a
identifica opțiunea necesară pentru autentificarea la un server HTTP. Pentru
autentificare veți folosi utilizatorul ``student`` și parola ``student``.

Accesul la distanţă în linie de comandă
---------------------------------------

În multe situații atunci când lucrăm cu sisteme, este necesar să rulăm aplicații
pe alte stații în afara calculatorului nostru fără să avem acces fizic la
stații.

Protocolul cel mai folosit pentru accesul la stații la distanță este protocolul
SSH. SSH permite autentificarea la o stație pe care rulează un server SSH.
Pentru a ne conecta la stație este necesar să introducem parola utilizatorului cu
care vrem să ne autentificăm, sau să folosim o cheie de acces la stație.

Conectarea folosind autentificare cu parolă
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Pentru a rula comenzi pe o altă stație putem folosi programul SSH (Secure Shell)
pentru a ne conecta la acesta în felul următor:

.. code-block::

    student@uso:~$ ssh <username>@<statie>

Unde <username> este numele utilizatorului și <stație> este adresa IP, sau
hostname-ul stației la care vrem să ne conectăm.

În mod implicit protocolul SSH va folosi autentificarea cu parolă.

EXERCIȚIU:

Autentificați-vă la stație <insert hostname> folosind utilizatorul <insert
utilizator> și parola <insert parolă>

OBSERVAȚIE:

Atunci când ne conectăm la o stație folosind protocolul SSH este necesar să
precizăm un nume de utilizator valid. Dacă utilizatorul nu există, serverul
nu va preciza faptul că utilizatorul nu există pe sistem, ci va cere parola
utilizatorului, dar nu va permite autentificarea la stație. De ce serverul SSH
nu specifică dacă utilizatorul exista sau nu.

Atunci când ne conectăm la o stație avem acces la un shell pe care putem să îl
folosim, dar dacă nu este necesar putem să rulăm mai multe comenzi, sau vrem să
automatizăm rularea comenzilor pe alte stații putem folosi comanda SSH în felul
următor:

.. code-block::

    student@uso:~$ ssh <username>@<statie> <comanda>

Rulați comanda <insert comanda> pe stațiile <insert stații> fără să intrați în
interfața în linia de comandă de pe stații.

Transferul fișierelor la distanţă
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Pentru a transfera fișiere la distanță să folosească ``scp``. Comanda ``scp``
se folosește de protocolul SSH pentru transferul de date între stații, astfel
ne putem folosi de modelul de autentificare de la SSH

.. code-block::

    student@uso:~$ scp file1 <username>@<stație>:~/file1
    TODO

OBSERVAȚIE:

Trimiterea fișierelor poate fi realizată în orice direcție:

* încărcarea fișierelor de la client la server

* descărcarea fișierelor de la server la client

Pentru descărcarea fișierelor de pe un server folosim comanda ``scp``:

.. code-block::

    student@uso:~$ scp <username>@<stație>:~/file1 .
    TODO

OBSERVAȚIE:

Comanda rulată anterior a descărcat fișierul ``file1`` din directorul home al
utilizatorului <user> de pe stația <stație> în directorul curent (``.``).

EXERCIȚIU:

Copiați fișierul ``/etc/passwd`` în directorul home al utilizatorului
``student``.

Pentru copierea unui director folosim opțiunea ``-r``:

.. code-block::

    student@uso:~$ scp <username>@<stație>:~/file1 .
    TODO

EXERCIȚIU:

Copiați directorul de pe stația TODO în directorul home al utilizatorului curent.

Conectarea folosind autentificare cu chei
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

În anumite scenarii ne dorim să evităm introducerea parolei pentru
autentificarea la o stație la distanță. De exemplu, ne dorim să rulăm aceeași
comandă pe 10 stații. Dacă am folosi autentificare bazată pe parolă fie ar fi
nevoie să scriem într-un fișier în clar parola, lucru care este o problema de
securitate, deoarece dacă păstrăm o cheie în format text aceasta poate fi furată
de cineva, sau să scriem parola de 10 ori de mână.

Pentru a trece de această problemă putem să folosim mecanismul de autentificare
cu chei. Autentificarea cu chei presupune existentă a două chei pereche:

* *cheia privată*: este o cheie secretă care este folosită de un client SSH
  pentru a se autentifica
* *cheia publică*, este o cheie care este copiată pe stația unde este rulat
  serverul SSH. Cheia este folosită pentru identificarea clienților SSH care se
  conectează la server.

Cele două chei sunt legate matematic, iar posesorul cheii private să se poată
autentifica pe orice sistem unde este disponibilă cheia publică. Câtă vreme
posesorul cheii private este singurul care are acces la cheie, nimeni nu se va
mai putea autentifica în locul său.

Pentru generarea unei perechi de chei folosim comanda ``ssh-keygen``:

.. code-block::

    student@uso:~$ ssh-keygen
    TODO

OBSERVAȚIE:

În procesul de generare a cheilor ni se cere și un passphrase
pentru a asigura securitatea cheii private în cazul în care este pierdută,
furată sau altcineva are acces accidental la ea. Desigur, uitarea
passphrase-ului face cheia nefolosibilă. Așa că passphrase-ul trebuie reținut
(și protejat) ca orice altă parolă.

Pentru copierea cheii publice pe o stație folosim comanda ``ssh-copy-id``:

.. code-block::

    student@uso:~$ ssh-copy-id <username>@<statie>
    TODO

Este necesar să cunoaștem parola utilizatorului pentru copierea cheii publice.

OBSERVAȚIE:

Atunci când copiem cheia publică aceasta va fi copiată pentru un singur
utilizator. Dacă vrem să ne autentificăm pe același calculator ca utilizatori
diferiți fără parola, este necesar să copiem cheia publică pentru fiecare
utilizator.

EXERCIȚIU:

Generați o nouă cheie SSH de tip RSA cu passphrase-ul ``mere``.

EXERCIȚIU:

Efectuați modificările necesare astfel încât să vă puteți autentifica drept
utilizatorul <TODO> de pe stația <host> fără parolă.

Conectarea între două calculatoare aflate în rețele private diferite
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

<TODO: de adăugat diagramă>

Pentru a demonstra principiul tunelării, ne vom folosi iar de netcat pentru a
realiza o conexiune între două stații. Ei se vor conecta la localhost:2222 și
vor accesa o altă mașină virtuală remote. Le vom arăta cum se face tunelul.


Controlul la distanță în mediul grafic
--------------------------------------

Există anumite tipuri de aplicații care funcționează în mod implicit în mediul
grafic și aceste aplicații nu pot fi rulate în interfața în linie de comandă. De
exemplu, installer-ul unui joc nu poate să fie rulat din linie de comandă.

Controlul aplicațiilor se poate reduce la două probleme:

* controlul întregului desktop;

* controlul unei singure aplicații.

Controlul desktopului la distanţă
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Pentru control complet al unei sesiuni desktop grafice există o multitudine de
soluții, cum ar fi VNC, sau FreeRDP, dar noi ne vom concentra pe soluția numită
TeamViewer, deoarece oferă suport pentru toate sistemele convenționale.

TeamViewer poate fi descărcat de la această adresă <TODO> și permite
autentificarea la o mașină folosind un ID și o parolă generate de aplicația
server.

TODO: Demo cu poze

EXERCIȚIU:

Porniți TeamViewer pe stația TODO și conectați-vă la stație de pe mașina voastră
fizică.

Controlul unei ferestre la distanţă
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Pentru controlul unei ferestre în Linux putem să folosim protocolul SSH pentru
transferul datelor care ar fi afișate pe stația pe care funcționează aplicația
grafică pe stația pe care este lansat clientul SSH.

Acest mod de transfer nu este rapid, deoarece transferul se face printr-un
protocol care nu este menit pentru aplicații care au nevoie să fie responsive,
cum sunt ferestrele interactive, dar pot fi folosite pentru aplicații cum ar fi
kituri de instalare ale programelor.

TODO: Demo cu poze

EXERCIȚIU:

Deschideți aplicația firefox ca utilizatorul <username> pe stația <hostname>.

Securizarea conexiunii la Internet folosind un VPN
--------------------------------------------------

O aplicație de tip VPN (Virtual Private Network) este o aplicație care permite
crearea rețelelor de calculatoare în Internet fără ca acestea să fie neapărat în
aceeași rețea fizică.

Funcționalitatea unui VPN este încapsularea datelor trimise de către un
calculator, criptarea și trimiterea lor către un server care le va trimite
mai departe către destinație.

Primul avantaj al folosirii unui VPN sunt "ascunderea" traficului între client,
adică stația de pe care se trimit datele și serverul VPN-ului. Astfel, acestea nu
mai pot fi văzute de alte entități până când ajung la server-ul VPN.

Al doilea avantaj al VPN-urilor este interconectarea facilă între calculatoare
care se află în rețele private diferite. De exemplu, pentru a juca un joc în
LAN, putem folosi un VPN, cum ar fi Hamachi, la care se conectează doi
utilizatori. Serverul de VPN va primi datele de la clienți și le va trimite
mai departe dintr-o rețea privată în alta.

<insert diagramă>

EXERCIȚIU:

Porniți infrastructura

EXERCIȚIU:

Identificați adresele IP ale celor două stații la care aveți acces.

EXERCIȚIU:

Verificați conectivitatea între cele doua stații.

OBSERVAȚIE:

Nu există conectivitate între cele două stații, deoarece acestea se află în
rețele private diferite.

Pentru a porni VPN-ul, vom folosi ``openvpn``. Rulați următoarea comandă pe ambele
stații pentru a porni clientul de VPN.

.. code-block::

    student@tom:~$ ip a s
    TODO

    student@jerry:~$ ip a s
    TODO

Observăm că a apărut o nouă interfață de rețea în sistem care nu are o componentă
fizică. Adresa IP setată pe această interfață este adresa care identifică
stațiile în rețeaua VPN-ului. Observați că ambele adrese de pe interfețele
<TODO> sunt foarte similare. Asta înseamnă că cele două stații sunt acum în
aceeași rețea virtuală

Testați conectivitatea de pe stația <TODO> cu stația de la adresa <TODO>.

Pentru a verifica că drumul pachetului chiar trece prin VPN, rulăm comanda
``traceroute 8.8.8.8`` și observăm că mesajele spre Internet nu mai trec prin
interfața eth0 ci trec prin interfața virtuală, ajung la serverul VPN în pasul
<TODO>, iar abia apoi sunt lansate mai departe spre Internet.

.. code-block::

    student@tom:~$ traceroute 8.8.8.8

Astfel, un pachet care se va îndrepta spre o destinație, poate să depășească
anumite filtre bazate pe locație, deoarece locația de unde provine pachetul va
fi înlocuită de serverul VPN.
