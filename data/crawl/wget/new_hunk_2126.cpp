"已经存在正确的符号连接 %s -> %s\n"
"\n"

#: src/ftp.c:1494
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "正在创建符号链接 %s -> %s\n"

#: src/ftp.c:1504
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "不支持符号连接，正在跳过符号连接“%s”。\n"

#: src/ftp.c:1516
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "正在跳过目录“%s”。\n"

#: src/ftp.c:1525
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s：未知的/不支持的文件类型。\n"

#: src/ftp.c:1552
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s：错误的时间戳标记。\n"

#: src/ftp.c:1580
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "因为深度为 %d(最大值为 %d)，所以不取回。\n"

#: src/ftp.c:1630
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "不进入“%s”目录因为已被排除或未被包含进来。\n"

#: src/ftp.c:1696 src/ftp.c:1710
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "拒绝“%s”。\n"

#: src/ftp.c:1733
#, fuzzy, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "写入“%s”时发生错误：%s\n"

#: src/ftp.c:1774
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "没有与模式“%s”相符合的。\n"

#: src/ftp.c:1840
#, fuzzy, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "已经将 HTML 格式的索引写入到“%s” [%ld]。\n"

#: src/ftp.c:1845
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "已经将 HTML 格式的索引写入到“%s”。\n"

#: src/host.c:348
#, fuzzy
msgid "Unknown host"
msgstr "未知的错误"

#: src/host.c:352
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:354
msgid "Unknown error"
msgstr "未知的错误"

#: src/host.c:715
#, c-format
msgid "Resolving %s... "
msgstr "正在解析主机 %s... "

#: src/host.c:762
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:785
msgid "failed: timed out.\n"
msgstr "失败：超时。\n"

#: src/html-url.c:289
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s：无法解析不完整的链接 %s。\n"

#: src/html-url.c:696
#, fuzzy, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s：%s：无效的值“%s”。\n"

#: src/http.c:368
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "无法写入 HTTP 请求：%s。\n"

#: src/http.c:737
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1417
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1570
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr ""

#: src/http.c:1619
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "再使用到 %s:%hu 的连接。\n"

#: src/http.c:1687
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "无法写入 HTTP 请求：%s。\n"

#: src/http.c:1707
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1752
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "已发出 %s 请求，正在等待回应... "

#: src/http.c:1763
#, fuzzy
msgid "No data received.\n"
msgstr "没有接收到数据"

#: src/http.c:1770
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "读取文件头错误 (%s)。\n"

#: src/http.c:1816 src/http.c:2368
#, fuzzy, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr "文件“%s”已经存在，不取回。\n"

#: src/http.c:1969
msgid "Unknown authentication scheme.\n"
msgstr "未知的验证方式。\n"

#: src/http.c:2000
msgid "Authorization failed.\n"
msgstr "验证失败。\n"

#: src/http.c:2014
msgid "Malformed status line"
msgstr "不正常的状态行"

#: src/http.c:2016
msgid "(no description)"
msgstr "(没有描述)"

#: src/http.c:2082
#, c-format
msgid "Location: %s%s\n"
msgstr "位置：%s%s\n"

#: src/http.c:2083 src/http.c:2193
msgid "unspecified"
msgstr "未指定"

#: src/http.c:2084
msgid " [following]"
msgstr " [跟随至新的 URL]"

#: src/http.c:2140
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
