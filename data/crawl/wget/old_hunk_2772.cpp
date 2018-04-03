#: src/http.c:1555
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "已送出 %s 要求，正在等候回應... "

#: src/http.c:1566
#, fuzzy
msgid "No data received.\n"
msgstr "沒有收到資料"

#: src/http.c:1573
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "讀取標頭時發生錯誤(%s)。\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1658
msgid "Unknown authentication scheme.\n"
msgstr "認證方式不詳。\n"

#: src/http.c:1682
msgid "Authorization failed.\n"
msgstr "認證失敗！\n"

#: src/http.c:1696
msgid "Malformed status line"
msgstr "不正常的狀態行"

#: src/http.c:1698
msgid "(no description)"
msgstr "(沒有描述)"

#: src/http.c:1769
#, c-format
msgid "Location: %s%s\n"
msgstr "位置：%s%s\n"

#: src/http.c:1770 src/http.c:1867
msgid "unspecified"
msgstr "未指定"

#: src/http.c:1771
msgid " [following]"
msgstr " [跟隨連結]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
