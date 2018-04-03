"Content-Type: text/plain; charset=iso-8859-1\n"
"Content-Transfer-Encoding: 8bit\n"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:147 src/http.c:346
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Mi sto connettendo a %s:%hu..."

#: src/ftp.c:169 src/ftp.c:411 src/http.c:363
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Connessione a %s:%hu rifiutata.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:190 src/http.c:374
msgid "connected!\n"
msgstr "connesso!\n"

#: src/ftp.c:191
#, c-format
msgid "Logging in as %s ... "
msgstr "Accesso come utente %s ... "

#: src/ftp.c:200 src/ftp.c:253 src/ftp.c:301 src/ftp.c:353 src/ftp.c:447
#: src/ftp.c:520 src/ftp.c:568 src/ftp.c:616
msgid "Error in server response, closing control connection.\n"
msgstr "Errore nella risposta del server, chiudo la connessione di controllo.\n"

#: src/ftp.c:208
msgid "Error in server greeting.\n"
msgstr "Errore nel codice di benvenuto del server\n"

#: src/ftp.c:216 src/ftp.c:262 src/ftp.c:310 src/ftp.c:362 src/ftp.c:457
#: src/ftp.c:530 src/ftp.c:578 src/ftp.c:626
msgid "Write failed, closing control connection.\n"
msgstr "Errore in scrittura, chiudo la connessione di controllo\n"

#: src/ftp.c:223
msgid "The server refuses login.\n"
msgstr "Il server rifiuta il login.\n"

#: src/ftp.c:230
msgid "Login incorrect.\n"
msgstr "Login non corretto.\n"

#: src/ftp.c:237
msgid "Logged in!\n"
msgstr "Login eseguito!\n"

#: src/ftp.c:270
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Tipo `%c' sconosciuto, chiudo la connessione di controllo.\n"

#: src/ftp.c:283
msgid "done.  "
msgstr "fatto.  "

#: src/ftp.c:289
msgid "==> CWD not needed.\n"
msgstr "==> CWD non necessaria.\n"

#: src/ftp.c:317
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "La directory `%s' non esiste.\n\n"

#: src/ftp.c:331 src/ftp.c:599 src/ftp.c:647 src/url.c:1431
msgid "done.\n"
msgstr "fatto.\n"

#. do not CWD
#: src/ftp.c:335
msgid "==> CWD not required.\n"
msgstr "==> CWD non necessaria.\n"

#: src/ftp.c:369
msgid "Cannot initiate PASV transfer.\n"
msgstr "Non riesco ad inizializzare il trasferimento PASV.\n"

#: src/ftp.c:373
msgid "Cannot parse PASV response.\n"
msgstr "Non riesco a comprendere la risposta PASV.\n"

#: src/ftp.c:387
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Proverò a connettermi a %s:%hu.\n"

#: src/ftp.c:432 src/ftp.c:504 src/ftp.c:548
msgid "done.    "
msgstr "fatto.   "

#: src/ftp.c:474
#, c-format
msgid "Bind error (%s).\n"
msgstr "Errore di bind (%s).\n"

#: src/ftp.c:490
msgid "Invalid PORT.\n"
msgstr "PORT non valido.\n"

#: src/ftp.c:537
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST fallito, ricomincio dall'inizio.\n"

#: src/ftp.c:586
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Il file `%s' non esiste.\n\n"

#: src/ftp.c:634
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Il file o la directory `%s' non esiste.\n\n"

#: src/ftp.c:692 src/ftp.c:699
#, c-format
msgid "Length: %s"
msgstr "Lunghezza: %s"

#: src/ftp.c:694 src/ftp.c:701
#, c-format
msgid " [%s to go]"
msgstr " [%s alla fine]"

#: src/ftp.c:703
msgid " (unauthoritative)\n"
msgstr " (non autorevole)\n"

#: src/ftp.c:721
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, chiudo la connessione di controllo.\n"

#: src/ftp.c:729
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Connessione dati: %s; "

#: src/ftp.c:746
msgid "Control connection closed.\n"
msgstr "Connessione di controllo chiusa.\n"

#: src/ftp.c:764
msgid "Data transfer aborted.\n"
msgstr "Trasferimento dati abortito.\n"

#: src/ftp.c:830
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Il file `%s' è già presente, non lo scarico.\n"

#: src/ftp.c:896 src/http.c:922
#, c-format
msgid "(try:%2d)"
msgstr "(provo:%2d)"

#: src/ftp.c:955 src/http.c:1116
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' salvato [%ld]\n\n"

#: src/ftp.c:1001
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Utilizzo `%s' come file temporaneo per il listing.\n"

#: src/ftp.c:1013
#, c-format
msgid "Removed `%s'.\n"
msgstr "`%s' rimosso.\n"

#: src/ftp.c:1049
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "La profondità di %d nella ricorsione eccede il massimo ( %d ).\n"

#: src/ftp.c:1096 src/http.c:1054
#, c-format
msgid "Local file `%s' is more recent, not retrieving.\n\n"
msgstr "Il file locale `%s' è più recente, non lo scarico.\n\n"

#: src/ftp.c:1102 src/http.c:1060
#, c-format
msgid "The sizes do not match (local %ld), retrieving.\n"
msgstr "Le dimensioni non coincidono (locale %ld), lo scarico.\n"

#: src/ftp.c:1119
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Il nome del link simbolico non è valido, passo oltre.\n"

#: src/ftp.c:1136
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Ho già il link simbolico %s -> %s\n\n"

#: src/ftp.c:1144
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Creo il link simbolico %s -> %s\n"

#: src/ftp.c:1155
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Link simbolici non supportati, ignoro il link `%s'.\n"

#: src/ftp.c:1167
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Ignoro la directory `%s'.\n"

#: src/ftp.c:1176
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tipo di file sconosciuto/non supportato.\n"

#: src/ftp.c:1193
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: time-stamp corrotto.\n"

#: src/ftp.c:1213
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Non scarico le directory perché la profondità é %d (max %d).\n"

#: src/ftp.c:1252
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Non scendo nella directory `%s' perché è esclusa/non inclusa.\n"

#: src/ftp.c:1297
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Rifiuto `%s'.\n"
