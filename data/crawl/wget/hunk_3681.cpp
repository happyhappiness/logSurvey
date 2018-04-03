 "`%s' というディレクトリはありません。\n"
 "\n"
 
+#: src/ftp.c:336 src/ftp.c:604 src/ftp.c:652 src/url.c:1678
+msgid "done.\n"
+msgstr "完了しました。\n"
+
 #. do not CWD
-#: src/ftp.c:441
+#: src/ftp.c:340
 msgid "==> CWD not required.\n"
 msgstr "==> CWD は必要ありません。\n"
 
-#: src/ftp.c:475
+#: src/ftp.c:374
 msgid "Cannot initiate PASV transfer.\n"
 msgstr "PASV転送の初期化ができません。\n"
 
-#: src/ftp.c:479
+#: src/ftp.c:378
 msgid "Cannot parse PASV response.\n"
 msgstr "PASVの応答を解析できません。\n"
 
-#: src/ftp.c:493
+#: src/ftp.c:392
 #, c-format
 msgid "Will try connecting to %s:%hu.\n"
-msgstr "%s:%hu への接続を試みています。\n"
+msgstr "%s:%hu への接続を試みます。\n"
 
-#: src/ftp.c:580
+#: src/ftp.c:437 src/ftp.c:509 src/ftp.c:553
+msgid "done.    "
+msgstr "完了しました。    "
+
+#: src/ftp.c:479
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "バインドエラーです (%s)。\n"
 
-#: src/ftp.c:596
+#: src/ftp.c:495
 msgid "Invalid PORT.\n"
 msgstr "無効なポート番号です。\n"
 
-#: src/ftp.c:643
+#: src/ftp.c:542
 msgid ""
 "\n"
 "REST failed, starting from scratch.\n"
