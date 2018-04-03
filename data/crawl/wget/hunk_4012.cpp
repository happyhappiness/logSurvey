 msgid " (%s bytes)"
 msgstr ""
 
-#: src/http.c:507
+#: src/http.c:508
 msgid "Failed writing HTTP request.\n"
 msgstr ""
 
-#: src/http.c:511
+#: src/http.c:512
 #, c-format
 msgid "%s request sent, awaiting response... "
 msgstr ""
 
-#: src/http.c:550
+#: src/http.c:551
 msgid "End of file while parsing headers.\n"
 msgstr ""
 
-#: src/http.c:561
+#: src/http.c:562
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr ""
 
-#: src/http.c:601
+#: src/http.c:602
 msgid "No data received"
 msgstr ""
 
-#: src/http.c:603
+#: src/http.c:604
 msgid "Malformed status line"
 msgstr ""
 
-#: src/http.c:608
+#: src/http.c:609
 msgid "(no description)"
 msgstr ""
 
 #. If we have tried it already, then there is not point
 #. retrying it.
-#: src/http.c:692
+#: src/http.c:693
 msgid "Authorization failed.\n"
 msgstr ""
 
-#: src/http.c:699
+#: src/http.c:700
 msgid "Unknown authentication scheme.\n"
 msgstr ""
 
-#: src/http.c:762
+#: src/http.c:783
 #, c-format
 msgid "Location: %s%s\n"
 msgstr ""
 
-#: src/http.c:763 src/http.c:788
+#: src/http.c:784 src/http.c:809
 msgid "unspecified"
 msgstr ""
 
-#: src/http.c:764
+#: src/http.c:785
 msgid " [following]"
 msgstr ""
 
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:778
+#: src/http.c:799
 msgid "Length: "
 msgstr ""
 
-#: src/http.c:783
+#: src/http.c:804
 #, c-format
 msgid " (%s to go)"
 msgstr ""
 
-#: src/http.c:788
+#: src/http.c:809
 msgid "ignored"
 msgstr ""
 
-#: src/http.c:880
+#: src/http.c:903
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr ""
 
 #. If opt.noclobber is turned on and file already exists, do not
 #. retrieve the file
-#: src/http.c:895
+#: src/http.c:924
 #, c-format
 msgid "File `%s' already there, will not retrieve.\n"
 msgstr ""
 
-#: src/http.c:1048
+#: src/http.c:1083
 #, c-format
 msgid "Cannot write to `%s' (%s).\n"
 msgstr ""
 
-#: src/http.c:1058
+#: src/http.c:1094
 #, c-format
 msgid "ERROR: Redirection (%d) without location.\n"
 msgstr ""
 
-#: src/http.c:1081
+#: src/http.c:1119
 #, c-format
 msgid "%s ERROR %d: %s.\n"
 msgstr ""
 
-#: src/http.c:1093
+#: src/http.c:1132
 msgid "Last-modified header missing -- time-stamps turned off.\n"
 msgstr ""
 
-#: src/http.c:1101
+#: src/http.c:1140
 msgid "Last-modified header invalid -- time-stamp ignored.\n"
 msgstr ""
 
-#. We can't collapse this down into just one logprintf()
-#. call with a variable set to u->local or the .orig
-#. filename because we have to malloc() space for the
-#. latter, and because there are multiple returns above (a
-#. coding style no-no by many measures, for reasons such as
-#. this) we'd have to remember to free() the string at each
-#. one to avoid a memory leak.
-#: src/http.c:1132
-#, c-format
-msgid ""
-"Server file no newer than local file `%s.orig' -- not retrieving.\n"
-"\n"
-msgstr ""
-
-#: src/http.c:1146
+#: src/http.c:1175
 msgid "Remote file is newer, retrieving.\n"
 msgstr ""
 
-#: src/http.c:1180
+#: src/http.c:1210
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld/%ld]\n"
 "\n"
 msgstr ""
 
-#: src/http.c:1214
+#: src/http.c:1258
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld. "
 msgstr ""
 
-#: src/http.c:1222
+#: src/http.c:1266
 #, c-format
 msgid ""
 "%s (%s) - `%s' saved [%ld/%ld])\n"
 "\n"
 msgstr ""
 
-#: src/http.c:1235
+#: src/http.c:1286
 #, c-format
 msgid "%s (%s) - Connection closed at byte %ld/%ld. "
 msgstr ""
 
-#: src/http.c:1246
+#: src/http.c:1297
 #, c-format
 msgid "%s (%s) - Read error at byte %ld (%s)."
 msgstr ""
 
-#: src/http.c:1254
+#: src/http.c:1305
 #, c-format
 msgid "%s (%s) - Read error at byte %ld/%ld (%s). "
 msgstr ""
 
-#: src/init.c:319 src/netrc.c:260
+#: src/init.c:320 src/netrc.c:260
 #, c-format
 msgid "%s: Cannot read %s (%s).\n"
 msgstr ""
 
-#: src/init.c:340 src/init.c:346
+#: src/init.c:341 src/init.c:347
 #, c-format
 msgid "%s: Error in %s at line %d.\n"
 msgstr ""
 
-#: src/init.c:377
+#: src/init.c:378
 #, c-format
 msgid "%s: Warning: Both system and user wgetrc point to `%s'.\n"
 msgstr ""
 
-#: src/init.c:465
+#: src/init.c:466
 #, c-format
 msgid "%s: BUG: unknown command `%s', value `%s'.\n"
 msgstr ""
 
-#: src/init.c:492
+#: src/init.c:493
 #, c-format
 msgid "%s: %s: Please specify on or off.\n"
 msgstr ""
 
-#: src/init.c:510 src/init.c:767 src/init.c:789 src/init.c:862
+#: src/init.c:511 src/init.c:768 src/init.c:790 src/init.c:863
 #, c-format
 msgid "%s: %s: Invalid specification `%s'.\n"
 msgstr ""
 
-#: src/init.c:623 src/init.c:645 src/init.c:667 src/init.c:693
+#: src/init.c:624 src/init.c:646 src/init.c:668 src/init.c:694
 #, c-format
 msgid "%s: Invalid specification `%s'\n"
 msgstr ""
