msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s：选项“-W %s”不允许有参数\n"

#: src/host.c:636
#, c-format
msgid "Resolving %s... "
msgstr "正在解析主机 %s... "

#: src/host.c:656 src/host.c:672
#, c-format
msgid "failed: %s.\n"
msgstr "失败：%s。\n"

#: src/host.c:674
msgid "failed: timed out.\n"
msgstr "失败：超时。\n"

#: src/host.c:762
msgid "Host not found"
msgstr "找不到主机"

#: src/host.c:764
msgid "Unknown error"
msgstr "未知的错误"

#: src/html-url.c:293
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s：无法解析不完整的链接 %s。\n"

#. this is fatal
#: src/http.c:674
msgid "Failed to set up an SSL context\n"
msgstr "无法创建 SSL context\n"

#: src/http.c:680
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "无法从 %s 载入证书 (certificate)\n"

#: src/http.c:684 src/http.c:692
msgid "Trying without the specified certificate\n"
msgstr "尝试不载入指定的证书 (certificate)\n"

#: src/http.c:688
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "无法从 %s 获取证书密钥\n"

#: src/http.c:761 src/http.c:1809
msgid "Unable to establish SSL connection.\n"
msgstr "无法建立 SSL 连接。\n"

#: src/http.c:770
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "再使用到 %s:%hu 的连接。\n"

#: src/http.c:1034
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "无法写入 HTTP 请求：%s。\n"

#: src/http.c:1039
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "已发出 %s 请求，正在等待回应... "

#: src/http.c:1083
msgid "End of file while parsing headers.\n"
msgstr "正在分析文件头时，文件已结束。\n"

#: src/http.c:1093
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "读取文件头错误 (%s)。\n"

#: src/http.c:1128
msgid "No data received"
msgstr "没有接收到数据"

#: src/http.c:1130
msgid "Malformed status line"
msgstr "不正常的状态行"

#: src/http.c:1135
msgid "(no description)"
msgstr "(没有描述)"

#: src/http.c:1267
msgid "Authorization failed.\n"
msgstr "验证失败。\n"

#: src/http.c:1274
msgid "Unknown authentication scheme.\n"
msgstr "未知的验证方式。\n"

#: src/http.c:1314
#, c-format
msgid "Location: %s%s\n"
msgstr "位置：%s%s\n"

#: src/http.c:1315 src/http.c:1454
msgid "unspecified"
msgstr "未指定"

#: src/http.c:1316
msgid " [following]"
msgstr " [跟随至新的 URL]"

#: src/http.c:1383
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
