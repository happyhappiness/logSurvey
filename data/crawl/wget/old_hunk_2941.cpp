#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1608
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "No hay nada que se ajuste al patr�n `%s'.\n"

#: src/ftp.c:1673
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "Se escribi� un �ndice en HTML a `%s' [%ld].\n"

#: src/ftp.c:1678
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Se escribi� un �ndice en HTML a `%s'.\n"

#: src/gen_sslfunc.c:109
msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
msgstr "No se pudo alimentar el PRNG de OpenSSL; deshabilitando SSL.\n"

#: src/getopt.c:454
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: la opci�n `%s' es ambigua\n"

#: src/getopt.c:478
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: la opci�n `--%s' no admite ning�n argumento\n"

#: src/getopt.c:483
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: la opci�n `%c%s' no admite ning�n argumento\n"

#: src/getopt.c:498
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: la opci�n `%s' requiere un argumento\n"

#. --option
#: src/getopt.c:528
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: opci�n no reconocida `--%s'\n"

#. +option or -option
#: src/getopt.c:532
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: opci�n no reconocida `%c%s\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:563
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: opci�n ilegal -- %c\n"

# nota jjrs: argumento o parametro?
# mmm... argumento? ;-P -Salva
#. 1003.2 specifies the format of this message.
#: src/getopt.c:602
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: la opci�n requiere un argumento -- %c\n"

#: src/host.c:271
#, c-format
msgid "Resolving %s... "
msgstr "Resolviendo %s... "

#: src/host.c:278
#, c-format
msgid "failed: %s.\n"
msgstr "fall�: %s.\n"

# �Con la Iglesia y el Ej�rcito hemos ido a topar! :)
#
# Lo de `host' puede dar lugar a una aut�ntica discusi�n, ... Te ruego
# por favor que, si no est�s de acuerdo conmigo, te dirijas a la lista
# para discutirlo all� p�blicamente, ... Es importante que todos los
# miembros de Spanish GNU Translation Team actuemos de la misma manera
# y, en este caso, el convenio es emplear el t�rmino `anfitri�n' para
# `host'. De hecho, yo lo he hecho en la traducci�n del CLisp y empieza
# a ser habitual verlo en el software comercial traducido al espa�ol, y
# si no, echa un ojo a los juegos de LucasArts, ... - cll
#
#: src/host.c:348
msgid "Host not found"
msgstr "No se ha encontrado el anfitri�n"

#: src/host.c:350
msgid "Unknown error"
msgstr "Error desconocido"

#: src/html-url.c:336
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: no se pudo resolver el enlace incompleto %s.\n"

#. this is fatal
#: src/http.c:573
msgid "Failed to set up an SSL context\n"
msgstr "No se pudo configurar un contexto SSL\n"

#: src/http.c:579
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "No se pudo descargar los certificados desde %s\n"

#: src/http.c:583 src/http.c:591
msgid "Trying without the specified certificate\n"
msgstr "Intent�ndolo sin el certificado especificado\n"

#: src/http.c:587
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "No se pudo obtener la clave certificadora desde %s\n"

#: src/http.c:657 src/http.c:1620
msgid "Unable to establish SSL connection.\n"
msgstr "No se pudo establecer la conexi�n SSL.\n"

#: src/http.c:666
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "Reutilizando la conexi�n con %s:%hu.\n"

#: src/http.c:868
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Fallo escribiendo petici�n HTTP: %s.\n"

#: src/http.c:873
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "Petici�n %s enviada, esperando respuesta... "

#: src/http.c:917
msgid "End of file while parsing headers.\n"
msgstr "Fin de fichero mientras se analizaban las cabeceras.\n"

#: src/http.c:927
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Error de lectura (%s) en las cabeceras.\n"

#: src/http.c:962
msgid "No data received"
msgstr "No se han recibido datos"

# Piiiiii: escuchemos a los super-taca�ones :)
#
# Como no existe el verbo "malformar" en espa�ol, el participio
# `malformado' es incorrecto. El �nico t�rmino parecido a �ste que
# existe en espa�ol es `malformaci�n'. - cll
#: src/http.c:964
msgid "Malformed status line"
msgstr "L�nea de estado mal formada"

#: src/http.c:969
msgid "(no description)"
msgstr "(sin descripci�n)"

# En vez de `fall� la autorizaci�n' me parece m�s apropiado
# `Autorizaci�n denegada' - cll
#
#: src/http.c:1101
msgid "Authorization failed.\n"
msgstr "Autorizaci�n denegada.\n"

#: src/http.c:1108
msgid "Unknown authentication scheme.\n"
msgstr "M�todo de autentificaci�n desconocido.\n"

#: src/http.c:1148
#, c-format
msgid "Location: %s%s\n"
msgstr "Localizaci�n: %s%s\n"

#: src/http.c:1149 src/http.c:1282
msgid "unspecified"
msgstr "no especificado"

# Duda: Hmmm, ... �`siguiendo' o `siguiente'? - cll
# siguiendo - Salva
#
#: src/http.c:1150
msgid " [following]"
msgstr " [siguiendo]"

#: src/http.c:1213
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n    El fichero ya ha sido totalmente recuperado, no hay nada que hacer.\n\n"

#: src/http.c:1229
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""
"\n"
"No se pudo continuar la descarga de este fichero, lo que choca con `-c'.\n"
"Se rechaza truncar el fichero existente `%s'.\n"
"\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1272
msgid "Length: "
msgstr "Longitud: "

#: src/http.c:1277
#, c-format
msgid " (%s to go)"
msgstr " (%s para acabar)"

#: src/http.c:1282
msgid "ignored"
msgstr "descartado"

#: src/http.c:1413
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "Atenci�n: no se admiten comodines en HTTP.\n"

