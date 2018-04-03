-# Italian messages for GNU Wget
-# Copyright (C) 1998 Free Software Foundation, Inc.
-# Giovanni Bortolozzo <borto@dei.unipd.it>, 1998
+# Italian messages for wget.
+# Copyright (C) 1998, 2004, 2005 Free Software Foundation, Inc.
+# This file is distributed under the same license as the wget package.
+# Marco Colombo <m.colombo@ed.ac.uk>, 2004, 2005.
+# Giovanni Bortolozzo <borto@dei.unipd.it>, 1998.
 #
 msgid ""
 msgstr ""
-"Project-Id-Version: GNU Wget 1.7-dev\n"
-"POT-Creation-Date: 2001-02-23 13:23-0800\n"
-"PO-Revision-Date: 1998-06-13 15:22+02:00\n"
-"Last-Translator: Giovanni Bortolozzo <borto@dei.unipd.it>\n"
-"Language-Team: Italian <it@li.org>\n"
+"Project-Id-Version: wget 1.9.1\n"
+"POT-Creation-Date: 2003-10-11 16:21+0200\n"
+"PO-Revision-Date: 2005-02-11 13:03+0000\n"
+"Last-Translator: Marco Colombo <m.colombo@ed.ac.uk>\n"
+"Language-Team: Italian <tp@lists.linux.it>\n"
 "MIME-Version: 1.0\n"
-"Content-Type: text/plain; charset=iso-8859-1\n"
+"Content-Type: text/plain; charset=UTF-8\n"
 "Content-Transfer-Encoding: 8bit\n"
 
-#: src/ftp-ls.c:779
-msgid "Usupported listing type, trying Unix listing parser.\n"
-msgstr ""
+# FIXME
+#: src/connect.c:88
+#, c-format
+msgid "Unable to convert `%s' to a bind address.  Reverting to ANY.\n"
+msgstr "Impossibile convertire \"%s\" in un indirizzo di bind. Utilizzato ANY.\n"
+
+# Spazio aggiunto per una migliore formattazione:
+#    Connessione a localhost [127.0.0.1]:80...
+#: src/connect.c:165
+#, c-format
+msgid "Connecting to %s[%s]:%hu... "
+msgstr "Connessione a %s [%s]:%hu... "
+
+#: src/connect.c:168
+#, c-format
+msgid "Connecting to %s:%hu... "
+msgstr "Connessione a %s:%hu..."
+
+#: src/connect.c:222
+msgid "connected.\n"
+msgstr "connesso.\n"
+
+#: src/convert.c:171
+#, c-format
+msgid "Converted %d files in %.2f seconds.\n"
+msgstr "Convertiti %d file in %.2f secondi.\n"
 
-#: src/ftp-ls.c:824 src/ftp-ls.c:826
+#: src/convert.c:197
+#, c-format
+msgid "Converting %s... "
+msgstr "Conversione di %s... "
+
+#: src/convert.c:210
+msgid "nothing to do.\n"
+msgstr "niente da fare.\n"
+
+#: src/convert.c:218 src/convert.c:242
+#, c-format
+msgid "Cannot convert links in %s: %s\n"
+msgstr "Impossibile convertire i link in %s: %s\n"
+
+#: src/convert.c:233
+#, c-format
+msgid "Unable to delete `%s': %s\n"
+msgstr "Impossibile rimuovere \"%s\": %s\n"
+
+#: src/convert.c:439
+#, c-format
+msgid "Cannot back up %s as %s: %s\n"
+msgstr "Impossibile fare il backup di %s in %s: %s\n"
+
+#: src/cookies.c:606
+#, c-format
+msgid "Error in Set-Cookie, field `%s'"
+msgstr "Errore in Set-Cookie, campo \"%s\""
+
+#: src/cookies.c:629
+#, c-format
+msgid "Syntax error in Set-Cookie: %s at position %d.\n"
+msgstr "Errore di sintassi in Set-Cookie: %s alla posizione %d.\n"
+
+#: src/cookies.c:1426
+#, c-format
+msgid "Cannot open cookies file `%s': %s\n"
+msgstr "Impossibile aprire il file dei cookies \"%s\": %s\n"
+
+#: src/cookies.c:1438
+#, c-format
+msgid "Error writing to `%s': %s\n"
+msgstr "Errore scrivendo in \"%s\": %s.\n"
+
+#: src/cookies.c:1442
+#, c-format
+msgid "Error closing `%s': %s\n"
+msgstr "Errore chiudendo \"%s\": %s\n"
+
+#: src/ftp-ls.c:812
+msgid "Unsupported listing type, trying Unix listing parser.\n"
+msgstr "Tipo di elencazione (listing) non gestita, provo un parser di liste Unix.\n"
+
+#: src/ftp-ls.c:857 src/ftp-ls.c:859
 #, c-format
 msgid "Index of /%s on %s:%d"
 msgstr "Indice della directory /%s su %s:%d"
 
-#: src/ftp-ls.c:848
+#: src/ftp-ls.c:882
 msgid "time unknown       "
 msgstr "data sconosciuta      "
 
-#: src/ftp-ls.c:852
+#: src/ftp-ls.c:886
 msgid "File        "
 msgstr "File        "
 
-#: src/ftp-ls.c:855
+#: src/ftp-ls.c:889
 msgid "Directory   "
 msgstr "Directory   "
 
-#: src/ftp-ls.c:858
+#: src/ftp-ls.c:892
 msgid "Link        "
 msgstr "Link        "
 
-#: src/ftp-ls.c:861
+#: src/ftp-ls.c:895
 msgid "Not sure    "
-msgstr "Incerto   "
+msgstr "Incerto     "
 
-#: src/ftp-ls.c:879
+#: src/ftp-ls.c:913
 #, c-format
 msgid " (%s bytes)"
 msgstr " (%s byte)"
 
-#. Login to the server:
-#. First: Establish the control connection.
-#: src/ftp.c:151 src/http.c:618
-#, c-format
-msgid "Connecting to %s:%hu... "
-msgstr "Mi sto connettendo a %s:%hu..."
-
-#: src/ftp.c:173 src/ftp.c:517 src/http.c:635
-#, c-format
-msgid "Connection to %s:%hu refused.\n"
-msgstr "Connessione a %s:%hu rifiutata.\n"
-
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:194 src/http.c:646
-msgid "connected!\n"
-msgstr "connesso!\n"
-
-#: src/ftp.c:195
+#: src/ftp.c:202
 #, c-format
 msgid "Logging in as %s ... "
 msgstr "Accesso come utente %s ... "
 
-#: src/ftp.c:204 src/ftp.c:257 src/ftp.c:288 src/ftp.c:313 src/ftp.c:407
-#: src/ftp.c:459 src/ftp.c:553 src/ftp.c:626 src/ftp.c:674 src/ftp.c:722
+#: src/ftp.c:215 src/ftp.c:268 src/ftp.c:299 src/ftp.c:353 src/ftp.c:468
+#: src/ftp.c:519 src/ftp.c:551 src/ftp.c:611 src/ftp.c:675 src/ftp.c:748
+#: src/ftp.c:796
 msgid "Error in server response, closing control connection.\n"
-msgstr ""
-"Errore nella risposta del server, chiudo la connessione di controllo.\n"
+msgstr "Errore nella risposta del server, chiusura della connessione di controllo.\n"
 
-#: src/ftp.c:212
+#: src/ftp.c:223
 msgid "Error in server greeting.\n"
-msgstr "Errore nel codice di benvenuto del server\n"
+msgstr "Errore nel codice di benvenuto del server.\n"
 
-#: src/ftp.c:220 src/ftp.c:322 src/ftp.c:416 src/ftp.c:468 src/ftp.c:563
-#: src/ftp.c:636 src/ftp.c:684 src/ftp.c:732
+#: src/ftp.c:231 src/ftp.c:362 src/ftp.c:477 src/ftp.c:560 src/ftp.c:621
+#: src/ftp.c:685 src/ftp.c:758 src/ftp.c:806
 msgid "Write failed, closing control connection.\n"
-msgstr "Errore in scrittura, chiudo la connessione di controllo\n"
+msgstr "Scrittura non riuscita, chiusura della connessione di controllo.\n"
 
-#: src/ftp.c:227
+#: src/ftp.c:238
 msgid "The server refuses login.\n"
 msgstr "Il server rifiuta il login.\n"
 
-#: src/ftp.c:234
+#: src/ftp.c:245
 msgid "Login incorrect.\n"
 msgstr "Login non corretto.\n"
 
-#: src/ftp.c:241
+#: src/ftp.c:252
 msgid "Logged in!\n"
 msgstr "Login eseguito!\n"
 
-#: src/ftp.c:266
+#: src/ftp.c:277
 msgid "Server error, can't determine system type.\n"
-msgstr ""
+msgstr "Errore del server, impossibile determinare il tipo di sistema.\n"
 
-#: src/ftp.c:276 src/ftp.c:538 src/ftp.c:610 src/ftp.c:654
+#: src/ftp.c:287 src/ftp.c:596 src/ftp.c:659 src/ftp.c:716
 msgid "done.    "
 msgstr "fatto.   "
 
-#: src/ftp.c:302 src/ftp.c:437 src/ftp.c:705 src/ftp.c:753 src/url.c:1432
+#: src/ftp.c:341 src/ftp.c:498 src/ftp.c:533 src/ftp.c:779 src/ftp.c:827
 msgid "done.\n"
 msgstr "fatto.\n"
 
-#: src/ftp.c:330
+#: src/ftp.c:370
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
-msgstr "Tipo `%c' sconosciuto, chiudo la connessione di controllo.\n"
+msgstr "Tipo \"%c\" sconosciuto, chiusura della connessione di controllo.\n"
 
-#: src/ftp.c:343
+#: src/ftp.c:383
 msgid "done.  "
 msgstr "fatto.  "
 
-#: src/ftp.c:349
+#: src/ftp.c:389
 msgid "==> CWD not needed.\n"
 msgstr "==> CWD non necessaria.\n"
 
-#: src/ftp.c:423
+#: src/ftp.c:484
 #, c-format
 msgid ""
 "No such directory `%s'.\n"
 "\n"
 msgstr ""
-"La directory `%s' non esiste.\n"
+"La directory \"%s\" non esiste.\n"
 "\n"
 
 #. do not CWD
-#: src/ftp.c:441
+#: src/ftp.c:502
 msgid "==> CWD not required.\n"
 msgstr "==> CWD non necessaria.\n"
 
-#: src/ftp.c:475
+# GB: initiate = inizializzare
+#: src/ftp.c:567
 msgid "Cannot initiate PASV transfer.\n"
-msgstr "Non riesco ad inizializzare il trasferimento PASV.\n"
+msgstr "Impossibile iniziare il trasferimento PASV.\n"
 
-#: src/ftp.c:479
+# GB: parse = comprendere
+#: src/ftp.c:571
 msgid "Cannot parse PASV response.\n"
-msgstr "Non riesco a comprendere la risposta PASV.\n"
+msgstr "Impossibile analizzare la risposta PASV.\n"
 
-#: src/ftp.c:493
+#: src/ftp.c:588
 #, c-format
-msgid "Will try connecting to %s:%hu.\n"
-msgstr "ProverÚ a connettermi a %s:%hu.\n"
+msgid "couldn't connect to %s:%hu: %s\n"
+msgstr "connessione a %s:%hu non riuscita: %s\n"
 
-#: src/ftp.c:580
+#: src/ftp.c:638
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Errore di bind (%s).\n"
 
-#: src/ftp.c:596
+#: src/ftp.c:645
 msgid "Invalid PORT.\n"
-msgstr "PORT non valido.\n"
+msgstr "Porta non valida.\n"
 
-#: src/ftp.c:643
+# Cos'√® questo REST?
+#: src/ftp.c:698
+#, c-format
+msgid ""
+"\n"
+"REST failed; will not truncate `%s'.\n"
+msgstr ""
+"\n"
+"REST non riuscito; \"%s\" non verr√† troncato.\n"
+
+#: src/ftp.c:705
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
 msgstr ""
 "\n"
-"REST fallito, ricomincio dall'inizio.\n"
+"REST non riuscito, riavvio da capo.\n"
 
-#: src/ftp.c:692
+#: src/ftp.c:766
 #, c-format
 msgid ""
 "No such file `%s'.\n"
 "\n"
 msgstr ""
-"Il file `%s' non esiste.\n"
+"Il file \"%s\" non esiste.\n"
 "\n"
 
-#: src/ftp.c:740
+#: src/ftp.c:814
 #, c-format
 msgid ""
 "No such file or directory `%s'.\n"
 "\n"
 msgstr ""
-"Il file o la directory `%s' non esiste.\n"
+"Il file o la directory \"%s\" non esiste.\n"
 "\n"
 
-#: src/ftp.c:816 src/ftp.c:823
+#: src/ftp.c:898 src/ftp.c:906
 #, c-format
 msgid "Length: %s"
 msgstr "Lunghezza: %s"
 
-#: src/ftp.c:818 src/ftp.c:825
+#: src/ftp.c:900 src/ftp.c:908
 #, c-format
 msgid " [%s to go]"
 msgstr " [%s alla fine]"
 
-#: src/ftp.c:827
+# FIXME
+#: src/ftp.c:910
 msgid " (unauthoritative)\n"
 msgstr " (non autorevole)\n"
 
-#: src/ftp.c:853
+#: src/ftp.c:936
 #, c-format
 msgid "%s: %s, closing control connection.\n"
-msgstr "%s: %s, chiudo la connessione di controllo.\n"
+msgstr "%s: %s, chiusura della connessione di controllo.\n"
 
-#: src/ftp.c:861
+#: src/ftp.c:944
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - Connessione dati: %s; "
 
-#: src/ftp.c:878
+#: src/ftp.c:961
 msgid "Control connection closed.\n"
 msgstr "Connessione di controllo chiusa.\n"
 
-#: src/ftp.c:896
+#: src/ftp.c:979
 msgid "Data transfer aborted.\n"
-msgstr "Trasferimento dati abortito.\n"
+msgstr "Trasferimento dati interrotto.\n"
 
-#: src/ftp.c:960
+#: src/ftp.c:1044
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
-msgstr "Il file `%s' Ë gi‡ presente, non lo scarico.\n"
+msgstr "Il file \"%s\" esiste gi√†, scaricamento non effettuato.\n"
 
-#: src/ftp.c:1021 src/http.c:1394
+#: src/ftp.c:1114 src/http.c:1716
 #, c-format
 msgid "(try:%2d)"
-msgstr "(provo:%2d)"
+msgstr "(tentativo:%2d)"
 
-#: src/ftp.c:1085 src/http.c:1632
+#: src/ftp.c:1180 src/http.c:1975
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld]\n"
 "\n"
 msgstr ""
-"%s (%s) - `%s' salvato [%ld]\n"
+"%s (%s) - \"%s\" salvato [%ld]\n"
 "\n"
 
-#: src/ftp.c:1127 src/main.c:789 src/recur.c:509 src/retr.c:602
+#: src/ftp.c:1222 src/main.c:890 src/recur.c:377 src/retr.c:596
 #, c-format
 msgid "Removing %s.\n"
-msgstr "Rimuovo %s.\n"
+msgstr "Rimozione di %s.\n"
 
-#: src/ftp.c:1168
+#: src/ftp.c:1264
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
-msgstr "Utilizzo `%s' come file temporaneo per il listing.\n"
+msgstr "Usato \"%s\" come file temporaneo per l'elencazione.\n"
 
-#: src/ftp.c:1180
+#: src/ftp.c:1279
 #, c-format
 msgid "Removed `%s'.\n"
-msgstr "`%s' rimosso.\n"
+msgstr "\"%s\" rimosso.\n"
 
-#: src/ftp.c:1216
+#: src/ftp.c:1314
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
-msgstr "La profondit‡ di %d nella ricorsione eccede il massimo ( %d ).\n"
+msgstr "La profondit√† di ricorsione %d eccede il massimo (%d).\n"
 
 #. Remote file is older, file sizes can be compared and
 #. are both equal.
-#: src/ftp.c:1277
-#, fuzzy, c-format
+#: src/ftp.c:1384
+#, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
-msgstr "Il file remoto Ë pi˘ recente, lo scarico.\n"
+msgstr "Il file remoto √® pi√π vecchio del file locale \"%s\" -- scaricamento non effettuato.\n"
 
 #. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1284
-#, fuzzy, c-format
+#: src/ftp.c:1391
+#, c-format
 msgid ""
 "Remote file is newer than local file `%s' -- retrieving.\n"
 "\n"
-msgstr "Il file remoto Ë pi˘ recente, lo scarico.\n"
+msgstr "Il file remoto √® pi√π recente del file locale \"%s\" -- scaricamento in corso.\n"
 
 #. Sizes do not match
-#: src/ftp.c:1291
-#, fuzzy, c-format
+#: src/ftp.c:1398
+#, c-format
 msgid ""
 "The sizes do not match (local %ld) -- retrieving.\n"
 "\n"
-msgstr "Le dimensioni non coincidono (locale %ld), lo scarico.\n"
+msgstr ""
+"Le dimensioni non coincidono (locale %ld) -- scaricamento in corso.\n"
+"\n"
 
-#: src/ftp.c:1308
+#: src/ftp.c:1415
 msgid "Invalid name of the symlink, skipping.\n"
-msgstr "Il nome del link simbolico non Ë valido, passo oltre.\n"
+msgstr "Il nome del link simbolico non √® valido, ignorato.\n"
 
-#: src/ftp.c:1325
+#: src/ftp.c:1432
 #, c-format
 msgid ""
 "Already have correct symlink %s -> %s\n"
 "\n"
 msgstr ""
-"Ho gi‡ il link simbolico %s -> %s\n"
+"Link simbolico gi√† esistente %s -> %s\n"
 "\n"
 
-#: src/ftp.c:1333
+#: src/ftp.c:1440
 #, c-format
 msgid "Creating symlink %s -> %s\n"
-msgstr "Creo il link simbolico %s -> %s\n"
+msgstr "Creazione del link simbolico %s -> %s\n"
 
-#: src/ftp.c:1344
+#: src/ftp.c:1451
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
-msgstr "Link simbolici non supportati, ignoro il link `%s'.\n"
+msgstr "Link simbolici non gestiti, link \"%s\" ignorato.\n"
 
-#: src/ftp.c:1356
+#: src/ftp.c:1463
 #, c-format
 msgid "Skipping directory `%s'.\n"
-msgstr "Ignoro la directory `%s'.\n"
+msgstr "Directory \"%s\" ignorata.\n"
 
-#: src/ftp.c:1365
+#: src/ftp.c:1472
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
-msgstr "%s: tipo di file sconosciuto/non supportato.\n"
+msgstr "%s: tipo di file sconosciuto/non gestito.\n"
 
-#: src/ftp.c:1392
+#: src/ftp.c:1499
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
-msgstr "%s: time-stamp corrotto.\n"
+msgstr "%s: timestamp danneggiato.\n"
 
-#: src/ftp.c:1413
+#: src/ftp.c:1524
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
-msgstr "Non scarico le directory perchÈ la profondit‡ È %d (max %d).\n"
+msgstr "Le directory non verranno scaricate perch√© la loro profondit√† √® %d (max %d).\n"
 
-#: src/ftp.c:1449
+#: src/ftp.c:1574
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
-msgstr "Non scendo nella directory `%s' perchÈ Ë esclusa/non inclusa.\n"
+msgstr "Non scendo nella directory \"%s\" perch√© √® esclusa/non inclusa.\n"
 
-#: src/ftp.c:1494
+#: src/ftp.c:1639 src/ftp.c:1652
 #, c-format
 msgid "Rejecting `%s'.\n"
-msgstr "Rifiuto `%s'.\n"
+msgstr "\"%s\" rifiutato.\n"
 
 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1541
+#: src/ftp.c:1698
 #, c-format
 msgid "No matches on pattern `%s'.\n"
-msgstr "Nessun corrispondenza con il modello `%s'.\n"
+msgstr "Nessun corrispondenza con il modello \"%s\".\n"
 
-#: src/ftp.c:1605
+#: src/ftp.c:1764
 #, c-format
 msgid "Wrote HTML-ized index to `%s' [%ld].\n"
-msgstr "Scrivo l'indice in formato HTML in `%s' [%ld].\n"
+msgstr "Indice in formato HTML scritto in \"%s\" [%ld].\n"
 
-#: src/ftp.c:1610
+#: src/ftp.c:1769
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
-msgstr "Scrivo l'indice in formato HTML in `%s'.\n"
+msgstr "Indice in formato HTML scritto in \"%s\".\n"
 
-#: src/getopt.c:454
+#: src/gen_sslfunc.c:117
+msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
+msgstr "Impossibile inizializzare OpenSSL PRNG; SSL disabilitato.\n"
+
+#: src/getopt.c:675
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
-msgstr "%s: l'opzione `%s' Ë ambigua\n"
+msgstr "%s: l'opzione \"%s\" √® ambigua\n"
 
-#: src/getopt.c:478
+#: src/getopt.c:700
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
-msgstr "%s: l'opzione `--%s' non ammette argomenti\n"
+msgstr "%s: l'opzione \"--%s\" non accetta argomenti\n"
 
-#: src/getopt.c:483
+#: src/getopt.c:705
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
-msgstr "%s: l'opzione `%c%s' non ammette argomenti\n"
+msgstr "%s: l'opzione \"%c%s\" non accetta argomenti\n"
 
-#: src/getopt.c:498
+#: src/getopt.c:723 src/getopt.c:896
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
-msgstr "%s: l'opzione `%s' richide un argomento\n"
+msgstr "%s: l'opzione \"%s\" richiede un argomento\n"
 
 #. --option
-#: src/getopt.c:528
+#: src/getopt.c:752
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
-msgstr "%s: opzione non riconosciuta`--%s'\n"
+msgstr "%s: opzione \"--%s\" non riconosciuta\n"
 
 #. +option or -option
-#: src/getopt.c:532
+#: src/getopt.c:756
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
-msgstr "%s: opzione non riconosciuta `%c%s'\n"
+msgstr "%s: opzione \"%c%s\" non riconosciuta\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:563
+#: src/getopt.c:782
 #, c-format
 msgid "%s: illegal option -- %c\n"
-msgstr "%s: opzione illegale -- %c\n"
+msgstr "%s: opzione illecita -- %c\n"
+
+#: src/getopt.c:785
+#, c-format
+msgid "%s: invalid option -- %c\n"
+msgstr "%s: opzione non valida -- %c\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:602
+#: src/getopt.c:815 src/getopt.c:945
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: l'opzione richiede un argomento -- %c\n"
 
-#: src/host.c:394
-#, c-format
-msgid "%s: Cannot determine user-id.\n"
-msgstr "%s: Impossibile determinare lo user-id .\n"
-
-#: src/host.c:406
+#: src/getopt.c:862
 #, c-format
-msgid "%s: Warning: uname failed: %s\n"
-msgstr "%s: Attenzione: uname fallita: %s\n"
+msgid "%s: option `-W %s' is ambiguous\n"
+msgstr "%s: l'opzione \"-W %s\" √® ambigua\n"
 
-#: src/host.c:418
+#: src/getopt.c:880
 #, c-format
-msgid "%s: Warning: gethostname failed\n"
-msgstr "%s: Attenzione: gethostname fallita\n"
+msgid "%s: option `-W %s' doesn't allow an argument\n"
+msgstr "%s: l'opzione \"-W %s\" non accetta argomenti\n"
 
-#: src/host.c:446
+#: src/host.c:636
 #, c-format
-msgid "%s: Warning: cannot determine local IP address.\n"
-msgstr "%s: Attenzione: impossibile determinare l'indirizzo IP locale.\n"
+msgid "Resolving %s... "
+msgstr "Risoluzione di %s in corso... "
 
-#: src/host.c:460
+#: src/host.c:656 src/host.c:672
 #, c-format
-msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
-msgstr ""
-"%s: Attenzione: impossibile fare la risoluzione inversa dell'indirizzo\n"
-"      IP locale.\n"
+msgid "failed: %s.\n"
+msgstr "fallito: %s.\n"
 
-#. This gets ticked pretty often.  Karl Berry reports
-#. that there can be valid reasons for the local host
-#. name not to be an FQDN, so I've decided to remove the
-#. annoying warning.
-#: src/host.c:473
-#, c-format
-msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
-msgstr ""
-"%s: Attenzione: la risoluzione inversa dell'indirizzo locale non ha\n"
-"      prodotto un FQDN!\n"
+#: src/host.c:674
+msgid "failed: timed out.\n"
+msgstr "fallito: tempo scaduto.\n"
 
-#: src/host.c:501
+#: src/host.c:762
 msgid "Host not found"
 msgstr "Host non trovato"
 
-#: src/host.c:503
+#: src/host.c:764
 msgid "Unknown error"
 msgstr "Errore sconosciuto"
 
+#: src/html-url.c:293
+#, c-format
+msgid "%s: Cannot resolve incomplete link %s.\n"
+msgstr "%s: impossibile risolvere il link incompleto %s.\n"
+
 #. this is fatal
-#: src/http.c:549
+#: src/http.c:674
 msgid "Failed to set up an SSL context\n"
-msgstr ""
+msgstr "Impostazione del contesto SSL non riuscita\n"
 
-#: src/http.c:555
+#: src/http.c:680
 #, c-format
 msgid "Failed to load certificates from %s\n"
-msgstr ""
+msgstr "Caricamento dei certificati da %s non riuscito\n"
 
-#: src/http.c:559 src/http.c:567
+#: src/http.c:684 src/http.c:692
 msgid "Trying without the specified certificate\n"
-msgstr ""
+msgstr "Provo senza il certificato specificato\n"
 
-#: src/http.c:563
+#: src/http.c:688
 #, c-format
 msgid "Failed to get certificate key from %s\n"
-msgstr ""
+msgstr "Ottenimento della chiave di certificato da %s non riuscito\n"
 
-#: src/http.c:657 src/http.c:1470
+#: src/http.c:761 src/http.c:1809
 msgid "Unable to establish SSL connection.\n"
-msgstr ""
+msgstr "Impossibile stabilire una connessione SSL.\n"
 
-#: src/http.c:665
-#, fuzzy, c-format
+#: src/http.c:770
+#, c-format
 msgid "Reusing connection to %s:%hu.\n"
-msgstr "ProverÚ a connettermi a %s:%hu.\n"
+msgstr "Riutilizzo della connessione a %s:%hu.\n"
 
-#: src/http.c:841
-#, fuzzy, c-format
+#: src/http.c:1034
+#, c-format
 msgid "Failed writing HTTP request: %s.\n"
-msgstr "Non riesco a scrivere la richiesta HTTP.\n"
+msgstr "Scrittura della richiesta HTTP non riuscita: %s.\n"
 
-#: src/http.c:846
+#: src/http.c:1039
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s richiesta inviata, aspetto la risposta... "
 
-#: src/http.c:890
+# parsing: analisi? lettura?
+#: src/http.c:1083
 msgid "End of file while parsing headers.\n"
 msgstr "Raggiunta la fine del file durante l'analisi degli header.\n"
 
-#: src/http.c:901
+#: src/http.c:1093
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Errore di lettura degli header (%s).\n"
 
-#: src/http.c:941
+#: src/http.c:1128
 msgid "No data received"
 msgstr "Nessun dato ricevuto"
 
-#: src/http.c:943
+#: src/http.c:1130
 msgid "Malformed status line"
 msgstr "Riga di stato malformata"
 
-#: src/http.c:948
+#: src/http.c:1135
 msgid "(no description)"
 msgstr "(nessuna descrizione)"
 
-#: src/http.c:1066
+#: src/http.c:1267
 msgid "Authorization failed.\n"
 msgstr "Autorizzazione fallita.\n"
 
-#: src/http.c:1073
+#: src/http.c:1274
 msgid "Unknown authentication scheme.\n"
 msgstr "Schema di autotentificazione sconosciuto.\n"
 
-#: src/http.c:1163
+#: src/http.c:1314
 #, c-format
 msgid "Location: %s%s\n"
-msgstr "Location: %s%s\n"
+msgstr "Posizione: %s%s\n"
 
-#: src/http.c:1164 src/http.c:1189
+#: src/http.c:1315 src/http.c:1454
 msgid "unspecified"
 msgstr "non specificato"
 
-#: src/http.c:1165
+#: src/http.c:1316
 msgid " [following]"
 msgstr " [segue]"
 
+#: src/http.c:1383
+msgid ""
+"\n"
+"    The file is already fully retrieved; nothing to do.\n"
+"\n"
+msgstr ""
+"\n"
+"    Il file √® gi√† completamente scaricato; niente da fare.\n"
+"\n"
+
+#: src/http.c:1401
+#, c-format
+msgid ""
+"\n"
+"Continued download failed on this file, which conflicts with `-c'.\n"
+"Refusing to truncate existing file `%s'.\n"
+"\n"
+msgstr ""
+"\n"
+"La ripresa dello scaricamento non √® riuscita su questo file, in conflitto\n"
+"con \"-c\".\n"
+"Troncamento del file esistente \"%s\" rifiutato.\n"
+"\n"
+
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:1179
+#: src/http.c:1444
 msgid "Length: "
 msgstr "Lunghezza: "
 
-#: src/http.c:1184
+#: src/http.c:1449
 #, c-format
 msgid " (%s to go)"
-msgstr " (%s per finire)"
+msgstr " (%s alla fine)"
 
-#: src/http.c:1189
+#: src/http.c:1454
 msgid "ignored"
 msgstr "ignorato"
 
-#: src/http.c:1290
+#: src/http.c:1598
 msgid "Warning: wildcards not supported in HTTP.\n"
-msgstr "Attenzione: le wildcard non sono supportate in HTTP.\n"
+msgstr "Attenzione: i metacaratteri non sono supportati in HTTP.\n"
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:1311
+#: src/http.c:1628
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
-msgstr "Il file `%s' Ë gi‡ presente, non lo scarico.\n"
+msgstr "Il file \"%s\" √® gi√† presente, scaricamento non effettuato.\n"
 
-#: src/http.c:1462
+#: src/http.c:1800
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
-msgstr "Non riesco a scrivere in `%s' (%s).\n"
+msgstr "Impossibile scrivere in \"%s\" (%s).\n"
 
-#: src/http.c:1480
+#: src/http.c:1819
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
-msgstr "ERRORE: Redirezione (%d) senza posizione.\n"
+msgstr "ERRORE: redirezione (%d) senza posizione.\n"
 
-#: src/http.c:1505
+#: src/http.c:1851
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s ERRORE %d: %s.\n"
 
-#: src/http.c:1518
+#: src/http.c:1864
 msgid "Last-modified header missing -- time-stamps turned off.\n"
-msgstr "Manca l'header last-modified -- date disattivate.\n"
+msgstr "Header Last-modified mancante -- date disattivate.\n"
 
-#: src/http.c:1526
+#: src/http.c:1872
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
-msgstr "Header last-modified non valido -- data ignorata.\n"
+msgstr "Header Last-modified non valido -- data ignorata.\n"
 
-#: src/http.c:1549
+# Perch√© "server file" e non "remote file"? C'√® differenza?
+#: src/http.c:1895
 #, c-format
 msgid ""
 "Server file no newer than local file `%s' -- not retrieving.\n"
 "\n"
-msgstr ""
+msgstr "Il file del server √® pi√π vecchio del file locale \"%s\" -- scaricamento non effettuato.\n"
 
-#: src/http.c:1557
-#, fuzzy, c-format
+#: src/http.c:1903
+#, c-format
 msgid "The sizes do not match (local %ld) -- retrieving.\n"
-msgstr "Le dimensioni non coincidono (locale %ld), lo scarico.\n"
+msgstr "Le dimensioni non coincidono (locale %ld) -- scaricamento in corso.\n"
 
-#: src/http.c:1561
+#: src/http.c:1907
 msgid "Remote file is newer, retrieving.\n"
-msgstr "Il file remoto Ë pi˘ recente, lo scarico.\n"
+msgstr "Il file remoto √® pi√π recente, scaricamento in corso.\n"
 
-#: src/http.c:1606
+#: src/http.c:1948
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld/%ld]\n"
 "\n"
 msgstr ""
-"%s (%s) - `%s' salvato [%ld/%ld]\n"
+"%s (%s) - \"%s\" salvato [%ld/%ld]\n"
 "\n"
 
-#: src/http.c:1654
+#: src/http.c:1998
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld. "
 msgstr "%s (%s) - Connessione chiusa al byte %ld. "
 
-#: src/http.c:1662
+# FIXME: o "salvato"?
+#: src/http.c:2007
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld/%ld])\n"
 "\n"
 msgstr ""
-"%s (%s) - `%s' salvati [%ld/%ld])\n"
+"%s (%s) - \"%s\" salvati [%ld/%ld])\n"
 "\n"
 
-#: src/http.c:1682
+#: src/http.c:2028
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld/%ld. "
 msgstr "%s (%s) - Connessione chiusa al byte  %ld/%ld. "
 
-#: src/http.c:1693
+#: src/http.c:2040
 #, c-format
 msgid "%s (%s) - Read error at byte %ld (%s)."
 msgstr "%s (%s) - Errore di lettura al byte %ld (%s). "
 
-#: src/http.c:1701
+#: src/http.c:2049
 #, c-format
 msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
-msgstr "%s (%s) - Errore di lettura al %ld/%ld (%s). "
+msgstr "%s (%s) - Errore di lettura al byte %ld/%ld (%s). "
 
-#: src/init.c:336 src/netrc.c:261
+#: src/init.c:342
+#, c-format
+msgid "%s: WGETRC points to %s, which doesn't exist.\n"
+msgstr "%s: WGETRC punta a %s, che non esiste.\n"
+
+#: src/init.c:398 src/netrc.c:276
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
-msgstr "%s: Impossibile leggere %s (%s).\n"
+msgstr "%s: impossibile leggere %s (%s).\n"
 
-#: src/init.c:354 src/init.c:360
+#: src/init.c:416 src/init.c:422
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
-msgstr "%s: Errore in %s alla linea %d.\n"
+msgstr "%s: errore in %s alla linea %d.\n"
 
-#: src/init.c:391
+#: src/init.c:454
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
-msgstr ""
-"%s: Attenzione: Sia il wgetrc di sistema che quello personale puntano\n"
-"                  a `%s'.\n"
+msgstr "%s: Attenzione: il file wgetrc di sistema e quello personale puntano entrambi a \"%s\".\n"
 
-#: src/init.c:483
+#: src/init.c:594
 #, c-format
-msgid "%s: BUG: unknown command `%s', value `%s'.\n"
-msgstr "%s: BUG: comando `%s' sconosciuto, valore `%s'.\n"
+msgid "%s: Invalid --execute command `%s'\n"
+msgstr "%s: comando \"%s\" passato a --execute non valido\n"
 
-#: src/init.c:504
-#, fuzzy, c-format
-msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
-msgstr ""
-"%s: Attenzione: impossibile fare la risoluzione inversa dell'indirizzo\n"
-"      IP locale.\n"
+# boolean: booleano? logico?
+#: src/init.c:630
+#, c-format
+msgid "%s: %s: Invalid boolean `%s', use `on' or `off'.\n"
+msgstr "%s: %s: valore logico \"%s\" non valido, usare \"on\" oppure \"off\".\n"
+
+#: src/init.c:673
+#, c-format
+msgid "%s: %s: Invalid boolean `%s', use always, on, off, or never.\n"
+msgstr "%s: %s: valore logico \"%s\" non valido, usare \"always\", \"on\", \"off\", o \"never\".\n"
+
+#: src/init.c:691
+#, c-format
+msgid "%s: %s: Invalid number `%s'.\n"
+msgstr "%s: %s: numero \"%s\" non valido.\n"
+
+#: src/init.c:930 src/init.c:949
+#, c-format
+msgid "%s: %s: Invalid byte value `%s'\n"
+msgstr "%s: %s: valore di byte \"%s\" non valido\n"
+
+#: src/init.c:974
+#, c-format
+msgid "%s: %s: Invalid time period `%s'\n"
+msgstr "%s: %s: periodo di tempo \"%s\" non valido\n"
 
-#: src/init.c:532
+#: src/init.c:1051
 #, c-format
-msgid "%s: %s: Please specify on or off.\n"
-msgstr "%s: %s: Specificare on oppure off.\n"
+msgid "%s: %s: Invalid header `%s'.\n"
+msgstr "%s: %s: header \"%s\" non valido.\n"
 
-#: src/init.c:576
-#, fuzzy, c-format
-msgid "%s: %s: Please specify always, on, off, or never.\n"
-msgstr "%s: %s: Specificare on oppure off.\n"
+#: src/init.c:1106
+#, c-format
+msgid "%s: %s: Invalid progress type `%s'.\n"
+msgstr "%s: %s: tipo di progresso \"%s\" non valido.\n"
 
-#: src/init.c:595 src/init.c:852 src/init.c:874 src/init.c:938
+#: src/init.c:1157
 #, c-format
-msgid "%s: %s: Invalid specification `%s'.\n"
-msgstr "%s: %s: Specificazione non valida `%s'\n"
+msgid "%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"
+msgstr "%s: %s: restrizione \"%s\" non valida, usare \"unix\" o \"windows\".\n"
 
-#: src/init.c:708 src/init.c:730 src/init.c:752 src/init.c:778
+#: src/init.c:1198
 #, c-format
-msgid "%s: Invalid specification `%s'\n"
-msgstr "wget: %s: Specificazione non valida `%s'\n"
+msgid "%s: %s: Invalid value `%s'.\n"
+msgstr "%s: %s: valore \"%s\" non valido.\n"
 
-#: src/main.c:120
+#: src/log.c:636
+#, c-format
+msgid ""
+"\n"
+"%s received, redirecting output to `%s'.\n"
+msgstr ""
+"\n"
+"%s ricevuti, output redirezionato su \"%s\".\n"
+
+#. Eek!  Opening the alternate log file has failed.  Nothing we
+#. can do but disable printing completely.
+#: src/log.c:643
+#, c-format
+msgid "%s: %s; disabling logging.\n"
+msgstr "%s: %s; logging disabilitato.\n"
+
+#: src/main.c:127
 #, c-format
 msgid "Usage: %s [OPTION]... [URL]...\n"
 msgstr "Uso: %s [OPZIONE]... [URL]...\n"
 
-#: src/main.c:128
+#: src/main.c:135
 #, c-format
 msgid "GNU Wget %s, a non-interactive network retriever.\n"
-msgstr ""
-"GNU Wget %s, un programma non interattivo per scaricare file dalla rete.\n"
+msgstr "GNU Wget %s, un programma non interattivo per scaricare file dalla rete.\n"
 
 #. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
 #. don't bitch.  Also, it makes translation much easier.
-#: src/main.c:133
+#: src/main.c:140
 msgid ""
 "\n"
 "Mandatory arguments to long options are mandatory for short options too.\n"
 "\n"
 msgstr ""
 "\n"
-"Gli argomenti obbligatori per le opzioni lunghe lo sono anche per quelle\n"
-"corte.\n"
+"Gli argomenti obbligatori per le opzioni lunghe lo sono anche per quelle corte.\n"
+"\n"
 
-#: src/main.c:136
-#, fuzzy
+#: src/main.c:144
 msgid ""
 "Startup:\n"
 "  -V,  --version           display the version of Wget and exit.\n"
