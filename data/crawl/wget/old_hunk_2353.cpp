#: src/http.c:1566
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr ""

#: src/http.c:1615
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Đang dùng lại kết nối đã có tới %s: %d.\n"

#: src/http.c:1684
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Đọc câu trả lời proxy không thành công: %s.\n"

#: src/http.c:1704
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Tạo đường hầm proxy không thành công: %s"

#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s yêu cầu đã gửi, đang đợi câu trả lời... "

#: src/http.c:1760
msgid "No data received.\n"
msgstr "Không nhận được dữ liệu.\n"

#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Lỗi đọc (%s) trong phần đầu.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, fuzzy, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr "Tập tin `%s' đã có ở đó, không nhận nữa.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr "Hệ thống xác thực không rõ.\n"

#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr "Xác thực không thành công.\n"

#: src/http.c:2011
msgid "Malformed status line"
msgstr "Dòng trạng thái bị lỗi"

#: src/http.c:2013
msgid "(no description)"
msgstr "(không mô tả)"

#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "Vị trí: %s%s\n"

#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "chưa chỉ ra"

#: src/http.c:2078
msgid " [following]"
msgstr " [theo sau]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
