 "����������� �������.\n"
 "\n"
 
-#: src/url.c:983
-#, c-format
-msgid "Error (%s): Link %s without a base provided.\n"
-msgstr "������ (%s): ������ %s ��� �������� ������.\n"
-
-#: src/url.c:999
-#, c-format
-msgid "Error (%s): Base %s relative, without referer URL.\n"
-msgstr "������ (%s): ������� ����� %s �����������, URL �� ���������.\n"
-
-#: src/url.c:1540
+#: src/url.c:1325
 #, c-format
 msgid "Converting %s... "
 msgstr "�������������� %s... "
 
-#: src/url.c:1545 src/url.c:1632
+#: src/url.c:1338
+msgid "nothing to do.\n"
+msgstr ""
+
+#: src/url.c:1346 src/url.c:1370
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "�� ������� ������������� ������ � %s: %s\n"
 
-#: src/url.c:1608
+#: src/url.c:1361
+#, fuzzy, c-format
+msgid "Unable to delete `%s': %s\n"
+msgstr "������ �������� ���������� ������ `%s': %s\n"
+
+#: src/url.c:1558
 #, c-format
 msgid "Cannot back up %s as %s: %s\n"
 msgstr "�� ������� ��������� %s ��� ������ %s: %s\n"
 
-#: src/utils.c:72
+#: src/utils.c:94
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: ������������ ������.\n"
 
-#: src/utils.c:204
+#: src/utils.c:392
 msgid "Unknown/unsupported protocol"
 msgstr "�������� ���������� ��� �� ��������������"
 
-#: src/utils.c:207
+#: src/utils.c:395
 msgid "Invalid port specification"
 msgstr "�������� ������������� �����"
 
-#: src/utils.c:210
+#: src/utils.c:398
 msgid "Invalid host name"
 msgstr "������������ ��� ������ (hostname)"
 
-#: src/utils.c:431
+#: src/utils.c:619
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "������ �������� ���������� ������ `%s': %s\n"
+
+#~ msgid "%s: Redirection to itself.\n"
+#~ msgstr "%s: ��������������� �� ������ ����.\n"
+
+#~ msgid "Error (%s): Link %s without a base provided.\n"
+#~ msgstr "������ (%s): ������ %s ��� �������� ������.\n"
+
+#~ msgid "Error (%s): Base %s relative, without referer URL.\n"
+#~ msgstr "������ (%s): ������� ����� %s �����������, URL �� ���������.\n"
