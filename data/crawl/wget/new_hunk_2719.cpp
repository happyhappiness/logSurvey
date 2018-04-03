# nota jjrs: stat es una función de C que obtiene datos de un archivo
#   y en esta parte solamente lo usa para checar si existe el archivo
#   pero el wget no utiliza esta función.
#: src/netrc.c:470
#, c-format
msgid "%s: cannot stat %s: %s\n"
msgstr "%s: no se pudo ejecutar `stat' sobre %s: %s\n"

# Como en otros mensajes anteriores te recomiendo que emplees el término
# `omitir' en vez de `saltar' para `skip' - clldigits in the skipped amount in K.
#. Align the [ skipping ... ] line with the dots.  To do
#. that, insert the number of spaces equal to the number of
#. digits in the skipped amount in K.
#: src/progress.c:224
#, c-format
msgid "\n%*s[ skipping %dK ]"
msgstr "\n%*s[ omitiendo %dK ]"

#: src/progress.c:391
#, c-format
msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
msgstr "El estilo de la pantalla '%s' no es válido; se utilizará el predeterminado.\n"

#: src/recur.c:350
#, c-format
msgid "Removing %s since it should be rejected.\n"
msgstr "Eliminando %s puesto que debería ser rechazado.\n"

#: src/recur.c:935
#, c-format
msgid "Converted %d files in %.2f seconds.\n"
msgstr "%d ficheros convertidos en %.2f segundos.\n"

#: src/res.c:540
msgid "Loading robots.txt; please ignore errors.\n"
msgstr "Cargando robots.txt; por favor ignore los errores.\n"

# `host' es traducido como `anfitrión'. Debes evitar los términos en
# inglés tanto como puedas, ... - cll
#
#: src/retr.c:363
msgid "Could not find proxy host.\n"
msgstr "No se pudo encontrar el anfitrión de proxy.\n"

#: src/retr.c:375
#, c-format
msgid "Error parsing proxy URL %s: %s.\n"
msgstr "Error parseando la URL del proxy `%s': %s\n"

#: src/retr.c:384
#, c-format
msgid "Error in proxy URL %s: Must be HTTP.\n"
msgstr "Error en la URL del proxy %s: debe ser HTTP.\n"

#: src/retr.c:476
#, c-format
msgid "%d redirections exceeded.\n"
msgstr "Sobrepasadas las %d redirecciones.\n"

#: src/retr.c:491
#, c-format
msgid "%s: Redirection cycle detected.\n"
msgstr "%s: redirección cíclica detectada.\n"

#: src/retr.c:608
msgid "Giving up.\n\n"
msgstr "Abandonando.\n\n"

#: src/retr.c:608
msgid "Retrying.\n\n"
msgstr "Reintentando.\n\n"

#: src/url.c:1875
#, c-format
msgid "Converting %s... "
msgstr "Convirtiendo %s... "

#: src/url.c:1888
msgid "nothing to do.\n"
msgstr "no hay nada que hacer.\n"

#: src/url.c:1896 src/url.c:1920
#, c-format
msgid "Cannot convert links in %s: %s\n"
msgstr "No se han podido convertir los enlaces en %s: %s\n"

#: src/url.c:1911
#, c-format
msgid "Unable to delete `%s': %s\n"
msgstr "No se ha borrar `%s': %s\n"

#: src/url.c:2117
#, c-format
msgid "Cannot back up %s as %s: %s\n"
msgstr "No se pudo hacer una copia de seguridad de %s como %s: %s\n"

#: src/utils.c:90
#, c-format
msgid "%s: %s: Not enough memory.\n"
msgstr "%s: %s: no hay suficiente memoria.\n"

# Lo mismo que antes, ... `background' es `segundo plano' - cll
msgid "Continuing in background, pid %d.\n"
msgstr "Continuando en segundo plano, pid %d.\n"

#: src/utils.c:499
#, c-format
msgid "Failed to unlink symlink `%s': %s\n"
msgstr "No se ha podido deshacer el enlace simbólico `%s': %s\n"
