 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1775
+#: src/ftp.c:1606
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr ".`%s' ������ ������ ���\n"
 
-#: src/ftp.c:1841
-#, fuzzy, c-format
-msgid "Wrote HTML-ized index to `%s' [%s].\n"
+#: src/ftp.c:1671
+#, c-format
+msgid "Wrote HTML-ized index to `%s' [%ld].\n"
 msgstr "`%s'-� ����� ���� %ld ������ HTML ������ ����� �����\n"
 
-#: src/ftp.c:1846
+#: src/ftp.c:1676
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "`%s'-� ����� HTML ������ ����� �����\n"
 
-#: src/getopt.c:675
+#: src/getopt.c:454
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
 msgstr "%s ����� ���� �����-�� ���� `%s' ������\n"
 
-#: src/getopt.c:700
+#: src/getopt.c:478
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
 msgstr "%s ����� ���� ������� ���� ���� `--%s' ������\n"
 
-#: src/getopt.c:705
+#: src/getopt.c:483
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
 msgstr "%s ����� ���� ������� ���� ���� `%c%s' ������\n"
 
-#: src/getopt.c:723 src/getopt.c:896
+#: src/getopt.c:498
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
 msgstr "%s ����� ���� ������� ����� `%s' ������\n"
 
 #. --option
-#: src/getopt.c:752
+#: src/getopt.c:528
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
 msgstr "%s ����� �\"� ���� ���� `--%s' ������\n"
 
 #. +option or -option
-#: src/getopt.c:756
+#: src/getopt.c:532
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
 msgstr "%s ����� �\"� ���� ���� `%c%s' ������\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:782
+#: src/getopt.c:563
 #, c-format
 msgid "%s: illegal option -- %c\n"
 msgstr "%s: ����-���� ������ -- %c\n"
 
-#: src/getopt.c:785
-#, fuzzy, c-format
-msgid "%s: invalid option -- %c\n"
-msgstr "%s: ����-���� ������ -- %c\n"
-
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:815 src/getopt.c:945
+#: src/getopt.c:602
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: ������� ����� ������ -- %c\n"
 
-#: src/getopt.c:862
-#, fuzzy, c-format
-msgid "%s: option `-W %s' is ambiguous\n"
-msgstr "%s ����� ���� �����-�� ���� `%s' ������\n"
-
-#: src/getopt.c:880
-#, fuzzy, c-format
-msgid "%s: option `-W %s' doesn't allow an argument\n"
-msgstr "%s ����� ���� ������� ���� ���� `--%s' ������\n"
-
-#: src/host.c:371
-#, fuzzy
-msgid "Unknown host"
-msgstr "�����-���� ����"
-
-#. Message modeled after what gai_strerror returns in similar
-#. circumstances.
-#: src/host.c:375
-msgid "Temporary failure in name resolution"
-msgstr ""
+#: src/host.c:374
+msgid "Host not found"
+msgstr "���� �� ���� ����"
 
-#: src/host.c:377
+#: src/host.c:376
 msgid "Unknown error"
 msgstr "�����-���� ����"
 
-#: src/host.c:756
-#, fuzzy, c-format
-msgid "Resolving %s... "
-msgstr ".%s ����\n"
+#. this is fatal
+#: src/http.c:555
+msgid "Failed to set up an SSL context\n"
+msgstr "(SSL) ������ ����� ����� ������ ����\n"
 
-#: src/host.c:800 src/host.c:829
+#: src/http.c:561
 #, c-format
-msgid "failed: %s.\n"
-msgstr ""
-
-#: src/host.c:809
-msgid "failed: No IPv4/IPv6 addresses for host.\n"
-msgstr ""
-
-#: src/host.c:832
-msgid "failed: timed out.\n"
-msgstr ""
+msgid "Failed to load certificates from %s\n"
+msgstr "%s-� (certificates) ����� ����� ������ ����\n"
 
-#: src/html-url.c:298
-#, c-format
-msgid "%s: Cannot resolve incomplete link %s.\n"
-msgstr ""
+#: src/http.c:565 src/http.c:573
+msgid "Trying without the specified certificate\n"
+msgstr "����� ����� ���� ��� ������ �����\n"
 
-#: src/http.c:373 src/http.c:1549
+#: src/http.c:569
 #, c-format
-msgid "Failed writing HTTP request: %s.\n"
-msgstr ".HTTP ����� �� ������ (%s) ����\n"
-
-#: src/http.c:687
-msgid "No headers, assuming HTTP/0.9"
-msgstr ""
+msgid "Failed to get certificate key from %s\n"
+msgstr "%s-� ����� ���� ����� ����\n"
 
-#: src/http.c:1198
-msgid "Disabling SSL due to encountered errors.\n"
-msgstr ""
+#: src/http.c:663 src/http.c:1593
+msgid "Unable to establish SSL connection.\n"
+msgstr ".(SSL) ������ ��� ���� ����� ���� ��\n"
 
-#: src/http.c:1417
-#, fuzzy, c-format
-msgid "Reusing existing connection to %s:%d.\n"
+#: src/http.c:671
+#, c-format
+msgid "Reusing connection to %s:%hu.\n"
 msgstr ".%s:%hu-� ������ ������ �����\n"
 
-#: src/http.c:1479
-#, fuzzy, c-format
-msgid "Failed writing to proxy: %s.\n"
-msgstr ".HTTP ����� �� ������ (%s) ����\n"
-
-#: src/http.c:1488
-#, fuzzy, c-format
-msgid "Failed reading proxy response: %s\n"
-msgstr ".HTTP ����� �� ������ (%s) ����\n"
-
-#: src/http.c:1508
+#: src/http.c:861
 #, c-format
-msgid "Proxy tunneling failed: %s"
-msgstr ""
+msgid "Failed writing HTTP request: %s.\n"
+msgstr ".HTTP ����� �� ������ (%s) ����\n"
 
 # FIXME: This message can be followed by "%d %s", which prints
 # the operation status code and error message.  I don't see how
 # can I make this look right in Hebrew...
-#: src/http.c:1555
+#: src/http.c:866
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "...����� ����� ����� ,����� %s ����� "
 
-#: src/http.c:1566
-#, fuzzy
-msgid "No data received.\n"
-msgstr "��� ����� ������ ��"
+#: src/http.c:910
+msgid "End of file while parsing headers.\n"
+msgstr ".������� ����� ��� ��� ��� ���\n"
 
-#: src/http.c:1573
+#: src/http.c:920
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr ".������ ����� ��� (%s) ����\n"
 
-#. If the authentication header is missing or
-#. unrecognized, there's no sense in retrying.
-#: src/http.c:1658
-msgid "Unknown authentication scheme.\n"
-msgstr ".�����-���� ����� ����\n"
-
-#: src/http.c:1682
-msgid "Authorization failed.\n"
-msgstr ".������ ���� �����\n"
+#: src/http.c:959
+msgid "No data received"
+msgstr "��� ����� ������ ��"
 
-#: src/http.c:1696
+#: src/http.c:961
 msgid "Malformed status line"
 msgstr "���� ���� �� ���� ����"
 
-#: src/http.c:1698
+#: src/http.c:966
 msgid "(no description)"
 msgstr "(�����-���� ����)"
 
+#: src/http.c:1089
+msgid "Authorization failed.\n"
+msgstr ".������ ���� �����\n"
+
+#: src/http.c:1096
+msgid "Unknown authentication scheme.\n"
+msgstr ".�����-���� ����� ����\n"
+
 # Pay attention: the translation of "unspecified" goes to the
 # left of this, the translation of "[following]" goes to the right.
-#: src/http.c:1769
+#: src/http.c:1136
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "%s :���� ����� �����%s\n"
 
-#: src/http.c:1770 src/http.c:1867
+#: src/http.c:1137 src/http.c:1269
 msgid "unspecified"
 msgstr "unspecified"
 
-#: src/http.c:1771
+#: src/http.c:1138
 msgid " [following]"
 msgstr " ��� ����"
 
-#. If `-c' is in use and the file has been fully downloaded (or
-#. the remote file has shrunk), Wget effectively requests bytes
-#. after the end of file and the server response with 416.
-#: src/http.c:1817
+#: src/http.c:1200
+msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
+msgstr "\n  .����� ������ ��� ��� ;���� ��� ����� �� ����� �� �����\n\n"
+
+#: src/http.c:1216
+#, c-format
 msgid ""
 "\n"
-"    The file is already fully retrieved; nothing to do.\n"
+"Continued download failed on this file, which conflicts with `-c'.\n"
+"Refusing to truncate existing file `%s'.\n"
 "\n"
 msgstr ""
 "\n"
-"  .����� ������ ��� ��� ;���� ��� ����� �� ����� �� �����\n"
+",����� `-c' ������� ���� .����� �� ���� �� ����-�����\n"
+".`%s' ���� ���� ����� �������� ���\n"
 "\n"
 
 # The next 3 messages are printed in order on the same line, and
