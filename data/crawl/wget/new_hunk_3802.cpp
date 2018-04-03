# Polish translation of wget
# Copyright (C) 1998-2000 Free Software Foundation, Inc.
# Arkadiusz Mi¶kiewicz <misiek@pld.ORG.PL>, 1998-2000.
# $Id: pl.po 254 2001-01-04 13:15:48Z hniksic $
msgid ""
msgstr ""
"Project-Id-Version: wget 1.6\n"
"POT-Creation-Date: 2001-01-02 23:18+0100\n"
"PO-Revision-Date: 1999-02-23 14:57+01:00\n"
"Last-Translator: Arkadiusz Mi¶kiewicz <misiek@pld.ORG.PL>\n"
"Language-Team: PL <pl@li.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=ISO8859-2\n"
"Content-Transfer-Encoding: 8bit\n"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:152 src/http.c:352
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "£±czenie siê z %s:%hu... "

#: src/ftp.c:174 src/ftp.c:416 src/http.c:369
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Po³±czenie zosta³o odrzucone przez %s:%hu.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:195 src/http.c:380
msgid "connected!\n"
msgstr "po³±czono siê!\n"

#: src/ftp.c:196
#, c-format
msgid "Logging in as %s ... "
msgstr "Logowanie siê jako %s ... "

#: src/ftp.c:205 src/ftp.c:258 src/ftp.c:306 src/ftp.c:358 src/ftp.c:452
#: src/ftp.c:525 src/ftp.c:573 src/ftp.c:621
msgid "Error in server response, closing control connection.\n"
msgstr "B³±d w odpowiedzi serwera, zamykanie po³±czenia kontrolnego.\n"

#: src/ftp.c:213
msgid "Error in server greeting.\n"
msgstr "B³±d w powitaniu serwera.\n"

#: src/ftp.c:221 src/ftp.c:267 src/ftp.c:315 src/ftp.c:367 src/ftp.c:462
#: src/ftp.c:535 src/ftp.c:583 src/ftp.c:631
msgid "Write failed, closing control connection.\n"
msgstr "Zapis nie powiód³ siê, zamykanie po³±czenienia kontrolnego.\n"

#: src/ftp.c:228
msgid "The server refuses login.\n"
msgstr "Serwer nie pozwala na logowanie siê.\n"

#: src/ftp.c:235
msgid "Login incorrect.\n"
msgstr "Nieprawid³owy login lub has³o.\n"

#: src/ftp.c:242
msgid "Logged in!\n"
msgstr "Zalogowano siê !\n"

#: src/ftp.c:275
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Nieznany typ `%c', zamykanie po³±czenienia kontrolnego.\n"

#: src/ftp.c:288
msgid "done.  "
msgstr "zrobiono.  "

#: src/ftp.c:294
msgid "==> CWD not needed.\n"
msgstr "==> CWD nie jest potrzebne.\n"

#: src/ftp.c:322
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"Nie ma katalogu `%s'.\n"
"\n"

#: src/ftp.c:336 src/ftp.c:604 src/ftp.c:652 src/url.c:1678
msgid "done.\n"
msgstr "zrobiono.\n"

#. do not CWD
#: src/ftp.c:340
msgid "==> CWD not required.\n"
msgstr "==> CWD nie wymagane.\n"

#: src/ftp.c:374
msgid "Cannot initiate PASV transfer.\n"
msgstr "Nie mo¿na zainicjowaæ transferu typu PASV.\n"

#: src/ftp.c:378
msgid "Cannot parse PASV response.\n"
msgstr "Nie mo¿na przeskanowaæ odpowiedzi PASV.\n"

#: src/ftp.c:392
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Nast±pi± próby po³±czenia z %s:%hu.\n"

#: src/ftp.c:437 src/ftp.c:509 src/ftp.c:553
msgid "done.    "
msgstr "zrobiono.    "

#: src/ftp.c:479
#, c-format
msgid "Bind error (%s).\n"
msgstr "B³±d Bind (%s).\n"

#: src/ftp.c:495
msgid "Invalid PORT.\n"
msgstr "Nieprawid³owe PORT.\n"

#: src/ftp.c:542
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"REST nieudane, rozpoczynanie od pocz±tku.\n"

#: src/ftp.c:591
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"Nie ma pliku %s'.\n"
"\n"

#: src/ftp.c:639
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"Nie ma pliku ani katalogu %s'.\n"
"\n"

#: src/ftp.c:715 src/ftp.c:722
#, c-format
msgid "Length: %s"
msgstr "D³ugo¶æ: %s"

#: src/ftp.c:717 src/ftp.c:724
#, c-format
msgid " [%s to go]"
msgstr " [%s do koñca]"

#: src/ftp.c:726
msgid " (unauthoritative)\n"
msgstr " (nie autorytatywne)\n"

#: src/ftp.c:752
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, zamykanie po³±czenienia kontrolnego.\n"

#: src/ftp.c:760
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Po³±czenie danych: %s; "

#: src/ftp.c:777
msgid "Control connection closed.\n"
msgstr "Po³±czenie kontrolne zamkniêto.\n"

#: src/ftp.c:795
msgid "Data transfer aborted.\n"
msgstr "Przerwano transfer danych.\n"

#: src/ftp.c:859
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Plik `%s' ju¿ istnieje, nie pobieram.\n"

#: src/ftp.c:920 src/http.c:1018
#, c-format
msgid "(try:%2d)"
msgstr "(próba:%2d)"

#: src/ftp.c:984 src/http.c:1248
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld]\n"
