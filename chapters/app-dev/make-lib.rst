.. _app_dev_link_libs:

Legarea executabilelor folosind biblioteci externe
==================================================

În secțiunea anterioară, :ref:`app_dev_compile_multiple_files` am compilat fișierul ``~/support/compile-multiple/main.c``, care conține:

.. code-block:: c

    #include <stdio.h>
    #include "algorithms.h"

    int main(void)
    {
        int n;

        printf("gimme number and i'll give you factorial: ");
        scanf("%d", &n);

        printf("%d! = %u\n", n, factorial(n));
        printf("%d! = %u\n", n + 1, factorial(n + 1));
        return 0;
    }

În acest cod sursă am apelat 2 funcții diferite ``printf`` și ``factorial``.
Găsim implementarea funcției ``factorial`` în fișierul ``algorithms.c``:

.. code-block:: c

    unsigned int factorial(int n)
    {
        unsigned int fact = 1;

        while (n > 0) {
            fact *= n;
            n--;
        }

        return fact;
    }

Găsim implementarea funcției ``printf`` în **biblioteca standard C** (*C Standard Library*).
Pentru a folosi funcția ``printf`` în fișierul ``main.c``, am inclus fișierul header ``stdio.h``.

O **bibliotecă** este un fișier în care găsim o colecție de funcții generale, pe care le putem folosi în programele noastre, dar pe care nu le-am scris noi.

Atunci când am legat fișierele obiect ``main.o`` și ``algorithms.o`` în executabilul ``algorithms``, am legat, de fapt, fișierele obiect ``main.o``, ``algorithms.o`` **și** biblioteca standard C.
Compilatorul GCC leagă implicit această bibliotecă la executabilul final.
Diagrama de mai jos arată cum se întâmplă acest lucru:

.. ditaa::

    +--------+           +--------+
    | cBLU   |     1     | cYEL   |
    | main.c +---------->+ main.o +---------+ 
    |        |           |        |         |
    |     {d}|           |     {d}|         |
    +--------+           +--------+         +
                                            |
    +--------------+     +--------------+   |     +------------+
    | cBLU         |  1  | cYEL         |   |  2  |            |
    | algorithms.c +---->+ algorithms.o +---+---->+ algorithms |
    |              |     |              |   |     |            |
    |           {d}|     |           {d}|   |     | cGRE       |
    +--------------+     +--------------+   |     +------------+
                                            |
                +-----------------------+   |
                | {d}                   |   |
                |  C standard library   +---+
                | cPNK                  |
                +-----------------------+
                                         

Există alte biblioteci (precum ``math``, ``ncurses``) pe care compilatorul nu le leagă implicit la programele noastre.

În continuare vom compila un fișier cod sursă care folosește biblioteca ``math`` pentru a calcula rădăcina pătrată a unui număr întreg.

.. _app_dev_link_libs_inspect_file:

Inspectarea fișierelor
----------------------

Intrăm în directorul ``~/support/compile-with-lib`` folosind comanda ``cd``, unde găsim fișierul ``squared_root.c``:

.. code-block:: bash

    student@uso:~$ cd ~/support/compile-with-lib/
    student@uso:~/support/compile-with-lib$ ls
    squared_root.c

Afișăm conținutul fișierului ``squared_root.c``, folosind comanda ``cat``:

.. code-block:: bash

    student@uso:~/support/compile-with-lib$ cat squared_root.c
    #include <stdio.h>
    #include <math.h>

    int main(void)
    {
        int n;

        printf("gimme a number and i'll give its square root: ");
        scanf("%d", &n);

        printf("here you go: %f\n", sqrt(n));

        return 0;
    }

Linia ``#include <math.h>`` a fost scrisă pentru că în acest fișier cod sursă folosim funcția ``sqrt`` din biblioteca ``math``.
Spunem că *includem fișierul header* asociat bibliotecii ``math`` în fișier.

În continuare vom vedea cum compilăm fișierul ``squared_root.c`` astfel încât să obținem un executabil care calculează rădăcina pătrată a unui număr întreg citit de la tastatură.

.. _app_dev_link_libs_compile_file:

Compilarea fișierelor
----------------------

Compilăm fișierul ``main.c``, folosind comanda ``gcc``, ca în secțiunea :ref:`app_dev_compile_custom`:

.. code-block:: bash

    student@uso:~/support/compile-with-lib$ gcc -o squared_root squared_root.c
    /tmp/ccp4kfvm.o: In function `main`:
    squared_root.c:(.text+0x48): undefined reference to `sqrt`
    collect2: error: ld returned 1 exit status

Eroarea ``undefined reference to `sqrt``` apare din cauză că în fișierul ``squared_root.c`` folosim funcția ``sqrt``, dar compilatorul nu știe unde să caute implementarea ei.
Corectăm eroarea folosind opțiunea ``-lm`` pentru ``gcc``:

.. code-block:: bash

    student@uso:~/support/compile-with-lib$ gcc -o squared_root squared_root.c -lm
    student@uso:~/support/compile-with-lib$ ls
    squared_root  squared_root.c

Opțiunea ``-lm`` este formată prin alipirea opțiunii ``-l`` (*library*, *bibliotecă*) cu ``m`` (*math*).
În cazul bibliotecii ``math`` trebuie folosită prescurtarea ``m``, pentru alte biblioteci va fi diferit.

Rulăm executabilul ``squared_root`` ca să verificăm că funcționează:

.. code-block:: bash

    student@uso:~/support/compile-with-lib$ ./squared_root
    gimme a number and i'll give its square root: 15
    here you go: 3.872983

Legarea bibliotecii ``math`` la executabilul ``squared_root`` se face după ce fișierul ``squared_root.c`` a fost compilat.
Cu alte cuvinte, putem compila mai întâi fișierul ``squared_root.c`` până la un fișier obiect și după să îl legăm la biblioteca ``math``, ca în exemplul de mai jos:

.. code-block:: bash

    student@uso:~/support/compile-with-lib$ gcc -c squared_root.c 
    student@uso:~/support/compile-with-lib$ gcc -o squared_root squared_root.o -lm
    student@uso:~/support/compile-with-lib$ ./squared_root
    gimme a number and i'll give its square root: 15
    here you go: 3.872983

Vedem acești pași și în diagrama de mai jos:

.. ditaa::

    +----------------+     +----------------+       +--------------+
    | cBLU           |  1  | cYEL           |   2   |              |
    | squared_root.c +---->+ squared_root.o +---+-->+ squared_root |
    |                |     |                |   |   |              |
    |           {d}  |     |           {d}  |   |   | cGRE         |
    +----------------+     +----------------+   |   +--------------+
                                                |
                           +---+----+           |
                           | {d}    |           |
                           |  math  +-----------+
                           | cPNK   |
                           +--------+

.. _app_dev_link_libs_ex:

Exerciții
---------

Înainte să începeți exercițiile, rulați comanda ``sudo apt-get install libncurses5-dev libncursesw5-dev``.
Aceasta are rolul de a instala biblioteca grafică ``ncurses`` pe sistemul vostru, bibliotecă folosită de programul ``hello_world.c``.

#. Intrați în directorul ``~/support/compile-with-lib-ex``.
#. Inspectați fișierul ``hello_world.c`` și identificați linia din program care ne arată că programul folosește biblioteca ``ncurses``.
#. Compilați programul, legați-l la biblioteca ``ncurses`` și creați executabilul ``hello_world``.
#. Verificați că programul ``hello_world`` funcționează.

.. hint::

    Pentru a lega programul la biblioteca ``ncurses`` folosiți opțiunea ``-lncurses``.