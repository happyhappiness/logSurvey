"Execution continued in background.\n"
"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
msgstr ""
"\n"
"CTRL+Break recibido, redirigiendo la salida a `%s'.\n"
"La ejecución continúa en segundo plano.\n"
"Puede parar Wget presionando CTRL+ALT+Supr.\n"

# Lo mismo que antes, ... `background' es `segundo plano' - cll
#
#. parent, no error
#: src/mswindows.c:106 src/utils.c:457
msgid "Continuing in background.\n"
msgstr "Continuando en segundo plano.\n"

#: src/mswindows.c:108 src/utils.c:459
#, c-format
msgid "Output will be written to `%s'.\n"
msgstr "La salida será escrita en `%s'.\n"

# Eso de `comenzando ...' ha sido demasiado literal, ... ;) ¿Qué te
# parece `iniciando'? Es lo mismo pero es un término más común en
# informática, ... - cll
#
#: src/mswindows.c:188
#, c-format
msgid "Starting WinHelp %s\n"
msgstr "Iniciando WinHelp %s\n"

# he imitado a Iñaki Gonzalez en el error.es.po, donde no traduce socket.
#
# Si, este es uno de esos casos que se dan por imposibles ya, ... Todo
# el mundo utilizamos `socket' "asinque" nada, ... - cll
#
#: src/mswindows.c:215 src/mswindows.c:222
#, c-format
msgid "%s: Couldn't find usable socket driver.\n"
msgstr "%s: No se ha podido encontrar un controlador de `socket' utilizable\n"

# Simplemente, te cambio un par de palabras de sitio, a ver si así te
# gusta más, ... - cll
#
#: src/netrc.c:367
#, c-format
msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
msgstr "%s: %s:%d: atención: no aparece ningún nombre de máquina antes del símbolo \"%s\"\n"

# la traducción de token es de diccionario, pero me parece correcta.
# nota jjrs: Aquí se usa en el contexto de un analizador léxico (parser)
#
# Asi es, jjrs tiene razón, ... por eso, `token' es habitualmente
# traducido en informática como `símbolo'. La traducción, por lo tanto,
# es correcta - cll
#
#: src/netrc.c:398
#, c-format
msgid "%s: %s:%d: unknown token \"%s\"\n"
msgstr "%s: %s:%d: símbolo desconocido \"%s\"\n"

#: src/netrc.c:462
#, c-format
msgid "Usage: %s NETRC [HOSTNAME]\n"
msgstr "Modo de empleo: %s NETRC [NOMBREDEMÁQUINA]\n"

# no tengo ni idea de a que se refiere stat en este caso :-/
# nota jjrs: stat es una función de C que obtiene datos de un archivo
#   y en esta parte solamente lo usa para checar si existe el archivo
#   pero el wget no utiliza esta función.
#: src/netrc.c:472
#, c-format
msgid "%s: cannot stat %s: %s\n"
msgstr "%s: no se pudo ejecutar `stat' sobre %s: %s\n"

#: src/recur.c:484
#, c-format
msgid "Removing %s since it should be rejected.\n"
msgstr "Eliminando %s puesto que debería ser rechazado.\n"

#: src/recur.c:679
msgid "Loading robots.txt; please ignore errors.\n"
msgstr "Cargando robots.txt; por favor ignore los errores.\n"

# Como en otros mensajes anteriores te recomiendo que emplees el término
# `omitir' en vez de `saltar' para `skip' - cll
#
#: src/retr.c:227
#, c-format
msgid "\n          [ skipping %dK ]"
msgstr "\n          [ omitiendo %dK ]"

# `host' es traducido como `anfitrión'. Debes evitar los términos en
# inglés tanto como puedas, ... - cll
#
#: src/retr.c:373
msgid "Could not find proxy host.\n"
msgstr "No se pudo encontrar el anfitrión de proxy.\n"

#: src/retr.c:387
#, c-format
msgid "Proxy %s: Must be HTTP.\n"
msgstr "Proxy %s: debe ser HTTP.\n"

#: src/retr.c:481
#, c-format
msgid "%s: Redirection cycle detected.\n"
msgstr "%s: redirección cíclica detectada.\n"

#: src/retr.c:587
msgid "Giving up.\n\n"
msgstr "Dejándolo.\n\n"

#: src/retr.c:587
msgid "Retrying.\n\n"
msgstr "Reintentando.\n\n"

#: src/url.c:1329
#, c-format
msgid "Converting %s... "
msgstr "Convirtiendo %s... "

#: src/url.c:1342
msgid "nothing to do.\n"
msgstr "no hay nada que hacer.\n"

#: src/url.c:1350 src/url.c:1374
#, c-format
msgid "Cannot convert links in %s: %s\n"
msgstr "No se han podido convertir los enlaces en %s: %s\n"

#: src/url.c:1365
#, c-format
msgid "Unable to delete `%s': %s\n"
msgstr "No se ha borrar `%s': %s\n"

#: src/url.c:1555
#, c-format
msgid "Cannot back up %s as %s: %s\n"
msgstr "No se pudo hacer una copia de seguridad de %s como %s: %s\n"

#: src/utils.c:93
#, c-format
msgid "%s: %s: Not enough memory.\n"
msgstr "%s: %s: no hay suficiente memoria.\n"

#: src/utils.c:416
msgid "Unknown/unsupported protocol"
msgstr "Protocolo desconocido/no soportado"

#: src/utils.c:419
msgid "Invalid port specification"
msgstr "El puerto especificado no es válido"

# `anfitrión' en vez de `host' - cll
#
#: src/utils.c:422
msgid "Invalid host name"
msgstr "El nombre del anfitrión no es válido"

#: src/utils.c:619
#, c-format
msgid "Failed to unlink symlink `%s': %s\n"
msgstr "No se ha podido deshacer el enlace simbólico `%s': %s\n"
