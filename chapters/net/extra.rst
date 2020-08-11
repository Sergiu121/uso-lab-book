Funcţionalităţi suplimentare de reţelistică
===========================================

Aceste exerciții sunt menite să abordeze lucruri care nu sunt neapărat necesare
pentru utilizarea și înțelegerea conceptelor din acest capitol, dar oferă bune
practici și cunoștințe extra despre conectarea calculatorului la Internet și
funcționarea serviciilor în Internet.

Folosirea proxy-urilor HTTP
---------------------------

Din unele motive, anumite site-uri nu permit accesul utilizatorilor din unele
țări la ele. Asta se întâmplă din motive logistice, legislative (cu precădere
la politicile de colectare a datelor interzise în anumite țări) sau securitate.
Totuși noi ne dorim să accesăm aceste site-uri.

Până acum am explorat cum putem să apărem în Internet ca o stație care provine
dintr-o altă adresă folosind un VPN.

Proxy-ul HTTP este o alternativă a VPN care în loc să tuneleze tot traficul
în Internet, o va face doar pentru traficul HTTP. Putem să folosim un serviciu
online de proxy-ing.

TODO demo proxy

Evitarea elementelor de tip paywall
-----------------------------------

Ştergerea elementelor din pagina web
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Îi putem pune să se conecteze pe un site cu paywall şi să le arătăm cum să
scoată paywallul folosind inspect element şi să şteargă elementul din pagină ca
să vadă conţinutul. Aici putem folosi un site care oferă cărţi.

Instalarea add-on-urilor de tip paywall bypass
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Le arătăm că pot să îşi instaleze pluginuri ca să şteargă paywalluri de la
site-uri cum ar fi cele de research, sau ştiri.

Configurarea avansată pentru SSH
--------------------------------

Configurarea scurtăturilor SSH
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Aplicația SSH permite configurarea scurtăturilor pentru destinații la care vrem
să ne conectăm prin SSH.

Pentru a ne conecta în mod normal la stația <TODO>, ca utilizatorul <TODO>
folosind opțiunile <TODO> ar fi nevoie să rulăm comanda:

.. code-block::

    student@tom:~$ ssh -X user@statie

Tastarea acestei comenzi pentru fiecare conexiune succesivă este ineficientă și
există alternative pentru a reduce timpul de scriere al comenzii.

Vom configura o scurtătura pentru utilitarul ``ssh`` folosit de utilizatorul
``student``. Fișierul de configurare se regăsește la calea ``~/.ssh/config``, iar
acesta conține intrări de tipul următor:

.. code-block::

    student@tom:~$ cat ~/.ssh/config
    Host sw-fep
        HostName fep.grid.pub.ro
        User student
        ForwardX11 yes

Folosindu-ne de intrarea de mai sus, putem să ne conectăm la stația menționată
mai sus folosind comanda următoare:

.. code-block::

    student@tom:~$ ssh sw-fep
    TODO

EXERCIȚIU

Realizați configurările necesare astfel încât să va puteți conecta la stația
<TODO> ca utilizatorul <TODO>, folosind opțiunea de X forwarding cu scurtătura
<TODO>.

Configurarea accesului prin chei SSH
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

După cum am observat în secțiunea <TODO>, ca să ne copiem singuri cheia publică
pe o stație este necesar să cunoaștem parola utilizatorului drept care vrem să
ne autentificăm.

Însă există situații în care nu cunoaștem parola utilizatorului, dar avem acces
fizic sau printr-un protocol de comunicare la stație.

În această situație putem să configurăm cheia publică folosindu-ne de fișierele
de configurare ale serverului SSH.

Atunci când verifică cheile publice ale utilizatorilor care încearcă să se
autentifice, serverul SSH verifică identitatea clientului folosind cheile
private care sunt salvate în fișierul ``~/.ssh/authorized_keys``.


.. code-block::

    student@tom:~$ cat ~/.ssh/authorized_keys
    TODO

Pentru adăugarea unei alte chei SSH pentru verificarea identității clienților,
este suficient să scriem cheia SSH a utilizatorului pe o linie nouă a fișierului
``authorized_keys``.

EXERCIȚIU

Realizați configurările necesare astfel încât utilizatorul <TODO> să se poată
autentifica fără parola la stația <TODO>.

TODO infra

Gestiunea avansată a conexiunilor la rețea
------------------------------------------

Pentru a ușura configurarea conexiunii la Internet pentru utilizatorii Linux, a
fost adoptat ca serviciu standard pentru gestionarea conexiunilor la Internet
serviciul ``NetworkManager``. Acesta permite utilizatorilor să configureze din
mediul grafic parametrii de funcționare ai rețelei, cum ar fi serviciul DNS
folosit.

``NetworkManager`` oferă și funcționalități în linie de comandă, cu scopul de a
face mai ușoară depanarea problemelor de rețea. Utilitarul pe care îl vom
folosi se numește ``nmcli``, iar acesta ne oferă funcționalități pentru
gestionarea configurărilor.

Din punctul de vedere al serviciului ``NetworkManager``, există interfețe pe care
acesta le configurează și există conexiuni, care rețin configurările.

Configurarea conexiunilor folosind ``nmcli``
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Pentru interfețe conectate prin cablu exista doar o singură conexiune în mod
normal.

Pentru a vizualiza parametrii de funcționare ai unei conexiuni rulăm comanda:

.. code-block::

    student@tom:~$ nmcli connection show Wired\ connection
    TODO

Observăm că sunt afișate lucruri cum ar fi ruta implicită, adresa IP configurată
pe interfață, serverul de DNS folosit, și modul prin care a fost configurată
interfața (prin DHCP sau în mod static).

Pentru modificarea unui atribut al conexiunii folosim comanda ``nmcli`` în felul
următor:

.. code-block::

    student@tom:~$ nmcli connection modify Wired\ connection ipv4.dns 1.1.1.1
    TODO

Atributul ``ipv4.dns`` reține date despre DNS-ul care va fi folosit în cadrul
conexiunii.

EXERCIȚIU:

Faceți modificările necesare folosind comanda ``nmcli`` astfel încât conexiunea
``Wired Connection`` să folosească adresa IP sursă <TODO>

Conectarea la reţelele wireless
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

TODO, nu sunt sigur că pot face o infrastructură pentru asta
