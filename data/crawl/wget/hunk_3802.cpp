-# Polish translation of wget.
-# Copyright (C) 2000 Free Software Foundation, Inc.
-# Grzegorz Kowal <g_kowal@poczta.onet.pl>, 2000.
-#
+# Polish translation of wget
+# Copyright (C) 1998-2000 Free Software Foundation, Inc.
+# Arkadiusz Mi¶kiewicz <misiek@pld.ORG.PL>, 1998-2000.
+# $Id: pl.po 254 2001-01-04 13:15:48Z hniksic $
 msgid ""
 msgstr ""
-"Project-Id-Version: GNU Wget 1.7-dev\n"
-"POT-Creation-Date: 2000-12-10 03:30+0100\n"
-"PO-Revision-Date: 2000-09-15 23:44+0200\n"
-"Last-Translator: Grzegorz Kowal <g_kowal@poczta.onet.pl>\n"
-"Language-Team: Polish <pl@li.org>\n"
+"Project-Id-Version: wget 1.6\n"
+"POT-Creation-Date: 2001-01-02 23:18+0100\n"
+"PO-Revision-Date: 1999-02-23 14:57+01:00\n"
+"Last-Translator: Arkadiusz Mi¶kiewicz <misiek@pld.ORG.PL>\n"
+"Language-Team: PL <pl@li.org>\n"
 "MIME-Version: 1.0\n"
-"Content-Type: text/plain; charset=iso-8859-2\n"
+"Content-Type: text/plain; charset=ISO8859-2\n"
 "Content-Transfer-Encoding: 8bit\n"
 
-#: src/ftp-ls.c:698 src/ftp-ls.c:700
-#, c-format
-msgid "Index of /%s on %s:%d"
-msgstr "Indeks /%s dla %s:%d"
-
-#: src/ftp-ls.c:722
-msgid "time unknown       "
-msgstr "nieznany czas      "
-
-#: src/ftp-ls.c:726
-msgid "File        "
-msgstr "Plik        "
-
-#: src/ftp-ls.c:729
-msgid "Directory   "
-msgstr "Katalog     "
-
-#: src/ftp-ls.c:732
-msgid "Link        "
-msgstr "??cze       "
-
-#: src/ftp-ls.c:735
-msgid "Not sure    "
-msgstr "Niepewne    "
-
-#: src/ftp-ls.c:753
-#, c-format
-msgid " (%s bytes)"
-msgstr " (%s bajtów)"
-
 #. Login to the server:
 #. First: Establish the control connection.
-#: src/ftp.c:152 src/http.c:582
+#: src/ftp.c:152 src/http.c:352
 #, c-format
 msgid "Connecting to %s:%hu... "
-msgstr "??czenie si? z %s:%hu... "
+msgstr "£±czenie siê z %s:%hu... "
 
-#: src/ftp.c:174 src/ftp.c:520 src/http.c:599
+#: src/ftp.c:174 src/ftp.c:416 src/http.c:369
 #, c-format
 msgid "Connection to %s:%hu refused.\n"
-msgstr "Po??czenie z %s:%hu zosta?o odrzucone.\n"
+msgstr "Po³±czenie zosta³o odrzucone przez %s:%hu.\n"
 
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:195 src/http.c:610
+#: src/ftp.c:195 src/http.c:380
 msgid "connected!\n"
-msgstr "po??czony!\n"
+msgstr "po³±czono siê!\n"
 
 #: src/ftp.c:196
 #, c-format
 msgid "Logging in as %s ... "
-msgstr "Logowanie si? jako %s ... "
+msgstr "Logowanie siê jako %s ... "
 
-#: src/ftp.c:205 src/ftp.c:258 src/ftp.c:289 src/ftp.c:314 src/ftp.c:410
-#: src/ftp.c:462 src/ftp.c:556 src/ftp.c:629 src/ftp.c:677 src/ftp.c:725
+#: src/ftp.c:205 src/ftp.c:258 src/ftp.c:306 src/ftp.c:358 src/ftp.c:452
+#: src/ftp.c:525 src/ftp.c:573 src/ftp.c:621
 msgid "Error in server response, closing control connection.\n"
-msgstr "B??d w odpowiedzi serwera, zamykanie po??czenia kontrolnego.\n"
+msgstr "B³±d w odpowiedzi serwera, zamykanie po³±czenia kontrolnego.\n"
 
 #: src/ftp.c:213
 msgid "Error in server greeting.\n"
-msgstr "B??d w powitaniu serwera.\n"
+msgstr "B³±d w powitaniu serwera.\n"
 
-#: src/ftp.c:221 src/ftp.c:323 src/ftp.c:419 src/ftp.c:471 src/ftp.c:566
-#: src/ftp.c:639 src/ftp.c:687 src/ftp.c:735
+#: src/ftp.c:221 src/ftp.c:267 src/ftp.c:315 src/ftp.c:367 src/ftp.c:462
+#: src/ftp.c:535 src/ftp.c:583 src/ftp.c:631
 msgid "Write failed, closing control connection.\n"
-msgstr "B??d zapisu, zamykanie po??czenia kontrolnego.\n"
+msgstr "Zapis nie powiód³ siê, zamykanie po³±czenienia kontrolnego.\n"
 
 #: src/ftp.c:228
 msgid "The server refuses login.\n"
-msgstr "Serwer odrzuci? login.\n"
+msgstr "Serwer nie pozwala na logowanie siê.\n"
 
 #: src/ftp.c:235
 msgid "Login incorrect.\n"
-msgstr "Nieprawid?owy login.\n"
+msgstr "Nieprawid³owy login lub has³o.\n"
 
 #: src/ftp.c:242
 msgid "Logged in!\n"
-msgstr "Zalogowany!\n"
+msgstr "Zalogowano siê !\n"
 
-#: src/ftp.c:267
-msgid "Server error, can't determine system type.\n"
-msgstr ""
-
-#: src/ftp.c:277 src/ftp.c:541 src/ftp.c:613 src/ftp.c:657
-msgid "done.    "
-msgstr "zrobione.  "
-
-#: src/ftp.c:303 src/ftp.c:440 src/ftp.c:708 src/ftp.c:756 src/url.c:1432
-msgid "done.\n"
-msgstr "zrobione.\n"
-
-#: src/ftp.c:331
+#: src/ftp.c:275
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
-msgstr "Nieznany typ `%c', zamykanie po??czenia kontrolnego.\n"
+msgstr "Nieznany typ `%c', zamykanie po³±czenienia kontrolnego.\n"
 
-#: src/ftp.c:344
+#: src/ftp.c:288
 msgid "done.  "
-msgstr "zrobione. "
+msgstr "zrobiono.  "
 
-#: src/ftp.c:350
+#: src/ftp.c:294
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD nie jest potrzebne.\n"
 
-#: src/ftp.c:426
+#: src/ftp.c:322
 #, c-format
 msgid ""
 "No such directory `%s'.\n"
 "\n"
 msgstr ""
-"Nie ma takiego katalogu `%s'.\n"
+"Nie ma katalogu `%s'.\n"
 "\n"
 
+#: src/ftp.c:336 src/ftp.c:604 src/ftp.c:652 src/url.c:1678
+msgid "done.\n"
+msgstr "zrobiono.\n"
+
 #. do not CWD
-#: src/ftp.c:444
+#: src/ftp.c:340
 msgid "==> CWD not required.\n"
-msgstr "==> CWD nie jest wymagany.\n"
+msgstr "==> CWD nie wymagane.\n"
 
-#: src/ftp.c:478
+#: src/ftp.c:374
 msgid "Cannot initiate PASV transfer.\n"
-msgstr "Nie mog? zainicjowa? transferu PASV.\n"
+msgstr "Nie mo¿na zainicjowaæ transferu typu PASV.\n"
 
-#: src/ftp.c:482
+#: src/ftp.c:378
 msgid "Cannot parse PASV response.\n"
-msgstr "Nie mog? przetworzy? odpowiedzi PASV.\n"
+msgstr "Nie mo¿na przeskanowaæ odpowiedzi PASV.\n"
 
-#: src/ftp.c:496
+#: src/ftp.c:392
 #, c-format
 msgid "Will try connecting to %s:%hu.\n"
-msgstr "Spróbuj? po??czy? si? z %s:%hu.\n"
+msgstr "Nast±pi± próby po³±czenia z %s:%hu.\n"
 
-#: src/ftp.c:583
+#: src/ftp.c:437 src/ftp.c:509 src/ftp.c:553
+msgid "done.    "
+msgstr "zrobiono.    "
+
+#: src/ftp.c:479
 #, c-format
 msgid "Bind error (%s).\n"
-msgstr "B??d przywi?zania (%s).\n"
+msgstr "B³±d Bind (%s).\n"
 
-#: src/ftp.c:599
+#: src/ftp.c:495
 msgid "Invalid PORT.\n"
-msgstr "Nieprawid?owy PORT.\n"
+msgstr "Nieprawid³owe PORT.\n"
 
-#: src/ftp.c:646
+#: src/ftp.c:542
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
 msgstr ""
 "\n"
-"Wykonanie REST nie powiod?o si?, zaczynam od pocz?tku.\n"
+"REST nieudane, rozpoczynanie od pocz±tku.\n"
 
-#: src/ftp.c:695
+#: src/ftp.c:591
 #, c-format
 msgid ""
 "No such file `%s'.\n"
 "\n"
 msgstr ""
-"Nie ma takiego pliku `%s'.\n"
+"Nie ma pliku %s'.\n"
 "\n"
 
-#: src/ftp.c:743
+#: src/ftp.c:639
 #, c-format
 msgid ""
 "No such file or directory `%s'.\n"
 "\n"
 msgstr ""
-"Nie ma takiego pliku lub katalogu `%s'.\n"
+"Nie ma pliku ani katalogu %s'.\n"
 "\n"
 
-#: src/ftp.c:819 src/ftp.c:826
+#: src/ftp.c:715 src/ftp.c:722
 #, c-format
 msgid "Length: %s"
-msgstr "D?ugo??: %s"
+msgstr "D³ugo¶æ: %s"
 
-#: src/ftp.c:821 src/ftp.c:828
+#: src/ftp.c:717 src/ftp.c:724
 #, c-format
 msgid " [%s to go]"
-msgstr " [pozosta?o %s]"
+msgstr " [%s do koñca]"
 
-#: src/ftp.c:830
+#: src/ftp.c:726
 msgid " (unauthoritative)\n"
-msgstr " (nieautorytatywny)\n"
+msgstr " (nie autorytatywne)\n"
 
-#: src/ftp.c:856
+#: src/ftp.c:752
 #, c-format
 msgid "%s: %s, closing control connection.\n"
-msgstr "%s: %s, zamykam po??czenie kontrolne.\n"
+msgstr "%s: %s, zamykanie po³±czenienia kontrolnego.\n"
 
-#: src/ftp.c:864
+#: src/ftp.c:760
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
-msgstr "%s (%s) - Po??czenie danych: %s; "
+msgstr "%s (%s) - Po³±czenie danych: %s; "
 
-#: src/ftp.c:881
+#: src/ftp.c:777
 msgid "Control connection closed.\n"
-msgstr "Po??czenie kontrolne zosta?o zamkni?te.\n"
+msgstr "Po³±czenie kontrolne zamkniêto.\n"
 
-#: src/ftp.c:899
+#: src/ftp.c:795
 msgid "Data transfer aborted.\n"
-msgstr "Transfer danych zosta? przerwany.\n"
+msgstr "Przerwano transfer danych.\n"
 
-#: src/ftp.c:963
+#: src/ftp.c:859
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
-msgstr "Plik `%s' jest ju? tam, wi?c go nie pobieram.\n"
+msgstr "Plik `%s' ju¿ istnieje, nie pobieram.\n"
 
-#: src/ftp.c:1024 src/http.c:1358
-#, c-format, ycp-format
+#: src/ftp.c:920 src/http.c:1018
+#, c-format
 msgid "(try:%2d)"
 msgstr "(próba:%2d)"
 
-#: src/ftp.c:1088 src/http.c:1585
+#: src/ftp.c:984 src/http.c:1248
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld]\n"
