msgid "%s: option requires an argument -- %c\n"
msgstr "%s: ���ץ����ϰ�����ɬ�פȤ��ޤ� -- %c\n"

#: src/host.c:438
#, c-format
msgid "%s: Cannot determine user-id.\n"
msgstr "%s: user-id�����Ǥ��ޤ���\n"

#: src/host.c:450
#, c-format
msgid "%s: Warning: uname failed: %s\n"
msgstr "%s: �ٹ�: uname�˼��Ԥ��ޤ���: %s\n"

#: src/host.c:462
#, c-format
msgid "%s: Warning: gethostname failed\n"
msgstr "%s: �ٹ�: gethostname�˼��Ԥ��ޤ���\n"

#: src/host.c:490
#, c-format
msgid "%s: Warning: cannot determine local IP address.\n"
msgstr "%s: �ٹ�: ������IP���ɥ쥹�����Ǥ��ޤ���\n"

#: src/host.c:504
#, c-format
msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
msgstr "%s: �ٹ�: ������IP���ɥ쥹�εհ������Ǥ��ޤ���\n"

#. This gets ticked pretty often.  Karl Berry reports
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
"\n"
msgstr ""
"%s (%s) - `%s' ����¸���ޤ��� [%ld/%ld]\n"
"\n"

#: src/http.c:1270
#, c-format
msgid "%s (%s) - Connection closed at byte %ld. "
msgstr "%s (%s) - %ld �Х��Ȥ���³����λ���ޤ����� "

#: src/http.c:1278
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld])\n"
"\n"
msgstr ""
"%s (%s) - `%s' ����¸���ޤ��� [%ld/%ld])\n"
"\n"

#: src/http.c:1298
#, c-format
msgid "%s (%s) - Connection closed at byte %ld/%ld. "
msgstr "%s (%s) - %ld/%ld �Х��Ȥ���³����λ���ޤ����� "

#: src/http.c:1309
#, c-format
msgid "%s (%s) - Read error at byte %ld (%s)."
msgstr "%s (%s) - %ld �Х��Ȥ��ɤ߹��ߥ��顼�Ǥ� (%s)��"

#: src/http.c:1317
#, c-format
msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
msgstr "%s (%s) - %ld/%ld �Х��Ȥ��ɤ߹��ߥ��顼�Ǥ� (%s)�� "

#: src/init.c:329 src/netrc.c:260
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: %s (%s)���ɤ߹���ޤ���\n"

#: src/init.c:347 src/init.c:353
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: %s ��� %d �Ԥǥ��顼�Ǥ�\n"

#: src/init.c:384
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr "%s: �ٹ�: �����ƥ�ȥ桼����wgetrc��ξ���� `%s' ����ꤷ�Ƥ��ޤ���\n"

#: src/init.c:476
#, c-format
msgid "%s: BUG: unknown command `%s', value `%s'.\n"
msgstr "%s: �Х�: `%s' ��������̿��Ǥ����ͤ� `%s' �Ǥ���\n"

#: src/init.c:497
#, c-format
msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
msgstr "%s: %s: `%s' ��IP���ɥ쥹���Ѵ��Ǥ��ޤ���\n"

#: src/init.c:525
#, c-format
msgid "%s: %s: Please specify on or off.\n"
msgstr "%s: %s: on��off������ꤷ�Ƥ���������\n"

#: src/init.c:569
#, c-format
msgid "%s: %s: Please specify always, on, off, or never.\n"
msgstr "%s: %s: always, on, off�ޤ���never�Τ����줫����ꤷ�Ƥ���������\n"

#: src/init.c:588 src/init.c:845 src/init.c:867 src/init.c:931
#, c-format
msgid "%s: %s: Invalid specification `%s'.\n"
msgstr "%s: %s: ̵���ʻ��� `%s' �Ǥ���\n"

#: src/init.c:701 src/init.c:723 src/init.c:745 src/init.c:771
#, c-format
msgid "%s: Invalid specification `%s'\n"
msgstr "%s: ̵���ʻ��� `%s' �Ǥ���\n"

#: src/main.c:106
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "�Ȥ���: %s [���ץ����]... [URL]...\n"

#: src/main.c:114
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, ������Ū�ͥåȥ��ž�����ե�\n"

#. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
#. don't bitch.  Also, it makes translation much easier.
#: src/main.c:119
msgid ""
"\n"
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"Ĺ�����ץ������Բķ�ʰ�����û�����ץ����Ǥ��Բķ�Ǥ���\n"
"\n"

#: src/main.c:122
msgid ""
"Startup:\n"
"  -V,  --version           display the version of Wget and exit.\n"
