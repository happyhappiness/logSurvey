msgid "No headers, assuming HTTP/0.9"
msgstr "��������� �����������, ��������������� HTTP/0.9"

#: src/http.c:1204
msgid "Disabling SSL due to encountered errors.\n"
msgstr "SSL ����������� ��-�� �������������� ������.\n"

#: src/http.c:1374
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr "����������� ���� POST-������ `%s': %s\n"

#: src/http.c:1423
#, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "��������� ������������� ���������� � %s:%d.\n"

#: src/http.c:1492
#, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "���� ������ ������ ������: %s.\n"

#: src/http.c:1512
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr "���� �������������� ������: %s"

#: src/http.c:1557
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "������ %s ������, ��������� �����... "

#: src/http.c:1568
msgid "No data received.\n"
msgstr "�� �������� ������� ������.\n"

#: src/http.c:1575
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "������ ������ (%s) � ����������.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1660
msgid "Unknown authentication scheme.\n"
msgstr "����������� ����� ��������������.\n"

#: src/http.c:1684
msgid "Authorization failed.\n"
msgstr "���� �����������.\n"

#: src/http.c:1698
msgid "Malformed status line"
msgstr "�������� ������ �������"

#: src/http.c:1700
msgid "(no description)"
msgstr "(��� ��������)"

#: src/http.c:1763
#, c-format
msgid "Location: %s%s\n"
msgstr "�����: %s%s\n"

#: src/http.c:1764 src/http.c:1871
msgid "unspecified"
msgstr "��� ����������"

#: src/http.c:1765
msgid " [following]"
msgstr " [�������]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1821
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
