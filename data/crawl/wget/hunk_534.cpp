 # Algo no es *parecido* a un patrón. Algo *cumple* con un patrón. (nl)
 # Bien, pero aceptaré la matización cd C.S. Suarez de 'se ajusta a...' -Salva
 #
-#: src/ftp.c:1814
+#: src/ftp.c:2073
 #, fuzzy, c-format
 msgid "No matches on pattern %s.\n"
 msgstr "No hay nada que se ajuste al patrón `%s'.\n"
 
-#: src/ftp.c:1880
+#: src/ftp.c:2144
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s [%s].\n"
 msgstr "Se escribió un índice en HTML a `%s' [%ld].\n"
 
-#: src/ftp.c:1885
+#: src/ftp.c:2149
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s.\n"
 msgstr "Se escribió un índice en HTML a `%s'.\n"
 
-#: src/host.c:348
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "ERROR"
+msgstr ""
+
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "WARNING"
+msgstr ""
+
+#: src/gnutls.c:225 src/openssl.c:504
+#, c-format
+msgid "%s: No certificate presented by %s.\n"
+msgstr ""
+
+#: src/gnutls.c:233
+#, c-format
+msgid "%s: The certificate of %s is not trusted.\n"
+msgstr ""
+
+#: src/gnutls.c:239
+#, c-format
+msgid "%s: The certificate of %s hasn't got a known issuer.\n"
+msgstr ""
+
+#: src/gnutls.c:245
+#, c-format
+msgid "%s: The certificate of %s has been revoked.\n"
+msgstr ""
+
+#: src/gnutls.c:259
+#, c-format
+msgid "Error initializing X509 certificate: %s\n"
+msgstr ""
+
+#: src/gnutls.c:268
+msgid "No certificate found\n"
+msgstr ""
+
+#: src/gnutls.c:275
+#, fuzzy, c-format
+msgid "Error parsing certificate: %s\n"
+msgstr "Error parseando la URL del proxy `%s': %s\n"
+
+#: src/gnutls.c:282
+msgid "The certificate has not yet been activated\n"
+msgstr ""
+
+#: src/gnutls.c:287
+msgid "The certificate has expired\n"
+msgstr ""
+
+#: src/gnutls.c:293
+#, c-format
+msgid "The certificate's owner does not match hostname '%s'\n"
+msgstr ""
+
+#: src/host.c:358
 #, fuzzy
 msgid "Unknown host"
 msgstr "Error desconocido"
 
-#: src/host.c:352
+#: src/host.c:362
 msgid "Temporary failure in name resolution"
 msgstr ""
 
-#: src/host.c:354
+#: src/host.c:364
 msgid "Unknown error"
 msgstr "Error desconocido"
 
-#: src/host.c:715
+#: src/host.c:737
 #, c-format
 msgid "Resolving %s... "
 msgstr "Resolviendo %s... "
 
-#: src/host.c:763
+#: src/host.c:789
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
 msgstr ""
 
-#: src/host.c:786
+#: src/host.c:812
 #, fuzzy
 msgid "failed: timed out.\n"
 msgstr "falló: %s.\n"
 
-#: src/html-url.c:289
+#: src/html-url.c:286
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: no se pudo resolver el enlace incompleto %s.\n"
 
-#: src/html-url.c:696
+#: src/html-url.c:762
 #, fuzzy, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: especificación inválida `%s'\n"
 
-#: src/http.c:368
+#: src/http.c:377
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Fallo escribiendo petición HTTP: %s.\n"
 
-#: src/http.c:745
+#: src/http.c:754
 msgid "No headers, assuming HTTP/0.9"
 msgstr ""
 
-#: src/http.c:1430
+#: src/http.c:1456
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr ""
 
-#: src/http.c:1548
+#: src/http.c:1576
 #, c-format
 msgid "POST data file %s missing: %s\n"
 msgstr ""
 
-#: src/http.c:1632
+#: src/http.c:1660
 #, fuzzy, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Reutilizando la conexión con %s:%hu.\n"
 
-#: src/http.c:1701
+#: src/http.c:1729
 #, fuzzy, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "Fallo escribiendo petición HTTP: %s.\n"
 
-#: src/http.c:1721
+#: src/http.c:1750
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr ""
 
-#: src/http.c:1766
+#: src/http.c:1795
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "Petición %s enviada, esperando respuesta... "
 
-#: src/http.c:1777
+#: src/http.c:1806
 #, fuzzy
 msgid "No data received.\n"
 msgstr "No se han recibido datos"
 
-#: src/http.c:1784
+#: src/http.c:1813
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Error de lectura (%s) en las cabeceras.\n"
 
-# `no recuperando' no me suena muy español, te propongo la alternativa
-# más "humanizada", `no se recupera' - cll
-#
-#: src/http.c:1831 src/http.c:2385
-#, fuzzy, c-format
-msgid ""
-"File %s already there; not retrieving.\n"
-"\n"
-msgstr "El fichero `%s' ya está ahí, no se recupera.\n"
-
-#: src/http.c:1985
+#: src/http.c:1884
 msgid "Unknown authentication scheme.\n"
 msgstr "Método de autentificación desconocido.\n"
 
 # En vez de `falló la autorización' me parece más apropiado
 # `Autorización denegada' - cll
 #
-#: src/http.c:2016
+#: src/http.c:1918
 msgid "Authorization failed.\n"
 msgstr "Autorización denegada.\n"
 
+# `no recuperando' no me suena muy español, te propongo la alternativa
+# más "humanizada", `no se recupera' - cll
+#
+#: src/http.c:1956 src/http.c:2466
+#, fuzzy, c-format
+msgid ""
+"File %s already there; not retrieving.\n"
+"\n"
+msgstr "El fichero `%s' ya está ahí, no se recupera.\n"
+
 # Piiiiii: escuchemos a los super-tacañones :)
 #
 # Como no existe el verbo "malformar" en español, el participio
 # `malformado' es incorrecto. El único término parecido a éste que
 # existe en español es `malformación'. - cll
-#: src/http.c:2030
+#: src/http.c:2070
 msgid "Malformed status line"
 msgstr "Línea de estado mal formada"
 
-#: src/http.c:2032
+#: src/http.c:2072
 msgid "(no description)"
 msgstr "(sin descripción)"
 
-#: src/http.c:2098
+#: src/http.c:2149
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Localización: %s%s\n"
 
-#: src/http.c:2099 src/http.c:2209
+#: src/http.c:2150 src/http.c:2258
 msgid "unspecified"
 msgstr "no especificado"
 
 # Duda: Hmmm, ... ¿`siguiendo' o `siguiente'? - cll
 # siguiendo - Salva
 #
-#: src/http.c:2100
+#: src/http.c:2151
 msgid " [following]"
 msgstr " [siguiendo]"
 
-#: src/http.c:2156
+#: src/http.c:2203
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
