 msgid "%s: option `-W %s' doesn't allow an argument\n"
 msgstr "%s: uz opciju `-W %s' ne ide argument\n"
 
-#: src/host.c:644
+#: src/host.c:345
+msgid "Unknown host"
+msgstr "Nepoznat host"
+
+#. Message modeled after what gai_strerror returns in similar
+#. circumstances.
+#: src/host.c:349
+msgid "Temporary failure in name resolution"
+msgstr "Privremena pogre�ka pri pronala�enju adrese"
+
+#: src/host.c:351
+msgid "Unknown error"
+msgstr "Nepoznata gre�ka"
+
+#: src/host.c:569
 #, c-format
 msgid "Resolving %s... "
 msgstr "Tra�im %s... "
 
-#: src/host.c:664 src/host.c:680
+#: src/host.c:598 src/host.c:619
 #, c-format
 msgid "failed: %s.\n"
 msgstr "nije uspjelo: %s.\n"
 
-#: src/host.c:682
-msgid "failed: timed out.\n"
-msgstr "nije uspjelo: time out.\n"
+#: src/host.c:607
+msgid "failed: No IPv4/IPv6 addresses for host.\n"
+msgstr "neuspjeh: ra�unalo nema IPv4/IPv6 adresa.\n"
 
-#: src/host.c:770
-msgid "Host not found"
-msgstr "Ra�unalo nije prona�eno"
-
-#: src/host.c:772
-msgid "Unknown error"
-msgstr "Nepoznata gre�ka"
+#: src/host.c:622
+msgid "failed: timed out.\n"
+msgstr "neuspjeh: isteklo vrijeme.\n"
 
-#: src/html-url.c:351
+#: src/html-url.c:297
 #, c-format
 msgid "%s: Cannot resolve incomplete link %s.\n"
 msgstr "%s: Ne mogu sastaviti nepotpun link %s.\n"
 
 #. this is fatal
-#: src/http.c:673
+#: src/http.c:645
 msgid "Failed to set up an SSL context\n"
 msgstr "Gre�ka pri uspostavljanju SSL konteksta\n"
 
-#: src/http.c:679
+#: src/http.c:650
 #, c-format
 msgid "Failed to load certificates from %s\n"
 msgstr "Nisam uspio u�itati ovjere iz %s\n"
 
-#: src/http.c:683 src/http.c:691
+#: src/http.c:653 src/http.c:660
 msgid "Trying without the specified certificate\n"
 msgstr "Poku�avam bez zadane ovjere\n"
 
-#: src/http.c:687
+#: src/http.c:657
 #, c-format
 msgid "Failed to get certificate key from %s\n"
 msgstr "Nisam uspio dobiti certifikat klju�a iz %s\n"
 
-#: src/http.c:760 src/http.c:1808
+#: src/http.c:732 src/http.c:1751
 msgid "Unable to establish SSL connection.\n"
 msgstr "Ne mogu uspostaviti SSL vezu.\n"
 
-#: src/http.c:769
+#: src/http.c:742
 #, c-format
-msgid "Reusing connection to %s:%hu.\n"
-msgstr "Koristim postoje�u vezu prema %s:%hu.\n"
+msgid "Reusing existing connection to %s:%d.\n"
+msgstr "Koristim postoje�u vezu prema %s:%d.\n"
 
-#: src/http.c:1033
+#: src/http.c:982
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Nisam uspio poslati HTTP zahtjev: %s.\n"
 
-#: src/http.c:1038
+#: src/http.c:987
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr "%s zahtjev poslan, i��ekujem odgovor... "
 
-#: src/http.c:1082
+#: src/http.c:1028
 msgid "End of file while parsing headers.\n"
 msgstr "Kraj spisa za vrijeme obrade zaglavlja.\n"
 
-#: src/http.c:1092
+#: src/http.c:1038
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Gre�ka pri �itanju zaglavlja (%s).\n"
 
-#: src/http.c:1127
+#: src/http.c:1073
 msgid "No data received"
 msgstr "Podaci nisu primljeni"
 
-#: src/http.c:1129
+#: src/http.c:1075
 msgid "Malformed status line"
 msgstr "Deformirana statusna linija"
 
-#: src/http.c:1134
+#: src/http.c:1080
 msgid "(no description)"
 msgstr "(bez opisa)"
 
-#: src/http.c:1266
+#: src/http.c:1209
 msgid "Authorization failed.\n"
 msgstr "Ovjera nije uspjela.\n"
 
-#: src/http.c:1273
+#: src/http.c:1216
 msgid "Unknown authentication scheme.\n"
 msgstr "Nepoznata metoda ovjere.\n"
 
-#: src/http.c:1313
+#: src/http.c:1256
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Polo�aj: %s%s\n"
 
-#: src/http.c:1314 src/http.c:1453
+#: src/http.c:1257 src/http.c:1396
 msgid "unspecified"
 msgstr "nenazna�en"
 
-#: src/http.c:1315
+#: src/http.c:1258
 msgid " [following]"
 msgstr " [pratim]"
 
-#: src/http.c:1382
+#: src/http.c:1325
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
