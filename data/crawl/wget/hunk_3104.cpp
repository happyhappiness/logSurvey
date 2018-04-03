-# Russian messages for GNU Wget.
-# Copyright (C) 1998, 1999, 2000, 2001 Free Software Foundation, Inc.
+# Translation of wget-1.9.1.ru.po to Russian
+# Copyright (C) 1998, 1999, 2000, 2001, 2004 Free Software Foundation, Inc.
 # Const Kaplinsky <const@ce.cctpu.edu.ru>, 1998, 1999, 2000, 2001.
+# Pavel Maryanov <acid_jack@ukr.net>, 2004.
 #
 msgid ""
 msgstr ""
-"Project-Id-Version: wget 1.8\n"
-"POT-Creation-Date: 2001-12-08 23:28+0100\n"
-"PO-Revision-Date: 2001-12-10 22:22+07:00\n"
-"Last-Translator: Const Kaplinsky <const@ce.cctpu.edu.ru>\n"
+"Project-Id-Version: wget 1.9.1\n"
+"POT-Creation-Date: 2003-10-11 16:21+0200\n"
+"PO-Revision-Date: 2004-05-13 11:35+0300\n"
+"Last-Translator: Pavel Maryanov <acid_jack@ukr.net>\n"
 "Language-Team: Russian <ru@li.org>\n"
 "MIME-Version: 1.0\n"
-"Content-Type: text/plain; charset=koi8-r\n"
+"Content-Type: text/plain; charset=KOI8-R\n"
 "Content-Transfer-Encoding: 8bit\n"
+"X-Generator: KBabel 1.0.2\n"
 
-#: src/connect.c:94
+#: src/connect.c:88
+#, c-format
+msgid "Unable to convert `%s' to a bind address.  Reverting to ANY.\n"
+msgstr "���������� ������������� `%s' � ��������� �����. ������� � ANY.\n"
+
+#: src/connect.c:165
 #, c-format
 msgid "Connecting to %s[%s]:%hu... "
-msgstr "��������� ���������� � %s[%s]:%hu... "
+msgstr "��������������� ���������� � %s[%s]:%hu... "
 
-#: src/connect.c:97
+#: src/connect.c:168
 #, c-format
 msgid "Connecting to %s:%hu... "
-msgstr "��������� ���������� � %s:%hu... "
+msgstr "��������������� ���������� � %s:%hu... "
 
-#: src/connect.c:131
+#: src/connect.c:222
 msgid "connected.\n"
-msgstr "�����������.\n"
+msgstr "���������� �����������.\n"
+
+#: src/convert.c:171
+#, c-format
+msgid "Converted %d files in %.2f seconds.\n"
+msgstr "������������� %d ������ �� %.2f ������.\n"
 
-#: src/cookies.c:595
+#: src/convert.c:197
+#, c-format
+msgid "Converting %s... "
+msgstr "����������� �������������� %s... "
+
+#: src/convert.c:210
+msgid "nothing to do.\n"
+msgstr "������ ���������.\n"
+
+#: src/convert.c:218 src/convert.c:242
+#, c-format
+msgid "Cannot convert links in %s: %s\n"
+msgstr "���������� ������������� ������ � %s: %s\n"
+
+#: src/convert.c:233
+#, c-format
+msgid "Unable to delete `%s': %s\n"
+msgstr "���������� ������� `%s': %s\n"
+
+#: src/convert.c:439
+#, c-format
+msgid "Cannot back up %s as %s: %s\n"
+msgstr "���������� ��������� %s ��� ������ %s: %s\n"
+
+#: src/cookies.c:606
 #, c-format
 msgid "Error in Set-Cookie, field `%s'"
 msgstr "������ � Set-Cookie, ���� `%s'"
 
-#: src/cookies.c:619
+#: src/cookies.c:629
 #, c-format
-msgid "Syntax error in Set-Cookie at character `%c'.\n"
-msgstr "�������������� ������ � Set-Cookie, ������ `%c'.\n"
-
-#: src/cookies.c:627
-msgid "Syntax error in Set-Cookie: premature end of string.\n"
-msgstr "�������������� ������ � Set-Cookie: ��������������� ����� ������.\n"
+msgid "Syntax error in Set-Cookie: %s at position %d.\n"
+msgstr "�������������� ������ � Set-Cookie: %s � ������� %d.\n"
 
-#: src/cookies.c:1329
+#: src/cookies.c:1426
 #, c-format
 msgid "Cannot open cookies file `%s': %s\n"
-msgstr "�� ������� ������� ���� � \"cookies\", `%s': %s\n"
+msgstr "���������� ������� ���� cookies, `%s': %s\n"
 
-#: src/cookies.c:1341
+#: src/cookies.c:1438
 #, c-format
 msgid "Error writing to `%s': %s\n"
 msgstr "������ ������ � `%s': %s\n"
 
-#: src/cookies.c:1345
+#: src/cookies.c:1442
 #, c-format
 msgid "Error closing `%s': %s\n"
 msgstr "������ �������� `%s': %s\n"
 
-#: src/ftp-ls.c:787
+#: src/ftp-ls.c:812
 msgid "Unsupported listing type, trying Unix listing parser.\n"
-msgstr "������ �������� �� ��������������, ������� ������������� Unix-�������.\n"
+msgstr "���������������� ������ ��������, ��������� ������ �������� ��� Unix.\n"
 
-#: src/ftp-ls.c:832 src/ftp-ls.c:834
+#: src/ftp-ls.c:857 src/ftp-ls.c:859
 #, c-format
 msgid "Index of /%s on %s:%d"
-msgstr "������� �������� /%s �� %s:%d"
+msgstr "������ /%s �� %s:%d"
 
-#: src/ftp-ls.c:856
+#: src/ftp-ls.c:882
 msgid "time unknown       "
 msgstr "����� ����������   "
 
-#: src/ftp-ls.c:860
+#: src/ftp-ls.c:886
 msgid "File        "
 msgstr "����        "
 
-#: src/ftp-ls.c:863
+#: src/ftp-ls.c:889
 msgid "Directory   "
 msgstr "�������     "
 
-#: src/ftp-ls.c:866
+#: src/ftp-ls.c:892
 msgid "Link        "
 msgstr "������      "
 
-#: src/ftp-ls.c:869
+#: src/ftp-ls.c:895
 msgid "Not sure    "
 msgstr "����������  "
 
-#: src/ftp-ls.c:887
+#: src/ftp-ls.c:913
 #, c-format
 msgid " (%s bytes)"
 msgstr " (%s ����)"
 
 #. Second: Login with proper USER/PASS sequence.
-#: src/ftp.c:179
+#: src/ftp.c:202
 #, c-format
 msgid "Logging in as %s ... "
-msgstr "����������� ��� ������ %s ... "
+msgstr "����������� ���� ��� ������ %s ... "
 
-#: src/ftp.c:188 src/ftp.c:241 src/ftp.c:272 src/ftp.c:326 src/ftp.c:419
-#: src/ftp.c:470 src/ftp.c:500 src/ftp.c:564 src/ftp.c:628 src/ftp.c:689
-#: src/ftp.c:737
+#: src/ftp.c:215 src/ftp.c:268 src/ftp.c:299 src/ftp.c:353 src/ftp.c:468
+#: src/ftp.c:519 src/ftp.c:551 src/ftp.c:611 src/ftp.c:675 src/ftp.c:748
+#: src/ftp.c:796
 msgid "Error in server response, closing control connection.\n"
-msgstr "������ � ������� �������, �������� ������������ ����������.\n"
+msgstr "������ � ������ �������, ����������� ���������� �����������.\n"
 
-#: src/ftp.c:196
+#: src/ftp.c:223
 msgid "Error in server greeting.\n"
 msgstr "������ � ����������� �������.\n"
 
-#: src/ftp.c:204 src/ftp.c:335 src/ftp.c:428 src/ftp.c:509 src/ftp.c:574
-#: src/ftp.c:638 src/ftp.c:699 src/ftp.c:747
+#: src/ftp.c:231 src/ftp.c:362 src/ftp.c:477 src/ftp.c:560 src/ftp.c:621
+#: src/ftp.c:685 src/ftp.c:758 src/ftp.c:806
 msgid "Write failed, closing control connection.\n"
-msgstr "������ ������, �������� ������������ ����������.\n"
+msgstr "������ ������, ����������� ���������� �����������.\n"
 
-#: src/ftp.c:211
+#: src/ftp.c:238
 msgid "The server refuses login.\n"
-msgstr "������ �������� �����������.\n"
+msgstr "������ �������� �����.\n"
 
-#: src/ftp.c:218
+#: src/ftp.c:245
 msgid "Login incorrect.\n"
-msgstr "������������ ��� ��� ������.\n"
+msgstr "�������� �����.\n"
 
-#: src/ftp.c:225
+#: src/ftp.c:252
 msgid "Logged in!\n"
-msgstr "����������� ������ �������!\n"
+msgstr "�������� ���� � �������!\n"
 
-#: src/ftp.c:250
+#: src/ftp.c:277
 msgid "Server error, can't determine system type.\n"
-msgstr "������ �� �������, �� ������� ���������� ��� �������.\n"
+msgstr "������ �������, ���������� ���������� ��� �������.\n"
 
-#: src/ftp.c:260 src/ftp.c:549 src/ftp.c:612 src/ftp.c:669
+#: src/ftp.c:287 src/ftp.c:596 src/ftp.c:659 src/ftp.c:716
 msgid "done.    "
-msgstr "�������.    "
+msgstr "������.  "
 
-#: src/ftp.c:314 src/ftp.c:449 src/ftp.c:484 src/ftp.c:720 src/ftp.c:768
-#: src/host.c:280
+#: src/ftp.c:341 src/ftp.c:498 src/ftp.c:533 src/ftp.c:779 src/ftp.c:827
 msgid "done.\n"
-msgstr "�������.\n"
+msgstr "������.\n"
 
-#: src/ftp.c:343
+#: src/ftp.c:370
 #, c-format
 msgid "Unknown type `%c', closing control connection.\n"
-msgstr "����������� ��� `%c', �������� ������������ ����������.\n"
+msgstr "����������� ��� `%c', ����������� ���������� �����������.\n"
 
-#: src/ftp.c:356
+#: src/ftp.c:383
 msgid "done.  "
-msgstr "�������.  "
+msgstr "������.   "
 
-#: src/ftp.c:362
+#: src/ftp.c:389
 msgid "==> CWD not needed.\n"
-msgstr "==> CWD �� �����.\n"
+msgstr "==> CWD �� �����.\n"
 
-#: src/ftp.c:435
+#: src/ftp.c:484
 #, c-format
-msgid "No such directory `%s'.\n\n"
-msgstr "����������� ������� `%s'.\n\n"
+msgid ""
+"No such directory `%s'.\n"
+"\n"
+msgstr ""
+"��� ������ �������� `%s'.\n"
+"\n"
 
 #. do not CWD
-#: src/ftp.c:453
+#: src/ftp.c:502
 msgid "==> CWD not required.\n"
 msgstr "==> CWD �� ���������.\n"
 
-#: src/ftp.c:516
+#: src/ftp.c:567
 msgid "Cannot initiate PASV transfer.\n"
-msgstr "�� ������� ������ PASV-��������.\n"
+msgstr "���������� ������ PASV-��������.\n"
 
-#: src/ftp.c:520
+#: src/ftp.c:571
 msgid "Cannot parse PASV response.\n"
-msgstr "������ ��������������� ������� ������ PASV.\n"
+msgstr "������ �������� ������ PASV.\n"
 
-#: src/ftp.c:541
+#: src/ftp.c:588
 #, c-format
 msgid "couldn't connect to %s:%hu: %s\n"
-msgstr "�� ������� ����������� � %s:%hu: %s\n"
+msgstr "���������� ���� ����������� � %s:%hu: %s\n"
 
-#: src/ftp.c:591
+#: src/ftp.c:638
 #, c-format
 msgid "Bind error (%s).\n"
 msgstr "������ bind (%s).\n"
 
-#: src/ftp.c:598
+#: src/ftp.c:645
 msgid "Invalid PORT.\n"
 msgstr "������������ PORT.\n"
 
-#: src/ftp.c:651
+#: src/ftp.c:698
 #, c-format
-msgid "\nREST failed; will not truncate `%s'.\n"
-msgstr "\n������� REST �� ���������; �������� `%s' �� ������������.\n"
+msgid ""
+"\n"
+"REST failed; will not truncate `%s'.\n"
+msgstr ""
+"\n"
+"���� REST; `%s' �� ����� �������.\n"
 
-#: src/ftp.c:658
-msgid "\nREST failed, starting from scratch.\n"
-msgstr "\n������� REST �� ���������, ������ � ������� �������.\n"
+#: src/ftp.c:705
+msgid ""
+"\n"
+"REST failed, starting from scratch.\n"
+msgstr ""
+"\n"
+"���� REST, ������ � ������.\n"
 
-#: src/ftp.c:707
+#: src/ftp.c:766
 #, c-format
-msgid "No such file `%s'.\n\n"
-msgstr "����������� ���� `%s'.\n\n"
+msgid ""
+"No such file `%s'.\n"
+"\n"
+msgstr ""
+"��� ������ ����� `%s'.\n"
+"\n"
 
-#: src/ftp.c:755
+#: src/ftp.c:814
 #, c-format
-msgid "No such file or directory `%s'.\n\n"
-msgstr "����������� ���� ��� ������� `%s'.\n\n"
+msgid ""
+"No such file or directory `%s'.\n"
+"\n"
+msgstr ""
+"��� ������ ����� ��� �������� `%s'.\n"
+"\n"
 
-#: src/ftp.c:839 src/ftp.c:847
+#: src/ftp.c:898 src/ftp.c:906
 #, c-format
 msgid "Length: %s"
 msgstr "�����: %s"
 
-#: src/ftp.c:841 src/ftp.c:849
+#: src/ftp.c:900 src/ftp.c:908
 #, c-format
 msgid " [%s to go]"
 msgstr " [�������� %s]"
 
-#: src/ftp.c:851
+#: src/ftp.c:910
 msgid " (unauthoritative)\n"
 msgstr " (�� ����������)\n"
 
-#: src/ftp.c:877
+#: src/ftp.c:936
 #, c-format
 msgid "%s: %s, closing control connection.\n"
-msgstr "%s: %s, �������� ������������ ����������.\n"
+msgstr "%s: %s, ����������� ���������� �����������.\n"
 
-#: src/ftp.c:885
+#: src/ftp.c:944
 #, c-format
 msgid "%s (%s) - Data connection: %s; "
 msgstr "%s (%s) - ����������: %s; "
 
-#: src/ftp.c:902
+#: src/ftp.c:961
 msgid "Control connection closed.\n"
 msgstr "����������� ���������� �������.\n"
 
-#: src/ftp.c:920
+#: src/ftp.c:979
 msgid "Data transfer aborted.\n"
 msgstr "�������� ������ ��������.\n"
 
-#: src/ftp.c:984
+#: src/ftp.c:1044
 #, c-format
 msgid "File `%s' already there, not retrieving.\n"
-msgstr "���� `%s' ��� ����������, �������� �� ���������.\n"
+msgstr "���� `%s' ��� ����������, �� �����������.\n"
 
-#: src/ftp.c:1054 src/http.c:1527
+#: src/ftp.c:1114 src/http.c:1716
 #, c-format
 msgid "(try:%2d)"
 msgstr "(�������:%2d)"
 
-#: src/ftp.c:1118 src/http.c:1786
+#: src/ftp.c:1180 src/http.c:1975
 #, c-format
-msgid "%s (%s) - `%s' saved [%ld]\n\n"
-msgstr "%s (%s) - `%s' �������� [%ld]\n\n"
+msgid ""
+"%s (%s) - `%s' saved [%ld]\n"
+"\n"
+msgstr ""
+"%s (%s) - `%s' �������� [%ld]\n"
+"\n"
 
-#: src/ftp.c:1160 src/main.c:822 src/recur.c:349 src/retr.c:587
+#: src/ftp.c:1222 src/main.c:890 src/recur.c:377 src/retr.c:596
 #, c-format
 msgid "Removing %s.\n"
-msgstr "�������� %s.\n"
+msgstr "��������� %s.\n"
 
-#: src/ftp.c:1202
+#: src/ftp.c:1264
 #, c-format
 msgid "Using `%s' as listing tmp file.\n"
-msgstr "������� ����� �������� �� ��������� ����� `%s'.\n"
+msgstr "`%s' ������������ ��� ��������� ���� ��� ��������.\n"
 
-#: src/ftp.c:1217
+#: src/ftp.c:1279
 #, c-format
 msgid "Removed `%s'.\n"
 msgstr "������ `%s'.\n"
 
-#: src/ftp.c:1252
+#: src/ftp.c:1314
 #, c-format
 msgid "Recursion depth %d exceeded max. depth %d.\n"
 msgstr "������� �������� %d ��������� ������������ ������� %d.\n"
 
 #. Remote file is older, file sizes can be compared and
 #. are both equal.
-#: src/ftp.c:1317
+#: src/ftp.c:1384
 #, c-format
 msgid "Remote file no newer than local file `%s' -- not retrieving.\n"
-msgstr "���� �� ������� �� ����� ���������� ����� `%s' -- �������.\n"
+msgstr "��������� ���� �� ����� ���������� ����� `%s' -- �� �����������.\n"
 
 #. Remote file is newer or sizes cannot be matched
-#: src/ftp.c:1324
+#: src/ftp.c:1391
 #, c-format
-msgid "Remote file is newer than local file `%s' -- retrieving.\n\n"
-msgstr "���� �� ������� ����� ���������� ����� `%s' -- ���������.\n"
+msgid ""
+"Remote file is newer than local file `%s' -- retrieving.\n"
+"\n"
+msgstr "��������� ���� ����� ���������� ����� `%s' -- �����������.\n"
 
 #. Sizes do not match
-#: src/ftp.c:1331
+#: src/ftp.c:1398
 #, c-format
-msgid "The sizes do not match (local %ld) -- retrieving.\n\n"
-msgstr "������� �� ��������� (��������� ������ %ld) -- ���������.\n"
+msgid ""
+"The sizes do not match (local %ld) -- retrieving.\n"
+"\n"
+msgstr "������� �� ��������� (��������� ������ %ld) -- �����������.\n"
 
-#: src/ftp.c:1348
+#: src/ftp.c:1415
 msgid "Invalid name of the symlink, skipping.\n"
-msgstr "������������ ��� ���������� ������, ���������.\n"
+msgstr "������������ ��� ������������� ������, ������������.\n"
 
-#: src/ftp.c:1365
+#: src/ftp.c:1432
 #, c-format
-msgid "Already have correct symlink %s -> %s\n\n"
-msgstr "���������� ������ %s -> %s ��� ����������.\n\n"
+msgid ""
+"Already have correct symlink %s -> %s\n"
+"\n"
+msgstr ""
+"���������� ������������� ������ %s -> %s ��� ����������.\n"
+"\n"
 
-#: src/ftp.c:1373
+#: src/ftp.c:1440
 #, c-format
 msgid "Creating symlink %s -> %s\n"
-msgstr "�������� ���������� ������ %s -> %s\n"
+msgstr "�������� ������������� ������ %s -> %s\n"
 
-#: src/ftp.c:1384
+#: src/ftp.c:1451
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
-msgstr "���������� ������ �� ��������������, ������� `%s'.\n"
+msgstr "������������� ������ �� ��������������, ������ `%s' ������������.\n"
 
-#: src/ftp.c:1396
+#: src/ftp.c:1463
 #, c-format
 msgid "Skipping directory `%s'.\n"
-msgstr "������� �������� `%s'.\n"
+msgstr "������������ ������� `%s'.\n"
 
-#: src/ftp.c:1405
+#: src/ftp.c:1472
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
-msgstr "%s: ��� ����� ���������� ��� �� ��������������.\n"
+msgstr "%s: �����������/���������������� ��� �����.\n"
 
-#: src/ftp.c:1432
+#: src/ftp.c:1499
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
-msgstr "%s: �������� ����� ��������� �����.\n"
+msgstr "%s: ���������� ����� ����/�������.\n"
 
-#: src/ftp.c:1457
+#: src/ftp.c:1524
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
-msgstr "�������� �� ����� ��������, ������� ���������� %d (�������� %d).\n"
+msgstr "�������� �� ����� ���������, �.�. ������� ���������� %d (�������� %d).\n"
 
-#: src/ftp.c:1507
+#: src/ftp.c:1574
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
-msgstr "������� `%s' ��������, ��� ��� ��������� � ������ �����������.\n"
+msgstr "���� � ������� `%s' �� �����������, �.�. �� ��������/�� �������.\n"
 
-#: src/ftp.c:1561
+#: src/ftp.c:1639 src/ftp.c:1652
 #, c-format
 msgid "Rejecting `%s'.\n"
-msgstr "������� `%s'.\n"
+msgstr "����������� `%s'.\n"
 
 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1608
+#: src/ftp.c:1698
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "��� ���������� � �������� `%s'.\n"
 
-#: src/ftp.c:1673
+#: src/ftp.c:1764
 #, c-format
 msgid "Wrote HTML-ized index to `%s' [%ld].\n"
-msgstr "������� � ������� HTML ������� � ���� `%s' [%ld].\n"
+msgstr "������ � ������� HTML ������� � ���� `%s' [%ld].\n"
 
-#: src/ftp.c:1678
+#: src/ftp.c:1769
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
-msgstr "������� � ������� HTML ������� � ���� `%s'.\n"
+msgstr "������ � ������� HTML ������� � ���� `%s'.\n"
 
-#: src/gen_sslfunc.c:109
+#: src/gen_sslfunc.c:117
 msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
-msgstr "�� ������� ���������������� PRNG � OpenSSL; �������� SSL ��������.\n"
+msgstr "���������� �������� PRNG � OpenSSL; �������� SSL �����������.\n"
 
-#: src/getopt.c:454
+#: src/getopt.c:675
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
-msgstr "%s: ���� `%s' ���������� � ������ ���������\n"
+msgstr "%s: ����� `%s' ������������\n"
 
-#: src/getopt.c:478
+#: src/getopt.c:700
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
-msgstr "%s: ���� `--%s' �� ��������� �������� ��������\n"
+msgstr "%s: ����� `--%s' �� ��������� ������������ ��������\n"
 
-#: src/getopt.c:483
+#: src/getopt.c:705
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
-msgstr "%s: ���� `%c%s' �� ��������� �������� ��������\n"
+msgstr "%s: ����� `%c%s' �� ��������� ������������ ��������\n"
 
-#: src/getopt.c:498
+#: src/getopt.c:723 src/getopt.c:896
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
-msgstr "%s: ���� `%s' ������� �������� ���������\n"
+msgstr "%s: ��� ����� `%s' ��������� ��������\n"
 
 #. --option
-#: src/getopt.c:528
+#: src/getopt.c:752
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
-msgstr "%s: �������������� ���� `--%s'\n"
+msgstr "%s: �������������� ����� `--%s'\n"
 
 #. +option or -option
-#: src/getopt.c:532
+#: src/getopt.c:756
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
-msgstr "%s: �������������� ���� `%c%s'\n"
+msgstr "%s: �������������� ����� `%c%s'\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:563
+#: src/getopt.c:782
 #, c-format
 msgid "%s: illegal option -- %c\n"
-msgstr "%s: ������������ ���� ��������� ������ -- %c\n"
+msgstr "%s: ������������ ����� -- %c\n"
+
+#: src/getopt.c:785
+#, c-format
+msgid "%s: invalid option -- %c\n"
+msgstr "%s: �������� ����� -- %c\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:602
+#: src/getopt.c:815 src/getopt.c:945
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
-msgstr "%s: ���� ������� �������� ��������� -- %c\n"
+msgstr "%s: ��� ����� ��������� �������� -- %c\n"
 
-#: src/host.c:268
+#: src/getopt.c:862
+#, c-format
+msgid "%s: option `-W %s' is ambiguous\n"
+msgstr "%s: ����� `-W %s' ������������\n"
+
+#: src/getopt.c:880
+#, c-format
+msgid "%s: option `-W %s' doesn't allow an argument\n"
+msgstr "%s: ����� `-W %s' �� ��������� ������������ ��������\n"
+
+#: src/host.c:636
 #, c-format
 msgid "Resolving %s... "
-msgstr "�������������� ������ %s... "
+msgstr "������������ %s... "
 
-#: src/host.c:275
+#: src/host.c:656 src/host.c:672
 #, c-format
 msgid "failed: %s.\n"
-msgstr "������: %s.\n"
+msgstr "����: %s.\n"
+
+#: src/host.c:674
+msgid "failed: timed out.\n"
+msgstr "����: �������� ����-���.\n"
 
-#: src/host.c:345
+#: src/host.c:762
 msgid "Host not found"
 msgstr "���� �� ������"
 
-#: src/host.c:347
+#: src/host.c:764
 msgid "Unknown error"
 msgstr "����������� ������"
 
+#: src/html-url.c:293
+#, c-format
+msgid "%s: Cannot resolve incomplete link %s.\n"
+msgstr "%s: ���������� ���������� �������� ������ %s.\n"
+
 #. this is fatal
-#: src/http.c:573
+#: src/http.c:674
 msgid "Failed to set up an SSL context\n"
-msgstr "�� ������� ���������� �������� SSL\n"
+msgstr "���� ��������� ��������� SSL\n"
 
-#: src/http.c:579
+#: src/http.c:680
 #, c-format
 msgid "Failed to load certificates from %s\n"
-msgstr "�� ������� ��������� ����������� � %s\n"
+msgstr "���� �������� ������������ �� %s\n"
 
-#: src/http.c:583 src/http.c:591
+#: src/http.c:684 src/http.c:692
 msgid "Trying without the specified certificate\n"
-msgstr "������� ���������� ��� ���������� �����������\n"
+msgstr "����������� ������� ��� ���������� �����������\n"
 
-#: src/http.c:587
+#: src/http.c:688
 #, c-format
 msgid "Failed to get certificate key from %s\n"
-msgstr "�� ������� �������� ���� ����������� � %s\n"
+msgstr "���� ��������� ����� ����������� �� %s\n"
 
-#: src/http.c:657 src/http.c:1620
+#: src/http.c:761 src/http.c:1809
 msgid "Unable to establish SSL connection.\n"
-msgstr "�� ������� ���������� ���������� SSL.\n"
+msgstr "���������� ���������� ���������� SSL.\n"
 
-#: src/http.c:666
+#: src/http.c:770
 #, c-format
 msgid "Reusing connection to %s:%hu.\n"
 msgstr "��������� ������������� ���������� � %s:%hu.\n"
 
-#: src/http.c:868
+#: src/http.c:1034
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
-msgstr "������ ������ ������� HTTP: %s.\n"
+msgstr "���� ������ ������� HTTP: %s.\n"
 
-#: src/http.c:873
+#: src/http.c:1039
 #, c-format
 msgid "%s request sent, awaiting response... "
-msgstr "������ %s ������, �������� ������... "
+msgstr "������ %s ������, ��������� �����... "
 
-#: src/http.c:917
+#: src/http.c:1083
 msgid "End of file while parsing headers.\n"
-msgstr "����� ����� �� ����� ������� ����������.\n"
+msgstr "����� ����� ��� ������� ����������.\n"
 
-#: src/http.c:927
+#: src/http.c:1093
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "������ ������ (%s) � ����������.\n"
 
-#: src/http.c:962
+#: src/http.c:1128
 msgid "No data received"
 msgstr "�� �������� ������� ������"
 
-#: src/http.c:964
+#: src/http.c:1130
 msgid "Malformed status line"
 msgstr "�������� ������ �������"
 
-#: src/http.c:969
+#: src/http.c:1135
 msgid "(no description)"
 msgstr "(��� ��������)"
 
-#: src/http.c:1101
+#: src/http.c:1267
 msgid "Authorization failed.\n"
-msgstr "����������� ������ ��������.\n"
+msgstr "���� �����������.\n"
 
-#: src/http.c:1108
+#: src/http.c:1274
 msgid "Unknown authentication scheme.\n"
-msgstr "����������� ����� �������� ����������.\n"
+msgstr "����������� ����� ��������������.\n"
 
-#: src/http.c:1148
+#: src/http.c:1314
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "�����: %s%s\n"
 
-#: src/http.c:1149 src/http.c:1282
+#: src/http.c:1315 src/http.c:1454
 msgid "unspecified"
 msgstr "��� ����������"
 
-#: src/http.c:1150
+#: src/http.c:1316
 msgid " [following]"
 msgstr " [�������]"
 
-#: src/http.c:1213
-msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
-msgstr "\n    ���� ��� ������� ���������; ��� ��������.\n\n"
+#: src/http.c:1383
+msgid ""
+"\n"
+"    The file is already fully retrieved; nothing to do.\n"
+"\n"
+msgstr ""
+"\n"
+"    ���� ��� ��������� ��������; ������ ���������.\n"
+"\n"
 
-#: src/http.c:1229
+#: src/http.c:1401
 #, c-format
 msgid ""
 "\n"
