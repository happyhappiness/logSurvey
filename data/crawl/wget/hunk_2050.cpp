 "正確的符號鏈結 %s → %s 已經存在\n"
 "\n"
 
-#: src/ftp.c:1493
+#: src/ftp.c:1494
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "建立符號鏈結 %s → %s\n"
 
-#: src/ftp.c:1503
+#: src/ftp.c:1504
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr "本系統不支援符號鏈結，略過符號鏈結‘%s’。\n"
 
-#: src/ftp.c:1515
+#: src/ftp.c:1516
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "略過目錄‘%s’。\n"
 
-#: src/ftp.c:1524
+#: src/ftp.c:1525
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: 檔案類別不詳或不支援。\n"
 
-#: src/ftp.c:1551
+#: src/ftp.c:1552
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: 時間標記錯誤。\n"
 
-#: src/ftp.c:1579
+#: src/ftp.c:1580
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "因為深度為 %d (最大值為 %d)，所以不下載。\n"
 
-#: src/ftp.c:1629
+#: src/ftp.c:1630
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr "不進入‘%s’目錄因為已被排除或不被列入清單中。\n"
 
-#: src/ftp.c:1695 src/ftp.c:1709
+#: src/ftp.c:1696 src/ftp.c:1710
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "拒絕‘%s’。\n"
 
-#: src/ftp.c:1757
+#: src/ftp.c:1733
+#, fuzzy, c-format
+msgid "Error matching %s against %s: %s\n"
+msgstr "寫入‘%s’時發生錯誤: %s\n"
+
+#: src/ftp.c:1774
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "沒有任何項目符合樣式‘%s’。\n"
 
-#: src/ftp.c:1823
+#: src/ftp.c:1840
 #, c-format
 msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "將 HTML 化的索引寫入至 ‘%s’ [%s]。\n"
 
-#: src/ftp.c:1828
+#: src/ftp.c:1845
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "將 HTML 化的索引寫入至 ‘%s’。\n"
 
-#: src/host.c:347
+#: src/host.c:348
 msgid "Unknown host"
 msgstr "不明主機"
 
-#: src/host.c:351
+#: src/host.c:352
 msgid "Temporary failure in name resolution"
 msgstr "暫時無法檢索主機名稱"
 
-#: src/host.c:353
+#: src/host.c:354
 msgid "Unknown error"
 msgstr "錯誤原因不明"
 
-#: src/host.c:714
+#: src/host.c:715
 #, c-format
 msgid "Resolving %s... "
 msgstr "正在查找主機 %s... "
 
-#: src/host.c:761
+#: src/host.c:762
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
 msgstr "失敗: 該主機沒有 IPv4/IPv6 地址。\n"
 
-#: src/host.c:784
+#: src/host.c:785
 msgid "failed: timed out.\n"
 msgstr "失敗: 連線逾時。\n"
 
-#: src/html-url.c:288
+#: src/html-url.c:289
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: 無法解析不完整的符號鏈結 %s。\n"
 
-#: src/html-url.c:695
+#: src/html-url.c:696
 #, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: URL ‘%s’ 無效: %s\n"
 
-#: src/http.c:367
+#: src/http.c:368
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "無法寫入 HTTP 要求: %s。\n"
 
-#: src/http.c:736
+#: src/http.c:737
 msgid "No headers, assuming HTTP/0.9"
 msgstr "沒有任何標頭資料，假設為 HTTP/0.9"
 
-#: src/http.c:1413
+#: src/http.c:1417
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr "因遇到錯誤而停止使用 SSL。\n"
 
-#: src/http.c:1566
+#: src/http.c:1570
 #, c-format
 msgid "POST data file `%s' missing: %s\n"
 msgstr "載有 POST 資料的檔案 ‘%s’ 不見了：%s\n"
 
-#: src/http.c:1615
+#: src/http.c:1619
 #, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "繼續使用和 %s:%d 的連線。\n"
 
-#: src/http.c:1683
+#: src/http.c:1687
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "無法讀取代理伺服器回應: %s。\n"
 
-#: src/http.c:1703
+#: src/http.c:1707
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr "無法透過代理伺服器進行 tunneling: %s"
 
-#: src/http.c:1748
+#: src/http.c:1752
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "已送出 %s 要求，正在等候回應... "
 
-#: src/http.c:1759
+#: src/http.c:1763
 msgid "No data received.\n"
 msgstr "收不到資料。\n"
 
-#: src/http.c:1766
+#: src/http.c:1770
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "讀取標頭時發生錯誤 (%s)。\n"
 
-#: src/http.c:1812
+#: src/http.c:1816 src/http.c:2368
 #, c-format
 msgid ""
 "File `%s' already there; not retrieving.\n"
