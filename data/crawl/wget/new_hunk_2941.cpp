#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1819
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "No hay nada que se ajuste al patr�n `%s'.\n"

#: src/ftp.c:1885
#, fuzzy, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Se escribi� un �ndice en HTML a `%s' [%ld].\n"

#: src/ftp.c:1890
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Se escribi� un �ndice en HTML a `%s'.\n"

#. Still not enough randomness, most likely because neither
#. /dev/random nor EGD were available.  Resort to a simple and
#. stupid method -- seed OpenSSL's PRNG with libc PRNG.  This is
#. cryptographically weak, but people who care about strong
#. cryptography should install /dev/random (default on Linux) or
#. specify their own source of randomness anyway.
#: src/gen_sslfunc.c:109
msgid "Warning: using a weak random seed.\n"
msgstr ""

#: src/gen_sslfunc.c:166
msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
msgstr "No se pudo alimentar el PRNG de OpenSSL; deshabilitando SSL.\n"

#: src/gen_sslfunc.c:223
msgid "Warning: validation of server certificate not possible!\n"
msgstr ""

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: la opci�n `%s' es ambigua\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: la opci�n `--%s' no admite ning�n argumento\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: la opci�n `%c%s' no admite ning�n argumento\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: la opci�n `%s' requiere un argumento\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: opci�n no reconocida `--%s'\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: opci�n no reconocida `%c%s\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: opci�n ilegal -- %c\n"

#: src/getopt.c:785
#, fuzzy, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: opci�n ilegal -- %c\n"

# nota jjrs: argumento o parametro?
# mmm... argumento? ;-P -Salva
#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: la opci�n requiere un argumento -- %c\n"

#: src/getopt.c:862
#, fuzzy, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: la opci�n `%s' es ambigua\n"

#: src/getopt.c:880
#, fuzzy, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: la opci�n `--%s' no admite ning�n argumento\n"

#: src/host.c:368
#, fuzzy
msgid "Unknown host"
msgstr "Error desconocido"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:372
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:374
msgid "Unknown error"
msgstr "Error desconocido"

#: src/host.c:748
#, c-format
msgid "Resolving %s... "
msgstr "Resolviendo %s... "

#: src/host.c:792 src/host.c:839
#, c-format
msgid "failed: %s.\n"
msgstr "fall�: %s.\n"

#: src/host.c:801
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:842
#, fuzzy
msgid "failed: timed out.\n"
msgstr "fall�: %s.\n"

#: src/html-url.c:297
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: no se pudo resolver el enlace incompleto %s.\n"

#: src/http.c:349 src/http.c:1504
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Fallo escribiendo petici�n HTTP: %s.\n"

#: src/http.c:663
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#. this is fatal
#: src/http.c:1151
msgid "Failed to set up an SSL context\n"
msgstr "No se pudo configurar un contexto SSL\n"

#: src/http.c:1156
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "No se pudo descargar los certificados desde %s\n"

#: src/http.c:1159 src/http.c:1166
msgid "Trying without the specified certificate\n"
msgstr "Intent�ndolo sin el certificado especificado\n"

#: src/http.c:1163
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "No se pudo obtener la clave certificadora desde %s\n"

#: src/http.c:1382
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Reutilizando la conexi�n con %s:%hu.\n"

#: src/http.c:1434
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "Fallo escribiendo petici�n HTTP: %s.\n"

#: src/http.c:1443
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Fallo escribiendo petici�n HTTP: %s.\n"

#: src/http.c:1463
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1510
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Petici�n %s enviada, esperando respuesta... "

#: src/http.c:1521
#, fuzzy
msgid "No data received.\n"
msgstr "No se han recibido datos"

#: src/http.c:1528
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Error de lectura (%s) en las cabeceras.\n"

# En vez de `fall� la autorizaci�n' me parece m�s apropiado
# `Autorizaci�n denegada' - cll
#
#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:1595
msgid "Authorization failed.\n"
msgstr "Autorizaci�n denegada.\n"

#: src/http.c:1609
msgid "Unknown authentication scheme.\n"
msgstr "M�todo de autentificaci�n desconocido.\n"

# Piiiiii: escuchemos a los super-taca�ones :)
#
# Como no existe el verbo "malformar" en espa�ol, el participio
# `malformado' es incorrecto. El �nico t�rmino parecido a �ste que
# existe en espa�ol es `malformaci�n'. - cll
#: src/http.c:1634
msgid "Malformed status line"
msgstr "L�nea de estado mal formada"

#: src/http.c:1636
msgid "(no description)"
msgstr "(sin descripci�n)"

#: src/http.c:1700
#, c-format
msgid "Location: %s%s\n"
msgstr "Localizaci�n: %s%s\n"

#: src/http.c:1701 src/http.c:1801
msgid "unspecified"
msgstr "no especificado"

# Duda: Hmmm, ... �`siguiendo' o `siguiente'? - cll
# siguiendo - Salva
#
#: src/http.c:1702
msgid " [following]"
msgstr " [siguiendo]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1751
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
#: src/http.c:1781
msgid "Length: "
msgstr "Longitud: "

#: src/http.c:1801
msgid "ignored"
msgstr "descartado"

#: src/http.c:1943
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Atenci�n: no se admiten comodines en HTTP.\n"

