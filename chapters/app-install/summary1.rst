.. _app_install_summary1:

Exerciții: Pornirea, rularea și configurarea aplicațiilor
=========================================================

Exercițiile de mai jos sunt exerciții recapitulative, cu grad sporit de dificultate.

Mod headless pentru aplicații grafice
-------------------------------------

Folosiți LibreOffice pentru a crea un document format ``.odt``.
Închideți LibreOffice.

Folosiți LibreOffice în linia de comandă (modul headless) pentru a converti fișierul ``.odt`` într-un fișier PDF.

Investigarea I/O a proceselor
-----------------------------

În afară de consumul de putere de calcul (memorie și procesor), ne interesează ce procese folosesc I/O (*input/output*).
Pentru aceasta putem folosi utilitarul ``iotop``.

Folosiți utilitarul ``iotop`` pentru a afișa resursele I/O consumate de procesele sistemului.

În interfața afișată, reduceți afișarea doar la procesele care consumă I/O.

.. hint::

    Urmăriți șirul ``--only`` în pagina de manual a utilitarului ``iotop``.

Emacs în modul full-screen
--------------------------

Configurați Emacs astfel încât pornirea sa în interfața grafică să fie în modul full-screen.

.. hint::

    Configurarea o realizați în fișierul ``~/.emacs``.

Configurare aplicații de startup
--------------------------------

Configurați sistemul astfel încât, la autentificarea utilizatorului, să fie pornite automat:

* o aplicație browser (Firefox)
* o aplicație de terminal (GNOME Terminal)

Configurare transparență terminal
---------------------------------

Configurați GNOME Terminal astfel încât fereastra de terminal să aibă transparență.

.. hint::

    Configurarea o realizați în interfața grafică a aplicației.
