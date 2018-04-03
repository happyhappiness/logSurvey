msgid "Reusing existing connection to %s:%d.\n"
msgstr "再使用到 %s:%hu 的连接。\n"

#: src/http.c:1684
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "无法写入 HTTP 请求：%s。\n"

#: src/http.c:1704
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "已发出 %s 请求，正在等待回应... "

#: src/http.c:1760
#, fuzzy
msgid "No data received.\n"
msgstr "没有接收到数据"

#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "读取文件头错误 (%s)。\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, fuzzy, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr "文件“%s”已经存在，不取回。\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr "未知的验证方式。\n"

#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr "验证失败。\n"

#: src/http.c:2011
msgid "Malformed status line"
msgstr "不正常的状态行"

#: src/http.c:2013
msgid "(no description)"
msgstr "(没有描述)"

#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "位置：%s%s\n"

#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "未指定"

#: src/http.c:2078
msgid " [following]"
msgstr " [跟随至新的 URL]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
