#
msgid ""
msgstr ""
"Project-Id-Version: wget 1.8.1\n"
"POT-Creation-Date: 2001-12-17 16:30+0100\n"
"PO-Revision-Date: 2002-01-03 18:07+0100\n"
"Last-Translator: Jacobo Tarrío Barreiro <jtarrio@iname.com>\n"
"Language-Team: Galician <gpul-traduccion@ceu.fi.udc.es>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=iso-8859-1\n"
"Content-Transfer-Encoding: 8bit\n"

#: src/connect.c:94
#, c-format
msgid "Connecting to %s[%s]:%hu... "
msgstr "Conectando con %s[%s]:%hu... "

#: src/connect.c:97
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Conectando con %s:%hu... "

#: src/connect.c:131
msgid "connected.\n"
msgstr "conectado.\n"

#: src/cookies.c:595
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Erro en Set-Cookie, campo `%s'"

#: src/cookies.c:619
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "Erro de sintaxe en Set-Cookie no carácter `%c'.\n"

#: src/cookies.c:627
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "Erro de sintaxe en Set-Cookie: fin de cadea prematura.\n"

#: src/cookies.c:1329
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "Non se pode abri-lo ficheiro de cookies `%s': %s\n"

#: src/cookies.c:1341
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "Non se pode escribir en `%s': %s\n"

#: src/cookies.c:1345
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "Erro ao pechar `%s': %s\n"

#: src/ftp-ls.c:802
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "Tipo de listado non soportado, probando o analizador de listados Unix.\n"

#: src/ftp-ls.c:847 src/ftp-ls.c:849
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Índice de /%s en %s:%d"

#: src/ftp-ls.c:871
msgid "time unknown       "
msgstr "data descoñecida   "

#: src/ftp-ls.c:875
msgid "File        "
msgstr "Ficheiro    "

#: src/ftp-ls.c:878
msgid "Directory   "
msgstr "Directorio  "

#: src/ftp-ls.c:881
msgid "Link        "
msgstr "Ligazón     "

#: src/ftp-ls.c:884
msgid "Not sure    "
msgstr "Non seguro  "

#: src/ftp-ls.c:902
#, c-format
msgid " (%s bytes)"
msgstr " (%s bytes)"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:179
#, c-format
msgid "Logging in as %s ... "
msgstr "Identificándome coma %s ... "

#: src/ftp.c:188 src/ftp.c:241 src/ftp.c:272 src/ftp.c:326 src/ftp.c:419
#: src/ftp.c:470 src/ftp.c:500 src/ftp.c:564 src/ftp.c:628 src/ftp.c:689
#: src/ftp.c:737
msgid "Error in server response, closing control connection.\n"
msgstr "Erro na resposta do servidor, pechando a conexión de control.\n"

#: src/ftp.c:196
msgid "Error in server greeting.\n"
msgstr "Erro no saúdo do servidor.\n"

#: src/ftp.c:204 src/ftp.c:335 src/ftp.c:428 src/ftp.c:509 src/ftp.c:574
#: src/ftp.c:638 src/ftp.c:699 src/ftp.c:747
msgid "Write failed, closing control connection.\n"
msgstr "Erro escribindo, pechando a conexión de control.\n"

#: src/ftp.c:211
msgid "The server refuses login.\n"
msgstr "O servidor rexeita o login.\n"

#: src/ftp.c:218
msgid "Login incorrect.\n"
msgstr "Login incorrecto.\n"

#: src/ftp.c:225
msgid "Logged in!\n"
msgstr "¡Conectado!\n"

#: src/ftp.c:250
msgid "Server error, can't determine system type.\n"
msgstr "Erro no servidor, non se pode determina-lo tipo do sistema.\n"

#: src/ftp.c:260 src/ftp.c:549 src/ftp.c:612 src/ftp.c:669
msgid "done.    "
msgstr "feito.   "

#: src/ftp.c:314 src/ftp.c:449 src/ftp.c:484 src/ftp.c:720 src/ftp.c:768
#: src/host.c:283
msgid "done.\n"
msgstr "feito.\n"

#: src/ftp.c:343
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Tipo `%c' descoñecido, pechando a conexión de control.\n"

#: src/ftp.c:356
msgid "done.  "
msgstr "feito.  "

#: src/ftp.c:362
msgid "==> CWD not needed.\n"
msgstr "==> CWD non foi necesario.\n"

#: src/ftp.c:435
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "Non existe tal ficheiro ou directorio `%s'.\n\n"

#. do not CWD
#: src/ftp.c:453
msgid "==> CWD not required.\n"
msgstr "==> CWD non foi preciso.\n"

#: src/ftp.c:516
msgid "Cannot initiate PASV transfer.\n"
msgstr "Non se puido comeza-la transferencia PASV.\n"

#: src/ftp.c:520
msgid "Cannot parse PASV response.\n"
msgstr "Non se puido analiza-la resposta PASV.\n"

#: src/ftp.c:541
#, c-format
msgid "couldn't connect to %s:%hu: %s\n"
msgstr "non se puido conectar a %s:%hu: %s\n"

#: src/ftp.c:591
#, c-format
msgid "Bind error (%s).\n"
msgstr "Erro facendo bind (%s).\n"

#: src/ftp.c:598
msgid "Invalid PORT.\n"
msgstr "PORT incorrecto.\n"

#: src/ftp.c:651
#, c-format
msgid "\nREST failed; will not truncate `%s'.\n"
msgstr "\nREST fallou; non se ha truncar `%s'.\n"

#: src/ftp.c:658
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST fallou, comezando dende o principio.\n"

#: src/ftp.c:707
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "Non hai tal ficheiro `%s'.\n\n"

#: src/ftp.c:755
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "Non hai tal ficheiro ou directorio `%s'.\n\n"

#: src/ftp.c:839 src/ftp.c:847
#, c-format
msgid "Length: %s"
msgstr "Lonxitude: %s"

#: src/ftp.c:841 src/ftp.c:849
#, c-format
msgid " [%s to go]"
msgstr " [quedan %s por descargar]"

#: src/ftp.c:851
msgid " (unauthoritative)\n"
msgstr " (dato non fidedigno)\n"

#: src/ftp.c:877
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, pechando a conexión de control.\n"

#: src/ftp.c:885
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Conexión de datos: %s; "

#: src/ftp.c:902
msgid "Control connection closed.\n"
msgstr "Conexión de control pechada.\n"

#: src/ftp.c:920
msgid "Data transfer aborted.\n"
msgstr "Transferencia de datos abortada.\n"

#: src/ftp.c:984
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "O ficheiro `%s' xa está aí, non se ha descargar.\n"

#: src/ftp.c:1054 src/http.c:1527
#, c-format
msgid "(try:%2d)"
msgstr "(intento:%2d)"

#: src/ftp.c:1118 src/http.c:1786
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' gardado [%ld]\n"

#: src/ftp.c:1160 src/main.c:819 src/recur.c:349 src/retr.c:587
#, c-format
msgid "Removing %s.\n"
msgstr "Borrando %s.\n"

#: src/ftp.c:1202
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Usando `%s' coma un ficheiro temporal de listado.\n"

#: src/ftp.c:1217
#, c-format
msgid "Removed `%s'.\n"
msgstr "Borrado `%s'.\n"

#: src/ftp.c:1252
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "A profundidade de recursión %d excedeu a máxima %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1317
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "O ficheiro remoto non é máis novo có ficheiro local `%s' -- non se descarga.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1324
#, c-format
msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
msgstr "O ficheiro remoto é máis novo có ficheiro local `%s' -- descargando.\n\n"

#. Sizes do not match
#: src/ftp.c:1331
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
msgstr "Os tamaños non coinciden (local %ld) -- descargando.\n\n"

#: src/ftp.c:1348
msgid "Invalid name of the symlink, skipping.\n"
msgstr "O nome da ligazón simbólica é incorrecto, omitindo.\n"

#: src/ftp.c:1365
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "Xa ten unha ligazón simbólica correcta %s -> %s\n\n"

#: src/ftp.c:1373
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Creando a ligazón simbólica %s -> %s\n"

#: src/ftp.c:1384
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Ligazóns simbólicas non soportadas, omitindo `%s'.\n"

#: src/ftp.c:1396
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Omitindo o directorio `%s'.\n"

#: src/ftp.c:1405
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tipo de ficheiro descoñecido ou non soportado.\n"

#: src/ftp.c:1432
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: data e hora corrompidas.\n"

#: src/ftp.c:1457
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Non se han descargar directorios, porque a profundidade chegou a %d (máximo %d).\n"

#: src/ftp.c:1507
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Non se ha descender a %s' porque está excluído ou non incluído.\n"

#: src/ftp.c:1561
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Rexeitando `%s'.\n"
