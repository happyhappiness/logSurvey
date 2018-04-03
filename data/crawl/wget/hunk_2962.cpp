 "\n"
 
 #. do not CWD
-#: src/ftp.c:453
+#: src/ftp.c:614
 msgid "==> CWD not required.\n"
 msgstr "==> CWD nem szükséges.\n"
 
-#: src/ftp.c:516
+#: src/ftp.c:677
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Nem tudok kezdeményezni PASV átvitelt.\n"
 
-#: src/ftp.c:520
+#: src/ftp.c:681
 msgid "Cannot parse PASV response.\n"
 msgstr "Nem tudom értelmezni a PASV választ.\n"
 
-#: src/ftp.c:541
-#, c-format
-msgid "couldn't connect to %s:%hu: %s\n"
+#: src/ftp.c:701
+#, fuzzy, c-format
+msgid "couldn't connect to %s port %d: %s\n"
 msgstr "nem tudok csatlakozni %s:%hu-hoz: %s\n"
 
-#: src/ftp.c:591
+#: src/ftp.c:752
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Hozzárendelési hiba (%s).\n"
 
-#: src/ftp.c:598
+#: src/ftp.c:759
 msgid "Invalid PORT.\n"
 msgstr "Hibás PORT.\n"
 
-#: src/ftp.c:651
-#, c-format
-msgid ""
-"\n"
-"REST failed; will not truncate `%s'.\n"
-msgstr ""
-"\n"
-"REST nem sikerült; nem fogom tördelni `%s'-t.\n"
-
-#: src/ftp.c:658
+#: src/ftp.c:810
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
