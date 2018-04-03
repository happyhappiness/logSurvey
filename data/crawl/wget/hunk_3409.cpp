 # ¡Efectivamente! Ahora lo has puesto tu, ...  `download'=`descarga' -
 # cll
 #
-#: src/main.c:854
+#: src/main.c:851
 #, c-format
 msgid "Download quota (%s bytes) EXCEEDED!\n"
 msgstr "¡Cuota de descarga (%s bytes) EXCEDIDA!\n"
 
-#. Please note that the double `%' in `%%s' is intentional, because
-#. redirect_output passes tmp through printf.
-#: src/main.c:896
-#, c-format
-msgid "%s received, redirecting output to `%%s'.\n"
-msgstr "%s recibido, redirigiendo la salida a `%%s'.\n"
-
-# Nunca debes traducir `background' como `fondo'. Es un término
-# comúnmente aceptado y muy bien comprendido el de `segundo plano'
-#
-# Por otra parte, y simplemente porque me suena mejor, he cambiado
-# `parar' por `detener', ... ¡Es una pijada!, lo sé, lo sé, ... :) - cll
-#
-#: src/mswindows.c:106
-#, c-format
-msgid ""
-"\n"
-"CTRL+Break received, redirecting output to `%s'.\n"
-"Execution continued in background.\n"
-"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
-msgstr ""
-"\n"
-"CTRL+Break recibido, redirigiendo la salida a `%s'.\n"
-"La ejecución continúa en segundo plano.\n"
-"Puede parar Wget presionando CTRL+ALT+Supr.\n"
-
 # Lo mismo que antes, ... `background' es `segundo plano' - cll
 #
-#. parent, no error
-#: src/mswindows.c:123 src/utils.c:467
+#: src/mswindows.c:120
 msgid "Continuing in background.\n"
 msgstr "Continuando en segundo plano.\n"
 
-#: src/mswindows.c:125 src/utils.c:469
+#: src/mswindows.c:122 src/utils.c:457
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr "La salida será escrita en `%s'.\n"
