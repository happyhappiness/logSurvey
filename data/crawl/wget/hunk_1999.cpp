+# translation of wget-1.11-b2425.po to translation-team-fi
 # Finnish messages for wget.
-# Copyright (C) 2005 Free Software Foundation, Inc.
-# Petri T. Koistinen <petri.koistinen@iki.fi>, 2005.
-# Proofreading by Tero J�nk� and others.
+# Copyright © 2005, 2007 Free Software Foundation, Inc.
+# This file is distributed under the same license as the wget package.
+# Proofreading by Tero Jänkä and others.
 #
+# Petri T. Koistinen <petri.koistinen@iki.fi>, 2005.
+# Jorma Karvonen <karvjorm@users.sf.net>, 2007.
 msgid ""
 msgstr ""
-"Project-Id-Version: wget 1.10.1-b1\n"
+"Project-Id-Version: wget 1.11-b2425\n"
 "Report-Msgid-Bugs-To: wget@sunsite.dk\n"
-"POT-Creation-Date: 2007-10-22 11:58-0700\n"
-"PO-Revision-Date: 2005-07-12 00:11+0300\n"
-"Last-Translator: Petri T. Koistinen <petri.koistinen@iki.fi>\n"
+"POT-Creation-Date: 2008-02-06 18:23-0800\n"
+"PO-Revision-Date: 2007-12-23 00:44+0200\n"
+"Last-Translator: Jorma Karvonen <karvjorm@users.sf.net>\n"
 "Language-Team: Finnish <translation-team-fi@lists.sourceforge.net>\n"
 "MIME-Version: 1.0\n"
-"Content-Type: text/plain; charset=iso-8859-15\n"
+"Content-Type: text/plain; charset=UTF-8\n"
 "Content-Transfer-Encoding: 8bit\n"
+"Plural-Forms: nplurals=2; plural=(n != 1);\n"
+"X-Generator: KBabel 1.11.4\n"
 
 #: lib/getopt.c:530 lib/getopt.c:546
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
-msgstr "%s: valitsin \"%s\" on moniselkoinen\n"
+msgstr "%s: valitsin ”%s” on moniselkoinen\n"
 
 #: lib/getopt.c:579 lib/getopt.c:583
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
-msgstr "%s: valitsin \"--%s\" ei salli argumenttia\n"
+msgstr "%s: valitsin ”--%s” ei salli argumenttia\n"
 
 #: lib/getopt.c:592 lib/getopt.c:597
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
-msgstr "%s: valitsin \"%c%s\" ei salli argumenttia\n"
+msgstr "%s: valitsin ”%c%s” ei salli argumenttia\n"
 
 #: lib/getopt.c:640 lib/getopt.c:659 lib/getopt.c:975 lib/getopt.c:994
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
-msgstr "%s: valitsin \"%s\" vaatii argumentin\n"
+msgstr "%s: valitsin ”%s” vaatii argumentin\n"
 
 #: lib/getopt.c:697 lib/getopt.c:700
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
-msgstr "%s: tuntematon valitsin \"--%s\"\n"
+msgstr "%s: tuntematon valitsin ”--%s”\n"
 
 #: lib/getopt.c:708 lib/getopt.c:711
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
-msgstr "%s: tuntematon valitsin \"%c%s\"\n"
+msgstr "%s: tuntematon valitsin ”%c%s”\n"
 
 #: lib/getopt.c:763 lib/getopt.c:766
 #, c-format
 msgid "%s: illegal option -- %c\n"
-msgstr "%s: valitsin ei kelpaa -- %c\n"
+msgstr "%s: valitsin ei kelpaa – %c\n"
 
 #: lib/getopt.c:772 lib/getopt.c:775
 #, c-format
 msgid "%s: invalid option -- %c\n"
-msgstr "%s: valitsin on virheellinen -- %c\n"
+msgstr "%s: valitsin on virheellinen – %c\n"
 
 #: lib/getopt.c:827 lib/getopt.c:843 lib/getopt.c:1047 lib/getopt.c:1065
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
-msgstr "%s: valitsin vaatii argumentin -- %c\n"
+msgstr "%s: valitsin vaatii argumentin – %c\n"
 
 #: lib/getopt.c:896 lib/getopt.c:912
 #, c-format
 msgid "%s: option `-W %s' is ambiguous\n"
-msgstr "%s: valitsin \"-W %s\" on moniselkoinen\n"
+msgstr "%s: valitsin ”-W %s” on moniselkoinen\n"
 
 #: lib/getopt.c:936 lib/getopt.c:954
 #, c-format
 msgid "%s: option `-W %s' doesn't allow an argument\n"
-msgstr "%s: valitsin \"-W %s\" ei salli argumentteja\n"
+msgstr "%s: valitsin ”-W %s” ei salli argumentteja\n"
 
-#: src/connect.c:194
+#: src/connect.c:195
 #, c-format
 msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
-msgstr "%s: l�hdeosoite %s ei selvinnyt, osoitetta ei k�ytet�.\n"
+msgstr "%s: lähdeosoite %s ei selvinnyt, osoitetta ei käytetä.\n"
 
-#: src/connect.c:266
+#: src/connect.c:267
 #, c-format
 msgid "Connecting to %s|%s|:%d... "
-msgstr "Yhdistet��n palvelimeen %s|%s|:%d... "
+msgstr "Yhdistetään palvelimeen %s|%s|:%d... "
 
-#: src/connect.c:269
+#: src/connect.c:270
 #, c-format
 msgid "Connecting to %s:%d... "
-msgstr "Yhdistet��n palvelimeen %s:%d... "
+msgstr "Yhdistetään palvelimeen %s:%d... "
 
-#: src/connect.c:329
+#: src/connect.c:330
 msgid "connected.\n"
 msgstr "yhdistetty.\n"
 
-#: src/connect.c:341 src/host.c:752 src/host.c:781
+#: src/connect.c:342 src/host.c:753 src/host.c:782
 #, c-format
 msgid "failed: %s.\n"
-msgstr "ep�onnistui: %s.\n"
+msgstr "epäonnistui: %s.\n"
 
-#: src/connect.c:365 src/http.c:1628
-#, fuzzy, c-format
+#: src/connect.c:366 src/http.c:1632
+#, c-format
 msgid "%s: unable to resolve host address `%s'\n"
-msgstr "%s: l�hdeosoite %s ei selvinnyt, osoitetta ei k�ytet�.\n"
+msgstr "%s: ei kyetty ratkaisemaan palvelinosoitetta ”%s”\n"
 
-#: src/convert.c:169
-#, fuzzy, c-format
+#: src/convert.c:170
+#, c-format
 msgid "Converted %d files in %s seconds.\n"
-msgstr "Muunnettu %d tiedostoa %.*f sekunnissa.\n"
+msgstr "Muunnettu %d tiedostoa %s sekunnissa.\n"
 
-#: src/convert.c:194
+#: src/convert.c:197
 #, c-format
 msgid "Converting %s... "
-msgstr "Muunnetaan linkkej� %s... "
+msgstr "Muunnetaan linkkejä %s... "
 
-#: src/convert.c:207
+#: src/convert.c:210
 msgid "nothing to do.\n"
-msgstr "ei ole teht�v��.\n"
+msgstr "ei ole tehtävää.\n"
 
-#: src/convert.c:215 src/convert.c:239
+#: src/convert.c:218 src/convert.c:242
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
-msgstr "Ei voida muuntaa linkkej� tiedostossa %s: %s\n"
+msgstr "Ei voida muuntaa linkkejä tiedostossa %s: %s\n"
 
-#: src/convert.c:230
+#: src/convert.c:233
 #, c-format
 msgid "Unable to delete `%s': %s\n"
-msgstr "Tiedostoa \"%s\" ei voitu poistaa: %s\n"
+msgstr "Tiedostoa ”%s” ei voitu poistaa: %s\n"
 
-#: src/convert.c:439
+#: src/convert.c:442
 #, c-format
 msgid "Cannot back up %s as %s: %s\n"
 msgstr "Tiedostoa %s ei voitu varmuuskopioida tiedostoon %s: %s\n"
 
-#: src/cookies.c:442
+#: src/cookies.c:443
 #, c-format
 msgid "Syntax error in Set-Cookie: %s at position %d.\n"
 msgstr "Syntaksivirhe Set-Cookiessa: %s kohdassa %d.\n"
 
-#: src/cookies.c:684
+#: src/cookies.c:685
 #, c-format
 msgid "Cookie coming from %s attempted to set domain to %s\n"
 msgstr ""
-"Ev�ste, joka tuli osoitteesta %s yritti asettaa verkkotunnukseksi %s.\n"
+"Eväste, joka tuli osoitteesta %s yritti asettaa verkkotunnukseksi %s.\n"
 
-#: src/cookies.c:1131 src/cookies.c:1249
+#: src/cookies.c:1132 src/cookies.c:1250
 #, c-format
 msgid "Cannot open cookies file `%s': %s\n"
-msgstr "Ev�stetiedostoa \"%s\" ei voitu avata: %s\n"
+msgstr "Evästetiedostoa ”%s” ei voitu avata: %s\n"
 
-#: src/cookies.c:1286
+#: src/cookies.c:1287
 #, c-format
 msgid "Error writing to `%s': %s\n"
-msgstr "Kirjoitettaessa tiedostoon \"%s\" tapahtui virhe: %s\n"
+msgstr "Kirjoitettaessa tiedostoon ”%s” tapahtui virhe: %s\n"
 
-#: src/cookies.c:1289
+#: src/cookies.c:1290
 #, c-format
 msgid "Error closing `%s': %s\n"
-msgstr "Virhe suljettaessa tiedostoa \"%s\": %s\n"
+msgstr "Virhe suljettaessa tiedostoa ”%s”: %s\n"
 
-#: src/ftp-ls.c:835
+#: src/ftp-ls.c:836
 msgid "Unsupported listing type, trying Unix listing parser.\n"
-msgstr "Listaustyyppi� ei tueta, yritet��n j�sent�� unix-listauksena.\n"
+msgstr "Listaustyyppiä ei tueta, yritetään jäsentää unix-listauksena.\n"
 
-#: src/ftp-ls.c:881 src/ftp-ls.c:883
+#: src/ftp-ls.c:882 src/ftp-ls.c:884
 #, c-format
 msgid "Index of /%s on %s:%d"
 msgstr "/%s indeksi kohteessa %s:%d"
 
-#: src/ftp-ls.c:906
+#: src/ftp-ls.c:907
 #, c-format
 msgid "time unknown       "
 msgstr "tuntematon aika    "
 
-#: src/ftp-ls.c:910
+#: src/ftp-ls.c:911
 #, c-format
 msgid "File        "
 msgstr "Tiedosto    "
 
-#: src/ftp-ls.c:913
+#: src/ftp-ls.c:914
 #, c-format
 msgid "Directory   "
 msgstr "Hakemisto   "
 
-#: src/ftp-ls.c:916
+#: src/ftp-ls.c:917
 #, c-format
 msgid "Link        "
 msgstr "Linkki      "
 
-#: src/ftp-ls.c:919
+#: src/ftp-ls.c:920
 #, c-format
 msgid "Not sure    "
-msgstr "Ep�varma    "
+msgstr "Epävarma    "
 
-#: src/ftp-ls.c:937
+#: src/ftp-ls.c:938
 #, c-format
 msgid " (%s bytes)"
 msgstr " (%s tavua)"
 
-#: src/ftp.c:213
+#: src/ftp.c:214
 #, c-format
 msgid "Length: %s"
 msgstr "Pituus: %s"
 
-#: src/ftp.c:219 src/http.c:2173
+#: src/ftp.c:220 src/http.c:2183
 #, c-format
 msgid ", %s (%s) remaining"
-msgstr ", %s (%s) j�ljell�"
+msgstr ", %s (%s) jäljellä"
 
-#: src/ftp.c:223 src/http.c:2177
+#: src/ftp.c:224 src/http.c:2187
 #, c-format
 msgid ", %s remaining"
-msgstr ", %s j�ljell�"
+msgstr ", %s jäljellä"
 
-#: src/ftp.c:226
+#: src/ftp.c:227
 msgid " (unauthoritative)\n"
 msgstr " (vahvistamaton)\n"
 
-#: src/ftp.c:302
+#: src/ftp.c:303
 #, c-format
 msgid "Logging in as %s ... "
-msgstr "Kirjaudutaan nimell� %s ... "
+msgstr "Kirjaudutaan nimellä %s ... "
 
-#: src/ftp.c:315 src/ftp.c:361 src/ftp.c:390 src/ftp.c:442 src/ftp.c:554
-#: src/ftp.c:600 src/ftp.c:629 src/ftp.c:686 src/ftp.c:747 src/ftp.c:807
-#: src/ftp.c:854
+#: src/ftp.c:316 src/ftp.c:362 src/ftp.c:391 src/ftp.c:443 src/ftp.c:555
+#: src/ftp.c:601 src/ftp.c:630 src/ftp.c:687 src/ftp.c:748 src/ftp.c:808
+#: src/ftp.c:855
 msgid "Error in server response, closing control connection.\n"
 msgstr "Virhe palvelimen vastauksessa. Hallintayhteys suljetaan.\n"
 
-#: src/ftp.c:322
+#: src/ftp.c:323
 msgid "Error in server greeting.\n"
-msgstr "Virhe palvelimen tervehdyksess�.\n"
+msgstr "Virhe palvelimen tervehdyksessä.\n"
 
-#: src/ftp.c:329 src/ftp.c:450 src/ftp.c:562 src/ftp.c:637 src/ftp.c:696
-#: src/ftp.c:757 src/ftp.c:817 src/ftp.c:864
+#: src/ftp.c:330 src/ftp.c:451 src/ftp.c:563 src/ftp.c:638 src/ftp.c:697
+#: src/ftp.c:758 src/ftp.c:818 src/ftp.c:865
 msgid "Write failed, closing control connection.\n"
-msgstr "Kirjoitus ep�onnistui. Hallintayhteys suljetaan.\n"
+msgstr "Kirjoitus epäonnistui. Hallintayhteys suljetaan.\n"
 
-#: src/ftp.c:335
+#: src/ftp.c:336
 msgid "The server refuses login.\n"
-msgstr "Palvelin hylk�si kirjautumisen.\n"
+msgstr "Palvelin hylkäsi kirjautumisen.\n"
 
-#: src/ftp.c:341
+#: src/ftp.c:342
 msgid "Login incorrect.\n"
-msgstr "Kirjautuminen ep�onnistui.\n"
+msgstr "Kirjautuminen epäonnistui.\n"
 
-#: src/ftp.c:347
+#: src/ftp.c:348
 msgid "Logged in!\n"
 msgstr "Kirjauduttu!\n"
 
-#: src/ftp.c:369
+#: src/ftp.c:370
 msgid "Server error, can't determine system type.\n"
-msgstr "Palvelinvirhe, j�rjestelm�n tyyppi� ei voitu p��tell�.\n"
+msgstr "Palvelinvirhe, järjestelmän tyyppiä ei voitu päätellä.\n"
 
-#: src/ftp.c:378 src/ftp.c:673 src/ftp.c:730 src/ftp.c:773
+#: src/ftp.c:379 src/ftp.c:674 src/ftp.c:731 src/ftp.c:774
 msgid "done.    "
 msgstr "valmis.  "
 
-#: src/ftp.c:430 src/ftp.c:579 src/ftp.c:612 src/ftp.c:837 src/ftp.c:883
+#: src/ftp.c:431 src/ftp.c:580 src/ftp.c:613 src/ftp.c:838 src/ftp.c:884
 msgid "done.\n"
 msgstr "valmis.\n"
 
-#: src/ftp.c:457
+#: src/ftp.c:458
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
-msgstr "Tuntematon tyyppi \"%c\". Hallintayhteys suljetaan.\n"
+msgstr "Tuntematon tyyppi ”%c”. Hallintayhteys suljetaan.\n"
 
-#: src/ftp.c:469
+#: src/ftp.c:470
 msgid "done.  "
 msgstr "valmis."
 
-#: src/ftp.c:475
+#: src/ftp.c:476
 msgid "==> CWD not needed.\n"
-msgstr "==> CWD:t� ei tarvita.\n"
+msgstr "==> CWD:tä ei tarvita.\n"
 
-#: src/ftp.c:568
+#: src/ftp.c:569
 #, c-format
 msgid ""
 "No such directory `%s'.\n"
 "\n"
 msgstr ""
-"Hakemistoa \"%s\" ei ole.\n"
+"Hakemistoa ”%s” ei ole.\n"
 "\n"
 
-#: src/ftp.c:583
+#: src/ftp.c:584
 msgid "==> CWD not required.\n"
-msgstr "==> CWD:t� ei vaadita.\n"
+msgstr "==> CWD:tä ei vaadita.\n"
 
-#: src/ftp.c:643
+#: src/ftp.c:644
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "PASV-siirtoa ei voitu aloittaa.\n"
 
-#: src/ftp.c:647
+#: src/ftp.c:648
 msgid "Cannot parse PASV response.\n"
-msgstr "PASV-vastausta ei voitu j�sent��.\n"
+msgstr "PASV-vastausta ei voitu jäsentää.\n"
 
-#: src/ftp.c:664
+#: src/ftp.c:665
 #, c-format
 msgid "couldn't connect to %s port %d: %s\n"
-msgstr "ei voitu yhdist�� %s porttiin %d: %s\n"
+msgstr "ei voitu yhdistää %s porttiin %d: %s\n"
 
-#: src/ftp.c:712
+#: src/ftp.c:713
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Bind-virhe (%s).\n"
 
-#: src/ftp.c:718
+#: src/ftp.c:719
 msgid "Invalid PORT.\n"
-msgstr "Virheellinen PORT.\n"
+msgstr "Virheellinen PORTti.\n"
 
-#: src/ftp.c:764
+#: src/ftp.c:765
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
 msgstr ""
 "\n"
-"REST ep�onnistui, aloitetaan alusta.\n"
+"REST epäonnistui, aloitetaan alusta.\n"
 
-#: src/ftp.c:825
+#: src/ftp.c:826
 #, c-format
 msgid ""
 "No such file `%s'.\n"
 "\n"
 msgstr ""
-"Tiedostoa \"%s\" ei ole.\n"
+"Tiedostoa ”%s” ei ole.\n"
 "\n"
 
-#: src/ftp.c:872
+#: src/ftp.c:873
 #, c-format
 msgid ""
 "No such file or directory `%s'.\n"
 "\n"
 msgstr ""
-"Tiedostoa tai hakemistoa \"%s\" ei ole.\n"
+"Tiedostoa tai hakemistoa ”%s” ei ole.\n"
 "\n"
 
-#: src/ftp.c:934 src/http.c:2235
+#: src/ftp.c:935 src/http.c:2245
 #, c-format
 msgid "%s has sprung into existence.\n"
 msgstr "%s on ilmestynyt.\n"
 
-#: src/ftp.c:986
+#: src/ftp.c:987
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, suljetaan hallintayhteys.\n"
 
-#: src/ftp.c:995
+#: src/ftp.c:996
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - tiedonsiirtoyhteys: %s; "
 
-#: src/ftp.c:1010
+#: src/ftp.c:1011
 msgid "Control connection closed.\n"
 msgstr "Hallintayhteys suljettu.\n"
 
-#: src/ftp.c:1028
+#: src/ftp.c:1029
 msgid "Data transfer aborted.\n"
 msgstr "Tiedonsiirto keskeytetty.\n"
 
-#: src/ftp.c:1096
+#: src/ftp.c:1097
 #, c-format
 msgid "File `%s' already there; not retrieving.\n"
-msgstr "Tiedostoa \"%s\" ei noudeta, koska se on jo paikalla.\n"
+msgstr "Tiedostoa ”%s” ei noudeta, koska se on jo paikalla.\n"
 
-#: src/ftp.c:1164 src/http.c:2393
+#: src/ftp.c:1165 src/http.c:2423
 #, c-format
 msgid "(try:%2d)"
 msgstr "(yritys:%2d)"
 
-#: src/ftp.c:1234 src/http.c:2716
+#: src/ftp.c:1235 src/http.c:2746
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%s]\n"
 "\n"
 msgstr ""
-"%s (%s) - \"%s\" tallennettu [%s]\n"
+"%s (%s) - ”%s” tallennettu [%s]\n"
 "\n"
 
-#: src/ftp.c:1276 src/main.c:1006 src/recur.c:377 src/retr.c:859
+#: src/ftp.c:1277 src/main.c:1010 src/recur.c:378 src/retr.c:860
 #, c-format
 msgid "Removing %s.\n"
 msgstr "Poistetaan %s.\n"
 
-#: src/ftp.c:1318
+#: src/ftp.c:1319
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
-msgstr "Listaus tallennetaan v�liaikaisesti \"%s\" tiedostoon.\n"
+msgstr "Listaus tallennetaan väliaikaisesti ”%s” tiedostoon.\n"
 
-#: src/ftp.c:1333
+#  Tähän lisäsin ylimääräisen sanan, jotta lause alkaisi isolla kirjaimella.
+#: src/ftp.c:1334
 #, c-format
 msgid "Removed `%s'.\n"
-msgstr "\"%s\" poistettu.\n"
+msgstr "Listatiedosto ”%s” poistettu.\n"
 
-#: src/ftp.c:1366
+#: src/ftp.c:1367
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
-msgstr "Rekursiosyvyys %d on ylitt�nyt sallitun syvyyden %d.\n"
+msgstr "Rekursiosyvyys %d on ylittänyt sallitun syvyyden %d.\n"
 
-#: src/ftp.c:1436
+#  Kahdessa seuraavassa olen otaksunut, että etätiedosto
+#  ja paikallinen ovat samannimisiä ja siksi tiedoston
+#  nimen paikkaa voi vaihtaa.
+#: src/ftp.c:1437
 #, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
-msgstr "Et�tiedosto \"%s\" ei ole paikallista uudempi -- ei noudeta.\n"
+msgstr "Etätiedosto ”%s” ei ole uudempi kuin paikallinen – ei noudeta.\n"
 
-#: src/ftp.c:1443
+#: src/ftp.c:1444
 #, c-format
 msgid ""
 "Remote file is newer than local file `%s' -- retrieving.\n"
 "\n"
 msgstr ""
-"Et�tiedosto \"%s\" on uudempi kuin paikallinen -- noudetaan.\n"
+"Etätiedosto ”%s” on uudempi kuin paikallinen – noudetaan.\n"
 "\n"
 
-#: src/ftp.c:1450
+#: src/ftp.c:1451
 #, c-format
 msgid ""
 "The sizes do not match (local %s) -- retrieving.\n"
 "\n"
 msgstr ""
-"Koot eiv�t t�sm�� (paikallinen %s) -- noudetaan.\n"
+"Koot eivät täsmää (paikallinen %s) – noudetaan.\n"
 "\n"
 
-#: src/ftp.c:1468
+#: src/ftp.c:1469
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr "Symbolisen linkin nimi on virheellinen, ohitetaan.\n"
 
-#: src/ftp.c:1485
+#: src/ftp.c:1486
 #, c-format
 msgid ""
 "Already have correct symlink %s -> %s\n"
