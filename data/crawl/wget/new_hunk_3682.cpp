#. that there can be valid reasons for the local host
#. name not to be an FQDN, so I've decided to remove the
#. annoying warning.
#: src/host.c:517
#, c-format
msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
msgstr "%s: �ٹ�: �����륢�ɥ쥹�εհ�����̤�FQDN�ǤϤ���ޤ���!\n"

#: src/host.c:545
msgid "Host not found"
msgstr "�ۥ��Ȥ����Ĥ���ޤ���"

#: src/host.c:547
msgid "Unknown error"
msgstr "�����ʥ��顼�Ǥ�"

#: src/html.c:615 src/html.c:617
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "/%s (%s:%d ��)�θ��Ф�(index)�Ǥ�"

#: src/html.c:639
msgid "time unknown       "
msgstr "���֤������Ǥ�       "

#: src/html.c:643
msgid "File        "
msgstr "�ե�����        "

#: src/html.c:646
msgid "Directory   "
msgstr "�ǥ��쥯�ȥ�   "

#: src/html.c:649
msgid "Link        "
msgstr "���        "

#: src/html.c:652
msgid "Not sure    "
msgstr "�Գμ�    "

#: src/html.c:670
#, c-format
msgid " (%s bytes)"
msgstr " (%s �Х���)"

#: src/http.c:512
msgid "Failed writing HTTP request.\n"
msgstr "HTTP �ˤ����³�׵�������˼��Ԥ��ޤ�����\n"

#: src/http.c:516
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "%s �ˤ����³�׵���������ޤ������������ԤäƤ��ޤ�... "

#: src/http.c:555
msgid "End of file while parsing headers.\n"
msgstr "�إå��β�����˽�ü�ޤǤ��Ƥ��ޤ��ޤ�����\n"

#: src/http.c:566
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "�إå�����ɤ߹��ߥ��顼(%s)�Ǥ�\n"

#: src/http.c:606
msgid "No data received"
msgstr "�ǡ�������������ޤ���Ǥ���"

#: src/http.c:608
msgid "Malformed status line"
msgstr "��̯�ʥ��ơ������ԤǤ�"

#: src/http.c:613
msgid "(no description)"
msgstr "(�����ʤ�)"

#. If we have tried it already, then there is not point
#. retrying it.
#: src/http.c:697
msgid "Authorization failed.\n"
msgstr "ǧ�ڤ˼��Ԥ��ޤ�����\n"

#: src/http.c:704
msgid "Unknown authentication scheme.\n"
msgstr "������ǧ�ڷ����Ǥ���\n"

#: src/http.c:787
#, c-format
msgid "Location: %s%s\n"
msgstr "���: %s%s\n"

#: src/http.c:788 src/http.c:813
msgid "unspecified"
msgstr "����Ǥ��ޤ���"

#: src/http.c:789
msgid " [following]"
msgstr " [³��]"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:803
msgid "Length: "
msgstr "Ĺ��: "

#: src/http.c:808
#, c-format
msgid " (%s to go)"
msgstr " (�Τ���%s)"

#: src/http.c:813
msgid "ignored"
msgstr "̵�뤷�ޤ���"

#: src/http.c:914
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "�ٹ�: HTTP�ϥ磻��ɥ����ɤ��б����Ƥ��ޤ���\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:935
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "�ե����� `%s' �Ϥ��Ǥ�¸�ߤ���Τǡ�ž�����ޤ���\n"

#: src/http.c:1085
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "`%s' (%s)�ؽ񤭹���ޤ���\n"

#: src/http.c:1096
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "���顼: ��꤬¸�ߤ��ʤ�������쥯�����(%d)�Ǥ���\n"

#: src/http.c:1121
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ���顼 %d: %s��\n"

#: src/http.c:1134
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "Last-modified �إå�������ޤ��� -- ���դ�̵���ˤ��ޤ���\n"

#: src/http.c:1142
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "Last-modified �إå���̵���Ǥ� -- ���դ�̵�뤷�ޤ���\n"

#: src/http.c:1177
msgid "Remote file is newer, retrieving.\n"
msgstr "��⡼�ȥե�����Τۤ����������Τǡ�ž�����ޤ���\n"

#: src/http.c:1222
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
