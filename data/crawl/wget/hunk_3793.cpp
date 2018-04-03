 #. that there can be valid reasons for the local host
 #. name not to be an FQDN, so I've decided to remove the
 #. annoying warning.
-#: src/host.c:516
+#: src/host.c:473
 #, c-format
 msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
 msgstr ""
 
-#: src/host.c:544
+#: src/host.c:501
 msgid "Host not found"
 msgstr ""
 
-#: src/host.c:546
+#: src/host.c:503
 msgid "Unknown error"
 msgstr ""
 
-#: src/html.c:615 src/html.c:617
-#, c-format
-msgid "Index of /%s on %s:%d"
-msgstr ""
-
-#: src/html.c:639
-msgid "time unknown       "
-msgstr ""
-
-#: src/html.c:643
-msgid "File        "
-msgstr ""
-
-#: src/html.c:646
-msgid "Directory   "
-msgstr ""
-
-#: src/html.c:649
-msgid "Link        "
-msgstr ""
-
-#: src/html.c:652
-msgid "Not sure    "
+#: src/http.c:625 src/http.c:1437
+msgid "Unable to establish SSL connection.\n"
 msgstr ""
 
-#: src/html.c:670
+#: src/http.c:633
 #, c-format
-msgid " (%s bytes)"
+msgid "Reusing connection to %s:%hu.\n"
 msgstr ""
 
-#: src/http.c:508
-msgid "Failed writing HTTP request.\n"
+#: src/http.c:809
+#, c-format
+msgid "Failed writing HTTP request: %s.\n"
 msgstr ""
 
-#: src/http.c:512
+#: src/http.c:814
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr ""
 
-#: src/http.c:551
+#: src/http.c:858
 msgid "End of file while parsing headers.\n"
 msgstr ""
 
-#: src/http.c:562
+#: src/http.c:869
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr ""
 
-#: src/http.c:602
+#: src/http.c:909
 msgid "No data received"
 msgstr ""
 
-#: src/http.c:604
+#: src/http.c:911
 msgid "Malformed status line"
 msgstr ""
 
-#: src/http.c:609
+#: src/http.c:916
 msgid "(no description)"
 msgstr ""
 
-#. If we have tried it already, then there is not point
-#. retrying it.
-#: src/http.c:693
+#: src/http.c:1034
 msgid "Authorization failed.\n"
 msgstr ""
 
-#: src/http.c:700
+#: src/http.c:1041
 msgid "Unknown authentication scheme.\n"
 msgstr ""
 
-#: src/http.c:783
+#: src/http.c:1131
 #, c-format
 msgid "Location: %s%s\n"
 msgstr ""
 
-#: src/http.c:784 src/http.c:809
+#: src/http.c:1132 src/http.c:1157
 msgid "unspecified"
 msgstr ""
 
-#: src/http.c:785
+#: src/http.c:1133
 msgid " [following]"
 msgstr ""
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:799
+#: src/http.c:1147
 msgid "Length: "
 msgstr ""
 
-#: src/http.c:804
+#: src/http.c:1152
 #, c-format
 msgid " (%s to go)"
 msgstr ""
 
-#: src/http.c:809
+#: src/http.c:1157
 msgid "ignored"
 msgstr ""
 
-#: src/http.c:912
+#: src/http.c:1258
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr ""
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:933
+#: src/http.c:1279
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr ""
 
-#: src/http.c:1099
+#: src/http.c:1429
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr ""
 
-#: src/http.c:1110
+#: src/http.c:1447
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr ""
 
-#: src/http.c:1135
+#: src/http.c:1472
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr ""
 
-#: src/http.c:1148
+#: src/http.c:1485
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr ""
 
-#: src/http.c:1156
+#: src/http.c:1493
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr ""
 
-#: src/http.c:1191
+#: src/http.c:1528
 msgid "Remote file is newer, retrieving.\n"
 msgstr ""
 
-#: src/http.c:1226
+#: src/http.c:1573
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld/%ld]\n"
 "\n"
 msgstr ""
 
-#: src/http.c:1274
+#: src/http.c:1621
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld. "
 msgstr ""
 
-#: src/http.c:1282
+#: src/http.c:1629
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld/%ld])\n"
 "\n"
 msgstr ""
 
-#: src/http.c:1302
+#: src/http.c:1649
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld/%ld. "
 msgstr ""
 
-#: src/http.c:1313
+#: src/http.c:1660
 #, c-format
 msgid "%s (%s) - Read error at byte %ld (%s)."
 msgstr ""
 
-#: src/http.c:1321
+#: src/http.c:1668
 #, c-format
 msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
 msgstr ""
 
-#: src/init.c:329 src/netrc.c:260
+#: src/init.c:332 src/netrc.c:261
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
 msgstr ""
