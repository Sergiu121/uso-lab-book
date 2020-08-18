Compilarea unui fișier cod sursă C
==================================

Crearea unui nou branch de lucru
--------------------------------

Își vor crea un branch cu numele lor pe care vor lucra pe parcursul acestei secțiuni.

Compilarea unui fișier cod sursă C
----------------------------------

Aici vor găsi în primul director un cod sursă C. Vor avea de compilat codul
și rulat binarul pentru a vedea că totul e în regulă. Scopul este să rezulte 2 binare: a.out
și unul denumit custom

Recompilarea programului
---------------------------

Vor face o modificare în codul sursă (oricât de mică) cu scopul de a crea un commit cu asta.
Până să comită schimbările se vor ocupa să modifice și fișierul .gitignore pentru a ignora 
fișierele generate (a.out și cel custom). Scopul este să facă 2 commit-uri diferite: unul cu 
modificările din .gitignore și unul cu codul sursă. Mesajele de commit trebuie să descrie bine 
ce au făcut.

Tot aici introducem și ideea de director /gen pentru a putea face un fișier .gitignore cât mai 
generic și să nu adauge în .gitignore toate numele de fișiere, vrem să fie universal valabil.
