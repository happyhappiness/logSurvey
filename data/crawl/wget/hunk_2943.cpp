 "\n"
 
 #. do not CWD
-#: src/ftp.c:502
+#: src/ftp.c:614
 msgid "==> CWD not required.\n"
 msgstr "==> CWD ei ole kohustuslik.\n"
 
-#: src/ftp.c:567
+#: src/ftp.c:677
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Ei saa algatada PASV ülekannet.\n"
 
-#: src/ftp.c:571
+#: src/ftp.c:681
 msgid "Cannot parse PASV response.\n"
 msgstr "Ei suuda analüüsida PASV vastust.\n"
 
-#: src/ftp.c:588
-#, c-format
-msgid "couldn't connect to %s:%hu: %s\n"
+#: src/ftp.c:701
+#, fuzzy, c-format
+msgid "couldn't connect to %s port %d: %s\n"
 msgstr "Ei õnnestu luua ühendust serveriga %s:%hu: %s.\n"
 
-#: src/ftp.c:638
+#: src/ftp.c:752
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Bind operatsiooni viga (%s).\n"
 
-#: src/ftp.c:645
+#: src/ftp.c:759
 msgid "Invalid PORT.\n"
 msgstr "Vale PORT.\n"
 
-#: src/ftp.c:698
-#, c-format
-msgid ""
-"\n"
-"REST failed; will not truncate `%s'.\n"
-msgstr ""
-"\n"
-"REST ebaõnnestus; ei lühenda faili `%s'.\n"
-
-#: src/ftp.c:705
+#: src/ftp.c:810
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
