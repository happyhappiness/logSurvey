msgid "Unknown error"
msgstr "�����ʥ��顼�Ǥ�"

#: src/http.c:625 src/http.c:1437
msgid "Unable to establish SSL connection.\n"
msgstr ""

#: src/http.c:633
#, fuzzy, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "%s:%hu �ؤ���³���ߤƤ��ޤ���\n"

#: src/http.c:809
#, fuzzy, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "HTTP �ˤ����³�׵�������˼��Ԥ��ޤ�����\n"

#: src/http.c:814
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s �ˤ����³�׵���������ޤ������������ԤäƤ��ޤ�... "

#: src/http.c:858
msgid "End of file while parsing headers.\n"
msgstr "�إå��β�����˥ե�����ν�ü�ˤʤ�ޤ�����\n"

#: src/http.c:869
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "�إå�����ɤ߹��ߥ��顼(%s)�Ǥ�\n"

#: src/http.c:909
msgid "No data received"
msgstr "�ǡ�������������ޤ���Ǥ���"

#: src/http.c:911
msgid "Malformed status line"
msgstr "��̯�ʾ��֤Ǥ�"

#: src/http.c:916
msgid "(no description)"
msgstr "(�����ʤ�)"

#: src/http.c:1034
msgid "Authorization failed.\n"
msgstr "ǧ�ڤ˼��Ԥ��ޤ�����\n"

#: src/http.c:1041
msgid "Unknown authentication scheme.\n"
msgstr "������ǧ�ڷ����Ǥ���\n"

#: src/http.c:1131
#, c-format
msgid "Location: %s%s\n"
msgstr "���: %s%s\n"

#: src/http.c:1132 src/http.c:1157
msgid "unspecified"
msgstr "����Ǥ��ޤ���"

#: src/http.c:1133
msgid " [following]"
msgstr " [³��]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1147
msgid "Length: "
msgstr "Ĺ��: "

#: src/http.c:1152
#, c-format
msgid " (%s to go)"
msgstr " (�Τ���%s)"

#: src/http.c:1157
msgid "ignored"
msgstr "̵�뤷�ޤ���"

#: src/http.c:1258
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "�ٹ�: HTTP�ϥ磻��ɥ����ɤ��б����Ƥ��ޤ���\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1279
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "�ե����� `%s' �Ϥ��Ǥ�¸�ߤ���Τǡ�ž�����ޤ���\n"

#: src/http.c:1429
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "`%s' (%s)�ؽ񤭹���ޤ���\n"

#: src/http.c:1447
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "���顼: ��꤬¸�ߤ��ʤ���ǥ��쥯�����(%d)�Ǥ���\n"

#: src/http.c:1472
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ���顼 %d: %s��\n"

#: src/http.c:1485
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Last-modified �إå�������ޤ��� -- ���դ�̵���ˤ��ޤ���\n"

#: src/http.c:1493
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Last-modified �إå���̵���Ǥ� -- ���դ�̵�뤷�ޤ���\n"

#: src/http.c:1528
msgid "Remote file is newer, retrieving.\n"
msgstr "��⡼�ȥե�����Τۤ����������Τǡ�ž�����ޤ���\n"

#: src/http.c:1573
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
