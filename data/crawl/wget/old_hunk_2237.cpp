msgid "Reusing existing connection to %s:%d.\n"
msgstr "�������� ������������ ��'���� � %s:%hu.\n"

#: src/http.c:1684
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "������� ������ HTTP-������: %s.\n"

#: src/http.c:1704
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s-����� ��Ħ�����, �ަ�դ� צ���צĦ... "

#: src/http.c:1760
#, fuzzy
msgid "No data received.\n"
msgstr "�� �������� �����"

#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "������� ������� � ���������� (%s).\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, fuzzy, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr "���� `%s' ��� � ���, �� ��������դ��.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr "��צ���� ����� �������Ʀ��æ�.\n"

#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr "��������æ� ���������.\n"

#: src/http.c:2011
msgid "Malformed status line"
msgstr "������������� ��������� �����"

#: src/http.c:2013
msgid "(no description)"
msgstr "(��� �����)"

#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "�����a: %s%s\n"

#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "�� �������"

#: src/http.c:2078
msgid " [following]"
msgstr " [����Ȧ�]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
