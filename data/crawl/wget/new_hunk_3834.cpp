"Content-Type: text/plain; charset=EUC-JP\n"
"Content-Transfer-Encoding: 8bit\n"

#: src/ftp-ls.c:698 src/ftp-ls.c:700
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "/%s (%s:%d ��)�θ��Ф�(index)�Ǥ�"

#: src/ftp-ls.c:722
msgid "time unknown       "
msgstr "���֤������Ǥ�       "

#: src/ftp-ls.c:726
msgid "File        "
msgstr "�ե�����        "

#: src/ftp-ls.c:729
msgid "Directory   "
msgstr "�ǥ��쥯�ȥ�   "

#: src/ftp-ls.c:732
msgid "Link        "
msgstr "���        "

#: src/ftp-ls.c:735
msgid "Not sure    "
msgstr "�Գμ�    "

#: src/ftp-ls.c:753
#, c-format
msgid " (%s bytes)"
msgstr " (%s �Х���)"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:152 src/http.c:582
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "%s:%hu ����³���Ƥ��ޤ�... "

#: src/ftp.c:174 src/ftp.c:520 src/http.c:599
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "%s:%hu �ؤ���³�˼��Ԥ��ޤ�����\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:195 src/http.c:610
msgid "connected!\n"
msgstr "��³���ޤ���!\n"

#: src/ftp.c:196
#, c-format
msgid "Logging in as %s ... "
msgstr "%s �Ȥ��ƥ����󤷤Ƥ��ޤ�... "

#: src/ftp.c:205 src/ftp.c:258 src/ftp.c:289 src/ftp.c:314 src/ftp.c:410
#: src/ftp.c:462 src/ftp.c:556 src/ftp.c:629 src/ftp.c:677 src/ftp.c:725
msgid "Error in server response, closing control connection.\n"
msgstr "�����Фα����˥��顼������Τǡ���³��λ���ޤ���\n"

#: src/ftp.c:213
msgid "Error in server greeting.\n"
msgstr "�����Фν�������˥��顼������ޤ���\n"

#: src/ftp.c:221 src/ftp.c:323 src/ftp.c:419 src/ftp.c:471 src/ftp.c:566
#: src/ftp.c:639 src/ftp.c:687 src/ftp.c:735
msgid "Write failed, closing control connection.\n"
msgstr "�񤭹��ߤ˼��Ԥ����Τǡ���³��λ���ޤ���\n"

#: src/ftp.c:228
msgid "The server refuses login.\n"
msgstr "�����Ф����������ݤ��ޤ�����\n"

#: src/ftp.c:235
msgid "Login incorrect.\n"
msgstr "������˼��Ԥ��ޤ�����\n"

#: src/ftp.c:242
msgid "Logged in!\n"
msgstr "�����󤷤ޤ���!\n"

#: src/ftp.c:267
msgid "Server error, can't determine system type.\n"
msgstr ""

#: src/ftp.c:277 src/ftp.c:541 src/ftp.c:613 src/ftp.c:657
msgid "done.    "
msgstr "��λ���ޤ�����    "

#: src/ftp.c:303 src/ftp.c:440 src/ftp.c:708 src/ftp.c:756 src/url.c:1432
msgid "done.\n"
msgstr "��λ���ޤ�����\n"

#: src/ftp.c:331
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "`%c' �������ʼ���ʤΤǡ���³��λ���ޤ���\n"

#: src/ftp.c:344
msgid "done.  "
msgstr "��λ���ޤ�����  "

#: src/ftp.c:350
msgid "==> CWD not needed.\n"
msgstr "==> CWD ��ɬ�פ���ޤ���\n"

#: src/ftp.c:426
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"`%s' �Ȥ����ǥ��쥯�ȥ�Ϥ���ޤ���\n"
"\n"

#. do not CWD
#: src/ftp.c:444
msgid "==> CWD not required.\n"
msgstr "==> CWD ��ɬ�פ���ޤ���\n"

#: src/ftp.c:478
msgid "Cannot initiate PASV transfer.\n"
msgstr "PASVž���ν�������Ǥ��ޤ���\n"

#: src/ftp.c:482
msgid "Cannot parse PASV response.\n"
msgstr "PASV�α�������ϤǤ��ޤ���\n"

#: src/ftp.c:496
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "%s:%hu �ؤ���³���ߤƤ��ޤ���\n"

#: src/ftp.c:583
#, c-format
msgid "Bind error (%s).\n"
msgstr "�Х���ɥ��顼�Ǥ� (%s)��\n"

#: src/ftp.c:599
msgid "Invalid PORT.\n"
msgstr "̵���ʥݡ����ֹ�Ǥ���\n"

#: src/ftp.c:646
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"REST�˼��Ԥ��ޤ������ǽ餫��Ϥ�ޤ���\n"

#: src/ftp.c:695
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"`%s' �Ȥ����ե�����Ϥ���ޤ���\n"
"\n"

#: src/ftp.c:743
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"`%s' �Ȥ����ե�����ޤ��ϥǥ��쥯�ȥ�Ϥ���ޤ���\n"
"\n"

#: src/ftp.c:819 src/ftp.c:826
#, c-format
msgid "Length: %s"
msgstr "Ĺ��: %s"

#: src/ftp.c:821 src/ftp.c:828
#, c-format
msgid " [%s to go]"
msgstr " [�Τ��� %s]"

#: src/ftp.c:830
msgid " (unauthoritative)\n"
msgstr " (ɬ���������ΤǤϤ���ޤ���)\n"

#: src/ftp.c:856
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s����³��λ���ޤ���\n"

#: src/ftp.c:864
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - �ǡ�����³: %s; "

#: src/ftp.c:881
msgid "Control connection closed.\n"
msgstr "��³��λ���ޤ���\n"

#: src/ftp.c:899
msgid "Data transfer aborted.\n"
msgstr "�ǡ���ž�������Ǥ��ޤ�����\n"

#: src/ftp.c:963
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "�ե����� `%s' �Ϥ��Ǥ�¸�ߤ���Τǡ�ž�����ޤ���\n"

#: src/ftp.c:1024 src/http.c:1358
#, c-format, ycp-format
msgid "(try:%2d)"
msgstr "(���:%2d)"

#: src/ftp.c:1088 src/http.c:1585
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' ����¸���ޤ��� [%ld]\n"
"\n"

#: src/ftp.c:1130 src/main.c:771 src/recur.c:505 src/retr.c:580
#, c-format
msgid "Removing %s.\n"
msgstr "%s �������ޤ�����\n"

#: src/ftp.c:1171
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "����ե������ꥹ�Ȥ��뤿��� `%s' ����Ѥ��ޤ���\n"

#: src/ftp.c:1183
#, c-format
msgid "Removed `%s'.\n"
msgstr "`%s' �������ޤ�����\n"

#: src/ftp.c:1219
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "�Ƶ����뿼�� %d �������ͤ�Ķ�ᤷ�Ƥ��ޤ��������� %d �Ǥ���\n"

#: src/ftp.c:1271 src/http.c:1512
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""

#: src/ftp.c:1279
msgid "Cannot compare sizes, remote system is VMS.\n"
msgstr ""

#: src/ftp.c:1285 src/http.c:1520
#, fuzzy, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "�礭�������ʤ��Τ�(������� %ld)��ž�����ޤ���\n"

#: src/ftp.c:1303
msgid "Invalid name of the symlink, skipping.\n"
msgstr "�����ʥ���ܥ�å����̾�ʤΤǡ��ȤФ��ޤ���\n"

#: src/ftp.c:1320
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"���Ǥ� %s -> %s �Ȥ�������������ܥ�å���󥯤�����ޤ�\n"
"\n"

#: src/ftp.c:1328
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "%s -> %s �Ȥ�������ܥ�å���󥯤�������Ƥ��ޤ�\n"

#: src/ftp.c:1339
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr ""
"����ܥ�å���󥯤��б����Ƥ��ʤ��Τǡ�����ܥ�å���� `%s' "
"��ȤФ��ޤ���\n"

#: src/ftp.c:1351
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "�ǥ��쥯�ȥ� `%s' ��ȤФ��ޤ���\n"

#: src/ftp.c:1360
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: �����ʤޤ����б����Ƥ��ʤ��ե�����μ���Ǥ���\n"

#: src/ftp.c:1377
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: ���դ�����Ƥ��ޤ���\n"

#: src/ftp.c:1398
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "������ %d (���� %d)�ʤΤǥǥ��쥯�ȥ��ž�����ޤ���\n"

#: src/ftp.c:1437
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "��������Ƥ��뤫�ޤޤ�Ƥ��ʤ��Τ� `%s' �˰�ư���ޤ���\n"

#: src/ftp.c:1482
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "`%s' ��������ޤ���\n"
