# -*- mode:po; coding:iso-latin-2; -*- Slovenian messages for GNU Wget
# Copyright (C) 2001 Free Software Foundation, Inc.
# Roman Maurer <roman.maurer@amis.net>, 2001.
# $Id: sl.po 525 2001-11-17 23:12:53Z hniksic $
#
# Spremembe:
#
# LLLL-MM-DD     avtor     sprememba
# -------------------------------------------------------------------
# 2001-11-01     roman     spremembe in dopolnitve za wget 1.7.1
# 2001-05-10     primo¾    spremembe in dopolnitve za wget 1.6
# 1999-10-04     roman     sprememba e-naslova
# 1999-07-09     roman     razlièica, ki jo je TP-robot sprejel
# 1999-05-06     roman     kot je bila poslana na lugos-slo@lugos.si
# 1999-03-11     roman     prva razlièica
#
msgid ""
msgstr ""
"Project-Id-Version: wget 1.7.1-pre1\n"
"POT-Creation-Date: 2001-06-03 15:27+0200\n"
"PO-Revision-Date: 2001-11-01 21:00+0100\n"
"Last-Translator: Roman Maurer <roman.maurer@hermes.si>\n"
"Language-Team: Slovenian <sl@li.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=iso-8859-2\n"
"Content-Transfer-Encoding: 8bit\n"

#: src/cookies.c:588
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Napaka pri nastavitvi pi¹kota, polje ,%s`"

#: src/cookies.c:612
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "Skladenjska napaka pri nastavitvi pi¹kota na znaku ,%c`.\n"

#: src/cookies.c:620
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "Skladenjska napaka pri nastavitvi pi¹kota: niz se konèa prezgodaj.\n"

#: src/cookies.c:1352
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Datoteke s piðkoti ,%s` ni moè odpreti: %s\n"

#: src/cookies.c:1364
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Napaka pri pisanju v ,%s`: %s\n"

#: src/cookies.c:1368
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Napaka pri zapiranju ,%s`: %s\n"

#: src/ftp-ls.c:787
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "Nepodprta vrsta seznama, posku¹am z razèlenjevalnikom seznama za Unix.\n"

#: src/ftp-ls.c:832 src/ftp-ls.c:834
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Kazalo imenika /%s na %s:%d"

#: src/ftp-ls.c:856
msgid "time unknown       "
msgstr "neznan èas         "

#: src/ftp-ls.c:860
msgid "File        "
msgstr "Datoteka    "

#: src/ftp-ls.c:863
msgid "Directory   "
msgstr "Imenik      "

#: src/ftp-ls.c:866
msgid "Link        "
msgstr "Povezava    "

#: src/ftp-ls.c:869
msgid "Not sure    "
msgstr "Neznano     "

#: src/ftp-ls.c:887
#, c-format
msgid " (%s bytes)"
msgstr " (%s bajtov)"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:150 src/http.c:624
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Povezujem se na %s:%hu... "

#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "%s:%hu zavraèa zvezo.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:193 src/http.c:652
msgid "connected!\n"
msgstr "prikljuèen!\n"

#: src/ftp.c:194
#, c-format
msgid "Logging in as %s ... "
msgstr "Prijavljam se kot %s ... "

#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
msgid "Error in server response, closing control connection.\n"
msgstr "Napaèen odgovor, zapiram nadzorno povezavo.\n"

#: src/ftp.c:211
msgid "Error in server greeting.\n"
msgstr "Napaka v pozdravu stre¾nika.\n"

#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
msgid "Write failed, closing control connection.\n"
msgstr "Pisanje neuspe¹no, zapiram nadzorno povezavo.\n"

#: src/ftp.c:226
msgid "The server refuses login.\n"
msgstr "Stre¾nik zavraèa prijavo.\n"

#: src/ftp.c:233
msgid "Login incorrect.\n"
msgstr "Napaèna prijava.\n"

#: src/ftp.c:240
msgid "Logged in!\n"
msgstr "Prijavljen!\n"

#: src/ftp.c:265
msgid "Server error, can't determine system type.\n"
msgstr "Napaka v stre¾niku, vrste sistema ni moè ugotoviti.\n"

#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
msgid "done.    "
msgstr "opravljeno. "

#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
msgid "done.\n"
msgstr "konèano.\n"

#: src/ftp.c:353
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Neznan tip `%c', zapiram nadzorno zvezo.\n"

#: src/ftp.c:366
msgid "done.  "
msgstr "opravljeno."

#: src/ftp.c:372
msgid "==> CWD not needed.\n"
msgstr "==> CWD ni potreben.\n"

#: src/ftp.c:445
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Ni imenika z imenom `%s'.\n\n"

#. do not CWD
#: src/ftp.c:463
msgid "==> CWD not required.\n"
msgstr "==> CWD ni zahtevan.\n"

#: src/ftp.c:497
msgid "Cannot initiate PASV transfer.\n"
msgstr "Ne morem zaèeti prenosa PASV.\n"

#: src/ftp.c:501
msgid "Cannot parse PASV response.\n"
msgstr "Ne morem razèleniti odgovora PASV.\n"

#: src/ftp.c:515
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Poskusil se bom prikljuèiti na %s:%hu.\n"

#: src/ftp.c:602
#, c-format
msgid "Bind error (%s).\n"
msgstr "Napaka pri povezovanju (%s).\n"

#: src/ftp.c:618
msgid "Invalid PORT.\n"
msgstr "Neveljaven PORT.\n"

#: src/ftp.c:671
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nREST neuspe¹en; ne bomo skraj¹ali ,%s`.\n"

#: src/ftp.c:678
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST neuspe¹en, zaèenjam znova.\n"

#: src/ftp.c:727
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Ni datoteke `%s'.\n\n"

#: src/ftp.c:775
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Ni datoteke ali imenika `%s'.\n\n"

#: src/ftp.c:859 src/ftp.c:867
#, c-format
msgid "Length: %s"
msgstr "Dol¾ina: %s"

#: src/ftp.c:861 src/ftp.c:869
#, c-format
msgid " [%s to go]"
msgstr " [¹e %s]"

#: src/ftp.c:871
msgid " (unauthoritative)\n"
msgstr " (neavtorizirana)\n"

#: src/ftp.c:898
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, zapiram nadzorno zvezo.\n"

#: src/ftp.c:906
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Podatkovna zveza: %s; "

#: src/ftp.c:923
msgid "Control connection closed.\n"
msgstr "Nadzorna zveza prekinjena.\n"

#: src/ftp.c:941
msgid "Data transfer aborted.\n"
msgstr "Prenos podatkov prekinjen.\n"

#: src/ftp.c:1005
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Datoteka `%s' ¾e obstaja, ne jemljem.\n"

#: src/ftp.c:1075 src/http.c:1502
#, c-format
msgid "(try:%2d)"
msgstr "(posk:%2d)"

#: src/ftp.c:1139 src/http.c:1753
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' posnet [%ld]\n\n"

#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
#, c-format
msgid "Removing %s.\n"
msgstr "Odstranjujem %s.\n"

#: src/ftp.c:1221
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Uporabljam `%s' kot zaèasno datoteko za izpis.\n"

#: src/ftp.c:1233
#, c-format
msgid "Removed `%s'.\n"
msgstr "Odstranil `%s'.\n"

#: src/ftp.c:1269
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Globina rekurzije %d presega najveèjo dovoljeno %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1330
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Datoteka na stre¾niku ni novej¹a kot lokalna ,%s` -- ne prena¹am.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1337
#, c-format
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "Datoteka na stre¾niku je novej¹a kot lokalna ,%s` -- prena¹am.\n\n"

#. Sizes do not match
#: src/ftp.c:1344
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "Velikosti se ne ujemata (lokalna %ld) -- prena¹am.\n\n"

#: src/ftp.c:1361
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Neveljavno ime simbolne povezave, preskakujem.\n"

#: src/ftp.c:1378
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Obstaja ¾e pravilna simbolna povezava %s -> %s\n\n"

#: src/ftp.c:1386
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Ustvarjam simbolno povezavo %s -> %s\n"

#: src/ftp.c:1397
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Povezave niso podprte, preskakujem simbolno povezavo `%s'.\n"

#: src/ftp.c:1409
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Preskakujem imenik `%s'.\n"

#: src/ftp.c:1418
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: neznana/nepodprta vrsta datoteke.\n"

#: src/ftp.c:1445
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: okvarjena oznaèba èasa.\n"

#: src/ftp.c:1466
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Ne jemljem imenikov, ker je globina %d (maksimalno %d).\n"

#: src/ftp.c:1512
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Ne grem v `%s', ker je izkljuèen ali pa ni vkljuèen.\n"

#: src/ftp.c:1559
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Zavraèam `%s'.\n"
