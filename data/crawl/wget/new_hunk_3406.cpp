"%s (%s) - `%s' ������������ [%ld]\n"
"\n"

#: src/ftp.c:1160 src/main.c:819 src/recur.c:349 src/retr.c:587
#, c-format
msgid "Removing %s.\n"
msgstr "�������� ��� %s.\n"

#: src/ftp.c:1202
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "����� ��� `%s' ��� ��������� ������ ������������ ���������.\n"

#: src/ftp.c:1217
#, c-format
msgid "Removed `%s'.\n"
msgstr "�������� ��� `%s'.\n"

#: src/ftp.c:1252
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "�� ������� ��������� %d �������� �� ������� ������� ��������� %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1317
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr ""
"�� ������ ��� ���������� ��� ����� ������� ��� ������� `%s' -- �� ������� ��������.\n"
"\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1324
#, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr ""
"�� ������ ��� ���������� ����� ������� ��� ������� `%s' -- ������� ��������.\n"
"\n"

#. Sizes do not match
#: src/ftp.c:1331
#, c-format
msgid ""
"The sizes do not match (local %ld) -- retrieving.\n"
"\n"
msgstr "�� ������ ��� ����� ��� (������ %ld) -- ������� ��������.\n"

#: src/ftp.c:1348
msgid "Invalid name of the symlink, skipping.\n"
msgstr "�� ������ ����� ���������� ���������, �������������.\n"

#: src/ftp.c:1365
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"������� ��� � ����� ��������� %s -> %s\n"
"\n"

#: src/ftp.c:1373
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "���������� ��������� %s -> %s\n"

#: src/ftp.c:1384
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "��� �������������� ���������, ��������� ��������� `%s'.\n"

#: src/ftp.c:1396
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "��������� ��������� `%s'.\n"

#: src/ftp.c:1405
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: �������/�� �������������� ����� �������.\n"

#: src/ftp.c:1432
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: ��������� ���������� �������.\n"

#: src/ftp.c:1457
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "��� �� ���������� ��������� ����� �� ����� ����� %d (������� %d).\n"

#: src/ftp.c:1507
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr "��� �������������� ��� `%s' ����� ����� �����������/��-������������������\n"

#: src/ftp.c:1561
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "�������� ��� `%s'.\n"

#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1608
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "��� �������� ����������� ��� ����� `%s'.\n"

#: src/ftp.c:1673
#, c-format
msgid "Wrote HTML-ized index to `%s' [%ld].\n"
msgstr "�������� ������ ��������� �� HTML ��� `%s' [%ld].\n"

#: src/ftp.c:1678
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "�������� ������ ��������� �� HTML ��� `%s'.\n"

#: src/gen_sslfunc.c:109
msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
msgstr "������� � ������������ ��� PRNG ��� OpenSSL� �������������� ��� SSL.\n"

#: src/getopt.c:454
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: � ������� `%s' ����� �������\n"

#: src/getopt.c:478
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: � ������� `--%s' ��� ���������� ������\n"

#: src/getopt.c:483
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: � ������� `%c%s' ��� ���������� ������\n"

#: src/getopt.c:498
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: � ������� `%s' ������� ������\n"

#. --option
#: src/getopt.c:528
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: �� ������������ ������� `--%s'\n"

#. +option or -option
#: src/getopt.c:532
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: �� ������������ ������� `%c%s'\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:563
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: �� �������� ������� -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:602
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: � ������� ������� ��� ��������� -- %c\n"

#: src/host.c:271
#, c-format
msgid "Resolving %s... "
msgstr "������ ��� %s... "

#: src/host.c:278
#, c-format
msgid "failed: %s.\n"
msgstr "�������: %s.\n"

#: src/host.c:348
msgid "Host not found"
msgstr "� ����������� �� �������"

#: src/host.c:350
msgid "Unknown error"
msgstr "������� ������"

#: src/html-url.c:336
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: ������� � ������� �� ������������� ��������� %s.\n"

#. this is fatal
#: src/http.c:573
msgid "Failed to set up an SSL context\n"
msgstr "�������� ����������� ������������� SSL\n"

#: src/http.c:579
#, c-format
msgid "Failed to load certificates from %s\n"
msgstr "�������� �������� �������������� ��� %s\n"

#: src/http.c:583 src/http.c:591
msgid "Trying without the specified certificate\n"
msgstr "���������� ����� �� ����������� �������������\n"

#: src/http.c:587
#, c-format
msgid "Failed to get certificate key from %s\n"
msgstr "�������� ����� �������� �������������� ��� %s\n"

#: src/http.c:657 src/http.c:1620
msgid "Unable to establish SSL connection.\n"
msgstr "������� � ������� �������� SSL.\n"

#: src/http.c:666
#, c-format
msgid "Reusing connection to %s:%hu.\n"
msgstr "����� ���� ��� �������� ��� %s:%hu.\n"

#: src/http.c:868
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "������ ���� ������� ��� ������� HTTP: %s.\n"

#: src/http.c:873
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "� ������ ��� %s ��������, ������� ���������... "

#: src/http.c:917
msgid "End of file while parsing headers.\n"
msgstr "����� ������� ��� ������� ����������� ��� ���������.\n"

#: src/http.c:927
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "������ ��������� (%s) ���� ���������.\n"

#: src/http.c:962
msgid "No data received"
msgstr "��� ��������� ��������"

#: src/http.c:964
msgid "Malformed status line"
msgstr "��������� ������ ����������"

#: src/http.c:969
msgid "(no description)"
msgstr "(����� ���������)"

#: src/http.c:1101
msgid "Authorization failed.\n"
msgstr "� ��������������� �������.\n"

#: src/http.c:1108
msgid "Unknown authentication scheme.\n"
msgstr "������� ����� ����������������.\n"

#: src/http.c:1148
#, c-format
msgid "Location: %s%s\n"
msgstr "���������: %s%s\n"

#: src/http.c:1149 src/http.c:1282
msgid "unspecified"
msgstr "�� ��������"

#: src/http.c:1150
msgid " [following]"
msgstr " [���������]"

#: src/http.c:1213
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""
"\n"
"    �� ������ ���� ��� ��������� ������ ������ �� ����.\n"

#: src/http.c:1229
#, c-format
msgid ""
"\n"
"Continued download failed on this file, which conflicts with `-c'.\n"
"Refusing to truncate existing file `%s'.\n"
"\n"
msgstr ""
"\n"
"� �������� ��� ��������� ������� ��� ���� �� ������, ��� ����������� �� �� `-c'.\n"
"������ �������� ���� ��� ������ ������ `%s'.\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1272
msgid "Length: "
msgstr "�����: "

#: src/http.c:1277
#, c-format
msgid " (%s to go)"
msgstr " (%s ����� �����)"

#: src/http.c:1282
msgid "ignored"
msgstr "���������"

#: src/http.c:1413
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr "�������������: �������������� (wildcards) ��� �������������� ��� HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:1443
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "�� ������ `%s' ����� ��� ���, �� �� ���������.\n"

#: src/http.c:1611
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "�������� ���� ������� ��� `%s' (%s).\n"

#: src/http.c:1630
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "������: ��������� (%d) ����� ���������.\n"

#: src/http.c:1662
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ������ %d: %s.\n"

#: src/http.c:1675
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr "�������� Last-modified ��� ������� -- �������� �������� �����������������.\n"

#: src/http.c:1683
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr "�������� Last-modified ��� ����� ������ -- �������� �������� ����������.\n"

#: src/http.c:1706
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""
"�� ������ ��� ���������� ��� ����� ������� ��� �� ������ ������ `%s' -- �� ������� ��������.\n"
"\n"

#: src/http.c:1714
#, c-format
msgid "The sizes do not match (local %ld) -- retrieving.\n"
msgstr "�� ������ ��� ����� ��� (������ %ld) -- ������� �������� ����.\n"

#: src/http.c:1718
msgid "Remote file is newer, retrieving.\n"
msgstr "������������� ������ ����� �������, ������ ���������.\n"

#: src/http.c:1759
#, c-format
msgid ""
"%s (%s) - `%s' saved [%ld/%ld]\n"
