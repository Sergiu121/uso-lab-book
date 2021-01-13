.. _app_dev_intro:

Introducere
===========

Toate dispozitivele electronice pe care le folosim în viața de zi cu zi, de la latopuri sau calculatoare personale, până la telefoane mobile sau smart watch-uri, au în comun un lucru: rulează software.
Având în vedere cât de variate sunt sistemele pe care rulează aplicațiile, trebuie să avem mereu în minte sistemul pentru care creăm o aplicație.
De exemplu, dacă aplicația noastră este gândită pentru un ceas inteligent, atunci trebuie să ținem în minte că resursele vor fi limitate; apare astfel o constrângere din punctul de vedere al memoriei disponibile.

Astfel, trebuie să ținem cont de următoarele:

* ce limbaj de programare folosim
* cum scriem și compilăm codul sursă
* cum depanăm codul sursă
* cum versionăm codul sursă

Vom vorbi despre toate aceste aspecte în acest capitol.

.. _app_dev_choose_programming_language:

Alegerea limbajului de programare
---------------------------------

Există trei categorii de limbaje de programare, grupate în funcție de modul în care codul sursă scris de noi (*de limbaj înalt*) ajunge să fie rulat pe procesor: **compilate**, **interpretate** și **hibride**.
Alegem limbajul de programare potrivit pentru dezvoltarea programului nostru în funcție de ce avem nevoie: să avem un program portabil sau să avem un program rapid sau să avem acces mai ușor la memorie.

În această carte vom folosi *limbajul C* ca să scriem codul sursă și *compilatorul gcc* pentru a compila codul sursă, însă mai jos descriem particularitățile fiecărui tip de limbaj de programare. 

.. _app_dev_compiled_languages:

Limbaje de programare compilate
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Programele scrise într-un limbaj **compilat** sunt analizate de către un program numit *compilator* înainte ca ele să poată fi rulate pe sistem.
În general, limbajele compilate sunt mai rapide în execuție decât cele interpretate sau hibride, deoarece problemele de **sintaxă** (*de scriere*) sunt eliminate din faza *compilării*, înainte să rulăm programul.
Neajunsul programelor compilate este faptul că programele **NU** sunt **portabile**, adică nu putem lua un program compilat pe calculator să îl rulăm pe un smartwatch; trebuie să *recompilăm* codul sursă.

Exemple de limbaje compilate sunt **C**, **C++**, **Fortran**, **Rust**, **Go**, **D**.

.. _app_dev_interpreted_languages:

Limbaje de programare interpretate
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Atunci când scriem un program într-un limbaj **interpretat**, programul este trecut printr-un alt program, numit *interpretor* care analizează și rulează fiecare linie de cod scrisă, pe rând.
Dacă alegem să scriem un program într-un limbaj de programare interpretat, atunci programul nostru este **portabil**, adică putem să îl rulăm pe orice sistem pe care avem interpretorul instalat.
Din cauza faptului că programele sunt analizate și rulate linie cu linie, execuția lor poate fi mai lentă.

Exemple de limbaje interpretate sunt **PHP** și **Perl**.

.. _app_dev_hybrid_languages:

Limbaje de programare hibride
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Programele scrise într-un limbaj **hibrid** trec print-un proces care îmbină etapa de *compilare* și etapa de *interpretare*, scopul fiind de a avea în final un program portabil al cărui timp de execuție este mai redus decât în cazul programelor interpretate.

Exemple de limbare hibride sunt **Python**, **Java** și **C#**.

.. _app_dev_writing_source_code:

Scrierea codului sursă
----------------------

Atunci când spunem că *dezvoltăm o aplicație*, spunem, de fapt, că scriem codul sursă, îl compilăm, îl verificăm de erori.
Pentru scrierea codului sursă putem să alegem **editoare de text** sau `medii de dezvoltare integrate <https://www.redhat.com/en/topics/middleware/what-is-ide>`_ (*Integrated Development Environment*, *IDE*).

*Editoarele de text* sunt programe mai simple în care putem edita fișiere text, deci putem dezvolta programe.
Ele pot permite instalarea de extensii care aduc funcționalități în plus, specifice pentru un anumit limbaj.
Printre cele mai cunoscute editoare de text se numără `GNU Nano <https://www.nano-editor.org>`_, `Vim <https://www.vim.org>`_, `Sublime <http://sublimetext.com>`_, `Atom <https://atom.io>`_, `Visual Studio Code <https://code.visualstudio.com>`_.

*IDE-urile* au anumite funcționalități avansate, multe dintre ele fiind adaptate unui singur limbaj de programare.
În plus, ele au integrat un compilator/interpretor pentru limbajul suportat.
Astfel, la o simplă apăsare de buton programul este rulat.
Printre IDE-uri se număra: `Microsoft Visual Studio <https://visualstudio.microsoft.com>`_, `Eclipse <https://www.eclipse.org/ide/>`_, `IntelliJ <https://www.jetbrains.com/idea/>`_, `XCode <https://developer.apple.com/xcode/>`_.

În această carte vom folosi *GNU Nano* ca editor de text principal.
Este un editor CLI și se pornește folosind comanda ``nano``, așa cum a fost prezentat în capitolul *Lucrul cu fișiere*.