 "\n"
 
 #. do not CWD
-#: src/ftp.c:502
+#: src/ftp.c:579
 msgid "==> CWD not required.\n"
 msgstr "==> CWD não requerido.\n"
 
-#: src/ftp.c:567
+#: src/ftp.c:639
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Não foi possível iniciar transferência PASV.\n"
 
-#: src/ftp.c:571
+#: src/ftp.c:643
 msgid "Cannot parse PASV response.\n"
 msgstr "Não foi possível entender resposta do comando PASV.\n"
 
-#: src/ftp.c:588
-#, c-format
-msgid "couldn't connect to %s:%hu: %s\n"
+#: src/ftp.c:660
+#, fuzzy, c-format
+msgid "couldn't connect to %s port %d: %s\n"
 msgstr "não foi possível conectar para %s:%hu: %s\n"
 
 # , c-format
-#: src/ftp.c:638
+#: src/ftp.c:708
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Erro no bind (%s).\n"
 
-#: src/ftp.c:645
+#: src/ftp.c:714
 msgid "Invalid PORT.\n"
 msgstr "PORT inválido.\n"
 
-#: src/ftp.c:698
-#, c-format
-msgid ""
-"\n"
-"REST failed; will not truncate `%s'.\n"
-msgstr ""
-"\n"
-"REST falhou; %s não será truncado.\n"
-
-#: src/ftp.c:705
+#: src/ftp.c:760
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
