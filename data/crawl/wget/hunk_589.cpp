 "已经存在正确的符号连接 %s -> %s\n"
 "\n"
 
-#: src/ftp.c:1533
+#: src/ftp.c:1788
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "正在创建符号链接 %s -> %s\n"
 
-#: src/ftp.c:1543
+#: src/ftp.c:1798
 #, fuzzy, c-format
 msgid "Symlinks not supported, skipping symlink %s.\n"
 msgstr "不支持符号连接，正在跳过符号连接“%s”。\n"
 
-#: src/ftp.c:1555
+#: src/ftp.c:1810
 #, fuzzy, c-format
 msgid "Skipping directory %s.\n"
 msgstr "正在跳过目录“%s”。\n"
 
-#: src/ftp.c:1564
+#: src/ftp.c:1819
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s：未知的/不支持的文件类型。\n"
 
-#: src/ftp.c:1591
+#: src/ftp.c:1856
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s：错误的时间戳标记。\n"
 
-#: src/ftp.c:1619
+#: src/ftp.c:1878
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "因为深度为 %d(最大值为 %d)，所以不取回。\n"
 
-#: src/ftp.c:1669
+#: src/ftp.c:1928
 #, fuzzy, c-format
 msgid "Not descending to %s as it is excluded/not-included.\n"
 msgstr "不进入“%s”目录因为已被排除或未被包含进来。\n"
 
-#: src/ftp.c:1735 src/ftp.c:1749
+#: src/ftp.c:1994 src/ftp.c:2008
 #, fuzzy, c-format
 msgid "Rejecting %s.\n"
 msgstr "拒绝“%s”。\n"
 
-#: src/ftp.c:1772
-#, fuzzy, c-format
+#: src/ftp.c:2031
+#, c-format
 msgid "Error matching %s against %s: %s\n"
-msgstr "写入“%s”时发生错误：%s\n"
+msgstr "%s 和 %s 匹配错误: %s\n"
 
-#: src/ftp.c:1814
+#: src/ftp.c:2073
 #, fuzzy, c-format
 msgid "No matches on pattern %s.\n"
 msgstr "没有与模式“%s”相符合的。\n"
 
-#: src/ftp.c:1880
+#: src/ftp.c:2144
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s [%s].\n"
-msgstr "已经将 HTML 格式的索引写入到“%s” [%ld]。\n"
+msgstr "已经将 HTML 格式的索引写入到‘%s’ [%s]。\n"
 
-#: src/ftp.c:1885
+#: src/ftp.c:2149
 #, fuzzy, c-format
 msgid "Wrote HTML-ized index to %s.\n"
 msgstr "已经将 HTML 格式的索引写入到“%s”。\n"
 
-#: src/host.c:348
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "ERROR"
+msgstr "错误"
+
+#: src/gnutls.c:219 src/openssl.c:495
+msgid "WARNING"
+msgstr "警告"
+
+#: src/gnutls.c:225 src/openssl.c:504
+#, c-format
+msgid "%s: No certificate presented by %s.\n"
+msgstr "%s: %s 未提出证书。\n"
+
+#: src/gnutls.c:233
+#, fuzzy, c-format
+msgid "%s: The certificate of %s is not trusted.\n"
+msgstr "%s: %s 未提出证书。\n"
+
+#: src/gnutls.c:239
+#, c-format
+msgid "%s: The certificate of %s hasn't got a known issuer.\n"
+msgstr ""
+
+#: src/gnutls.c:245
+#, fuzzy, c-format
+msgid "%s: The certificate of %s has been revoked.\n"
+msgstr "  颁发的证书已经过期。\n"
+
+#: src/gnutls.c:259
+#, c-format
+msgid "Error initializing X509 certificate: %s\n"
+msgstr ""
+
+#: src/gnutls.c:268
 #, fuzzy
+msgid "No certificate found\n"
+msgstr "%s: %s 未提出证书。\n"
+
+#: src/gnutls.c:275
+#, fuzzy, c-format
+msgid "Error parsing certificate: %s\n"
+msgstr "解析代理服务器 URL %s 时发生错误：%s。\n"
+
+#: src/gnutls.c:282
+#, fuzzy
+msgid "The certificate has not yet been activated\n"
+msgstr "  颁发的证书还未生效。\n"
+
+#: src/gnutls.c:287
+#, fuzzy
+msgid "The certificate has expired\n"
+msgstr "  颁发的证书已经过期。\n"
+
+#: src/gnutls.c:293
+#, fuzzy, c-format
+msgid "The certificate's owner does not match hostname '%s'\n"
+msgstr "%s: 证书通用名‘%s’不匹配所要求的主机名‘%s’。\n"
+
+#: src/host.c:358
 msgid "Unknown host"
-msgstr "未知的错误"
+msgstr "未知的主机"
 
-#: src/host.c:352
+#: src/host.c:362
 msgid "Temporary failure in name resolution"
-msgstr ""
+msgstr "名字解析时有临时错误"
 
-#: src/host.c:354
+#: src/host.c:364
 msgid "Unknown error"
 msgstr "未知的错误"
 
-#: src/host.c:715
+#: src/host.c:737
 #, c-format
 msgid "Resolving %s... "
 msgstr "正在解析主机 %s... "
 
-#: src/host.c:763
+#: src/host.c:789
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
-msgstr ""
+msgstr "失败：主机没有 IPv4/IPv6 地址。\n"
 
-#: src/host.c:786
+#: src/host.c:812
 msgid "failed: timed out.\n"
 msgstr "失败：超时。\n"
 
-#: src/html-url.c:289
+#: src/html-url.c:286
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s：无法解析不完整的链接 %s。\n"
 
-#: src/html-url.c:696
-#, fuzzy, c-format
+#: src/html-url.c:762
+#, c-format
 msgid "%s: Invalid URL %s: %s\n"
-msgstr "%s：%s：无效的值“%s”。\n"
+msgstr "%s：无效的 URL %s: %s\n"
 
-#: src/http.c:368
+#: src/http.c:377
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "无法写入 HTTP 请求：%s。\n"
 
-#: src/http.c:745
+#: src/http.c:754
 msgid "No headers, assuming HTTP/0.9"
-msgstr ""
+msgstr "没有 HTTP 头，尝试 HTTP/0.9"
 
-#: src/http.c:1430
+#: src/http.c:1456
 msgid "Disabling SSL due to encountered errors.\n"
-msgstr ""
+msgstr "由于遭遇错误，将禁用 SSL。\n"
 
-#: src/http.c:1548
-#, c-format
+#: src/http.c:1576
+#, fuzzy, c-format
 msgid "POST data file %s missing: %s\n"
-msgstr ""
+msgstr "缺少 POST 数据文件‘%s’: %s\n"
 
-#: src/http.c:1632
-#, fuzzy, c-format
+#: src/http.c:1660
+#, c-format
 msgid "Reusing existing connection to %s:%d.\n"
-msgstr "再使用到 %s:%hu 的连接。\n"
+msgstr "再次使用存在的到 %s:%d 的连接。\n"
 
-#: src/http.c:1701
-#, fuzzy, c-format
+#: src/http.c:1729
+#, c-format
 msgid "Failed reading proxy response: %s\n"
-msgstr "无法写入 HTTP 请求：%s。\n"
+msgstr "无法读取代理响应：%s\n"
 
-#: src/http.c:1721
+#: src/http.c:1750
 #, c-format
 msgid "Proxy tunneling failed: %s"
-msgstr ""
+msgstr "代理渠道错误: %s"
 
-#: src/http.c:1766
+#: src/http.c:1795
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "已发出 %s 请求，正在等待回应... "
 
-#: src/http.c:1777
-#, fuzzy
+#: src/http.c:1806
 msgid "No data received.\n"
-msgstr "没有接收到数据"
+msgstr "没有接收到数据。\n"
 
-#: src/http.c:1784
+#: src/http.c:1813
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "读取文件头错误 (%s)。\n"
 
-#: src/http.c:1831 src/http.c:2385
-#, fuzzy, c-format
-msgid ""
-"File %s already there; not retrieving.\n"
-"\n"
-msgstr "文件“%s”已经存在，不取回。\n"
-
-#: src/http.c:1985
+#: src/http.c:1884
 msgid "Unknown authentication scheme.\n"
 msgstr "未知的验证方式。\n"
 
-#: src/http.c:2016
+#: src/http.c:1918
 msgid "Authorization failed.\n"
 msgstr "验证失败。\n"
 
-#: src/http.c:2030
+#: src/http.c:1956 src/http.c:2466
+#, fuzzy, c-format
+msgid ""
+"File %s already there; not retrieving.\n"
+"\n"
+msgstr ""
+"文件‘%s’已经存在；不取回。\n"
+"\n"
+
+#: src/http.c:2070
 msgid "Malformed status line"
 msgstr "不正常的状态行"
 
-#: src/http.c:2032
+#: src/http.c:2072
 msgid "(no description)"
 msgstr "(没有描述)"
 
-#: src/http.c:2098
+#: src/http.c:2149
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "位置：%s%s\n"
 
-#: src/http.c:2099 src/http.c:2209
+#: src/http.c:2150 src/http.c:2258
 msgid "unspecified"
 msgstr "未指定"
 
-#: src/http.c:2100
+#: src/http.c:2151
 msgid " [following]"
 msgstr " [跟随至新的 URL]"
 
-#: src/http.c:2156
+#: src/http.c:2203
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
