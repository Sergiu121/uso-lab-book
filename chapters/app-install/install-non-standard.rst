.. _app_install_non_standard:

Instalarea și dezinstalarea aplicațiilor în mod nestandard
==========================================================

**breviar**: aplicațiile sunt, în general, instalate dintr-un repository al distribuției; dar pot lipsi de acolo (licențiere, disponibilitate)

**breviar**: alternativ se pot instala: cu alte sisteme de pachete (Flatpak, Snap), adăugând un repository custom, descărcând pachetul furnizat

**tutorial**: pachetul pdftk (pentru prelucrarea de fișiere PDF) nu se găsește în repository dar este în snap
snap install pdftk

**tutorial**: exemplu de folosire pdftk

**exercițiu**: de instalat spotify folosind snap

**breviar**: instalarea de la furnizor se face descărcând pachetul și instalându-l, fie din GUI fie din CLI
sudo dpkg -i <package>

**tutorial**: de instalat MS Teams de la furnizor

**exercițiu**: de instalat Skype de la furnizor

**breviar**: alte aplicații nu sunt în pachete standard, se descarcă și se rulează executabilul

**tutorial**: de instalat IDA prin descărcarea și rularea executabilului

TODO: dezinstalări
