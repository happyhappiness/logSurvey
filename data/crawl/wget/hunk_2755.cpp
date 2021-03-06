 msgid "%s: option `-W %s' doesn't allow an argument\n"
 msgstr "%s: izbira `-W %s' ne dopu��a dodatnih argumentov\n"
 
-#: src/host.c:371
-#, fuzzy
-msgid "Unknown host"
-msgstr "Neznana napaka"
-
-#. Message modeled after what gai_strerror returns in similar
-#. circumstances.
-#: src/host.c:375
-msgid "Temporary failure in name resolution"
-msgstr ""
-
-#: src/host.c:377
-msgid "Unknown error"
-msgstr "Neznana napaka"
-
-#: src/host.c:756
+#: src/host.c:636
 #, c-format
 msgid "Resolving %s... "
 msgstr "Razre�uje se %s..."
 
-#: src/host.c:800 src/host.c:829
+#: src/host.c:656 src/host.c:672
 #, c-format
 msgid "failed: %s.\n"
 msgstr "spodletelo: %s.\n"
 
-#: src/host.c:809
-msgid "failed: No IPv4/IPv6 addresses for host.\n"
-msgstr ""
-
-#: src/host.c:832
+#: src/host.c:674
 msgid "failed: timed out.\n"
 msgstr "spodletelo: zakasnitev.\n"
 
-#: src/html-url.c:298
+#: src/host.c:762
+msgid "Host not found"
+msgstr "Gostitelj ni bil najden"
+
+#: src/host.c:764
+msgid "Unknown error"
+msgstr "Neznana napaka"
+
+#: src/html-url.c:293
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: Ni mo� razre�iti nepopolne povezave %s.\n"
 
-#: src/http.c:373 src/http.c:1549
-#, c-format
-msgid "Failed writing HTTP request: %s.\n"
-msgstr "Napaka pri pisanju zahteve HTTP: %s.\n"
+#. this is fatal
+#: src/http.c:674
+msgid "Failed to set up an SSL context\n"
+msgstr "Vzpostavljanje konteksta SSL ni uspelo.\n"
 
-#: src/http.c:687
-msgid "No headers, assuming HTTP/0.9"
-msgstr ""
+#: src/http.c:680
+#, c-format
+msgid "Failed to load certificates from %s\n"
+msgstr "Ni bilo mo� nalo�iti certifikatov od %s\n"
 
-#: src/http.c:1198
-msgid "Disabling SSL due to encountered errors.\n"
-msgstr ""
+#: src/http.c:684 src/http.c:692
+msgid "Trying without the specified certificate\n"
+msgstr "Posku�am brez dolo�enega certifikata\n"
 
-#: src/http.c:1417
-#, fuzzy, c-format
-msgid "Reusing existing connection to %s:%d.\n"
-msgstr "Znova uporabljam povezavo z %s:%hu.\n"
+#: src/http.c:688
+#, c-format
+msgid "Failed to get certificate key from %s\n"
+msgstr "Ni bilo mo� dobiti certifikatskega klju�a od %s\n"
 
-#: src/http.c:1479
-#, fuzzy, c-format
-msgid "Failed writing to proxy: %s.\n"
-msgstr "Napaka pri pisanju zahteve HTTP: %s.\n"
+#: src/http.c:761 src/http.c:1809
+msgid "Unable to establish SSL connection.\n"
+msgstr "Povezave SSL ni bilo mo� vzpostaviti.\n"
 
-#: src/http.c:1488
-#, fuzzy, c-format
-msgid "Failed reading proxy response: %s\n"
-msgstr "Napaka pri pisanju zahteve HTTP: %s.\n"
+#: src/http.c:770
+#, c-format
+msgid "Reusing connection to %s:%hu.\n"
+msgstr "Znova uporabljam povezavo z %s:%hu.\n"
 
-#: src/http.c:1508
+#: src/http.c:1034
 #, c-format
-msgid "Proxy tunneling failed: %s"
-msgstr ""
+msgid "Failed writing HTTP request: %s.\n"
+msgstr "Napaka pri pisanju zahteve HTTP: %s.\n"
 
-#: src/http.c:1555
+#: src/http.c:1039
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s zahteva poslana, �akam odgovor... "
 
-#: src/http.c:1566
-#, fuzzy
-msgid "No data received.\n"
-msgstr "Brez sprejetih podatkov"
+#: src/http.c:1083
+msgid "End of file while parsing headers.\n"
+msgstr "Pri raz�lenjevanju glave naletel na konec datoteke.\n"
 
-#: src/http.c:1573
+#: src/http.c:1093
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Napaka pri branju glave (%s).\n"
 
-#. If the authentication header is missing or
-#. unrecognized, there's no sense in retrying.
-#: src/http.c:1658
-msgid "Unknown authentication scheme.\n"
-msgstr "Neznata metoda avtentifikacije.\n"
-
-#: src/http.c:1682
-msgid "Authorization failed.\n"
-msgstr "Avtorizacija neuspe�na.\n"
+#: src/http.c:1128
+msgid "No data received"
+msgstr "Brez sprejetih podatkov"
 
-#: src/http.c:1696
+#: src/http.c:1130
 msgid "Malformed status line"
 msgstr "Zmali�ena statusna linija"
 
-#: src/http.c:1698
+#: src/http.c:1135
 msgid "(no description)"
 msgstr "(brez opisa)"
 
-#: src/http.c:1769
+#: src/http.c:1267
+msgid "Authorization failed.\n"
+msgstr "Avtorizacija neuspe�na.\n"
+
+#: src/http.c:1274
+msgid "Unknown authentication scheme.\n"
+msgstr "Neznata metoda avtentifikacije.\n"
+
+#: src/http.c:1314
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Polo�aj: %s%s\n"
 
-#: src/http.c:1770 src/http.c:1867
+#: src/http.c:1315 src/http.c:1454
 msgid "unspecified"
 msgstr "nedolo�en"
 
-#: src/http.c:1771
+#: src/http.c:1316
 msgid " [following]"
 msgstr " [spremljam]"
 
-#. If `-c' is in use and the file has been fully downloaded (or
-#. the remote file has shrunk), Wget effectively requests bytes
-#. after the end of file and the server response with 416.
-#: src/http.c:1817
+#: src/http.c:1383
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
