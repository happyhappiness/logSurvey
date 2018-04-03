# Translation of wget messages to Catalan.
# Copyright (C) 2001, 2002 Free Software Foundation, Inc.
# Jordi Valverde Sivilla <jordi@eclipsi.net>, 2001, 2002.
#
msgid ""
msgstr ""
"Project-Id-Version: wget 1.8\n"
"POT-Creation-Date: 2001-12-08 23:28+0100\n"
"PO-Revision-Date: 2002-01-13 21:29+0100\n"
"Last-Translator: Jordi Valverde Sivilla <jordi@eclipsi.net>\n"
"Language-Team: Catalan <ca@dodds.net>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=iso-8859-1\n"
"Content-Transfer-Encoding: 8bit\n"

#: src/connect.c:94
#, c-format
msgid "Connecting to %s[%s]:%hu... "
msgstr "Conectant a %s[%s]:%hu... "

#: src/connect.c:97
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Conectant a %s:%hu... "

#: src/connect.c:131
msgid "connected.\n"
msgstr "conectat.\n"

#: src/cookies.c:595
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Error al fixar a la secció de la cookie `%s'"

#: src/cookies.c:619
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "Error de sintaxi al fixar la cookie al caracter `%c'.\n"

#: src/cookies.c:627
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "Error de sintaxi al fixar la cookie: final inesperat.\n"

#: src/cookies.c:1329
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "No es pot obrir el arxiu de cookies `%s': %s\n"

#: src/cookies.c:1341
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Error d'escriptura a `%s': %s\n"

#: src/cookies.c:1345
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Error tancant `%s': %s\n"

#: src/ftp-ls.c:787
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "tipus de llistat no soportat, intentant fent servir el parsejador de Unix.\n"

#: src/ftp-ls.c:832 src/ftp-ls.c:834
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Índex de /%s a %s:%d"

#: src/ftp-ls.c:856
msgid "time unknown       "
msgstr "temps desconegut       "

#: src/ftp-ls.c:860
msgid "File        "
msgstr "Arxiu         "

#: src/ftp-ls.c:863
msgid "Directory   "
msgstr "Directori   "

#: src/ftp-ls.c:866
msgid "Link        "
msgstr "Enllaç        "

#: src/ftp-ls.c:869
msgid "Not sure    "
msgstr "No segur    "

#: src/ftp-ls.c:887
#, c-format
msgid " (%s bytes)"
msgstr " (%s bytes)"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:179
#, c-format
msgid "Logging in as %s ... "
msgstr "entrant com a %s ... "

#: src/ftp.c:188 src/ftp.c:241 src/ftp.c:272 src/ftp.c:326 src/ftp.c:419
#: src/ftp.c:470 src/ftp.c:500 src/ftp.c:564 src/ftp.c:628 src/ftp.c:689
#: src/ftp.c:737
msgid "Error in server response, closing control connection.\n"
msgstr "Error en el servidor, tancant la conexió de control.\n"

#: src/ftp.c:196
msgid "Error in server greeting.\n"
msgstr "Error en la benvinguda del servidor.\n"

#: src/ftp.c:204 src/ftp.c:335 src/ftp.c:428 src/ftp.c:509 src/ftp.c:574
#: src/ftp.c:638 src/ftp.c:699 src/ftp.c:747
msgid "Write failed, closing control connection.\n"
msgstr "Escritura fallada, tancant la conexió de control.\n"

#: src/ftp.c:211
msgid "The server refuses login.\n"
msgstr "El servidor refusa la entrada.\n"

#: src/ftp.c:218
msgid "Login incorrect.\n"
msgstr "entrada incorrecte.\n"

#: src/ftp.c:225
msgid "Logged in!\n"
msgstr "entrada aconseguida!\n"

#: src/ftp.c:250
msgid "Server error, can't determine system type.\n"
msgstr "Error de servidor, no es pot determinar el tipus de sistema.\n"

#: src/ftp.c:260 src/ftp.c:549 src/ftp.c:612 src/ftp.c:669
msgid "done.    "
msgstr "fet.    "

#: src/ftp.c:314 src/ftp.c:449 src/ftp.c:484 src/ftp.c:720 src/ftp.c:768
#: src/host.c:280
msgid "done.\n"
msgstr "fet.\n"

#: src/ftp.c:343
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Tipus desconegut `%c', tancant la conexió de control.\n"

#: src/ftp.c:356
msgid "done.  "
msgstr "fet.  "

#: src/ftp.c:362
msgid "==> CWD not needed.\n"
msgstr "==> CWD no necessari.\n"

#: src/ftp.c:435
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "No existeix el directori `%s'.\n\n"

#. do not CWD
#: src/ftp.c:453
msgid "==> CWD not required.\n"
msgstr "==> CWD no requerit.\n"

#: src/ftp.c:516
msgid "Cannot initiate PASV transfer.\n"
msgstr "No es pot iniciar la transferéncia en PASV.\n"

#: src/ftp.c:520
msgid "Cannot parse PASV response.\n"
msgstr "No es pot parsejar la resposta en PASV.\n"

#: src/ftp.c:541
#, c-format
msgid "couldn't connect to %s:%hu: %s\n"
msgstr "no es pot conectar a `%s:%hu: %s\n"

#: src/ftp.c:591
#, c-format
msgid "Bind error (%s).\n"
msgstr "Error a la trucada `bind' (%s).\n"

#: src/ftp.c:598
msgid "Invalid PORT.\n"
msgstr "PORT incorrecte.\n"

#: src/ftp.c:651
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nREST fallat; no es truncarà `%s'.\n"

#: src/ftp.c:658
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST ha fallat, començant des del inici.\n"

#: src/ftp.c:707
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "No existeix el arxiu `%s'.\n\n"

#: src/ftp.c:755
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "No existeix el arxiu o directori `%s'.\n\n"

#: src/ftp.c:839 src/ftp.c:847
#, c-format
msgid "Length: %s"
msgstr "Longitut: %s"

#: src/ftp.c:841 src/ftp.c:849
#, c-format
msgid " [%s to go]"
msgstr " [%s per acabar]"

#: src/ftp.c:851
msgid " (unauthoritative)\n"
msgstr " (probablement)\n"

#: src/ftp.c:877
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, tancant la conexió de control.\n"

#: src/ftp.c:885
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s)   Conexió de dades: %s; "

#: src/ftp.c:902
msgid "Control connection closed.\n"
msgstr "Conexió de control tancada.\n"

#: src/ftp.c:920
msgid "Data transfer aborted.\n"
msgstr "Transferéncia de dades cancel·lada.\n"

#: src/ftp.c:984
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "L'arxiu `%s' ja existeix, no es descarregarà.\n"

#: src/ftp.c:1054 src/http.c:1527
#, c-format
msgid "(try:%2d)"
msgstr "(prova:%2d)"

#: src/ftp.c:1118 src/http.c:1786
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s)   `%s guardat [%ld]\n\n"

#: src/ftp.c:1160 src/main.c:822 src/recur.c:349 src/retr.c:587
#, c-format
msgid "Removing %s.\n"
msgstr "Esborrant %s.\n"

#: src/ftp.c:1202
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Utilitzant `%s' com a un arxiu de llistat temporal.\n"

#: src/ftp.c:1217
#, c-format
msgid "Removed `%s'.\n"
msgstr "Esborrat `%s'.\n"

#: src/ftp.c:1252
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "La profunditat de recursió %d excedeix el màxim permés %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1317
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "L'arxiu remot no és més nou que l'arxiu local `%s' -- no es descarrega.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1324
#, c-format
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "L'arxiu remot és més nou que l'arxiu local `%s' -- descarregant.\n\n"

#. Sizes do not match
#: src/ftp.c:1331
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "Els tamanys no corresponen (local %ld) -- descarregant.\n"

#: src/ftp.c:1348
msgid "Invalid name of the symlink, skipping.\n"
msgstr "El nom del enllaç és incorrecte; omitint.\n"

#: src/ftp.c:1365
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Ja té el enllaç correcte %s --> %s\n\n"

#: src/ftp.c:1373
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Creant enllaç %s --> %s\n"

#: src/ftp.c:1384
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Els enllaços no estan suportats, omitint enllaç `%s'.\n"

#: src/ftp.c:1396
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "omitint directori `%s'.\n"

#: src/ftp.c:1405
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tipus d'arxiu desconegut/no soportat.\n"

#: src/ftp.c:1432
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: marca de temps corrupte.\n"

#: src/ftp.c:1457
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "No es descarregaran els directoris perquè la profunditat es %d (màx %d).\n"

#: src/ftp.c:1507
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Es descén fins a `%s' per estar exclós/no inclós.\n"

#: src/ftp.c:1561
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Rebutjant `%s'.\n"
