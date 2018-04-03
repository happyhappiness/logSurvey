# -*- mode:po; coding:iso-latin-2; -*- Slovenian messages for GNU Wget
# Copyright (C) 2001 Free Software Foundation, Inc.
# Roman Maurer <roman.maurer@hermes.si>, 2001.
# $Id: sl.po 813 2002-04-15 16:16:09Z hniksic $
#
# Spremembe:
#
# LLLL-MM-DD     avtor     sprememba
# -------------------------------------------------------------------
# 2002-04-09     Roman     spremembe in dopolnitve za wget 1.8.1
# 2001-11-01     Roman     spremembe in dopolnitve za wget 1.7.1
# 2001-05-10     Primo¾    spremembe in dopolnitve za wget 1.6
# 1999-10-04     Roman     sprememba e-naslova
# 1999-07-09     Roman     razlièica, ki jo je TP-robot sprejel
# 1999-05-06     Roman     kot je bila poslana na lugos-slo@lugos.si
# 1999-03-11     Roman     prva razlièica
#
msgid ""
msgstr ""
"Project-Id-Version: wget 1.8.1\n"
"POT-Creation-Date: 2001-12-17 16:30+0100\n"
"PO-Revision-Date: 2002-04-09 11:00+0100\n"
"Last-Translator: Roman Maurer <roman.maurer@hermes.si>\n"
"Language-Team: Slovenian <translation-team-sl@lists.sourceforge.net>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=iso-8859-2\n"
"Content-Transfer-Encoding: 8bit\n"

#: src/connect.c:94
#, c-format
msgid "Connecting to %s[%s]:%hu... "
msgstr "Povezujem se na %s[%s]:%hu... "

#: src/connect.c:97
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Povezujem se na %s:%hu... "

#: src/connect.c:131
msgid "connected.\n"
msgstr "prikljuèen.\n"

#: src/cookies.c:595
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Napaka pri nastavitvi pi¹kota, polje ,%s`"

#: src/cookies.c:619
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "Skladenjska napaka pri nastavitvi pi¹kota na znaku ,%c`.\n"

#: src/cookies.c:627
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "Skladenjska napaka pri nastavitvi pi¹kota: niz se konèa prezgodaj.\n"

#: src/cookies.c:1329
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Datoteke s piðkoti ,%s` ni moè odpreti: %s\n"

#: src/cookies.c:1341
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Napaka pri pisanju v ,%s`: %s\n"

#: src/cookies.c:1345
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Napaka pri zapiranju ,%s`: %s\n"

#: src/ftp-ls.c:802
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "Nepodprta vrsta seznama, posku¹am z razèlenjevalnikom seznama za Unix.\n"

#: src/ftp-ls.c:847 src/ftp-ls.c:849
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Kazalo imenika /%s na %s:%d"

#: src/ftp-ls.c:871
msgid "time unknown       "
msgstr "neznan èas         "

#: src/ftp-ls.c:875
msgid "File        "
msgstr "Datoteka    "

#: src/ftp-ls.c:878
msgid "Directory   "
msgstr "Imenik      "

#: src/ftp-ls.c:881
msgid "Link        "
msgstr "Povezava    "

#: src/ftp-ls.c:884
msgid "Not sure    "
msgstr "Neznano     "

#: src/ftp-ls.c:902
#, c-format
msgid " (%s bytes)"
msgstr " (%s bajtov)"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:179
#, c-format
msgid "Logging in as %s ... "
msgstr "Prijavljam se kot %s ... "

#: src/ftp.c:188 src/ftp.c:241 src/ftp.c:272 src/ftp.c:326 src/ftp.c:419 src/ftp.c:470 src/ftp.c:500 src/ftp.c:564 src/ftp.c:628 src/ftp.c:689 src/ftp.c:737
msgid "Error in server response, closing control connection.\n"
msgstr "Napaèen odgovor, zapiram nadzorno povezavo.\n"

#: src/ftp.c:196
msgid "Error in server greeting.\n"
msgstr "Napaka v pozdravu stre¾nika.\n"

#: src/ftp.c:204 src/ftp.c:335 src/ftp.c:428 src/ftp.c:509 src/ftp.c:574 src/ftp.c:638 src/ftp.c:699 src/ftp.c:747
msgid "Write failed, closing control connection.\n"
msgstr "Pisanje neuspe¹no, zapiram nadzorno povezavo.\n"

#: src/ftp.c:211
msgid "The server refuses login.\n"
msgstr "Stre¾nik zavraèa prijavo.\n"

#: src/ftp.c:218
msgid "Login incorrect.\n"
msgstr "Napaèna prijava.\n"

#: src/ftp.c:225
msgid "Logged in!\n"
msgstr "Prijavljen!\n"

#: src/ftp.c:250
msgid "Server error, can't determine system type.\n"
msgstr "Napaka v stre¾niku, vrste sistema ni moè ugotoviti.\n"

#: src/ftp.c:260 src/ftp.c:549 src/ftp.c:612 src/ftp.c:669
msgid "done.    "
msgstr "opravljeno. "

#: src/ftp.c:314 src/ftp.c:449 src/ftp.c:484 src/ftp.c:720 src/ftp.c:768 src/host.c:283
msgid "done.\n"
msgstr "konèano.\n"

#: src/ftp.c:343
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Neznan tip `%c', zapiram nadzorno zvezo.\n"

#: src/ftp.c:356
msgid "done.  "
msgstr "opravljeno."

#: src/ftp.c:362
msgid "==> CWD not needed.\n"
msgstr "==> CWD ni potreben.\n"

#: src/ftp.c:435
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"Ni imenika z imenom `%s'.\n"
"\n"

#. do not CWD
#: src/ftp.c:453
msgid "==> CWD not required.\n"
msgstr "==> CWD ni zahtevan.\n"

#: src/ftp.c:516
msgid "Cannot initiate PASV transfer.\n"
msgstr "Ne morem zaèeti prenosa PASV.\n"

#: src/ftp.c:520
msgid "Cannot parse PASV response.\n"
msgstr "Ne morem razèleniti odgovora PASV.\n"

#: src/ftp.c:541
#, c-format
msgid "couldn't connect to %s:%hu: %s\n"
msgstr "ni se bilo moè povezati z %s:%hu: %s.\n"

#: src/ftp.c:591
#, c-format
msgid "Bind error (%s).\n"
msgstr "Napaka pri povezovanju (%s).\n"

#: src/ftp.c:598
msgid "Invalid PORT.\n"
msgstr "Neveljaven PORT.\n"

#: src/ftp.c:651
#, c-format
msgid ""
"\n"
"REST failed; will not truncate `%s'.\n"
msgstr ""
"\n"
"REST neuspe¹en; ne bomo skraj¹ali ,%s`.\n"

#: src/ftp.c:658
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"REST neuspe¹en, zaèenjam znova.\n"

#: src/ftp.c:707
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"Ni datoteke `%s'.\n"
"\n"

#: src/ftp.c:755
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"Ni datoteke ali imenika `%s'.\n"
"\n"

#: src/ftp.c:839 src/ftp.c:847
#, c-format
msgid "Length: %s"
msgstr "Dol¾ina: %s"

#: src/ftp.c:841 src/ftp.c:849
#, c-format
msgid " [%s to go]"
msgstr " [¹e %s]"

#: src/ftp.c:851
msgid " (unauthoritative)\n"
msgstr " (neavtorizirana)\n"

#: src/ftp.c:877
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, zapiram nadzorno zvezo.\n"

#: src/ftp.c:885
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Podatkovna zveza: %s; "

#: src/ftp.c:902
msgid "Control connection closed.\n"
msgstr "Nadzorna zveza prekinjena.\n"

#: src/ftp.c:920
msgid "Data transfer aborted.\n"
msgstr "Prenos podatkov prekinjen.\n"

#: src/ftp.c:984
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Datoteka `%s' ¾e obstaja, ne jemljem.\n"

#: src/ftp.c:1054 src/http.c:1527
#, c-format
msgid "(try:%2d)"
msgstr "(posk:%2d)"

#: src/ftp.c:1118 src/http.c:1786
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' posnet [%ld]\n"
"\n"

#: src/ftp.c:1160 src/main.c:819 src/recur.c:349 src/retr.c:587
#, c-format
msgid "Removing %s.\n"
msgstr "Odstranjujem %s.\n"

#: src/ftp.c:1202
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Uporabljam `%s' kot zaèasno datoteko za izpis.\n"

#: src/ftp.c:1217
#, c-format
msgid "Removed `%s'.\n"
msgstr "Odstranil `%s'.\n"

#: src/ftp.c:1252
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Globina rekurzije %d presega najveèjo dovoljeno %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1317
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Datoteka na stre¾niku ni novej¹a kot lokalna ,%s` -- ne prena¹am.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1324
#, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr ""
"Datoteka na stre¾niku je novej¹a kot lokalna ,%s` -- prena¹am.\n"
"\n"

#. Sizes do not match
#: src/ftp.c:1331
#, c-format
msgid ""
"The sizes do not match (local %ld) -- retrieving.\n"
"\n"
msgstr ""
"Velikosti se ne ujemata (lokalna %ld) -- prena¹am.\n"
"\n"

#: src/ftp.c:1348
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Neveljavno ime simbolne povezave, preskakujem.\n"

#: src/ftp.c:1365
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"Obstaja ¾e pravilna simbolna povezava %s -> %s\n"
"\n"

#: src/ftp.c:1373
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Ustvarjam simbolno povezavo %s -> %s\n"

#: src/ftp.c:1384
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Povezave niso podprte, preskakujem simbolno povezavo `%s'.\n"

#: src/ftp.c:1396
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Preskakujem imenik `%s'.\n"

#: src/ftp.c:1405
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: neznana/nepodprta vrsta datoteke.\n"

#: src/ftp.c:1432
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: okvarjena oznaèba èasa.\n"

#: src/ftp.c:1457
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Ne jemljem imenikov, ker je globina %d (maksimalno %d).\n"

#: src/ftp.c:1507
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Ne grem v `%s', ker je izkljuèen ali pa ni vkljuèen.\n"

#: src/ftp.c:1561
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Zavraèam `%s'.\n"
