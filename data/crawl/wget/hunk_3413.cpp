 "Termin� --%s--\n"
 "T�l�chargement: %s octets dans %d fichiers\n"
 
-#: src/main.c:854
+#: src/main.c:851
 #, c-format
 msgid "Download quota (%s bytes) EXCEEDED!\n"
 msgstr "Quota de t�l�chargement (%s octets) D�PASS�!\n"
 
-#. Please note that the double `%' in `%%s' is intentional, because
-#. redirect_output passes tmp through printf.
-#: src/main.c:896
-#, c-format
-msgid "%s received, redirecting output to `%%s'.\n"
-msgstr "%s re�u, redirection de la sortie vers `%%s'.\n"
-
-#: src/mswindows.c:106
-#, c-format
-msgid ""
-"\n"
-"CTRL+Break received, redirecting output to `%s'.\n"
-"Execution continued in background.\n"
-"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
-msgstr ""
-"\n"
-"CTRL+Break re�u, redirection de la sortie vers `%s'.\n"
-"L'ex�cution de poursuit en arri�re plan.\n"
-"Vous pouvez arr�ter l'ex�cution de `wget' en appuyant CTRL+ALT+DELETE.\n"
-
-#. parent, no error
-#: src/mswindows.c:123 src/utils.c:467
+#: src/mswindows.c:120
 msgid "Continuing in background.\n"
 msgstr "Poursuite � l'arri�re plan.\n"
 
-#: src/mswindows.c:125 src/utils.c:469
+#: src/mswindows.c:122 src/utils.c:457
 #, c-format
 msgid "Output will be written to `%s'.\n"
-msgstr "La sortie sera �crite vers `%s'.\n"
+msgstr "La sortie sera �crite vers � %s �.\n"
 
-#: src/mswindows.c:205
+#: src/mswindows.c:202
 #, c-format
 msgid "Starting WinHelp %s\n"
 msgstr "D�marrage de WinHelp %s\n"
 
-#: src/mswindows.c:232 src/mswindows.c:239
+#: src/mswindows.c:229 src/mswindows.c:236
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: ne rep�rer un pilote de socket utilisable.\n"
