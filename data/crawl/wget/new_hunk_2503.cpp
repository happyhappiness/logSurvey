#  --option
#  --option
#. --option
#: src/getopt.c:747
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: �����Ц������ �������� `--%s'\n"

#  +option or -option
#. +option or -option
#: src/getopt.c:751
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: �����Ц������ �������� `%c%s'\n"

#  1003.2 specifies the format of this message.
#. 1003.2 specifies the format of this message.
#: src/getopt.c:777
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: ��צ���� �������� -- %c\n"

#: src/getopt.c:780
#, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: ��צ���� �������� -- %c\n"

#  1003.2 specifies the format of this message.
#. 1003.2 specifies the format of this message.
#: src/getopt.c:810 src/getopt.c:940
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: ��������� ����Ȧ���� �������� -- %c\n"

#: src/getopt.c:857
#, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: ������������� �������� `-W %s'\n"

#: src/getopt.c:875
#, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: �������� `-W %s' �� ���� ���� ���������\n"

#: src/host.c:347
#, fuzzy
msgid "Unknown host"
msgstr "��צ���� �������"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:351
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:353
msgid "Unknown error"
msgstr "��צ���� �������"

#: src/host.c:714
#, c-format
msgid "Resolving %s... "
msgstr "���������� ���Φ %s... "

#: src/host.c:761
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:784
msgid "failed: timed out.\n"
msgstr "�������: ����-���.\n"

#: src/html-url.c:288
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: �� ���� ��ڦ����� ������� ��������� %s.\n"

#: src/html-url.c:695
#, fuzzy, c-format
msgid "%s: Invalid URL %s: %s\n"
msgstr "%s: %s: ��צ��� �������� `%s'.\n"

#: src/http.c:367
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "������� ������ HTTP-������: %s.\n"

#: src/http.c:736
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1413
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1566
#, c-format
msgid "POST data file `%s' missing: %s\n"
msgstr ""

#: src/http.c:1615
#, fuzzy, c-format
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
