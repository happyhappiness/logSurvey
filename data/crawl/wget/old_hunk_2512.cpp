#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1778
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "沒有任何項目符合樣式‘%s’。\n"

#: src/ftp.c:1844
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "將 HTML 化的索引寫入至 ‘%s’ [%s]。\n"

#: src/ftp.c:1849
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "將 HTML 化的索引寫入至 ‘%s’。\n"

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: 選項‘%s’不明確\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: 選項‘--%s’不可配合引數使用\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: 選項‘%c%s’不可配合引數使用\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: 選項‘%s’需要引數\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: 無法識別選項‘--%s’\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: 無法識別選項‘%c%s’\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: 選項不合法 ─ %c\n"

#: src/getopt.c:785
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: 選項無效 ─ %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: 選項需要引數 ─ %c\n"

#: src/getopt.c:862
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: 選項‘-W %s’不明確\n"

#: src/getopt.c:880
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: 選項‘-W %s’不可配合引數使用\n"

#: src/host.c:366
msgid "Unknown host"
msgstr "不明主機"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:370
msgid "Temporary failure in name resolution"
msgstr "暫時無法檢索主機名稱"

#: src/host.c:372
msgid "Unknown error"
msgstr "錯誤原因不明"

#: src/host.c:751
#, c-format
msgid "Resolving %s... "
msgstr "正在查找主機 %s... "

#: src/host.c:798
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "失敗: 該主機沒有 IPv4/IPv6 地址。\n"

#: src/host.c:821
msgid "failed: timed out.\n"
msgstr "失敗: 連線逾時。\n"

#: src/html-url.c:298
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: 無法解析不完整的符號鏈結 %s。\n"

#: src/html-url.c:705
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: URL ‘%s’ 無效: %s\n"

#: src/http.c:373
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "無法寫入 HTTP 要求: %s。\n"

#: src/http.c:687
msgid "No headers, assuming HTTP/0.9"
msgstr "沒有任何標頭資料，假設為 HTTP/0.9"

#: src/http.c:1204
msgid "Disabling SSL due to encountered errors.\n"
msgstr "因遇到錯誤而停止使用 SSL。\n"

#: src/http.c:1374
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "載有 POST 資料的檔案 ‘%s’ 不見了：%s\n"

#: src/http.c:1423
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "繼續使用和 %s:%d 的連線。\n"

#: src/http.c:1492
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "無法讀取代理伺服器回應: %s。\n"

#: src/http.c:1512
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "無法透過代理伺服器進行 tunneling: %s"

#: src/http.c:1557
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "已送出 %s 要求，正在等候回應... "

#: src/http.c:1568
msgid "No data received.\n"
msgstr "收不到資料。\n"

#: src/http.c:1575
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "讀取標頭時發生錯誤 (%s)。\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1660
msgid "Unknown authentication scheme.\n"
msgstr "認證方式不詳。\n"

#: src/http.c:1684
msgid "Authorization failed.\n"
msgstr "認證失敗！\n"

#: src/http.c:1698
msgid "Malformed status line"
msgstr "不正常的狀態行"

#: src/http.c:1700
msgid "(no description)"
msgstr "(沒有任何說明)"

#: src/http.c:1763
#, c-format
msgid "Location: %s%s\n"
msgstr "位置: %s%s\n"

#: src/http.c:1764 src/http.c:1871
msgid "unspecified"
msgstr "未指定"

#: src/http.c:1765
msgid " [following]"
msgstr " [跟隨至新的 URL]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1821
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
