 msgstr ""
 "\n"
 "��������� --%s--\n"
-"�������: %s ���� � %d ����ax\n"
+"���������: %s ���� � %d ������\n"
 
-#: src/main.c:854
+#: src/main.c:920
 #, c-format
 msgid "Download quota (%s bytes) EXCEEDED!\n"
-msgstr "��������� ����������� ������ (%s ����)!\n"
-
-#. Please note that the double `%' in `%%s' is intentional, because
-#. redirect_output passes tmp through printf.
-#: src/main.c:896
-#, c-format
-msgid "%s received, redirecting output to `%%s'.\n"
-msgstr "������� ������ %s, ����� ������������� � `%%s'.\n"
+msgstr "��������� ����������� �� �������� (%s ����)!\n"
 
-#: src/mswindows.c:106
-#, c-format
-msgid ""
-"\n"
-"CTRL+Break received, redirecting output to `%s'.\n"
-"Execution continued in background.\n"
-"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
-msgstr ""
-"\n"
-"������ CTRL+Break, ����� ���������������� � `%s'.\n"
-"���������� ��������� ����� ���������� � ������� ������.\n"
-"�� ������ ���������� ������ Wget �������� CTRL+ALT+DELETE.\n"
-
-#. parent, no error
-#: src/mswindows.c:123 src/utils.c:467
+#: src/mswindows.c:147
 msgid "Continuing in background.\n"
-msgstr "����������� ������ � ������� ������.\n"
+msgstr "������ ������������ � ������� ������.\n"
 
-#: src/mswindows.c:125 src/utils.c:469
+#: src/mswindows.c:149 src/utils.c:487
 #, c-format
 msgid "Output will be written to `%s'.\n"
-msgstr "�������� ���������� ����� �������� � ���� `%s'.\n"
+msgstr "�������� ������ ����� �������� � `%s'.\n"
 
-#: src/mswindows.c:205
+#: src/mswindows.c:245
 #, c-format
 msgid "Starting WinHelp %s\n"
-msgstr "������ WinHelp %s\n"
+msgstr "����������� WinHelp %s\n"
 
-#: src/mswindows.c:232 src/mswindows.c:239
+#: src/mswindows.c:272 src/mswindows.c:279
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
-msgstr "%s: �� ������ ���������� ������� TCP/IP.\n"
+msgstr "%s: ���������� ����� ���������� ������� ������.\n"
 
-#: src/netrc.c:365
+#: src/netrc.c:380
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
-msgstr "%s: %s:%d: ��������������: ������� \"%s\" ��������� ����� ����� ������\n"
+msgstr "%s: %s:%d: ��������������: ����� ������ ������ ������ ����������� ������ \"%s\"\n"
 
-#: src/netrc.c:396
+#: src/netrc.c:411
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
-msgstr "%s: %s:%d: ����������� ������� \"%s\"\n"
+msgstr "%s: %s:%d: ����������� ������ \"%s\"\n"
 
-#: src/netrc.c:460
+#: src/netrc.c:475
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
-msgstr "�������������: %s NETRC [HOSTNAME]\n"
+msgstr "�������������: %s NETRC [���_�����]\n"
 
-#: src/netrc.c:470
+#: src/netrc.c:485
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
-msgstr "%s: �� ������� ��������� stat ��� %s: %s\n"
+msgstr "%s: ���������� ��������� stat ��� %s: %s\n"
 
 #. Align the [ skipping ... ] line with the dots.  To do
 #. that, insert the number of spaces equal to the number of
 #. digits in the skipped amount in K.
-#: src/progress.c:224
+#: src/progress.c:234
 #, c-format
-msgid "\n%*s[ skipping %dK ]"
-msgstr "\n%*s[ ������� %dK ]"
+msgid ""
+"\n"
+"%*s[ skipping %dK ]"
+msgstr ""
+"\n"
+"%*s[ ������������ %dK ]"
 
-#: src/progress.c:391
+#: src/progress.c:401
 #, c-format
 msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
-msgstr "������������ �������� `%s'; ����� �������� ��� ���������.\n"
+msgstr "������������ ������������ dot-����� `%s'; �������� ��� ���������.\n"
 
-#: src/recur.c:350
+#: src/recur.c:378
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
-msgstr "�������� %s, ��� ��� ���� ���� ������ ���� ��������.\n"
+msgstr "��������� %s, �.�. �� ������ ���� ��������.\n"
 
-#: src/recur.c:916
-#, c-format
-msgid "Converted %d files in %.2f seconds.\n"
-msgstr "������������� %d ������ �� %.2f ������.\n"
-
-#: src/res.c:541
+#: src/res.c:549
 msgid "Loading robots.txt; please ignore errors.\n"
-msgstr "�������� robots.txt; �� ��������� �������� �� ������.\n"
-
-#: src/retr.c:363
-msgid "Could not find proxy host.\n"
-msgstr "�� ������ ������-������.\n"
+msgstr "����������� robots.txt; �� ��������� �������� �� ������.\n"
 
-#: src/retr.c:375
+#: src/retr.c:400
 #, c-format
 msgid "Error parsing proxy URL %s: %s.\n"
-msgstr "������ ������� URL ������-������� %s: %s\n"
+msgstr "������ ������� URL ������ %s: %s\n"
 
-#: src/retr.c:384
+#: src/retr.c:408
 #, c-format
 msgid "Error in proxy URL %s: Must be HTTP.\n"
-msgstr "������ � URL ������-������� %s: ����������� ������ HTTP.\n"
+msgstr "������ � URL ������ %s: ������ ���� HTTP.\n"
 
-#: src/retr.c:476
+#: src/retr.c:493
 #, c-format
 msgid "%d redirections exceeded.\n"
-msgstr "����� %d ���������������.\n"
+msgstr "��������� ����� ��������������� %d.\n"
 
-#: src/retr.c:491
-#, c-format
-msgid "%s: Redirection cycle detected.\n"
-msgstr "%s: ��������� ���� ���������������.\n"
+#: src/retr.c:617
+msgid ""
+"Giving up.\n"
+"\n"
+msgstr ""
+"����������.\n"
+"\n"
+
+#: src/retr.c:617
+msgid ""
+"Retrying.\n"
+"\n"
+msgstr ""
+"������.\n"
+"\n"
 
-#: src/retr.c:608
-msgid "Giving up.\n\n"
-msgstr "����������.\n\n"
+#: src/url.c:621
+msgid "No error"
+msgstr "��� ������"
 
-#: src/retr.c:608
-msgid "Retrying.\n\n"
-msgstr "����������� �������.\n\n"
+#: src/url.c:623
+msgid "Unsupported scheme"
+msgstr "���������������� �����"
 
-#: src/url.c:1748
-#, c-format
-msgid "Converting %s... "
-msgstr "�������������� %s... "
+#: src/url.c:625
+msgid "Empty host"
+msgstr "������ ����"
 
-#: src/url.c:1761
-msgid "nothing to do.\n"
-msgstr "�������� �� ������.\n"
+#: src/url.c:627
+msgid "Bad port number"
+msgstr "�������� ����� �����"
 
-#: src/url.c:1769 src/url.c:1793
-#, c-format
-msgid "Cannot convert links in %s: %s\n"
-msgstr "�� ������� ������������� ������ � %s: %s\n"
+#: src/url.c:629
+msgid "Invalid user name"
+msgstr "�������� ��� ������������"
 
-#: src/url.c:1784
-#, c-format
-msgid "Unable to delete `%s': %s\n"
-msgstr "������ �������� `%s': %s\n"
+#: src/url.c:631
+msgid "Unterminated IPv6 numeric address"
+msgstr "������������� �������� ������ IPv6"
 
-#: src/url.c:1990
-#, c-format
-msgid "Cannot back up %s as %s: %s\n"
-msgstr "�� ������� ��������� %s ��� ������ %s: %s\n"
+#: src/url.c:633
+msgid "IPv6 addresses not supported"
+msgstr "������ IPv6 �� ��������������"
+
+#: src/url.c:635
+msgid "Invalid IPv6 numeric address"
+msgstr "�������� �������� ����� IPv6"
 
-#: src/utils.c:102
+#: src/utils.c:120
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: ������������ ������.\n"
 
-#: src/utils.c:667
+#. parent, no error
+#: src/utils.c:485
 #, c-format
-msgid "Failed to unlink symlink `%s': %s\n"
-msgstr "������ �������� ���������� ������ `%s': %s\n"
-
-#~ msgid "Connection to %s:%hu refused.\n"
-#~ msgstr "������ %s:%hu �������� ����������.\n"
+msgid "Continuing in background, pid %d.\n"
+msgstr "������ ������������ � ������� ������, pid %d.\n"
 
-#~ msgid "Will try connecting to %s:%hu.\n"
-#~ msgstr "������� ���������� � %s:%hu ����� ����������.\n"
-
-#~ msgid "Unknown/unsupported protocol"
-#~ msgstr "�������� ���������� ��� �� ��������������."
-
-#~ msgid "Invalid port specification"
-#~ msgstr "������������ ����������� �����"
-
-#~ msgid "Invalid host name"
-#~ msgstr "������������ ��� ������"
+#: src/utils.c:529
+#, c-format
+msgid "Failed to unlink symlink `%s': %s\n"
+msgstr "�� ������� ��������� ������������� ������ `%s': %s\n"
