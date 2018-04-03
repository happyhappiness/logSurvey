#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1608
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "不符合樣式‘%s’。\n"

#: src/ftp.c:1673
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "將 HTML 化的索引寫入‘%s’[%ld]。\n"

#: src/ftp.c:1678
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "將 HTML 化的索引寫入‘%s’。\n"

#: src/gen_sslfunc.c:109
msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
msgstr "無法產生 OpenSSL 亂數產生程序 (PRNG) 使用的亂數種子；暫停使用 SSL。\n"

#: src/getopt.c:454
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s：選項‘%s’是不明確的\n"

#: src/getopt.c:478
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s：選項‘--%s’不接受參數\n"

#: src/getopt.c:483
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s：選項‘%c%s’不接受參數\n"

#: src/getopt.c:498
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s：選項‘%s’需要參數\n"

#. --option
#: src/getopt.c:528
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s：無法識別選項‘--%s’\n"

#. +option or -option
#: src/getopt.c:532
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s：無法識別選項‘%c%s’\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:563
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s：不合法的選項 ─ %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:602
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s：選項需要參數 ─ %c\n"

#: src/host.c:271
#, c-format
msgid "Resolving %s... "
msgstr "正在查找主機 %s... "

#: src/host.c:278
#, c-format
msgid "failed: %s.\n"
msgstr "失敗：%s。\n"

#: src/host.c:348
msgid "Host not found"
msgstr "找不到主機"

#: src/host.c:350
msgid "Unknown error"
msgstr "不明的錯誤"

#: src/html-url.c:336
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s：無法解析不完整的符號連結 %s。\n"

#. this is fatal
#: src/http.c:573
msgid "Failed to set up an SSL context\n"
msgstr "無法建立 SSL context\n"

#: src/http.c:579
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "無法由 %s 載入認證檔（certificate）\n"

#: src/http.c:583 src/http.c:591
msgid "Trying without the specified certificate\n"
msgstr "嘗試不載入指定的認證檔（certificate）\n"

#: src/http.c:587
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "無法由 %s 載入相關認證檔的鑰匙\n"

#: src/http.c:657 src/http.c:1620
msgid "Unable to establish SSL connection.\n"
msgstr "無法建立 SSL 連線。\n"

#: src/http.c:666
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "再使用連到 %s:%hu 的連線。\n"

#: src/http.c:868
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "無法寫入 HTTP 要求：%s。\n"

#: src/http.c:873
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "已送出 %s 要求，正在等候回應... "

#: src/http.c:917
msgid "End of file while parsing headers.\n"
msgstr "分析標頭時檔案突然結束。\n"

#: src/http.c:927
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "讀取標頭時發生錯誤(%s)。\n"

#: src/http.c:962
msgid "No data received"
msgstr "沒有收到資料"

#: src/http.c:964
msgid "Malformed status line"
msgstr "不正常的狀態行"

#: src/http.c:969
msgid "(no description)"
msgstr "(沒有描述)"

#: src/http.c:1101
msgid "Authorization failed.\n"
msgstr "認證失敗！\n"

#: src/http.c:1108
msgid "Unknown authentication scheme.\n"
msgstr "認證方式不詳。\n"

#: src/http.c:1148
#, c-format
msgid "Location: %s%s\n"
msgstr "位置：%s%s\n"

#: src/http.c:1149 src/http.c:1282
msgid "unspecified"
msgstr "未指定"

#: src/http.c:1150
msgid " [following]"
msgstr " [跟隨連結]"

#: src/http.c:1213
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
