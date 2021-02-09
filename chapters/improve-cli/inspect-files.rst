.. _improve_cli_inspect_files:

Inspectarea fișierelor
======================


Inspectarea rapida a conținutului fișierelor
--------------------------------------------

În secțiunea anterioară, :ref:`improve_cli_inspect_fs`, am văzut cum căutăm fișiere în sistem cu ajutorul utilitarelor ``locate`` și ``find``.
Căutăm un fișier cu un scop: vrem să găsim fișierul ``README`` pentru informații despre compilarea proiectului, vrem să ne amintim un detaliu de implementare din cod, etc.

De cele mai multe ori acțiunea noastră se poate grupa în una din următoarele două categorii:

* Ne dorim să inspectăm rapid conținutul fișierelor pentru a ne da seama dacă am găsit informația căutată.
* Ne dorim să afișăm pe ecran conținutul fișierelor pentru a extrage și prelucra informații din acestea.

Căutarea informației într-un fișier
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Pentru a vedea rapid conținutul unui fișier folosim utlitarul ``less``.

.. note::

    De fapt, comanda ``man`` folosește utilitarul ``less`` pentru a afișa paginile de manual.
    ``less`` este pagerul implicit în majoritatea distribuțiilor Linux.

Avem fișierul ``workspace/C/searching/binary_search.c``.
Vrem să ne facem rapid o idee despre cum arată implementarea algoritmului **binary_search**.
Inspectăm conținutul fișierului ``workspace/C/searching/binary_search.c``, folosind utilitarul ``less`, ca în exemplul de mai jos:

.. code-block:: bash

    student@uso:~$ less workspace/C/searching/binary_search.c

    /**
     * @file
     * @brief Program to perform [binary
     * search](https://en.wikipedia.org/wiki/Binary_search_algorithm) of a target
     * value in a given *sorted* array.
     * @authors [James McDermott](https://github.com/theycallmemac) - recursive
     * algorithm
     * @authors [Krishna Vedala](https://github.com/kvedala) - iterative algorithm
     */
    #include <assert.h>
    #include <stdio.h>

    /** Recursive implementation
     * \param[in] arr array to search
     * \param l left index of search range
     * \param r right index of search range
     * \param x target value to search for
     * \returns location of x assuming array arr[l..r] is present
     * \returns -1 otherwise
     */
    int binarysearch1(const int *arr, int l, int r, int x)
    {
        if (r >= l)
        {
            int mid = l + (r - l) / 2;

            // If element is present at middle
            if (arr[mid] == x)
                return mid;
    : 

Observăm că acum avem o sesiune interactivă în interiorul căreia putem explora fișierul.

.. note::

    În cadrul unei sesiuni ``less`` putem folosi aceeleași taste ca în cadrul sesiunii interactive ``man`` pentru navigarea în pagină:

    * ``Ctrl+n``/``Ctrl+p`` sau ``j``/``k`` pentru a naviga, cu câte o linie, în jos, respectiv în sus; recomandăm utlizarea tastelor ``j``/``k`` pentru a fi mai eficienți
    * ``Ctrl+f``/``Ctrl+b`` pentru a naviga, cu câte o pagină de terminal, în jos, respectiv în sus
    * Search (``/``, ``?``, ``n``, ``N``)
    * Go up (``g``), go down (``G``)
    * Help (``h``) pentru a afla mai multe despre cum putem folosi mai bine sesiunea interactivă
    * Quit (``q``) pentru a ieși din sesiunea interactivă

    Toate aceste informații se găsesc în pagina de manual a utilitarului ``less``: ``man less``.

În sesiunea interactivă căutăm după cuvântul cheie **search**.
Pentru a porni căutarea apăsăm tasta ``/``, introducem textul căutat (**search**) și apăsăm tasta ``Enter``.
Apăsăm tasta ``n`` pentru a merge la următoarea apariție a textului căutat; apăsăm ``n`` până când ajungem la implementarea funcției ``binarysearch2``.

Exerciții
"""""""""

#. Analizați, folosind ``less``, algoritmul de căutare din fișierul ``workspace/C/searching/linear_search.c``.
   Ce implementare este mai eficientă: **binary_search** sau **linear_search**?
#. Analizați, folosind ``less``, algoritmul de sortare **quick_sort**.
   Folosiți utilitarul ``find`` pentru a găsi fișierul sursă care conține implementarea.
#. Analizați, folosind ``less``, algoritmul de sortare **merge_sort**.
   Folosiți utilitarul ``find`` pentru a găsi fișierul sursă care conține implementarea.
#. Căutați pe Google detalii despre cei doi algoritmi de sortare și încercați să vă răspundeți la întrebarea:
   Când folosim **merge_sort** și când folosim **quick_sort**?


Prelucrarea informației dintr-un fișier
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Pentru a afișa pe ecran conținutul unui fișier folosim utlitarul ``cat``.
Rulăm comanda de mai jos, pentru a exemplifica:

.. code-block:: bash

    student@uso:~$ cat workspace/C/searching/binary_search.c
    /**
     * @file
     * @brief Program to perform [binary
     * search](https://en.wikipedia.org/wiki/Binary_search_algorithm) of a target
     * value in a given *sorted* array.
     * @authors [James McDermott](https://github.com/theycallmemac) - recursive
     * algorithm
     * @authors [Krishna Vedala](https://github.com/kvedala) - iterative algorithm
     */
    #include <assert.h>
    #include <stdio.h>

    [...]

Observăm că pentru un fișier cu un număr mare de linii, așa cum este **binary_search.c**, afișarea întregului conținut pe ecran devine un impediment în a putea înțelege și urmări conținutul.
De aceea vă încurajăm să folosiți ``less`` în loc de ``cat`` pentru a inspecta un fișier: vă este mult mai ușor să vă plimbați în interiorul fișierului și puteți folosi funcția search pentru a căuta în fișier.
De asemeni, folosind ``less`` vă păstrați consola curată și puteți urmări mai ușor ce comenzi ați dat anterior și care au fost rezultatele acestora.

Folosim comanda ``cat`` în combinație cu alte comenzi pentru a extrage sau filtra conținutul anumitor fișiere.
Comanda ``cat`` primește ca argumente calea către unul sau mai multe fișiere și afișează pe ecran conținutul concatenat al acestora.

Un exemplu uzual este faptul că vrem să extragem informațiile despre starea memoriei sistemului din fișierul ``/proc/meminfo``.
Pentru aceasta rulăm comanda de mai jos:

.. code-block:: bash

    student@uso:~$ cat /proc/meminfo | grep "Mem"
    MemTotal:        2041248 kB
    MemFree:          236092 kB
    MemAvailable:     874420 kB

În exemplul de mai sus folosim ``cat`` pentru a oferi ca intrare conținutul fișierului ``/proc/meminfo`` utilitarului ``grep``; cu utilitarul ``grep`` filtrăm conținutul după textul ``"Mem"``.
Cu alte cuvinte, outputul comenzii ``cat /proc/meminfo``, adică conținutul fișierului ``/proc/meminfo`` este textul pe care utilitarul ``grep`` îl prelucrează.

**Exercițiu**: Plecând de la exemplul de mai sus, extrageți din fișierul ``/proc/cpuinfo`` dimensiunea memoriei cache a procesorului vostru; filtrați conținutul după textul ``"cache"``.

Afișarea parțială a unui fișier
"""""""""""""""""""""""""""""""

Am văzut că utilitarul ``cat`` afișează întreg conținutul unui fișier.
Există scenarii în care suntem interesați doar de începutul sau sfârșitul unui conținut.
Pentru aceste cazuri putem folosi utilitarele:

* ``head`` - afișează primele **10** linii din conținut
* ``tail`` - afișează ultimele **10** linii din conținut

.. note::

    Valoarea **10** este valoarea implicită a ambelor utilitare, dar putem specifica un alt număr de linii.

Așa cum am observat în capitolul despre procese, putem folosi utilitarul ``ps`` pentru a vedea care sunt procesele din sistem și ce resurse consumă acestea.
Memoria sistemului este una dintre cele mai importante resurse; dacă sistemul nostru rămâne fără memorie disponibilă, tot sistemul este afectat: sistemul se va "mișca" mai greu, procesele se vor "mișca" mai greu sau pot chiar să își întrerupă activitatea.
Știind acest lucru, suntem interesați să vedem care sunt primele zece procese care consumă cea mai multă memorie.

Folosim utilitarul ``ps`` pentru a afișa toate procesele din sistem:

.. code-block:: bash

    student@uso:~$ ps -e -ouser,uid,pid,%mem,%cpu,rss,cmd --sort=%mem

    USER       UID   PID %MEM %CPU   RSS CMD
    root         0     2  0.0  0.0     0 [kthreadd]

    [...]

    student   1000  8338  3.0  0.0 61860 /usr/lib/evolution/evolution-calendar-factory-subprocess --factory all --bus-name org.gnome.evolution.dataserver.Subprocess.Backend.Calendarx8307x2 --own-path /org/gnome/evolution/dataserver/Subprocess/Backend/Calendar/8307/2
    student   1000  8307  3.1  0.0 64628 /usr/lib/evolution/evolution-calendar-factory
    root         0  1338  3.8  0.0 78880 /usr/bin/dockerd -H fd:// --containerd=/run/containerd/containerd.sock
    student   1000  7782  3.9  0.0 81312 /usr/lib/xorg/Xorg vt1 -displayfd 3 -auth /run/user/1000/gdm/Xauthority -background none -noreset -keeptty -verbose 3
    student   1000  8437  8.4  0.0 171916 /usr/bin/gnome-software --gapplication-service
    student   1000  7938 18.0  0.1 368304 /usr/bin/gnome-shell

Am folosit opțiunea ``-ouser,uid,pid,%mem,%cpu,rss,cmd`` pentru a selecta coloanele pe care să le afișeze ``ps``.

Am folosit opțiunea ``--sort`` cu argumentul ``%mem`` pentru a sorta procesele după procentul de memorie folosită.

.. note::

    Folosiți comanda ``ps -e -ouser,uid,pid,%mem,%cpu,rss,cmd --sort=%mem | less`` pentru a vizualiza rezultatul comenzii ``ps`` într-o sesiune interactivă ``less``.

Observăm că avem procesele sortate crescător după coloana ``%MEM``.
Folosim utilitarul ``tail`` pentru a extrage din rezultatul ``ps`` cele mai consumatoare zece procese:

.. code-block:: bash

    student@uso:~$ ps -e -ouser,uid,pid,%mem,%cpu,rss,cmd --sort=%mem | tail
    student   1000 12966  1.8  0.0 38216 /usr/lib/gnome-terminal/gnome-terminal-server
    root         0  1074  2.2  0.0 45460 /usr/bin/containerd
    student   1000  8274  2.3  0.0 48296 nautilus-desktop
    root         0   336  2.6  0.0 53612 /lib/systemd/systemd-journald
    student   1000  8338  3.0  0.0 61860 /usr/lib/evolution/evolution-calendar-factory-subprocess --factory all --bus-name org.gnome.evolution.dataserver.Subprocess.Backend.Calendarx8307x2 --own-path /org/gnome/evolution/dataserver/Subprocess/Backend/Calendar/8307/2
    student   1000  8307  3.1  0.0 64628 /usr/lib/evolution/evolution-calendar-factory
    root         0  1338  3.8  0.0 78880 /usr/bin/dockerd -H fd:// --containerd=/run/containerd/containerd.sock
    student   1000  7782  3.9  0.0 81312 /usr/lib/xorg/Xorg vt1 -displayfd 3 -auth /run/user/1000/gdm/Xauthority -background none -noreset -keeptty -verbose 3
    student   1000  8437  8.4  0.0 171916 /usr/bin/gnome-software --gapplication-service
    student   1000  7938 18.0  0.1 368248 /usr/bin/gnome-shell

În acest moment am găsit răspunsul căutat, dar avem două mici neajunsuri:

* Ne lipsește antetul, așa că nu știm ce informații avem pe coloane
* Procesele sunt sortate crescător, a.î. cel mai consumator este ultimul; vrem să fie sortate descrescător

Rezolvăm cele două probleme prin intermediul opțiunii ``--sort``: dacă punem un ``-`` (minus) în fața argumentului după care sortăm, o să sortăm descrescător.
Rulăm comanda:

.. code-block:: bash

    student@uso:~$ ps -e -ouser,uid,pid,%mem,%cpu,rss,cmd --sort=-%mem | less
    USER       UID   PID %MEM %CPU   RSS CMD
    student   1000  7938 18.0  0.1 368248 /usr/bin/gnome-shell
    student   1000  8437  8.4  0.0 171916 /usr/bin/gnome-software --gapplication-service
    student   1000  7782  3.9  0.0 81312 /usr/lib/xorg/Xorg vt1 -displayfd 3 -auth /run/user/1000/gdm/Xauthority -background none -noreset -keeptty -verbose 3
    root         0  1338  3.8  0.0 78880 /usr/bin/dockerd -H fd:// --containerd=/run/containerd/containerd.sock
    student   1000  8307  3.1  0.0 64628 /usr/lib/evolution/evolution-calendar-factory

    [...]

Observăm că acum avem formatul dorit.
Ne mai rămâne să extragem primele **11** linii din rezultatul comenzii de mai sus; **11** deoarece prima este linia antetului iar următoarele zece sunt procesele de interes.
Pentru aceasta utilizăm comanda ``head`` cu opțiunea ``-11`` ca în exemplul de mai jos:

.. code-block:: bash

    student@uso:~$ ps -e -ouser,uid,pid,%mem,%cpu,rss,cmd --sort=-%mem | head -11
    USER       UID   PID %MEM %CPU   RSS CMD
    student   1000  7938 18.0  0.1 367952 /usr/bin/gnome-shell
    student   1000  8437  8.4  0.0 171916 /usr/bin/gnome-software --gapplication-service
    student   1000  7782  3.9  0.0 81312 /usr/lib/xorg/Xorg vt1 -displayfd 3 -auth /run/user/1000/gdm/Xauthority -background none -noreset -keeptty -verbose 3
    root         0  1338  3.8  0.0 78880 /usr/bin/dockerd -H fd:// --containerd=/run/containerd/containerd.sock
    student   1000  8307  3.1  0.0 64628 /usr/lib/evolution/evolution-calendar-factory
    student   1000  8338  3.0  0.0 61860 /usr/lib/evolution/evolution-calendar-factory-subprocess --factory all --bus-name org.gnome.evolution.dataserver.Subprocess.Backend.Calendarx8307x2 --own-path /org/gnome/evolution/dataserver/Subprocess/Backend/Calendar/8307/2
    root         0   336  2.6  0.0 53612 /lib/systemd/systemd-journald
    student   1000  8274  2.3  0.0 48296 nautilus-desktop
    root         0  1074  2.2  0.0 45460 /usr/bin/containerd
    student   1000 12966  1.8  0.0 38216 /usr/lib/gnome-terminal/gnome-terminal-server

Exerciții
"""""""""

#. Afișați primele zece procese sortate în funcție de memoria ocupată (Hint: RSS).
   Nu uitați să includeți antetul.
#. Afișați ultimele zece procese sortate în funcție de utilizarea procesorului (Hint: CPU).
   Nu uitați să includeți antetul.


Căutarea în fișiere
-------------------

Așa cum am văzut până în acest punct din carte, majoritatea comenzilor Linux afișează o gamă largă de informații pe care apoi utilizatorul (adică noi) le filtrează pentru a extrage ceea ce îl intresează.
La începutul acestei secțiuni, dar și de-a lungul cărții, am folosit utilitarul ``grep`` ca să filtrăm rezultatul unei comenzi.

Comanda ``grep`` este una dintre cele mai folosite în linie de comandă.
Sintaxa de folosire a ``grep`` este următoarea:

.. code-block:: bash

    SYNOPSIS
           grep [OPTIONS] PATTERN [FILE...]

``grep`` caută **PATTERN** în lista de fișiere primită ca argument și afișează liniile care conțin **PATTERN**-ul căutat.
Atunci când nu primește nici un fișier, citește text de la tastatură (intrarea standard) și afișează liniile care conțin **PATTERN**-ul căutat.

Până acum noi am utilizat ``grep`` după modelul de mai jos:

.. code-block:: bash

    student@uso:~$ cat workspace/C/searching/binary_search.c | grep search
     * search](https://en.wikipedia.org/wiki/Binary_search_algorithm) of a target
     * \param[in] arr array to search
     * \param l left index of search range
     * \param r right index of search range
     * \param x target value to search for
    int binarysearch1(const int *arr, int l, int r, int x)

    [...]

În exemplul de mai sus, operatorul ``|`` trimite textul afișat de comanda ``cat`` către intrarea standard a comenzii ``grep``.
Vom discuta mai multe despre acesta în secțiunea :ref:`improve_cli_improve_shell_oneliners`.

Comanda următoare este echivalentă cu cea de mai sus:

.. code-block:: bash

    student@uso:~$ grep search workspace/C/searching/binary_search.c
     * search](https://en.wikipedia.org/wiki/Binary_search_algorithm) of a target
     * \param[in] arr array to search
     * \param l left index of search range
     * \param r right index of search range
     * \param x target value to search for
    int binarysearch1(const int *arr, int l, int r, int x)
    [...]

Observăm modul de folosire: ``grep PATTERN cale/către/fișier``.

Exerciții
^^^^^^^^^

#. Căutați *patternul* "l" în fișierul ``binary_search.c``, pentru a vedea unde este folosit parametrul **left**.
   Observați cât de multe rezultate irelevante ați găsit datorită faptului că am căutat doar caracterul **l**.
   Aici există o lecție de învățat.
   Numele variabilelor sunt foarte improtante: nu fac doar codul mai ușor de înțeles, dar ajută și căutarea.
   Folosiți *patternul* "param l" în încercarea de a restrânge căutarea.

#. Căutați *patternul* "arr" în fișierul ``binary_search.c``.

#. Căutați *patternul* "binarysearch1" în fișierul ``binary_search.c`` pentru a vedea cum este apelată funcția de căutare.

Opțiuni uzuale ale ``grep``
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Afișarea numărului liniei care conține patternul
""""""""""""""""""""""""""""""""""""""""""""""""

Folosim opțiunea ``-n`` pentru a afișa și numărul liniei care conține patternul căutat:

.. code-block:: bash

    student@uso:~$ grep -n search workspace/C/searching/binary_search.c
    4: * search](https://en.wikipedia.org/wiki/Binary_search_algorithm) of a target
    14: * \param[in] arr array to search
    15: * \param l left index of search range
    16: * \param r right index of search range
    17: * \param x target value to search for
    21:int binarysearch1(const int *arr, int l, int r, int x)
    [...]

Căutarea case-insensitive
"""""""""""""""""""""""""

Implicit, grep caută în mod case-sensitive patternul, așa cum putem observa din exemplul de mai jos:

.. code-block:: bash

    student@uso:~$ grep Search workspace/C/searching/binary_search.c

Pentru a efectua căutarea textului în mod case-insesnsitive, folosim opțiunea ``-i``, ca în exemplul de mai jos:

.. code-block:: bash

    student@uso:~$ grep -i Search workspace/C/searching/binary_search.c
     * search](https://en.wikipedia.org/wiki/Binary_search_algorithm) of a target
     * \param[in] arr array to search
     * \param l left index of search range
     * \param r right index of search range
     * \param x target value to search for
    int binarysearch1(const int *arr, int l, int r, int x)
    [...]

Excluderea unui pattern
"""""""""""""""""""""""

Pentru a afișa toate liniile, mai puțin pe cele care conțin pattern, folosim opțiunea ``-v``, ca în exemplul de mai jos:

.. code-block:: bash

    student@uso:~$ grep -v search workspace/C/searching/binary_search.c | less
    /**
     * @file
     * @brief Program to perform [binary
     * value in a given *sorted* array.
     * @authors [James McDermott](https://github.com/theycallmemac) - recursive
     * algorithm
     * @authors [Krishna Vedala](https://github.com/kvedala) - iterative algorithm
     */
    #include <assert.h>
    #include <stdio.h>
    [...]

Căutarea recursivă a unui pattern
"""""""""""""""""""""""""""""""""

În căutările noastre de până acum, ca și în exemplele de mai sus, am presupus că știm în ce fișiere se găsește informația căutată de noi.
Acest lucru este adevărat pentru fișiere din sistem cu informații bine cunoscute, cum ar fi ``/proc/meminfo``, dar atunci când lucrăm cu un proiect nou nu vom ști în ce fișiere să căutăm informația dorită.
De exemplu, în cazul proiectului cu algoritmi implementați în C, noi am făcut presupunerea că vom găsi linii care conțin patternul **search** în fișierul ``workspace/C/searching/binary_search.c``.

Atunci când nu știm în ce fișiere se află informația căutată putem să-i spunem lui ``grep`` să caute recursiv prin toată ierarhia de fișiere dintr-un anumit director.
Pentru a efectua o căutare recursivă folosim opțiunea ``-r``, ca în exemplul de mai jos:

.. code-block:: bash

    student@uso:~$ grep -r search workspace/C/ | less

    workspace/C/leetcode/src/700.c:struct TreeNode *searchBST(struct TreeNode *root, int val)
    workspace/C/leetcode/src/700.c:        return searchBST(root->left, val);
    workspace/C/leetcode/src/700.c:        return searchBST(root->right, val);
    workspace/C/leetcode/src/35.c:int searchInsert(int *nums, int numsSize, int target)
    workspace/C/leetcode/src/35.c:int searchInsert(int *nums, int numsSize, int target)
    workspace/C/leetcode/src/35.c:        return searchInsert(nums, numsSize - 1, target);
    workspace/C/leetcode/src/704.c:int search(int *nums, int numsSize, int target)
    workspace/C/leetcode/src/704.c:/* Another solution: Using bsearch() */
    workspace/C/leetcode/src/704.c:int search(int *nums, int numsSize, int target)
    workspace/C/leetcode/src/704.c:    int *ret = bsearch(&target, nums, numsSize, sizeof(int), cmpint);
    workspace/C/leetcode/README.md:|35|[Search Insert Position](https://leetcode.com/problems/search-insert-position/) | [C](./src/35.c)|Easy|
    workspace/C/leetcode/README.md:|108|[Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/) | [C](./src/108.c)|Easy|
    workspace/C/leetcode/README.md:|109|[Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/) | [C](./src/109.c)|Medium|
    workspace/C/leetcode/README.md:|173|[Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/) | [C](./src/173.c)|Medium|
    workspace/C/leetcode/README.md:|700|[Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/) | [C](./src/700.c)|Easy|
    workspace/C/leetcode/README.md:|701|[Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/) | [C](./src/701.c)|Medium|
    workspace/C/leetcode/README.md:|704|[Binary Search](https://leetcode.com/problems/binary-search/) | [C](./src/704.c)|Easy|
    workspace/C/DIRECTORY.md:    * [Binary Search Tree](https://github.com/TheAlgorithms/C/blob/master/data_structures/binary_trees/binary_search_tree.c)
    workspace/C/DIRECTORY.md:  * [Binary Search](https://github.com/TheAlgorithms/C/blob/master/searching/binary_search.c)
    workspace/C/DIRECTORY.md:  * [Fibonacci Search](https://github.com/TheAlgorithms/C/blob/master/searching/fibonacci_search.c)

Best practice
"""""""""""""

De cele mai multe ori vom folosi opțiunile ``-n``, ``-i`` și ``-r`` în aceelași timp.
În cazul nostru de până acum, aceasta se traduce în:

.. code-block:: bash

    student@uso:~$ grep -nri search workspace/C/ | less

    workspace/C/leetcode/src/700.c:10:struct TreeNode *searchBST(struct TreeNode *root, int val)
    workspace/C/leetcode/src/700.c:21:        return searchBST(root->left, val);
    workspace/C/leetcode/src/700.c:25:        return searchBST(root->right, val);
    workspace/C/leetcode/src/35.c:1:int searchInsert(int *nums, int numsSize, int target)
    workspace/C/leetcode/src/35.c:18:int searchInsert(int *nums, int numsSize, int target)
    workspace/C/leetcode/src/35.c:27:        return searchInsert(nums, numsSize - 1, target);
    workspace/C/leetcode/src/704.c:1:int search(int *nums, int numsSize, int target)
    workspace/C/leetcode/src/704.c:23:/* Another solution: Using bsearch() */
    workspace/C/leetcode/src/704.c:26:int search(int *nums, int numsSize, int target)
    workspace/C/leetcode/src/704.c:28:    int *ret = bsearch(&target, nums, numsSize, sizeof(int), cmpint);
    workspace/C/leetcode/README.md:26:|35|[Search Insert Position](https://leetcode.com/problems/search-insert-position/) | [C](./src/35.c)|Easy|
    workspace/C/leetcode/README.md:35:|108|[Convert Sorted Array to Binary Search Tree](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/) | [C](./src/108.c)|Easy|
    workspace/C/leetcode/README.md:36:|109|[Convert Sorted List to Binary Search Tree](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/) | [C](./src/109.c)|Medium|
    workspace/C/leetcode/README.md:47:|173|[Binary Search Tree Iterator](https://leetcode.com/problems/binary-search-tree-iterator/) | [C](./src/173.c)|Medium|
    workspace/C/leetcode/README.md:78:|700|[Search in a Binary Search Tree](https://leetcode.com/problems/search-in-a-binary-search-tree/) | [C](./src/700.c)|Easy|
    workspace/C/leetcode/README.md:79:|701|[Insert into a Binary Search Tree](https://leetcode.com/problems/insert-into-a-binary-search-tree/) | [C](./src/701.c)|Medium|
    workspace/C/leetcode/README.md:80:|704|[Binary Search](https://leetcode.com/problems/binary-search/) | [C](./src/704.c)|Easy|
    workspace/C/.github/pull_request_template.md:20:- [ ] Search previous suggestions before making a new one, as yours may be a duplicate.
    workspace/C/DIRECTORY.md:31:    * [Binary Search Tree](https://github.com/TheAlgorithms/C/blob/master/data_structures/binary_trees/binary_search_tree.c)
    workspace/C/DIRECTORY.md:338:## Searching
    :

Astfel avem o căutare cât mai cuprinzătoare și putem folosi funcția de căutare în sesiunea interactivă ``less`` pentru a găsi linia și fișierul care ne interesează.

Bonus: Căutarea unui cuvânt
"""""""""""""""""""""""""""

Din rezultatele căutărilor de mai sus observăm că ``grep`` caută patternul dat ca un subșir.
Acest lucru se vede foarte ușor în rezultatul anterior:

.. code-block:: bash

    student@uso:~$ grep -nri search workspace/C/ | less

    workspace/C/leetcode/src/700.c:10:struct TreeNode *searchBST(struct TreeNode *root, int val)

Observăm că patternul **search** se regăsește în șirul **\*searchBST**.
Dacă dorim să căutăm cuvântul **search** folosim opțiunea ``-w`` (word) pentru a-i transmite utilitarului că patternul trebuie tratat ca un cuvânt, ca în exemplul de mai jos:

.. code-block:: bash

    student@uso:~$ grep -nri -w "search" workspace/C/ | less

    workspace/C/leetcode/src/704.c:1:int search(int *nums, int numsSize, int target)
    workspace/C/leetcode/src/704.c:26:int search(int *nums, int numsSize, int target)
    workspace/C/leetcode/README.md:26:|35|[Search Insert Position](https://leetcode.com/problems/search-insert-position/) | [C](./src/35.c)|Easy|
    [...]

Observăm că acum rezultatele conțin doar cuvântul **search**.

Exerciții
"""""""""

#. Găsiți toate fișierele care includ headerul ``stdio.h``.

#. Găsiți toate aparițiile patternului ``binarySearch``.

#. Găsiți toate aparițiile patternului ``quickSort``.


Compararea fișierelor
---------------------

Atunci când lucrăm cu fișiere o să ne întâlnim sporadic cu nevoia de a compara două fișiere între ele.

Compararea octet cu octet
^^^^^^^^^^^^^^^^^^^^^^^^^

Compararea octet cu octet este utilă atunci când vrem aflăm dacă două fișiere sunt diferite sau nu, dar nu ne interesează cu ce diferă.
Un exemplu ar fi: avem o arhivă cu aceelași nume în două locații diferite și nu mai ținem minte dacă am copiat-o noi sau este o coincidență de nume.
Verificăm, fără să fie nevoie să le dezarhivăm, printr-o comparare la nivel de octet folosind comanda ``cmp``:

.. code-block:: bash

    student@uso:~$ cmp Documents/uso.tar Downloads/uso.tar
    student@uso:~$ cmp Downloads/courses.tar Downloads/uso.tar
    Downloads/courses.tar Downloads/uso.tar differ: byte 1, line 1

În exemplul de mai sus, observăm că arhiva din calea ``Documents/uso.tar`` și cea din calea ``Downloads/uso.tar`` sunt identice, pe când arhivele ``Downloads/courses.tar`` și ``Downloads/uso.tar`` diferă de la primul octet *(byte 1, line 1)*.
Observăm că în cazul în care fișierele sunt identice, ``cmp`` nu afișează nimic pe ecran.

Compararea text
^^^^^^^^^^^^^^^

Putem folosi ``cmp`` pentru a compara orice tip de fișier, inclusiv fișiere text, ca în exemplul de mai jos:

.. code-block:: bash

    student@uso:~$ cmp workspace/C/sorting/merge_sort.c workspace/C/sorting/quick_sort.c
    workspace/C/sorting/merge_sort.c workspace/C/sorting/quick_sort.c differ: byte 1, line 1

Rezultatul de mai sus nu este ideal: știm că cele două fișiere sunt diferite, dar nu știm și cu ce anume diferă.
Pentru comparații text folosim utilitarul ``diff``.

Pentru a exemplifica, navigăm în directorul ``~/workspace/C/sorting/``, facem o copie fișierului ``quick_sort.c`` cu numele ``quick_sort_old.c`` și adăugăm comentariul ``// It's so simple to diff``:

.. code-block:: bash

    student@uso:~$ cd workspace/C/sorting/
    student@uso:~/workspace/C/sorting$ cp quick_sort.c quick_sort_old.c
    student@uso:~/workspace/C/sorting$ echo "// It's so simple to diff" >> quick_sort.c

Folosim comanda ``diff`` pentru a vedea diferențele dintre ``quick_sort.c`` și ``quick_sort_old.c``:

.. code-block:: bash

    student@uso:~/workspace/C/sorting$ diff quick_sort.c quick_sort_old.c
    98d97
    < // It's so simple to diff
    student@uso:~/workspace/C/sorting$ diff quick_sort_old.c quick_sort.c
    97a98
    > // It's so simple to diff

Observăm următorul lucru: linia care diferă este precedată de caracterul ``<`` atunci când provine din primul fișier, și este precedată de caracterul ``>`` atunci când provine din al doilea fișier.

Exerciții
"""""""""

#. TODO


