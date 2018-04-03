#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1698
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "没有与模式“%s”相符合的。\n"

#: src/ftp.c:1764
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "已经将 HTML 格式的索引写入到“%s” [%ld]。\n"

#: src/ftp.c:1769
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "已经将 HTML 格式的索引写入到“%s”。\n"

#: src/gen_sslfunc.c:117
msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
msgstr "无法产生 OpenSSL 随机数产生程序(PRNG)使用的种子；禁用 SSL。\n"

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s：选项“%s”不明确\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s：选项“--%s”不允许有参数\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s：选项“%c%s”不允许有参数\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s：选项“%s”需要参数\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s：无法识别的选项“--%s”\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s：无法识别的选项“%c%s”\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s：非法选项 -- %c\n"

#: src/getopt.c:785
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s：无效选项 -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s：选项需要参数 -- %c\n"

#: src/getopt.c:862
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s：选项“-W %s”不明确\n"

#: src/getopt.c:880
#, c-format
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
