 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: ���� ������� �������� ��������� -- %c\n"
 
-#: src/host.c:394
-#, c-format
-msgid "%s: Cannot determine user-id.\n"
-msgstr "%s: �� ������� ���������� ������������� ������������.\n"
-
-#: src/host.c:406
-#, c-format
-msgid "%s: Warning: uname failed: %s\n"
-msgstr "%s: ��������������: ��������� ����� uname: %s\n"
-
-#: src/host.c:418
-#, c-format
-msgid "%s: Warning: gethostname failed\n"
-msgstr "%s: ��������������: ��������� ����� gethostname\n"
-
-#: src/host.c:446
-#, c-format
-msgid "%s: Warning: cannot determine local IP address.\n"
-msgstr "%s: ��������������: ������ ����������� ���������� IP-������.\n"
-
-#: src/host.c:460
-#, c-format
-msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
-msgstr ""
-"%s: ��������������: ������ ��������� �������������� ���������� IP-������.\n"
-
-#. This gets ticked pretty often.  Karl Berry reports
-#. that there can be valid reasons for the local host
-#. name not to be an FQDN, so I've decided to remove the
-#. annoying warning.
-#: src/host.c:473
-#, c-format
-msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
-msgstr ""
-"%s: ��������������: ��� �������� �������������� IP-������ �� �������� FQDN!\n"
-
-#: src/host.c:501
+#: src/host.c:374
 msgid "Host not found"
 msgstr "���� �� ������"
 
-#: src/host.c:503
+#: src/host.c:376
 msgid "Unknown error"
 msgstr "����������� ������"
 
 #. this is fatal
-#: src/http.c:549
+#: src/http.c:554
 msgid "Failed to set up an SSL context\n"
-msgstr ""
+msgstr "�� ������� ���������� �������� SSL\n"
 
-#: src/http.c:555
+#: src/http.c:560
 #, c-format
 msgid "Failed to load certificates from %s\n"
-msgstr ""
+msgstr "�� ������� ��������� ����������� � %s\n"
 
-#: src/http.c:559 src/http.c:567
+#: src/http.c:564 src/http.c:572
 msgid "Trying without the specified certificate\n"
-msgstr ""
+msgstr "������� ���������� ��� ���������� �����������\n"
 
-#: src/http.c:563
+#: src/http.c:568
 #, c-format
 msgid "Failed to get certificate key from %s\n"
-msgstr ""
+msgstr "�� ������� �������� ���� ����������� � %s\n"
 
-#: src/http.c:657 src/http.c:1470
+#: src/http.c:662 src/http.c:1592
 msgid "Unable to establish SSL connection.\n"
-msgstr ""
+msgstr "�� ������� ���������� ���������� SSL.\n"
 
-#: src/http.c:665
-#, fuzzy, c-format
+#: src/http.c:670
+#, c-format
 msgid "Reusing connection to %s:%hu.\n"
-msgstr "������� ���������� � %s:%hu ����� ����������.\n"
+msgstr "��������� ������������� ���������� � %s:%hu.\n"
 
-#: src/http.c:841
-#, fuzzy, c-format
+#: src/http.c:860
+#, c-format
 msgid "Failed writing HTTP request: %s.\n"
-msgstr "������ ������ ������� HTTP.\n"
+msgstr "������ ������ ������� HTTP: %s.\n"
 
-#: src/http.c:846
+#: src/http.c:865
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "������ %s ������, �������� ������... "
 
-#: src/http.c:890
+#: src/http.c:909
 msgid "End of file while parsing headers.\n"
 msgstr "����� ����� �� ����� ������� ����������.\n"
 
-#: src/http.c:901
+#: src/http.c:919
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "������ ������ (%s) � ����������.\n"
 
-#: src/http.c:941
+#: src/http.c:958
 msgid "No data received"
 msgstr "�� �������� ������� ������"
 
-#: src/http.c:943
+#: src/http.c:960
 msgid "Malformed status line"
 msgstr "�������� ������ �������"
 
-#: src/http.c:948
+#: src/http.c:965
 msgid "(no description)"
 msgstr "(��� ��������)"
 
-#: src/http.c:1066
+#: src/http.c:1088
 msgid "Authorization failed.\n"
 msgstr "����������� ������ ��������.\n"
 
-#: src/http.c:1073
+#: src/http.c:1095
 msgid "Unknown authentication scheme.\n"
 msgstr "����������� ����� �������� ����������.\n"
 
-#: src/http.c:1163
+#: src/http.c:1135
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "�����: %s%s\n"
 
-#: src/http.c:1164 src/http.c:1189
+#: src/http.c:1136 src/http.c:1268
 msgid "unspecified"
 msgstr "��� ����������"
 
-#: src/http.c:1165
+#: src/http.c:1137
 msgid " [following]"
 msgstr " [�������]"
 
+#: src/http.c:1199
+msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
+msgstr "\n    ���� ��� ������� ���������; ��� ��������.\n\n"
+
+#: src/http.c:1215
+#, c-format
+msgid ""
+"\n"
+"The server does not support continued downloads, which conflicts with `-c'.\n"
+"Refusing to truncate existing file `%s'.\n"
+"\n"
+msgstr ""
+"\n"
+"������ �� ������������ ������������� ��� ��������� ������, ���������������\n"
+"������ -c. ������������ ���� `%s' �� ����� ������.\n"
+"\n"
+
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:1179
+#: src/http.c:1258
 msgid "Length: "
 msgstr "�����: "
 
-#: src/http.c:1184
+#: src/http.c:1263
 #, c-format
 msgid " (%s to go)"
 msgstr " (�������� %s)"
 
-#: src/http.c:1189
+#: src/http.c:1268
 msgid "ignored"
 msgstr "������������"
 
-#: src/http.c:1290
+#: src/http.c:1398
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "��������������: � HTTP ������� �� ��������������.\n"
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:1311
+#: src/http.c:1416
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "���� `%s' ��� ����������, ��������� �� ������������.\n"
 
-#: src/http.c:1462
+#: src/http.c:1584
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "������ ������ � `%s' (%s).\n"
 
-#: src/http.c:1480
+#: src/http.c:1601
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "������: ��������������� (%d) ��� �������� ������.\n"
 
-#: src/http.c:1505
+#: src/http.c:1629
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s ������ %d: %s.\n"
 
-#: src/http.c:1518
+#: src/http.c:1641
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr "��� ��������� last-modified -- ��������� ������� ���������.\n"
 
-#: src/http.c:1526
+#: src/http.c:1649
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
-msgstr ""
-"��������� last-modified ����������� -- ��������� ������� ������������.\n"
+msgstr "��������� last-modified ����������� -- ��������� ������� ������������.\n"
 
-#: src/http.c:1549
+#: src/http.c:1672
 #, c-format
-msgid ""
-"Server file no newer than local file `%s' -- not retrieving.\n"
-"\n"
+msgid "Server file no newer than local file `%s' -- not retrieving.\n\n"
 msgstr "���� �� ������� �� ����� ���������� ����� `%s' -- �������.\n"
 
-#: src/http.c:1557
+#: src/http.c:1679
 #, c-format
 msgid "The sizes do not match (local %ld) -- retrieving.\n"
 msgstr "������� ������ �� ��������� (��������� ������ %ld) -- ���������.\n"
 
-#: src/http.c:1561
+#: src/http.c:1683
 msgid "Remote file is newer, retrieving.\n"
 msgstr "���� ����� ����������, ���������.\n"
 
-#: src/http.c:1606
+#: src/http.c:1727
 #, c-format
-msgid ""
-"%s (%s) - `%s' saved [%ld/%ld]\n"
-"\n"
-msgstr ""
-"%s (%s) - `%s' �������� [%ld/%ld]\n"
-"\n"
+msgid "%s (%s) - `%s' saved [%ld/%ld]\n\n"
+msgstr "%s (%s) - `%s' �������� [%ld/%ld]\n\n"
 
-#: src/http.c:1654
+#: src/http.c:1773
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld. "
 msgstr "%s (%s) - ���������� �������, ������� %ld. "
 
-#: src/http.c:1662
+#: src/http.c:1781
 #, c-format
-msgid ""
-"%s (%s) - `%s' saved [%ld/%ld])\n"
-"\n"
-msgstr ""
-"%s (%s) - `%s' �������� [%ld/%ld])\n"
-"\n"
+msgid "%s (%s) - `%s' saved [%ld/%ld])\n\n"
+msgstr "%s (%s) - `%s' �������� [%ld/%ld])\n\n"
 
-#: src/http.c:1682
+#: src/http.c:1800
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld/%ld. "
 msgstr "%s (%s) - ���������� �������, ������� %ld/%ld. "
 
-#: src/http.c:1693
+#: src/http.c:1811
 #, c-format
 msgid "%s (%s) - Read error at byte %ld (%s)."
 msgstr "%s (%s) - ������ ������, ������� %ld (%s)."
 
-#: src/http.c:1701
+#: src/http.c:1819
 #, c-format
 msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
 msgstr "%s (%s) - ������ ������, ������� %ld/%ld (%s). "
 
-#: src/init.c:336 src/netrc.c:261
+#: src/init.c:348 src/netrc.c:267
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
 msgstr "%s: ������ ������ %s (%s).\n"
 
-#: src/init.c:354 src/init.c:360
+#: src/init.c:366 src/init.c:372
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
 msgstr "%s: ������ � %s � ������ %d.\n"
 
-#: src/init.c:391
+#: src/init.c:404
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
-msgstr ""
-"%s: ��������������: ��������� � ���������������� wgetrc ��������� �� `%s'.\n"
+msgstr "%s: ��������������: ��������� � ���������������� wgetrc ��������� �� `%s'.\n"
 
-#: src/init.c:483
+#: src/init.c:496
 #, c-format
 msgid "%s: BUG: unknown command `%s', value `%s'.\n"
 msgstr "%s: ������ � ���������: ����������� ������� `%s', �������� `%s'.\n"
 
-#: src/init.c:504
+#: src/init.c:528
 #, c-format
 msgid "%s: %s: Cannot convert `%s' to an IP address.\n"
 msgstr "%s: %s: ������ ����������� IP-������ ��� `%s'.\n"
 
-#: src/init.c:532
+#: src/init.c:558
 #, c-format
 msgid "%s: %s: Please specify on or off.\n"
 msgstr "%s: %s: ����������, ������� on ��� off.\n"
 
-#: src/init.c:576
+#: src/init.c:602
 #, c-format
 msgid "%s: %s: Please specify always, on, off, or never.\n"
 msgstr "%s: %s: ����������, ������� always, on, off ��� never.\n"
 
-#: src/init.c:595 src/init.c:852 src/init.c:874 src/init.c:938
+#: src/init.c:621 src/init.c:918 src/init.c:940 src/init.c:1004
 #, c-format
 msgid "%s: %s: Invalid specification `%s'.\n"
 msgstr "%s: %s: ������������ �������� `%s'.\n"
 
-#: src/init.c:708 src/init.c:730 src/init.c:752 src/init.c:778
+#: src/init.c:774 src/init.c:796 src/init.c:818 src/init.c:844
 #, c-format
 msgid "%s: Invalid specification `%s'\n"
 msgstr "%s: ������������ �������� `%s'\n"
 
-#: src/main.c:120
+#: src/main.c:119
 #, c-format
 msgid "Usage: %s [OPTION]... [URL]...\n"
 msgstr "�������������: %s [����]... [URL]...\n"
 
-#: src/main.c:128
+#: src/main.c:127
 #, c-format
 msgid "GNU Wget %s, a non-interactive network retriever.\n"
 msgstr "GNU Wget %s, ��������� ��������������� ��������� ������ �� ����.\n"
 
 #. Had to split this in parts, so the #@@#%# Ultrix compiler and cpp
 #. don't bitch.  Also, it makes translation much easier.
-#: src/main.c:133
-msgid ""
-"\n"
-"Mandatory arguments to long options are mandatory for short options too.\n"
-"\n"
-msgstr ""
-"\n"
-"�������� ����� ������� �������� ��� �� ����������, ��� � ������� �����.\n"
-"\n"
+#: src/main.c:132
+msgid "\nMandatory arguments to long options are mandatory for short options too.\n\n"
+msgstr "\n�������� ����� ������� �������� ��� �� ����������, ��� � ������� �����.\n\n"
 
 #: src/main.c:136
 msgid ""