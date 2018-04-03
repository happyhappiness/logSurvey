# Greek messages for GNU wget.
# Copyright (C) 1999, 2000, 2001, 2002 Free Software Foundation, Inc.
# Simos Xenitellis <simos@hellug.gr>, 1999, 2000, 2001, 2002.
#
msgid ""
msgstr ""
"Project-Id-Version: wget 1.8.1\n"
"POT-Creation-Date: 2001-12-17 16:30+0100\n"
"PO-Revision-Date: 2002-03-05 17:50+0000\n"
"Last-Translator: Simos Xenitellis <simos@hellug.gr>\n"
"Language-Team: Greek <nls@tux.hellug.gr>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=ISO-8859-7\n"
"Content-Transfer-Encoding: 8-bit\n"

#: src/connect.c:94
#, c-format
msgid "Connecting to %s[%s]:%hu... "
msgstr "������� �� %s[%s]:%hu... "

#: src/connect.c:97
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "������� �� %s:%hu... "

#: src/connect.c:131
msgid "connected.\n"
msgstr "���������.\n"

#: src/cookies.c:595
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "������ ��� Set-Cookie, ����� `%s'"

#: src/cookies.c:619
#, c-format
msgid "Syntax error in Set-Cookie at character `%c'.\n"
msgstr "��������� ������ ��� Set-Cookie ��� ��������� `%c'.\n"

#: src/cookies.c:627
msgid "Syntax error in Set-Cookie: premature end of string.\n"
msgstr "���������� ������ ��� Set-Cookie: ������ ����� ��������������.\n"

#: src/cookies.c:1329
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "������� �� ������� ��� ������� cookies `%s': %s\n"

#: src/cookies.c:1341
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "������ ���� ������� ��� `%s': %s\n"

#: src/cookies.c:1345
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "������ ��� �������� ��� `%s': %s\n"

#: src/ftp-ls.c:802
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr "�� ��������������� ����� ���������, �������� �� ��� ������� ��� Unix ��������.\n"

#: src/ftp-ls.c:847 src/ftp-ls.c:849
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "��������� ��� /%s ��� %s:%d"

#: src/ftp-ls.c:871
msgid "time unknown       "
msgstr "��� �������        "

#: src/ftp-ls.c:875
msgid "File        "
msgstr "������      "

#: src/ftp-ls.c:878
msgid "Directory   "
msgstr "���������   "

#: src/ftp-ls.c:881
msgid "Link        "
msgstr "�������     "

#: src/ftp-ls.c:884
msgid "Not sure    "
msgstr "��� ������� ��������   "

#: src/ftp-ls.c:902
#, c-format
msgid " (%s bytes)"
msgstr " (%s byte)"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:179
#, c-format
msgid "Logging in as %s ... "
msgstr "��������������� �� %s ... "

#: src/ftp.c:188 src/ftp.c:241 src/ftp.c:272 src/ftp.c:326 src/ftp.c:419 src/ftp.c:470 src/ftp.c:500 src/ftp.c:564 src/ftp.c:628 src/ftp.c:689 src/ftp.c:737
msgid "Error in server response, closing control connection.\n"
msgstr "������ ���� �������� ��� ����������, ������� � ������� �������.\n"

#: src/ftp.c:196
msgid "Error in server greeting.\n"
msgstr "������ ��� ������ �������� ��� ����������.\n"

#: src/ftp.c:204 src/ftp.c:335 src/ftp.c:428 src/ftp.c:509 src/ftp.c:574 src/ftp.c:638 src/ftp.c:699 src/ftp.c:747
msgid "Write failed, closing control connection.\n"
msgstr "�������� ���� ������� ���������, ������� � ������� �������.\n"

#: src/ftp.c:211
msgid "The server refuses login.\n"
msgstr "� ����������� ���������� �� �������.\n"

#: src/ftp.c:218
msgid "Login incorrect.\n"
msgstr "������ ���� ���������������.\n"

#: src/ftp.c:225
msgid "Logged in!\n"
msgstr "�������� �������!\n"

#: src/ftp.c:250
msgid "Server error, can't determine system type.\n"
msgstr "������ ����������, ��� ����� �� ��������� ��� ���� ��� ����������.\n"

#: src/ftp.c:260 src/ftp.c:549 src/ftp.c:612 src/ftp.c:669
msgid "done.    "
msgstr "�����.    "

#: src/ftp.c:314 src/ftp.c:449 src/ftp.c:484 src/ftp.c:720 src/ftp.c:768 src/host.c:283
msgid "done.\n"
msgstr "�����.\n"

#: src/ftp.c:343
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "�������� ����� `%c', ������� ��� ��������.\n"

#: src/ftp.c:356
msgid "done.  "
msgstr "�����.  "

#: src/ftp.c:362
msgid "==> CWD not needed.\n"
msgstr "==> CWD ��� ���������.\n"

#: src/ftp.c:435
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr "��� ������� ������� ��������� `%s'.\n"

#. do not CWD
#: src/ftp.c:453
msgid "==> CWD not required.\n"
msgstr "==> CWD ��� ����������.\n"

#: src/ftp.c:516
msgid "Cannot initiate PASV transfer.\n"
msgstr "��� ����� ������ �� ��������� �������� ����� PASV.\n"

#: src/ftp.c:520
msgid "Cannot parse PASV response.\n"
msgstr "��� ����� ������ � ��������� ��� ��������� PASV.\n"

#: src/ftp.c:541
#, c-format
msgid "couldn't connect to %s:%hu: %s\n"
msgstr "������� � ������� ��� %s:%hu: %s\n"

#: src/ftp.c:591
#, c-format
msgid "Bind error (%s).\n"
msgstr "������ ��� ������� (%s).\n"

#: src/ftp.c:598
msgid "Invalid PORT.\n"
msgstr "�� ������ ����.\n"

#: src/ftp.c:651
#, c-format
msgid ""
"\n"
"REST failed; will not truncate `%s'.\n"
msgstr ""
"\n"
"�������� ��� REST� �� �� ����������� �� `%s'.\n"

#: src/ftp.c:658
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"�������� ���� ������ REST, �������� ��� ��� ����.\n"

#: src/ftp.c:707
#, c-format
msgid ""
"No such file `%s'.\n"
