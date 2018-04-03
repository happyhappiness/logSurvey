# Greek messages for GNU wget.
# Copyright (C) 1999, 2000, 2001, 2002 Free Software Foundation, Inc.
# Simos Xenitellis <simos@hellug.gr>, 1999, 2000, 2001, 2002.
#
msgid ""
msgstr ""
"Project-Id-Version: wget 1.8.1\n"
"Report-Msgid-Bugs-To: \n"
"POT-Creation-Date: 2005-06-06 09:11-0400\n"
"PO-Revision-Date: 2002-03-05 17:50+0000\n"
"Last-Translator: Simos Xenitellis <simos@hellug.gr>\n"
"Language-Team: Greek <nls@tux.hellug.gr>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=ISO-8859-7\n"
"Content-Transfer-Encoding: 8-bit\n"

#: src/connect.c:199
#, c-format
msgid "%s: unable to resolve bind address `%s'; disabling bind.\n"
msgstr ""

#: src/connect.c:271
#, fuzzy, c-format
msgid "Connecting to %s|%s|:%d... "
msgstr "������� �� %s[%s]:%hu... "

#: src/connect.c:274
#, fuzzy, c-format
msgid "Connecting to %s:%d... "
msgstr "������� �� %s:%hu... "

#: src/connect.c:335
msgid "connected.\n"
msgstr "���������.\n"

#: src/convert.c:176
#, fuzzy, c-format
msgid "Converted %d files in %.*f seconds.\n"
msgstr "������������ %d ������ �� %.2f ������������.\n"

#: src/convert.c:202
#, c-format
msgid "Converting %s... "
msgstr "��������� ��� %s... "

#: src/convert.c:215
msgid "nothing to do.\n"
msgstr "������ �� ����.\n"

#: src/convert.c:223 src/convert.c:247
#, c-format
msgid "Cannot convert links in %s: %s\n"
msgstr "�������� ���������� ��������� ��� %s: %s\n"

#: src/convert.c:238
#, c-format
msgid "Unable to delete `%s': %s\n"
msgstr "�������� ��������� ��� `%s': %s\n"

#: src/convert.c:447
#, c-format
msgid "Cannot back up %s as %s: %s\n"
msgstr "������� � ���� ���������� ��������� ��� %s �� %s: %s\n"

#: src/cookies.c:619
#, c-format
msgid "Error in Set-Cookie, field `%s'"
msgstr "������ ��� Set-Cookie, ����� `%s'"

#: src/cookies.c:643
#, fuzzy, c-format
msgid "Syntax error in Set-Cookie: %s at position %d.\n"
msgstr "���������� ������ ��� Set-Cookie: ������ ����� ��������������.\n"

#: src/cookies.c:1469
#, c-format
msgid "Cannot open cookies file `%s': %s\n"
msgstr "������� �� ������� ��� ������� cookies `%s': %s\n"

#: src/cookies.c:1481
#, c-format
msgid "Error writing to `%s': %s\n"
msgstr "������ ���� ������� ��� `%s': %s\n"

#: src/cookies.c:1484
#, c-format
msgid "Error closing `%s': %s\n"
msgstr "������ ��� �������� ��� `%s': %s\n"

#: src/ftp-ls.c:841
msgid "Unsupported listing type, trying Unix listing parser.\n"
msgstr ""
"�� ��������������� ����� ���������, �������� �� ��� ������� ��� Unix "
"��������.\n"

#: src/ftp-ls.c:887 src/ftp-ls.c:889
#, c-format
msgid "Index of /%s on %s:%d"
msgstr "��������� ��� /%s ��� %s:%d"

#: src/ftp-ls.c:912
#, c-format
msgid "time unknown       "
msgstr "��� �������        "

#: src/ftp-ls.c:916
#, c-format
msgid "File        "
msgstr "������      "

#: src/ftp-ls.c:919
#, c-format
msgid "Directory   "
msgstr "���������   "

#: src/ftp-ls.c:922
#, c-format
msgid "Link        "
msgstr "�������     "

#: src/ftp-ls.c:925
#, c-format
msgid "Not sure    "
msgstr "��� ������� ��������   "

#: src/ftp-ls.c:943
#, c-format
msgid " (%s bytes)"
msgstr " (%s byte)"

#: src/ftp.c:226
#, c-format
msgid "Length: %s"
msgstr "�����: %s"

#: src/ftp.c:232 src/http.c:1857
#, c-format
msgid ", %s (%s) remaining"
msgstr ""

#: src/ftp.c:236 src/http.c:1861
#, c-format
msgid ", %s remaining"
msgstr ""

#: src/ftp.c:239
msgid " (unauthoritative)\n"
msgstr " (���������)\n"

#. Second: Login with proper USER/PASS sequence.
#: src/ftp.c:314
#, c-format
msgid "Logging in as %s ... "
msgstr "��������������� �� %s ... "

#: src/ftp.c:327 src/ftp.c:373 src/ftp.c:402 src/ftp.c:454 src/ftp.c:566
#: src/ftp.c:612 src/ftp.c:640 src/ftp.c:698 src/ftp.c:759 src/ftp.c:819
#: src/ftp.c:866
msgid "Error in server response, closing control connection.\n"
msgstr "������ ���� �������� ��� ����������, ������� � ������� �������.\n"

#: src/ftp.c:334
msgid "Error in server greeting.\n"
msgstr "������ ��� ������ �������� ��� ����������.\n"

#: src/ftp.c:341 src/ftp.c:462 src/ftp.c:574 src/ftp.c:648 src/ftp.c:708
#: src/ftp.c:769 src/ftp.c:829 src/ftp.c:876
msgid "Write failed, closing control connection.\n"
msgstr "�������� ���� ������� ���������, ������� � ������� �������.\n"

#: src/ftp.c:347
msgid "The server refuses login.\n"
msgstr "� ����������� ���������� �� �������.\n"

#: src/ftp.c:353
msgid "Login incorrect.\n"
msgstr "������ ���� ���������������.\n"

#: src/ftp.c:359
msgid "Logged in!\n"
msgstr "�������� �������!\n"

#: src/ftp.c:381
msgid "Server error, can't determine system type.\n"
msgstr "������ ����������, ��� ����� �� ��������� ��� ���� ��� ����������.\n"

#: src/ftp.c:390 src/ftp.c:685 src/ftp.c:742 src/ftp.c:785
msgid "done.    "
msgstr "�����.    "

#: src/ftp.c:442 src/ftp.c:591 src/ftp.c:624 src/ftp.c:849 src/ftp.c:895
msgid "done.\n"
msgstr "�����.\n"

#: src/ftp.c:469
#, c-format
msgid "Unknown type `%c', closing control connection.\n"
msgstr "�������� ����� `%c', ������� ��� ��������.\n"

#: src/ftp.c:481
msgid "done.  "
msgstr "�����.  "

#: src/ftp.c:487
msgid "==> CWD not needed.\n"
msgstr "==> CWD ��� ���������.\n"

#: src/ftp.c:580
#, c-format
msgid ""
"No such directory `%s'.\n"
"\n"
msgstr "��� ������� ������� ��������� `%s'.\n"

#. do not CWD
#: src/ftp.c:595
msgid "==> CWD not required.\n"
msgstr "==> CWD ��� ����������.\n"

#: src/ftp.c:654
msgid "Cannot initiate PASV transfer.\n"
msgstr "��� ����� ������ �� ��������� �������� ����� PASV.\n"

#: src/ftp.c:658
msgid "Cannot parse PASV response.\n"
msgstr "��� ����� ������ � ��������� ��� ��������� PASV.\n"

#: src/ftp.c:676
#, fuzzy, c-format
msgid "couldn't connect to %s port %d: %s\n"
msgstr "������� � ������� ��� %s:%hu: %s\n"

#: src/ftp.c:724
#, c-format
msgid "Bind error (%s).\n"
msgstr "������ ��� ������� (%s).\n"

#: src/ftp.c:730
msgid "Invalid PORT.\n"
msgstr "�� ������ ����.\n"

#: src/ftp.c:776
msgid ""
"\n"
"REST failed, starting from scratch.\n"
msgstr ""
"\n"
"�������� ���� ������ REST, �������� ��� ��� ����.\n"

#: src/ftp.c:837
#, c-format
msgid ""
"No such file `%s'.\n"
"\n"
msgstr ""
"��� ������� ������ `%s'.\n"
"\n"

#: src/ftp.c:884
#, c-format
msgid ""
"No such file or directory `%s'.\n"
"\n"
msgstr ""
"��� ������� ������ � ��������� `%s'.\n"
"\n"

#. We cannot just invent a new name and use it (which is
#. what functions like unique_create typically do)
#. because we told the user we'd use this name.
#. Instead, return and retry the download.
#: src/ftp.c:946 src/http.c:1913
#, c-format
msgid "%s has sprung into existence.\n"
msgstr ""

#: src/ftp.c:1008
#, c-format
msgid "%s: %s, closing control connection.\n"
msgstr "%s: %s, �������� �������� �������.\n"

#: src/ftp.c:1016
#, c-format
msgid "%s (%s) - Data connection: %s; "
msgstr "%s (%s) - ������� ���������: %s; "

#: src/ftp.c:1031
msgid "Control connection closed.\n"
msgstr "� ������� ������� �������.\n"

#: src/ftp.c:1049
msgid "Data transfer aborted.\n"
msgstr "� �������� ��������� ��������� �������.\n"

#: src/ftp.c:1114
#, c-format
msgid "File `%s' already there, not retrieving.\n"
msgstr "�� ������ `%s' ������� ���, ��� �����������.\n"

#: src/ftp.c:1182 src/http.c:2130
#, c-format
msgid "(try:%2d)"
msgstr "(����������:%2d)"

#: src/ftp.c:1252 src/http.c:2409
#, fuzzy, c-format
msgid ""
"%s (%s) - `%s' saved [%s]\n"
"\n"
msgstr ""
"%s (%s) - `%s' ������������ [%ld]\n"
"\n"

#: src/ftp.c:1294 src/main.c:948 src/recur.c:376 src/retr.c:842
#, c-format
msgid "Removing %s.\n"
msgstr "�������� ��� %s.\n"

#: src/ftp.c:1336
#, c-format
msgid "Using `%s' as listing tmp file.\n"
msgstr "����� ��� `%s' ��� ��������� ������ ������������ ���������.\n"

#: src/ftp.c:1351
#, c-format
msgid "Removed `%s'.\n"
msgstr "�������� ��� `%s'.\n"

#: src/ftp.c:1386
#, c-format
msgid "Recursion depth %d exceeded max. depth %d.\n"
msgstr "�� ������� ��������� %d �������� �� ������� ������� ��������� %d.\n"

#. Remote file is older, file sizes can be compared and
#. are both equal.
#: src/ftp.c:1456
#, c-format
msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
msgstr ""
"�� ������ ��� ���������� ��� ����� ������� ��� ������� `%s' -- �� ������� "
"��������.\n"
"\n"

#. Remote file is newer or sizes cannot be matched
#: src/ftp.c:1463
#, c-format
msgid ""
"Remote file is newer than local file `%s' -- retrieving.\n"
"\n"
msgstr ""
"�� ������ ��� ���������� ����� ������� ��� ������� `%s' -- ������� "
"��������.\n"
"\n"

#. Sizes do not match
#: src/ftp.c:1470
#, fuzzy, c-format
msgid ""
"The sizes do not match (local %s) -- retrieving.\n"
"\n"
msgstr "�� ������ ��� ����� ��� (������ %ld) -- ������� ��������.\n"

#: src/ftp.c:1488
msgid "Invalid name of the symlink, skipping.\n"
msgstr "�� ������ ����� ���������� ���������, �������������.\n"

#: src/ftp.c:1505
#, c-format
msgid ""
"Already have correct symlink %s -> %s\n"
"\n"
msgstr ""
"������� ��� � ����� ��������� %s -> %s\n"
"\n"

#: src/ftp.c:1513
#, c-format
msgid "Creating symlink %s -> %s\n"
msgstr "���������� ��������� %s -> %s\n"

#: src/ftp.c:1523
#, c-format
msgid "Symlinks not supported, skipping symlink `%s'.\n"
msgstr "��� �������������� ���������, ��������� ��������� `%s'.\n"

#: src/ftp.c:1535
#, c-format
msgid "Skipping directory `%s'.\n"
msgstr "��������� ��������� `%s'.\n"

#: src/ftp.c:1544
#, c-format
msgid "%s: unknown/unsupported file type.\n"
msgstr "%s: �������/�� �������������� ����� �������.\n"

#: src/ftp.c:1571
#, c-format
msgid "%s: corrupt time-stamp.\n"
msgstr "%s: ��������� ���������� �������.\n"

#: src/ftp.c:1599
#, c-format
msgid "Will not retrieve dirs since depth is %d (max %d).\n"
msgstr "��� �� ���������� ��������� ����� �� ����� ����� %d (������� %d).\n"

#: src/ftp.c:1649
#, c-format
msgid "Not descending to `%s' as it is excluded/not-included.\n"
msgstr ""
"��� �������������� ��� `%s' ����� ����� �����������/��-������������������\n"

#: src/ftp.c:1715 src/ftp.c:1729
#, c-format
msgid "Rejecting `%s'.\n"
msgstr "�������� ��� `%s'.\n"

#. No luck.
#. #### This message SUCKS.  We should see what was the
#. reason that nothing was retrieved.
#: src/ftp.c:1775
#, c-format
msgid "No matches on pattern `%s'.\n"
msgstr "��� �������� ����������� ��� ����� `%s'.\n"

#: src/ftp.c:1841
#, fuzzy, c-format
msgid "Wrote HTML-ized index to `%s' [%s].\n"
msgstr "�������� ������ ��������� �� HTML ��� `%s' [%ld].\n"

#: src/ftp.c:1846
#, c-format
msgid "Wrote HTML-ized index to `%s'.\n"
msgstr "�������� ������ ��������� �� HTML ��� `%s'.\n"

#: src/getopt.c:675
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: � ������� `%s' ����� �������\n"

#: src/getopt.c:700
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: � ������� `--%s' ��� ���������� ������\n"

#: src/getopt.c:705
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: � ������� `%c%s' ��� ���������� ������\n"

#: src/getopt.c:723 src/getopt.c:896
#, c-format
msgid "%s: option `%s' requires an argument\n"
msgstr "%s: � ������� `%s' ������� ������\n"

#. --option
#: src/getopt.c:752
#, c-format
msgid "%s: unrecognized option `--%s'\n"
msgstr "%s: �� ������������ ������� `--%s'\n"

#. +option or -option
#: src/getopt.c:756
#, c-format
msgid "%s: unrecognized option `%c%s'\n"
msgstr "%s: �� ������������ ������� `%c%s'\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:782
#, c-format
msgid "%s: illegal option -- %c\n"
msgstr "%s: �� �������� ������� -- %c\n"

#: src/getopt.c:785
#, fuzzy, c-format
msgid "%s: invalid option -- %c\n"
msgstr "%s: �� �������� ������� -- %c\n"

#. 1003.2 specifies the format of this message.
#: src/getopt.c:815 src/getopt.c:945
#, c-format
msgid "%s: option requires an argument -- %c\n"
msgstr "%s: � ������� ������� ��� ��������� -- %c\n"

#: src/getopt.c:862
#, fuzzy, c-format
msgid "%s: option `-W %s' is ambiguous\n"
msgstr "%s: � ������� `%s' ����� �������\n"

#: src/getopt.c:880
#, fuzzy, c-format
msgid "%s: option `-W %s' doesn't allow an argument\n"
msgstr "%s: � ������� `--%s' ��� ���������� ������\n"

#: src/host.c:371
#, fuzzy
msgid "Unknown host"
msgstr "������� ������"

#. Message modeled after what gai_strerror returns in similar
#. circumstances.
#: src/host.c:375
msgid "Temporary failure in name resolution"
msgstr ""

#: src/host.c:377
msgid "Unknown error"
msgstr "������� ������"

#: src/host.c:756
#, c-format
msgid "Resolving %s... "
msgstr "������ ��� %s... "

#: src/host.c:800 src/host.c:829
#, c-format
msgid "failed: %s.\n"
msgstr "�������: %s.\n"

#: src/host.c:809
msgid "failed: No IPv4/IPv6 addresses for host.\n"
msgstr ""

#: src/host.c:832
#, fuzzy
msgid "failed: timed out.\n"
msgstr "�������: %s.\n"

#: src/html-url.c:298
#, c-format
msgid "%s: Cannot resolve incomplete link %s.\n"
msgstr "%s: ������� � ������� �� ������������� ��������� %s.\n"

#: src/http.c:373 src/http.c:1549
#, c-format
msgid "Failed writing HTTP request: %s.\n"
msgstr "������ ���� ������� ��� ������� HTTP: %s.\n"

#: src/http.c:687
msgid "No headers, assuming HTTP/0.9"
msgstr ""

#: src/http.c:1198
msgid "Disabling SSL due to encountered errors.\n"
msgstr ""

#: src/http.c:1417
#, fuzzy, c-format
msgid "Reusing existing connection to %s:%d.\n"
msgstr "����� ���� ��� �������� ��� %s:%hu.\n"

#: src/http.c:1479
#, fuzzy, c-format
msgid "Failed writing to proxy: %s.\n"
msgstr "������ ���� ������� ��� ������� HTTP: %s.\n"

#: src/http.c:1488
#, fuzzy, c-format
msgid "Failed reading proxy response: %s\n"
msgstr "������ ���� ������� ��� ������� HTTP: %s.\n"

#: src/http.c:1508
#, c-format
msgid "Proxy tunneling failed: %s"
msgstr ""

#: src/http.c:1555
#, c-format
msgid "%s request sent, awaiting response... "
msgstr "� ������ ��� %s ��������, ������� ���������... "

#: src/http.c:1566
#, fuzzy
msgid "No data received.\n"
msgstr "��� ��������� ��������"

#: src/http.c:1573
#, c-format
msgid "Read error (%s) in headers.\n"
msgstr "������ ��������� (%s) ���� ���������.\n"

#. If the authentication header is missing or
#. unrecognized, there's no sense in retrying.
#: src/http.c:1658
msgid "Unknown authentication scheme.\n"
msgstr "������� ����� ����������������.\n"

#: src/http.c:1682
msgid "Authorization failed.\n"
msgstr "� ��������������� �������.\n"

#: src/http.c:1696
msgid "Malformed status line"
msgstr "��������� ������ ����������"

#: src/http.c:1698
msgid "(no description)"
msgstr "(����� ���������)"

#: src/http.c:1769
#, c-format
msgid "Location: %s%s\n"
msgstr "���������: %s%s\n"

#: src/http.c:1770 src/http.c:1867
msgid "unspecified"
msgstr "�� ��������"

#: src/http.c:1771
msgid " [following]"
msgstr " [���������]"

#. If `-c' is in use and the file has been fully downloaded (or
#. the remote file has shrunk), Wget effectively requests bytes
#. after the end of file and the server response with 416.
#: src/http.c:1817
msgid ""
"\n"
"    The file is already fully retrieved; nothing to do.\n"
"\n"
msgstr ""
"\n"
"    �� ������ ���� ��� ��������� ������ ������ �� ����.\n"

#. No need to print this output if the body won't be
#. downloaded at all, or if the original server response is
#. printed.
#: src/http.c:1847
msgid "Length: "
msgstr "�����: "

#: src/http.c:1867
msgid "ignored"
msgstr "���������"

#: src/http.c:2007
msgid "Warning: wildcards not supported in HTTP.\n"
msgstr ""
"�������������: �������������� (wildcards) ��� �������������� ��� HTTP.\n"

#. If opt.noclobber is turned on and file already exists, do not
#. retrieve the file
#: src/http.c:2042
#, c-format
msgid "File `%s' already there, will not retrieve.\n"
msgstr "�� ������ `%s' ����� ��� ���, �� �� ���������.\n"

#: src/http.c:2232
#, c-format
msgid "Cannot write to `%s' (%s).\n"
msgstr "�������� ���� ������� ��� `%s' (%s).\n"

#. Another fatal error.
#: src/http.c:2239
msgid "Unable to establish SSL connection.\n"
msgstr "������� � ������� �������� SSL.\n"

#: src/http.c:2248
#, c-format
msgid "ERROR: Redirection (%d) without location.\n"
msgstr "������: ��������� (%d) ����� ���������.\n"

#: src/http.c:2278
#, c-format
msgid "%s ERROR %d: %s.\n"
msgstr "%s ������ %d: %s.\n"

#: src/http.c:2291
msgid "Last-modified header missing -- time-stamps turned off.\n"
msgstr ""
"�������� Last-modified ��� ������� -- �������� �������� �����������������.\n"

#: src/http.c:2299
msgid "Last-modified header invalid -- time-stamp ignored.\n"
msgstr ""
"�������� Last-modified ��� ����� ������ -- �������� �������� ����������.\n"

#: src/http.c:2322
#, c-format
msgid ""
"Server file no newer than local file `%s' -- not retrieving.\n"
"\n"
msgstr ""
"�� ������ ��� ���������� ��� ����� ������� ��� �� ������ ������ `%s' -- �� "
"������� ��������.\n"
"\n"

#: src/http.c:2330
#, fuzzy, c-format
msgid "The sizes do not match (local %s) -- retrieving.\n"
msgstr "�� ������ ��� ����� ��� (������ %ld) -- ������� �������� ����.\n"

#: src/http.c:2335
msgid "Remote file is newer, retrieving.\n"
msgstr "������������� ������ ����� �������, ������ ���������.\n"

#: src/http.c:2377
#, fuzzy, c-format
msgid ""
"%s (%s) - `%s' saved [%s/%s]\n"
"\n"
msgstr ""
"%s (%s) - `%s' ������������ [%ld/%ld]\n"
"\n"

#: src/http.c:2434
#, fuzzy, c-format
msgid "%s (%s) - Connection closed at byte %s. "
msgstr "%s (%s) - � ������� ��������� ��� byte %ld. "

#: src/http.c:2443
#, fuzzy, c-format
msgid ""
"%s (%s) - `%s' saved [%s/%s])\n"
"\n"
msgstr ""
"%s (%s) - `%s' ������������ [%ld/%ld])\n"
"\n"

#: src/http.c:2469
#, fuzzy, c-format
msgid "%s (%s) - Connection closed at byte %s/%s. "
msgstr "%s (%s) - � ������� ��������� ��� byte %ld/%ld. "

#: src/http.c:2483
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s (%s)."
msgstr "%s (%s) - ������ ��������� ��� byte %ld (%s)."

#: src/http.c:2493
#, fuzzy, c-format
msgid "%s (%s) - Read error at byte %s/%s (%s). "
msgstr "%s (%s) - ������ ��������� ��� byte %ld/%ld (%s). "

#: src/init.c:369
#, c-format
msgid "%s: WGETRC points to %s, which doesn't exist.\n"
msgstr ""

#: src/init.c:433 src/netrc.c:277
#, c-format
msgid "%s: Cannot read %s (%s).\n"
msgstr "%s: �������� ��������� %s (%s).\n"

#: src/init.c:451
#, c-format
msgid "%s: Error in %s at line %d.\n"
msgstr "%s: ������ ��� %s ��� ������ %d.\n"

#: src/init.c:457
#, fuzzy, c-format
msgid "%s: Syntax error in %s at line %d.\n"
msgstr "%s: ������ ��� %s ��� ������ %d.\n"

#: src/init.c:462
#, fuzzy, c-format
msgid "%s: Unknown command `%s' in %s at line %d.\n"
msgstr "%s: ������: ������� ������ `%s', ���� `%s'.\n"

#: src/init.c:507
#, c-format
msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
msgstr ""
"%s: �������������: �� wgetrc ��� ���������� ��� ��� ������ �������� ��� ���� "
"������ `%s'.\n"

#: src/init.c:661
#, fuzzy, c-format
msgid "%s: Invalid --execute command `%s'\n"
msgstr "%s: �� ������ ������� `%s'.\n"

#: src/init.c:707
#, fuzzy, c-format
msgid "%s: %s: Invalid boolean `%s', use `on' or `off'.\n"
msgstr "%s: %s: �������� ������ on � off.\n"

#: src/init.c:750
#, fuzzy, c-format
msgid "%s: %s: Invalid boolean `%s', use always, on, off, or never.\n"
msgstr ""
"%s: %s: �������� ��������� �����(always), ������(on), ��������(off) � ����"
"(never).\n"

#: src/init.c:767
#, fuzzy, c-format
msgid "%s: %s: Invalid number `%s'.\n"
msgstr "%s: %s: �� ������ ������� `%s'.\n"

#: src/init.c:998 src/init.c:1017
#, fuzzy, c-format
msgid "%s: %s: Invalid byte value `%s'\n"
msgstr "%s: %s: �� ������� ����� ������� `%s'.\n"

#: src/init.c:1042
#, fuzzy, c-format
msgid "%s: %s: Invalid time period `%s'\n"
msgstr "%s: %s: �� ������ ������� `%s'.\n"

#: src/init.c:1096 src/init.c:1186 src/init.c:1281 src/init.c:1306
#, fuzzy, c-format
msgid "%s: %s: Invalid value `%s'.\n"
msgstr "%s: %s: �� ������ ������� `%s'.\n"

#: src/init.c:1133
#, fuzzy, c-format
msgid "%s: %s: Invalid header `%s'.\n"
msgstr "%s: %s: �� ������ ������� `%s'.\n"

#: src/init.c:1198
#, c-format
msgid "%s: %s: Invalid progress type `%s'.\n"
msgstr "%s: %s: �� ������� ����� ������� `%s'.\n"

#: src/init.c:1249
#, fuzzy, c-format
msgid "%s: %s: Invalid restriction `%s', use `unix' or `windows'.\n"
msgstr "%s: %s: �� ������ ������� `%s'.\n"

#: src/log.c:806
#, c-format
msgid ""
"\n"
"%s received, redirecting output to `%s'.\n"
msgstr ""
"\n"
"%s �������, ������������� ������ ��� `%s'.\n"

#. Eek!  Opening the alternate log file has failed.  Nothing we
#. can do but disable printing completely.
#: src/log.c:816
#, fuzzy, c-format
msgid ""
"\n"
"%s received.\n"
msgstr "��� ��������� ��������"

#: src/log.c:817
#, c-format
msgid "%s: %s; disabling logging.\n"
msgstr "%s: %s; �������������� ����� ����������.\n"

#: src/main.c:375
#, c-format
msgid "Usage: %s [OPTION]... [URL]...\n"
msgstr "�����: %s [�������]... [URL]...\n"

#: src/main.c:387
#, fuzzy
msgid ""
"Mandatory arguments to long options are mandatory for short options too.\n"
"\n"
msgstr ""
"\n"
"�� ������������ ���������� ��� ������� �������� ����� ������������ ��� ��� "
"�� ������� ��������.\n"
"\n"

#: src/main.c:389
msgid "Startup:\n"
msgstr ""

#: src/main.c:391
msgid "  -V,  --version           display the version of Wget and exit.\n"
msgstr ""

#: src/main.c:393
msgid "  -h,  --help              print this help.\n"
msgstr ""

#: src/main.c:395
msgid "  -b,  --background        go to background after startup.\n"
msgstr ""

#: src/main.c:397
msgid "  -e,  --execute=COMMAND   execute a `.wgetrc'-style command.\n"
msgstr ""

#: src/main.c:401
msgid "Logging and input file:\n"
msgstr ""

#: src/main.c:403
msgid "  -o,  --output-file=FILE    log messages to FILE.\n"
msgstr ""

#: src/main.c:405
msgid "  -a,  --append-output=FILE  append messages to FILE.\n"
msgstr ""

#: src/main.c:408
msgid "  -d,  --debug               print lots of debugging information.\n"
msgstr ""

#: src/main.c:411
msgid "  -q,  --quiet               quiet (no output).\n"
msgstr ""

#: src/main.c:413
msgid "  -v,  --verbose             be verbose (this is the default).\n"
msgstr ""

#: src/main.c:415
msgid ""
"  -nv, --no-verbose          turn off verboseness, without being quiet.\n"
msgstr ""

#: src/main.c:417
msgid "  -i,  --input-file=FILE     download URLs found in FILE.\n"
msgstr ""

#: src/main.c:419
msgid "  -F,  --force-html          treat input file as HTML.\n"
msgstr ""

#: src/main.c:421
msgid ""
"  -B,  --base=URL            prepends URL to relative links in -F -i file.\n"
msgstr ""

#: src/main.c:425
msgid "Download:\n"
msgstr ""

#: src/main.c:427
msgid ""
"  -t,  --tries=NUMBER            set number of retries to NUMBER (0 "
"unlimits).\n"
msgstr ""

#: src/main.c:429
msgid "       --retry-connrefused       retry even if connection is refused.\n"
msgstr ""

#: src/main.c:431
msgid "  -O,  --output-document=FILE    write documents to FILE.\n"
msgstr ""

#: src/main.c:433
msgid ""
"  -nc, --no-clobber              skip downloads that would download to\n"
"                                 existing files.\n"
msgstr ""

#: src/main.c:436
msgid ""
"  -c,  --continue                resume getting a partially-downloaded "
"file.\n"
msgstr ""

#: src/main.c:438
msgid "       --progress=TYPE           select progress gauge type.\n"
msgstr ""

#: src/main.c:440
msgid ""
"  -N,  --timestamping            don't re-retrieve files unless newer than\n"
"                                 local.\n"
msgstr ""

#: src/main.c:443
msgid "  -S,  --server-response         print server response.\n"
msgstr ""

#: src/main.c:445
msgid "       --spider                  don't download anything.\n"
msgstr ""

#: src/main.c:447
msgid "  -T,  --timeout=SECONDS         set all timeout values to SECONDS.\n"
msgstr ""

#: src/main.c:449
msgid "       --dns-timeout=SECS        set the DNS lookup timeout to SECS.\n"
msgstr ""

#: src/main.c:451
msgid "       --connect-timeout=SECS    set the connect timeout to SECS.\n"
msgstr ""

#: src/main.c:453
msgid "       --read-timeout=SECS       set the read timeout to SECS.\n"
msgstr ""

#: src/main.c:455
msgid "  -w,  --wait=SECONDS            wait SECONDS between retrievals.\n"
msgstr ""

#: src/main.c:457
msgid ""
"       --waitretry=SECONDS       wait 1..SECONDS between retries of a "
"retrieval.\n"
msgstr ""

#: src/main.c:459
msgid ""
"       --random-wait             wait from 0...2*WAIT secs between "
"retrievals.\n"
msgstr ""

#: src/main.c:461
msgid "  -Y,  --proxy                   explicitly turn on proxy.\n"
msgstr ""

#: src/main.c:463
msgid "       --no-proxy                explicitly turn off proxy.\n"
msgstr ""

#: src/main.c:465
msgid "  -Q,  --quota=NUMBER            set retrieval quota to NUMBER.\n"
msgstr ""

#: src/main.c:467
msgid ""
"       --bind-address=ADDRESS    bind to ADDRESS (hostname or IP) on local "
"host.\n"
msgstr ""

#: src/main.c:469
msgid "       --limit-rate=RATE         limit download rate to RATE.\n"
msgstr ""

#: src/main.c:471
msgid "       --no-dns-cache            disable caching DNS lookups.\n"
msgstr ""

#: src/main.c:473
msgid ""
"       --restrict-file-names=OS  restrict chars in file names to ones OS "
"allows.\n"
msgstr ""

#: src/main.c:476
msgid "  -4,  --inet4-only              connect only to IPv4 addresses.\n"
msgstr ""

#: src/main.c:478
msgid "  -6,  --inet6-only              connect only to IPv6 addresses.\n"
msgstr ""

#: src/main.c:480
msgid ""
"       --prefer-family=FAMILY    connect first to addresses of specified "
"family,\n"
"                                 one of IPv6, IPv4, or none.\n"
msgstr ""

#: src/main.c:484
msgid "       --user=USER               set both ftp and http user to USER.\n"
msgstr ""

#: src/main.c:486
msgid ""
"       --password=PASS           set both ftp and http password to PASS.\n"
msgstr ""

#: src/main.c:490
#, fuzzy
msgid "Directories:\n"
msgstr "���������   "

#: src/main.c:492
msgid "  -nd, --no-directories           don't create directories.\n"
msgstr ""

#: src/main.c:494
msgid "  -x,  --force-directories        force creation of directories.\n"
msgstr ""

#: src/main.c:496
msgid "  -nH, --no-host-directories      don't create host directories.\n"
msgstr ""

#: src/main.c:498
msgid "       --protocol-directories     use protocol name in directories.\n"
msgstr ""

#: src/main.c:500
msgid "  -P,  --directory-prefix=PREFIX  save files to PREFIX/...\n"
msgstr ""

#: src/main.c:502
msgid ""
"       --cut-dirs=NUMBER          ignore NUMBER remote directory "
"components.\n"
msgstr ""

#: src/main.c:506
msgid "HTTP options:\n"
msgstr ""

#: src/main.c:508
msgid "       --http-user=USER        set http user to USER.\n"
msgstr ""

#: src/main.c:510
msgid "       --http-password=PASS    set http password to PASS.\n"
msgstr ""

#: src/main.c:512
msgid "       --no-cache              disallow server-cached data.\n"
msgstr ""

#: src/main.c:514
msgid ""
"  -E,  --html-extension        save HTML documents with `.html' extension.\n"
msgstr ""

#: src/main.c:516
msgid "       --ignore-length         ignore `Content-Length' header field.\n"
msgstr ""

#: src/main.c:518
msgid "       --header=STRING         insert STRING among the headers.\n"
msgstr ""

#: src/main.c:520
msgid "       --proxy-user=USER       set USER as proxy username.\n"
msgstr ""

#: src/main.c:522
msgid "       --proxy-password=PASS   set PASS as proxy password.\n"
msgstr ""

#: src/main.c:524
msgid ""
"       --referer=URL           include `Referer: URL' header in HTTP "
"request.\n"
msgstr ""

#: src/main.c:526
msgid "       --save-headers          save the HTTP headers to file.\n"
msgstr ""

#: src/main.c:528
msgid ""
"  -U,  --user-agent=AGENT      identify as AGENT instead of Wget/VERSION.\n"
msgstr ""

#: src/main.c:530
msgid ""
"       --no-http-keep-alive    disable HTTP keep-alive (persistent "
"connections).\n"
msgstr ""

#: src/main.c:532
msgid "       --no-cookies            don't use cookies.\n"
msgstr ""

#: src/main.c:534
msgid "       --load-cookies=FILE     load cookies from FILE before session.\n"
msgstr ""

#: src/main.c:536
msgid "       --save-cookies=FILE     save cookies to FILE after session.\n"
msgstr ""

#: src/main.c:538
msgid ""
"       --keep-session-cookies  load and save session (non-permanent) "
"cookies.\n"
msgstr ""

#: src/main.c:540
msgid ""
"       --post-data=STRING      use the POST method; send STRING as the "
"data.\n"
msgstr ""

#: src/main.c:542
msgid ""
"       --post-file=FILE        use the POST method; send contents of FILE.\n"
msgstr ""

#: src/main.c:547
msgid "HTTPS (SSL/TLS) options:\n"
msgstr ""

#: src/main.c:549
msgid ""
"       --secure-protocol=PR     choose secure protocol, one of auto, SSLv2,\n"
"                                SSLv3, and TLSv1.\n"
msgstr ""

#: src/main.c:552
msgid ""
"       --no-check-certificate   don't validate the server's certificate.\n"
msgstr ""

#: src/main.c:554
msgid "       --certificate=FILE       client certificate file.\n"
msgstr ""

#: src/main.c:556
msgid "       --certificate-type=TYPE  client certificate type, PEM or DER.\n"
msgstr ""

#: src/main.c:558
msgid "       --private-key=FILE       private key file.\n"
msgstr ""

#: src/main.c:560
msgid "       --private-key-type=TYPE  private key type, PEM or DER.\n"
msgstr ""

#: src/main.c:562
msgid "       --ca-certificate=FILE    file with the bundle of CA's.\n"
msgstr ""

#: src/main.c:564
msgid ""
"       --ca-directory=DIR       directory where hash list of CA's is "
"stored.\n"
msgstr ""

#: src/main.c:566
msgid ""
"       --random-file=FILE       file with random data for seeding the SSL "
"PRNG.\n"
msgstr ""

#: src/main.c:568
msgid ""
"       --egd-file=FILE          file naming the EGD socket with random "
"data.\n"
msgstr ""

#: src/main.c:573
msgid "FTP options:\n"
msgstr ""

#: src/main.c:575
msgid "       --ftp-user=USER         set ftp user to USER.\n"
msgstr ""

#: src/main.c:577
msgid "       --ftp-password=PASS     set ftp password to PASS.\n"
msgstr ""

#: src/main.c:579
msgid "       --no-remove-listing     don't remove `.listing' files.\n"
msgstr ""

#: src/main.c:581
msgid "       --no-glob               turn off FTP file name globbing.\n"
msgstr ""

#: src/main.c:583
msgid "       --no-passive-ftp        disable the \"passive\" transfer mode.\n"
msgstr ""

#: src/main.c:585
msgid ""
"       --retr-symlinks         when recursing, get linked-to files (not "
"dir).\n"
msgstr ""

#: src/main.c:587
msgid "       --preserve-permissions  preserve remote file permissions.\n"
msgstr ""

#: src/main.c:591
msgid "Recursive download:\n"
msgstr ""

#: src/main.c:593
msgid "  -r,  --recursive          specify recursive download.\n"
msgstr ""

#: src/main.c:595
msgid ""
"  -l,  --level=NUMBER       maximum recursion depth (inf or 0 for "
"infinite).\n"
msgstr ""

#: src/main.c:597
msgid ""
"       --delete-after       delete files locally after downloading them.\n"
msgstr ""

#: src/main.c:599
msgid ""
"  -k,  --convert-links      make links in downloaded HTML point to local "
"files.\n"
msgstr ""

#: src/main.c:601
msgid ""
"  -K,  --backup-converted   before converting file X, back up as X.orig.\n"
msgstr ""

#: src/main.c:603
msgid ""
"  -m,  --mirror             shortcut option equivalent to -r -N -l inf -nr.\n"
msgstr ""

#: src/main.c:605
msgid ""
"  -p,  --page-requisites    get all images, etc. needed to display HTML "
"page.\n"
msgstr ""

#: src/main.c:607
msgid ""
"       --strict-comments    turn on strict (SGML) handling of HTML "
"comments.\n"
msgstr ""

#: src/main.c:611
msgid "Recursive accept/reject:\n"
msgstr ""

#: src/main.c:613
msgid ""
"  -A,  --accept=LIST               comma-separated list of accepted "
"extensions.\n"
msgstr ""

#: src/main.c:615
msgid ""
"  -R,  --reject=LIST               comma-separated list of rejected "
"extensions.\n"
msgstr ""

#: src/main.c:617
msgid ""
"  -D,  --domains=LIST              comma-separated list of accepted "
"domains.\n"
msgstr ""

#: src/main.c:619
msgid ""
"       --exclude-domains=LIST      comma-separated list of rejected "
"domains.\n"
msgstr ""

#: src/main.c:621
msgid ""
"       --follow-ftp                follow FTP links from HTML documents.\n"
msgstr ""

#: src/main.c:623
msgid ""
"       --follow-tags=LIST          comma-separated list of followed HTML "
"tags.\n"
msgstr ""

#: src/main.c:625
msgid ""
"       --ignore-tags=LIST          comma-separated list of ignored HTML "
"tags.\n"
msgstr ""

#: src/main.c:627
msgid ""
"  -H,  --span-hosts                go to foreign hosts when recursive.\n"
msgstr ""

#: src/main.c:629
msgid "  -L,  --relative                  follow relative links only.\n"
msgstr ""

#: src/main.c:631
msgid "  -I,  --include-directories=LIST  list of allowed directories.\n"
msgstr ""

#: src/main.c:633
msgid "  -X,  --exclude-directories=LIST  list of excluded directories.\n"
msgstr ""

#: src/main.c:635
msgid ""
"  -np, --no-parent                 don't ascend to the parent directory.\n"
msgstr ""

#: src/main.c:639
msgid "Mail bug reports and suggestions to <bug-wget@gnu.org>.\n"
msgstr "������� �������� ��������� ��� ��������� ��� <bug-wget@gnu.org>.\n"

#: src/main.c:644
#, c-format
msgid "GNU Wget %s, a non-interactive network retriever.\n"
msgstr "GNU Wget %s, ��� ��-��������� �������� ��������� ��������� �������.\n"

#: src/main.c:658
#, fuzzy
msgid "Copyright (C) 2005 Free Software Foundation, Inc.\n"
msgstr ""
"���������� ���������� (C) 1995, 1996, 1997, 1998, 2000, 2001 Free Software "
"Foundation, Inc.\n"

#: src/main.c:660
msgid ""
"This program is distributed in the hope that it will be useful,\n"
"but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
"MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
"GNU General Public License for more details.\n"
msgstr ""
"���� �� ��������� ���������� �� ��� ������ ��� �� ����� �������,\n"
"���� ����� ����� ������Ƿ ����� ���� ������ �������\n"
"���������������� � �������������� ��� ��� ������������ �����.\n"
"����������� ��� ������ ������� ����� GNU ��� ������������ ������������.\n"

#: src/main.c:665
#, fuzzy
msgid ""
"\n"
"Originally written by Hrvoje Niksic <hniksic@xemacs.org>.\n"
msgstr ""
"\n"
"�������� ������ ��� ��� Hrvoje Niksic <hniksic@arsdigita.com>.\n"

#. #### Something nicer should be printed here -- similar to the
#. pre-1.5 `--help' page.
#: src/main.c:711 src/main.c:780 src/main.c:859
#, c-format
msgid "Try `%s --help' for more options.\n"
msgstr "��������� `%s --help' ��� ������������ �������� ���������.\n"

#: src/main.c:777
#, c-format
msgid "%s: illegal option -- `-n%c'\n"
msgstr "%s: �� �������� ������� -- `-n%c'\n"

#: src/main.c:830
#, c-format
msgid "Can't be verbose and quiet at the same time.\n"
msgstr "��� ����� �� ����� �������������� ��� ���������� ��������.\n"

#: src/main.c:836
#, c-format
msgid "Can't timestamp and not clobber old files at the same time.\n"
msgstr ""
"��� ����� �� ����������� �������� �������� ��� ���������� �� ��� ���������� "
"�� ������ ���� ��� ��������.\n"

#: src/main.c:844
#, c-format
msgid "Cannot specify both --inet4-only and --inet6-only.\n"
msgstr ""

#. No URL specified.
#: src/main.c:854
#, c-format
msgid "%s: missing URL\n"
msgstr "%s: ������������ �� URL\n"

#: src/main.c:963
#, c-format
msgid "No URLs found in %s.\n"
msgstr "��� �������� URL ��� %s.\n"

#: src/main.c:972
#, c-format
msgid ""
"\n"
