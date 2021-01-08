Gestionarea spațiului de stocare partajat
=========================================

O componentă importantă a mediului de lucru este spațiul de stocare.
Cu toate că noi vom rula aplicații pe serverul de la distanță, noi avem nevoie de acces la spațiul de stocare al acestuia, deoarece vrem ca într-un final să urmărim rezultatul procesării și eventual să îl analizăm folosind diferite utilitate grafice, cum ar fi aplicații de monitorizare, aplicații de generare de grafice.
O altă nevoie pe care o avem, dacă suntem programatori este editarea codului la distanță, deoarece majoritatea programatorilor folosesc IDE-uri în mediu grafic, care nu pot rula mereu eficient de la distanță.
Soluția la această nevoie este să partajăm spațiul de stocare între serverul de la distanță și laptopul sau stația locală de pe care lucrăm.

Stocare partajată folosind SSHFS
--------------------------------

Le vom face tutorial despre cum să monteze un sistem de fișiere folosind SSHFS și le vom explica că acest mod de lucru nu duce la duplicarea fișierelor.

Stocare partajată folosind aplicații online
-------------------------------------------

SSHFS nu este o soluție bună pentru a face backup fișierelor, deoarece existând o singură replică, ai șters un fișier și au dispărut toate replicile.Pe lângă asta, dacă ai Internet slab, ai acces greu la fișiere (le vrei și local). Și, pe lângă asta, trebuie să ai SSH configurat, care poate necesita tunel etc.

O alternativă pentru acest serviciu sunt soluții cum ar fi GoogleDrive, Dropbox, ownCloud sau OneDrive, care for stoca o replică a fișierului pe toate calculatoarele autentificate de pe un anumit cont.
Avantajul aici este că aceste sisteme oferă suport pentru controlul versiunilor pentru a șterge modificarea anterioară. Cu dezavantajul că trebuie configurate. Și cu dezavantajul că acum informația este duplicată: dublu spațiu ocupat și pot apărea conflicte la modificări.

Stocarea partajată folosind Dropbox
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Dropbox este o soluție care se folosește de un server în Internet care stochează fișierele noastre, ca apoi acestea să fie replicate pe fiecare calculator client.

Îi vom pune să instaleze Dropbox pentru a sincroniza fișierele de pe workstation și mașina locală.

Extra: Stocarea partajată folosind un server privat
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Îi vom pune să instaleze un container cu ownCloud și să îl configureze astfel încât să îl folosească ca o alternativă la Dropbox.
