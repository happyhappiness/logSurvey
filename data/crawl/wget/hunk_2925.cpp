 "Celkem naèteno %s bajtù v %d souborech\n"
 
 # , c-format
-#: src/main.c:842
+#: src/main.c:951
 #, c-format
 msgid "Download quota (%s bytes) EXCEEDED!\n"
 msgstr "Pøekroèen limit objemu ulo¾ených dat (%s bajtù)!\n"
 
-#. Please note that the double `%' in `%%s' is intentional, because
-#. redirect_output passes tmp through printf.
-#: src/main.c:876
-msgid "%s received, redirecting output to `%%s'.\n"
-msgstr "Byl zachycen signál %s, výstup pøesmìrován do `%%s'.\n"
-
-# , c-format
-#: src/mswindows.c:89
+#: src/mswindows.c:235
 #, c-format
-msgid ""
-"\n"
-"CTRL+Break received, redirecting output to `%s'.\n"
-"Execution continued in background.\n"
-"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
-msgstr ""
-"\n"
-"Stiskli jste CTRL+Break, výstup byl proto pøesmìrován do `%s'.\n"
-"Program pokraèuje v bìhu na pozadí.\n"
-"Wget lze zastavit stiskem CTRL+ALT+DELETE.\n"
-
-#. parent, no error
-#: src/mswindows.c:106 src/utils.c:458
 msgid "Continuing in background.\n"
 msgstr "Program pokraèuje v bìhu na pozadí.\n"
 
+#: src/mswindows.c:427
+#, fuzzy, c-format
+msgid "Continuing in background, pid %lu.\n"
+msgstr "Program pokraèuje v bìhu na pozadí.\n"
+
 # , c-format
-#: src/mswindows.c:108 src/utils.c:460
+#: src/mswindows.c:429 src/utils.c:349
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr "Výstup bude zapsán do `%s'.\n"
 
-# , c-format
-#: src/mswindows.c:188
-#, c-format
-msgid "Starting WinHelp %s\n"
-msgstr "Spou¹tí se WinHelp %s\n"
-
-#: src/mswindows.c:215 src/mswindows.c:222
+#: src/mswindows.c:597 src/mswindows.c:604
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: Nelze najít pou¾itelný ovladaè socketù.\n"
 
 # , c-format
-#: src/netrc.c:367
+#: src/netrc.c:385
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
 msgstr ""
