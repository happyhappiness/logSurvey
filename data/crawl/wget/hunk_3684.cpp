 "�ƻ�Ԥ��Ƥ��ޤ���\n"
 "\n"
 
-#: src/url.c:1332
+#: src/url.c:983
 #, c-format
-msgid "Converting %s... "
-msgstr "%s ���Ѵ����Ƥ��ޤ�... "
+msgid "Error (%s): Link %s without a base provided.\n"
+msgstr "���顼 (%s): %s �Ȥ�����󥯤��Ф���١�����Ϳ�����Ƥ��ޤ���\n"
 
-#: src/url.c:1345
-msgid "nothing to do.\n"
+#: src/url.c:999
+#, c-format
+msgid "Error (%s): Base %s relative, without referer URL.\n"
 msgstr ""
+"���顼(%s): Base URL %s �����л���ǡ����Ȥ���URL(Referer)��¸�ߤ��ޤ���\n"
+
+#: src/url.c:1540
+#, c-format
+msgid "Converting %s... "
+msgstr "%s ���Ѵ����Ƥ��ޤ�... "
 
-#: src/url.c:1353 src/url.c:1377
+#: src/url.c:1545 src/url.c:1632
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "%s ��Υ�󥯤��Ѵ��Ǥ��ޤ���: %s\n"
 
-#: src/url.c:1368
-#, fuzzy, c-format
-msgid "Unable to delete `%s': %s\n"
-msgstr "����ܥ�å���� `%s' �κ���˼��Ԥ��ޤ���: %s\n"
-
-#: src/url.c:1558
-#, fuzzy, c-format
+#: src/url.c:1608
+#, c-format
 msgid "Cannot back up %s as %s: %s\n"
-msgstr "%s ��Υ�󥯤��Ѵ��Ǥ��ޤ���: %s\n"
+msgstr "%s �ΥХå����å� %s �����ޤ���: %s\n"
 
-#: src/utils.c:94
+#: src/utils.c:72
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: ��ʬ�ʥ��꤬����ޤ���\n"
 
-#: src/utils.c:386
+#: src/utils.c:204
 msgid "Unknown/unsupported protocol"
 msgstr "�����ʡ��ޤ����б����Ƥ��ʤ��ץ�ȥ���Ǥ�"
 
-#: src/utils.c:389
+#: src/utils.c:207
 msgid "Invalid port specification"
 msgstr "̵���ʥݡ����ֹ�Ǥ�"
 
-#: src/utils.c:392
+#: src/utils.c:210
 msgid "Invalid host name"
 msgstr "̵���ʥۥ���̾�Ǥ�"
 
-#: src/utils.c:613
+#: src/utils.c:431
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "����ܥ�å���� `%s' �κ���˼��Ԥ��ޤ���: %s\n"
-
-#, fuzzy
-#~ msgid "%s: Out of memory.\n"
-#~ msgstr "%s: %s: ��ʬ�ʥ��꤬����ޤ���\n"
-
-#~ msgid ""
-#~ "Local file `%s' is more recent, not retrieving.\n"
-#~ "\n"
-#~ msgstr ""
-#~ "������ե����� `%s' �Τۤ����������Τǡ�ž�����ޤ���\n"
-#~ "\n"
-
-#~ msgid "Error (%s): Link %s without a base provided.\n"
-#~ msgstr "���顼 (%s): %s �Ȥ�����󥯤��Ф���١�����Ϳ�����Ƥ��ޤ���\n"
-
-#~ msgid "Error (%s): Base %s relative, without referer URL.\n"
-#~ msgstr ""
-#~ "���顼(%s): Base URL %s �����л���ǡ����Ȥ���URL(Referer)��¸�ߤ��ޤ���\n"
