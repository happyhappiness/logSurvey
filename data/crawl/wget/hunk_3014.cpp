 "\n"
 
 #. do not CWD
-#: src/ftp.c:453
+#: src/ftp.c:614
 msgid "==> CWD not required.\n"
 msgstr "==> 不需要 CWD(切換路徑)。\n"
 
-#: src/ftp.c:516
+#: src/ftp.c:677
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "無法初始化 PASV 傳輸。\n"
 
-#: src/ftp.c:520
+#: src/ftp.c:681
 msgid "Cannot parse PASV response.\n"
 msgstr "無法分析 PASV 回應。\n"
 
-#: src/ftp.c:541
-#, c-format
-msgid "couldn't connect to %s:%hu: %s\n"
+#: src/ftp.c:701
+#, fuzzy, c-format
+msgid "couldn't connect to %s port %d: %s\n"
 msgstr "無法連上 %s:%hu ：%s\n"
 
-#: src/ftp.c:591
+#: src/ftp.c:752
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Bind 發生錯誤(%s)。\n"
 
-#: src/ftp.c:598
+#: src/ftp.c:759
 msgid "Invalid PORT.\n"
 msgstr "錯誤的通訊埠。\n"
 
-#: src/ftp.c:651
-#, c-format
-msgid ""
-"\n"
-"REST failed; will not truncate `%s'.\n"
-msgstr ""
-"\n"
-"重設(REST)失敗；不會截短‘%s’。\n"
-
-#: src/ftp.c:658
+#: src/ftp.c:810
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
