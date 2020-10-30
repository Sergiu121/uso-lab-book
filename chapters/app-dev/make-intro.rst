.. _app_dev_compile_source_file:

Compilarea unui fișier cod sursă C
==================================

În această secțiune vom crea un program care verifică dacă un număr citit de la tastatură este prim sau nu.
Vom scrie într-un nou fișier algoritmul, vom compila codul sursă folosind `compilatorul GNU Compiler Collection <https://gcc.gnu.org>`_ (*GCC*) și vom testa că programul funcționează.

.. _app_dev_create_source_file:

Crearea unui fișier cod sursă
-----------------------------

Creăm fișierul ``is-prime.c`` folosind Nano, ca în imaginea de mai jos:

.. figure:: gifs/create-is-prime.gif
    :alt: Crearea unui fișier ``is-prime.c`` cu algoritmul asociat

Conținutul fișierului ``is-prime.c`` este următorul:

.. code-block:: c

    #include <stdio.h>

    int check_if_prime(int n)
    {
        int i;

        for (i = 2; i < n / 2; i++) {
            if (n % i) {
                return 0;
            }
        }

        return 1;
    }

    int main(void)
    {
        int n;

        printf("Please gimme a number: ");
        scanf("%d", &n);
        
        if (check_if_prime(n)) {
            printf("%d is prime\n", n);
        } else {
            printf("%d is not prime\n", n);
        }

        return 0;
    }

.. _app_dev_compile_aout:

Compilarea codului sursă în executabilul ``a.out``
--------------------------------------------------

Compilăm codul sursă pe care l-am scris în fișierul ``is-prime.c`` pentru a obține un program pe care putem să îl rulăm pe sistemul nostru.
Acest program este de fapt un **executabil** (*binar*).
Executabilele sunt fișiere care conțin instrucțiuni pe care procesorul știe să le interpreteze și să le ruleze.

Creăm un executabil din fișierul ``is-prime.c`` folosind comanda ``gcc``:

.. code-block:: bash

    student@uso:~$ gcc is-prime.c 
    student@uso:~$ ls -l
    total 16
    -rwxr-xr-x 1 student student 8448 Oct 26 06:34 a.out
    -rw-r--r-- 1 student student  406 Oct 26 06:17 is-prime.c

Executabilul se numește ``a.out``.
Verificăm că fișierul ``a.out`` este într-adevăr un fișier executabil:

.. code-block:: bash

    student@uso:~$ file a.out 
    a.out: ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/l, for GNU/Linux 3.2.0, BuildID[sha1]=14553360a84b6dbe4dba5f287a665047572bde7f, not stripped

*ELF 64-bit LSB shared object* din output ne indică acest lucru.

Rulăm executabilul ``a.out`` în felul următor și introducem de la tastatură un număr:

.. code-block:: bash

    student@uso:~$ ./a.out
    Please gimme a number: 13
    13 is not prime

.. _app_dev_compile_custom:

Compilarea codului sursă într-un executabil cu nume diferit
-----------------------------------------------------------

Numele ``a.out`` nu este intuitiv, vrem ca executabilele să aibă un nume care să sugereze ceea ce fac.
Spre exemplu, pentru programul care verifică dacă un număr este prim sau nu, numim executabilul ``is-prime``.
Creăm un executabil cu numele ``is-prime`` din fișierul ``is-prime.c`` folosind comanda ``gcc``:

.. code-block:: bash

    student@uso:~$ gcc -o is-prime is-prime.c 
    student@uso:~$ ls -l
    total 28
    -rwxr-xr-x 1 student student 8448 Oct 26 06:34 a.out
    -rwxr-xr-x 1 student student 8448 Oct 26 06:57 is-prime
    -rw-r--r-- 1 student student  406 Oct 26 06:17 is-prime.c
    student@uso:~$ file is-prime
    is-prime: ELF 64-bit LSB shared object, x86-64, version 1 (SYSV), dynamically linked, interpreter /lib64/l, for GNU/Linux 3.2.0, BuildID[sha1]=14553360a84b6dbe4dba5f287a665047572bde7f, not stripped

Opțiunea ``-o`` urmată de numele ales pentru program(``is-prime``) specifică compilatorului ca programul să se numească ``is-prime``, și nu ``a.out``.
Rulăm executabilul ``is-prime`` în felul următor și introducem de la tastatură un număr:

.. code-block:: bash

    student@uso:~$ ./is-prime
    Please gimme a number: 13
    13 is not prime

Vedem că programele ``a.out`` și ``is-prime`` au același comportament, dar au nume diferit.
Acest lucru este normal deoarece ele sunt 2 fișiere executabile obținute din același fișier cod sursă obținute folosind același compilator: GCC.

.. _app_dev_make_intro_ex:

Exerciții
---------

* Creați un fișier cu numele ``is-palindrome.c`` care să conțină următorul conținut:

  .. code-block:: c

    #include <stdio.h>

    int check_if_palindrome(int n)
    {
        int new_n = 0;

        while (n > 0) {
            int r = n % 10;
            n /= 10;
            new_n = new_n * 10 + r;
        }

        return (new_n == n) ? 1 : 0;
    }

    int main(void)
    {
        int n;

        printf("Please gimme a number: ");
        scanf("%d", &n);
        
        if (check_if_palindrome(n)) {
            printf("%d is a palindome\n", n);
        } else {
            printf("%d is not a palindrome\n", n);
        }

        return 0;
    }

* Compilați fișierul ``is-palindrome.c`` într-un executabil cu numele ``a.out`` folosind ``gcc``.
  Verificați funcționalitatea programului.
* Compilați fișierul ``is-palindrome.c`` într-un executabil cu numele ``is-palindrome`` folosind ``gcc``.
  Verificați funcționalitatea programului.