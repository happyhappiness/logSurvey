msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: ���ץ���� `-W %s' �ϰ�������ޤ���\n"

#: src/host.c:368
#, fuzzy
msgid "Unknown host"
msgstr "�����ʥ��顼�Ǥ�"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:372
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:374
msgid "Unknown error"
msgstr "�����ʥ��顼�Ǥ�"

#: src/host.c:748
#, c-format
msgid "Resolving %s... "
msgstr "%s ��DNS���䤤���碌�Ƥ��ޤ�... "

#: src/host.c:792 src/host.c:839
#, c-format
msgid "failed: %s.\n"
msgstr "���Ԥ��ޤ���: %s.\n"

#: src/host.c:801
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:842
msgid "failed: timed out.\n"
msgstr "���Ԥ��ޤ���: �����ॢ����.\n"

#: src/html-url.c:297
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: �Դ����ʥ�� %s ����Ǥ��ޤ���\n"

#: src/http.c:349 src/http.c:1504
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP �ˤ����³�׵�������˼��Ԥ��ޤ���: %s\n"

#: src/http.c:663
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#. this is fatal
#: src/http.c:1151
msgid "Failed to set up an SSL context\n"
msgstr "SSL context�ν����˼��Ԥ��ޤ�����\n"

#: src/http.c:1156
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "%s ����ξ�������ɤ߹��ߤ˼��Ԥ��ޤ�����\n"

#: src/http.c:1159 src/http.c:1166
msgid "Trying without the specified certificate\n"
msgstr "���ꤵ�줿������ʤ��ǻ�ߤޤ���\n"

#: src/http.c:1163
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "%s ����ξ�����θ����ɤ߹��ߤ˼��Ԥ��ޤ�����\n"

#: src/http.c:1382
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "%s:%hu �ؤ���³������Ѥ��ޤ���\n"

#: src/http.c:1434
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "HTTP �ˤ����³�׵�������˼��Ԥ��ޤ���: %s\n"

#: src/http.c:1443
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "HTTP �ˤ����³�׵�������˼��Ԥ��ޤ���: %s\n"

#: src/http.c:1463
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1510
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s �ˤ����³�׵���������ޤ������������ԤäƤ��ޤ�... "

#: src/http.c:1521
#, fuzzy
msgid "No data received.\n"
msgstr "�ǡ�������������ޤ���Ǥ���"

#: src/http.c:1528
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "�إå�����ɤ߹��ߥ��顼(%s)�Ǥ�\n"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:1595
msgid "Authorization failed.\n"
msgstr "ǧ�ڤ˼��Ԥ��ޤ�����\n"

#: src/http.c:1609
msgid "Unknown authentication scheme.\n"
msgstr "������ǧ�ڷ����Ǥ���\n"

#: src/http.c:1634
msgid "Malformed status line"
msgstr "��̯�ʥ��ơ������ԤǤ�"

#: src/http.c:1636
msgid "(no description)"
msgstr "(�����ʤ�)"

#: src/http.c:1700
#, c-format
msgid "Location: %s%s\n"
msgstr "���: %s%s\n"

#: src/http.c:1701 src/http.c:1801
msgid "unspecified"
msgstr "����Ǥ��ޤ���"

#: src/http.c:1702
msgid " [following]"
msgstr " [³��]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1751
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
