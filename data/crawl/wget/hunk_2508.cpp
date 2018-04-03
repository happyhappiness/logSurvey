 "\n"
 
 #. do not CWD
-#: src/ftp.c:502
+#: src/ftp.c:579
 msgid "==> CWD not required.\n"
 msgstr "==> 不需要 CWD。\n"
 
-#: src/ftp.c:567
+#: src/ftp.c:639
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "无法启动 PASV 传输。\n"
 
-#: src/ftp.c:571
+#: src/ftp.c:643
 msgid "Cannot parse PASV response.\n"
 msgstr "无法解析 PASV 响应内容。\n"
 
-#: src/ftp.c:588
-#, c-format
-msgid "couldn't connect to %s:%hu: %s\n"
+#: src/ftp.c:660
+#, fuzzy, c-format
+msgid "couldn't connect to %s port %d: %s\n"
 msgstr "无法连接到 %s:%hu ：%s\n"
 
-#: src/ftp.c:638
+#: src/ftp.c:708
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "Bind 错误(%s)。\n"
 
-#: src/ftp.c:645
+#: src/ftp.c:714
 msgid "Invalid PORT.\n"
 msgstr "无效的 PORT(端口)。\n"
 
-#: src/ftp.c:698
-#, c-format
-msgid ""
-"\n"
-"REST failed; will not truncate `%s'.\n"
-msgstr ""
-"\n"
-"重置 (REST) 失败；不会截短‘%s’。\n"
-
-#: src/ftp.c:705
+#: src/ftp.c:760
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
