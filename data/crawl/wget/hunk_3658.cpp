 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: �� ������� ��������� stat ��� %s: %s\n"
 
-#: src/recur.c:510
+#: src/recur.c:484
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "�������� %s, ��� ��� ���� ���� ������ ���� ��������.\n"
 
-#: src/recur.c:684
+#: src/recur.c:679
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "�������� robots.txt; �� ��������� �������� �� ������.\n"
 
-#: src/retr.c:229
+#: src/retr.c:227
 #, c-format
-msgid ""
-"\n"
-"          [ skipping %dK ]"
-msgstr ""
-"\n"
-"          [ ������� %dK ]"
+msgid "\n          [ skipping %dK ]"
+msgstr "\n          [ ������� %dK ]"
 
-#: src/retr.c:421
+#: src/retr.c:373
 msgid "Could not find proxy host.\n"
 msgstr "�� ������ ������-������.\n"
 
-#: src/retr.c:435
+#: src/retr.c:387
 #, c-format
 msgid "Proxy %s: Must be HTTP.\n"
 msgstr "������-������ %s: ������ ���� HTTP.\n"
 
-#: src/retr.c:529
+#: src/retr.c:481
 #, c-format
 msgid "%s: Redirection cycle detected.\n"
 msgstr "%s: ��������� ���� ���������������.\n"
 
-#: src/retr.c:623
-msgid ""
-"Giving up.\n"
-"\n"
-msgstr ""
-"����������.\n"
-"\n"
+#: src/retr.c:587
+msgid "Giving up.\n\n"
+msgstr "����������.\n\n"
 
-#: src/retr.c:623
-msgid ""
-"Retrying.\n"
-"\n"
-msgstr ""
-"����������� �������.\n"
-"\n"
+#: src/retr.c:587
+msgid "Retrying.\n\n"
+msgstr "����������� �������.\n\n"
 
-#: src/url.c:1332
+#: src/url.c:1329
 #, c-format
 msgid "Converting %s... "
 msgstr "�������������� %s... "
 
-#: src/url.c:1345
+#: src/url.c:1342
 msgid "nothing to do.\n"
-msgstr ""
+msgstr "�������� �� ������.\n"
 
-#: src/url.c:1353 src/url.c:1377
+#: src/url.c:1350 src/url.c:1374
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "�� ������� ������������� ������ � %s: %s\n"
 
-#: src/url.c:1368
-#, fuzzy, c-format
+#: src/url.c:1365
+#, c-format
 msgid "Unable to delete `%s': %s\n"
-msgstr "������ �������� ���������� ������ `%s': %s\n"
+msgstr "������ �������� `%s': %s\n"
 
-#: src/url.c:1558
+#: src/url.c:1555
 #, c-format
 msgid "Cannot back up %s as %s: %s\n"
 msgstr "�� ������� ��������� %s ��� ������ %s: %s\n"
 
-#: src/utils.c:94
+#: src/utils.c:93
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: ������������ ������.\n"
 
-#: src/utils.c:386
+#: src/utils.c:416
 msgid "Unknown/unsupported protocol"
 msgstr "�������� ���������� ��� �� ��������������"
 
-#: src/utils.c:389
+#: src/utils.c:419
 msgid "Invalid port specification"
 msgstr "�������� ������������� �����"
 
-#: src/utils.c:392
+#: src/utils.c:422
 msgid "Invalid host name"
 msgstr "������������ ��� ������ (hostname)"
 
-#: src/utils.c:613
+#: src/utils.c:619
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "������ �������� ���������� ������ `%s': %s\n"
-
-#~ msgid "%s: Out of memory.\n"
-#~ msgstr "%s: ������������ ������.\n"
-
-#~ msgid "%s: Redirection to itself.\n"
-#~ msgstr "%s: ��������������� �� ������ ����.\n"
-
-#~ msgid "Error (%s): Link %s without a base provided.\n"
-#~ msgstr "������ (%s): ������ %s ��� �������� ������.\n"
-
-#~ msgid "Error (%s): Base %s relative, without referer URL.\n"
-#~ msgstr "������ (%s): ������� ����� %s �����������, URL �� ���������.\n"
