Programarea rulării acțiunilor
==============================

Un workstation, ca oricare alt calculator, necesită mentenanță, cum ar fi crearea de copii de rezervă pentru fișierele importante, sau ștergerea anumitor fișiere jurnal care devin prea mari.
Toate aceste acțiuni sunt acțiuni fixe, repetitive, care nu necesită atenția utilizatorului.
Din acest motiv, putem spune că automatizăm aceste acțiuni astfel încât acestea să ruleze programat la un anumit interval.

Rularea amânată a unei aplicații
--------------------------------

Le vom arăta cum să folosească at ca să programeze o acțiune care poate să
ruleze la un anumit timp o singură dată (care va rula chiar și după un shutdown)

Rularea programată a unei aplicații
-----------------------------------

Le vom arăta ce face cron și le vom explica despre fișierele din /etc/cron.{daily, monthly, hourly, weekly}.

Formatarea acțiunilor amânabile
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Pentru formatare vom folosi fișierele /etc/cron.d/

Realizarea automată a copiilor de rezervă
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Îi vom pune să își facă copii de rezervă fișierelor de configurare din /etc într-un director partajat prin Dropbox.
