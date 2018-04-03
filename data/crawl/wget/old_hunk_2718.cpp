#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1775
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "No hay nada que se ajuste al patrón `%s'.\n"

#: src/ftp.c:1841
#, fuzzy, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Se escribió un índice en HTML a `%s' [%ld].\n"

#: src/ftp.c:1846
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Se escribió un índice en HTML a `%s'.\n"

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: la opción `%s' es ambigua\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: la opción `--%s' no admite ningún argumento\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: la opción `%c%s' no admite ningún argumento\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: la opción `%s' requiere un argumento\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: opción no reconocida `--%s'\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: opción no reconocida `%c%s\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: opción ilegal -- %c\n"

#: src/getopt.c:785
#, fuzzy, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: opción ilegal -- %c\n"

# nota jjrs: argumento o parametro?
# mmm... argumento? ;-P -Salva
#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: la opción requiere un argumento -- %c\n"

#: src/getopt.c:862
#, fuzzy, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: la opción `%s' es ambigua\n"

#: src/getopt.c:880
#, fuzzy, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: la opción `--%s' no admite ningún argumento\n"

#: src/host.c:371
#, fuzzy
msgid "Unknown host"
msgstr "Error desconocido"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:375
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:377
msgid "Unknown error"
msgstr "Error desconocido"

#: src/host.c:756
#, c-format
msgid "Resolving %s... "
msgstr "Resolviendo %s... "

#: src/host.c:800 src/host.c:829
#, c-format
msgid "failed: %s.\n"
msgstr "falló: %s.\n"

#: src/host.c:809
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:832
#, fuzzy
msgid "failed: timed out.\n"
msgstr "falló: %s.\n"

#: src/html-url.c:298
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: no se pudo resolver el enlace incompleto %s.\n"

#: src/http.c:373 src/http.c:1549
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Fallo escribiendo petición HTTP: %s.\n"

#: src/http.c:687
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1198
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1417
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Reutilizando la conexión con %s:%hu.\n"

#: src/http.c:1479
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "Fallo escribiendo petición HTTP: %s.\n"

#: src/http.c:1488
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Fallo escribiendo petición HTTP: %s.\n"

#: src/http.c:1508
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1555
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Petición %s enviada, esperando respuesta... "

#: src/http.c:1566
#, fuzzy
msgid "No data received.\n"
msgstr "No se han recibido datos"

#: src/http.c:1573
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Error de lectura (%s) en las cabeceras.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1658
msgid "Unknown authentication scheme.\n"
msgstr "Método de autentificación desconocido.\n"

# En vez de `falló la autorización' me parece más apropiado
# `Autorización denegada' - cll
#
#: src/http.c:1682
msgid "Authorization failed.\n"
msgstr "Autorización denegada.\n"

# Piiiiii: escuchemos a los super-tacañones :)
#
# Como no existe el verbo "malformar" en español, el participio
# `malformado' es incorrecto. El único término parecido a éste que
# existe en español es `malformación'. - cll
#: src/http.c:1696
msgid "Malformed status line"
msgstr "Línea de estado mal formada"

#: src/http.c:1698
msgid "(no description)"
msgstr "(sin descripción)"

#: src/http.c:1769
#, c-format
msgid "Location: %s%s\n"
msgstr "Localización: %s%s\n"

#: src/http.c:1770 src/http.c:1867
msgid "unspecified"
msgstr "no especificado"

# Duda: Hmmm, ... ¿`siguiendo' o `siguiente'? - cll
# siguiendo - Salva
#
#: src/http.c:1771
msgid " [following]"
msgstr " [siguiendo]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1817
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""
"\n"
"    El fichero ya ha sido totalmente recuperado, no hay nada que hacer.\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1847
msgid "Length: "
msgstr "Longitud: "

#: src/http.c:1867
msgid "ignored"
msgstr "descartado"

#: src/http.c:2007
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Atención: no se admiten comodines en HTTP.\n"

