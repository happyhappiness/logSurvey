 "REMATADO --%s--\n"
 "Descargados: %s bytes en %d ficheiros\n"
 
-#: src/main.c:842
+#: src/main.c:851
 #, c-format
 msgid "Download quota (%s bytes) EXCEEDED!\n"
 msgstr "¡O límite de descarga (%s bytes) foi SUPERADO!\n"
 
-#. Please note that the double `%' in `%%s' is intentional, because
-#. redirect_output passes tmp through printf.
-#: src/main.c:876
-#, c-format
-msgid "%s received, redirecting output to `%%s'.\n"
-msgstr "%s recibido, redireccionando a saída a `%%s'\n"
-
-#: src/mswindows.c:89
-#, c-format
-msgid ""
-"\n"
-"CTRL+Break received, redirecting output to `%s'.\n"
-"Execution continued in background.\n"
-"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
-msgstr ""
-"\n"
-"Recibiuse un CTRL+Break, redireccionando a saida a `%s'.\n"
-"A execución segue en segundo plano.\n"
-"Pode deter Wget premendo CTRL+ALT+DELETE.\n"
-
-#. parent, no error
-#: src/mswindows.c:106 src/utils.c:458
+#: src/mswindows.c:120
 msgid "Continuing in background.\n"
 msgstr "Seguindo en segundo plano.\n"
 
-#: src/mswindows.c:108 src/utils.c:460
+#: src/mswindows.c:122 src/utils.c:457
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr "Vaise escribi-la saida a `%s'.\n"
 
-#: src/mswindows.c:188
+#: src/mswindows.c:202
 #, c-format
 msgid "Starting WinHelp %s\n"
 msgstr "Comezando WinHelp %s\n"
 
-#: src/mswindows.c:215 src/mswindows.c:222
+#: src/mswindows.c:229 src/mswindows.c:236
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: Non se puido atopar un controlador de sockets utilizable.\n"
 
-#: src/netrc.c:367
+#: src/netrc.c:365
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
 msgstr "%s: %s:%d: aviso: o elemento \"%s\" aparece antes dun nome de máquina\n"
 
-#: src/netrc.c:398
+#: src/netrc.c:396
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: elemento \"%s\" descoñecido\n"
 
-#: src/netrc.c:462
+#: src/netrc.c:460
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Uso: %s NETRC [SERVIDOR]\n"
 
-#: src/netrc.c:472
+#: src/netrc.c:470
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: non se pode obter información de %s: %s\n"
 
-#: src/recur.c:484
+#. Align the [ skipping ... ] line with the dots.  To do
+#. that, insert the number of spaces equal to the number of
+#. digits in the skipped amount in K.
+#: src/progress.c:224
+#, c-format
+msgid "\n%*s[ skipping %dK ]"
+msgstr "\n%*s[ omitindo %dK ]"
+
+#: src/progress.c:391
+#, c-format
+msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
+msgstr "Especificación de estilo dos pountos `%s' non válida; queda sen cambiar.\n"
+
+#: src/recur.c:350
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Borrando %s porque debería ser rexeitado.\n"
 
-#: src/recur.c:679
+#: src/recur.c:935
+#, c-format
+msgid "Converted %d files in %.2f seconds.\n"
+msgstr "Convertéronse %d ficheiros en %.2f segundos.\n"
+
+#: src/res.c:540
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Cargando robots.txt; por favor, ignore os erros.\n"
 
-#: src/retr.c:227
-#, c-format
-msgid "\n          [ skipping %dK ]"
-msgstr "\n          [ saltando %dK ]"
-
-#: src/retr.c:373
+#: src/retr.c:363
 msgid "Could not find proxy host.\n"
 msgstr "Non se puido atopar un servidor proxy.\n"
 
-#: src/retr.c:387
+#: src/retr.c:375
 #, c-format
-msgid "Proxy %s: Must be HTTP.\n"
-msgstr "Proxy %s: Debe ser HTTP.\n"
+msgid "Error parsing proxy URL %s: %s.\n"
+msgstr "Erro ao analiza-lo URL do proxy %s: %s.\n"
 
-#: src/retr.c:481
+#: src/retr.c:384
+#, c-format
+msgid "Error in proxy URL %s: Must be HTTP.\n"
+msgstr "Erro no URL do proxy %s: Debe ser HTTP.\n"
+
+#: src/retr.c:476
+#, c-format
+msgid "%d redirections exceeded.\n"
+msgstr "Superáronse %d redireccións.\n"
+
+#: src/retr.c:491
 #, c-format
 msgid "%s: Redirection cycle detected.\n"
 msgstr "%s: Detectouse un ciclo de redireccións.\n"
 
-#: src/retr.c:587
+#: src/retr.c:608
 msgid "Giving up.\n\n"
 msgstr "Abandonando.\n\n"
 
-#: src/retr.c:587
+#: src/retr.c:608
 msgid "Retrying.\n\n"
 msgstr "Intentándoo de novo.\n\n"
 
-#: src/url.c:1329
+#: src/url.c:1875
 #, c-format
 msgid "Converting %s... "
 msgstr "Convertindo %s..."
 
-#: src/url.c:1342
+#: src/url.c:1888
 msgid "nothing to do.\n"
 msgstr "non hai nada que facer.\n"
 
-#: src/url.c:1350 src/url.c:1374
+#: src/url.c:1896 src/url.c:1920
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Non se poden converte-las ligazóns en %s: %s\n"
 
-#: src/url.c:1365
+#: src/url.c:1911
 #, c-format
 msgid "Unable to delete `%s': %s\n"
 msgstr "Non se puido borrar `%s': %s\n"
 
-#: src/url.c:1555
+#: src/url.c:2117
 #, c-format
 msgid "Cannot back up %s as %s: %s\n"
 msgstr "Non se pode copiar %s coma %s: %s\n"
 
-#: src/utils.c:94
+#: src/utils.c:90
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: Non hai memoria dabondo.\n"
 
-#: src/utils.c:417
-msgid "Unknown/unsupported protocol"
-msgstr "Protocolo descoñecido ou non soportado"
-
-#: src/utils.c:420
-msgid "Invalid port specification"
-msgstr "Especificación de porto incorrecta"
-
-#: src/utils.c:423
-msgid "Invalid host name"
-msgstr "O nome do servidor non é válido"
+#. parent, no error
+#: src/utils.c:455
+#, c-format
+msgid "Continuing in background, pid %d.\n"
+msgstr "Seguindo en segundo plano, pid %d.\n"
 
-#: src/utils.c:620
+#: src/utils.c:499
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Fallo ao desligar `%s': %s\n"
 
+#~ msgid ""
+#~ "\n"
+#~ "CTRL+Break received, redirecting output to `%s'.\n"
+#~ "Execution continued in background.\n"
+#~ "You may stop Wget by pressing CTRL+ALT+DELETE.\n"
+#~ msgstr ""
+#~ "\n"
+#~ "Recibiuse un CTRL+Break, redireccionando a saida a `%s'.\n"
+#~ "A execución segue en segundo plano.\n"
+#~ "Pode deter Wget premendo CTRL+ALT+DELETE.\n"
+
+#~ msgid "Connection to %s:%hu refused.\n"
+#~ msgstr "A conexión a %s:%hu foi rexeitada.\n"
+
+#~ msgid "Will try connecting to %s:%hu.\n"
+#~ msgstr "Tentarase conectar con %s:%hu.\n"
+
+#~ msgid "Unknown/unsupported protocol"
+#~ msgstr "Protocolo descoñecido ou non soportado"
+
+#~ msgid "Invalid port specification"
+#~ msgstr "Especificación de porto incorrecta"
+
+#~ msgid "Invalid host name"
+#~ msgstr "O nome do servidor non é válido"
+
 #~ msgid "%s: Cannot determine user-id.\n"
 #~ msgstr "%s: Non se pode determina-lo identificador de usuario.\n"
 
