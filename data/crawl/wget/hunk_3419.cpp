 "終了しました --%s--\n"
 "ダウンロード: %s バイト(ファイル数 %d)\n"
 
-#: src/main.c:854
+#: src/main.c:851
 #, c-format
 msgid "Download quota (%s bytes) EXCEEDED!\n"
 msgstr "容量制限(%s バイトのquota)を超過します!\n"
 
-#. Please note that the double `%' in `%%s' is intentional, because
-#. redirect_output passes tmp through printf.
-#: src/main.c:896
-msgid "%s received, redirecting output to `%%s'.\n"
-msgstr "%s を受信しました、`%%s' に出力をリダイレクトします。\n"
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
-"CTRL+Breakが押されました、`%s' に出力をリダイレクションします。\n"
-"実行はバックグラウンドで継続します。\n"
-"CTRL+ALT+DELETE を押せば、Wget を停止できます。\n"
-
-#. parent, no error
-#: src/mswindows.c:123 src/utils.c:467
+#: src/mswindows.c:120
 msgid "Continuing in background.\n"
 msgstr "バックグラウンドで継続します。\n"
 
-#: src/mswindows.c:125 src/utils.c:469
+#: src/mswindows.c:122 src/utils.c:457
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr "出力を `%s' に書き込みます。\n"
 
-#: src/mswindows.c:205
+#: src/mswindows.c:202
 #, c-format
 msgid "Starting WinHelp %s\n"
 msgstr "WinHelp %s を開始します。\n"
 
-#: src/mswindows.c:232 src/mswindows.c:239
+#: src/mswindows.c:229 src/mswindows.c:236
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: 使用可能なソケットドライバを見つけられません。\n"
