msgid "%s: illegal option -- %c\n"
msgstr "%s: opción ilegal -- %c\n"

# nota jjrs: argumento o parametro?
# mmm... argumento? ;-P -Salva
#. 1003.2 specifies the format of this message.
#: src/getopt.c:602
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: la opción requiere un argumento -- %c\n"

# ¡Con la Iglesia y el Ejército hemos ido a topar! :)
#
# Lo de `host' puede dar lugar a una auténtica discusión, ... Te ruego
# por favor que, si no estás de acuerdo conmigo, te dirijas a la lista
# para discutirlo allí públicamente, ... Es importante que todos los
# miembros de Spanish GNU Translation Team actuemos de la misma manera
# y, en este caso, el convenio es emplear el término `anfitrión' para
# `host'. De hecho, yo lo he hecho en la traducción del CLisp y empieza
# a ser habitual verlo en el software comercial traducido al español, y
# si no, echa un ojo a los juegos de LucasArts, ... - cll
#
#: src/host.c:374
msgid "Host not found"
msgstr "No se ha encontrado el anfitrión"

#: src/host.c:376
msgid "Unknown error"
msgstr "Error desconocido"

#. this is fatal
#: src/http.c:554
msgid "Failed to set up an SSL context\n"
msgstr "No se pudo configurar un contexto SSL\n"

#: src/http.c:560
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "No se pudo descargar los certificados desde %s\n"

#: src/http.c:564 src/http.c:572
msgid "Trying without the specified certificate\n"
msgstr "Intentándolo sin el certificado especificado\n"

#: src/http.c:568
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "No se pudo obtener la clave certificadora desde %s\n"

#: src/http.c:662 src/http.c:1592
msgid "Unable to establish SSL connection.\n"
msgstr "No se pudo establecer la conexión SSL.\n"

#: src/http.c:670
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Reutilizando la conexión con %s:%hu.\n"

#: src/http.c:860
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Fallo escribiendo petición HTTP: %s.\n"

#: src/http.c:865
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Petición %s enviada, esperando respuesta... "

#: src/http.c:909
msgid "End of file while parsing headers.\n"
msgstr "Fin de fichero mientras se analizaban las cabeceras.\n"

#: src/http.c:919
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Error de lectura (%s) en las cabeceras.\n"

#: src/http.c:958
msgid "No data received"
msgstr "No se han recibido datos"

# Piiiiii: escuchemos a los super-tacañones :)
#
# Como no existe el verbo "malformar" en español, el participio
# `malformado' es incorrecto. El único término parecido a éste que
# existe en español es `malformación'. - cll
#: src/http.c:960
msgid "Malformed status line"
msgstr "Línea de estado mal formada"

#: src/http.c:965
msgid "(no description)"
msgstr "(sin descripción)"

# En vez de `falló la autorización' me parece más apropiado
# `Autorización denegada' - cll
#
#: src/http.c:1088
msgid "Authorization failed.\n"
msgstr "Autorización denegada.\n"

#: src/http.c:1095
msgid "Unknown authentication scheme.\n"
msgstr "Método de autentificación desconocido.\n"

#: src/http.c:1135
#, c-format
msgid "Location: %s%s\n"
msgstr "Localización: %s%s\n"

#: src/http.c:1136 src/http.c:1268
msgid "unspecified"
msgstr "no especificado"

# Duda: Hmmm, ... ¿`siguiendo' o `siguiente'? - cll
# siguiendo - Salva
#
#: src/http.c:1137
msgid " [following]"
msgstr " [siguiendo]"

#: src/http.c:1199
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    El fichero ya ha sido totalmente recuperado, no hay nada que hacer.\n\n"

#: src/http.c:1215
#, c-format
msgid ""
"\n"
"The server does not support continued downloads, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""
"\n"
"El servidor no permite continuar descargas, lo que choca con la opción `-c'.\n"
"Se rechaza truncar el fichero existente `%s'.\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1258
msgid "Length: "
msgstr "Longitud: "

#: src/http.c:1263
#, c-format
msgid " (%s to go)"
msgstr " (%s para acabar)"

#: src/http.c:1268
msgid "ignored"
msgstr "descartado"

#: src/http.c:1398
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Atención: no se admiten comodines en HTTP.\n"

# Has traducido `retrieve' como `recuperar' todo el rato, ... ¿por qué
# lo cambias ahora?. Te lo pongo de nuevo como `recuperar' - cll
# jjr no solo revisó, sino que además tradujo bastante cacho del po,
# seguramente se debe a eso - Salva
#
#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1416
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "El fichero '%s' ya existe, no se recuperará.\n"

#: src/http.c:1584
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "No se puede escribir a `%s' (%s).\n"

#: src/http.c:1601
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERROR: redirección (%d) sin localización.\n"

#: src/http.c:1629
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ERROR %d: %s.\n"

# así se entiende mejor -Salva
#: src/http.c:1641
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Falta la fecha de la última modificación -- marcas de tiempo apagadas.\n"

#: src/http.c:1649
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "La fecha de última modificación es inválida -- marca de tiempo descartada.\n"

#: src/http.c:1672
#, c-format
msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
msgstr "El fichero del servidor no es más moderno que el fichero local `%s' -- no se descargará.\n\n"

#: src/http.c:1679
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "Los tamaños no concuerdan (%ld local), recuperando.\n"

#: src/http.c:1683
msgid "Remote file is newer, retrieving.\n"
msgstr "El fichero remoto es nuevo, recuperando.\n"

#: src/http.c:1727
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
msgstr "%s (%s) - `%s' guardado [%ld/%ld]\n\n"

#: src/http.c:1773
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - Conexión cerrada en el byte %ld. "

#: src/http.c:1781
#, c-format
msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
msgstr "%s (%s) - `%s' guardado [%ld/%ld])\n\n"

#: src/http.c:1800
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - Conexión cerrada en el byte %ld/%ld. "

#: src/http.c:1811
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Error de lectura en el byte %ld (%s)."

#: src/http.c:1819
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Error de lectura en el byte %ld/%ld (%s)."

#: src/init.c:348 src/netrc.c:267
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: No se pudo leer %s (%s).\n"

#: src/init.c:366 src/init.c:372
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Error en %s en la línea %d.\n"

#: src/init.c:404
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Atención: tanto el fichero wgetrc de usuario como el del sistema apuntan a `%s'.\n"

#: src/init.c:496
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: Error: orden desconocida `%s', valor `%s'.\n"

# ¿No debiera ser la `dirección IP local'? - cll
# uups - Salva
#: src/init.c:528
#, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: %s: no se pudo convertir `%s' en una dirección IP.\n"

# Te cambio la `o' antes de `off' por `u' - cll
#
#: src/init.c:558
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: por favor, especifique on u off.\n"

# Te cambio la `o' antes de `off' por `u' - cll
#: src/init.c:602
#, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: por favor especifique siempre, on, off, o nunca.\n"

#: src/init.c:621 src/init.c:918 src/init.c:940 src/init.c:1004
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: especificación inválida `%s'.\n"

#: src/init.c:774 src/init.c:796 src/init.c:818 src/init.c:844
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: especificación inválida `%s'\n"

#: src/main.c:119
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Modo de empleo: %s [OPCIÓN]... [URL]...\n"

#: src/main.c:127
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, un recuperador por red no interactivo.\n"

# Duda: ¿por qué has insertado manualmente un `\n'? ¿es realmente
# necesario? Probablemente sí, pero yo normalmente traduzco todo en la
# misma línea, ... - cll
# Hombre, así debería quedar bastante mejor (además creo que no es la única vez
# que lo he hecho), espero que no de problemas. - Salva
#
#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:132
msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
msgstr ""
"\n"
"Los argumentos obligatorios para las opciones largas son también obligatorios\n"
"para las opciones cortas.\n"
"\n"

# Primero, simplemente pongo `wget' con `W'. Es una pijada :) pero es
# por hacerlo como en el mensaje original, ...rc' contendrá una
# orden y, sin embargo, cualquier usuario imaginará que, al ser un
# fichero con un nombre acabado en `rc', será un fichero de
# recursos. Esto es, no sólo servirá para ejecutar varias órdenes al
# inicio de Wget, sino que además, probablemente servirá para configurar
# su ejecución. Por todo ello, ¿qué tal te suena `ejecuta el fichero de
# órdenes .wgetrc'?. De momento, yo te lo pongo así, ... - cll
# bien - Salva
#
# --execute ejecuta una orden `del estilo de las incluidas en .wgetrc'
# (nl)
#
#: src/main.c:136
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
