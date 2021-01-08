Conectarea la workstation
=========================

Prima problemă cu care ne vom confrunta este conectarea la stație, deoarece, în majoritatea cazurilor, nu vom lucra în aceeași rețea cu sistemul la distanță și stația nu va avea o adresă IP publică, astfel încât să ne putem conecta direct la sistem folosind un protocol de comunicare la distanță, cum ar fi SSH fără să facem pași extra.

Câteva soluții de conectare la sistem pe care le vom aborda sunt:
* VPN
* tunel SSH
* DDNS

<insert demo despre adrese private>

Conectarea prin VPN
-------------------

Prima soluție pentru conectarea la o stație din exterior o reprezintă serviciile de tip VPN.
Acestea conectează două stații care în mod fizic nu sunt conectate la aceeași rețea <TODO ref capitol rețea>

Pentru această soluție avem două moduri de organizare: folosind un server public pe care îl setăm noi drept server de VPN, sau folosirea unui serviciu public de VPN cum ar fi Hamachi sau ZeroTier.

Am folosit ca exemplu serviciile Hamachi sau ZeroTier, deoarece acestea pot fi
folosite fără să fie cumpărate și sunt ușor de configurat.

<insert matrice/link cu avantaje și dezavantaje servicii>

Folosirea serviciului Hamachi
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Pentru început, recomandăm folosirea serviciului Hamachi, deoarece acesta nu presupune înregistrarea unui cont pentru folosirea aplicației, dar Hamachi vine cu dezavantajul că putem să conectăm mai puține stații între ele și viteza conexiunii este mai mică decât dacă am folosii unele servicii plătite, cum ar fi OpenVPN, sau altele.

Instalarea Hamachi
""""""""""""""""""

Vom urmări instrucțiunile de aici:
https://support.logmeininc.com/central/help/how-to-install-the-client-to-a-local-computer-central-t-hamachi-add-attached-local

Crearea unei rețele private
"""""""""""""""""""""""""""

.. code-block::

    root@workstation:~$ sudo hamachi create nume-prenume 12345667890

Conectarea la o rețea
"""""""""""""""""""""

.. code-block::

    student@uso:~$ sudo hamachi join nume-prenume 12345667890

Folosirea unui VPN privat
^^^^^^^^^^^^^^^^^^^^^^^^^

Le vom da un reminder despre ce înseamnă un VPN privat, hostat de ei și îi vom trimite să vadă instrucțiunile de la laboratorul de networking pentru a își face setupul.

Conectarea folosind un tunel SSH
--------------------------------

Le vom lăsa instrucțiuni despre cum să facă un tunel printr-un server.
Problema aici e că nu știm dacă toți au acces la un server terț prin care să facă ssh.
Le putem arăta un demo didactic, iar la facultate pot să folosească fep, dar ceva practic pentru toți nu există.
