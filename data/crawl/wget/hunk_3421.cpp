 "\n"
 
 #. do not CWD
-#: src/ftp.c:441
+#: src/ftp.c:453
 msgid "==> CWD not required.\n"
 msgstr "==> CWD nie wymagane.\n"
 
-#: src/ftp.c:475
+#: src/ftp.c:516
 msgid "Cannot initiate PASV transfer.\n"
-msgstr "Nie mo¿na zainicjowaæ transferu typu PASV.\n"
+msgstr "Nie mo¿na zainicjowaæ przesy³ania typu PASV.\n"
 
-#: src/ftp.c:479
+#: src/ftp.c:520
 msgid "Cannot parse PASV response.\n"
-msgstr "Nie mo¿na przeskanowaæ odpowiedzi PASV.\n"
+msgstr "Nie mo¿na przeanalizowaæ sk³adni odpowiedzi PASV.\n"
 
-#: src/ftp.c:493
+#: src/ftp.c:541
 #, c-format
-msgid "Will try connecting to %s:%hu.\n"
-msgstr "Nast±pi± próby po³±czenia z %s:%hu.\n"
+msgid "couldn't connect to %s:%hu: %s\n"
+msgstr "nie uda³o siê po³±czyæ z %s:%hu: %s\n"
 
-#: src/ftp.c:580
+#: src/ftp.c:591
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "B³±d Bind (%s).\n"
 
-#: src/ftp.c:596
+#: src/ftp.c:598
 msgid "Invalid PORT.\n"
 msgstr "Nieprawid³owe PORT.\n"
 
-#: src/ftp.c:643
+#: src/ftp.c:651
+#, c-format
+msgid ""
+"\n"
+"REST failed; will not truncate `%s'.\n"
+msgstr ""
+"\n"
+"REST nieudane; zawarto¶æ `%s' nie zostanie obciêta.\n"
+
+#: src/ftp.c:658
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
