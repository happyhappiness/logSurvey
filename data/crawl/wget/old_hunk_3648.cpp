#
msgid ""
msgstr ""
"Project-Id-Version: GNU Wget 1.7-dev\n"
"POT-Creation-Date: 2001-04-27 08:45+0200\n"
"PO-Revision-Date: 2001-04-29 04:12+0800\n"
"Last-Translator: Abel Cheung <maddog@linux.org.hk>\n"
"Language-Team: traditional chinese <zh-l10n@linux.org.tw>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=utf-8\n"
"Content-Transfer-Encoding: 8bit\n"

#: src/cookies.c:623
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Set-Cookie 在欄位 `%s' 出現錯誤"

#: src/cookies.c:647
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "Set-Cookie 在字元 `%c' 出現語法錯誤。\n"

#: src/cookies.c:655
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "Set-Cookie 出現語法錯誤：字串過早完結。\n"

#: src/cookies.c:1350
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "無法開啟 cookies 檔 `%s'：%s\n"

#: src/cookies.c:1362
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "寫入 `%s' 時發生錯誤：%s\n"

#: src/cookies.c:1366
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "關閉 `%s' 時發生錯誤：%s\n"

#: src/ftp-ls.c:785
msgid "Usupported listing type, trying Unix listing parser.\n"
msgstr "不支援的檔案列表類型，假設是 Unix 列表來分析.\n"

#: src/ftp-ls.c:830 src/ftp-ls.c:832
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "/%s 的索引在 %s:%d"

#: src/ftp-ls.c:854
msgid "time unknown       "
msgstr "未知的時間         "

#: src/ftp-ls.c:858
msgid "File        "
msgstr "檔案        "

#: src/ftp-ls.c:861
msgid "Directory   "
msgstr "目錄        "

#: src/ftp-ls.c:864
msgid "Link        "
msgstr "連結        "

#: src/ftp-ls.c:867
msgid "Not sure    "
msgstr "不確定      "

#: src/ftp-ls.c:885
#, c-format
msgid " (%s bytes)"
msgstr " (%s 位元組)"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:151 src/http.c:627
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "正在連接到 %s:%hu…"

#: src/ftp.c:173 src/ftp.c:540 src/http.c:644
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "嘗試連接到 %s:%hu 但被拒絕.\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:194 src/http.c:655
msgid "connected!\n"
msgstr "接上了!\n"

#: src/ftp.c:195
#, c-format
msgid "Logging in as %s ... "
msgstr "以 %s 的身份登入中…"

#: src/ftp.c:204 src/ftp.c:257 src/ftp.c:289 src/ftp.c:337 src/ftp.c:430
#: src/ftp.c:482 src/ftp.c:576 src/ftp.c:649 src/ftp.c:710 src/ftp.c:758
msgid "Error in server response, closing control connection.\n"
msgstr "伺服器回應錯誤，關閉控制連結.\n"

#: src/ftp.c:212
msgid "Error in server greeting.\n"
msgstr "伺服器問候錯誤.\n"

#: src/ftp.c:220 src/ftp.c:346 src/ftp.c:439 src/ftp.c:491 src/ftp.c:586
#: src/ftp.c:659 src/ftp.c:720 src/ftp.c:768
msgid "Write failed, closing control connection.\n"
msgstr "寫入失敗，關閉控制連結.\n"

#: src/ftp.c:227
msgid "The server refuses login.\n"
msgstr "伺服器拒絕登入.\n"

#: src/ftp.c:234
msgid "Login incorrect.\n"
msgstr "登入錯誤.\n"

#: src/ftp.c:241
msgid "Logged in!\n"
msgstr "登入完成!\n"

#: src/ftp.c:266
msgid "Server error, can't determine system type.\n"
msgstr "伺服器錯誤，不能決定作業系統的類型.\n"

#: src/ftp.c:276 src/ftp.c:561 src/ftp.c:633 src/ftp.c:690
msgid "done.    "
msgstr "完成."

#: src/ftp.c:326 src/ftp.c:460 src/ftp.c:741 src/ftp.c:789 src/url.c:1429
msgid "done.\n"
msgstr "完成.\n"

#: src/ftp.c:354
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "未知的類別 '%c'，關閉控制連結.\n"

#: src/ftp.c:367
msgid "done.  "
msgstr "完成."

#: src/ftp.c:373
msgid "==> CWD not needed.\n"
msgstr "==> 不需要 CWD (切換路徑).\n"

#: src/ftp.c:446
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"目錄 '%s' 不存在.\n"
"\n"

#. do not CWD
#: src/ftp.c:464
msgid "==> CWD not required.\n"
msgstr "==> 不需要 CWD (切換路徑).\n"

#: src/ftp.c:498
msgid "Cannot initiate PASV transfer.\n"
msgstr "無法初始化 PASV 傳輸.\n"

#: src/ftp.c:502
msgid "Cannot parse PASV response.\n"
msgstr "無法分析 PASV 回應.\n"

#: src/ftp.c:516
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "會嘗試連接到 %s:%hu.\n"

#: src/ftp.c:603
#, c-format
msgid "Bind error (%s).\n"
msgstr "結合(Bind)錯誤 (%s).\n"

#: src/ftp.c:619
msgid "Invalid PORT.\n"
msgstr "錯誤的通訊埠.\n"

#: src/ftp.c:672
#, c-format
msgid ""
"\n"
"REST failed; will not truncate `%s'.\n"
msgstr ""
"\n"
"重設(REST) 失敗；不會截短 `%s'。\n"

#: src/ftp.c:679
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"重設(REST) 失敗，要重頭開始。\n"

#: src/ftp.c:728
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"檔案 '%s' 不存在.\n"
"\n"

#: src/ftp.c:776
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"檔案或目錄 '%s' 不存在.\n"
"\n"

#: src/ftp.c:860 src/ftp.c:868
#, c-format
msgid "Length: %s"
msgstr "長度: %s"

#: src/ftp.c:862 src/ftp.c:870
#, c-format
msgid " [%s to go]"
msgstr " [尚有 %s]"

#: src/ftp.c:872
msgid " (unauthoritative)\n"
msgstr " (不可靠)\n"

#: src/ftp.c:899
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s 關閉控制連結.\n"

#: src/ftp.c:907
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - 資料連結: %s; "

#: src/ftp.c:924
msgid "Control connection closed.\n"
msgstr "已關閉控制連結.\n"

#: src/ftp.c:942
msgid "Data transfer aborted.\n"
msgstr "已中止資料傳輸.\n"

#: src/ftp.c:1006
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "檔案 '%s' 已存在，不會接收.\n"

#: src/ftp.c:1076 src/http.c:1501
#, c-format
msgid "(try:%2d)"
msgstr "(嘗試次數:%2d)"

#: src/ftp.c:1140 src/http.c:1754
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld]\n"
