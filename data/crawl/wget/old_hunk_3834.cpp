"Content-Type: text/plain; charset=EUC-JP\n"
"Content-Transfer-Encoding: 8bit\n"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:147 src/http.c:346
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "%s:%hu ����³���Ƥ��ޤ�... "

#: src/ftp.c:169 src/ftp.c:411 src/http.c:363
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "%s:%hu �ؤ���³�˼��Ԥ��ޤ�����\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:190 src/http.c:374
msgid "connected!\n"
msgstr "��³���ޤ���!\n"

#: src/ftp.c:191
#, c-format
msgid "Logging in as %s ... "
msgstr "%s �Ȥ��ƥ����󤷤Ƥ��ޤ�... "

#: src/ftp.c:200 src/ftp.c:253 src/ftp.c:301 src/ftp.c:353 src/ftp.c:447
#: src/ftp.c:520 src/ftp.c:568 src/ftp.c:616
msgid "Error in server response, closing control connection.\n"
msgstr "�����Фα����˥��顼������Τǡ���³��λ���ޤ���\n"

#: src/ftp.c:208
msgid "Error in server greeting.\n"
msgstr "�����Фν�������˥��顼������ޤ���\n"

#: src/ftp.c:216 src/ftp.c:262 src/ftp.c:310 src/ftp.c:362 src/ftp.c:457
#: src/ftp.c:530 src/ftp.c:578 src/ftp.c:626
msgid "Write failed, closing control connection.\n"
msgstr "�񤭹��ߤ˼��Ԥ����Τǡ���³��λ���ޤ���\n"

#: src/ftp.c:223
msgid "The server refuses login.\n"
msgstr "�����Ф����������ݤ��ޤ�����\n"

#: src/ftp.c:230
msgid "Login incorrect.\n"
msgstr "������˼��Ԥ��ޤ�����\n"

#: src/ftp.c:237
msgid "Logged in!\n"
msgstr "�����󤷤ޤ���!\n"

#: src/ftp.c:270
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "`%c' �������ʼ���ʤΤǡ���³��λ���ޤ���\n"

#: src/ftp.c:283
msgid "done.  "
msgstr "��λ���ޤ�����  "

#: src/ftp.c:289
msgid "==> CWD not needed.\n"
msgstr "==> CWD ��ɬ�פ���ޤ���\n"

#: src/ftp.c:317
#, c-format
msgid "No such directory `%s'.\n\n"
msgstr "`%s' �Ȥ����ǥ��쥯�ȥ�Ϥ���ޤ���\n\n"

#: src/ftp.c:331 src/ftp.c:599 src/ftp.c:647 src/url.c:1431
msgid "done.\n"
msgstr "��λ���ޤ�����\n"

#. do not CWD
#: src/ftp.c:335
msgid "==> CWD not required.\n"
msgstr "==> CWD ��ɬ�פ���ޤ���\n"

#: src/ftp.c:369
msgid "Cannot initiate PASV transfer.\n"
msgstr "PASVž���ν�������Ǥ��ޤ���\n"

#: src/ftp.c:373
msgid "Cannot parse PASV response.\n"
msgstr "PASV�α�������ϤǤ��ޤ���\n"

#: src/ftp.c:387
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "%s:%hu �ؤ���³���ߤƤ��ޤ���\n"

#: src/ftp.c:432 src/ftp.c:504 src/ftp.c:548
msgid "done.    "
msgstr "��λ���ޤ�����    "

#: src/ftp.c:474
#, c-format
msgid "Bind error (%s).\n"
msgstr "�Х���ɥ��顼�Ǥ� (%s)��\n"

#: src/ftp.c:490
msgid "Invalid PORT.\n"
msgstr "̵���ʥݡ����ֹ�Ǥ���\n"

#: src/ftp.c:537
msgid "\nREST failed, starting from scratch.\n"
msgstr "\nREST�˼��Ԥ��ޤ������ǽ餫��Ϥ�ޤ���\n"

#: src/ftp.c:586
#, c-format
msgid "No such file `%s'.\n\n"
msgstr "`%s' �Ȥ����ե�����Ϥ���ޤ���\n\n"

#: src/ftp.c:634
#, c-format
msgid "No such file or directory `%s'.\n\n"
msgstr "`%s' �Ȥ����ե�����ޤ��ϥǥ��쥯�ȥ�Ϥ���ޤ���\n\n"

#: src/ftp.c:692 src/ftp.c:699
#, c-format
msgid "Length: %s"
msgstr "Ĺ��: %s"

#: src/ftp.c:694 src/ftp.c:701
#, c-format
msgid " [%s to go]"
msgstr " [�Τ��� %s]"

#: src/ftp.c:703
msgid " (unauthoritative)\n"
msgstr " (ɬ���������ΤǤϤ���ޤ���)\n"

#: src/ftp.c:721
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s����³��λ���ޤ���\n"

#: src/ftp.c:729
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - �ǡ�����³: %s; "

#: src/ftp.c:746
msgid "Control connection closed.\n"
msgstr "��³��λ���ޤ���\n"

#: src/ftp.c:764
msgid "Data transfer aborted.\n"
msgstr "�ǡ���ž�������Ǥ��ޤ�����\n"

#: src/ftp.c:830
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "�ե����� `%s' �Ϥ��Ǥ�¸�ߤ���Τǡ�ž�����ޤ���\n"

#: src/ftp.c:896 src/http.c:922
#, c-format
msgid "(try:%2d)"
msgstr "(���:%2d)"

#: src/ftp.c:955 src/http.c:1116
#, c-format
msgid "%s (%s) - `%s' saved [%ld]\n\n"
msgstr "%s (%s) - `%s' ����¸���ޤ��� [%ld]\n\n"

#: src/ftp.c:1001
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "����ե������ꥹ�Ȥ��뤿��� `%s' ����Ѥ��ޤ���\n"

#: src/ftp.c:1013
#, c-format
msgid "Removed `%s'.\n"
msgstr "`%s' �������ޤ�����\n"

#: src/ftp.c:1049
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "�Ƶ����뿼�� %d �������ͤ�Ķ�ᤷ�Ƥ��ޤ��������� %d �Ǥ���\n"

#: src/ftp.c:1096 src/http.c:1054
#, c-format
msgid "Local file `%s' is more recent, not retrieving.\n\n"
msgstr "������ե����� `%s' �Τۤ����������Τǡ�ž�����ޤ���\n\n"

#: src/ftp.c:1102 src/http.c:1060
#, c-format
msgid "The sizes do not match (local %ld), retrieving.\n"
msgstr "�礭�������ʤ��Τ�(������� %ld)��ž�����ޤ���\n"

#: src/ftp.c:1119
msgid "Invalid name of the symlink, skipping.\n"
msgstr "�����ʥ���ܥ�å����̾�ʤΤǡ��ȤФ��ޤ���\n"

#: src/ftp.c:1136
#, c-format
msgid "Already have correct symlink %s -> %s\n\n"
msgstr "���Ǥ� %s -> %s �Ȥ�������������ܥ�å���󥯤�����ޤ�\n\n"

#: src/ftp.c:1144
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "%s -> %s �Ȥ�������ܥ�å���󥯤�������Ƥ��ޤ�\n"

#: src/ftp.c:1155
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "����ܥ�å���󥯤��б����Ƥ��ʤ��Τǡ�����ܥ�å���� `%s' ��ȤФ��ޤ���\n"

#: src/ftp.c:1167
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "�ǥ��쥯�ȥ� `%s' ��ȤФ��ޤ���\n"

#: src/ftp.c:1176
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: �����ʤޤ����б����Ƥ��ʤ��ե�����μ���Ǥ���\n"

#: src/ftp.c:1193
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: ���դ�����Ƥ��ޤ���\n"

#: src/ftp.c:1213
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "������ %d (���� %d)�ʤΤǥǥ��쥯�ȥ��ž�����ޤ���\n"

#: src/ftp.c:1252
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "��������Ƥ��뤫�ޤޤ�Ƥ��ʤ��Τ� `%s' �˰�ư���ޤ���\n"

#: src/ftp.c:1297
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "`%s' ��������ޤ���\n"
