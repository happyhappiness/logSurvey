# Polish translation of wget.
# Copyright (C) 2000 Free Software Foundation, Inc.
# Grzegorz Kowal <g_kowal@poczta.onet.pl>, 2000.
#
msgid ""
msgstr ""
"Project-Id-Version: GNU Wget 1.7-dev\n"
"POT-Creation-Date: 2000-12-10 03:30+0100\n"
"PO-Revision-Date: 2000-09-15 23:44+0200\n"
"Last-Translator: Grzegorz Kowal <g_kowal@poczta.onet.pl>\n"
"Language-Team: Polish <pl@li.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=iso-8859-2\n"
"Content-Transfer-Encoding: 8bit\n"

#: src/ftp-ls.c:698 src/ftp-ls.c:700
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Indeks /%s dla %s:%d"

#: src/ftp-ls.c:722
msgid "time unknown       "
msgstr "nieznany czas      "

#: src/ftp-ls.c:726
msgid "File        "
msgstr "Plik        "

#: src/ftp-ls.c:729
msgid "Directory   "
msgstr "Katalog     "

#: src/ftp-ls.c:732
msgid "Link        "
msgstr "??cze       "

#: src/ftp-ls.c:735
msgid "Not sure    "
msgstr "Niepewne    "

#: src/ftp-ls.c:753
#, c-format
msgid " (%s bytes)"
msgstr " (%s bajtów)"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:152 src/http.c:582
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "??czenie si? z %s:%hu... "

#: src/ftp.c:174 src/ftp.c:520 src/http.c:599
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Po??czenie z %s:%hu zosta?o odrzucone.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:195 src/http.c:610
msgid "connected!\n"
msgstr "po??czony!\n"

#: src/ftp.c:196
#, c-format
msgid "Logging in as %s ... "
msgstr "Logowanie si? jako %s ... "

#: src/ftp.c:205 src/ftp.c:258 src/ftp.c:289 src/ftp.c:314 src/ftp.c:410
#: src/ftp.c:462 src/ftp.c:556 src/ftp.c:629 src/ftp.c:677 src/ftp.c:725
msgid "Error in server response, closing control connection.\n"
msgstr "B??d w odpowiedzi serwera, zamykanie po??czenia kontrolnego.\n"

#: src/ftp.c:213
msgid "Error in server greeting.\n"
msgstr "B??d w powitaniu serwera.\n"

#: src/ftp.c:221 src/ftp.c:323 src/ftp.c:419 src/ftp.c:471 src/ftp.c:566
#: src/ftp.c:639 src/ftp.c:687 src/ftp.c:735
msgid "Write failed, closing control connection.\n"
msgstr "B??d zapisu, zamykanie po??czenia kontrolnego.\n"

#: src/ftp.c:228
msgid "The server refuses login.\n"
msgstr "Serwer odrzuci? login.\n"

#: src/ftp.c:235
msgid "Login incorrect.\n"
msgstr "Nieprawid?owy login.\n"

#: src/ftp.c:242
msgid "Logged in!\n"
msgstr "Zalogowany!\n"

#: src/ftp.c:267
msgid "Server error, can't determine system type.\n"
msgstr ""

#: src/ftp.c:277 src/ftp.c:541 src/ftp.c:613 src/ftp.c:657
msgid "done.    "
msgstr "zrobione.  "

#: src/ftp.c:303 src/ftp.c:440 src/ftp.c:708 src/ftp.c:756 src/url.c:1432
msgid "done.\n"
msgstr "zrobione.\n"

#: src/ftp.c:331
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Nieznany typ `%c', zamykanie po??czenia kontrolnego.\n"

#: src/ftp.c:344
msgid "done.  "
msgstr "zrobione. "

#: src/ftp.c:350
msgid "==> CWD not needed.\n"
msgstr "==> CWD nie jest potrzebne.\n"

#: src/ftp.c:426
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"Nie ma takiego katalogu `%s'.\n"
"\n"

#. do not CWD
#: src/ftp.c:444
msgid "==> CWD not required.\n"
msgstr "==> CWD nie jest wymagany.\n"

#: src/ftp.c:478
msgid "Cannot initiate PASV transfer.\n"
msgstr "Nie mog? zainicjowa? transferu PASV.\n"

#: src/ftp.c:482
msgid "Cannot parse PASV response.\n"
msgstr "Nie mog? przetworzy? odpowiedzi PASV.\n"

#: src/ftp.c:496
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Spróbuj? po??czy? si? z %s:%hu.\n"

#: src/ftp.c:583
#, c-format
msgid "Bind error (%s).\n"
msgstr "B??d przywi?zania (%s).\n"

#: src/ftp.c:599
msgid "Invalid PORT.\n"
msgstr "Nieprawid?owy PORT.\n"

#: src/ftp.c:646
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"Wykonanie REST nie powiod?o si?, zaczynam od pocz?tku.\n"

#: src/ftp.c:695
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"Nie ma takiego pliku `%s'.\n"
"\n"

#: src/ftp.c:743
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"Nie ma takiego pliku lub katalogu `%s'.\n"
"\n"

#: src/ftp.c:819 src/ftp.c:826
#, c-format
msgid "Length: %s"
msgstr "D?ugo??: %s"

#: src/ftp.c:821 src/ftp.c:828
#, c-format
msgid " [%s to go]"
msgstr " [pozosta?o %s]"

#: src/ftp.c:830
msgid " (unauthoritative)\n"
msgstr " (nieautorytatywny)\n"

#: src/ftp.c:856
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, zamykam po??czenie kontrolne.\n"

#: src/ftp.c:864
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Po??czenie danych: %s; "

#: src/ftp.c:881
msgid "Control connection closed.\n"
msgstr "Po??czenie kontrolne zosta?o zamkni?te.\n"

#: src/ftp.c:899
msgid "Data transfer aborted.\n"
msgstr "Transfer danych zosta? przerwany.\n"

#: src/ftp.c:963
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Plik `%s' jest ju? tam, wi?c go nie pobieram.\n"

#: src/ftp.c:1024 src/http.c:1358
#, c-format, ycp-format
msgid "(try:%2d)"
msgstr "(próba:%2d)"

#: src/ftp.c:1088 src/http.c:1585
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld]\n"
