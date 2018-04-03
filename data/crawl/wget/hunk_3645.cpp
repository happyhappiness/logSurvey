-# SOME DESCRIPTIVE TITLE.
-# Copyright (C) YEAR Free Software Foundation, Inc.
-# FIRST AUTHOR <EMAIL@ADDRESS>, YEAR.
+# Mensajes en español para GNU wget.
+# Copyright (C) 2001 Free Software Foundation, Inc.
+# Salvador Gimeno Zanón <salgiza@jazzfree.com>, 2001
+#
+# Traducido con la ayuda de:
+# Juan José Rodríguez <jcnsoft@jal1.telmex.net.mx>
+#
+# Revisado por:
+# Carlos Linares López <clinares@delicias.dia.fi.upm.es; carlosl@acm.org>
+# Santiago Vila <sanvila@unex.es>
+# Nicolás Lichtmaier <nick@feedback.net.ar>
+#
+# Notas:
+#
+# 1. Los comentarios que empiezan por "Duda:" se refieren a mensajes que
+#    debieran ser revisados.
 #
 msgid ""
 msgstr ""
-"Project-Id-Version: GNU Wget 1.6\n"
-"POT-Creation-Date: 2001-02-26 21:18-0300\n"
-"PO-Revision-Date: 2001-02-26 22:45+0300\n"
-"Last-Translator: Nicolás Lichtmaier <nick@debian.org>\n"
+"Project-Id-Version: wget 1.7-pre1\n"
+"POT-Creation-Date: 2001-05-26 11:07+0200\n"
+"PO-Revision-Date: 2001-06-02 16:16GMT+0200\n"
+"Last-Translator: Salvador Gimeno Zanón <salgiza@jazzfree.com>\n"
+"Language-Team: Spanish <es@li.org>\n"
 "MIME-Version: 1.0\n"
 "Content-Type: text/plain; charset=ISO-8859-1\n"
 "Content-Transfer-Encoding: 8bit\n"
+"X-Generator: KBabel 0.8\n"
+
+#: src/cookies.c:588
+#, c-format
+msgid "Error in Set-Cookie, field `%s'"
+msgstr "Error al asignar cookie, en el campo `%s'"
+
+#: src/cookies.c:612
+#, c-format
+msgid "Syntax error in Set-Cookie at character `%c'.\n"
+msgstr "Error de sintaxis al asignar cookie, en el carácter `%c'.\n"
+
+#: src/cookies.c:620
+msgid "Syntax error in Set-Cookie: premature end of string.\n"
+msgstr "Error de sintaxis al asignar cookie: fin de cadena inesperado.\n"
+
+#: src/cookies.c:1352
+#, c-format
+msgid "Cannot open cookies file `%s': %s\n"
+msgstr "No se pudo abrir el fichero de cookies `%s': %s\n"
+
+#: src/cookies.c:1364
+#, c-format
+msgid "Error writing to `%s': %s\n"
+msgstr "Error escribiendo a `%s': %s\n"
+
+#: src/cookies.c:1368
+#, c-format
+msgid "Error closing `%s': %s\n"
+msgstr "Error cerrando `%s': %s\n"
+
+#: src/ftp-ls.c:787
+msgid "Usupported listing type, trying Unix listing parser.\n"
+msgstr "Tipo de listado no soportado, se intenará con el parseador de listados de Unix.\n"
+
+#: src/ftp-ls.c:832 src/ftp-ls.c:834
+#, c-format
+msgid "Index of /%s on %s:%d"
+msgstr "Índice de /%s en %s:%d"
+
+#: src/ftp-ls.c:856
+msgid "time unknown       "
+msgstr "hora desconocida   "
+
+#: src/ftp-ls.c:860
+msgid "File        "
+msgstr "Fichero     "
+
+#: src/ftp-ls.c:863
+msgid "Directory   "
+msgstr "Directorio  "
+
+#: src/ftp-ls.c:866
+msgid "Link        "
+msgstr "Enlace      "
 
+# creo que se refiere al tipo (fichero/directorio/enlace)
+#: src/ftp-ls.c:869
+msgid "Not sure    "
+msgstr "Ni idea     "
+
+#: src/ftp-ls.c:887
+#, c-format
+msgid " (%s bytes)"
+msgstr " (%s bytes)"
+
+# Me temo que nadie se "conecta a" sino que se "conecta con", ... ¿no te
+# suena mejor? - cll
+# sip - Salva
+#
 #. Login to the server:
 #. First: Establish the control connection.
-#: src/ftp.c:152 src/http.c:354
+#: src/ftp.c:149 src/http.c:623
 #, c-format
 msgid "Connecting to %s:%hu... "
-msgstr "Conectándose con %s:%hu... "
+msgstr "Conectando con %s:%hu... "
 
-#: src/ftp.c:174 src/ftp.c:416 src/http.c:371
+#: src/ftp.c:171 src/ftp.c:538 src/http.c:640
 #, c-format
 msgid "Connection to %s:%hu refused.\n"
-msgstr "Conexión con %s:%hu rehusada.\n"
+msgstr "Conexión con %s:%hu rechazada.\n"
 
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:195 src/http.c:382
+#: src/ftp.c:192 src/http.c:651
 msgid "connected!\n"
-msgstr "¡conectado!\n"
+msgstr "¡Conectado!\n"
 
-#: src/ftp.c:196
+# mmmm... no estoy seguro de esto...
+# ¿Así no es mejor? (nl)
+#: src/ftp.c:193
 #, c-format
 msgid "Logging in as %s ... "
-msgstr "Entrando como %s ... "
+msgstr "Identificándose como %s ... "
 
-#: src/ftp.c:205 src/ftp.c:258 src/ftp.c:306 src/ftp.c:358 src/ftp.c:452
-#: src/ftp.c:525 src/ftp.c:573 src/ftp.c:621
+# Me parece más `humanoide' añadir el artículo a las cosas, ... Los
+# angloparlantes suelen evitarlo (¿será porque no son humanos? :) pero
+# eso no significa que nosotros nos lo ahorremos, pues eso es contrario
+# a nuestra costumbre - cll
+# einch! que tengo familiares güiris ;-) , pero tienes razón -Salva
+#
+#: src/ftp.c:202 src/ftp.c:255 src/ftp.c:287 src/ftp.c:335 src/ftp.c:428
+#: src/ftp.c:480 src/ftp.c:574 src/ftp.c:647 src/ftp.c:708 src/ftp.c:756
 msgid "Error in server response, closing control connection.\n"
-msgstr ""
+msgstr "Error en la respuesta del servidor, cerrando la conexión de control.\n"
 
-#: src/ftp.c:213
+# `greeting' también puede traducirse como `recepción' que, en este
+# caso, me parece más apropiado. -cll
+# bien - Salva
+# No está bien, es confuso. Recepción suena a recibir... (nl)
+#
+#: src/ftp.c:210
 msgid "Error in server greeting.\n"
-msgstr ""
+msgstr "Error en el saludo del servidor.\n"
 
-#: src/ftp.c:221 src/ftp.c:267 src/ftp.c:315 src/ftp.c:367 src/ftp.c:462
-#: src/ftp.c:535 src/ftp.c:583 src/ftp.c:631
+# En inglés suele resultar muy adecuada la utilización de participios,
+# puesto que esa es una forma de adjetivación muy común. Sin embargo, en
+# español crea un efecto "computadora" muy desagradable, ...
+#
+# Por ejemplo, "Fallo de escritura" me parece muchísimo más apropiado
+# que "Escritura fallida"
+#
+# Además, he añadido el artículo a `conexión' - cll
+#
+#: src/ftp.c:218 src/ftp.c:344 src/ftp.c:437 src/ftp.c:489 src/ftp.c:584
+#: src/ftp.c:657 src/ftp.c:718 src/ftp.c:766
 msgid "Write failed, closing control connection.\n"
-msgstr ""
+msgstr "Fallo de escritura, cerrando la conexión de control.\n"
 
-#: src/ftp.c:228
+# Es una regla de oro intentar evitar las expresiones en inglés tanto
+# como sea posible. Esta ha sido una cuestión harto discutida en
+# es@li.org y, al final, se decidió, por consenso adoptar siempre la
+# siguiente norma:
+#
+# "Siempre que sea posible debe sustituirse el término en inglés por
+# otro equivalente en español. Solo si el término español no resulta
+# suficientemente descriptivo puede acompañarse entre paréntesis del
+# término en inglés. Por ejemplo: `pipe' se debe traducir por `tubería',
+# pero como este término puede resultar extraño para muchos
+# programadores, se admite: `tuberia (pipe)'.
+#
+# A propósito de esta norma, `login' puede parecer un término muy
+# extendido que todo el mundo conoce y entiende, ¡pero no es
+# español!.
+#
+# Me he permitido sustituirte `login' por `acceso', o una expresión
+# equivalente, en todos los mensajes del fichero. Espero que te parezca
+# oportuno - cll
+#
+#: src/ftp.c:225
 msgid "The server refuses login.\n"
-msgstr ""
+msgstr "El servidor ha rechazado el acceso.\n"
 
-#: src/ftp.c:235
+# Duda: en este caso, sospecho que el `login' se refiere al nombre de
+# usuario, ¿verdad? - cll
+# sí -Salva
+#
+#: src/ftp.c:232
 msgid "Login incorrect.\n"
-msgstr "Login incorrecto.\n"
+msgstr "Nombre de usuario incorrecto.\n"
 
-#: src/ftp.c:242
+# ¡Una excelente traducción! :) - cll
+# gracias! :) -Salva
+#
+# Preferiría algo como "Conectado" o algo así. sv
+#: src/ftp.c:239
 msgid "Logged in!\n"
-msgstr "¡Adentro!\n"
+msgstr "¡Dentro!\n"
 
-#: src/ftp.c:275
+#: src/ftp.c:264
+msgid "Server error, can't determine system type.\n"
+msgstr "Error del servidor, no se pudo determinar el tipo de sistema.\n"
+
+#: src/ftp.c:274 src/ftp.c:559 src/ftp.c:631 src/ftp.c:688
+msgid "done.    "
+msgstr "hecho.   "
+
+#: src/ftp.c:324 src/ftp.c:458 src/ftp.c:739 src/ftp.c:787 src/url.c:1429
+msgid "done.\n"
+msgstr "hecho.\n"
+
+# He añadido el artículo a `conexión' - cll
+#
+#: src/ftp.c:352
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
-msgstr "Tipo `%c' desconocido, cerrando conexión de control.\n"
+msgstr "Tipo desconocido `%c', cerrando la conexión de control.\n"
 
-#: src/ftp.c:288
+#: src/ftp.c:365
 msgid "done.  "
 msgstr "hecho.  "
 
-#: src/ftp.c:294
+#: src/ftp.c:371
 msgid "==> CWD not needed.\n"
-msgstr "==> No se necesita CWD.\n"
+msgstr "==> no se necesita CWD.\n"
 
-#: src/ftp.c:322
+#: src/ftp.c:444
 #, c-format
-msgid ""
-"No such directory `%s'.\n"
-"\n"
-msgstr ""
-"No existe ningún directorio `%s'.\n"
-"\n"
-
-#: src/ftp.c:336 src/ftp.c:604 src/ftp.c:652 src/url.c:1678
-msgid "done.\n"
-msgstr "hecho.\n"
+msgid "No such directory `%s'.\n\n"
+msgstr "No existe el directorio `%s'.\n\n"
 
 #. do not CWD
-#: src/ftp.c:340
+#: src/ftp.c:462
 msgid "==> CWD not required.\n"
-msgstr "==> No se requiere CWD.\n"
+msgstr "==> no se requiere CWD.\n"
 
-#: src/ftp.c:374
+#: src/ftp.c:496
 msgid "Cannot initiate PASV transfer.\n"
-msgstr "No se puede iniciar transferencia PASV.\n"
+msgstr "No se pudo iniciar la trasferencia PASV.\n"
 
-#: src/ftp.c:378
+#: src/ftp.c:500
 msgid "Cannot parse PASV response.\n"
-msgstr "No se pudo interpretar la respuesta de PASV.\n"
+msgstr "No se pudo analizar la respuesta PASV.\n"
 
-#: src/ftp.c:392
+#: src/ftp.c:514
 #, c-format
 msgid "Will try connecting to %s:%hu.\n"
-msgstr "Se intentará conectarse con %s:%hu.\n"
-
-#: src/ftp.c:437 src/ftp.c:509 src/ftp.c:553
-msgid "done.    "
-msgstr "hecho.    "
+msgstr "Se intentará conectar con %s:%hu.\n"
 
-#: src/ftp.c:479
+# Duda: no estoy muy seguro, pero ... ¿y `error de enlace' o algo
+# parecido? Probablemente, este sea uno de los casos en los que debas
+# incluir entre paréntesis la palabra `bind'.
+#
+# Mientras tanto, te sugiero `error de enlace (bind)' - cll
+# la verdad es que no tengo ni idea de qué es esto :( - Salva
+#
+# Es la función bind(2), que asigna una dirección a un socket.
+# Me parece que decir lo de la función es mejor. (nl)
+#
+#: src/ftp.c:601
 #, c-format
 msgid "Bind error (%s).\n"
-msgstr ""
+msgstr "Error en la llamada `bind' (%s).\n"
 
-#: src/ftp.c:495
+# Ya no está "prohibido" usar esta palabra. sv
+#: src/ftp.c:617
 msgid "Invalid PORT.\n"
 msgstr "PUERTO inválido.\n"
 
-#: src/ftp.c:542
-msgid ""
-"\n"
-"REST failed, starting from scratch.\n"
-msgstr ""
-"\n"
-"Falló REST, recomenzando de cero.\n"
+#: src/ftp.c:670
+#, c-format
+msgid "\nREST failed; will not truncate `%s'.\n"
+msgstr "\nEl comando REST no funcionó, no se truncará `%s'.\n"
+
+#: src/ftp.c:677
+msgid "\nREST failed, starting from scratch.\n"
+msgstr "\nEl comando REST no funcionó, se empezará desde el principio\n"
 
-#: src/ftp.c:591
+#: src/ftp.c:726
 #, c-format
-msgid ""
-"No such file `%s'.\n"
-"\n"
-msgstr ""
-"No existe un archivo `%s'.\n"
-"\n"
+msgid "No such file `%s'.\n\n"
+msgstr "No existe el fichero `%s'.\n\n"
 
-#: src/ftp.c:639
+#: src/ftp.c:774
 #, c-format
-msgid ""
-"No such file or directory `%s'.\n"
-"\n"
-msgstr ""
-"No existe el archivo o directorio `%s'.\n"
-"\n"
+msgid "No such file or directory `%s'.\n\n"
+msgstr "No existe el fichero o directorio `%s'.\n\n"
 
-#: src/ftp.c:715 src/ftp.c:722
+#: src/ftp.c:858 src/ftp.c:866
 #, c-format
 msgid "Length: %s"
-msgstr "Tamaño: %s"
+msgstr "Longitud: %s"
 
-#: src/ftp.c:717 src/ftp.c:724
+#: src/ftp.c:860 src/ftp.c:868
 #, c-format
 msgid " [%s to go]"
-msgstr " [%s para terminar]"
+msgstr " [%s para acabar]"
 
-#: src/ftp.c:726
+# nota jjrs: Se agrega este mensaje cuando el wget no ha obtenido
+#   directamente el tamaño del archivo a transferir y esta usando la
+#   longitud que reporta el inicio de la transferencia.
+#
+# ¡Dabuti! Si no lo llegas a decir, ... ¡Lo estaba flipando! :) Pero
+# vamos, siendo como dices, a mí me suena perfectísimamente - cll
+#
+#: src/ftp.c:870
 msgid " (unauthoritative)\n"
-msgstr ""
+msgstr " (probablemente)\n"
 
-#: src/ftp.c:752
+# He añadido el artículo a `conexión' - cll
+#
+#: src/ftp.c:897
 #, c-format
 msgid "%s: %s, closing control connection.\n"
-msgstr "%s: %s, cerrando conexión de control.\n"
+msgstr "%s: %s, cerrando la conexión de control.\n"
 
-#: src/ftp.c:760
+#: src/ftp.c:905
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - Conexión de datos: %s; "
 
-#: src/ftp.c:777
+#: src/ftp.c:922
 msgid "Control connection closed.\n"
 msgstr "Conexión de control cerrada.\n"
 
-#: src/ftp.c:795
+#: src/ftp.c:940
 msgid "Data transfer aborted.\n"
-msgstr "Transferencia de datos abortada.\n"
+msgstr "Trasferencia de datos abortada.\n"
 
-#: src/ftp.c:859
+# `no recuperando' no me suena muy español, te propongo la alternativa
+# más "humanizada", `no se recupera' - cll
+#
+#: src/ftp.c:1004
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
-msgstr "El archivo `%s' ya está, no se trae.\n"
+msgstr "El fichero `%s' ya está ahí, no se recupera.\n"
 
-#: src/ftp.c:920 src/http.c:1021
+# nota jjrs: no sería mejor intento?
+# pues sí - Salva
+# decididamente si - cll
+#: src/ftp.c:1074 src/http.c:1501
 #, c-format
 msgid "(try:%2d)"
 msgstr "(intento:%2d)"
 
-#: src/ftp.c:984 src/http.c:1251
+#: src/ftp.c:1138 src/http.c:1752
 #, c-format
-msgid ""
-"%s (%s) - `%s' saved [%ld]\n"
-"\n"
-msgstr ""
-"%s (%s) - %s' guardado [%ld]\n"
-"\n"
+msgid "%s (%s) - `%s' saved [%ld]\n\n"
+msgstr "%s (%s) - `%s' guardado [%ld]\n\n"
 
-#: src/ftp.c:1026 src/main.c:754 src/recur.c:472 src/retr.c:564
+#: src/ftp.c:1180 src/main.c:809 src/recur.c:483 src/retr.c:566
 #, c-format
 msgid "Removing %s.\n"
-msgstr "Borrando %s.\n"
+msgstr "Eliminando %s.\n"
 
-#: src/ftp.c:1067
+#: src/ftp.c:1220
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
-msgstr "Usando `%s' como archivo temporario para el listado.\n"
+msgstr "Usando `%s' como fichero temporal de listado.\n"
 
-#: src/ftp.c:1079
+# Aquí volvemos un poco a lo de siempre: en inglés, los participios se
+# emplean con frecuencia para adjetivar un sustantivo, sin embargo, en
+# español sirven para hacer referencia a una acción. Esto es, deben ir
+# después del sustantivo - cll
+#
+#: src/ftp.c:1232
 #, c-format
 msgid "Removed `%s'.\n"
-msgstr "Se borra `%s'.\n"
+msgstr "`%s' eliminado.\n"
 
-#: src/ftp.c:1115
+#: src/ftp.c:1268
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
-msgstr ""
+msgstr "La profundidad de recursión %d excede la máxima de %d.\n"
 
-#: src/ftp.c:1167 src/http.c:1168
+#. Remote file is older, file sizes can be compared and
+#. are both equal.
+#: src/ftp.c:1329
 #, c-format
-msgid ""
-"Server file no newer than local file `%s' -- not retrieving.\n"
-"\n"
-msgstr ""
-"El archivo en el servidor no es más reciente que el local `%s' -- no se trae.\n"
-"\n"
+msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
+msgstr "El fichero remoto no es más moderno que el fichero local `%s' -- no se descargará.\n"
 
-#: src/ftp.c:1173 src/http.c:1176
+#. Remote file is newer or sizes cannot be matched
+#: src/ftp.c:1336
 #, c-format
-msgid "The sizes do not match (local %ld) -- retrieving.\n"
-msgstr "Los tamaños no coinciden (el local es %ld) -- se trae.\n"
+msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
+msgstr "El fichero remoto es más moderno que el fichero local `%s' -- descargando.\n\n"
+
+#. Sizes do not match
+#: src/ftp.c:1343
+#, c-format
+msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
+msgstr "Los tamaños no concuerdan (%ld local) -- recuperando.\n\n"
 
-#: src/ftp.c:1190
+# Simplemente me suena mejor `omitir' que `saltar'. Ademàs, las acciones
+# expresadas en gerundio, ..., prefiero una forma impersonal como `se
+# omite' - cll
+#
+#: src/ftp.c:1360
 msgid "Invalid name of the symlink, skipping.\n"
-msgstr "El nombre del enlace simbólico no es válido. Se saltea.\n"
+msgstr "El nombre del enlace simbólico no es válido, se omite.\n"
 
-#: src/ftp.c:1207
+#: src/ftp.c:1377
 #, c-format
-msgid ""
-"Already have correct symlink %s -> %s\n"
-"\n"
-msgstr ""
-"Ya se tiene el enlace %s -> %s correcto\n"
-"\n"
+msgid "Already have correct symlink %s -> %s\n\n"
+msgstr "Ya se tiene el enlace simbólico correcto %s -> %s\n\n"
 
-#: src/ftp.c:1215
+#: src/ftp.c:1385
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "Creando enlace simbólico %s -> %s\n"
 
-#: src/ftp.c:1226
+# Lo dicho de los gerundios por formas impersonales - cll
+#
+#: src/ftp.c:1396
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
-msgstr "No se soportan enlaces simbólicos, se saltéa `%s'.\n"
+msgstr "No se admiten enlaces simbólicos, se omite el enlace simbólico `%s'.\n"
 
-#: src/ftp.c:1238
+#: src/ftp.c:1408
 #, c-format
 msgid "Skipping directory `%s'.\n"
-msgstr "Ignorando directorio `%s'.\n"
+msgstr "Omitiendo el directorio `%s'.\n"
 
-#: src/ftp.c:1247
+#: src/ftp.c:1417
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
-msgstr "%s: tipo de archivo desconocido/no soportado.\n"
+msgstr "%s: tipo de fichero desconocido/no soportado.\n"
 
-#: src/ftp.c:1274
+# sigo las indicaciones del texto "pifias" para time-stamp.
+#: src/ftp.c:1444
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
-msgstr "%s: datado corrupto.\n"
+msgstr "%s: marca de tiempo corrupta.\n"
 
-#: src/ftp.c:1295
+#: src/ftp.c:1465
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
-msgstr "No se traen directorios ya que la profundidad es %d (máx: %d).\n"
+msgstr "No se recuperarán directorios puesto que la profundidad es %d (máx %d).\n"
 
-#: src/ftp.c:1334
+# Los gerundios me parecen poco apropiados para construir predicados
+# normales y corrientes como intentas en este mensaje. En su lugar, te
+# propongo la forma alternativa `se desciende' - cll
+#
+#: src/ftp.c:1511
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
-msgstr "No se desciende a `%s' ya que está excluido o no incluido.\n"
+msgstr "No se desciende hasta `%s' por estar excluido/no incluido.\n"
 
-#: src/ftp.c:1379
+#: src/ftp.c:1558
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "Rechazando `%s'.\n"
 
+# alguna idea mejor?
+# nota jjrs: En el PO para el grep 2.1 pattern está traducido como
+#   patrón por <melero@iprolink.ch> y <sanvila@unex.es>
+#
+# De hecho, `pattern' debiera traducirse como `patrón' y casi siempre os
+# saldrán las traducciones perfectas con este término. A mí, de hecho el
+# mensaje que habeis puesto me parece una traducción excelente - cll
+#
+# Algo no es *parecido* a un patrón. Algo *cumple* con un patrón. (nl)
+# Bien, pero aceptaré la matización cd C.S. Suarez de 'se ajusta a...' -Salva
+#
 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1426
+#: src/ftp.c:1605
 #, c-format
 msgid "No matches on pattern `%s'.\n"
-msgstr "No hay coincidencias con `%s'.\n"
+msgstr "No hay nada que se ajuste al patrón `%s'.\n"
 
-#: src/ftp.c:1486
+#: src/ftp.c:1670
 #, c-format
 msgid "Wrote HTML-ized index to `%s' [%ld].\n"
-msgstr "Índice en formato HTML escrito en `%s' [%ld].\n"
+msgstr "Se escribió un índice en HTML a `%s' [%ld].\n"
 
-#: src/ftp.c:1491
+#: src/ftp.c:1675
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
-msgstr "Índice en formato HTML escrito en `%s'.\n"
+msgstr "Se escribió un índice en HTML a `%s'.\n"
 
 #: src/getopt.c:454
 #, c-format
