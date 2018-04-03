 # Slovak translations for GNU wget
-# Copyright (C) 1998 Free Software Foundation, Inc.
-# Miroslav Vasko <vasko@debian.cz>, 1999
+# Copyright (C) 1999, 2002 Free Software Foundation, Inc.
+# Marcel Telka <marcel@telka.sk>, 2002.
+# Miroslav Vasko <vasko@debian.cz>, 1999.
 #
 msgid ""
 msgstr ""
-"Project-Id-Version: GNU wget 1.7\n"
-"POT-Creation-Date: 2001-06-03 15:27+0200\n"
-"PO-Revision-Date: 2001-06-08 20:45 +02:00\n"
-"Last-Translator: Stanislav Meduna <stano@eunet.sk>\n"
-"Language-Team: Slovak <sk-i18n@rak.isternet.sk>\n"
+"Project-Id-Version: GNU wget 1.8.1\n"
+"POT-Creation-Date: 2001-12-17 16:30+0100\n"
+"PO-Revision-Date: 2002-01-16 19:57+0100\n"
+"Last-Translator: Marcel Telka <marcel@telka.sk>\n"
+"Language-Team: Slovak <sk-i18n@lists.linux.sk>\n"
 "MIME-Version: 1.0\n"
 "Content-Type: text/plain; charset=iso-8859-2\n"
 "Content-Transfer-Encoding: 8-bit\n"
 
-#: src/cookies.c:588
+# , c-format
+#: src/connect.c:94
+#, c-format
+msgid "Connecting to %s[%s]:%hu... "
+msgstr "Prip�jam sa k %s[%s]:%hu... "
+
+# , c-format
+#: src/connect.c:97
+#, c-format
+msgid "Connecting to %s:%hu... "
+msgstr "Prip�jam sa k %s:%hu... "
+
+#: src/connect.c:131
+msgid "connected.\n"
+msgstr "pripojen�.\n"
+
+#: src/cookies.c:595
 #, c-format
 msgid "Error in Set-Cookie, field `%s'"
 msgstr "Chyba v Set-Cookie, pole `%s'"
 
-#: src/cookies.c:612
+#: src/cookies.c:619
 #, c-format
 msgid "Syntax error in Set-Cookie at character `%c'.\n"
 msgstr "Chyba syntaxe v Set-Cookie na znaku `%c'.\n"
 
-#: src/cookies.c:620
+#: src/cookies.c:627
 msgid "Syntax error in Set-Cookie: premature end of string.\n"
 msgstr "Chyba syntaxe v Set-Cookie: pred�asn� koniec re�azca.\n"
 
 # , c-format
-#: src/cookies.c:1352
+#: src/cookies.c:1329
 #, c-format
 msgid "Cannot open cookies file `%s': %s\n"
 msgstr "Nedok�em otvori� s�bor s cookie `%s': %s\n"
 
 # , c-format
-#: src/cookies.c:1364
+#: src/cookies.c:1341
 #, c-format
 msgid "Error writing to `%s': %s\n"
-msgstr "Nemo�no zap�sa� do `%s': %s\n"
+msgstr "Chyba pri z�pise do `%s': %s\n"
 
-#: src/cookies.c:1368
+#: src/cookies.c:1345
 #, c-format
 msgid "Error closing `%s': %s\n"
 msgstr "Chyba pri zatv�ran� `%s': %s\n"
 
-#: src/ftp-ls.c:787
+#: src/ftp-ls.c:802
 msgid "Unsupported listing type, trying Unix listing parser.\n"
 msgstr "Nepodporovan� typ v�pisu, sk��a sa unixov� parser.\n"
 
 # , c-format
-#: src/ftp-ls.c:832 src/ftp-ls.c:834
+#: src/ftp-ls.c:847 src/ftp-ls.c:849
 #, c-format
 msgid "Index of /%s on %s:%d"
 msgstr "Obsah /%s na %s:%d"
 
-#: src/ftp-ls.c:856
+#: src/ftp-ls.c:871
 msgid "time unknown       "
 msgstr "�as nezn�my        "
 
-#: src/ftp-ls.c:860
+#: src/ftp-ls.c:875
 msgid "File        "
 msgstr "S�bor       "
 
-#: src/ftp-ls.c:863
+#: src/ftp-ls.c:878
 msgid "Directory   "
 msgstr "Adres�r     "
 
-#: src/ftp-ls.c:866
+#: src/ftp-ls.c:881
 msgid "Link        "
 msgstr "Sym. odkaz  "
 
-#: src/ftp-ls.c:869
+#: src/ftp-ls.c:884
 msgid "Not sure    "
 msgstr "Nezn�my typ "
 
 # , c-format
-#: src/ftp-ls.c:887
+#: src/ftp-ls.c:902
 #, c-format
 msgid " (%s bytes)"
-msgstr " (%s bytov)"
-
-# , c-format
-#. Login to the server:
-#. First: Establish the control connection.
-#: src/ftp.c:150 src/http.c:624
-#, c-format
-msgid "Connecting to %s:%hu... "
-msgstr "Nav�zujem spojenie s %s:%hu... "
+msgstr " (%s bajtov)"
 
 # , c-format
-#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
-#, c-format
-msgid "Connection to %s:%hu refused.\n"
-msgstr "Spojenie s %s:%hu odmietnut�.\n"
-
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:193 src/http.c:652
-msgid "connected!\n"
-msgstr "spojen�!\n"
-
-# , c-format
-#: src/ftp.c:194
+#: src/ftp.c:179
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Prihlasujem sa ako %s ... "
 
-#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
-#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
+#: src/ftp.c:188 src/ftp.c:241 src/ftp.c:272 src/ftp.c:326 src/ftp.c:419
+#: src/ftp.c:470 src/ftp.c:500 src/ftp.c:564 src/ftp.c:628 src/ftp.c:689
+#: src/ftp.c:737
 msgid "Error in server response, closing control connection.\n"
 msgstr "Server odpovedal chybne, uzatv�ram riadiace spojenie.\n"
 
-#: src/ftp.c:211
+#: src/ftp.c:196
 msgid "Error in server greeting.\n"
-msgstr "�vodn� odpove� serveru je chybn�.\n"
+msgstr "�vodn� odpove� servera je chybn�.\n"
 
-#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
-#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
+#: src/ftp.c:204 src/ftp.c:335 src/ftp.c:428 src/ftp.c:509 src/ftp.c:574
+#: src/ftp.c:638 src/ftp.c:699 src/ftp.c:747
 msgid "Write failed, closing control connection.\n"
 msgstr "Nem��em zap�sa� d�ta, uzatv�ram riadiace spojenie.\n"
 
-#: src/ftp.c:226
+#: src/ftp.c:211
 msgid "The server refuses login.\n"
 msgstr "Server odmieta prihl�senie.\n"
 
-#: src/ftp.c:233
+#: src/ftp.c:218
 msgid "Login incorrect.\n"
 msgstr "Chyba pri prihl�sen�.\n"
 
-#: src/ftp.c:240
+#: src/ftp.c:225
 msgid "Logged in!\n"
 msgstr "Prihl�sen�!\n"
 
-#: src/ftp.c:265
+#: src/ftp.c:250
 msgid "Server error, can't determine system type.\n"
 msgstr "Chyba servera, nie je mo�n� zisti� typ syst�mu.\n"
 
-#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
+#: src/ftp.c:260 src/ftp.c:549 src/ftp.c:612 src/ftp.c:669
 msgid "done.    "
 msgstr "hotovo.  "
 
-#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
+#: src/ftp.c:314 src/ftp.c:449 src/ftp.c:484 src/ftp.c:720 src/ftp.c:768
+#: src/host.c:283
 msgid "done.\n"
 msgstr "hotovo.\n"
 
 # , c-format
-#: src/ftp.c:353
+#: src/ftp.c:343
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "Nezn�my typ `%c', uzatv�ram riadiace spojenie.\n"
 
-#: src/ftp.c:366
+#: src/ftp.c:356
 msgid "done.  "
 msgstr "hotovo."
 
-#: src/ftp.c:372
+#: src/ftp.c:362
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD nie je potrebn�.\n"
 
 # , c-format
-#: src/ftp.c:445
+#: src/ftp.c:435
 #, c-format
 msgid "No such directory `%s'.\n\n"
 msgstr "Adres�r `%s' neexistuje.\n\n"
 
 #. do not CWD
-#: src/ftp.c:463
+#: src/ftp.c:453
 msgid "==> CWD not required.\n"
 msgstr "==> CWD nie je potrebn�.\n"
 
-#: src/ftp.c:497
+#: src/ftp.c:516
 msgid "Cannot initiate PASV transfer.\n"
-msgstr "Nemo�no inicializova� prenos pr�kazom PASV.\n"
+msgstr "Nemo�no iniciova� prenos pr�kazom PASV.\n"
 
-#: src/ftp.c:501
+#: src/ftp.c:520
 msgid "Cannot parse PASV response.\n"
-msgstr "Odpovr� na PASV je nepochopite�n�.\n"
+msgstr "Nem��em analyzova� odpove� na PASV.\n"
 
 # , c-format
-#: src/ftp.c:515
+#: src/ftp.c:541
 #, c-format
-msgid "Will try connecting to %s:%hu.\n"
-msgstr "Pok�sim sa spoji� s %s:%hu.\n"
+msgid "couldn't connect to %s:%hu: %s\n"
+msgstr "nem��em sa pripoji� k %s:%hu: %s.\n"
 
 # , c-format
-#: src/ftp.c:602
+#: src/ftp.c:591
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Chyba pri oper�cii \"bind\" (%s).\n"
 
-#: src/ftp.c:618
+#: src/ftp.c:598
 msgid "Invalid PORT.\n"
 msgstr "Neplatn� PORT.\n"
 
-#: src/ftp.c:671
+#: src/ftp.c:651
 #, c-format
 msgid "\nREST failed; will not truncate `%s'.\n"
 msgstr "\nREST zlyhal; `%s' sa neskr�ti.\n"
 
-#: src/ftp.c:678
+#: src/ftp.c:658
 msgid "\nREST failed, starting from scratch.\n"
-msgstr "\nPr�kaz REST zlyhal, pren�am s�bor od za�iatku.\n"
+msgstr "\nREST zlyhal, za��nam odznova.\n"
 
 # , c-format
-#: src/ftp.c:727
+#: src/ftp.c:707
 #, c-format
 msgid "No such file `%s'.\n\n"
 msgstr "S�bor `%s' neexistuje.\n\n"
 
 # , c-format
-#: src/ftp.c:775
+#: src/ftp.c:755
 #, c-format
 msgid "No such file or directory `%s'.\n\n"
 msgstr "S�bor alebo adres�r `%s' neexistuje.\n\n"
 
 # , c-format
-#: src/ftp.c:859 src/ftp.c:867
+#: src/ftp.c:839 src/ftp.c:847
 #, c-format
 msgid "Length: %s"
 msgstr "D�ka: %s"
 
 # , c-format
-#: src/ftp.c:861 src/ftp.c:869
+#: src/ftp.c:841 src/ftp.c:849
 #, c-format
 msgid " [%s to go]"
 msgstr " [ost�va %s]"
 
-#: src/ftp.c:871
+#: src/ftp.c:851
 msgid " (unauthoritative)\n"
 msgstr " (nie je smerodajn�)\n"
 
 # , c-format
-#: src/ftp.c:898
+#: src/ftp.c:877
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, uzatv�ram riadiace spojenie.\n"
 
 # , c-format
-#: src/ftp.c:906
+#: src/ftp.c:885
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - D�tov� spojenie: %s; "
 
-#: src/ftp.c:923
+#: src/ftp.c:902
 msgid "Control connection closed.\n"
 msgstr "Riadiace spojenie uzatvoren�.\n"
 
-#: src/ftp.c:941
+#: src/ftp.c:920
 msgid "Data transfer aborted.\n"
 msgstr "Prenos d�t bol pred�asne ukon�en�.\n"
 
 # , c-format
-#: src/ftp.c:1005
+#: src/ftp.c:984
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr "S�bor `%s' je u� tu, nebudem ho pren�a�.\n"
 
 # , c-format
-#: src/ftp.c:1075 src/http.c:1502
+#: src/ftp.c:1054 src/http.c:1527
 #, c-format
 msgid "(try:%2d)"
 msgstr "(pokus:%2d)"
 
 # , c-format
-#: src/ftp.c:1139 src/http.c:1753
+#: src/ftp.c:1118 src/http.c:1786
 #, c-format
 msgid "%s (%s) - `%s' saved [%ld]\n\n"
 msgstr "%s (%s) - `%s' ulo�en� [%ld]\n\n"
 
 # , c-format
-#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
+#: src/ftp.c:1160 src/main.c:819 src/recur.c:349 src/retr.c:587
 #, c-format
 msgid "Removing %s.\n"
-msgstr "Ma�e sa %s.\n"
+msgstr "Odstra�ujem %s.\n"
 
 # , c-format
-#: src/ftp.c:1221
+#: src/ftp.c:1202
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr "Zoznam s�borov bude do�asne ulo�en� v `%s'.\n"
 
 # , c-format
-#: src/ftp.c:1233
+#: src/ftp.c:1217
 #, c-format
 msgid "Removed `%s'.\n"
-msgstr "Vymazan� `%s'.\n"
+msgstr "Odstr�nen� `%s'.\n"
 
 # , c-format
-#: src/ftp.c:1269
+#: src/ftp.c:1252
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "H�bka rekurzie %d prekro�ila maxim�lnu povolen� h�bku %d.\n"
 
 #. Remote file is older, file sizes can be compared and
 #. are both equal.
-#: src/ftp.c:1330
+#: src/ftp.c:1317
 #, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
-msgstr "Vzdialen� s�bor nie je nov�� ako lok�lny s�bor `%s' -- nepren�am.\n"
+msgstr "Vzdialen� s�bor nie je nov�� ako miestny s�bor `%s' -- nepren�am.\n"
 
 #. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1337
+#: src/ftp.c:1324
 #, c-format
 msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
-msgstr "Vzdialen� s�bor je nov�� ako lok�lny s�bor `%s' -- pren�am.\n\n"
+msgstr "Vzdialen� s�bor je nov�� ako miestny s�bor `%s' -- pren�am.\n\n"
 
 # , c-format
 #. Sizes do not match
-#: src/ftp.c:1344
+#: src/ftp.c:1331
 #, c-format
 msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
-msgstr "Ve�kosti se nezhoduj� (lok�lne %ld) -- pren�am.\n\n"
+msgstr "Ve�kosti se nezhoduj� (miestny %ld) -- pren�am.\n\n"
 
-#: src/ftp.c:1361
+#: src/ftp.c:1348
 msgid "Invalid name of the symlink, skipping.\n"
 msgstr "Neplatn� n�zov symoblick�ho odkazu, preskakujem.\n"
 
 # , c-format
-#: src/ftp.c:1378
+#: src/ftp.c:1365
 #, c-format
 msgid "Already have correct symlink %s -> %s\n\n"
 msgstr "Korektn� symbolick� odkaz %s -> %s u� existuje.\n\n"
 
 # , c-format
-#: src/ftp.c:1386
+#: src/ftp.c:1373
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Vytv�ram symbolick� odkaz %s -> %s\n"
 
 # , c-format
-#: src/ftp.c:1397
+#: src/ftp.c:1384
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
-msgstr ""
-"Preskakujem symbolick� odkaz `%s', preto�e tento syst�m symbolick� odkazy\n"
-"nepodporuje.\n"
+msgstr "Symbolick� odkazy nie s� podporovan�, preskakujem symbolick� odkaz `%s'.\n"
 
 # , c-format
-#: src/ftp.c:1409
+#: src/ftp.c:1396
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "Preskakujem adres�r `%s'.\n"
 
 # , c-format
-#: src/ftp.c:1418
+#: src/ftp.c:1405
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: nezn�my/nepodporovan� typ s�boru.\n"
 
 # , c-format
-#: src/ftp.c:1445
+#: src/ftp.c:1432
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
-msgstr "%s: �asov� raz�tko s�boru je poru�en�.\n"
+msgstr "%s: �asov� zna�ka s�boru je poru�en�.\n"
 
 # , c-format
-#: src/ftp.c:1466
+#: src/ftp.c:1457
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
-msgstr "Podadres�re nebudem pren�a�, preto�e sme u� v h�bke %d (maximum je %d).\n"
+msgstr "Nebudem pren�a� adres�re, preto�e sme u� v h�bke %d (maximum je %d).\n"
 
 # , c-format
-#: src/ftp.c:1512
+#: src/ftp.c:1507
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr ""
