#
msgid ""
msgstr ""
"Project-Id-Version: GNU Wget 1.6\n"
"POT-Creation-Date: 2001-01-03 16:11+0900\n"
"PO-Revision-Date: 2001-01-03 17:04+09:00\n"
"Last-Translator: Hiroshi Takekawa <takekawa@sr3.t.u-tokyo.ac.jp>\n"
"Language-Team: Japanese <ja@li.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=EUC-JP\n"
"Content-Transfer-Encoding: 8bit\n"

#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:152 src/http.c:352
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "%s:%hu ����³���Ƥ��ޤ�... "

#: src/ftp.c:174 src/ftp.c:416 src/http.c:369
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "%s:%hu �ؤ���³�ϵ��ݤ���ޤ�����\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:195 src/http.c:380
msgid "connected!\n"
msgstr "��³���ޤ���!\n"

#: src/ftp.c:196
#, c-format
msgid "Logging in as %s ... "
msgstr "%s �Ȥ��ƥ����󤷤Ƥ��ޤ�... "

#: src/ftp.c:205 src/ftp.c:258 src/ftp.c:306 src/ftp.c:358 src/ftp.c:452
#: src/ftp.c:525 src/ftp.c:573 src/ftp.c:621
msgid "Error in server response, closing control connection.\n"
msgstr "�����Фα����˥��顼������Τǡ���³��λ���ޤ���\n"

#: src/ftp.c:213
msgid "Error in server greeting.\n"
msgstr "�����Фν�������˥��顼������ޤ���\n"

#: src/ftp.c:221 src/ftp.c:267 src/ftp.c:315 src/ftp.c:367 src/ftp.c:462
#: src/ftp.c:535 src/ftp.c:583 src/ftp.c:631
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

#: src/ftp.c:275
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "`%c' �������ʼ���ʤΤǡ���³��λ���ޤ���\n"

#: src/ftp.c:288
msgid "done.  "
msgstr "��λ���ޤ�����  "

#: src/ftp.c:294
msgid "==> CWD not needed.\n"
msgstr "==> CWD ��ɬ�פ���ޤ���\n"

#: src/ftp.c:322
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"`%s' �Ȥ����ǥ��쥯�ȥ�Ϥ���ޤ���\n"
"\n"

#: src/ftp.c:336 src/ftp.c:604 src/ftp.c:652 src/url.c:1678
msgid "done.\n"
msgstr "��λ���ޤ�����\n"

#. do not CWD
#: src/ftp.c:340
msgid "==> CWD not required.\n"
msgstr "==> CWD ��ɬ�פ���ޤ���\n"

#: src/ftp.c:374
msgid "Cannot initiate PASV transfer.\n"
msgstr "PASVž���ν�������Ǥ��ޤ���\n"

#: src/ftp.c:378
msgid "Cannot parse PASV response.\n"
msgstr "PASV�α�������ϤǤ��ޤ���\n"

#: src/ftp.c:392
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "%s:%hu �ؤ���³���ߤޤ���\n"

#: src/ftp.c:437 src/ftp.c:509 src/ftp.c:553
msgid "done.    "
msgstr "��λ���ޤ�����    "

#: src/ftp.c:479
#, c-format
msgid "Bind error (%s).\n"
msgstr "�Х���ɥ��顼�Ǥ� (%s)��\n"

#: src/ftp.c:495
msgid "Invalid PORT.\n"
msgstr "̵���ʥݡ����ֹ�Ǥ���\n"

#: src/ftp.c:542
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"REST�˼��Ԥ��ޤ������ǽ餫��Ϥ�ޤ���\n"

#: src/ftp.c:591
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"`%s' �Ȥ����ե�����Ϥ���ޤ���\n"
"\n"

#: src/ftp.c:639
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"`%s' �Ȥ����ե�����ޤ��ϥǥ��쥯�ȥ�Ϥ���ޤ���\n"
"\n"

#: src/ftp.c:715 src/ftp.c:722
#, c-format
msgid "Length: %s"
msgstr "Ĺ��: %s"

#: src/ftp.c:717 src/ftp.c:724
#, c-format
msgid " [%s to go]"
msgstr " [�Τ��� %s]"

#: src/ftp.c:726
msgid " (unauthoritative)\n"
msgstr " (�ξڤϤ���ޤ���)\n"

#: src/ftp.c:752
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s����³��λ���ޤ���\n"

#: src/ftp.c:760
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - �ǡ�����³: %s; "

#: src/ftp.c:777
msgid "Control connection closed.\n"
msgstr "�����Ѥ���³�����Ǥ��ޤ���\n"

#: src/ftp.c:795
msgid "Data transfer aborted.\n"
msgstr "�ǡ���ž�������Ǥ��ޤ�����\n"

#: src/ftp.c:859
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "�ե����� `%s' �Ϥ��Ǥ�¸�ߤ���Τǡ��������ޤ���\n"

#: src/ftp.c:920 src/http.c:1018
#, c-format
msgid "(try:%2d)"
msgstr "(���:%2d)"

#: src/ftp.c:984 src/http.c:1248
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' ����¸���ޤ��� [%ld]\n"
"\n"

#: src/ftp.c:1026 src/main.c:753 src/recur.c:472 src/retr.c:564
#, c-format
msgid "Removing %s.\n"
msgstr "%s �������ޤ�����\n"

#: src/ftp.c:1067
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "����ե������ꥹ�Ȥ��뤿��� `%s' ����Ѥ��ޤ���\n"

#: src/ftp.c:1079
#, c-format
msgid "Removed `%s'.\n"
msgstr "`%s' �������ޤ�����\n"

#: src/ftp.c:1115
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "�Ƶ����뿼�� %d �������ͤ�Ķ�ᤷ�Ƥ��ޤ��������� %d �Ǥ���\n"

#: src/ftp.c:1167 src/http.c:1165
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr "������¦�Υե������������Υե����� `%s' �������������ΤǼ������ޤ���\n\n"

#: src/ftp.c:1173 src/http.c:1173
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "�礭�������ʤ��Τ�(������� %ld)��ž�����ޤ���\n"

#: src/ftp.c:1190
msgid "Invalid name of the symlink, skipping.\n"
msgstr "�����ʥ���ܥ�å����̾�ʤΤǡ��ȤФ��ޤ���\n"

#: src/ftp.c:1207
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"���Ǥ� %s -> %s �Ȥ�������������ܥ�å���󥯤�����ޤ�\n"
"\n"

#: src/ftp.c:1215
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "%s -> %s �Ȥ�������ܥ�å���󥯤�������Ƥ��ޤ�\n"

#: src/ftp.c:1226
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr ""
"����ܥ�å���󥯤��б����Ƥ��ʤ��Τǡ�����ܥ�å���� `%s' "
"��ȤФ��ޤ���\n"

#: src/ftp.c:1238
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "�ǥ��쥯�ȥ� `%s' ��ȤФ��ޤ���\n"

#: src/ftp.c:1247
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: �����ʤޤ����б����Ƥ��ʤ��ե�����μ���Ǥ���\n"

#: src/ftp.c:1274
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: ���դ�����Ƥ��ޤ���\n"

#: src/ftp.c:1295
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "������ %d (���� %d)�ʤΤǥǥ��쥯�ȥ��ž�����ޤ���\n"

#: src/ftp.c:1334
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "��������Ƥ��뤫�ޤޤ�Ƥ��ʤ��Τ� `%s' �˰�ư���ޤ���\n"

#: src/ftp.c:1379
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "`%s' ��������ޤ���\n"
