 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Yêu cầu ghi HTTP không thành công: %s.\n"
 
-#: src/http.c:737
+#: src/http.c:745
 msgid "No headers, assuming HTTP/0.9"
 msgstr "Không có phần đầu, coi như HTTP/0.9"
 
-#: src/http.c:1417
+#: src/http.c:1430
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr "Tắt bỏ SSL vì tạo ra lỗi.\n"
 
-#: src/http.c:1570
-#, c-format
-msgid "POST data file `%s' missing: %s\n"
+#: src/http.c:1548
+#, fuzzy, c-format
+msgid "POST data file %s missing: %s\n"
 msgstr "Thiếu tập tin dữ liệu POST « %s »: %s\n"
 
-#: src/http.c:1619
+#: src/http.c:1632
 #, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "Đang dùng lại kết nối đã có tới %s: %d.\n"
 
-#: src/http.c:1687
+#: src/http.c:1701
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "Đọc câu trả lời proxy không thành công: %s.\n"
 
-#: src/http.c:1707
+#: src/http.c:1721
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr "Tạo đường hầm proxy không thành công: %s"
 
-#: src/http.c:1752
+#: src/http.c:1766
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s yêu cầu đã gửi, đang đợi câu trả lời... "
 
-#: src/http.c:1763
+#: src/http.c:1777
 msgid "No data received.\n"
 msgstr "Không nhận được dữ liệu.\n"
 
-#: src/http.c:1770
+#: src/http.c:1784
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Lỗi đọc (%s) trong phần đầu.\n"
 
-#: src/http.c:1816 src/http.c:2368
-#, c-format
+#: src/http.c:1831 src/http.c:2385
+#, fuzzy, c-format
 msgid ""
-"File `%s' already there; not retrieving.\n"
+"File %s already there; not retrieving.\n"
 "\n"
 msgstr ""
 "Tập tin `%s' đã có ở đó nên không nhận nữa.\n"
 "\n"
 
-#: src/http.c:1969
+#: src/http.c:1985
 msgid "Unknown authentication scheme.\n"
 msgstr "Hệ thống xác thực không rõ.\n"
 
-#: src/http.c:2000
+#: src/http.c:2016
 msgid "Authorization failed.\n"
 msgstr "Xác thực không thành công.\n"
 
-#: src/http.c:2014
+#: src/http.c:2030
 msgid "Malformed status line"
 msgstr "Dòng trạng thái bị lỗi"
 
-#: src/http.c:2016
+#: src/http.c:2032
 msgid "(no description)"
 msgstr "(không mô tả)"
 
-#: src/http.c:2082
+#: src/http.c:2098
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Vị trí: %s%s\n"
 
-#: src/http.c:2083 src/http.c:2193
+#: src/http.c:2099 src/http.c:2209
 msgid "unspecified"
 msgstr "chưa chỉ ra"
 
-#: src/http.c:2084
+#: src/http.c:2100
 msgid " [following]"
 msgstr " [theo sau]"
 
-#: src/http.c:2140
+#: src/http.c:2156
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
