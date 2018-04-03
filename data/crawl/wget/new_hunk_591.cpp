"正確的符號鏈結 %s → %s 已經存在\n"
"\n"

#: src/ftp.c:1788
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "建立符號鏈結 %s → %s\n"

#: src/ftp.c:1798
#, fuzzy, c-format
msgid "Symlinks not supported, skipping symlink %s.\n"
msgstr "本系統不支援符號鏈結，略過符號鏈結‘%s’。\n"

#: src/ftp.c:1810
#, fuzzy, c-format
msgid "Skipping directory %s.\n"
msgstr "略過目錄‘%s’。\n"

#: src/ftp.c:1819
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: 檔案類別不詳或不支援。\n"

#: src/ftp.c:1856
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: 時間標記錯誤。\n"

#: src/ftp.c:1878
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "因為深度為 %d (最大值為 %d)，所以不下載。\n"

#: src/ftp.c:1928
#, fuzzy, c-format
msgid "Not descending to %s as it is excluded/not-included.\n"
msgstr "不進入‘%s’目錄因為已被排除或不被列入清單中。\n"

#: src/ftp.c:1994 src/ftp.c:2008
#, fuzzy, c-format
msgid "Rejecting %s.\n"
msgstr "拒絕‘%s’。\n"

#: src/ftp.c:2031
#, fuzzy, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "寫入‘%s’時發生錯誤: %s\n"

#: src/ftp.c:2073
#, fuzzy, c-format
msgid "No matches on pattern %s.\n"
msgstr "沒有任何項目符合樣式‘%s’。\n"

#: src/ftp.c:2144
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s [%s].\n"
msgstr "將 HTML 化的索引寫入至 ‘%s’ [%s]。\n"

#: src/ftp.c:2149
#, fuzzy, c-format
msgid "Wrote HTML-ized index to %s.\n"
msgstr "將 HTML 化的索引寫入至 ‘%s’。\n"

#: src/gnutls.c:219 src/openssl.c:495
msgid "ERROR"
msgstr "錯誤"

#: src/gnutls.c:219 src/openssl.c:495
msgid "WARNING"
msgstr "警告"

#: src/gnutls.c:225 src/openssl.c:504
#, c-format
msgid "%s: No certificate presented by %s.\n"
msgstr "%s：%s 沒有提供憑證。\n"

#: src/gnutls.c:233
#, fuzzy, c-format
msgid "%s: The certificate of %s is not trusted.\n"
msgstr "%s：%s 沒有提供憑證。\n"

#: src/gnutls.c:239
#, c-format
msgid "%s: The certificate of %s hasn't got a known issuer.\n"
msgstr ""

#: src/gnutls.c:245
#, fuzzy, c-format
msgid "%s: The certificate of %s has been revoked.\n"
msgstr "%s：%s 沒有提供憑證。\n"

#: src/gnutls.c:259
#, c-format
msgid "Error initializing X509 certificate: %s\n"
msgstr ""

#: src/gnutls.c:268
#, fuzzy
msgid "No certificate found\n"
msgstr "%s：%s 沒有提供憑證。\n"

#: src/gnutls.c:275
#, fuzzy, c-format
msgid "Error parsing certificate: %s\n"
msgstr "分析代理伺服器 URL %s 時發生錯誤: %s。\n"

#: src/gnutls.c:282
msgid "The certificate has not yet been activated\n"
msgstr ""

#: src/gnutls.c:287
msgid "The certificate has expired\n"
msgstr ""

#: src/gnutls.c:293
#, fuzzy, c-format
msgid "The certificate's owner does not match hostname '%s'\n"
msgstr "%s：憑證的 common name ‘%s’ 和主機名稱 ‘%s’ 不符。\n"

#: src/host.c:358
msgid "Unknown host"
msgstr "不明主機"

#: src/host.c:362
msgid "Temporary failure in name resolution"
msgstr "暫時無法檢索主機名稱"

#: src/host.c:364
msgid "Unknown error"
msgstr "錯誤原因不明"

#: src/host.c:737
#, c-format
msgid "Resolving %s... "
msgstr "正在查找主機 %s... "

#: src/host.c:789
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "失敗: 該主機沒有 IPv4/IPv6 地址。\n"

#: src/host.c:812
msgid "failed: timed out.\n"
msgstr "失敗: 連線逾時。\n"

#: src/html-url.c:286
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: 無法解析不完整的符號鏈結 %s。\n"

#: src/html-url.c:762
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: URL ‘%s’ 無效: %s\n"

#: src/http.c:377
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "無法寫入 HTTP 要求: %s。\n"

#: src/http.c:754
msgid "No headers, assuming HTTP/0.9"
msgstr "沒有任何標頭資料，假設為 HTTP/0.9"

#: src/http.c:1456
msgid "Disabling SSL due to encountered errors.\n"
msgstr "因遇到錯誤而停止使用 SSL。\n"

#: src/http.c:1576
#, fuzzy, c-format
msgid "POST data file %s missing: %s\n"
msgstr "載有 POST 資料的檔案 ‘%s’ 不見了：%s\n"

#: src/http.c:1660
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "繼續使用和 %s:%d 的連線。\n"

#: src/http.c:1729
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "無法讀取代理伺服器回應: %s。\n"

#: src/http.c:1750
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "無法透過代理伺服器進行 tunneling: %s"

#: src/http.c:1795
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "已送出 %s 要求，正在等候回應... "

#: src/http.c:1806
msgid "No data received.\n"
msgstr "收不到資料。\n"

#: src/http.c:1813
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "讀取標頭時發生錯誤 (%s)。\n"

#: src/http.c:1884
msgid "Unknown authentication scheme.\n"
msgstr "認證方式不詳。\n"

#: src/http.c:1918
msgid "Authorization failed.\n"
msgstr "認證失敗！\n"

#: src/http.c:1956 src/http.c:2466
#, fuzzy, c-format
msgid ""
"File %s already there; not retrieving.\n"
