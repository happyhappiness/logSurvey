"Content-Type: text/plain; charset=ISO-8859-1\n"
"Content-Transfer-Encoding: 8bit\n"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:147 src/http.c:346
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Ansluter till %s:%hu... "

#: src/ftp.c:169 src/ftp.c:411 src/http.c:363
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Anslutning till %s:%hu v�gras.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:190 src/http.c:374
msgid "connected!\n"
msgstr "ansluten!\n"

#: src/ftp.c:191
#, c-format
msgid "Logging in as %s ... "
msgstr "Loggar in som %s ... "

#: src/ftp.c:200 src/ftp.c:253 src/ftp.c:301 src/ftp.c:353 src/ftp.c:447
#: src/ftp.c:520 src/ftp.c:568 src/ftp.c:616
msgid "Error in server response, closing control connection.\n"
msgstr "Fel i serversvar, st�nger styrf�rbindelse.\n"

#: src/ftp.c:208
msgid "Error in server greeting.\n"
msgstr "Fel i serverh�lsning.\n"

#: src/ftp.c:216 src/ftp.c:262 src/ftp.c:310 src/ftp.c:362 src/ftp.c:457
#: src/ftp.c:530 src/ftp.c:578 src/ftp.c:626
msgid "Write failed, closing control connection.\n"
msgstr "Skrivning misslyckades, st�nger styrf�rbindelse.\n"

#: src/ftp.c:223
msgid "The server refuses login.\n"
msgstr "Inloggning nekas av servern.\n"

#: src/ftp.c:230
msgid "Login incorrect.\n"
msgstr "Felaktig inloggning.\n"

#: src/ftp.c:237
msgid "Logged in!\n"
msgstr "Inloggad!\n"

#: src/ftp.c:270
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Ok�nd typ \"%c\", st�nger styrf�rbindelse.\n"

#: src/ftp.c:283
msgid "done.  "
msgstr "f�rdig.  "

#: src/ftp.c:289
msgid "==> CWD not needed.\n"
msgstr "==> CWD beh�vs inte.\n"

#: src/ftp.c:317
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Katalogen \"%s\" finns inte.\n\n"

#: src/ftp.c:331 src/ftp.c:599 src/ftp.c:647 src/url.c:1431
msgid "done.\n"
msgstr "f�rdig.\n"

#. do not CWD
#: src/ftp.c:335
msgid "==> CWD not required.\n"
msgstr "==> CWD kr�vs inte.\n"

#: src/ftp.c:369
msgid "Cannot initiate PASV transfer.\n"
msgstr "Kan inte initiera PASV-�verf�ring.\n"

#: src/ftp.c:373
msgid "Cannot parse PASV response.\n"
msgstr "Kan inte tolka PASV-svar.\n"

#: src/ftp.c:387
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "F�rs�ker ansluta till %s:%hu.\n"

#: src/ftp.c:432 src/ftp.c:504 src/ftp.c:548
msgid "done.    "
msgstr "f�rdig.  "

#: src/ftp.c:474
#, c-format
msgid "Bind error (%s).\n"
msgstr "Bindningsfel (%s).\n"

#: src/ftp.c:490
msgid "Invalid PORT.\n"
msgstr "Felaktig PORT.\n"

#: src/ftp.c:537
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST misslyckades, startar om fr�n b�rjan.\n"

#: src/ftp.c:586
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Filen \"%s\" finns inte.\n\n"

#: src/ftp.c:634
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Filen eller katalogen \"%s\" finns inte.\n\n"

#: src/ftp.c:692 src/ftp.c:699
#, c-format
msgid "Length: %s"
msgstr "L�ngd: %s"

#: src/ftp.c:694 src/ftp.c:701
#, c-format
msgid " [%s to go]"
msgstr " [%s kvar]"

#: src/ftp.c:703
msgid " (unauthoritative)\n"
msgstr " (ej auktoritativt)\n"

#: src/ftp.c:721
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, st�nger styrf�rbindelse.\n"

#: src/ftp.c:729
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Dataf�rbindelse: %s; "

#: src/ftp.c:746
msgid "Control connection closed.\n"
msgstr "Styrf�rbindelse st�ngd.\n"

#: src/ftp.c:764
msgid "Data transfer aborted.\n"
msgstr "Data�verf�ring avbruten.\n"

#: src/ftp.c:830
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "Filen \"%s\" finns redan, h�mtar inte.\n"

#: src/ftp.c:896 src/http.c:922
#, c-format
msgid "(try:%2d)"
msgstr "(f�rs�k:%2d)"

#: src/ftp.c:955 src/http.c:1116
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - \"%s\" sparad [%ld]\n\n"

#: src/ftp.c:1001
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Anv�nder \"%s\" som tempor�r listningsfil.\n"

#: src/ftp.c:1013
#, c-format
msgid "Removed `%s'.\n"
msgstr "Raderade \"%s\".\n"

#: src/ftp.c:1049
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "Rekursionsdjupet %d �verskred det maximala djupet %d.\n"

#: src/ftp.c:1096 src/http.c:1054
#, c-format
msgid "Local file `%s' is more recent, not retrieving.\n\n"
msgstr "Lokala filen \"%s\" �r nyare, h�mtar inte.\n\n"

#: src/ftp.c:1102 src/http.c:1060
#, c-format
msgid "The sizes do not match (local %ld), retrieving.\n"
msgstr "Storlekarna st�mmer inte �verens (lokal %ld), h�mtar.\n"

#: src/ftp.c:1119
msgid "Invalid name of the symlink, skipping.\n"
msgstr "Ogiltig symbolisk l�nk, hoppar �ver.\n"

#: src/ftp.c:1136
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "En korrekt symbolisk l�nk %s -> %s existerar redan.\n\n"

#: src/ftp.c:1144
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Skapar symbolisk l�nk %s -> %s\n"

#: src/ftp.c:1155
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Symboliska l�nkar st�ds inte, hoppar �ver symbolisk l�nk \"%s\".\n"

#: src/ftp.c:1167
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Hoppar �ver katalogen \"%s\".\n"

#: src/ftp.c:1176
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: ok�nd/ej underst�dd filtyp.\n"

#: src/ftp.c:1193
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: felaktig tidsst�mpel.\n"

#: src/ftp.c:1213
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "H�mtar inte kataloger eftersom djupet �r %d (max %d).\n"

#: src/ftp.c:1252
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "G�r inte ner till \"%s\" eftersom det �r undantaget/inte ing�r.\n"

#: src/ftp.c:1297
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "F�rkastar \"%s\".\n"
