# FIXME: This message can be followed by "%d %s", which prints
# the operation status code and error message.  I don't see how
# can I make this look right in Hebrew...
#: src/http.c:1749
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "...����� ����� ����� ,����� %s ����� "

#: src/http.c:1760
#, fuzzy
msgid "No data received.\n"
msgstr "��� ����� ������ ��"

#: src/http.c:1767
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr ".������ ����� ��� (%s) ����\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1813
#, fuzzy, c-format
msgid ""
"File `%s' already there; not retrieving.\n"
"\n"
msgstr ".���� ����� ���� ��� ,��� ��� `%s' ����\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1966
msgid "Unknown authentication scheme.\n"
msgstr ".�����-���� ����� ����\n"

#: src/http.c:1997
msgid "Authorization failed.\n"
msgstr ".������ ���� �����\n"

#: src/http.c:2011
msgid "Malformed status line"
msgstr "���� ���� �� ���� ����"

#: src/http.c:2013
msgid "(no description)"
msgstr "(�����-���� ����)"

# Pay attention: the translation of "unspecified" goes to the
# left of this, the translation of "[following]" goes to the right.
#: src/http.c:2076
#, c-format
msgid "Location: %s%s\n"
msgstr "%s :���� ����� �����%s\n"

#: src/http.c:2077 src/http.c:2184
msgid "unspecified"
msgstr "unspecified"

#: src/http.c:2078
msgid " [following]"
msgstr " ��� ����"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:2134
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
