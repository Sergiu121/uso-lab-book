Editor de text
==============

O acțiune foarte des întâlnită este modificarea unor fișiere.
Fie că scriem în jurnal, facem un TODO list sau scriem cod, trebuie să scriem într-un fișier.
Pentru a modifica un fișier, folosim un program numit **editor de fișier**.
Există două tipuri de editoare de fișier: **editoare în mod grafic** sau **editoare în linie de comandă**.
Vom detalia în continuare aceste două categorii.

.. note::
    Nu există un editor bun sau prost.
    Există un editor potrivit sau nepotrivit.


Editor grafic
-------------
Folosit în mod uzual de utilizatori non-tehnici, aceste tipuri de editoare au o interfață grafică ce permit modificarea fișierelor într-un mod cât mai ușor, facil.


Poate cel mai folosit editor din această categorie este `Microsoft Word`_.
Scopul acestuia este ușurința în folosință: există multe capabilități (culori, marime font, stil, aranjare în pagină) pentru crearea de conținut, iar opțiunile sunt ușor de găsit și folosit.
Un alt editor de text este `Notepad++`_. Acesta este mai simplu, cu mai puține opțiuni.

Un editor foarte folosit pentru programare este `Sublime`_. Acesta este și editorul grafic recomandat de noi.

Editoarele grafice sunt populare și pentru programare.
Acestea oferă capabilități diverse pentru a ajuta un programator să scrie cod mai ușor, facil.
De exemplu:

* Buton pentru compilare și execuție
* Auto-indentare (alinierea liniilor de cod)
* Auto-completare a numelor de funcții și variabile
* Suport pentru debugging
* Integrarea cu alte componente: de exemplu editorul Xcode (de la Apple) este integrat cu simulator (iPhone).

Printr-o singură apăsare de buton, se pornește simulatorul de iPhone și se execută aplicația.

Alte editoare grafice: `Sublime`_, `gedit`_, `Visual Studio`_.

.. _gedit: https://wiki.gnome.org/Apps/Gedit
.. _Visual Studio: https://visualstudio.microsoft.com/
.. _Sublime: https://www.sublimetext.com/3
.. _Microsoft Word: https://www.microsoft.com/en-us/microsoft-365/word>
.. _Notepad++: https://notepad-plus-plus.org/



Interacțiunea cu fișiere cu ajutorul editoarelor grafice
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Mai jos este un exemplu de interacțiune cu editorul `Pages`_, un editor de text de la Apple.
Editarea documentelor este simplă, intuitivă și cu multe opțiuni.

.. _Pages: https://www.apple.com/pages/

.. figure:: res/pages.gif

Putem adăuga text foarte intuitiv.
Am modificat dimensiunea, culoarea, fontul textului foarte ușor.
Aceasta este puterea unui editor grafic.

Însă, pentru programare nu este deloc util; vom folosi ``sublime``.

Deschiderea unui fișier se poate face atât din linia de comandă ``student@uso:~$ subl fișier``

O listă de comenzi utile găsim `aici`_ le executăm în continuare:

.. _aici: https://www.shortcutfoo.com/app/dojos/sublime-text-3-win/cheatsheet

Folosim combinația de taste ``ctrl+x`` pentru *cut*:

.. figure:: res/sublime1.gif

Folosim combinația de taste ``ctrl+u`` pentru *undo*, iar pentru a șterge de la cursor până la începutul liniei ``ctrl+k ctrl+backspace``:

.. figure:: res/sublime2.gif

Indentarea se face cu ``ctrl+[`` și ``ctrl+]``:

.. figure:: res/sublime3.gif

Duplicăm o linie folosind ``shift+ctrl+d``:

.. figure:: res/sublime4.gif

Pentru a compila cod folosim combinația de taste ``ctrl+b``:

.. figure:: res/sublime5.gif


Exerciții - editor grafic
"""""""""""""""""""""""""

#. * Deschideți fișierul ``Romanian Presidents`` și completați fișierul cu cel puțin 3 președinți ai României.
   * Salvati fișierul în directorul vostru ``home``.
   * Duplicați textul scris anterior (copiat/lipit) de 5 ori;
   * Indentați fiecare linie o dată;
   * Comentați liniile 2-8.

#. * Scrieti cod C (similar exemplului de mai sus) pentru a afișa textul ``Make USO Great Again!``;
   * Folositi scurtăturile pentru indentare;
   * Compilați folosind scurtătura ``ctrl+b``.

Editor în linie de comandă
--------------------------

Editoarele în linia de comandă sunt făcute pentru interacțiunea cu terminalul.
Acestea asigură funcționalitați restrânse de formatare în comparație cu editoarele grafice.
Nu există butoane fizice; de obicei comenzile se dau prin combinații de taste.

Un alt caz în care folosim editoarele în linie de comandă este lucrul la distanță.
Atunci când ne conectăm remote la un server și nu avem interfață grafică, utilizarea unui editor în linie de comandă este necesară.

Există editoare mai puternice `vim`_, `emacs`_ care permit automatizarea unor sarcini precum cele de mai sus.


Un editor în linie de comandă uzual folosit este `nano`_.
Acesta are funcționalități de bază și este ușor de folosit.

.. _nano : https://www.nano-editor.org/
.. _vim : https://www.vim.org/
.. _emacs : https://www.gnu.org/software/emacs/

Interacțiunea cu fișiere cu ajutorul editoarelor în linie de comandă
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

În continuare vom folosi ``nano`` pentru a interacționa cu un fișier.

.. figure:: res/avengers.gif

În exemplul de mai sus am deschis fișierul ``avengers`` cu ``nano``.
În urma comenzii, s-a creat fișierul dacă acesta nu exista.
Am adăugat numele a 4 supereroi și am salvat folosind combinația de taste ``Ctrl+x`` după care a apărut întrebarea dacă vrem să salvăm modificările.
În partea de jos apare optiunea de ``Y``
es și ``N``
o.
Apăsând pe tasta ``Y``, ne cere să trecem numele fișierului, după care să confirmăm cu tasta **Enter**.

O listă de comenzi utile găsim la `cheatsheet nano`_.

.. _cheatsheet nano : https://www.nano-editor.org/dist/latest/cheatsheet.html


În continuare vom exemplifica scurtături cu ajutorul combinațiilor de taste pentru a spori eficiența.

.. figure:: res/shortcuts.gif


Exerciții - editor în linie de comandă
""""""""""""""""""""""""""""""""""""""

#. * Deschideți fișierul ``US Presidents`` și completați fișierul cu cel puțin 3 președinți ai Statelor Unite are Americii.
   * Salvati fișierul în directorul vostru ``home``.
   * Duplicați textul scris anterior (copiat/lipit) de 5 ori;
   * Indentați fiecare linie de două ori;
   * Comentați liniile 2-8.


   * Salvati fișierul în directorul vostru **home**.
   * Duplicați textul scris anterior (copiat/lipit) de 5 ori;
   * Adăugați 4 spații la început de fiecare rând;
   * Adăugați caracterul **#** la început de rând pentru liniile 2-8.

#. * Scrieti cod C (similar exemplului de la editor grafic) pentru a afișa textul ``Make USO Great Again!``;
   * Folositi scurtăturile pentru indentare;
   * Compilați folosind scurtătura ``ctrl+b``.
