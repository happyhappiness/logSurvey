 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: ���Ѳ�ǽ�ʥ����åȥɥ饤�Ф򸫤Ĥ����ޤ���\n"
 
-#: src/netrc.c:334
+#: src/netrc.c:367
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
-msgstr "%s: %s:%d: �ٹ�: ���ڤ국��(token) \"%s\" �Ϥ��٤ƤΥޥ���̾�����˸����ޤ�\n"
+msgstr ""
+"%s: %s:%d: �ٹ�: ���ڤ국��(token) \"%s\" "
+"�Ϥ��٤ƤΥޥ���̾�����˸����ޤ�\n"
 
-#: src/netrc.c:365
+#: src/netrc.c:398
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: \"%s\" �������ʶ��ڤ국��(token)�Ǥ�\n"
 
-#: src/netrc.c:429
+#: src/netrc.c:462
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "�Ȥ���: %s NETRC [�ۥ���̾]\n"
 
-#: src/netrc.c:439
+#: src/netrc.c:472
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: %s�ξ��������Ǥ��ޤ���: %s \n"
 
-#: src/recur.c:449 src/retr.c:462
-#, c-format
-msgid "Removing %s.\n"
-msgstr "%s �������ޤ�����\n"
-
-#: src/recur.c:450
+#: src/recur.c:506
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "���ݤ��٤��ʤΤǡ�%s �������ޤ�����\n"
 
-#: src/recur.c:609
+#: src/recur.c:680
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "robots.txt���ɤ߹���Ǥ��ޤ������顼��̵�뤷�Ƥ���������\n"
 
-#: src/retr.c:193
+#: src/retr.c:217
 #, c-format
-msgid "\n          [ skipping %dK ]"
-msgstr "\n          [ %dK �ȤФ��ޤ� ]"
+msgid ""
+"\n"
+"          [ skipping %dK ]"
+msgstr ""
+"\n"
+"          [ %dK �ȤФ��ޤ� ]"
 
-#: src/retr.c:344
+#: src/retr.c:399
 msgid "Could not find proxy host.\n"
 msgstr "�����ۥ���(proxy host)�����Ĥ���ޤ���\n"
 
-#: src/retr.c:355
+#: src/retr.c:413
 #, c-format
 msgid "Proxy %s: Must be HTTP.\n"
 msgstr "����������(proxy) %s: HTTP�Ǥ���ɬ�פ�����ޤ���\n"
 
-#: src/retr.c:398
-#, c-format
-msgid "%s: Redirection to itself.\n"
+#: src/retr.c:507
+#, fuzzy, c-format
+msgid "%s: Redirection cycle detected.\n"
 msgstr "%s �ϼ�ʬ���ȤؤΥ�ǥ��쥯�����Ǥ���\n"
 
-#: src/retr.c:483
-msgid "Giving up.\n\n"
-msgstr "��ߤ��ޤ�����\n\n"
-
-#: src/retr.c:483
-msgid "Retrying.\n\n"
-msgstr "�ƻ�Ԥ��Ƥ��ޤ���\n\n"
-
-#: src/url.c:940
-#, c-format
-msgid "Error (%s): Link %s without a base provided.\n"
-msgstr "���顼 (%s): %s �Ȥ�����󥯤��Ф���١�����Ϳ�����Ƥ��ޤ���\n"
+#: src/retr.c:601
+msgid ""
+"Giving up.\n"
+"\n"
+msgstr ""
+"��ߤ��ޤ�����\n"
+"\n"
 
-#: src/url.c:955
-#, c-format
-msgid "Error (%s): Base %s relative, without referer URL.\n"
-msgstr "���顼(%s): Base URL %s �����л���ǡ����Ȥ���URL(Referer)��¸�ߤ��ޤ���\n"
+#: src/retr.c:601
+msgid ""
+"Retrying.\n"
+"\n"
+msgstr ""
+"�ƻ�Ԥ��Ƥ��ޤ���\n"
+"\n"
 
-#: src/url.c:1373
+#: src/url.c:1325
 #, c-format
 msgid "Converting %s... "
 msgstr "%s ���Ѵ����Ƥ��ޤ�... "
 
-#: src/url.c:1378 src/url.c:1389
+#: src/url.c:1338
+msgid "nothing to do.\n"
+msgstr ""
+
+#: src/url.c:1346 src/url.c:1370
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "%s ��Υ�󥯤��Ѵ��Ǥ��ޤ���: %s\n"
 
-#: src/utils.c:71
+#: src/url.c:1361
+#, fuzzy, c-format
+msgid "Unable to delete `%s': %s\n"
+msgstr "����ܥ�å���� `%s' �κ���˼��Ԥ��ޤ���: %s\n"
+
+#: src/url.c:1558
+#, fuzzy, c-format
+msgid "Cannot back up %s as %s: %s\n"
+msgstr "%s ��Υ�󥯤��Ѵ��Ǥ��ޤ���: %s\n"
+
+#: src/utils.c:94
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: ��ʬ�ʥ��꤬����ޤ���\n"
 
-#: src/utils.c:203
+#: src/utils.c:392
 msgid "Unknown/unsupported protocol"
 msgstr "�����ʡ��ޤ����б����Ƥ��ʤ��ץ�ȥ���Ǥ�"
 
-#: src/utils.c:206
+#: src/utils.c:395
 msgid "Invalid port specification"
 msgstr "̵���ʥݡ����ֹ�Ǥ�"
 
-#: src/utils.c:209
+#: src/utils.c:398
 msgid "Invalid host name"
 msgstr "̵���ʥۥ���̾�Ǥ�"
 
-#: src/utils.c:430
+#: src/utils.c:619
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "����ܥ�å���� `%s' �κ���˼��Ԥ��ޤ���: %s\n"
+
+#~ msgid ""
+#~ "Local file `%s' is more recent, not retrieving.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "������ե����� `%s' �Τۤ����������Τǡ�ž�����ޤ���\n"
+#~ "\n"
+
+#~ msgid "Error (%s): Link %s without a base provided.\n"
+#~ msgstr "���顼 (%s): %s �Ȥ�����󥯤��Ф���١�����Ϳ�����Ƥ��ޤ���\n"
+
+#~ msgid "Error (%s): Base %s relative, without referer URL.\n"
+#~ msgstr ""
+#~ "���顼(%s): Base URL %s �����л���ǡ����Ȥ���URL(Referer)��¸�ߤ��ޤ���\n"
