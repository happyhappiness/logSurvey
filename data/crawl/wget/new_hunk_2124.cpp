"Đã có liên kết mềm đúng %s -> %s\n"
"\n"

#: src/ftp.c:1494
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "Đang tạo liên kết mềm %s -> %s\n"

#: src/ftp.c:1504
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "Không hỗ trợ liên kết mềm, nhảy qua liên kết mềm `%s'.\n"

#: src/ftp.c:1516
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "Nhảy qua thư mục `%s'.\n"

#: src/ftp.c:1525
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: loại tập tin không biết/không hỗ trợ.\n"

#: src/ftp.c:1552
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: tem đánh dấu thời gian bị lỗi.\n"

#: src/ftp.c:1580
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "Sẽ không nhận thư mục vì độ sâu là %d (max %d).\n"

#: src/ftp.c:1630
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "Không giảm xuống thành `%s' vì nó bị loại bỏ/không được thêm.\n"

#: src/ftp.c:1696 src/ftp.c:1710
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "Đang nhả ra `%s'.\n"

#: src/ftp.c:1733
#, fuzzy, c-format
msgid "Error matching %s against %s: %s\n"
msgstr "Lỗi ghi nhớ tới `%s': %s\n"

#: src/ftp.c:1774
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Không có tương ứng với mẫu `%s'.\n"

#: src/ftp.c:1840
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Đã viết chỉ mục ở dạng HTML tới `%s' [%s].\n"

#: src/ftp.c:1845
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Đã viết chỉ mục ở dạng HTML tới `%s'.\n"

#: src/host.c:348
msgid "Unknown host"
msgstr "Máy không rõ"

#: src/host.c:352
msgid "Temporary failure in name resolution"
msgstr "Thất bại tạm thời khi tìm tên"

#: src/host.c:354
msgid "Unknown error"
msgstr "Lỗi không rõ nguyên nhân"

#: src/host.c:715
#, c-format
msgid "Resolving %s... "
msgstr "Đang tìm %s... "

#: src/host.c:762
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "thất bại: Không có địa chỉ IPv4/IPv6 cho máy.\n"

#: src/host.c:785
msgid "failed: timed out.\n"
msgstr "không thành công: vượt quá thời gian chờ.\n"

#: src/html-url.c:289
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Không tìm thấy được liên kết không hoàn chỉnh %s.\n"

#: src/html-url.c:696
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: URL không hợp lệ %s: %s\n"

#: src/http.c:368
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Yêu cầu ghi HTTP không thành công: %s.\n"

#: src/http.c:737
msgid "No headers, assuming HTTP/0.9"
msgstr "Không có phần đầu, coi như HTTP/0.9"

#: src/http.c:1417
msgid "Disabling SSL due to encountered errors.\n"
msgstr "Tắt bỏ SSL vì tạo ra lỗi.\n"

#: src/http.c:1570
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "Thiếu tập tin dữ liệu POST « %s »: %s\n"

#: src/http.c:1619
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Đang dùng lại kết nối đã có tới %s: %d.\n"

#: src/http.c:1687
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Đọc câu trả lời proxy không thành công: %s.\n"

#: src/http.c:1707
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Tạo đường hầm proxy không thành công: %s"

#: src/http.c:1752
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s yêu cầu đã gửi, đang đợi câu trả lời... "

#: src/http.c:1763
msgid "No data received.\n"
msgstr "Không nhận được dữ liệu.\n"

#: src/http.c:1770
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Lỗi đọc (%s) trong phần đầu.\n"

#: src/http.c:1816 src/http.c:2368
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
