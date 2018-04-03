#
msgid ""
msgstr ""
"Project-Id-Version: GNU Wget 1.7 pre 1\n"
"POT-Creation-Date: 2001-05-26 11:07+0200\n"
"PO-Revision-Date: 2001-05-27 21:29+0800\n"
"Last-Translator: Abel Cheung <maddog@linux.org.hk>\n"
"Language-Team: traditional chinese <zh-l10n@linux.org.tw>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=utf-8 \n"
"Content-Transfer-Encoding: 8bit\n"

#: src/cookies.c:588
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "Set-Cookie 在欄位 `%s' 出現錯誤"

#: src/cookies.c:612
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "Set-Cookie 在字元 `%c' 出現語法錯誤。\n"

#: src/cookies.c:620
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "Set-Cookie 出現語法錯誤：字串過早完結。\n"

#: src/cookies.c:1352
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "無法開啟 cookies 檔 `%s'：%s\n"

#: src/cookies.c:1364
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "寫入 `%s' 時發生錯誤：%s\n"

#: src/cookies.c:1368
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "關閉 `%s' 時發生錯誤：%s\n"

#: src/ftp-ls.c:787
msgid "Usupported listing type, trying Unix listing parser.\n"
msgstr "不支援的檔案列表類型，假設是 Unix 列表來分析。\n"

#: src/ftp-ls.c:832 src/ftp-ls.c:834
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "/%s 的索引在 %s:%d"

#: src/ftp-ls.c:856
msgid "time unknown       "
msgstr "未知的時間         "

#: src/ftp-ls.c:860
msgid "File        "
msgstr "檔案        "

#: src/ftp-ls.c:863
msgid "Directory   "
msgstr "目錄        "

#: src/ftp-ls.c:866
msgid "Link        "
msgstr "連結        "

#: src/ftp-ls.c:869
msgid "Not sure    "
msgstr "不確定      "

#: src/ftp-ls.c:887
#, c-format
msgid " (%s bytes)"
msgstr " (%s 位元組)"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:149 src/http.c:623
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "正在連接到 %s:%hu… "

#: src/ftp.c:171 src/ftp.c:538 src/http.c:640
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "嘗試連接到 %s:%hu 但被拒絕。\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:192 src/http.c:651
msgid "connected!\n"
msgstr "接上了！\n"

#: src/ftp.c:193
#, c-format
msgid "Logging in as %s ... "
msgstr "以 %s 的身份登入中… "

#: src/ftp.c:202 src/ftp.c:255 src/ftp.c:287 src/ftp.c:335 src/ftp.c:428
#: src/ftp.c:480 src/ftp.c:574 src/ftp.c:647 src/ftp.c:708 src/ftp.c:756
msgid "Error in server response, closing control connection.\n"
msgstr "伺服器回應錯誤，關閉控制連線。\n"

#: src/ftp.c:210
msgid "Error in server greeting.\n"
msgstr "伺服器問候錯誤。\n"

#: src/ftp.c:218 src/ftp.c:344 src/ftp.c:437 src/ftp.c:489 src/ftp.c:584
#: src/ftp.c:657 src/ftp.c:718 src/ftp.c:766
msgid "Write failed, closing control connection.\n"
msgstr "寫入失敗，關閉控制連線。\n"

#: src/ftp.c:225
msgid "The server refuses login.\n"
msgstr "伺服器拒絕登入。\n"

#: src/ftp.c:232
msgid "Login incorrect.\n"
msgstr "登入錯誤。\n"

#: src/ftp.c:239
msgid "Logged in!\n"
msgstr "登入完成！\n"

#: src/ftp.c:264
msgid "Server error, can't determine system type.\n"
msgstr "伺服器錯誤，不能決定作業系統的類型。\n"

#: src/ftp.c:274 src/ftp.c:559 src/ftp.c:631 src/ftp.c:688
msgid "done.    "
msgstr "完成。    "

#: src/ftp.c:324 src/ftp.c:458 src/ftp.c:739 src/ftp.c:787 src/url.c:1429
msgid "done.\n"
msgstr "完成。\n"

#: src/ftp.c:352
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "未知的類別 `%c'，關閉控制連線。\n"

#: src/ftp.c:365
msgid "done.  "
msgstr "完成。  "

#: src/ftp.c:371
msgid "==> CWD not needed.\n"
msgstr "==> 不需要 CWD(切換路徑)。\n"

#: src/ftp.c:444
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"目錄 `%s' 不存在。\n"
"\n"

#. do not CWD
#: src/ftp.c:462
msgid "==> CWD not required.\n"
msgstr "==> 不需要 CWD(切換路徑)。\n"

#: src/ftp.c:496
msgid "Cannot initiate PASV transfer.\n"
msgstr "無法初始化 PASV 傳輸。\n"

#: src/ftp.c:500
msgid "Cannot parse PASV response.\n"
msgstr "無法分析 PASV 回應。\n"

#: src/ftp.c:514
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "會嘗試連接到 %s:%hu。\n"

#: src/ftp.c:601
#, c-format
msgid "Bind error (%s).\n"
msgstr "聯繫(Bind)錯誤(%s)。\n"

#: src/ftp.c:617
msgid "Invalid PORT.\n"
msgstr "錯誤的通訊埠。\n"

#: src/ftp.c:670
#, c-format
msgid ""
"\n"
"REST failed; will not truncate `%s'.\n"
msgstr ""
"\n"
"重設(REST)失敗；不會截短 `%s'。\n"

#: src/ftp.c:677
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"重設(REST)失敗，要重頭開始。\n"

#: src/ftp.c:726
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"檔案 `%s' 不存在。\n"
"\n"

#: src/ftp.c:774
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"檔案或目錄 `%s' 不存在。\n"
"\n"

#: src/ftp.c:858 src/ftp.c:866
#, c-format
msgid "Length: %s"
msgstr "長度：%s"

#: src/ftp.c:860 src/ftp.c:868
#, c-format
msgid " [%s to go]"
msgstr " [尚有 %s]"

#: src/ftp.c:870
msgid " (unauthoritative)\n"
msgstr " (不可靠)\n"

#: src/ftp.c:897
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s：%s，關閉控制連線。\n"

#: src/ftp.c:905
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - 資料連線：%s；"

#: src/ftp.c:922
msgid "Control connection closed.\n"
msgstr "已關閉控制連線。\n"

#: src/ftp.c:940
msgid "Data transfer aborted.\n"
msgstr "已中止資料傳輸。\n"

#: src/ftp.c:1004
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "檔案 `%s' 已存在，不會接收。\n"

#: src/ftp.c:1074 src/http.c:1501
#, c-format
msgid "(try:%2d)"
msgstr "(嘗試次數：%2d)"

#: src/ftp.c:1138 src/http.c:1752
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld]\n"
