msgid "%s: illegal option -- %c\n"
msgstr "%s: opción ilegal -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:602
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: la opción requiere un argumento -- %c\n"

#: src/host.c:430
#, c-format
msgid "%s: Cannot determine user-id.\n"
msgstr "%s: No se puede determinar el usuario.\n"

#: src/host.c:442
#, c-format
msgid "%s: Warning: uname failed: %s\n"
msgstr "%s: Aviso: falló uname: %s\n"

#: src/host.c:454
#, c-format
msgid "%s: Warning: gethostname failed\n"
msgstr "%s: Aviso: falló gethostname\n"

#: src/host.c:482
#, c-format
msgid "%s: Warning: cannot determine local IP address.\n"
msgstr "%s: Aviso: no se puede determinar la dirección IP local.\n"

#: src/host.c:496
#, c-format
msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
msgstr ""
"%s: Aviso: no se puede hacer la búsqueda inversa de la dirección IP local.\n"

#. This gets ticked pretty often.  Karl Berry reports
#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:509
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr "%s: Aviso: ¡La búsqueda reversa de la dirección local no dio un FQDN!\n"

#: src/host.c:537
msgid "Host not found"
msgstr "Nombre de máquina no encontrado"

#: src/host.c:539
msgid "Unknown error"
msgstr "Error desconocido"

#: src/html.c:615 src/html.c:617
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "Índice de /%s en %s:%d"

#: src/html.c:639
msgid "time unknown       "
msgstr "tiempo desconocido "

#: src/html.c:643
msgid "File        "
msgstr "Archivo     "

#: src/html.c:646
msgid "Directory   "
msgstr "Directorio  "

#: src/html.c:649
msgid "Link        "
msgstr "Enlace      "

#: src/html.c:652
msgid "Not sure    "
msgstr "No es seguro"

#: src/html.c:670
#, c-format
msgid " (%s bytes)"
msgstr ""

#: src/http.c:515
msgid "Failed writing HTTP request.\n"
msgstr "Falló la escritura del requerimiento HTTP.\n"

#: src/http.c:519
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Requerimiento %s enviado, esperando respuesta... "

#: src/http.c:558
msgid "End of file while parsing headers.\n"
msgstr "Final de archivo mientras se analizaban las cabeceras.\n"

#: src/http.c:569
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Error de lectura (%s) en las cabeceras.\n"

#: src/http.c:609
msgid "No data received"
msgstr "No se recibieron datos"

#: src/http.c:611
msgid "Malformed status line"
msgstr "Línea de status mal formada"

#: src/http.c:616
msgid "(no description)"
msgstr "(sin descripción)"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:700
msgid "Authorization failed.\n"
msgstr "Falló autorización.\n"

#: src/http.c:707
msgid "Unknown authentication scheme.\n"
msgstr "Esquema de autentificación desconocido.\n"

#: src/http.c:790
#, c-format
msgid "Location: %s%s\n"
msgstr "Ubicación: %s%s\n"

#: src/http.c:791 src/http.c:816
msgid "unspecified"
msgstr "no especificado"

#: src/http.c:792
msgid " [following]"
msgstr " [siguiendo]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:806
msgid "Length: "
msgstr "Tamaño: "

#: src/http.c:811
#, c-format
msgid " (%s to go)"
msgstr " (faltan %s)"

#: src/http.c:816
msgid "ignored"
msgstr "se ignora"

#: src/http.c:917
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Aviso: no se soportan comodines en HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:938
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "El archivo `%s' ya está, no se trae.\n"

#: src/http.c:1088
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "No se pudo escribir a `%s' (%s).\n"

#: src/http.c:1099
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "ERROR: Redirección (%d) sin `location'.\n"

#: src/http.c:1124
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr ""

#: src/http.c:1137
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Falta cabecera Last-modified -- no se usará time-stamps.\n"

#: src/http.c:1145
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Cabecera Last-modified inválido -- se ignora el time-stamp.\n"

#: src/http.c:1180
msgid "Remote file is newer, retrieving.\n"
msgstr "El archivo remoto es más nuevo, se lo trae.\n"

#: src/http.c:1225
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' guardado [%ld/%ld]\n"
"\n"

#: src/http.c:1273
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - La conexión se cerró en el byte %ld. "

#: src/http.c:1281
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""
"%s (%s) - %s' guardado [%ld/%ld])\n"
"\n"

#: src/http.c:1301
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - La conexión se cerró en el byte %ld/%ld. "

#: src/http.c:1312
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - Error de lectura en el byte %ld (%s)."

#: src/http.c:1320
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - Error de lectura en el byte %ld/%ld (%s). "

#: src/init.c:329 src/netrc.c:260
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: No se puede leer %s (%s).\n"

#: src/init.c:347 src/init.c:353
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: Error en %s, línea %d.\n"

#: src/init.c:384
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: Aviso: El wgetrc de usuario y el de sistema apuntan a `%s'.\n"

#: src/init.c:476
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: BUG: comando desconocido `%s', valor `%s'.\n"

#: src/init.c:497
#, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: %s: No se puede convertir `%s' a una dirección IP.\n"

#: src/init.c:525
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: Especifique `on' u `off'.\n"

#: src/init.c:569
#, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: Por favor especifique `always', `on', `off' o `never'.\n"

#: src/init.c:588 src/init.c:845 src/init.c:867 src/init.c:931
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: Especificación `%s' inválida.\n"

#: src/init.c:701 src/init.c:723 src/init.c:745 src/init.c:771
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: Especificación `%s' inválida.\n"

#: src/main.c:107
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "Uso: %s [OPCIÓN]... [URL]...\n"

#: src/main.c:115
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, un recuperador de datos de red no interactivo.\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:120
msgid ""
"\n"
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"Los argumentos obligatorios para las opciones largas también lo son para\n"
"las cortas.\n"
"\n"

#: src/main.c:123
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
