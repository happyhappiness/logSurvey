 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1608
+#: src/ftp.c:1819
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "No hay nada que se ajuste al patrón `%s'.\n"
 
-#: src/ftp.c:1673
-#, c-format
-msgid "Wrote HTML-ized index to `%s' [%ld].\n"
+#: src/ftp.c:1885
+#, fuzzy, c-format
+msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "Se escribió un índice en HTML a `%s' [%ld].\n"
 
-#: src/ftp.c:1678
+#: src/ftp.c:1890
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "Se escribió un índice en HTML a `%s'.\n"
 
+#. Still not enough randomness, most likely because neither
+#. /dev/random nor EGD were available.  Resort to a simple and
+#. stupid method -- seed OpenSSL's PRNG with libc PRNG.  This is
+#. cryptographically weak, but people who care about strong
+#. cryptography should install /dev/random (default on Linux) or
+#. specify their own source of randomness anyway.
 #: src/gen_sslfunc.c:109
+msgid "Warning: using a weak random seed.\n"
+msgstr ""
+
+#: src/gen_sslfunc.c:166
 msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
 msgstr "No se pudo alimentar el PRNG de OpenSSL; deshabilitando SSL.\n"
 
-#: src/getopt.c:454
+#: src/gen_sslfunc.c:223
+msgid "Warning: validation of server certificate not possible!\n"
+msgstr ""
+
+#: src/getopt.c:675
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
 msgstr "%s: la opción `%s' es ambigua\n"
 
-#: src/getopt.c:478
+#: src/getopt.c:700
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
 msgstr "%s: la opción `--%s' no admite ningún argumento\n"
 
-#: src/getopt.c:483
+#: src/getopt.c:705
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
 msgstr "%s: la opción `%c%s' no admite ningún argumento\n"
 
-#: src/getopt.c:498
+#: src/getopt.c:723 src/getopt.c:896
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
 msgstr "%s: la opción `%s' requiere un argumento\n"
 
 #. --option
-#: src/getopt.c:528
+#: src/getopt.c:752
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
 msgstr "%s: opción no reconocida `--%s'\n"
 
 #. +option or -option
-#: src/getopt.c:532
+#: src/getopt.c:756
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
 msgstr "%s: opción no reconocida `%c%s\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:563
+#: src/getopt.c:782
 #, c-format
 msgid "%s: illegal option -- %c\n"
 msgstr "%s: opción ilegal -- %c\n"
 
+#: src/getopt.c:785
+#, fuzzy, c-format
+msgid "%s: invalid option -- %c\n"
+msgstr "%s: opción ilegal -- %c\n"
+
 # nota jjrs: argumento o parametro?
 # mmm... argumento? ;-P -Salva
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:602
+#: src/getopt.c:815 src/getopt.c:945
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: la opción requiere un argumento -- %c\n"
 
-#: src/host.c:271
+#: src/getopt.c:862
+#, fuzzy, c-format
+msgid "%s: option `-W %s' is ambiguous\n"
+msgstr "%s: la opción `%s' es ambigua\n"
+
+#: src/getopt.c:880
+#, fuzzy, c-format
+msgid "%s: option `-W %s' doesn't allow an argument\n"
+msgstr "%s: la opción `--%s' no admite ningún argumento\n"
+
+#: src/host.c:368
+#, fuzzy
+msgid "Unknown host"
+msgstr "Error desconocido"
+
+#. Message modeled after what gai_strerror returns in similar
+#. circumstances.
+#: src/host.c:372
+msgid "Temporary failure in name resolution"
+msgstr ""
+
+#: src/host.c:374
+msgid "Unknown error"
+msgstr "Error desconocido"
+
+#: src/host.c:748
 #, c-format
 msgid "Resolving %s... "
 msgstr "Resolviendo %s... "
 
-#: src/host.c:278
+#: src/host.c:792 src/host.c:839
 #, c-format
 msgid "failed: %s.\n"
 msgstr "falló: %s.\n"
 
-# ¡Con la Iglesia y el Ejército hemos ido a topar! :)
-#
-# Lo de `host' puede dar lugar a una auténtica discusión, ... Te ruego
-# por favor que, si no estás de acuerdo conmigo, te dirijas a la lista
-# para discutirlo allí públicamente, ... Es importante que todos los
-# miembros de Spanish GNU Translation Team actuemos de la misma manera
-# y, en este caso, el convenio es emplear el término `anfitrión' para
-# `host'. De hecho, yo lo he hecho en la traducción del CLisp y empieza
-# a ser habitual verlo en el software comercial traducido al español, y
-# si no, echa un ojo a los juegos de LucasArts, ... - cll
-#
-#: src/host.c:348
-msgid "Host not found"
-msgstr "No se ha encontrado el anfitrión"
+#: src/host.c:801
+msgid "failed: No IPv4/IPv6 addresses for host.\n"
+msgstr ""
 
-#: src/host.c:350
-msgid "Unknown error"
-msgstr "Error desconocido"
+#: src/host.c:842
+#, fuzzy
+msgid "failed: timed out.\n"
+msgstr "falló: %s.\n"
 
-#: src/html-url.c:336
+#: src/html-url.c:297
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: no se pudo resolver el enlace incompleto %s.\n"
 
+#: src/http.c:349 src/http.c:1504
+#, c-format
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "Fallo escribiendo petición HTTP: %s.\n"
+
+#: src/http.c:663
+msgid "No headers, assuming HTTP/0.9"
+msgstr ""
+
 #. this is fatal
-#: src/http.c:573
+#: src/http.c:1151
 msgid "Failed to set up an SSL context\n"
 msgstr "No se pudo configurar un contexto SSL\n"
 
-#: src/http.c:579
+#: src/http.c:1156
 #, c-format
 msgid "Failed to load certificates from %s\n"
 msgstr "No se pudo descargar los certificados desde %s\n"
 
-#: src/http.c:583 src/http.c:591
+#: src/http.c:1159 src/http.c:1166
 msgid "Trying without the specified certificate\n"
 msgstr "Intentándolo sin el certificado especificado\n"
 
-#: src/http.c:587
+#: src/http.c:1163
 #, c-format
 msgid "Failed to get certificate key from %s\n"
 msgstr "No se pudo obtener la clave certificadora desde %s\n"
 
-#: src/http.c:657 src/http.c:1620
-msgid "Unable to establish SSL connection.\n"
-msgstr "No se pudo establecer la conexión SSL.\n"
-
-#: src/http.c:666
-#, c-format
-msgid "Reusing connection to %s:%hu.\n"
+#: src/http.c:1382
+#, fuzzy, c-format
+msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Reutilizando la conexión con %s:%hu.\n"
 
-#: src/http.c:868
-#, c-format
-msgid "Failed writing HTTP request: %s.\n"
+#: src/http.c:1434
+#, fuzzy, c-format
+msgid "Failed writing to proxy: %s.\n"
+msgstr "Fallo escribiendo petición HTTP: %s.\n"
+
+#: src/http.c:1443
+#, fuzzy, c-format
+msgid "Failed reading proxy response: %s\n"
 msgstr "Fallo escribiendo petición HTTP: %s.\n"
 
-#: src/http.c:873
+#: src/http.c:1463
+#, c-format
+msgid "Proxy tunneling failed: %s"
+msgstr ""
+
+#: src/http.c:1510
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "Petición %s enviada, esperando respuesta... "
 
-#: src/http.c:917
-msgid "End of file while parsing headers.\n"
-msgstr "Fin de fichero mientras se analizaban las cabeceras.\n"
+#: src/http.c:1521
+#, fuzzy
+msgid "No data received.\n"
+msgstr "No se han recibido datos"
 
-#: src/http.c:927
+#: src/http.c:1528
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Error de lectura (%s) en las cabeceras.\n"
 
-#: src/http.c:962
-msgid "No data received"
-msgstr "No se han recibido datos"
+# En vez de `falló la autorización' me parece más apropiado
+# `Autorización denegada' - cll
+#
+#. If we have tried it already, then there is not point
+#. retrying it.
+#: src/http.c:1595
+msgid "Authorization failed.\n"
+msgstr "Autorización denegada.\n"
+
+#: src/http.c:1609
+msgid "Unknown authentication scheme.\n"
+msgstr "Método de autentificación desconocido.\n"
 
 # Piiiiii: escuchemos a los super-tacañones :)
 #
 # Como no existe el verbo "malformar" en español, el participio
 # `malformado' es incorrecto. El único término parecido a éste que
 # existe en español es `malformación'. - cll
-#: src/http.c:964
+#: src/http.c:1634
 msgid "Malformed status line"
 msgstr "Línea de estado mal formada"
 
-#: src/http.c:969
+#: src/http.c:1636
 msgid "(no description)"
 msgstr "(sin descripción)"
 
-# En vez de `falló la autorización' me parece más apropiado
-# `Autorización denegada' - cll
-#
-#: src/http.c:1101
-msgid "Authorization failed.\n"
-msgstr "Autorización denegada.\n"
-
-#: src/http.c:1108
-msgid "Unknown authentication scheme.\n"
-msgstr "Método de autentificación desconocido.\n"
-
-#: src/http.c:1148
+#: src/http.c:1700
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Localización: %s%s\n"
 
-#: src/http.c:1149 src/http.c:1282
+#: src/http.c:1701 src/http.c:1801
 msgid "unspecified"
 msgstr "no especificado"
 
 # Duda: Hmmm, ... ¿`siguiendo' o `siguiente'? - cll
 # siguiendo - Salva
 #
-#: src/http.c:1150
+#: src/http.c:1702
 msgid " [following]"
 msgstr " [siguiendo]"
 
-#: src/http.c:1213
-msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
-msgstr "\n    El fichero ya ha sido totalmente recuperado, no hay nada que hacer.\n\n"
-
-#: src/http.c:1229
-#, c-format
+#. If `-c' is in use and the file has been fully downloaded (or
+#. the remote file has shrunk), Wget effectively requests bytes
+#. after the end of file and the server response with 416.
+#: src/http.c:1751
 msgid ""
 "\n"
-"Continued download failed on this file, which conflicts with `-c'.\n"
-"Refusing to truncate existing file `%s'.\n"
+"    The file is already fully retrieved; nothing to do.\n"
 "\n"
 msgstr ""
 "\n"
-"No se pudo continuar la descarga de este fichero, lo que choca con `-c'.\n"
-"Se rechaza truncar el fichero existente `%s'.\n"
+"    El fichero ya ha sido totalmente recuperado, no hay nada que hacer.\n"
 "\n"
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:1272
+#: src/http.c:1781
 msgid "Length: "
 msgstr "Longitud: "
 
-#: src/http.c:1277
-#, c-format
-msgid " (%s to go)"
-msgstr " (%s para acabar)"
-
-#: src/http.c:1282
+#: src/http.c:1801
 msgid "ignored"
 msgstr "descartado"
 
-#: src/http.c:1413
+#: src/http.c:1943
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "Atención: no se admiten comodines en HTTP.\n"
 
