 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1606
+#: src/ftp.c:1753
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr ".`%s' ������ ������ ���\n"
 
-#: src/ftp.c:1671
-#, c-format
-msgid "Wrote HTML-ized index to `%s' [%ld].\n"
+#: src/ftp.c:1819
+#, fuzzy, c-format
+msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "`%s'-� ����� ���� %ld ������ HTML ������ ����� �����\n"
 
-#: src/ftp.c:1676
+#: src/ftp.c:1824
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "`%s'-� ����� HTML ������ ����� �����\n"
 
-#: src/getopt.c:454
+#: src/getopt.c:670
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
 msgstr "%s ����� ���� �����-�� ���� `%s' ������\n"
 
-#: src/getopt.c:478
+#: src/getopt.c:695
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
 msgstr "%s ����� ���� ������� ���� ���� `--%s' ������\n"
 
-#: src/getopt.c:483
+#: src/getopt.c:700
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
 msgstr "%s ����� ���� ������� ���� ���� `%c%s' ������\n"
 
-#: src/getopt.c:498
+#: src/getopt.c:718 src/getopt.c:891
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
 msgstr "%s ����� ���� ������� ����� `%s' ������\n"
 
 #. --option
-#: src/getopt.c:528
+#: src/getopt.c:747
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
 msgstr "%s ����� �\"� ���� ���� `--%s' ������\n"
 
 #. +option or -option
-#: src/getopt.c:532
+#: src/getopt.c:751
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
 msgstr "%s ����� �\"� ���� ���� `%c%s' ������\n"
 
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:563
+#: src/getopt.c:777
 #, c-format
 msgid "%s: illegal option -- %c\n"
 msgstr "%s: ����-���� ������ -- %c\n"
 
+#: src/getopt.c:780
+#, fuzzy, c-format
+msgid "%s: invalid option -- %c\n"
+msgstr "%s: ����-���� ������ -- %c\n"
+
 #. 1003.2 specifies the format of this message.
-#: src/getopt.c:602
+#: src/getopt.c:810 src/getopt.c:940
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
 msgstr "%s: ������� ����� ������ -- %c\n"
 
-#: src/host.c:374
-msgid "Host not found"
-msgstr "���� �� ���� ����"
+#: src/getopt.c:857
+#, fuzzy, c-format
+msgid "%s: option `-W %s' is ambiguous\n"
+msgstr "%s ����� ���� �����-�� ���� `%s' ������\n"
+
+#: src/getopt.c:875
+#, fuzzy, c-format
+msgid "%s: option `-W %s' doesn't allow an argument\n"
+msgstr "%s ����� ���� ������� ���� ���� `--%s' ������\n"
+
+#: src/host.c:347
+#, fuzzy
+msgid "Unknown host"
+msgstr "�����-���� ����"
+
+#. Message modeled after what gai_strerror returns in similar
+#. circumstances.
+#: src/host.c:351
+msgid "Temporary failure in name resolution"
+msgstr ""
 
-#: src/host.c:376
+#: src/host.c:353
 msgid "Unknown error"
 msgstr "�����-���� ����"
 
-#. this is fatal
-#: src/http.c:555
-msgid "Failed to set up an SSL context\n"
-msgstr "(SSL) ������ ����� ����� ������ ����\n"
+#: src/host.c:714
+#, fuzzy, c-format
+msgid "Resolving %s... "
+msgstr ".%s ����\n"
+
+#: src/host.c:761
+msgid "failed: No IPv4/IPv6 addresses for host.\n"
+msgstr ""
+
+#: src/host.c:784
+msgid "failed: timed out.\n"
+msgstr ""
 
-#: src/http.c:561
+#: src/html-url.c:288
 #, c-format
-msgid "Failed to load certificates from %s\n"
-msgstr "%s-� (certificates) ����� ����� ������ ����\n"
+msgid "%s: Cannot resolve incomplete link %s.\n"
+msgstr ""
 
-#: src/http.c:565 src/http.c:573
-msgid "Trying without the specified certificate\n"
-msgstr "����� ����� ���� ��� ������ �����\n"
+#: src/html-url.c:695
+#, fuzzy, c-format
+msgid "%s: Invalid URL %s: %s\n"
+msgstr ".%s ������ `%s' ���� ���\n"
 
-#: src/http.c:569
+#: src/http.c:367
 #, c-format
-msgid "Failed to get certificate key from %s\n"
-msgstr "%s-� ����� ���� ����� ����\n"
+msgid "Failed writing HTTP request: %s.\n"
+msgstr ".HTTP ����� �� ������ (%s) ����\n"
 
-#: src/http.c:663 src/http.c:1593
-msgid "Unable to establish SSL connection.\n"
-msgstr ".(SSL) ������ ��� ���� ����� ���� ��\n"
+#: src/http.c:736
+msgid "No headers, assuming HTTP/0.9"
+msgstr ""
+
+#: src/http.c:1413
+msgid "Disabling SSL due to encountered errors.\n"
+msgstr ""
 
-#: src/http.c:671
+#: src/http.c:1566
 #, c-format
-msgid "Reusing connection to %s:%hu.\n"
+msgid "POST data file `%s' missing: %s\n"
+msgstr ""
+
+#: src/http.c:1615
+#, fuzzy, c-format
+msgid "Reusing existing connection to %s:%d.\n"
 msgstr ".%s:%hu-� ������ ������ �����\n"
 
-#: src/http.c:861
-#, c-format
-msgid "Failed writing HTTP request: %s.\n"
+#: src/http.c:1684
+#, fuzzy, c-format
+msgid "Failed reading proxy response: %s\n"
 msgstr ".HTTP ����� �� ������ (%s) ����\n"
 
+#: src/http.c:1704
+#, c-format
+msgid "Proxy tunneling failed: %s"
+msgstr ""
+
 # FIXME: This message can be followed by "%d %s", which prints
 # the operation status code and error message.  I don't see how
 # can I make this look right in Hebrew...
-#: src/http.c:866
+#: src/http.c:1749
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "...����� ����� ����� ,����� %s ����� "
 
-#: src/http.c:910
-msgid "End of file while parsing headers.\n"
-msgstr ".������� ����� ��� ��� ��� ���\n"
+#: src/http.c:1760
+#, fuzzy
+msgid "No data received.\n"
+msgstr "��� ����� ������ ��"
 
-#: src/http.c:920
+#: src/http.c:1767
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr ".������ ����� ��� (%s) ����\n"
 
-#: src/http.c:959
-msgid "No data received"
-msgstr "��� ����� ������ ��"
+#. If opt.noclobber is turned on and file already exists, do not
+#. retrieve the file
+#: src/http.c:1813
+#, fuzzy, c-format
+msgid ""
+"File `%s' already there; not retrieving.\n"
+"\n"
+msgstr ".���� ����� ���� ��� ,��� ��� `%s' ����\n"
+
+#. If the authentication header is missing or
+#. unrecognized, there's no sense in retrying.
+#: src/http.c:1966
+msgid "Unknown authentication scheme.\n"
+msgstr ".�����-���� ����� ����\n"
+
+#: src/http.c:1997
+msgid "Authorization failed.\n"
+msgstr ".������ ���� �����\n"
 
-#: src/http.c:961
+#: src/http.c:2011
 msgid "Malformed status line"
 msgstr "���� ���� �� ���� ����"
 
-#: src/http.c:966
+#: src/http.c:2013
 msgid "(no description)"
 msgstr "(�����-���� ����)"
 
-#: src/http.c:1089
-msgid "Authorization failed.\n"
-msgstr ".������ ���� �����\n"
-
-#: src/http.c:1096
-msgid "Unknown authentication scheme.\n"
-msgstr ".�����-���� ����� ����\n"
-
 # Pay attention: the translation of "unspecified" goes to the
 # left of this, the translation of "[following]" goes to the right.
-#: src/http.c:1136
+#: src/http.c:2076
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "%s :���� ����� �����%s\n"
 
-#: src/http.c:1137 src/http.c:1269
+#: src/http.c:2077 src/http.c:2184
 msgid "unspecified"
 msgstr "unspecified"
 
-#: src/http.c:1138
+#: src/http.c:2078
 msgid " [following]"
 msgstr " ��� ����"
 
-#: src/http.c:1200
-msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
-msgstr "\n  .����� ������ ��� ��� ;���� ��� ����� �� ����� �� �����\n\n"
-
-#: src/http.c:1216
-#, c-format
+#. If `-c' is in use and the file has been fully downloaded (or
+#. the remote file has shrunk), Wget effectively requests bytes
+#. after the end of file and the server response with 416.
+#: src/http.c:2134
 msgid ""
 "\n"
-"Continued download failed on this file, which conflicts with `-c'.\n"
-"Refusing to truncate existing file `%s'.\n"
+"    The file is already fully retrieved; nothing to do.\n"
 "\n"
 msgstr ""
 "\n"
-",����� `-c' ������� ���� .����� �� ���� �� ����-�����\n"
-".`%s' ���� ���� ����� �������� ���\n"
+"  .����� ������ ��� ��� ;���� ��� ����� �� ����� �� �����\n"
 "\n"
 
 # The next 3 messages are printed in order on the same line, and
