msgid " (unauthoritative)\n"
msgstr " (非正式資料)\n"

#: src/ftp.c:303
#, c-format
msgid "Logging in as %s ... "
msgstr "以 %s 的身分登入... "

#: src/ftp.c:316 src/ftp.c:362 src/ftp.c:391 src/ftp.c:443 src/ftp.c:555
#: src/ftp.c:601 src/ftp.c:630 src/ftp.c:687 src/ftp.c:748 src/ftp.c:808
#: src/ftp.c:855
msgid "Error in server response, closing control connection.\n"
msgstr "伺服器回應訊息發生錯誤，會關閉控制連線。\n"

#: src/ftp.c:323
msgid "Error in server greeting.\n"
msgstr "伺服器訊息出現錯誤。\n"

#: src/ftp.c:330 src/ftp.c:451 src/ftp.c:563 src/ftp.c:638 src/ftp.c:697
#: src/ftp.c:758 src/ftp.c:818 src/ftp.c:865
msgid "Write failed, closing control connection.\n"
msgstr "無法寫入，會關閉控制連線。\n"

#: src/ftp.c:336
msgid "The server refuses login.\n"
msgstr "伺服器拒絕登入。\n"

#: src/ftp.c:342
msgid "Login incorrect.\n"
msgstr "登入錯誤。\n"

#: src/ftp.c:348
msgid "Logged in!\n"
msgstr "登入完成！\n"

#: src/ftp.c:370
msgid "Server error, can't determine system type.\n"
msgstr "伺服器錯誤，無法決定作業系統的類型。\n"

#: src/ftp.c:379 src/ftp.c:674 src/ftp.c:731 src/ftp.c:774
msgid "done.    "
msgstr "完成。    "

#: src/ftp.c:431 src/ftp.c:580 src/ftp.c:613 src/ftp.c:838 src/ftp.c:884
msgid "done.\n"
msgstr "完成。\n"

#: src/ftp.c:458
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "類別 ‘%c’ 不詳，會關閉控制連線。\n"

#: src/ftp.c:470
msgid "done.  "
msgstr "完成。  "

#: src/ftp.c:476
msgid "==> CWD not needed.\n"
msgstr "==> 不需要 CWD (切換路徑)。\n"

#: src/ftp.c:569
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"目錄‘%s’不存在。\n"
"\n"

#: src/ftp.c:584
msgid "==> CWD not required.\n"
msgstr "==> 不需要 CWD (切換路徑)。\n"

#: src/ftp.c:644
msgid "Cannot initiate PASV transfer.\n"
msgstr "無法初始化 PASV 檔案傳送方式。\n"

#: src/ftp.c:648
msgid "Cannot parse PASV response.\n"
msgstr "無法分析 PASV 回應訊息。\n"

#: src/ftp.c:665
#, c-format
msgid "couldn't connect to %s port %d: %s\n"
msgstr "無法連上 %s 的埠號 %d: %s\n"

#: src/ftp.c:713
#, c-format
msgid "Bind error (%s).\n"
msgstr "Bind 發生錯誤(%s)。\n"

#: src/ftp.c:719
msgid "Invalid PORT.\n"
msgstr "PORT 指令無效。\n"

#: src/ftp.c:765
msgid ""
"\n"
"REST failed, starting from scratch.\n"
