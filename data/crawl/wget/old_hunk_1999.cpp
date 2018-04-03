# Finnish messages for wget.
# Copyright (C) 2005 Free Software Foundation, Inc.
# Petri T. Koistinen <petri.koistinen@iki.fi>, 2005.
# Proofreading by Tero Jänkä and others.
#
msgid ""
msgstr ""
"Project-Id-Version: wget 1.10.1-b1\n"
"Report-Msgid-Bugs-To: wget@sunsite.dk\n"
"POT-Creation-Date: 2007-10-22 11:58-0700\n"
"PO-Revision-Date: 2005-07-12 00:11+0300\n"
"Last-Translator: Petri T. Koistinen <petri.koistinen@iki.fi>\n"
"Language-Team: Finnish <translation-team-fi@lists.sourceforge.net>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=iso-8859-15\n"
"Content-Transfer-Encoding: 8bit\n"

#: lib/getopt.c:530 lib/getopt.c:546
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: valitsin \"%s\" on moniselkoinen\n"

#: lib/getopt.c:579 lib/getopt.c:583
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: valitsin \"--%s\" ei salli argumenttia\n"

#: lib/getopt.c:592 lib/getopt.c:597
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: valitsin \"%c%s\" ei salli argumenttia\n"

#: lib/getopt.c:640 lib/getopt.c:659 lib/getopt.c:975 lib/getopt.c:994
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: valitsin \"%s\" vaatii argumentin\n"

#: lib/getopt.c:697 lib/getopt.c:700
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: tuntematon valitsin \"--%s\"\n"

#: lib/getopt.c:708 lib/getopt.c:711
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: tuntematon valitsin \"%c%s\"\n"

#: lib/getopt.c:763 lib/getopt.c:766
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: valitsin ei kelpaa -- %c\n"

#: lib/getopt.c:772 lib/getopt.c:775
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: valitsin on virheellinen -- %c\n"

#: lib/getopt.c:827 lib/getopt.c:843 lib/getopt.c:1047 lib/getopt.c:1065
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: valitsin vaatii argumentin -- %c\n"

#: lib/getopt.c:896 lib/getopt.c:912
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: valitsin \"-W %s\" on moniselkoinen\n"

#: lib/getopt.c:936 lib/getopt.c:954
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: valitsin \"-W %s\" ei salli argumentteja\n"

#: src/connect.c:194
#, c-format
msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
msgstr "%s: lähdeosoite %s ei selvinnyt, osoitetta ei käytetä.\n"

#: src/connect.c:266
#, c-format
msgid "Connecting to %s|%s|:%d... "
msgstr "Yhdistetään palvelimeen %s|%s|:%d... "

#: src/connect.c:269
#, c-format
msgid "Connecting to %s:%d... "
msgstr "Yhdistetään palvelimeen %s:%d... "

#: src/connect.c:329
msgid "connected.\n"
msgstr "yhdistetty.\n"

#: src/connect.c:341 src/host.c:752 src/host.c:781
#, c-format
msgid "failed: %s.\n"
msgstr "epäonnistui: %s.\n"

#: src/connect.c:365 src/http.c:1628
#, fuzzy, c-format
msgid "%s: unable to resolve host address `%s'\n"
msgstr "%s: lähdeosoite %s ei selvinnyt, osoitetta ei käytetä.\n"

#: src/convert.c:169
#, fuzzy, c-format
msgid "Converted %d files in %s seconds.\n"
msgstr "Muunnettu %d tiedostoa %.*f sekunnissa.\n"

#: src/convert.c:194
#, c-format
msgid "Converting %s... "
msgstr "Muunnetaan linkkejä %s... "

#: src/convert.c:207
msgid "nothing to do.\n"
msgstr "ei ole tehtävää.\n"

#: src/convert.c:215 src/convert.c:239
#, c-format
msgid "Cannot convert links in %s: %s\n"
msgstr "Ei voida muuntaa linkkejä tiedostossa %s: %s\n"

#: src/convert.c:230
#, c-format
msgid "Unable to delete `%s': %s\n"
msgstr "Tiedostoa \"%s\" ei voitu poistaa: %s\n"

#: src/convert.c:439
#, c-format
msgid "Cannot back up %s as %s: %s\n"
msgstr "Tiedostoa %s ei voitu varmuuskopioida tiedostoon %s: %s\n"

#: src/cookies.c:442
#, c-format
msgid "Syntax error in Set-Cookie: %s at position %d.\n"
msgstr "Syntaksivirhe Set-Cookiessa: %s kohdassa %d.\n"

#: src/cookies.c:684
#, c-format
msgid "Cookie coming from %s attempted to set domain to %s\n"
msgstr ""
"Eväste, joka tuli osoitteesta %s yritti asettaa verkkotunnukseksi %s.\n"

#: src/cookies.c:1131 src/cookies.c:1249
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Evästetiedostoa \"%s\" ei voitu avata: %s\n"

#: src/cookies.c:1286
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Kirjoitettaessa tiedostoon \"%s\" tapahtui virhe: %s\n"

#: src/cookies.c:1289
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Virhe suljettaessa tiedostoa \"%s\": %s\n"

#: src/ftp-ls.c:835
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "Listaustyyppiä ei tueta, yritetään jäsentää unix-listauksena.\n"

#: src/ftp-ls.c:881 src/ftp-ls.c:883
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "/%s indeksi kohteessa %s:%d"

#: src/ftp-ls.c:906
#, c-format
msgid "time unknown       "
msgstr "tuntematon aika    "

#: src/ftp-ls.c:910
#, c-format
msgid "File        "
msgstr "Tiedosto    "

#: src/ftp-ls.c:913
#, c-format
msgid "Directory   "
msgstr "Hakemisto   "

#: src/ftp-ls.c:916
#, c-format
msgid "Link        "
msgstr "Linkki      "

#: src/ftp-ls.c:919
#, c-format
msgid "Not sure    "
msgstr "Epävarma    "

#: src/ftp-ls.c:937
#, c-format
msgid " (%s bytes)"
msgstr " (%s tavua)"

#: src/ftp.c:213
#, c-format
msgid "Length: %s"
msgstr "Pituus: %s"

#: src/ftp.c:219 src/http.c:2173
#, c-format
msgid ", %s (%s) remaining"
msgstr ", %s (%s) jäljellä"

#: src/ftp.c:223 src/http.c:2177
#, c-format
msgid ", %s remaining"
msgstr ", %s jäljellä"

#: src/ftp.c:226
msgid " (unauthoritative)\n"
msgstr " (vahvistamaton)\n"

#: src/ftp.c:302
#, c-format
msgid "Logging in as %s ... "
msgstr "Kirjaudutaan nimellä %s ... "

#: src/ftp.c:315 src/ftp.c:361 src/ftp.c:390 src/ftp.c:442 src/ftp.c:554
#: src/ftp.c:600 src/ftp.c:629 src/ftp.c:686 src/ftp.c:747 src/ftp.c:807
#: src/ftp.c:854
msgid "Error in server response, closing control connection.\n"
msgstr "Virhe palvelimen vastauksessa. Hallintayhteys suljetaan.\n"

#: src/ftp.c:322
msgid "Error in server greeting.\n"
msgstr "Virhe palvelimen tervehdyksessä.\n"

#: src/ftp.c:329 src/ftp.c:450 src/ftp.c:562 src/ftp.c:637 src/ftp.c:696
#: src/ftp.c:757 src/ftp.c:817 src/ftp.c:864
msgid "Write failed, closing control connection.\n"
msgstr "Kirjoitus epäonnistui. Hallintayhteys suljetaan.\n"

#: src/ftp.c:335
msgid "The server refuses login.\n"
msgstr "Palvelin hylkäsi kirjautumisen.\n"

#: src/ftp.c:341
msgid "Login incorrect.\n"
msgstr "Kirjautuminen epäonnistui.\n"

#: src/ftp.c:347
msgid "Logged in!\n"
msgstr "Kirjauduttu!\n"

#: src/ftp.c:369
msgid "Server error, can't determine system type.\n"
msgstr "Palvelinvirhe, järjestelmän tyyppiä ei voitu päätellä.\n"

#: src/ftp.c:378 src/ftp.c:673 src/ftp.c:730 src/ftp.c:773
msgid "done.    "
msgstr "valmis.  "

#: src/ftp.c:430 src/ftp.c:579 src/ftp.c:612 src/ftp.c:837 src/ftp.c:883
msgid "done.\n"
msgstr "valmis.\n"

#: src/ftp.c:457
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Tuntematon tyyppi \"%c\". Hallintayhteys suljetaan.\n"

#: src/ftp.c:469
msgid "done.  "
msgstr "valmis."

#: src/ftp.c:475
msgid "==> CWD not needed.\n"
msgstr "==> CWD:tä ei tarvita.\n"

#: src/ftp.c:568
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"Hakemistoa \"%s\" ei ole.\n"
"\n"

#: src/ftp.c:583
msgid "==> CWD not required.\n"
msgstr "==> CWD:tä ei vaadita.\n"

#: src/ftp.c:643
msgid "Cannot initiate PASV transfer.\n"
msgstr "PASV-siirtoa ei voitu aloittaa.\n"

#: src/ftp.c:647
msgid "Cannot parse PASV response.\n"
msgstr "PASV-vastausta ei voitu jäsentää.\n"

#: src/ftp.c:664
#, c-format
msgid "couldn't connect to %s port %d: %s\n"
msgstr "ei voitu yhdistää %s porttiin %d: %s\n"

#: src/ftp.c:712
#, c-format
msgid "Bind error (%s).\n"
msgstr "Bind-virhe (%s).\n"

#: src/ftp.c:718
msgid "Invalid PORT.\n"
msgstr "Virheellinen PORT.\n"

#: src/ftp.c:764
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"REST epäonnistui, aloitetaan alusta.\n"

#: src/ftp.c:825
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"Tiedostoa \"%s\" ei ole.\n"
"\n"

#: src/ftp.c:872
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"Tiedostoa tai hakemistoa \"%s\" ei ole.\n"
"\n"

#: src/ftp.c:934 src/http.c:2235
#, c-format
msgid "%s has sprung into existence.\n"
msgstr "%s on ilmestynyt.\n"

#: src/ftp.c:986
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, suljetaan hallintayhteys.\n"

#: src/ftp.c:995
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - tiedonsiirtoyhteys: %s; "

#: src/ftp.c:1010
msgid "Control connection closed.\n"
msgstr "Hallintayhteys suljettu.\n"

#: src/ftp.c:1028
msgid "Data transfer aborted.\n"
msgstr "Tiedonsiirto keskeytetty.\n"

#: src/ftp.c:1096
#, c-format
msgid "File `%s' already there; not retrieving.\n"
msgstr "Tiedostoa \"%s\" ei noudeta, koska se on jo paikalla.\n"

#: src/ftp.c:1164 src/http.c:2393
#, c-format
msgid "(try:%2d)"
msgstr "(yritys:%2d)"

#: src/ftp.c:1234 src/http.c:2716
#, c-format
msgid ""
"%s (%s) - `%s' saved [%s]\n"
"\n"
msgstr ""
"%s (%s) - \"%s\" tallennettu [%s]\n"
"\n"

#: src/ftp.c:1276 src/main.c:1006 src/recur.c:377 src/retr.c:859
#, c-format
msgid "Removing %s.\n"
msgstr "Poistetaan %s.\n"

#: src/ftp.c:1318
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Listaus tallennetaan väliaikaisesti \"%s\" tiedostoon.\n"

#: src/ftp.c:1333
#, c-format
msgid "Removed `%s'.\n"
msgstr "\"%s\" poistettu.\n"

#: src/ftp.c:1366
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Rekursiosyvyys %d on ylittänyt sallitun syvyyden %d.\n"

#: src/ftp.c:1436
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Etätiedosto \"%s\" ei ole paikallista uudempi -- ei noudeta.\n"

#: src/ftp.c:1443
#, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr ""
"Etätiedosto \"%s\" on uudempi kuin paikallinen -- noudetaan.\n"
"\n"

#: src/ftp.c:1450
#, c-format
msgid ""
"The sizes do not match (local %s) -- retrieving.\n"
"\n"
msgstr ""
"Koot eivät täsmää (paikallinen %s) -- noudetaan.\n"
"\n"

#: src/ftp.c:1468
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Symbolisen linkin nimi on virheellinen, ohitetaan.\n"

#: src/ftp.c:1485
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
