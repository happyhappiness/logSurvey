# Greek messages for GNU wget.
# Copyright (C) 1999 Free Software Foundation, Inc.
# Simos KSenitellis <simos@teiath.gr>, 1999.
#
msgid ""
msgstr ""
"Project-Id-Version: GNU Wget 1.7-dev\n"
"POT-Creation-Date: 2001-02-23 13:23-0800\n"
"PO-Revision-Date: 1999-02-09 02:00+0000\n"
"Last-Translator: Simos KSenitellis <S.Xenitellis@rhbnc.ac.uk>\n"
"Language-Team: Greek <S.Xenitellis@rhbnc.ac.uk>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=ISO-8859-7\n"
"Content-Transfer-Encoding: 8-bit\n"

#: src/ftp-ls.c:779
msgid "Usupported listing type, trying Unix listing parser.\n"
msgstr ""

#
#: src/ftp-ls.c:824 src/ftp-ls.c:826
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "��������� ��� /%s ��� %s:%d"

#
#: src/ftp-ls.c:848
msgid "time unknown       "
msgstr "��� �������        "

#
#: src/ftp-ls.c:852
msgid "File        "
msgstr "������      "

#
#: src/ftp-ls.c:855
msgid "Directory   "
msgstr "���������   "

#
#: src/ftp-ls.c:858
msgid "Link        "
msgstr "�������     "

#
#: src/ftp-ls.c:861
msgid "Not sure    "
msgstr "��� ������� ��������   "

#
#: src/ftp-ls.c:879
#, c-format
msgid " (%s bytes)"
msgstr " (%s bytes)"

#
#. Login to the server:
#. First: Establish the control connection.
#: src/ftp.c:151 src/http.c:618
#, c-format
msgid "Connecting to %s:%hu... "
msgstr "������� �� %s:%hu... "

#
#: src/ftp.c:173 src/ftp.c:517 src/http.c:635
#, c-format
msgid "Connection to %s:%hu refused.\n"
msgstr "������� �� %s:%hu ��� ���������.\n"

#
#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:194 src/http.c:646
msgid "connected!\n"
msgstr "���������!\n"

#
#: src/ftp.c:195
#, c-format
msgid "Logging in as %s ... "
msgstr "��������������� ��� %s ... "

#
#: src/ftp.c:204 src/ftp.c:257 src/ftp.c:288 src/ftp.c:313 src/ftp.c:407
#: src/ftp.c:459 src/ftp.c:553 src/ftp.c:626 src/ftp.c:674 src/ftp.c:722
msgid "Error in server response, closing control connection.\n"
msgstr "������ ���� �������� ��� �����������, ������� � ������� �������.\n"

#
#: src/ftp.c:212
msgid "Error in server greeting.\n"
msgstr "������ ��� ������ �������� ��� �����������.\n"

#
#: src/ftp.c:220 src/ftp.c:322 src/ftp.c:416 src/ftp.c:468 src/ftp.c:563
#: src/ftp.c:636 src/ftp.c:684 src/ftp.c:732
msgid "Write failed, closing control connection.\n"
msgstr "�������� ���� ������� ���������, ������� � ������� �������.\n"

#
#: src/ftp.c:227
msgid "The server refuses login.\n"
msgstr "� ������������ ���������� �� �������.\n"

#
#: src/ftp.c:234
msgid "Login incorrect.\n"
msgstr "����� ����� ���������.\n"

#
#: src/ftp.c:241
msgid "Logged in!\n"
msgstr "�������� �������!\n"

#: src/ftp.c:266
msgid "Server error, can't determine system type.\n"
msgstr ""

#
#: src/ftp.c:276 src/ftp.c:538 src/ftp.c:610 src/ftp.c:654
msgid "done.    "
msgstr "�����.    "

#
#: src/ftp.c:302 src/ftp.c:437 src/ftp.c:705 src/ftp.c:753 src/url.c:1432
msgid "done.\n"
msgstr "�����.\n"

#
#: src/ftp.c:330
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "�������� ����� `%c', ������� ��� ��������.\n"

#
#: src/ftp.c:343
msgid "done.  "
msgstr "�����.  "

#
#: src/ftp.c:349
msgid "==> CWD not needed.\n"
msgstr "==> CWD ��� ���������.\n"

#
#: src/ftp.c:423
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr "��� ������� ������� ��������� `%s'.\n"

#
#. do not CWD
#: src/ftp.c:441
msgid "==> CWD not required.\n"
msgstr "==> CWD ��� ����������.\n"

#
#: src/ftp.c:475
msgid "Cannot initiate PASV transfer.\n"
msgstr "��� ����� ������ �� ��������� �������� ����� PASV.\n"

#
#: src/ftp.c:479
msgid "Cannot parse PASV response.\n"
msgstr "��� ����� ������ � ��������� ��� ��������� PASV.\n"

#
#: src/ftp.c:493
#, c-format
msgid "Will try connecting to %s:%hu.\n"
msgstr "�� ����������� ������� ��� %s:%hu.\n"

#
#: src/ftp.c:580
#, c-format
msgid "Bind error (%s).\n"
msgstr "������ ��� ������� (%s).\n"

#
#: src/ftp.c:596
msgid "Invalid PORT.\n"
msgstr "�� ������ PORT.\n"

#
#: src/ftp.c:643
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"�������� ���� ������ REST, �������� ��� �� �����.\n"

#
#: src/ftp.c:692
#, c-format
msgid ""
"No such file `%s'.\n"
