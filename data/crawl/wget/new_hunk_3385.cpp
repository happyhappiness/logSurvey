# Ukrainian messages for GNU Wget.
# Copyright (C) 1999 Free Software Foundation, Inc.
# Olexander Kunytsa <xakep@snark.ukma.kiev.ua>, 2000
#
msgid ""
msgstr ""
"Project-Id-Version: wget 1.8.1\n"
"POT-Creation-Date: 2001-12-17 16:30+0100\n"
"PO-Revision-Date: 2002-03-03 12:53+0200\n"
"Last-Translator: Olexander Kunytsa <xakep@snark.ukma.kiev.ua>\n"
"Language-Team: Ukrainian <translation-team-uk@lists.sourceforge.net>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=koi8-u\n"
"Content-Transfer-Encoding: 8bit\n"

#: src/connect.c:94
#, c-format
msgid "Connecting to %s[%s]:%hu... "
msgstr "������������ �'������� � %s[%s]:%hu... "

#: src/connect.c:97
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "������������ �'������� � %s:%hu... "

#: src/connect.c:131
msgid "connected.\n"
msgstr "Ц�'������.\n"

#: src/cookies.c:595
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "������� � �����, ���� `%s'"

#: src/cookies.c:619
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "����������� ������� � �����, �� �����̦ `%c'.\n"

#: src/cookies.c:627
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "����������� ������� � �����: ���ަ������� ˦���� �����.\n"

#: src/cookies.c:1329
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "�� ���� צ������ ���� � ������ `%s': %s\n"

#: src/cookies.c:1341
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "������� ������ � `%s': %s\n"

#: src/cookies.c:1345
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "������� �������� `%s': %s\n"

#: src/ftp-ls.c:802
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "��� ̦�Ԧ��� ��צ�����, ������ ��ڦ����� � ���̦ ̦������ Unix.\n"

#: src/ftp-ls.c:847 src/ftp-ls.c:849
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "������ �������� /%s �� %s:%d"

#: src/ftp-ls.c:871
msgid "time unknown       "
msgstr "��� ��צ�����      "

#: src/ftp-ls.c:875
msgid "File        "
msgstr "����        "

#: src/ftp-ls.c:878
msgid "Directory   "
msgstr "�������     "

#: src/ftp-ls.c:881
msgid "Link        "
msgstr "���������   "

#: src/ftp-ls.c:884
msgid "Not sure    "
msgstr "�������     "

#: src/ftp-ls.c:902
#, c-format
msgid " (%s bytes)"
msgstr " (%s ����)"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:179
#, c-format
msgid "Logging in as %s ... "
msgstr "�Ť���դ���� �� %s ... "

#: src/ftp.c:188 src/ftp.c:241 src/ftp.c:272 src/ftp.c:326 src/ftp.c:419 src/ftp.c:470 src/ftp.c:500 src/ftp.c:564 src/ftp.c:628 src/ftp.c:689 src/ftp.c:737
msgid "Error in server response, closing control connection.\n"
msgstr "������� � ����æ� �������, �������� ��������� �'�������.\n"

#: src/ftp.c:196
msgid "Error in server greeting.\n"
msgstr "������� � ���צ���Φ �������.\n"

#: src/ftp.c:204 src/ftp.c:335 src/ftp.c:428 src/ftp.c:509 src/ftp.c:574 src/ftp.c:638 src/ftp.c:699 src/ftp.c:747
msgid "Write failed, closing control connection.\n"
msgstr "������� ������, �������� ��������� �'�������.\n"

#: src/ftp.c:211
msgid "The server refuses login.\n"
msgstr "������ צ������ � �Ť����æ�.\n"

#: src/ftp.c:218
msgid "Login incorrect.\n"
msgstr "��'� �� ������ ���������Φ.\n"

#: src/ftp.c:225
msgid "Logged in!\n"
msgstr "�Ť����æ� �������!\n"

#: src/ftp.c:250
msgid "Server error, can't determine system type.\n"
msgstr "������� �������, �� ���� ��������� ��� �������.\n"

#: src/ftp.c:260 src/ftp.c:549 src/ftp.c:612 src/ftp.c:669
msgid "done.    "
msgstr "��������.    "

#: src/ftp.c:314 src/ftp.c:449 src/ftp.c:484 src/ftp.c:720 src/ftp.c:768 src/host.c:283
msgid "done.\n"
msgstr "��������.\n"

#: src/ftp.c:343
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "��צ����� ��� `%c', �������� ��������� �'�������.\n"

#: src/ftp.c:356
msgid "done.  "
msgstr "��������.  "

#: src/ftp.c:362
msgid "==> CWD not needed.\n"
msgstr "==> CWD �� ���Ҧ���.\n"

#: src/ftp.c:435
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr ""
"������� `%s' צ����Φ�.\n"
"\n"

#. do not CWD
#: src/ftp.c:453
msgid "==> CWD not required.\n"
msgstr "==> CWD �� �����������.\n"

#: src/ftp.c:516
msgid "Cannot initiate PASV transfer.\n"
msgstr "�� ���� �Φæ����� PASV-��������.\n"

#: src/ftp.c:520
msgid "Cannot parse PASV response.\n"
msgstr "������� ������������� ���̦�� צ���צĦ PASV.\n"

#: src/ftp.c:541
#, c-format
msgid "couldn't connect to %s:%hu: %s\n"
msgstr "�� ������� Ц�'�������� �� %s:%hu: %s\n"

#: src/ftp.c:591
#, c-format
msgid "Bind error (%s).\n"
msgstr "������� ��'�������� (%s).\n"

#: src/ftp.c:598
msgid "Invalid PORT.\n"
msgstr "��צ���� PORT.\n"

#: src/ftp.c:651
#, c-format
msgid ""
"\n"
"REST failed; will not truncate `%s'.\n"
msgstr ""
"\n"
"������� REST �� �������, �� ��Ҧ����� `%s'.\n"

#: src/ftp.c:658
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"������� REST �� �������, ��������� � ����.\n"

#: src/ftp.c:707
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"���� `%s' צ����Φ�.\n"
"\n"

#: src/ftp.c:755
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"���� �� ������� `%s' צ����Φ�.\n"
"\n"

#: src/ftp.c:839 src/ftp.c:847
#, c-format
msgid "Length: %s"
msgstr "�������: %s"

#: src/ftp.c:841 src/ftp.c:849
#, c-format
msgid " [%s to go]"
msgstr " [%s ����������]"

#: src/ftp.c:851
msgid " (unauthoritative)\n"
msgstr " (�� �����)\n"

#: src/ftp.c:877
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, �������� ��������� �'�������.\n"

#: src/ftp.c:885
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - �'�������: %s; "

#: src/ftp.c:902
msgid "Control connection closed.\n"
msgstr "������� �'������� �������.\n"

#: src/ftp.c:920
msgid "Data transfer aborted.\n"
msgstr "�������� ����� ���������.\n"

#: src/ftp.c:984
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "���� `%s' ��� � ���, �� ��������դ��.\n"

#: src/ftp.c:1054 src/http.c:1527
#, c-format
msgid "(try:%2d)"
msgstr "(������:%2d)"

#: src/ftp.c:1118 src/http.c:1786
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld]\n"
"\n"
msgstr ""
"%s (%s) - `%s' ��������� [%ld]\n"
"\n"

#: src/ftp.c:1160 src/main.c:819 src/recur.c:349 src/retr.c:587
#, c-format
msgid "Removing %s.\n"
msgstr "��������� %s.\n"

#: src/ftp.c:1202
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "������ ���� ��������� � ����������� ���̦ `%s'.\n"

#: src/ftp.c:1217
#, c-format
msgid "Removed `%s'.\n"
msgstr "`%s' ��������.\n"

#: src/ftp.c:1252
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "������� �����Ӧ� %d ���������� ����������� ������� %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1317
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr "��������� ���� `%s' ��צ��� -- �� ��������դ�� ����.\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1324
#, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr ""
"���� `%s' �� �����Ҧ ��צ��� -- ��������դ��.\n"
"\n"

#. Sizes do not match
#: src/ftp.c:1331
#, c-format
msgid ""
"The sizes do not match (local %ld) -- retrieving.\n"
"\n"
msgstr ""
"������� ���̦� �� �Ц�������� (��������: %ld) -- ��������դ��.\n"
"\n"

#: src/ftp.c:1348
msgid "Invalid name of the symlink, skipping.\n"
msgstr "��צ��� ��'� ����������� ���������, ����������.\n"

#: src/ftp.c:1365
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"��������� ��������� %s -> %s ��� ���դ.\n"
"\n"

#: src/ftp.c:1373
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "��������� ��������� ��������� %s -> %s\n"

#: src/ftp.c:1384
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "�������Φ ��������� �� Ц�����������, ����������� `%s'.\n"

#: src/ftp.c:1396
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "����������� ������� `%s'.\n"

#: src/ftp.c:1405
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: ��צ����� ��� ����� (��� �� Ц�����դ����).\n"

#: src/ftp.c:1432
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: ���������� ͦ��� ����.\n"

#: src/ftp.c:1457
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "�� ��������դ�� �������� ��˦���� ������� ��� %d (�������� %d).\n"

#: src/ftp.c:1507
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "����������� ������� `%s' ڦ ������ ����������.\n"

#: src/ftp.c:1561
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "����������� `%s'.\n"
