 #: src/mswindows.c:254 src/mswindows.c:262
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
-msgstr "%s: Kann keinen benutzbaren \"socket driver\" finden.\n"
+msgstr "%s: Kein benutzbar \"socket driver\" auffindbar.\n"
 
-#: src/netrc.c:359
+#: src/netrc.c:334
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
 msgstr "%s: %s:%d: Warnung: »%s«-Wortteil erscheint vor einem Maschinennamen\n"
 
-#: src/netrc.c:390
+#: src/netrc.c:365
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: unbekannter Wortteil »%s«\n"
 
-#: src/netrc.c:454
+#: src/netrc.c:429
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Syntax: %s NETRC [HOSTNAME]\n"
 
 # stat
-#: src/netrc.c:464
+#: src/netrc.c:439
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: kann nicht finden %s: %s\n"
 
-#: src/recur.c:469
+#: src/recur.c:449 src/retr.c:462
+#, c-format
+msgid "Removing %s.\n"
+msgstr "Entferne »%s«.\n"
+
+#: src/recur.c:450
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Entferne »%s«, da dies zurückgewiesen werden soll.\n"
 
-#: src/recur.c:630
+#: src/recur.c:609
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Lade »robots.txt«; bitte Fehler ignorieren.\n"
 
-#: src/retr.c:197
+#: src/retr.c:193
 #, c-format
-msgid ""
-"\n"
-"          [ skipping %dK ]"
-msgstr ""
-"\n"
-"          [ überspringe %dK ]"
+msgid "\n          [ skipping %dK ]"
+msgstr "\n          [ %dK übersprungen ]"
 
-#: src/retr.c:380
+#: src/retr.c:344
 msgid "Could not find proxy host.\n"
-msgstr "Kann Proxy-Host nicht finden.\n"
+msgstr "Proxy-Host nicht auffindbar.\n"
 
-#: src/retr.c:393
+#: src/retr.c:355
 #, c-format
 msgid "Proxy %s: Must be HTTP.\n"
 msgstr "Proxy %s: Muss HTTP sein.\n"
 
-#: src/retr.c:472
+#: src/retr.c:398
 #, c-format
 msgid "%s: Redirection to itself.\n"
-msgstr "%s: Redirektion auf sich selber.\n"
+msgstr "%s: Umleitung auf sich selber.\n"
 
-#: src/retr.c:486
-#, fuzzy, c-format
-msgid "%s: Redirection cycle detected.\n"
-msgstr "%s: Redirektion auf sich selber.\n"
+#: src/retr.c:483
+msgid "Giving up.\n\n"
+msgstr "Aufgegeben.\n\n"
 
-#: src/retr.c:581
-msgid ""
-"Giving up.\n"
-"\n"
-msgstr ""
-"Gebe auf.\n"
-"\n"
-
-#: src/retr.c:581
-msgid ""
-"Retrying.\n"
-"\n"
-msgstr ""
-"Versuche erneut.\n"
-"\n"
+#: src/retr.c:483
+msgid "Retrying.\n\n"
+msgstr "Erneuter Versuch.\n\n"
 
 # ???
-#: src/url.c:983
+#: src/url.c:940
 #, c-format
 msgid "Error (%s): Link %s without a base provided.\n"
-msgstr "Fehler (%s): Verweis »%s« ohne »base« versucht.\n"
+msgstr "Fehler (%s): Verweis »%s« ohne Basis-URL (»base«) versucht.\n"
 
-#: src/url.c:999
+#: src/url.c:955
 #, c-format
 msgid "Error (%s): Base %s relative, without referer URL.\n"
-msgstr "Fehler (%s): »Base« %s relativ, ohne Bezugs-URL.\n"
+msgstr "Fehler (%s): Basis-URL (»base«) %s relativ, ohne Bezugs-URL.\n"
 
-#: src/url.c:1533
+#: src/url.c:1373
 #, c-format
 msgid "Converting %s... "
-msgstr "Wandle um %s... "
+msgstr "Umwandlung in %s... "
 
-#: src/url.c:1538 src/url.c:1625
+#: src/url.c:1378 src/url.c:1389
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
-msgstr "Kann Verweise nicht umwandeln zu %s: %s\n"
-
-#: src/url.c:1601
-#, fuzzy, c-format
-msgid "Cannot back up %s as %s: %s\n"
-msgstr "Kann Verweise nicht umwandeln zu %s: %s\n"
+msgstr "Verweise nicht umwandelbar in %s: %s\n"
 
 #: src/utils.c:71
 #, c-format
