 #: src/http.c:1566
 #, c-format
 msgid "POST data file `%s' missing: %s\n"
-msgstr ""
+msgstr "Thiếu tập tin dữ liệu POST « %s »: %s\n"
 
 #: src/http.c:1615
 #, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Đang dùng lại kết nối đã có tới %s: %d.\n"
 
-#: src/http.c:1684
+#: src/http.c:1683
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "Đọc câu trả lời proxy không thành công: %s.\n"
 
-#: src/http.c:1704
+#: src/http.c:1703
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr "Tạo đường hầm proxy không thành công: %s"
 
-#: src/http.c:1749
+#: src/http.c:1748
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s yêu cầu đã gửi, đang đợi câu trả lời... "
 
-#: src/http.c:1760
+#: src/http.c:1759
 msgid "No data received.\n"
 msgstr "Không nhận được dữ liệu.\n"
 
-#: src/http.c:1767
+#: src/http.c:1766
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Lỗi đọc (%s) trong phần đầu.\n"
 
-#. If opt.noclobber is turned on and file already exists, do not
-#. retrieve the file
-#: src/http.c:1813
-#, fuzzy, c-format
+#: src/http.c:1812
+#, c-format
 msgid ""
 "File `%s' already there; not retrieving.\n"
 "\n"
-msgstr "Tập tin `%s' đã có ở đó, không nhận nữa.\n"
+msgstr ""
+"Tập tin `%s' đã có ở đó nên không nhận nữa.\n"
+"\n"
 
-#. If the authentication header is missing or
-#. unrecognized, there's no sense in retrying.
-#: src/http.c:1966
+#: src/http.c:1965
 msgid "Unknown authentication scheme.\n"
 msgstr "Hệ thống xác thực không rõ.\n"
 
-#: src/http.c:1997
+#: src/http.c:1996
 msgid "Authorization failed.\n"
 msgstr "Xác thực không thành công.\n"
 
-#: src/http.c:2011
+#: src/http.c:2010
 msgid "Malformed status line"
 msgstr "Dòng trạng thái bị lỗi"
 
-#: src/http.c:2013
+#: src/http.c:2012
 msgid "(no description)"
 msgstr "(không mô tả)"
 
-#: src/http.c:2076
+#: src/http.c:2075
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Vị trí: %s%s\n"
 
-#: src/http.c:2077 src/http.c:2184
+#: src/http.c:2076 src/http.c:2183
 msgid "unspecified"
 msgstr "chưa chỉ ra"
 
-#: src/http.c:2078
+#: src/http.c:2077
 msgid " [following]"
 msgstr " [theo sau]"
 
-#. If `-c' is in use and the file has been fully downloaded (or
-#. the remote file has shrunk), Wget effectively requests bytes
-#. after the end of file and the server response with 416.
-#: src/http.c:2134
+#: src/http.c:2133
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
