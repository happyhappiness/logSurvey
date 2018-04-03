#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1775
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "Không có tương ứng với mẫu `%s'.\n"

#: src/ftp.c:1841
#, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "Đã viết chỉ mục ở dạng HTML tới `%s' [%s].\n"

#: src/ftp.c:1846
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "Đã viết chỉ mục ở dạng HTML tới `%s'.\n"

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: tùy chọn `%s' không rõ ràng\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: tùy chọn `--%s' không cho phép một tham số\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: tùy chọn `%c%s' không cho phép một tham số\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: tùy chọn `%s' yêu cầu một tham số\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: tùy chọn không nhận ra `--%s'\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: tùy chọn không nhận ra `%c%s'\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: tùy chọn không hợp lệ -- %c\n"

#: src/getopt.c:785
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: tùy chọn sai -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: tùy chọn yêu cầu một tham số -- %c\n"

#: src/getopt.c:862
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: tùy chọn `-W %s' không rõ ràng\n"

#: src/getopt.c:880
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: tùy chọn `-W %s' không cho phép một tham số\n"

#: src/host.c:371
msgid "Unknown host"
msgstr "Máy không rõ"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:375
msgid "Temporary failure in name resolution"
msgstr "Thất bại tạm thời khi tìm tên"

#: src/host.c:377
msgid "Unknown error"
msgstr "Lỗi không rõ nguyên nhân"

#: src/host.c:756
#, c-format
msgid "Resolving %s... "
msgstr "Đang tìm %s... "

#: src/host.c:800 src/host.c:829
#, c-format
msgid "failed: %s.\n"
msgstr "không thành công: %s.\n"

#: src/host.c:809
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr "thất bại: Không có địa chỉ IPv4/IPv6 cho máy.\n"

#: src/host.c:832
msgid "failed: timed out.\n"
msgstr "không thành công: vượt quá thời gian chờ.\n"

#: src/html-url.c:298
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: Không tìm thấy được liên kết không hoàn chỉnh %s.\n"

#: src/http.c:373 src/http.c:1549
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Yêu cầu ghi HTTP không thành công: %s.\n"

#: src/http.c:687
msgid "No headers, assuming HTTP/0.9"
msgstr "Không có phần đầu, coi như HTTP/0.9"

#: src/http.c:1198
msgid "Disabling SSL due to encountered errors.\n"
msgstr "Tắt bỏ SSL vì tạo ra lỗi.\n"

#: src/http.c:1417
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Đang dùng lại kết nối đã có tới %s: %d.\n"

#: src/http.c:1479
#, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "Ghi tới proxy  không thành công: %s.\n"

#: src/http.c:1488
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Đọc câu trả lời proxy không thành công: %s.\n"

#: src/http.c:1508
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Tạo đường hầm proxy không thành công: %s"

#: src/http.c:1555
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s yêu cầu đã gửi, đang đợi câu trả lời... "

#: src/http.c:1566
msgid "No data received.\n"
msgstr "Không nhận được dữ liệu.\n"

#: src/http.c:1573
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Lỗi đọc (%s) trong phần đầu.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1658
msgid "Unknown authentication scheme.\n"
msgstr "Hệ thống xác thực không rõ.\n"

#: src/http.c:1682
msgid "Authorization failed.\n"
msgstr "Xác thực không thành công.\n"

#: src/http.c:1696
msgid "Malformed status line"
msgstr "Dòng trạng thái bị lỗi"

#: src/http.c:1698
msgid "(no description)"
msgstr "(không mô tả)"

#: src/http.c:1769
#, c-format
msgid "Location: %s%s\n"
msgstr "Vị trí: %s%s\n"

#: src/http.c:1770 src/http.c:1867
msgid "unspecified"
msgstr "chưa chỉ ra"

#: src/http.c:1771
msgid " [following]"
msgstr " [theo sau]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1817
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
