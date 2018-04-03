 "\n"
 
 #. do not CWD
-#: src/ftp.c:595
+#: src/ftp.c:502
 msgid "==> CWD not required.\n"
 msgstr "==> CWD ez da beharrezkoa.\n"
 
-#: src/ftp.c:654
+#: src/ftp.c:567
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "Ezin da PASV transferentzia hasi.\n"
 
-#: src/ftp.c:658
+#: src/ftp.c:571
 msgid "Cannot parse PASV response.\n"
 msgstr "Ezin da PASV erantzuan parseatu.\n"
 
-#: src/ftp.c:676
-#, fuzzy, c-format
-msgid "couldn't connect to %s port %d: %s\n"
+#: src/ftp.c:588
+#, c-format
+msgid "couldn't connect to %s:%hu: %s\n"
 msgstr "ezin izan da %s-ra konektatu:%hu:%s\n"
 
-#: src/ftp.c:724
+#: src/ftp.c:638
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Lotze errorea (%s).\n"
 
-#: src/ftp.c:730
+#: src/ftp.c:645
 msgid "Invalid PORT.\n"
 msgstr "PORTU desegokia.\n"
 
-#: src/ftp.c:776
+#: src/ftp.c:698
+#, c-format
+msgid ""
+"\n"
+"REST failed; will not truncate `%s'.\n"
+msgstr ""
+"\n"
+"REST komanduak huts egin du, ez da`%s' moztuko.\n"
+
+#: src/ftp.c:705
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
