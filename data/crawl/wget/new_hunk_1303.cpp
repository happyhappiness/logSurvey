msgid " (unauthoritative)\n"
msgstr " (非正式資料)\n"

#: src/ftp.c:305
#, c-format
msgid "Logging in as %s ... "
msgstr "以 %s 的身分登入... "

#: src/ftp.c:319 src/ftp.c:365 src/ftp.c:394 src/ftp.c:446 src/ftp.c:559
#: src/ftp.c:606 src/ftp.c:635 src/ftp.c:692 src/ftp.c:753 src/ftp.c:839
#: src/ftp.c:886
msgid "Error in server response, closing control connection.\n"
msgstr "伺服器回應訊息發生錯誤，會關閉控制連線。\n"

#: src/ftp.c:326
msgid "Error in server greeting.\n"
msgstr "伺服器訊息出現錯誤。\n"

#: src/ftp.c:333 src/ftp.c:454 src/ftp.c:567 src/ftp.c:643 src/ftp.c:702
#: src/ftp.c:763 src/ftp.c:849 src/ftp.c:896
msgid "Write failed, closing control connection.\n"
msgstr "無法寫入，會關閉控制連線。\n"

#: src/ftp.c:339
msgid "The server refuses login.\n"
msgstr "伺服器拒絕登入。\n"

#: src/ftp.c:345
msgid "Login incorrect.\n"
msgstr "登入錯誤。\n"

#: src/ftp.c:351
msgid "Logged in!\n"
msgstr "登入完成！\n"

#: src/ftp.c:373
msgid "Server error, can't determine system type.\n"
msgstr "伺服器錯誤，無法決定作業系統的類型。\n"

#: src/ftp.c:382 src/ftp.c:679 src/ftp.c:736 src/ftp.c:779
msgid "done.    "
msgstr "完成。    "

#: src/ftp.c:434 src/ftp.c:584 src/ftp.c:618 src/ftp.c:869 src/ftp.c:915
msgid "done.\n"
msgstr "完成。\n"

#: src/ftp.c:461
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "類別 ‘%c’ 不詳，會關閉控制連線。\n"

#: src/ftp.c:473
msgid "done.  "
msgstr "完成。  "

#: src/ftp.c:479
msgid "==> CWD not needed.\n"
msgstr "==> 不需要 CWD (切換路徑)。\n"

#: src/ftp.c:573
#, fuzzy, c-format
msgid ""
"No such directory %s.\n"
"\n"
msgstr ""
"目錄‘%s’不存在。\n"
"\n"

#: src/ftp.c:588
msgid "==> CWD not required.\n"
msgstr "==> 不需要 CWD (切換路徑)。\n"

#: src/ftp.c:649
msgid "Cannot initiate PASV transfer.\n"
msgstr "無法初始化 PASV 檔案傳送方式。\n"

#: src/ftp.c:653
msgid "Cannot parse PASV response.\n"
msgstr "無法分析 PASV 回應訊息。\n"

#: src/ftp.c:670
#, c-format
msgid "couldn't connect to %s port %d: %s\n"
msgstr "無法連上 %s 的埠號 %d: %s\n"

#: src/ftp.c:718
#, c-format
msgid "Bind error (%s).\n"
msgstr "Bind 發生錯誤(%s)。\n"

#: src/ftp.c:724
msgid "Invalid PORT.\n"
msgstr "PORT 指令無效。\n"

#: src/ftp.c:770
msgid ""
"\n"
"REST failed, starting from scratch.\n"
