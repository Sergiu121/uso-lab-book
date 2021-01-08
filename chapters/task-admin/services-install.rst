Instalarea aplicațiilor (serviciilor) folosind Docker
=====================================================

Scopul acestui capitol este să îi introducem pe studenți în instalarea, folosirea containerelor și în instalarea serviciilor folosind containerele.

Instalarea serviciilor nu este o operație ușoară.
Acestea depind de aplicații și biblioteci care uneori nu sunt disponibile, sau nu există versiunile necesare pentru distribuția noastră.
O altă problemă vine de la faptul că serviciile nu sunt de tipul "plug-and-play", adică nu oferă o configurație simplă care să permită rularea serviciului imediat după instalarea aplicației.

Docker vine ca o soluție pentru această problemă, deoarece acesta ne oferă servicii pre-împachetate cu dependențele pe care le are serviciul respectiv și cu configurările necesare pentru rularea serviciului.
Un alt avantaj al folosirii Docker este că mediul oferit de Docker este unul izolat și efemer, adică o aplicație care rulează în Docker nu are acces în mod obișnuit la restul sistemului, iar orice modificare asupra sistemului de fișiere din Docker nu se va reflecta asupra sistemului.

Folosirea Docker
----------------

În această subsecțiune studenții vor învăța cum să folosească Docker ca să pornească un container, cum să descarce un container, cum să se conecteze la un container.
Nu punem accentul pe crearea containerelor ci pe folosirea lor.

Gestionarea containerelor
^^^^^^^^^^^^^^^^^^^^^^^^^

În această sub-subsecțiune vom prezenta cum să descarce și cum să pornească un container care oferă o pagină web simplă, ca apoi să oprească containerul.

Conectarea la un container
^^^^^^^^^^^^^^^^^^^^^^^^^^

În această sub-subsecțiune vor învăța cum să se conecteze la containerul de la secțiunea anterioară și vor modifica pagina web afișată.

Instalarea serviciilor folosind Docker
--------------------------------------

Cum am prezentat mai devreme, un avantaj al folosirii containerelor este faptul că putem să descărcăm containere care pot rula servicii.
Aceste servicii nu vor mai fi lansate și gestionate de aplicația systemd care rulează pe stația de lucru, deoarece acestea vor rula în cadrul unui container care va gestiona rularea serviciului.
Noi trebuie doar să ne asigurăm ca rulăm containerul folosind opțiunile potrivite.

Identificarea containerelor pe Dockerhub
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Precum aplicațiile obișnuite, și containerele Docker pot fi descărcate dintr-un repository central.
Repository-ul central pentru containere este Dockerhub.
Noi vom folosi site-ul Dockerhub pentru a căuta containere împreună cu instrucțiuni de folosire ale acestora.

Instalarea unui server de minecraft folosind containere
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Își vor instala un server de Minecraft pe PC, pe care îl vor testa folosind TLauncher (nu știu cât de legal e asta, TBD).

Instalarea Grafana folosind containere
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Își vor instala un server de grafana și baza de date pentru acesta.

Extra: Instalarea containerelor personalizate
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Studenții vor descărca un Dockerfile și vor face build acestuia în loc să descarce direct containerul despre net.

Le vom arăta cum să modifice Dockerfile-ul ca să instaleze diverse aplicații.
