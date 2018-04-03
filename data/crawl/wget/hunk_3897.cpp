 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: Kein benutzbar \"socket driver\" auffindbar.\n"
 
-#: src/netrc.c:334
+#: src/netrc.c:360
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
 msgstr "%s: %s:%d: Warnung: »%s«-Wortteil erscheint vor einem Maschinennamen\n"
 
-#: src/netrc.c:365
+#: src/netrc.c:391
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: unbekannter Wortteil »%s«\n"
 
-#: src/netrc.c:429
+#: src/netrc.c:455
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Syntax: %s NETRC [HOSTNAME]\n"
 
 # stat
-#: src/netrc.c:439
+#: src/netrc.c:465
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: kann nicht finden %s: %s\n"
 
-#: src/recur.c:449 src/retr.c:462
-#, c-format
-msgid "Removing %s.\n"
-msgstr "Entferne »%s«.\n"
-
-#: src/recur.c:450
+#: src/recur.c:506
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Entferne »%s«, da dies zurückgewiesen werden soll.\n"
 
-#: src/recur.c:609
+#: src/recur.c:680
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Lade »robots.txt«; bitte Fehler ignorieren.\n"
 
-#: src/retr.c:193
+#: src/retr.c:209
 #, c-format
-msgid "\n          [ skipping %dK ]"
-msgstr "\n          [ %dK übersprungen ]"
+msgid ""
+"\n"
+"          [ skipping %dK ]"
+msgstr ""
+"\n"
+"          [ %dK übersprungen ]"
 
-#: src/retr.c:344
+#: src/retr.c:391
 msgid "Could not find proxy host.\n"
 msgstr "Proxy-Host nicht auffindbar.\n"
 
-#: src/retr.c:355
+#: src/retr.c:405
 #, c-format
 msgid "Proxy %s: Must be HTTP.\n"
 msgstr "Proxy %s: Muss HTTP sein.\n"
 
-#: src/retr.c:398
+#: src/retr.c:495
 #, c-format
-msgid "%s: Redirection to itself.\n"
-msgstr "%s: Umleitung auf sich selber.\n"
+msgid "%s: Redirection cycle detected.\n"
+msgstr "%s: Zyklische Umleitung festgestellt.\n"
 
-#: src/retr.c:483
-msgid "Giving up.\n\n"
-msgstr "Aufgegeben.\n\n"
+#: src/retr.c:589
+msgid ""
+"Giving up.\n"
+"\n"
+msgstr ""
+"Aufgegeben.\n"
+"\n"
 
-#: src/retr.c:483
-msgid "Retrying.\n\n"
-msgstr "Erneuter Versuch.\n\n"
+#: src/retr.c:589
+msgid ""
+"Retrying.\n"
+"\n"
+msgstr ""
+"Erneuter Versuch.\n"
+"\n"
 
-# ???
-#: src/url.c:940
+#: src/url.c:1316
 #, c-format
-msgid "Error (%s): Link %s without a base provided.\n"
-msgstr "Fehler (%s): Verweis »%s« ohne Basis-URL (»base«) versucht.\n"
+msgid "Converting %s... "
+msgstr "Umwandlung in »%s«... "
 
-#: src/url.c:955
+#: src/url.c:1329
+msgid "nothing to do.\n"
+msgstr "nichts zu tun.\n"
+
+#: src/url.c:1337 src/url.c:1361
 #, c-format
-msgid "Error (%s): Base %s relative, without referer URL.\n"
-msgstr "Fehler (%s): Basis-URL (»base«) %s relativ, ohne Bezugs-URL.\n"
+msgid "Cannot convert links in %s: %s\n"
+msgstr "Verweise nicht umwandelbar in »%s«: %s\n"
 
-#: src/url.c:1373
+#: src/url.c:1352
 #, c-format
-msgid "Converting %s... "
-msgstr "Umwandlung in %s... "
+msgid "Unable to delete `%s': %s\n"
+msgstr "Löschen von »%s« nicht möglich: %s\n"
 
-#: src/url.c:1378 src/url.c:1389
+#: src/url.c:1549
 #, c-format
-msgid "Cannot convert links in %s: %s\n"
-msgstr "Verweise nicht umwandelbar in %s: %s\n"
+msgid "Cannot back up %s as %s: %s\n"
+msgstr "Anlegen eines Backups von »%s« als »%s« nicht möglich: %s\n"
 
-#: src/utils.c:71
+#: src/utils.c:94
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: Nicht genügend Speicher.\n"
 
-#: src/utils.c:203
+#: src/utils.c:392
 msgid "Unknown/unsupported protocol"
-msgstr "Unbekanntes/nicht unterstütztes Protokoll"
+msgstr "Unbekanntes bzw. nicht unterstütztes Protokoll"
 
-#: src/utils.c:206
+#: src/utils.c:395
 msgid "Invalid port specification"
 msgstr "Ungültige Port-Angabe"
 
-#: src/utils.c:209
+#: src/utils.c:398
 msgid "Invalid host name"
 msgstr "Ungültiger Hostname"
 
-#: src/utils.c:430
+#: src/utils.c:619
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Entfernen des symbolischen Verweises »%s« fehlgeschlagen: %s\n"
