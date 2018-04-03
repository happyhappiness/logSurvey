msgid "Resolving %s... "
msgstr "Пошук %s... "

#: src/host.c:762
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:785
msgid "failed: timed out.\n"
msgstr "збой: скончыўся час.\n"

#: src/html-url.c:289
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr ""

#: src/html-url.c:696
#, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr ""

#: src/http.c:368
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "Памылка запісу HTTP зварота: %s.\n"

#: src/http.c:737
msgid "No headers, assuming HTTP/0.9"
msgstr "Адсутнічаюць загалоўкі; верагодна, HTTP/0.9"

#: src/http.c:1414
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1567
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr ""

#: src/http.c:1616
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "Паўторнае выкарыстаньне далучэньня да %s:%hu.\n"

#: src/http.c:1684
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "Памылка чытаньня адказу проксі: %s.\n"

#: src/http.c:1704
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "Збой проксі-тунэлю: %s"

#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s зварот дасланы, чакаецца адказ... "

#: src/http.c:1760
msgid "No data received.\n"
msgstr "Даныя не атрыманы.\n"

#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Памылка чытаньня (%s) у загалоўках.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr ""
"Файл \"%s\" ужо тут і ня будзе выцягвацца.\n"
"\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr "Невядомая схема аўтарызаваньня.\n"

#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr "Збой аўтарызаваньня.\n"

#: src/http.c:2011
msgid "Malformed status line"
msgstr "Дрэннаскладзены радок стану"

#: src/http.c:2013
msgid "(no description)"
msgstr "(апісаньне адсутнічае)"

#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "Знаходжаньне: %s%s\n"

#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "незаданы"

#: src/http.c:2078
msgid " [following]"
msgstr ""

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
