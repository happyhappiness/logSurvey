 "�������� --%s--\n"
 "�������: %s ���Ԧ� � %d ������(�)\n"
 
-#: src/main.c:842
+#: src/main.c:851
 #, c-format
 msgid "Download quota (%s bytes) EXCEEDED!\n"
 msgstr "��������� ��������� �� ������������ (%s ���Ԧ�)!\n"
 
-#. Please note that the double `%' in `%%s' is intentional, because
-#. redirect_output passes tmp through printf.
-#: src/main.c:876
-#, c-format
-msgid "%s received, redirecting output to `%%s'.\n"
-msgstr "�������� %s, ��������������� ��������� � `%%s'.\n"
-
-#: src/mswindows.c:89
-#, c-format
-msgid ""
-"\n"
-"CTRL+Break received, redirecting output to `%s'.\n"
-"Execution continued in background.\n"
-"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
-msgstr ""
-"\n"
-"�������� CTRL+Break, ��������� �����������Ѥ�� � `%s'.\n"
-"��������� ���� ���������� �� �̦.\n"
-"���������� CTRL+ALT+DELETE �� ������� �������� Wget.\n"
-
-#. parent, no error
-#: src/mswindows.c:106 src/utils.c:458
+#: src/mswindows.c:120
 msgid "Continuing in background.\n"
 msgstr "�������դ�� � �������� ����ͦ.\n"
 
-#: src/mswindows.c:108 src/utils.c:460
+#: src/mswindows.c:122 src/utils.c:457
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr "��������� ���� �������� �� `%s'.\n"
 
-#: src/mswindows.c:188
+#: src/mswindows.c:202
 #, c-format
 msgid "Starting WinHelp %s\n"
 msgstr "���������� WinHelp %s\n"
 
-#: src/mswindows.c:215 src/mswindows.c:222
+#: src/mswindows.c:229 src/mswindows.c:236
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: �� ���� ������ ���Ҧ���� �������.\n"
 
-#: src/netrc.c:367
+#: src/netrc.c:365
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
 msgstr "%s: %s:%d: ������������: ������� \"%s\" ����� ������ ������\n"
 
-#: src/netrc.c:398
+#: src/netrc.c:396
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: ��צ���� ������� \"%s\"\n"
 
-#: src/netrc.c:462
+#: src/netrc.c:460
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "������������: %s NETRC [��'� ������]\n"
 
-#: src/netrc.c:472
+#: src/netrc.c:470
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: �� ���� �������� stat %s: %s\n"
 
-#: src/recur.c:484
+#. Align the [ skipping ... ] line with the dots.  To do
+#. that, insert the number of spaces equal to the number of
+#. digits in the skipped amount in K.
+#: src/progress.c:224
+#, c-format
+msgid ""
+"\n"
+"%*s[ skipping %dK ]"
+msgstr ""
+"\n"
+"%*s[ ������� %dK ]"
+
+#: src/progress.c:391
+#, c-format
+msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
+msgstr "���������� �������� ����� `%s'; ������� ��� �ͦ��.\n"
+
+#: src/recur.c:350
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "�����Ѥ�� %s, ��˦���� ���� ����� ����������.\n"
 
-#: src/recur.c:679
+#: src/recur.c:935
+#, c-format
+msgid "Converted %d files in %.2f seconds.\n"
+msgstr "������������� %d ���̦� �� %.2f ������.\n"
+
+#: src/res.c:540
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "��������դ�� ���� robots.txt; �� �������� �� �������.\n"
 
-#: src/retr.c:227
-#, c-format
-msgid "\n          [ skipping %dK ]"
-msgstr "\n          [ ������� %dK ]"
-
-#: src/retr.c:373
+#: src/retr.c:363
 msgid "Could not find proxy host.\n"
 msgstr "�� �������� ����Ӧ-������.\n"
 
-#: src/retr.c:387
+#: src/retr.c:375
+#, c-format
+msgid "Error parsing proxy URL %s: %s.\n"
+msgstr "������� ������� ������ ����Ӧ %s: %s.\n"
+
+#: src/retr.c:384
 #, c-format
-msgid "Proxy %s: Must be HTTP.\n"
+msgid "Error in proxy URL %s: Must be HTTP.\n"
 msgstr "����Ӧ-������ %s ��� ���� HTTP.\n"
 
-#: src/retr.c:481
+#: src/retr.c:476
+#, c-format
+msgid "%d redirections exceeded.\n"
+msgstr "%d ��������� - ¦����, Φ� ���������.\n"
+
+#: src/retr.c:491
 #, c-format
 msgid "%s: Redirection cycle detected.\n"
 msgstr "%s: ���������� ���������������.\n"
 
-#: src/retr.c:587
-msgid "Giving up.\n\n"
-msgstr "���Ҧ��� ����������.\n\n"
+#: src/retr.c:608
+msgid ""
+"Giving up.\n"
+"\n"
+msgstr ""
+"���Ҧ��� ����������.\n"
+"\n"
 
-#: src/retr.c:587
-msgid "Retrying.\n\n"
-msgstr "����������� �����.\n\n"
+#: src/retr.c:608
+msgid ""
+"Retrying.\n"
+"\n"
+msgstr ""
+"����������� �����.\n"
+"\n"
 
-#: src/url.c:1329
+#: src/url.c:1875
 #, c-format
 msgid "Converting %s... "
 msgstr "������������ %s... "
 
-#: src/url.c:1342
+#: src/url.c:1888
 msgid "nothing to do.\n"
 msgstr "���� ���� ������.\n"
 
-#: src/url.c:1350 src/url.c:1374
+#: src/url.c:1896 src/url.c:1920
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "�� ���� ����������� ��������� � %s: %s\n"
 
-#: src/url.c:1365
+#: src/url.c:1911
 #, c-format
 msgid "Unable to delete `%s': %s\n"
 msgstr "�� ���� �������� `%s': %s\n"
 
-#: src/url.c:1555
+#: src/url.c:2117
 #, c-format
 msgid "Cannot back up %s as %s: %s\n"
 msgstr "�� ���� �������� ��Ц� %s Ц� ������ %s: %s\n"
 
-#: src/utils.c:94
+#: src/utils.c:90
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: ����������� ���'�Ԧ.\n"
 
-#: src/utils.c:417
-msgid "Unknown/unsupported protocol"
-msgstr "�������� ��צ����� �� �� Ц�����դ����"
-
-#: src/utils.c:420
-msgid "Invalid port specification"
-msgstr "������������ ����� �����"
-
-#: src/utils.c:423
-msgid "Invalid host name"
-msgstr "����������� ��'� ������"
+#. parent, no error
+#: src/utils.c:455
+#, c-format
+msgid "Continuing in background, pid %d.\n"
+msgstr "�������դ�� � �������� ����ͦ, ����� ������� %d.\n"
 
-#: src/utils.c:620
+#: src/utils.c:499
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "�� ������� �������� ��������� ��������� `%s': %s\n"
