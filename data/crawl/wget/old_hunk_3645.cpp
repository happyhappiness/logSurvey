# SOME DESCRIPTIVE TITLE.
# Copyright (C) YEAR Free Software Foundation, Inc.
# FIRST AUTHOR <EMAIL@ADDRESS>, YEAR.
#
msgid ""
msgstr ""
"Project-Id-Version: GNU Wget 1.6\n"
"POT-Creation-Date: 2001-02-26 21:18-0300\n"
"PO-Revision-Date: 2001-02-26 22:45+0300\n"
"Last-Translator: Nicolás Lichtmaier <nick@debian.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=ISO-8859-1\n"
"Content-Transfer-Encoding: 8bit\n"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:152 src/http.c:354
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "Conectándose con %s:%hu... "

#: src/ftp.c:174 src/ftp.c:416 src/http.c:371
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "Conexión con %s:%hu rehusada.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:195 src/http.c:382
msgid "connected!\n"
msgstr "¡conectado!\n"

#: src/ftp.c:196
#, c-format
msgid "Logging in as %s ... "
msgstr "Entrando como %s ... "

#: src/ftp.c:205 src/ftp.c:258 src/ftp.c:306 src/ftp.c:358 src/ftp.c:452
#: src/ftp.c:525 src/ftp.c:573 src/ftp.c:621
msgid "Error in server response, closing control connection.\n"
msgstr ""

#: src/ftp.c:213
msgid "Error in server greeting.\n"
msgstr ""

#: src/ftp.c:221 src/ftp.c:267 src/ftp.c:315 src/ftp.c:367 src/ftp.c:462
#: src/ftp.c:535 src/ftp.c:583 src/ftp.c:631
msgid "Write failed, closing control connection.\n"
msgstr ""

#: src/ftp.c:228
msgid "The server refuses login.\n"
msgstr ""

#: src/ftp.c:235
msgid "Login incorrect.\n"
msgstr "Login incorrecto.\n"

#: src/ftp.c:242
msgid "Logged in!\n"
msgstr "¡Adentro!\n"

#: src/ftp.c:275
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "Tipo `%c' desconocido, cerrando conexión de control.\n"

#: src/ftp.c:288
msgid "done.  "
msgstr "hecho.  "

#: src/ftp.c:294
msgid "==> CWD not needed.\n"
msgstr "==> No se necesita CWD.\n"

#: src/ftp.c:322
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"No existe ningún directorio `%s'.\n"
"\n"

#: src/ftp.c:336 src/ftp.c:604 src/ftp.c:652 src/url.c:1678
msgid "done.\n"
msgstr "hecho.\n"

#. do not CWD
#: src/ftp.c:340
msgid "==> CWD not required.\n"
msgstr "==> No se requiere CWD.\n"

#: src/ftp.c:374
msgid "Cannot initiate PASV transfer.\n"
msgstr "No se puede iniciar transferencia PASV.\n"

#: src/ftp.c:378
msgid "Cannot parse PASV response.\n"
msgstr "No se pudo interpretar la respuesta de PASV.\n"

#: src/ftp.c:392
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "Se intentará conectarse con %s:%hu.\n"

#: src/ftp.c:437 src/ftp.c:509 src/ftp.c:553
msgid "done.    "
msgstr "hecho.    "

#: src/ftp.c:479
#, c-format
msgid "Bind error (%s).\n"
msgstr ""

#: src/ftp.c:495
msgid "Invalid PORT.\n"
msgstr "PUERTO inválido.\n"

#: src/ftp.c:542
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"Falló REST, recomenzando de cero.\n"

#: src/ftp.c:591
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"No existe un archivo `%s'.\n"
"\n"

#: src/ftp.c:639
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"No existe el archivo o directorio `%s'.\n"
"\n"

#: src/ftp.c:715 src/ftp.c:722
#, c-format
msgid "Length: %s"
msgstr "Tamaño: %s"

#: src/ftp.c:717 src/ftp.c:724
#, c-format
msgid " [%s to go]"
msgstr " [%s para terminar]"

#: src/ftp.c:726
msgid " (unauthoritative)\n"
msgstr ""

#: src/ftp.c:752
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, cerrando conexión de control.\n"

#: src/ftp.c:760
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - Conexión de datos: %s; "

#: src/ftp.c:777
msgid "Control connection closed.\n"
msgstr "Conexión de control cerrada.\n"

#: src/ftp.c:795
msgid "Data transfer aborted.\n"
msgstr "Transferencia de datos abortada.\n"

#: src/ftp.c:859
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "El archivo `%s' ya está, no se trae.\n"

#: src/ftp.c:920 src/http.c:1021
#, c-format
msgid "(try:%2d)"
msgstr "(intento:%2d)"

#: src/ftp.c:984 src/http.c:1251
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld]\n"
"\n"
msgstr ""
"%s (%s) - %s' guardado [%ld]\n"
"\n"

#: src/ftp.c:1026 src/main.c:754 src/recur.c:472 src/retr.c:564
#, c-format
msgid "Removing %s.\n"
msgstr "Borrando %s.\n"

#: src/ftp.c:1067
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "Usando `%s' como archivo temporario para el listado.\n"

#: src/ftp.c:1079
#, c-format
msgid "Removed `%s'.\n"
msgstr "Se borra `%s'.\n"

#: src/ftp.c:1115
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr ""

#: src/ftp.c:1167 src/http.c:1168
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""
"El archivo en el servidor no es más reciente que el local `%s' -- no se trae.\n"
"\n"

#: src/ftp.c:1173 src/http.c:1176
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Los tamaños no coinciden (el local es %ld) -- se trae.\n"

#: src/ftp.c:1190
msgid "Invalid name of the symlink, skipping.\n"
msgstr "El nombre del enlace simbólico no es válido. Se saltea.\n"

#: src/ftp.c:1207
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"Ya se tiene el enlace %s -> %s correcto\n"
"\n"

#: src/ftp.c:1215
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Creando enlace simbólico %s -> %s\n"

#: src/ftp.c:1226
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "No se soportan enlaces simbólicos, se saltéa `%s'.\n"

#: src/ftp.c:1238
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Ignorando directorio `%s'.\n"

#: src/ftp.c:1247
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: tipo de archivo desconocido/no soportado.\n"

#: src/ftp.c:1274
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: datado corrupto.\n"

#: src/ftp.c:1295
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "No se traen directorios ya que la profundidad es %d (máx: %d).\n"

#: src/ftp.c:1334
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "No se desciende a `%s' ya que está excluido o no incluido.\n"

#: src/ftp.c:1379
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Rechazando `%s'.\n"

#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1426
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "No hay coincidencias con `%s'.\n"

#: src/ftp.c:1486
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "Índice en formato HTML escrito en `%s' [%ld].\n"

#: src/ftp.c:1491
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Índice en formato HTML escrito en `%s'.\n"

#: src/getopt.c:454
#, c-format
