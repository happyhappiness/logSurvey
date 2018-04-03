 msgid "End of file while parsing headers.\n"
 msgstr ""
 
-#: src/http.c:920
+#: src/http.c:919
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr ""
 
-#: src/http.c:960
+#: src/http.c:958
 msgid "No data received"
 msgstr ""
 
-#: src/http.c:962
+#: src/http.c:960
 msgid "Malformed status line"
 msgstr ""
 
-#: src/http.c:967
+#: src/http.c:965
 msgid "(no description)"
 msgstr ""
 
-#: src/http.c:1090
+#: src/http.c:1088
 msgid "Authorization failed.\n"
 msgstr ""
 
-#: src/http.c:1097
+#: src/http.c:1095
 msgid "Unknown authentication scheme.\n"
 msgstr ""
 
-#: src/http.c:1173
+#: src/http.c:1135
+#, c-format
+msgid "Location: %s%s\n"
+msgstr ""
+
+#: src/http.c:1136 src/http.c:1268
+msgid "unspecified"
+msgstr ""
+
+#: src/http.c:1137
+msgid " [following]"
+msgstr ""
+
+#: src/http.c:1199
 msgid ""
 "\n"
 "    The file is already fully retrieved; nothing to do.\n"
 "\n"
 msgstr ""
 
-#: src/http.c:1190
+#: src/http.c:1215
 #, c-format
 msgid ""
 "\n"
-"    The server does not support continued download;\n"
-"    refusing to truncate `%s'.\n"
+"The server does not support continued downloads, which conflicts with `-c'.\n"
+"Refusing to truncate existing file `%s'.\n"
 "\n"
 msgstr ""
 
-#: src/http.c:1238
-#, c-format
-msgid "Location: %s%s\n"
-msgstr ""
-
-#: src/http.c:1239 src/http.c:1265
-msgid "unspecified"
-msgstr ""
-
-#: src/http.c:1240
-msgid " [following]"
-msgstr ""
-
 #. No need to print this output if the body won't be
 #. downloaded at all, or if the original server response is
 #. printed.
-#: src/http.c:1255
+#: src/http.c:1258
 msgid "Length: "
 msgstr ""
 
-#: src/http.c:1260
+#: src/http.c:1263
 #, c-format
 msgid " (%s to go)"
 msgstr ""
 
-#: src/http.c:1265
+#: src/http.c:1268
 msgid "ignored"
 msgstr ""
 
-#: src/http.c:1395
+#: src/http.c:1398
 msgid "Warning: wildcards not supported in HTTP.\n"
 msgstr ""
 
