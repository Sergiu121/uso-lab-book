.. _app_install_install_uninstall:

Instalarea și dezinstalarea aplicațiilor
========================================

Instalarea unei aplicații cunoscute
-----------------------------------

**tutorial**: vreau să instalez o aplicație pentru editare fișiere SVG
inkscape

**tutorial**: acum pot porni inkscape fie din mod grafic, fie din linia de comandă, fie Alt+F2

**exercițiu**: folosit inskcape îm GUI și în CLI pentru obținut din SVG un PNG sau PDF

Identificarea unei aplicații de instalat
----------------------------------------

**breviar**: avem situația în care știm ce aplicație să instalăm sau în care avem un use case

**breviar**: în general căutăm după aplicație sau după un șir

**tutorial**: căutăm o aplicație pentru e-book
Internet sau apt search calibre,rezultă calibre

**tutorial**: căutăm un editor de PDF
apt search pdf | grep -C 2 -i edit, nu ajută, folosim Internet-ul

**exercițiu**: de folosit editorul PDF pentru a pune o semnătură

**exercițiu**: de instalat și folosit o aplicație de screen-recording
apt search record | grep -C2 -i screen; apt search record | grep -C 2 -i video	

**exercițiu**: de făcut o înregistrare, eventual de pus pe YouTube

Identificarea unei aplicații după fișier
----------------------------------------

**breviar**: uneori știm numele unei comenzi sau al unui fișier dar nu știm ce să instalăm

**exercițiu**: din ce pachet face parte utilitarul ssconvert
folosit ssconvert pentru a converti un fișier .csv la .xls

**exercițiu**: un fișier Makefile conține comanda arm-linux-gnueabihf-gcc pentru a compila un fișier C pe arhitectura ARM
trebuie instalat pachetul corespunzătoră (găsit cu apt-file sau apt search)

TODO: dezinstalări

Bune practici și pitfalls
-------------------------

**tutorial**: putem instala o aplicație ``apt install -y`` și atunci nu mai este nevoie de confirmare, dar ...

**breviar**: atunci când instalăm o aplicație este posibil să dezinstalăm alte aplicații; similar, când instalăm o aplicație este posibil să instalăm alte aplicații care ne încarcă foarte mult sistemul (și îl deschide la posibile vulnerabilități); e important să urmărim promptul ``apt`` / ``dnf`` și, dacă facem operații critice, să **nu** folosim ``-y``

**tutorial**: TODO: o aplicație mai accesibilă (nu un server web) care va dezinstala o altă aplicație
