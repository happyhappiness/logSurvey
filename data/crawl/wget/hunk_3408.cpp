 "���������� ����.\n"
 "\n"
 
-#
-#: src/url.c:1332
+#: src/url.c:1875
 #, c-format
 msgid "Converting %s... "
 msgstr "��������� ��� %s... "
 
-#: src/url.c:1345
+#: src/url.c:1888
 msgid "nothing to do.\n"
-msgstr ""
+msgstr "������ �� ����.\n"
 
-#
-#: src/url.c:1353 src/url.c:1377
+#: src/url.c:1896 src/url.c:1920
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
-msgstr "�������� ���������� ���������� ��� %s: %s\n"
+msgstr "�������� ���������� ��������� ��� %s: %s\n"
 
-#
-#: src/url.c:1368
-#, fuzzy, c-format
+#: src/url.c:1911
+#, c-format
 msgid "Unable to delete `%s': %s\n"
-msgstr "�������� ��������� ���������� ��������� `%s': %s\n"
+msgstr "�������� ��������� ��� `%s': %s\n"
 
-#
-#: src/url.c:1558
-#, fuzzy, c-format
+#: src/url.c:2117
+#, c-format
 msgid "Cannot back up %s as %s: %s\n"
-msgstr "�������� ���������� ���������� ��� %s: %s\n"
+msgstr "������� � ���� ���������� ��������� ��� %s �� %s: %s\n"
 
-#
-#: src/utils.c:94
+#: src/utils.c:90
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: ��� ������� ������ �����.\n"
 
-#
-#: src/utils.c:386
-msgid "Unknown/unsupported protocol"
-msgstr "�������/�� �������������� ����������"
-
-#
-#: src/utils.c:389
-msgid "Invalid port specification"
-msgstr "�� ������ ������� ����� (port)"
-
-#
-#: src/utils.c:392
-msgid "Invalid host name"
-msgstr "�� ������ ����� �����������"
+#. parent, no error
+#: src/utils.c:455
+#, c-format
+msgid "Continuing in background, pid %d.\n"
+msgstr ""
+"�������� ��� ����������, ��������� ���������� (pid) %d.\n"
+"\n"
 
-#
-#: src/utils.c:613
+#: src/utils.c:499
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "�������� ��������� ���������� ��������� `%s': %s\n"
 
-#
-#, fuzzy
+#~ msgid "Connection to %s:%hu refused.\n"
+#~ msgstr "������� �� %s:%hu ��� ���������.\n"
+
+#~ msgid "%s: Cannot determine user-id.\n"
+#~ msgstr "%s: ��� ����� ������ � ���������� ��� ���������� ������.\n"
+
+#~ msgid "%s: Warning: uname failed: %s\n"
+#~ msgstr "%s: �������������: � uname �������: %s\n"
+
+#~ msgid "%s: Warning: gethostname failed\n"
+#~ msgstr "%s: �������������: � gethostname �������\n"
+
+#~ msgid "%s: Warning: cannot determine local IP address.\n"
+#~ msgstr "%s: �������������: ��� ����� ������ � �������� ��� ������� ���������� IP.\n"
+
+#~ msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
+#~ msgstr "%s: �������������: ��� ����� ������ � �������� ��� ������� ���������� IP.\n"
+
+#~ msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
+#~ msgstr "%s: �������������: � ��������� ��������� ��� ������� ���������� ��� �������� �� FDQN!\n"
+
 #~ msgid "%s: Out of memory.\n"
-#~ msgstr "%s: %s: ��� ������� ������ �����.\n"
+#~ msgstr "%s: � ����� �����������.\n"
 
-#
 #~ msgid ""
-#~ "Local file `%s' is more recent, not retrieving.\n"
 #~ "\n"
+#~ "CTRL+Break received, redirecting output to `%s'.\n"
+#~ "Execution continued in background.\n"
+#~ "You may stop Wget by pressing CTRL+ALT+DELETE.\n"
 #~ msgstr ""
-#~ "�� ������ ������ `%s' ����� ��� ��������, ���������� � ��������.\n"
 #~ "\n"
+#~ "CTRL+Break ��������, ������������� ������ ��� `%s'.\n"
+#~ "� �������� ����������� ��� ����������.\n"
+#~ "�������� �� ��������� �� Wget �������� CTRL+ALT+DELETE.\n"
+
+#~ msgid "%s: Redirection to itself.\n"
+#~ msgstr "%s: ������������� ���� ����� ���.\n"
 
-#
 #~ msgid "Error (%s): Link %s without a base provided.\n"
 #~ msgstr "������ (%s): ������ ��������� %s ����� ����.\n"
 
-#
 #~ msgid "Error (%s): Base %s relative, without referer URL.\n"
 #~ msgstr "������ (%s): � ���� %s ����� �������, ����� URL ��������.\n"
 
-#
+#~ msgid "Unknown/unsupported protocol"
+#~ msgstr "�������/�� �������������� ����������"
+
+#~ msgid "Invalid port specification"
+#~ msgstr "�� ������ ������� ����� (port)"
+
+#~ msgid "Invalid host name"
+#~ msgstr "�� ������ ����� �����������"
+
+#~ msgid ""
+#~ "Local file `%s' is more recent, not retrieving.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "�� ������ ������ `%s' ����� ��� ��������, ����������� � ��������.\n"
+#~ "\n"
+
 #~ msgid "%s: unrecognized option, character code 0%o\n"
 #~ msgstr "%s: �� ������������ �������, ������� ��������� 0%o\n"
 
-#
 #~ msgid "%s: unrecognized option `-%c'\n"
 #~ msgstr "%s: �� ������������ ������� `-%c'\n"
 
-#
 #~ msgid "%s: option `-%c' requires an argument\n"
 #~ msgstr "%s: � ������� `-%c' ������� ��� ������\n"
