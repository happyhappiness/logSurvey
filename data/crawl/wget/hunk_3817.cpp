 "�������� �� ��������� �� Wget �������� CTRL+ALT+DELETE.\n"
 
 #
-# File: src/mswindows.c, line: 135
-# File: src/utils.c, line: 268
 #. parent, no error
+#: src/mswindows.c:135 src/utils.c:457
 msgid "Continuing in background.\n"
 msgstr "�������� ��� ����������.\n"
 
 #
-# File: src/mswindows.c, line: 137
-# File: src/utils.c, line: 270
+#: src/mswindows.c:137 src/utils.c:459
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr "� ������ �� ������� ��� `%s'.\n"
 
 #
-# File: src/mswindows.c, line: 227
+#: src/mswindows.c:227
 #, c-format
 msgid "Starting WinHelp %s\n"
 msgstr "�������� ��� WinHelp %s\n"
 
 #
-# File: src/mswindows.c, line: 254
-# File: src/mswindows.c, line: 262
+#: src/mswindows.c:254 src/mswindows.c:262
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: �������� ������� ������� ������ �������.\n"
 
 #
-# File: src/netrc.c, line: 334
+#: src/netrc.c:367
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
-msgstr "%s: %s:%d: �������������: �� ����� \"%s\" ����������� ���� ��� �� ������� ��� �����������\n"
+msgstr ""
+"%s: %s:%d: �������������: �� ����� \"%s\" ����������� ���� ��� �� ������� "
+"��� �����������\n"
 
 #
-# File: src/netrc.c, line: 365
+#: src/netrc.c:398
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: �������� ���������� \"%s\"\n"
 
 #
-# File: src/netrc.c, line: 429
+#: src/netrc.c:462
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "�����: %s NETRC [����� �����������]\n"
 
 #
-# File: src/netrc.c, line: 439
+#: src/netrc.c:472
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: �������� ��������� ��� %s: %s\n"
 
 #
-# File: src/recur.c, line: 449
-# File: src/retr.c, line: 462
-#, c-format
-msgid "Removing %s.\n"
-msgstr "�������� ��� %s.\n"
-
-#
-# File: src/recur.c, line: 450
+#: src/recur.c:506
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "�������� ��� %s ���� �� ������ �� ����������.\n"
 
 #
-# File: src/recur.c, line: 609
+#: src/recur.c:680
 msgid "Loading robots.txt; please ignore errors.\n"
-msgstr "�������� ��� robots.txt; �������� ��������� ����� �������� ���������.\n"
+msgstr ""
+"�������� ��� robots.txt; �������� ��������� ����� �������� ���������.\n"
 
 #
-# File: src/retr.c, line: 193
+#: src/retr.c:217
 #, c-format
-msgid "\n          [ skipping %dK ]"
-msgstr "\n          [ ��������� %dK ]"
+msgid ""
+"\n"
+"          [ skipping %dK ]"
+msgstr ""
+"\n"
+"          [ ��������� %dK ]"
 
 #
-# File: src/retr.c, line: 344
+#: src/retr.c:399
 msgid "Could not find proxy host.\n"
 msgstr "�������� ������� ����������� proxy.\n"
 
 #
-# File: src/retr.c, line: 355
+#: src/retr.c:413
 #, c-format
 msgid "Proxy %s: Must be HTTP.\n"
 msgstr "Proxy %s: ������ �� ����� HTTP.\n"
 
 #
-# File: src/retr.c, line: 398
-#, c-format
-msgid "%s: Redirection to itself.\n"
+#: src/retr.c:507
+#, fuzzy, c-format
+msgid "%s: Redirection cycle detected.\n"
 msgstr "%s: ������������� ���� ����� ���.\n"
 
 #
-# File: src/retr.c, line: 483
-msgid "Giving up.\n\n"
-msgstr "�����������.\n\n"
+#: src/retr.c:601
+msgid ""
+"Giving up.\n"
+"\n"
+msgstr ""
+"�����������.\n"
+"\n"
 
 #
-# File: src/retr.c, line: 483
-msgid "Retrying.\n\n"
-msgstr "���������� ����.\n\n"
+#: src/retr.c:601
+msgid ""
+"Retrying.\n"
+"\n"
+msgstr ""
+"���������� ����.\n"
+"\n"
 
 #
-# File: src/url.c, line: 940
+#: src/url.c:1325
 #, c-format
-msgid "Error (%s): Link %s without a base provided.\n"
-msgstr "������ (%s): ������ ��������� %s ����� ����.\n"
+msgid "Converting %s... "
+msgstr "��������� ��� %s... "
+
+#: src/url.c:1338
+msgid "nothing to do.\n"
+msgstr ""
 
 #
-# File: src/url.c, line: 955
+#: src/url.c:1346 src/url.c:1370
 #, c-format
-msgid "Error (%s): Base %s relative, without referer URL.\n"
-msgstr "������ (%s): � ���� %s ����� �������, ����� URL ��������.\n"
+msgid "Cannot convert links in %s: %s\n"
+msgstr "�������� ���������� ���������� ��� %s: %s\n"
 
 #
-# File: src/url.c, line: 1373
-#, c-format
-msgid "Converting %s... "
-msgstr "��������� ��� %s... "
+#: src/url.c:1361
+#, fuzzy, c-format
+msgid "Unable to delete `%s': %s\n"
+msgstr "�������� ��������� ���������� ��������� `%s': %s\n"
 
 #
-# File: src/url.c, line: 1378
-# File: src/url.c, line: 1389
-#, c-format
-msgid "Cannot convert links in %s: %s\n"
+#: src/url.c:1558
+#, fuzzy, c-format
+msgid "Cannot back up %s as %s: %s\n"
 msgstr "�������� ���������� ���������� ��� %s: %s\n"
 
 #
-# File: src/utils.c, line: 71
+#: src/utils.c:94
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: ��� ������� ������ �����.\n"
 
 #
-# File: src/utils.c, line: 203
+#: src/utils.c:392
 msgid "Unknown/unsupported protocol"
 msgstr "�������/�� �������������� ����������"
 
 #
-# File: src/utils.c, line: 206
+#: src/utils.c:395
 msgid "Invalid port specification"
 msgstr "�� ������ ������� ����� (port)"
 
 #
-# File: src/utils.c, line: 209
+#: src/utils.c:398
 msgid "Invalid host name"
 msgstr "�� ������ ����� �����������"
 
 #
-# File: src/utils.c, line: 430
+#: src/utils.c:619
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "�������� ��������� ���������� ��������� `%s': %s\n"
 
-#~ #
+#
+#~ msgid ""
+#~ "Local file `%s' is more recent, not retrieving.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "�� ������ ������ `%s' ����� ��� ��������, ���������� � ��������.\n"
+#~ "\n"
+
+#
+#~ msgid "Error (%s): Link %s without a base provided.\n"
+#~ msgstr "������ (%s): ������ ��������� %s ����� ����.\n"
+
+#
+#~ msgid "Error (%s): Base %s relative, without referer URL.\n"
+#~ msgstr "������ (%s): � ���� %s ����� �������, ����� URL ��������.\n"
+
+#
 #~ msgid "%s: unrecognized option, character code 0%o\n"
 #~ msgstr "%s: �� ������������ �������, ������� ��������� 0%o\n"
 
-#~ #
+#
 #~ msgid "%s: unrecognized option `-%c'\n"
 #~ msgstr "%s: �� ������������ ������� `-%c'\n"
 
-#~ #
+#
 #~ msgid "%s: option `-%c' requires an argument\n"
 #~ msgstr "%s: � ������� `-%c' ������� ��� ������\n"
