 "���Ǥ� %s -> %s �Ȥ�������������ܥ�å���󥯤�����ޤ�\n"
 "\n"
 
-#: src/ftp.c:1493
+#: src/ftp.c:1494
 #, c-format
 msgid "Creating symlink %s -> %s\n"
 msgstr "%s -> %s �Ȥ�������ܥ�å���󥯤�������Ƥ��ޤ�\n"
 
-#: src/ftp.c:1503
+#: src/ftp.c:1504
 #, c-format
 msgid "Symlinks not supported, skipping symlink `%s'.\n"
 msgstr ""
 "����ܥ�å���󥯤��б����Ƥ��ʤ��Τǡ�����ܥ�å���� `%s' ��ȤФ���"
 "����\n"
 
-#: src/ftp.c:1515
+#: src/ftp.c:1516
 #, c-format
 msgid "Skipping directory `%s'.\n"
 msgstr "�ǥ��쥯�ȥ� `%s' ��ȤФ��ޤ���\n"
 
-#: src/ftp.c:1524
+#: src/ftp.c:1525
 #, c-format
 msgid "%s: unknown/unsupported file type.\n"
 msgstr "%s: �����ʤޤ����б����Ƥ��ʤ��ե�����μ���Ǥ���\n"
 
-#: src/ftp.c:1551
+#: src/ftp.c:1552
 #, c-format
 msgid "%s: corrupt time-stamp.\n"
 msgstr "%s: ���դ�����Ƥ��ޤ���\n"
 
-#: src/ftp.c:1579
+#: src/ftp.c:1580
 #, c-format
 msgid "Will not retrieve dirs since depth is %d (max %d).\n"
 msgstr "������ %d (���� %d)�ʤΤǥǥ��쥯�ȥ��ž�����ޤ���\n"
 
-#: src/ftp.c:1629
+#: src/ftp.c:1630
 #, c-format
 msgid "Not descending to `%s' as it is excluded/not-included.\n"
 msgstr "��������Ƥ��뤫�ޤޤ�Ƥ��ʤ��Τ� `%s' �˰�ư���ޤ���\n"
 
-#: src/ftp.c:1695 src/ftp.c:1709
+#: src/ftp.c:1696 src/ftp.c:1710
 #, c-format
 msgid "Rejecting `%s'.\n"
 msgstr "`%s' ��������ޤ���\n"
 
-#: src/ftp.c:1757
+#: src/ftp.c:1733
+#, fuzzy, c-format
+msgid "Error matching %s against %s: %s\n"
+msgstr "`%s' �ؽ񤭹���ޤ���: %s\n"
+
+#: src/ftp.c:1774
 #, c-format
 msgid "No matches on pattern `%s'.\n"
 msgstr "�ѥ����� `%s' ��Ŭ�礹���Τ�����ޤ���\n"
 
-#: src/ftp.c:1823
+#: src/ftp.c:1840
 #, c-format
 msgid "Wrote HTML-ized index to `%s' [%s].\n"
 msgstr "`%s' [%s]���Ф���HTML�����줿���Ф�(index)��񤭤ޤ�����\n"
 
-#: src/ftp.c:1828
+#: src/ftp.c:1845
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "`%s' ���Ф���HTML�����줿���Ф�(index)��񤭤ޤ�����\n"
 
-#: src/host.c:347
+#: src/host.c:348
 msgid "Unknown host"
 msgstr "�����ʥۥ��ȤǤ�"
 
-#: src/host.c:351
+#: src/host.c:352
 msgid "Temporary failure in name resolution"
 msgstr "̾�������˰��Ū�ʼ��Ԥ�ȯ�����ޤ���"
 
-#: src/host.c:353
+#: src/host.c:354
 msgid "Unknown error"
 msgstr "�����ʥ��顼�Ǥ�"
 
-#: src/host.c:714
+#: src/host.c:715
 #, c-format
 msgid "Resolving %s... "
 msgstr "%s ��DNS���䤤���碌�Ƥ��ޤ�... "
 
-#: src/host.c:761
+#: src/host.c:762
 msgid "failed: No IPv4/IPv6 addresses for host.\n"
 msgstr "����: �ۥ��Ȥ� IPv4/IPv6 ���ɥ쥹������ޤ���\n"
 
-#: src/host.c:784
+#: src/host.c:785
 msgid "failed: timed out.\n"
 msgstr "���Ԥ��ޤ���: �����ॢ����.\n"
 
-#: src/html-url.c:288
+#: src/html-url.c:289
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: �Դ����ʥ�� %s ����Ǥ��ޤ���\n"
 
-#: src/html-url.c:695
+#: src/html-url.c:696
 #, c-format
 msgid "%s: Invalid URL %s: %s\n"
 msgstr "%s: %s ��̵���� URL �Ǥ�(%s)��\n"
 
-#: src/http.c:367
+#: src/http.c:368
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "HTTP �ˤ����³�׵�������˼��Ԥ��ޤ���: %s\n"
 
-#: src/http.c:736
+#: src/http.c:737
 msgid "No headers, assuming HTTP/0.9"
 msgstr "�إå����ʤ��Τǡ�HTTP/0.9 ���Ȳ��ꤷ�ޤ�"
 
-#: src/http.c:1413
+#: src/http.c:1417
 msgid "Disabling SSL due to encountered errors.\n"
 msgstr "���顼��ȯ�������Τ� SSL ��̵���ˤ��ޤ�\n"
 
-#: src/http.c:1566
+#: src/http.c:1570
 #, c-format
 msgid "POST data file `%s' missing: %s\n"
 msgstr "POST �ǡ����ե����� `%s' ������ޤ���: %s\n"
 
-#: src/http.c:1615
+#: src/http.c:1619
 #, c-format
 msgid "Reusing existing connection to %s:%d.\n"
 msgstr "%s:%d �ؤ���³������Ѥ��ޤ���\n"
 
-#: src/http.c:1683
+#: src/http.c:1687
 #, c-format
 msgid "Failed reading proxy response: %s\n"
 msgstr "�ץ���������ɤ߹��ߤ˼��Ԥ��ޤ���: %s\n"
 
-#: src/http.c:1703
+#: src/http.c:1707
 #, c-format
 msgid "Proxy tunneling failed: %s"
 msgstr "�ץ����Υȥ�ͥ�󥰤˼��Ԥ��ޤ���: %s"
 
-#: src/http.c:1748
+#: src/http.c:1752
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s �ˤ����³�׵���������ޤ������������ԤäƤ��ޤ�... "
 
-#: src/http.c:1759
+#: src/http.c:1763
 msgid "No data received.\n"
 msgstr "�ǡ�������������ޤ���Ǥ���\n"
 
-#: src/http.c:1766
+#: src/http.c:1770
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "�إå�����ɤ߹��ߥ��顼(%s)�Ǥ�\n"
 
-#: src/http.c:1812
+#: src/http.c:1816 src/http.c:2368
 #, c-format
 msgid ""
 "File `%s' already there; not retrieving.\n"
