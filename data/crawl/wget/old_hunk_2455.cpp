#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1606
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr ".`%s' ������ ������ ���\n"

#: src/ftp.c:1671
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "`%s'-� ����� ���� %ld ������ HTML ������ ����� �����\n"

#: src/ftp.c:1676
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "`%s'-� ����� HTML ������ ����� �����\n"

#: src/getopt.c:454
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s ����� ���� �����-�� ���� `%s' ������\n"

#: src/getopt.c:478
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s ����� ���� ������� ���� ���� `--%s' ������\n"

#: src/getopt.c:483
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s ����� ���� ������� ���� ���� `%c%s' ������\n"

#: src/getopt.c:498
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s ����� ���� ������� ����� `%s' ������\n"

#. --option
#: src/getopt.c:528
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s ����� �\"� ���� ���� `--%s' ������\n"

#. +option or -option
#: src/getopt.c:532
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s ����� �\"� ���� ���� `%c%s' ������\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:563
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: ����-���� ������ -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:602
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: ������� ����� ������ -- %c\n"

#: src/host.c:374
msgid "Host not found"
msgstr "���� �� ���� ����"

#: src/host.c:376
msgid "Unknown error"
msgstr "�����-���� ����"

#. this is fatal
#: src/http.c:555
msgid "Failed to set up an SSL context\n"
msgstr "(SSL) ������ ����� ����� ������ ����\n"

#: src/http.c:561
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "%s-� (certificates) ����� ����� ������ ����\n"

#: src/http.c:565 src/http.c:573
msgid "Trying without the specified certificate\n"
msgstr "����� ����� ���� ��� ������ �����\n"

#: src/http.c:569
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "%s-� ����� ���� ����� ����\n"

#: src/http.c:663 src/http.c:1593
msgid "Unable to establish SSL connection.\n"
msgstr ".(SSL) ������ ��� ���� ����� ���� ��\n"

#: src/http.c:671
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr ".%s:%hu-� ������ ������ �����\n"

#: src/http.c:861
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr ".HTTP ����� �� ������ (%s) ����\n"

# FIXME: This message can be followed by "%d %s", which prints
# the operation status code and error message.  I don't see how
# can I make this look right in Hebrew...
#: src/http.c:866
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "...����� ����� ����� ,����� %s ����� "

#: src/http.c:910
msgid "End of file while parsing headers.\n"
msgstr ".������� ����� ��� ��� ��� ���\n"

#: src/http.c:920
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr ".������ ����� ��� (%s) ����\n"

#: src/http.c:959
msgid "No data received"
msgstr "��� ����� ������ ��"

#: src/http.c:961
msgid "Malformed status line"
msgstr "���� ���� �� ���� ����"

#: src/http.c:966
msgid "(no description)"
msgstr "(�����-���� ����)"

#: src/http.c:1089
msgid "Authorization failed.\n"
msgstr ".������ ���� �����\n"

#: src/http.c:1096
msgid "Unknown authentication scheme.\n"
msgstr ".�����-���� ����� ����\n"

# Pay attention: the translation of "unspecified" goes to the
# left of this, the translation of "[following]" goes to the right.
#: src/http.c:1136
#, c-format
msgid "Location: %s%s\n"
msgstr "%s :���� ����� �����%s\n"

#: src/http.c:1137 src/http.c:1269
msgid "unspecified"
msgstr "unspecified"

#: src/http.c:1138
msgid " [following]"
msgstr " ��� ����"

#: src/http.c:1200
msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
msgstr "\n  .����� ������ ��� ��� ;���� ��� ����� �� ����� �� �����\n\n"

#: src/http.c:1216
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""
"\n"
",����� `-c' ������� ���� .����� �� ���� �� ����-�����\n"
".`%s' ���� ���� ����� �������� ���\n"
"\n"

# The next 3 messages are printed in order on the same line, and
