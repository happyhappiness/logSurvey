# Algo no es *parecido* a un patrón. Algo *cumple* con un patrón. (nl)
# Bien, pero aceptaré la matización cd C.S. Suarez de 'se ajusta a...' -Salva
#
#: src/ftp.c:1814
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "No hay nada que se ajuste al patrón `%s'.\n"

#: src/ftp.c:1880
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "Se escribió un índice en HTML a `%s' [%ld].\n"

#: src/ftp.c:1885
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
msgstr "Se escribió un índice en HTML a `%s'.\n"

#: src/host.c:348
#, fuzzy
msgid "Unknown host"
msgstr "Error desconocido"

#: src/host.c:352
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:354
msgid "Unknown error"
msgstr "Error desconocido"

#: src/host.c:715
#, c-format
msgid "Resolving %s... "
msgstr "Resolviendo %s... "

#: src/host.c:763
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:786
#, fuzzy
msgid "failed: timed out.\n"
msgstr "falló: %s.\n"

#: src/html-url.c:289
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: no se pudo resolver el enlace incompleto %s.\n"

#: src/html-url.c:696
#, fuzzy, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: especificación inválida `%s'\n"

#: src/http.c:368
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Fallo escribiendo petición HTTP: %s.\n"

#: src/http.c:745
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1430
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1548
#, c-format
msgid "POST data file %s missing: %s\n"
msgstr ""

#: src/http.c:1632
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Reutilizando la conexión con %s:%hu.\n"

#: src/http.c:1701
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Fallo escribiendo petición HTTP: %s.\n"

#: src/http.c:1721
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1766
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Petición %s enviada, esperando respuesta... "

#: src/http.c:1777
#, fuzzy
msgid "No data received.\n"
msgstr "No se han recibido datos"

#: src/http.c:1784
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Error de lectura (%s) en las cabeceras.\n"

# `no recuperando' no me suena muy español, te propongo la alternativa
# más "humanizada", `no se recupera' - cll
#
#: src/http.c:1831 src/http.c:2385
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
"\n"
msgstr "El fichero `%s' ya está ahí, no se recupera.\n"

#: src/http.c:1985
msgid "Unknown authentication scheme.\n"
msgstr "Método de autentificación desconocido.\n"

# En vez de `falló la autorización' me parece más apropiado
# `Autorización denegada' - cll
#
#: src/http.c:2016
msgid "Authorization failed.\n"
msgstr "Autorización denegada.\n"

# Piiiiii: escuchemos a los super-tacañones :)
#
# Como no existe el verbo "malformar" en español, el participio
# `malformado' es incorrecto. El único término parecido a éste que
# existe en español es `malformación'. - cll
#: src/http.c:2030
msgid "Malformed status line"
msgstr "Línea de estado mal formada"

#: src/http.c:2032
msgid "(no description)"
msgstr "(sin descripción)"

#: src/http.c:2098
#, c-format
msgid "Location: %s%s\n"
msgstr "Localización: %s%s\n"

#: src/http.c:2099 src/http.c:2209
msgid "unspecified"
msgstr "no especificado"

# Duda: Hmmm, ... ¿`siguiendo' o `siguiente'? - cll
# siguiendo - Salva
#
#: src/http.c:2100
msgid " [following]"
msgstr " [siguiendo]"

#: src/http.c:2156
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
