 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: a opción precisa dun argumento -- %c\n"
 
-#: src/host.c:374
+#: src/host.c:271
+#, c-format
+msgid "Resolving %s... "
+msgstr "Resolvendo %s... "
+
+#: src/host.c:278
+#, c-format
+msgid "failed: %s.\n"
+msgstr "fallou: %s.\n"
+
+#: src/host.c:348
 msgid "Host not found"
 msgstr "Non se atopou o servidor"
 
-#: src/host.c:376
+#: src/host.c:350
 msgid "Unknown error"
 msgstr "Erro descoñecido"
 
+#: src/html-url.c:336
+#, c-format
+msgid "%s: Cannot resolve incomplete link %s.\n"
+msgstr "%s: Non se pode resolve-la ligazón incompleta %s.\n"
+
 #. this is fatal
-#: src/http.c:555
+#: src/http.c:573
 msgid "Failed to set up an SSL context\n"
 msgstr "Non se puido estabrecer un contexto SSL\n"
 
-#: src/http.c:561
+#: src/http.c:579
 #, c-format
 msgid "Failed to load certificates from %s\n"
 msgstr "Non se puideron carga-los certificados de %s\n"
 
-#: src/http.c:565 src/http.c:573
+#: src/http.c:583 src/http.c:591
 msgid "Trying without the specified certificate\n"
 msgstr "Probando sen o certificado especificado\n"
 
-#: src/http.c:569
+#: src/http.c:587
 #, c-format
 msgid "Failed to get certificate key from %s\n"
 msgstr "Non se puido obte-la clave do certificado de %s\n"
 
-#: src/http.c:663 src/http.c:1593
+#: src/http.c:657 src/http.c:1620
 msgid "Unable to establish SSL connection.\n"
 msgstr "Non se puido estabrece-la conexión SSL.\n"
 
-#: src/http.c:671
+#: src/http.c:666
 #, c-format
 msgid "Reusing connection to %s:%hu.\n"
 msgstr "Reutilizando a conexión de %s:%hu.\n"
 
-#: src/http.c:861
+#: src/http.c:868
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Fallo ao escribir unha petición HTTP: %s.\n"
 
-#: src/http.c:866
+#: src/http.c:873
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "Petición %s enviada, agardando unha resposta... "
 
-#: src/http.c:910
+#: src/http.c:917
 msgid "End of file while parsing headers.\n"
 msgstr "Fin de ficheiro mentres se analizaban as cabeceiras.\n"
 
-#: src/http.c:920
+#: src/http.c:927
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Erro ao ler (%s) nas cabeceiras.\n"
 
-#: src/http.c:959
+#: src/http.c:962
 msgid "No data received"
 msgstr "Non se recibiron datos"
 
-#: src/http.c:961
+#: src/http.c:964
 msgid "Malformed status line"
 msgstr "Liña de estado mal formada"
 
-#: src/http.c:966
+#: src/http.c:969
 msgid "(no description)"
 msgstr "(sen descripción)"
 
-#: src/http.c:1089
+#: src/http.c:1101
 msgid "Authorization failed.\n"
 msgstr "Fallo na autorización.\n"
 
-#: src/http.c:1096
+#: src/http.c:1108
 msgid "Unknown authentication scheme.\n"
 msgstr "Sistema de autenticación descoñecido.\n"
 
-#: src/http.c:1136
+#: src/http.c:1148
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Lugar: %s%s\n"
 
-#: src/http.c:1137 src/http.c:1269
+#: src/http.c:1149 src/http.c:1282
 msgid "unspecified"
 msgstr "non especificado"
 
-#: src/http.c:1138
+#: src/http.c:1150
 msgid " [following]"
 msgstr " [seguíndoo]"
 
-#: src/http.c:1200
+#: src/http.c:1213
 msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
 msgstr "\n    O ficheiro xa está completo; non hai nada que facer.\n\n"
 
-#: src/http.c:1216
+#: src/http.c:1229
 #, c-format
 msgid ""
 "\n"
