 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: ���ץ����ϰ�����ɬ�פȤ��ޤ� -- %c\n"
 
-#: src/host.c:438
-#, c-format
-msgid "%s: Cannot determine user-id.\n"
-msgstr "%s: user-id�����Ǥ��ޤ���\n"
-
-#: src/host.c:450
-#, c-format
-msgid "%s: Warning: uname failed: %s\n"
-msgstr "%s: �ٹ�: uname�˼��Ԥ��ޤ���: %s\n"
-
-#: src/host.c:462
-#, c-format
-msgid "%s: Warning: gethostname failed\n"
-msgstr "%s: �ٹ�: gethostname�˼��Ԥ��ޤ���\n"
-
-#: src/host.c:490
-#, c-format
-msgid "%s: Warning: cannot determine local IP address.\n"
-msgstr "%s: �ٹ�: ������IP���ɥ쥹�����Ǥ��ޤ���\n"
-
-#: src/host.c:504
-#, c-format
-msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
-msgstr "%s: �ٹ�: ������IP���ɥ쥹�εհ������Ǥ��ޤ���\n"
-
-#. This gets ticked pretty often.  Karl Berry reports
-#. that there can be valid reasons for the local host
-#. name not to be an FQDN, so I've decided to remove the
-#. annoying warning.
-#: src/host.c:517
-#, c-format
-msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
-msgstr "%s: �ٹ�: �����륢�ɥ쥹�εհ�����̤�FQDN�ǤϤ���ޤ���!\n"
-
-#: src/host.c:545
+#: src/host.c:374
 msgid "Host not found"
 msgstr "�ۥ��Ȥ����Ĥ���ޤ���"
 
-#: src/host.c:547
+#: src/host.c:376
 msgid "Unknown error"
 msgstr "�����ʥ��顼�Ǥ�"
 
-#: src/html.c:615 src/html.c:617
-#, c-format
-msgid "Index of /%s on %s:%d"
-msgstr "/%s (%s:%d ��)�θ��Ф�(index)�Ǥ�"
+#. this is fatal
+#: src/http.c:555
+msgid "Failed to set up an SSL context\n"
+msgstr "SSL context�ν����˼��Ԥ��ޤ�����\n"
 
-#: src/html.c:639
-msgid "time unknown       "
-msgstr "���֤������Ǥ�       "
+#: src/http.c:561
+#, c-format
+msgid "Failed to load certificates from %s\n"
+msgstr "%s ����ξ�������ɤ߹��ߤ˼��Ԥ��ޤ�����\n"
 
-#: src/html.c:643
-msgid "File        "
-msgstr "�ե�����        "
+#: src/http.c:565 src/http.c:573
+msgid "Trying without the specified certificate\n"
+msgstr "���ꤵ�줿������ʤ��ǻ�ߤޤ���\n"
 
-#: src/html.c:646
-msgid "Directory   "
-msgstr "�ǥ��쥯�ȥ�   "
+#: src/http.c:569
+#, c-format
+msgid "Failed to get certificate key from %s\n"
+msgstr "%s ����ξ�����θ����ɤ߹��ߤ˼��Ԥ��ޤ�����\n"
 
-#: src/html.c:649
-msgid "Link        "
-msgstr "���        "
+#: src/http.c:663 src/http.c:1593
+msgid "Unable to establish SSL connection.\n"
+msgstr "SSL �ˤ����³����Ω�Ǥ��ޤ���\n"
 
-#: src/html.c:652
-msgid "Not sure    "
-msgstr "�Գμ�    "
-
-#: src/html.c:670
+#: src/http.c:671
 #, c-format
-msgid " (%s bytes)"
-msgstr " (%s �Х���)"
+msgid "Reusing connection to %s:%hu.\n"
+msgstr "%s:%hu �ؤ���³������Ѥ��ޤ���\n"
 
-#: src/http.c:512
-msgid "Failed writing HTTP request.\n"
-msgstr "HTTP �ˤ����³�׵�������˼��Ԥ��ޤ�����\n"
+#: src/http.c:861
+#, c-format
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "HTTP �ˤ����³�׵�������˼��Ԥ��ޤ���: %s\n"
 
-#: src/http.c:516
+#: src/http.c:866
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s �ˤ����³�׵���������ޤ������������ԤäƤ��ޤ�... "
 
-#: src/http.c:555
+#: src/http.c:910
 msgid "End of file while parsing headers.\n"
 msgstr "�إå��β�����˽�ü�ޤǤ��Ƥ��ޤ��ޤ�����\n"
 
-#: src/http.c:566
+#: src/http.c:920
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "�إå�����ɤ߹��ߥ��顼(%s)�Ǥ�\n"
 
-#: src/http.c:606
+#: src/http.c:959
 msgid "No data received"
 msgstr "�ǡ�������������ޤ���Ǥ���"
 
-#: src/http.c:608
+#: src/http.c:961
 msgid "Malformed status line"
 msgstr "��̯�ʥ��ơ������ԤǤ�"
 
-#: src/http.c:613
+#: src/http.c:966
 msgid "(no description)"
 msgstr "(�����ʤ�)"
 
-#. If we have tried it already, then there is not point
-#. retrying it.
-#: src/http.c:697
+#: src/http.c:1089
 msgid "Authorization failed.\n"
 msgstr "ǧ�ڤ˼��Ԥ��ޤ�����\n"
 
-#: src/http.c:704
+#: src/http.c:1096
 msgid "Unknown authentication scheme.\n"
 msgstr "������ǧ�ڷ����Ǥ���\n"
 
-#: src/http.c:787
+#: src/http.c:1136
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "���: %s%s\n"
 
-#: src/http.c:788 src/http.c:813
+#: src/http.c:1137 src/http.c:1269
 msgid "unspecified"
 msgstr "����Ǥ��ޤ���"
 
-#: src/http.c:789
+#: src/http.c:1138
 msgid " [following]"
 msgstr " [³��]"
 
+#: src/http.c:1200
+msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
+msgstr "\n    ���Υե�����ϴ�����������������äƤ��ޤ������⤹�뤳�ȤϤ���ޤ���\n\n"
+
+#: src/http.c:1216
+#, c-format
+msgid ""
+"\n"
+"Continued download failed on this file, which conflicts with `-c'.\n"
+"Refusing to truncate existing file `%s'.\n"
+"\n"
+msgstr ""
+"\n"
+"���椫��Υ�������ɤ˼��Ԥ��ޤ����Τǡ�`-c'��ͭ����Ư���ޤ���\n"
+"����¸�ߤ��Ƥ���ե����� `%s' ���ڤ�Ĥ�Ϥ��ޤ���\n"
+"\n"
+
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:803
+#: src/http.c:1259
 msgid "Length: "
 msgstr "Ĺ��: "
 
-#: src/http.c:808
+#: src/http.c:1264
 #, c-format
 msgid " (%s to go)"
 msgstr " (�Τ���%s)"
 
-#: src/http.c:813
+#: src/http.c:1269
 msgid "ignored"
 msgstr "̵�뤷�ޤ���"
 
-#: src/http.c:914
+#: src/http.c:1399
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "�ٹ�: HTTP�ϥ磻��ɥ����ɤ��б����Ƥ��ޤ���\n"
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:935
+#: src/http.c:1417
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "�ե����� `%s' �Ϥ��Ǥ�¸�ߤ���Τǡ�ž�����ޤ���\n"
 
-#: src/http.c:1085
+#: src/http.c:1585
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "`%s' (%s)�ؽ񤭹���ޤ���\n"
 
-#: src/http.c:1096
+#: src/http.c:1602
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "���顼: ��꤬¸�ߤ��ʤ�������쥯�����(%d)�Ǥ���\n"
 
-#: src/http.c:1121
+#: src/http.c:1630
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s ���顼 %d: %s��\n"
 
-#: src/http.c:1134
+#: src/http.c:1642
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr "Last-modified �إå�������ޤ��� -- ���դ�̵���ˤ��ޤ���\n"
 
-#: src/http.c:1142
+#: src/http.c:1650
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr "Last-modified �إå���̵���Ǥ� -- ���դ�̵�뤷�ޤ���\n"
 
-#: src/http.c:1177
+#: src/http.c:1673
+#, c-format
+msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
+msgstr "������¦�Υե������������Υե����� `%s' �������������ΤǼ������ޤ���\n\n"
+
+#: src/http.c:1680
+#, c-format
+msgid "The sizes do not match (local %ld) -- retrieving.\n"
+msgstr "�礭�������ʤ��Τ�(������� %ld)��ž�����ޤ���\n"
+
+#: src/http.c:1684
 msgid "Remote file is newer, retrieving.\n"
 msgstr "��⡼�ȥե�����Τۤ����������Τǡ�ž�����ޤ���\n"
 
-#: src/http.c:1222
+#: src/http.c:1728
 #, c-format
-msgid ""
-"%s (%s) - `%s' saved [%ld/%ld]\n"
-"\n"
-msgstr ""
-"%s (%s) - `%s' ����¸���ޤ��� [%ld/%ld]\n"
-"\n"
+msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
+msgstr "%s (%s) - `%s' ����¸���ޤ��� [%ld/%ld]\n\n"
 
-#: src/http.c:1270
+#: src/http.c:1774
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld. "
 msgstr "%s (%s) - %ld �Х��Ȥ���³����λ���ޤ����� "
 
-#: src/http.c:1278
+#: src/http.c:1782
 #, c-format
-msgid ""
-"%s (%s) - `%s' saved [%ld/%ld])\n"
-"\n"
-msgstr ""
-"%s (%s) - `%s' ����¸���ޤ��� [%ld/%ld])\n"
-"\n"
+msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
+msgstr "%s (%s) - `%s' ����¸���ޤ��� [%ld/%ld])\n\n"
 
-#: src/http.c:1298
+#: src/http.c:1801
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld/%ld. "
 msgstr "%s (%s) - %ld/%ld �Х��Ȥ���³����λ���ޤ����� "
 
-#: src/http.c:1309
+#: src/http.c:1812
 #, c-format
 msgid "%s (%s) - Read error at byte %ld (%s)."
 msgstr "%s (%s) - %ld �Х��Ȥ��ɤ߹��ߥ��顼�Ǥ� (%s)��"
 
-#: src/http.c:1317
+#: src/http.c:1820
 #, c-format
 msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
 msgstr "%s (%s) - %ld/%ld �Х��Ȥ��ɤ߹��ߥ��顼�Ǥ� (%s)�� "
 
-#: src/init.c:329 src/netrc.c:260
+#: src/init.c:349 src/netrc.c:267
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
 msgstr "%s: %s (%s)���ɤ߹���ޤ���\n"
 
-#: src/init.c:347 src/init.c:353
+#: src/init.c:367 src/init.c:373
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
 msgstr "%s: %s ��� %d �Ԥǥ��顼�Ǥ�\n"
 
-#: src/init.c:384
+#: src/init.c:405
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
 msgstr "%s: �ٹ�: �����ƥ�ȥ桼����wgetrc��ξ���� `%s' ����ꤷ�Ƥ��ޤ���\n"
 
-#: src/init.c:476
+#: src/init.c:497
 #, c-format
 msgid "%s: BUG: unknown command `%s', value `%s'.\n"
 msgstr "%s: �Х�: `%s' ��������̿��Ǥ����ͤ� `%s' �Ǥ���\n"
 
-#: src/init.c:497
+#: src/init.c:529
 #, c-format
 msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
 msgstr "%s: %s: `%s' ��IP���ɥ쥹���Ѵ��Ǥ��ޤ���\n"
 
-#: src/init.c:525
+#: src/init.c:559
 #, c-format
 msgid "%s: %s: Please specify on or off.\n"
 msgstr "%s: %s: on��off������ꤷ�Ƥ���������\n"
 
-#: src/init.c:569
+#: src/init.c:603
 #, c-format
 msgid "%s: %s: Please specify always, on, off, or never.\n"
 msgstr "%s: %s: always, on, off�ޤ���never�Τ����줫����ꤷ�Ƥ���������\n"
 
-#: src/init.c:588 src/init.c:845 src/init.c:867 src/init.c:931
+#: src/init.c:622 src/init.c:919 src/init.c:941 src/init.c:1005
 #, c-format
 msgid "%s: %s: Invalid specification `%s'.\n"
 msgstr "%s: %s: ̵���ʻ��� `%s' �Ǥ���\n"
 
-#: src/init.c:701 src/init.c:723 src/init.c:745 src/init.c:771
+#: src/init.c:775 src/init.c:797 src/init.c:819 src/init.c:845
 #, c-format
 msgid "%s: Invalid specification `%s'\n"
 msgstr "%s: ̵���ʻ��� `%s' �Ǥ���\n"
 
-#: src/main.c:106
+#: src/main.c:120
 #, c-format
 msgid "Usage: %s [OPTION]... [URL]...\n"
 msgstr "�Ȥ���: %s [���ץ����]... [URL]...\n"
 
-#: src/main.c:114
+#: src/main.c:128
 #, c-format
 msgid "GNU Wget %s, a non-interactive network retriever.\n"
 msgstr "GNU Wget %s, ������Ū�ͥåȥ��ž�����ե�\n"
 
 #. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
 #. don't bitch.  Also, it makes translation much easier.
-#: src/main.c:119
-msgid ""
-"\n"
-"Mandatory arguments to long options are mandatory for short options too.\n"
-"\n"
-msgstr ""
-"\n"
-"Ĺ�����ץ������Բķ�ʰ�����û�����ץ����Ǥ��Բķ�Ǥ���\n"
-"\n"
+#: src/main.c:133
+msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
+msgstr "\nĹ�����ץ������Բķ�ʰ�����û�����ץ����Ǥ��Բķ�Ǥ���\n\n"
 
-#: src/main.c:122
+#: src/main.c:137
 msgid ""
 "Startup:\n"
 "  -V,  --version           display the version of Wget and exit.\n"
