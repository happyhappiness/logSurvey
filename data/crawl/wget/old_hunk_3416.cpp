#
msgid ""
msgstr ""
"Project-Id-Version: wget 1.7\n"
"POT-Creation-Date: 2001-06-03 15:27+0200\n"
"PO-Revision-Date: 2001-06-07 09:28+02:00\n"
"Last-Translator: Jacobo Tarrío Barreiro <jtarrio@iname.com>\n"
"Language-Team: Galician <gpul-traduccion@ceu.fi.udc.es>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=iso-8859-1\n"
"Content-Transfer-Encoding: 8bit\n"

#: src/cookies.c:588
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Erro en Set-Cookie, campo `%s'"

#: src/cookies.c:612
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "Erro de sintaxe en Set-Cookie no carácter `%c'.\n"

#: src/cookies.c:620
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "Erro de sintaxe en Set-Cookie: fin de cadea prematura.\n"

#: src/cookies.c:1352
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Non se pode abri-lo ficheiro de cookies `%s': %s\n"

#: src/cookies.c:1364
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Non se pode escribir en `%s': %s\n"

#: src/cookies.c:1368
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Erro ao pechar `%s': %s\n"

#: src/ftp-ls.c:787
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "Tipo de listado non soportado, probando o analizador de listados Unix.\n"

#: src/ftp-ls.c:832 src/ftp-ls.c:834
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Índice de /%s en %s:%d"

#: src/ftp-ls.c:856
msgid "time unknown       "
msgstr "data descoñecida   "

#: src/ftp-ls.c:860
msgid "File        "
msgstr "Ficheiro    "

#: src/ftp-ls.c:863
msgid "Directory   "
msgstr "Directorio  "

#: src/ftp-ls.c:866
msgid "Link        "
msgstr "Ligazón     "

#: src/ftp-ls.c:869
msgid "Not sure    "
msgstr "Non seguro  "

#: src/ftp-ls.c:887
#, c-format
msgid " (%s bytes)"
msgstr " (%s bytes)"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:150 src/http.c:624
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Conectando con %s:%hu... "

#: src/ftp.c:172 src/ftp.c:539 src/http.c:641
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "A conexión a %s:%hu foi rexeitada.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:193 src/http.c:652
msgid "connected!\n"
msgstr "¡conectado!\n"

#: src/ftp.c:194
#, c-format
msgid "Logging in as %s ... "
msgstr "Identificándome coma %s ... "

#: src/ftp.c:203 src/ftp.c:256 src/ftp.c:288 src/ftp.c:336 src/ftp.c:429
#: src/ftp.c:481 src/ftp.c:575 src/ftp.c:648 src/ftp.c:709 src/ftp.c:757
msgid "Error in server response, closing control connection.\n"
msgstr "Erro na resposta do servidor, pechando a conexión de control.\n"

#: src/ftp.c:211
msgid "Error in server greeting.\n"
msgstr "Erro no saúdo do servidor.\n"

#: src/ftp.c:219 src/ftp.c:345 src/ftp.c:438 src/ftp.c:490 src/ftp.c:585
#: src/ftp.c:658 src/ftp.c:719 src/ftp.c:767
msgid "Write failed, closing control connection.\n"
msgstr "Erro escribindo, pechando a conexión de control.\n"

#: src/ftp.c:226
msgid "The server refuses login.\n"
msgstr "O servidor rexeita o login.\n"

#: src/ftp.c:233
msgid "Login incorrect.\n"
msgstr "Login incorrecto.\n"

#: src/ftp.c:240
msgid "Logged in!\n"
msgstr "¡Conectado!\n"

#: src/ftp.c:265
msgid "Server error, can't determine system type.\n"
msgstr "Erro no servidor, non se pode determina-lo tipo do sistema.\n"

#: src/ftp.c:275 src/ftp.c:560 src/ftp.c:632 src/ftp.c:689
msgid "done.    "
msgstr "feito.   "

#: src/ftp.c:325 src/ftp.c:459 src/ftp.c:740 src/ftp.c:788 src/url.c:1429
msgid "done.\n"
msgstr "feito.\n"

#: src/ftp.c:353
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Tipo `%c' descoñecido, pechando a conexión de control.\n"

#: src/ftp.c:366
msgid "done.  "
msgstr "feito.  "

#: src/ftp.c:372
msgid "==> CWD not needed.\n"
msgstr "==> CWD non foi necesario.\n"

#: src/ftp.c:445
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Non existe tal ficheiro ou directorio `%s'.\n\n"

#. do not CWD
#: src/ftp.c:463
msgid "==> CWD not required.\n"
msgstr "==> CWD non foi preciso.\n"

#: src/ftp.c:497
msgid "Cannot initiate PASV transfer.\n"
msgstr "Non se puido comeza-la transferencia PASV.\n"

#: src/ftp.c:501
msgid "Cannot parse PASV response.\n"
msgstr "Non se puido analiza-la resposta PASV.\n"

#: src/ftp.c:515
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Tentarase conectar con %s:%hu.\n"

#: src/ftp.c:602
#, c-format
msgid "Bind error (%s).\n"
msgstr "Erro facendo bind (%s).\n"

#: src/ftp.c:618
msgid "Invalid PORT.\n"
msgstr "PORT incorrecto.\n"

#: src/ftp.c:671
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nREST fallou; non se ha truncar `%s'.\n"

#: src/ftp.c:678
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST fallou, comezando dende o principio.\n"

#: src/ftp.c:727
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Non hai tal ficheiro `%s'.\n\n"

#: src/ftp.c:775
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Non hai tal ficheiro ou directorio `%s'.\n\n"

#: src/ftp.c:859 src/ftp.c:867
#, c-format
msgid "Length: %s"
msgstr "Lonxitude: %s"

#: src/ftp.c:861 src/ftp.c:869
#, c-format
msgid " [%s to go]"
msgstr " [quedan %s por descargar]"

#: src/ftp.c:871
msgid " (unauthoritative)\n"
msgstr " (dato non fidedigno)\n"

#: src/ftp.c:898
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, pechando a conexión de control.\n"

#: src/ftp.c:906
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Conexión de datos: %s; "

#: src/ftp.c:923
msgid "Control connection closed.\n"
msgstr "Conexión de control pechada.\n"

#: src/ftp.c:941
msgid "Data transfer aborted.\n"
msgstr "Transferencia de datos abortada.\n"

#: src/ftp.c:1005
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "O ficheiro `%s' xa está aí, non se ha descargar.\n"

#: src/ftp.c:1075 src/http.c:1502
#, c-format
msgid "(try:%2d)"
msgstr "(intento:%2d)"

#: src/ftp.c:1139 src/http.c:1753
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' gardado [%ld]\n"

#: src/ftp.c:1181 src/main.c:810 src/recur.c:483 src/retr.c:566
#, c-format
msgid "Removing %s.\n"
msgstr "Borrando %s.\n"

#: src/ftp.c:1221
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Usando `%s' coma un ficheiro temporal de listado.\n"

#: src/ftp.c:1233
#, c-format
msgid "Removed `%s'.\n"
msgstr "Borrado `%s'.\n"

#: src/ftp.c:1269
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "A profundidade de recursión %d excedeu a máxima %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1330
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "O ficheiro remoto non é máis novo có ficheiro local `%s' -- non se descarga.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1337
#, c-format
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "O ficheiro remoto é máis novo có ficheiro local `%s' -- descargando.\n\n"

#. Sizes do not match
#: src/ftp.c:1344
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "Os tamaños non coinciden (local %ld) -- descargando.\n\n"

#: src/ftp.c:1361
msgid "Invalid name of the symlink, skipping.\n"
msgstr "O nome da ligazón simbólica é incorrecto, omitindo.\n"

#: src/ftp.c:1378
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Xa ten unha ligazón simbólica correcta %s -> %s\n\n"

#: src/ftp.c:1386
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Creando a ligazón simbólica %s -> %s\n"

#: src/ftp.c:1397
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Ligazóns simbólicas non soportadas, omitindo `%s'.\n"

#: src/ftp.c:1409
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Omitindo o directorio `%s'.\n"

#: src/ftp.c:1418
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tipo de ficheiro descoñecido ou non soportado.\n"

#: src/ftp.c:1445
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: data e hora corrompidas.\n"

#: src/ftp.c:1466
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Non se han descargar directorios, porque a profundidade chegou a %d (máximo %d).\n"

#: src/ftp.c:1512
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Non se ha descender a %s' porque está excluído ou non incluído.\n"

#: src/ftp.c:1559
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Rexeitando `%s'.\n"
