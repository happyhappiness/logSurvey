 #
 msgid ""
 msgstr ""
-"Project-Id-Version: GNU Wget 1.6\n"
-"POT-Creation-Date: 2000-11-23 11:23+0100\n"
-"PO-Revision-Date: 2001-02-05 21:53+02:00\n"
+"Project-Id-Version: GNU wget 1.7-pre1\n"
+"POT-Creation-Date: 2001-05-26 11:07+0200\n"
+"PO-Revision-Date: 2001-05-31 14:57+02:00\n"
 "Last-Translator: Toomas Soome <tsoome@ut.ee>\n"
-"Language-Team: Estonian <linux-ee@eenet.ee>\n"
+"Language-Team: Estonian <et@li.org>\n"
 "MIME-Version: 1.0\n"
-"Content-Type: text/plain; charset=ISO-8859-1\n"
+"Content-Type: text/plain; charset=ISO-8859-15\n"
 "Content-Transfer-Encoding: 8-bit\n"
 
+#: src/cookies.c:588
+#, c-format
+msgid "Error in Set-Cookie, field `%s'"
+msgstr "Set-Cookie viga, väli `%s'"
+
+#: src/cookies.c:612
+#, c-format
+msgid "Syntax error in Set-Cookie at character `%c'.\n"
+msgstr "Set-Cookie süntaksi viga sümbolil `%c'.\n"
+
+#: src/cookies.c:620
+msgid "Syntax error in Set-Cookie: premature end of string.\n"
+msgstr "Set-Cookie süntaksi viga: enneaegne sõne lõpp.\n"
+
+#: src/cookies.c:1352
+#, c-format
+msgid "Cannot open cookies file `%s': %s\n"
+msgstr "Ei suuda teisendada linke `%s': %s\n"
+
+#: src/cookies.c:1364
+#, c-format
+msgid "Error writing to `%s': %s\n"
+msgstr "Ei saa kirjutada faili `%s': %s\n"
+
+#: src/cookies.c:1368
+#, c-format
+msgid "Error closing `%s': %s\n"
+msgstr "Viga `%s' sulgemisel: %s\n"
+
+#: src/ftp-ls.c:787
+msgid "Usupported listing type, trying Unix listing parser.\n"
+msgstr "Tundmatu listingu tüüp, proovin Unix listingu parserit.\n"
+
+#: src/ftp-ls.c:832 src/ftp-ls.c:834
+#, c-format
+msgid "Index of /%s on %s:%d"
+msgstr "/%s indeks serveris %s:%d"
+
+#: src/ftp-ls.c:856
+msgid "time unknown       "
+msgstr "tundmatu aeg       "
+
+#: src/ftp-ls.c:860
+msgid "File        "
+msgstr "Fail        "
+
+#: src/ftp-ls.c:863
+msgid "Directory   "
+msgstr "Kataloog    "
+
+#: src/ftp-ls.c:866
+msgid "Link        "
+msgstr "Viide       "
+
+#: src/ftp-ls.c:869
+msgid "Not sure    "
+msgstr "Pole kindel "
+
+#: src/ftp-ls.c:887
+#, c-format
+msgid " (%s bytes)"
+msgstr " (%s baiti)"
+
 #. Login to the server:
 #. First: Establish the control connection.
-#: src/ftp.c:147 src/http.c:348
+#: src/ftp.c:149 src/http.c:623
 #, c-format
 msgid "Connecting to %s:%hu... "
 msgstr "Võtan ühendust serveriga %s:%hu... "
 
-#: src/ftp.c:169 src/ftp.c:411 src/http.c:365
+#: src/ftp.c:171 src/ftp.c:538 src/http.c:640
 #, c-format
 msgid "Connection to %s:%hu refused.\n"
 msgstr "Ei saa ühendust serveriga %s:%hu.\n"
 
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:190 src/http.c:376
+#: src/ftp.c:192 src/http.c:651
 msgid "connected!\n"
 msgstr "ühendus loodud!\n"
 
-#: src/ftp.c:191
+#: src/ftp.c:193
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Meldin serverisse kasutajana %s ... "
 
-#: src/ftp.c:200 src/ftp.c:253 src/ftp.c:301 src/ftp.c:353 src/ftp.c:447
-#: src/ftp.c:520 src/ftp.c:568 src/ftp.c:616
+#: src/ftp.c:202 src/ftp.c:255 src/ftp.c:287 src/ftp.c:335 src/ftp.c:428
+#: src/ftp.c:480 src/ftp.c:574 src/ftp.c:647 src/ftp.c:708 src/ftp.c:756
 msgid "Error in server response, closing control connection.\n"
 msgstr "Vigane serveri vastus, sulgen juhtühenduse.\n"
 
-#: src/ftp.c:208
+#: src/ftp.c:210
 msgid "Error in server greeting.\n"
 msgstr "Vigane serveri tervitus.\n"
 
-#: src/ftp.c:216 src/ftp.c:262 src/ftp.c:310 src/ftp.c:362 src/ftp.c:457
-#: src/ftp.c:530 src/ftp.c:578 src/ftp.c:626
+#: src/ftp.c:218 src/ftp.c:344 src/ftp.c:437 src/ftp.c:489 src/ftp.c:584
+#: src/ftp.c:657 src/ftp.c:718 src/ftp.c:766
 msgid "Write failed, closing control connection.\n"
 msgstr "Kirjutamine ebaõnnestus, sulgen juhtühenduse.\n"
 
-#: src/ftp.c:223
+#: src/ftp.c:225
 msgid "The server refuses login.\n"
 msgstr "Server ei luba meldida.\n"
 
-#: src/ftp.c:230
+#: src/ftp.c:232
 msgid "Login incorrect.\n"
 msgstr "Vigane meldimine.\n"
 
-#: src/ftp.c:237
+#: src/ftp.c:239
 msgid "Logged in!\n"
 msgstr "Melditud!\n"
 
-#: src/ftp.c:270
+#: src/ftp.c:264
+msgid "Server error, can't determine system type.\n"
+msgstr "Viga serveris, ei suuda tuvastada süsteemi tüüpi.\n"
+
+#: src/ftp.c:274 src/ftp.c:559 src/ftp.c:631 src/ftp.c:688
+msgid "done.    "
+msgstr "tehtud.  "
+
+#: src/ftp.c:324 src/ftp.c:458 src/ftp.c:739 src/ftp.c:787 src/url.c:1429
+msgid "done.\n"
+msgstr "tehtud.\n"
+
+#: src/ftp.c:352
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
 msgstr "Tundmatu tüüp `%c', sulgen juhtühenduse.\n"
 
-#: src/ftp.c:283
+#: src/ftp.c:365
 msgid "done.  "
 msgstr "tehtud.  "
 
-#: src/ftp.c:289
+#: src/ftp.c:371
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD pole vajalik.\n"
 
-#: src/ftp.c:317
+#: src/ftp.c:444
 #, c-format
-msgid ""
-"No such directory `%s'.\n"
-"\n"
-msgstr ""
-"Kataloogi `%s' pole.\n"
-"\n"
-
-#: src/ftp.c:331 src/ftp.c:599 src/ftp.c:647 src/url.c:1678
-msgid "done.\n"
-msgstr "tehtud.\n"
+msgid "No such directory `%s'.\n\n"
+msgstr "Kataloogi `%s' pole.\n\n"
 
 #. do not CWD
-#: src/ftp.c:335
+#: src/ftp.c:462
 msgid "==> CWD not required.\n"
 msgstr "==> CWD ei ole kohustuslik.\n"
 
-#: src/ftp.c:369
+#: src/ftp.c:496
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Ei saa algatada PASV ülekannet.\n"
 
-#: src/ftp.c:373
+#: src/ftp.c:500
 msgid "Cannot parse PASV response.\n"
 msgstr "Ei suuda analüüsida PASV vastust.\n"
 
-#: src/ftp.c:387
+#: src/ftp.c:514
 #, c-format
 msgid "Will try connecting to %s:%hu.\n"
 msgstr "Üritan ühenduda serveriga %s:%hu.\n"
 
-#: src/ftp.c:432 src/ftp.c:504 src/ftp.c:548
-msgid "done.    "
-msgstr "tehtud.  "
-
-#: src/ftp.c:474
+#: src/ftp.c:601
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Bind operatsiooni viga (%s).\n"
 
-#: src/ftp.c:490
+#: src/ftp.c:617
 msgid "Invalid PORT.\n"
 msgstr "Vale PORT.\n"
 
-#: src/ftp.c:537
-msgid ""
-"\n"
-"REST failed, starting from scratch.\n"
-msgstr ""
-"\n"
-"REST ebaõnnestus, alustan algusest.\n"
+#: src/ftp.c:670
+#, c-format
+msgid "\nREST failed; will not truncate `%s'.\n"
+msgstr "\nREST ebaõnnestus; ei lühenda faili `%s'.\n"
 
-#: src/ftp.c:586
+#: src/ftp.c:677
+msgid "\nREST failed, starting from scratch.\n"
+msgstr "\nREST ebaõnnestus, alustan algusest.\n"
+
+#: src/ftp.c:726
 #, c-format
-msgid ""
-"No such file `%s'.\n"
-"\n"
-msgstr ""
-"Faili `%s' pole.\n"
-"\n"
+msgid "No such file `%s'.\n\n"
+msgstr "Faili `%s' pole.\n\n"
 
-#: src/ftp.c:634
+#: src/ftp.c:774
 #, c-format
-msgid ""
-"No such file or directory `%s'.\n"
-"\n"
-msgstr ""
-"Faili või kataloogi `%s' pole.\n"
-"\n"
+msgid "No such file or directory `%s'.\n\n"
+msgstr "Faili või kataloogi `%s' pole.\n\n"
 
-#: src/ftp.c:710 src/ftp.c:717
+#: src/ftp.c:858 src/ftp.c:866
 #, c-format
 msgid "Length: %s"
 msgstr "Pikkus: %s"
 
-#: src/ftp.c:712 src/ftp.c:719
+#: src/ftp.c:860 src/ftp.c:868
 #, c-format
 msgid " [%s to go]"
 msgstr " [%s on veel]"
 
-#: src/ftp.c:721
+#: src/ftp.c:870
 msgid " (unauthoritative)\n"
 msgstr " (autoriseerimata)\n"
 
-#: src/ftp.c:747
+#: src/ftp.c:897
 #, c-format
 msgid "%s: %s, closing control connection.\n"
 msgstr "%s: %s, sulgen juhtühenduse.\n"
 
-#: src/ftp.c:755
+#: src/ftp.c:905
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - andme ühendus: %s; "
 
-#: src/ftp.c:772
+#: src/ftp.c:922
 msgid "Control connection closed.\n"
 msgstr "Juhtühendus suletud.\n"
 
-#: src/ftp.c:790
+#: src/ftp.c:940
 msgid "Data transfer aborted.\n"
 msgstr "Andmete ülekanne katkestatud.\n"
 
-#: src/ftp.c:856
+#: src/ftp.c:1004
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
 msgstr "Fail `%s' on juba olemas, ei tõmba.\n"
 
-#: src/ftp.c:933 src/http.c:1032
+#: src/ftp.c:1074 src/http.c:1501
 #, c-format
 msgid "(try:%2d)"
 msgstr "(katse:%2d)"
 
-#: src/ftp.c:997 src/http.c:1252
+#: src/ftp.c:1138 src/http.c:1752
 #, c-format
-msgid ""
-"%s (%s) - `%s' saved [%ld]\n"
-"\n"
-msgstr ""
-"%s (%s) - `%s' salvestatud [%ld]\n"
-"\n"
+msgid "%s (%s) - `%s' saved [%ld]\n\n"
+msgstr "%s (%s) - `%s' salvestatud [%ld]\n\n"
 
-#: src/ftp.c:1039 src/main.c:749 src/recur.c:468 src/retr.c:560
+#: src/ftp.c:1180 src/main.c:809 src/recur.c:483 src/retr.c:566
 #, c-format
 msgid "Removing %s.\n"
 msgstr "Kustutan %s.\n"
 
-#: src/ftp.c:1080
+#: src/ftp.c:1220
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
 msgstr "Kasutan `%s' ajutise listingu failina.\n"
 
-#: src/ftp.c:1092
+#: src/ftp.c:1232
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr "Kustutatud `%s'.\n"
 
-#: src/ftp.c:1128
+#: src/ftp.c:1268
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "Rekursiooni sügavus %d ületab maksimum sügavust %d.\n"
 
-#: src/ftp.c:1180 src/http.c:1179
+#. Remote file is older, file sizes can be compared and
+#. are both equal.
+#: src/ftp.c:1329
 #, c-format
-msgid ""
-"Server file no newer than local file `%s' -- not retrieving.\n"
-"\n"
-msgstr "Fail `%s' serveril ei ole uuem, kui lokaalne -- ei lae.\n\n"
+msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
+msgstr "Kauge fail ei ole uuem, kui lokaalne fail `%s' -- ei lae.\n"
 
-#: src/ftp.c:1186 src/http.c:1187
+#. Remote file is newer or sizes cannot be matched
+#: src/ftp.c:1336
 #, c-format
-msgid "The sizes do not match (local %ld) -- retrieving.\n"
-msgstr "Suurused ei klapi (lokaalne %ld) -- uuendan.\n"
+msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
+msgstr "Kauge fail on uuem kui lokaalne fail `%s' -- laen uuesti.\n\n"
 
-#: src/ftp.c:1203
+#. Sizes do not match
+#: src/ftp.c:1343
+#, c-format
+msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
+msgstr "Suurused ei klapi (lokaalne %ld) -- laen uuesti.\n"
+
+#: src/ftp.c:1360
 msgid "Invalid name of the symlink, skipping.\n"
-msgstr "Vigane sümbol viite nimi, jätan vahele.\n"
+msgstr "Vigane nimeviide, jätan vahele.\n"
 
-#: src/ftp.c:1220
+#: src/ftp.c:1377
 #, c-format
-msgid ""
-"Already have correct symlink %s -> %s\n"
-"\n"
-msgstr ""
-"Korrektne sümbol viide on juba olemas %s -> %s\n"
-"\n"
+msgid "Already have correct symlink %s -> %s\n\n"
+msgstr "Korrektne nimeviide on juba olemas %s -> %s\n\n"
 
-#: src/ftp.c:1228
+#: src/ftp.c:1385
 #, c-format
 msgid "Creating symlink %s -> %s\n"
-msgstr "Loon sümbol viite %s -> %s\n"
+msgstr "Loon nimeviite %s -> %s\n"
 
-#: src/ftp.c:1239
+#: src/ftp.c:1396
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
-msgstr "Ei toeta sümbol viiteid, jätan `%s' vahele.\n"
+msgstr "Ei toeta nimeviiteid, jätan `%s' vahele.\n"
 
-#: src/ftp.c:1251
+#: src/ftp.c:1408
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "Jätan kataloogi `%s' vahele.\n"
 
-#: src/ftp.c:1260
+#: src/ftp.c:1417
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: tundmatu faili tüüp.\n"
 
-#: src/ftp.c:1277
+#: src/ftp.c:1444
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: vigane aeg.\n"
 
-#: src/ftp.c:1298
+#: src/ftp.c:1465
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "Ei tõmba katalooge, kuna sügavus on %d (maks. %d).\n"
 
-#: src/ftp.c:1337
+#: src/ftp.c:1511
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr "Jätame `%s' vahele, ta on välistatud või pole kaasatud.\n"
 
-#: src/ftp.c:1382
+#: src/ftp.c:1558
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "Keelame `%s'.\n"
