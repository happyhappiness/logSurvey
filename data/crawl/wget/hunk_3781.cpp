 msgid "Unknown error"
 msgstr "����������� ������"
 
-#: src/http.c:621 src/http.c:1433
+#: src/http.c:625 src/http.c:1437
 msgid "Unable to establish SSL connection.\n"
 msgstr ""
 
-#: src/http.c:629
+#: src/http.c:633
 #, fuzzy, c-format
 msgid "Reusing connection to %s:%hu.\n"
 msgstr "������� ���������� � %s:%hu ����� ����������.\n"
 
-#: src/http.c:805
+#: src/http.c:809
 #, fuzzy, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "������ ������ ������� HTTP.\n"
 
-#: src/http.c:810
+#: src/http.c:814
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "������ %s ������, �������� ������... "
 
-#: src/http.c:854
+#: src/http.c:858
 msgid "End of file while parsing headers.\n"
 msgstr "����� ����� �� ����� ������� ����������.\n"
 
-#: src/http.c:865
+#: src/http.c:869
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "������ ������ (%s) � ����������.\n"
 
-#: src/http.c:905
+#: src/http.c:909
 msgid "No data received"
 msgstr "�� �������� ������� ������"
 
-#: src/http.c:907
+#: src/http.c:911
 msgid "Malformed status line"
 msgstr "�������� ������ �������"
 
-#: src/http.c:912
+#: src/http.c:916
 msgid "(no description)"
 msgstr "(��� ��������)"
 
-#: src/http.c:1030
+#: src/http.c:1034
 msgid "Authorization failed.\n"
 msgstr "����������� ������ ��������.\n"
 
-#: src/http.c:1037
+#: src/http.c:1041
 msgid "Unknown authentication scheme.\n"
 msgstr "����������� ����� �������� ����������.\n"
 
-#: src/http.c:1127
+#: src/http.c:1131
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "�����: %s%s\n"
 
-#: src/http.c:1128 src/http.c:1153
+#: src/http.c:1132 src/http.c:1157
 msgid "unspecified"
 msgstr "��� ����������"
 
-#: src/http.c:1129
+#: src/http.c:1133
 msgid " [following]"
 msgstr " [�������]"
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:1143
+#: src/http.c:1147
 msgid "Length: "
 msgstr "�����: "
 
-#: src/http.c:1148
+#: src/http.c:1152
 #, c-format
 msgid " (%s to go)"
 msgstr " (�������� %s)"
 
-#: src/http.c:1153
+#: src/http.c:1157
 msgid "ignored"
 msgstr "������������"
 
-#: src/http.c:1254
+#: src/http.c:1258
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr "��������������: � HTTP ������� �� ��������������.\n"
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:1275
+#: src/http.c:1279
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr "���� `%s' ��� ����������, ��������� �� ������������.\n"
 
-#: src/http.c:1425
+#: src/http.c:1429
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr "������ ������ � `%s' (%s).\n"
 
-#: src/http.c:1443
+#: src/http.c:1447
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr "������: ��������������� (%d) ��� �������� ������.\n"
 
-#: src/http.c:1468
+#: src/http.c:1472
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr "%s ������ %d: %s.\n"
 
-#: src/http.c:1481
+#: src/http.c:1485
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr "��� ��������� last-modified -- ��������� ������� ���������.\n"
 
-#: src/http.c:1489
+#: src/http.c:1493
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr ""
 "��������� last-modified ����������� -- ��������� ������� ������������.\n"
 
-#: src/http.c:1524
+#: src/http.c:1528
 msgid "Remote file is newer, retrieving.\n"
 msgstr "���� ����� ����������, ���������.\n"
 
-#: src/http.c:1559
+#: src/http.c:1573
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld/%ld]\n"
