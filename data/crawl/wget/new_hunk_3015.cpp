#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1819
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "���ŦX�˦���%s���C\n"

#: src/ftp.c:1885
#, fuzzy, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "�N HTML �ƪ����޼g�J��%s��[%ld]�C\n"

#: src/ftp.c:1890
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "�N HTML �ƪ����޼g�J��%s���C\n"

#. Still not enough randomness, most likely because neither
#. /dev/random nor EGD were available.  Resort to a simple and
#. stupid method -- seed OpenSSL's PRNG with libc PRNG.  This is
#. cryptographically weak, but people who care about strong
#. cryptography should install /dev/random (default on Linux) or
#. specify their own source of randomness anyway.
#: src/gen_sslfunc.c:109
msgid "Warning: using a weak random seed.\n"
msgstr ""

#: src/gen_sslfunc.c:166
msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
msgstr "�L�k���� OpenSSL �üƲ��͵{�� (PRNG) �ϥΪ��üƺؤl�F�Ȱ��ϥ� SSL�C\n"

#: src/gen_sslfunc.c:223
msgid "Warning: validation of server certificate not possible!\n"
msgstr ""

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s�G�ﶵ��%s���O�����T��\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s�G�ﶵ��--%s���������Ѽ�\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s�G�ﶵ��%c%s���������Ѽ�\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s�G�ﶵ��%s���ݭn�Ѽ�\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s�G�L�k�ѧO�ﶵ��--%s��\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s�G�L�k�ѧO�ﶵ��%c%s��\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s�G���X�k���ﶵ �w %c\n"

#: src/getopt.c:785
#, fuzzy, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s�G���X�k���ﶵ �w %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s�G�ﶵ�ݭn�Ѽ� �w %c\n"

#: src/getopt.c:862
#, fuzzy, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s�G�ﶵ��%s���O�����T��\n"

#: src/getopt.c:880
#, fuzzy, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s�G�ﶵ��--%s���������Ѽ�\n"

#: src/host.c:368
#, fuzzy
msgid "Unknown host"
msgstr "���������~"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:372
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:374
msgid "Unknown error"
msgstr "���������~"

#: src/host.c:748
#, c-format
msgid "Resolving %s... "
msgstr "���b�d��D�� %s... "

#: src/host.c:792 src/host.c:839
#, c-format
msgid "failed: %s.\n"
msgstr "���ѡG%s�C\n"

#: src/host.c:801
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:842
#, fuzzy
msgid "failed: timed out.\n"
msgstr "���ѡG%s�C\n"

#: src/html-url.c:297
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s�G�L�k�ѪR�����㪺�Ÿ��s�� %s�C\n"

#: src/http.c:349 src/http.c:1504
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "�L�k�g�J HTTP �n�D�G%s�C\n"

#: src/http.c:663
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#. this is fatal
#: src/http.c:1151
msgid "Failed to set up an SSL context\n"
msgstr "�L�k�إ� SSL context\n"

#: src/http.c:1156
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "�L�k�� %s ���J�{���ɡ]certificate�^\n"

#: src/http.c:1159 src/http.c:1166
msgid "Trying without the specified certificate\n"
msgstr "���դ����J���w���{���ɡ]certificate�^\n"

#: src/http.c:1163
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "�L�k�� %s ���J�����{���ɪ��_��\n"

#: src/http.c:1382
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "�A�ϥγs�� %s:%hu ���s�u�C\n"

#: src/http.c:1434
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "�L�k�g�J HTTP �n�D�G%s�C\n"

#: src/http.c:1443
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "�L�k�g�J HTTP �n�D�G%s�C\n"

#: src/http.c:1463
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1510
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "�w�e�X %s �n�D�A���b���Ԧ^��... "

#: src/http.c:1521
#, fuzzy
msgid "No data received.\n"
msgstr "�S��������"

#: src/http.c:1528
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "Ū�����Y�ɵo�Ϳ��~(%s)�C\n"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:1595
msgid "Authorization failed.\n"
msgstr "�{�ҥ��ѡI\n"

#: src/http.c:1609
msgid "Unknown authentication scheme.\n"
msgstr "�{�Ҥ覡���ԡC\n"

#: src/http.c:1634
msgid "Malformed status line"
msgstr "�����`�����A��"

#: src/http.c:1636
msgid "(no description)"
msgstr "(�S���y�z)"

#: src/http.c:1700
#, c-format
msgid "Location: %s%s\n"
msgstr "��m�G%s%s\n"

#: src/http.c:1701 src/http.c:1801
msgid "unspecified"
msgstr "�����w"

#: src/http.c:1702
msgid " [following]"
msgstr " [���H�s��]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1751
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
