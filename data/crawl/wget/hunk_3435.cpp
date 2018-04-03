 "完成 ─%s─\n"
 "下載了：%s 位元組，共 %d 個檔案\n"
 
-#: src/main.c:845
+#: src/main.c:851
 #, c-format
 msgid "Download quota (%s bytes) EXCEEDED!\n"
 msgstr "超過下載限額（%s 位元組）！\n"
 
-#. Please note that the double `%' in `%%s' is intentional, because
-#. redirect_output passes tmp through printf.
-#: src/main.c:883
-#, c-format
-msgid "%s received, redirecting output to `%%s'.\n"
-msgstr "接收 %s 完畢，將輸出導向至 `%%s'。\n"
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
-"接收到 CTRL+Break 按鍵，將輸出導向至 `%s'。\n"
-"程式將在背景繼續執行。\n"
-"你可以按下 CTRL+ALT+DELETE 以停止 Wget。\n"
-
-#. parent, no error
-#: src/mswindows.c:123 src/utils.c:462
+#: src/mswindows.c:120
 msgid "Continuing in background.\n"
 msgstr "繼續在背景中執行。\n"
 
-#: src/mswindows.c:125 src/utils.c:464
+#: src/mswindows.c:122 src/utils.c:457
 #, c-format
 msgid "Output will be written to `%s'.\n"
-msgstr "將輸出寫入 `%s'。\n"
+msgstr "將輸出寫入‘%s’。\n"
 
-#: src/mswindows.c:205
+#: src/mswindows.c:202
 #, c-format
 msgid "Starting WinHelp %s\n"
 msgstr "啟動 WinHelp %s\n"
 
-#: src/mswindows.c:232 src/mswindows.c:239
+#: src/mswindows.c:229 src/mswindows.c:236
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s：找不到可用的 socket 驅動程式。\n"
