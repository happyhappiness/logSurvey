# Italian messages for GNU Wget
# Copyright (C) 1998 Free Software Foundation, Inc.
# Giovanni Bortolozzo <borto@dei.unipd.it>, 1998
#
msgid ""
msgstr ""
"Project-Id-Version: GNU Wget 1.7-dev\n"
"POT-Creation-Date: 2001-02-23 13:23-0800\n"
"PO-Revision-Date: 1998-06-13 15:22+02:00\n"
"Last-Translator: Giovanni Bortolozzo <borto@dei.unipd.it>\n"
"Language-Team: Italian <it@li.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=iso-8859-1\n"
"Content-Transfer-Encoding: 8bit\n"

#: src/ftp-ls.c:779
msgid "Usupported listing type, trying Unix listing parser.\n"
msgstr ""

#: src/ftp-ls.c:824 src/ftp-ls.c:826
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Indice della directory /%s su %s:%d"

#: src/ftp-ls.c:848
msgid "time unknown       "
msgstr "data sconosciuta      "

#: src/ftp-ls.c:852
msgid "File        "
msgstr "File        "

#: src/ftp-ls.c:855
msgid "Directory   "
msgstr "Directory   "

#: src/ftp-ls.c:858
msgid "Link        "
msgstr "Link        "

#: src/ftp-ls.c:861
msgid "Not sure    "
msgstr "Incerto   "

#: src/ftp-ls.c:879
#, c-format
msgid " (%s bytes)"
msgstr " (%s byte)"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:151 src/http.c:618
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Mi sto connettendo a %s:%hu..."

#: src/ftp.c:173 src/ftp.c:517 src/http.c:635
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Connessione a %s:%hu rifiutata.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:194 src/http.c:646
msgid "connected!\n"
msgstr "connesso!\n"

#: src/ftp.c:195
#, c-format
msgid "Logging in as %s ... "
msgstr "Accesso come utente %s ... "

#: src/ftp.c:204 src/ftp.c:257 src/ftp.c:288 src/ftp.c:313 src/ftp.c:407
#: src/ftp.c:459 src/ftp.c:553 src/ftp.c:626 src/ftp.c:674 src/ftp.c:722
msgid "Error in server response, closing control connection.\n"
msgstr ""
"Errore nella risposta del server, chiudo la connessione di controllo.\n"

#: src/ftp.c:212
msgid "Error in server greeting.\n"
msgstr "Errore nel codice di benvenuto del server\n"

#: src/ftp.c:220 src/ftp.c:322 src/ftp.c:416 src/ftp.c:468 src/ftp.c:563
#: src/ftp.c:636 src/ftp.c:684 src/ftp.c:732
msgid "Write failed, closing control connection.\n"
msgstr "Errore in scrittura, chiudo la connessione di controllo\n"

#: src/ftp.c:227
msgid "The server refuses login.\n"
msgstr "Il server rifiuta il login.\n"

#: src/ftp.c:234
msgid "Login incorrect.\n"
msgstr "Login non corretto.\n"

#: src/ftp.c:241
msgid "Logged in!\n"
msgstr "Login eseguito!\n"

#: src/ftp.c:266
msgid "Server error, can't determine system type.\n"
msgstr ""

#: src/ftp.c:276 src/ftp.c:538 src/ftp.c:610 src/ftp.c:654
msgid "done.    "
msgstr "fatto.   "

#: src/ftp.c:302 src/ftp.c:437 src/ftp.c:705 src/ftp.c:753 src/url.c:1432
msgid "done.\n"
msgstr "fatto.\n"

#: src/ftp.c:330
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Tipo `%c' sconosciuto, chiudo la connessione di controllo.\n"

#: src/ftp.c:343
msgid "done.  "
msgstr "fatto.  "

#: src/ftp.c:349
msgid "==> CWD not needed.\n"
msgstr "==> CWD non necessaria.\n"

#: src/ftp.c:423
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"La directory `%s' non esiste.\n"
"\n"

#. do not CWD
#: src/ftp.c:441
msgid "==> CWD not required.\n"
msgstr "==> CWD non necessaria.\n"

#: src/ftp.c:475
msgid "Cannot initiate PASV transfer.\n"
msgstr "Non riesco ad inizializzare il trasferimento PASV.\n"

#: src/ftp.c:479
msgid "Cannot parse PASV response.\n"
msgstr "Non riesco a comprendere la risposta PASV.\n"

#: src/ftp.c:493
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Proverò a connettermi a %s:%hu.\n"

#: src/ftp.c:580
#, c-format
msgid "Bind error (%s).\n"
msgstr "Errore di bind (%s).\n"

#: src/ftp.c:596
msgid "Invalid PORT.\n"
msgstr "PORT non valido.\n"

#: src/ftp.c:643
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"REST fallito, ricomincio dall'inizio.\n"

#: src/ftp.c:692
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"Il file `%s' non esiste.\n"
"\n"

#: src/ftp.c:740
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"Il file o la directory `%s' non esiste.\n"
"\n"

#: src/ftp.c:816 src/ftp.c:823
#, c-format
msgid "Length: %s"
msgstr "Lunghezza: %s"

#: src/ftp.c:818 src/ftp.c:825
#, c-format
msgid " [%s to go]"
msgstr " [%s alla fine]"

#: src/ftp.c:827
msgid " (unauthoritative)\n"
msgstr " (non autorevole)\n"

#: src/ftp.c:853
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, chiudo la connessione di controllo.\n"

#: src/ftp.c:861
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Connessione dati: %s; "

#: src/ftp.c:878
msgid "Control connection closed.\n"
msgstr "Connessione di controllo chiusa.\n"

#: src/ftp.c:896
msgid "Data transfer aborted.\n"
msgstr "Trasferimento dati abortito.\n"

#: src/ftp.c:960
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Il file `%s' è già presente, non lo scarico.\n"

#: src/ftp.c:1021 src/http.c:1394
#, c-format
msgid "(try:%2d)"
msgstr "(provo:%2d)"

#: src/ftp.c:1085 src/http.c:1632
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' salvato [%ld]\n"
"\n"

#: src/ftp.c:1127 src/main.c:789 src/recur.c:509 src/retr.c:602
#, c-format
msgid "Removing %s.\n"
msgstr "Rimuovo %s.\n"

#: src/ftp.c:1168
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Utilizzo `%s' come file temporaneo per il listing.\n"

#: src/ftp.c:1180
#, c-format
msgid "Removed `%s'.\n"
msgstr "`%s' rimosso.\n"

#: src/ftp.c:1216
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "La profondità di %d nella ricorsione eccede il massimo ( %d ).\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1277
#, fuzzy, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "Il file remoto è più recente, lo scarico.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1284
#, fuzzy, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr "Il file remoto è più recente, lo scarico.\n"

#. Sizes do not match
#: src/ftp.c:1291
#, fuzzy, c-format
msgid ""
"The sizes do not match (local %ld) -- retrieving.\n"
"\n"
msgstr "Le dimensioni non coincidono (locale %ld), lo scarico.\n"

#: src/ftp.c:1308
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Il nome del link simbolico non è valido, passo oltre.\n"

#: src/ftp.c:1325
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"Ho già il link simbolico %s -> %s\n"
"\n"

#: src/ftp.c:1333
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Creo il link simbolico %s -> %s\n"

#: src/ftp.c:1344
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Link simbolici non supportati, ignoro il link `%s'.\n"

#: src/ftp.c:1356
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Ignoro la directory `%s'.\n"

#: src/ftp.c:1365
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tipo di file sconosciuto/non supportato.\n"

#: src/ftp.c:1392
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: time-stamp corrotto.\n"

#: src/ftp.c:1413
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Non scarico le directory perché la profondità é %d (max %d).\n"

#: src/ftp.c:1449
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Non scendo nella directory `%s' perché è esclusa/non inclusa.\n"

#: src/ftp.c:1494
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Rifiuto `%s'.\n"

#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1541
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Nessun corrispondenza con il modello `%s'.\n"

#: src/ftp.c:1605
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "Scrivo l'indice in formato HTML in `%s' [%ld].\n"

#: src/ftp.c:1610
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Scrivo l'indice in formato HTML in `%s'.\n"

#: src/getopt.c:454
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: l'opzione `%s' è ambigua\n"

#: src/getopt.c:478
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: l'opzione `--%s' non ammette argomenti\n"

#: src/getopt.c:483
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: l'opzione `%c%s' non ammette argomenti\n"

#: src/getopt.c:498
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: l'opzione `%s' richide un argomento\n"

#. --option
#: src/getopt.c:528
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: opzione non riconosciuta`--%s'\n"

#. +option or -option
#: src/getopt.c:532
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: opzione non riconosciuta `%c%s'\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:563
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: opzione illegale -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:602
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: l'opzione richiede un argomento -- %c\n"

#: src/host.c:394
#, c-format
msgid "%s: Cannot determine user-id.\n"
msgstr "%s: Impossibile determinare lo user-id .\n"

#: src/host.c:406
#, c-format
msgid "%s: Warning: uname failed: %s\n"
msgstr "%s: Attenzione: uname fallita: %s\n"

#: src/host.c:418
#, c-format
msgid "%s: Warning: gethostname failed\n"
msgstr "%s: Attenzione: gethostname fallita\n"

#: src/host.c:446
#, c-format
msgid "%s: Warning: cannot determine local IP address.\n"
msgstr "%s: Attenzione: impossibile determinare l'indirizzo IP locale.\n"

#: src/host.c:460
#, c-format
msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
msgstr ""
"%s: Attenzione: impossibile fare la risoluzione inversa dell'indirizzo\n"
"      IP locale.\n"

#. This gets ticked pretty often.  Karl Berry reports
#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:473
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr ""
"%s: Attenzione: la risoluzione inversa dell'indirizzo locale non ha\n"
"      prodotto un FQDN!\n"

#: src/host.c:501
msgid "Host not found"
msgstr "Host non trovato"

#: src/host.c:503
msgid "Unknown error"
msgstr "Errore sconosciuto"

#. this is fatal
#: src/http.c:549
msgid "Failed to set up an SSL context\n"
msgstr ""

#: src/http.c:555
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr ""

#: src/http.c:559 src/http.c:567
msgid "Trying without the specified certificate\n"
msgstr ""

#: src/http.c:563
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr ""

#: src/http.c:657 src/http.c:1470
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:665
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Proverò a connettermi a %s:%hu.\n"

#: src/http.c:841
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Non riesco a scrivere la richiesta HTTP.\n"

#: src/http.c:846
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s richiesta inviata, aspetto la risposta... "

#: src/http.c:890
msgid "End of file while parsing headers.\n"
msgstr "Raggiunta la fine del file durante l'analisi degli header.\n"

#: src/http.c:901
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Errore di lettura degli header (%s).\n"

#: src/http.c:941
msgid "No data received"
msgstr "Nessun dato ricevuto"

#: src/http.c:943
msgid "Malformed status line"
msgstr "Riga di stato malformata"

#: src/http.c:948
msgid "(no description)"
msgstr "(nessuna descrizione)"

#: src/http.c:1066
msgid "Authorization failed.\n"
msgstr "Autorizzazione fallita.\n"

#: src/http.c:1073
msgid "Unknown authentication scheme.\n"
msgstr "Schema di autotentificazione sconosciuto.\n"

#: src/http.c:1163
#, c-format
msgid "Location: %s%s\n"
msgstr "Location: %s%s\n"

#: src/http.c:1164 src/http.c:1189
msgid "unspecified"
msgstr "non specificato"

#: src/http.c:1165
msgid " [following]"
msgstr " [segue]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1179
msgid "Length: "
msgstr "Lunghezza: "

#: src/http.c:1184
#, c-format
msgid " (%s to go)"
msgstr " (%s per finire)"

#: src/http.c:1189
msgid "ignored"
msgstr "ignorato"

#: src/http.c:1290
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Attenzione: le wildcard non sono supportate in HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1311
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "Il file `%s' è già presente, non lo scarico.\n"

#: src/http.c:1462
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "Non riesco a scrivere in `%s' (%s).\n"

#: src/http.c:1480
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERRORE: Redirezione (%d) senza posizione.\n"

#: src/http.c:1505
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERRORE %d: %s.\n"

#: src/http.c:1518
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Manca l'header last-modified -- date disattivate.\n"

#: src/http.c:1526
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Header last-modified non valido -- data ignorata.\n"

#: src/http.c:1549
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""

#: src/http.c:1557
#, fuzzy, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Le dimensioni non coincidono (locale %ld), lo scarico.\n"

#: src/http.c:1561
msgid "Remote file is newer, retrieving.\n"
msgstr "Il file remoto è più recente, lo scarico.\n"

#: src/http.c:1606
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' salvato [%ld/%ld]\n"
"\n"

#: src/http.c:1654
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Connessione chiusa al byte %ld. "

#: src/http.c:1662
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""
"%s (%s) - `%s' salvati [%ld/%ld])\n"
"\n"

#: src/http.c:1682
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Connessione chiusa al byte  %ld/%ld. "

#: src/http.c:1693
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Errore di lettura al byte %ld (%s). "

#: src/http.c:1701
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Errore di lettura al %ld/%ld (%s). "

#: src/init.c:336 src/netrc.c:261
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: Impossibile leggere %s (%s).\n"

#: src/init.c:354 src/init.c:360
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Errore in %s alla linea %d.\n"

#: src/init.c:391
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""
"%s: Attenzione: Sia il wgetrc di sistema che quello personale puntano\n"
"                  a `%s'.\n"

#: src/init.c:483
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: BUG: comando `%s' sconosciuto, valore `%s'.\n"

#: src/init.c:504
#, fuzzy, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr ""
"%s: Attenzione: impossibile fare la risoluzione inversa dell'indirizzo\n"
"      IP locale.\n"

#: src/init.c:532
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Specificare on oppure off.\n"

#: src/init.c:576
#, fuzzy, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Specificare on oppure off.\n"

#: src/init.c:595 src/init.c:852 src/init.c:874 src/init.c:938
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Specificazione non valida `%s'\n"

#: src/init.c:708 src/init.c:730 src/init.c:752 src/init.c:778
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "wget: %s: Specificazione non valida `%s'\n"

#: src/main.c:120
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Uso: %s [OPZIONE]... [URL]...\n"

#: src/main.c:128
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr ""
"GNU Wget %s, un programma non interattivo per scaricare file dalla rete.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:133
msgid ""
"\n"
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"Gli argomenti obbligatori per le opzioni lunghe lo sono anche per quelle\n"
"corte.\n"

#: src/main.c:136
#, fuzzy
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
