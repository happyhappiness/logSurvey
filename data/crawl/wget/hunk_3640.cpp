 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: kann nicht finden %s: %s\n"
 
-#: src/recur.c:510
+#: src/recur.c:484
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Entferne »%s«, da dies zurückgewiesen werden soll.\n"
 
-#: src/recur.c:684
+#: src/recur.c:679
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Lade »robots.txt«; bitte Fehler ignorieren.\n"
 
-#: src/retr.c:229
+#: src/retr.c:227
 #, c-format
-msgid ""
-"\n"
-"          [ skipping %dK ]"
-msgstr ""
-"\n"
-"          [ %dK übersprungen ]"
+msgid "\n          [ skipping %dK ]"
+msgstr "\n          [ %dK übersprungen ]"
 
-#: src/retr.c:421
+#: src/retr.c:373
 msgid "Could not find proxy host.\n"
 msgstr "Proxy-Host nicht auffindbar.\n"
 
-#: src/retr.c:435
+#: src/retr.c:387
 #, c-format
 msgid "Proxy %s: Must be HTTP.\n"
 msgstr "Proxy %s: Muss HTTP sein.\n"
 
-#: src/retr.c:529
+#: src/retr.c:481
 #, c-format
 msgid "%s: Redirection cycle detected.\n"
-msgstr "%s: Zyklische Umleitung festgestellt.\n"
+msgstr "%s: Zyklischer Rückverweis festgestellt.\n"
 
-#: src/retr.c:623
-msgid ""
-"Giving up.\n"
-"\n"
-msgstr ""
-"Aufgegeben.\n"
-"\n"
+#: src/retr.c:587
+msgid "Giving up.\n\n"
+msgstr "Aufgegeben.\n\n"
 
-#: src/retr.c:623
-msgid ""
-"Retrying.\n"
-"\n"
-msgstr ""
-"Erneuter Versuch.\n"
-"\n"
+#: src/retr.c:587
+msgid "Retrying.\n\n"
+msgstr "Erneuter Versuch.\n\n"
 
-#: src/url.c:1332
+#: src/url.c:1329
 #, c-format
 msgid "Converting %s... "
 msgstr "Umwandlung in »%s«... "
 
-#: src/url.c:1345
+#: src/url.c:1342
 msgid "nothing to do.\n"
-msgstr "nichts zu tun.\n"
+msgstr "kein Download notwendig.\n"
 
-#: src/url.c:1353 src/url.c:1377
+#: src/url.c:1350 src/url.c:1374
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Verweise nicht umwandelbar in »%s«: %s\n"
 
-#: src/url.c:1368
+#: src/url.c:1365
 #, c-format
 msgid "Unable to delete `%s': %s\n"
-msgstr "Löschen von »%s« nicht möglich: %s\n"
+msgstr "Es ist nicht möglich, »%s« zu löschen: %s\n"
 
-#: src/url.c:1558
+#: src/url.c:1555
 #, c-format
 msgid "Cannot back up %s as %s: %s\n"
 msgstr "Anlegen eines Backups von »%s« als »%s« nicht möglich: %s\n"
 
-#: src/utils.c:94
+#: src/utils.c:93
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: Nicht genügend Speicher.\n"
 
-#: src/utils.c:386
+#: src/utils.c:416
 msgid "Unknown/unsupported protocol"
 msgstr "Unbekanntes bzw. nicht unterstütztes Protokoll"
 
-#: src/utils.c:389
+#: src/utils.c:419
 msgid "Invalid port specification"
 msgstr "Ungültige Port-Angabe"
 
-#: src/utils.c:392
+#: src/utils.c:422
 msgid "Invalid host name"
 msgstr "Ungültiger Hostname"
 
-#: src/utils.c:613
+#: src/utils.c:619
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Entfernen des symbolischen Verweises »%s« fehlgeschlagen: %s\n"
 
-#~ msgid "Cannot compare sizes, remote system is VMS.\n"
-#~ msgstr "Größe nicht bestimmbar; das System der Gegenseite ist VMS.\n"
+#~ msgid "%s: Cannot determine user-id.\n"
+#~ msgstr "%s: Benutzer-Kennung (User-ID) nicht bestimmbar.\n"
+
+#~ msgid "%s: Warning: uname failed: %s\n"
+#~ msgstr "%s: Warnung: uname fehlgeschlagen: %s\n"
+
+#~ msgid "%s: Warning: gethostname failed\n"
+#~ msgstr "%s: Warnung: gethostname fehlgeschlagen\n"
+
+#~ msgid "%s: Warning: cannot determine local IP address.\n"
+#~ msgstr "%s: Warnung: lokale IP-Adresse nicht bestimmbar.\n"
+
+#~ msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
+#~ msgstr "%s: Warnung: kein \"reverse-lookup\" für lokale IP-Adresse möglich.\n"
+
+#~ msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
+#~ msgstr "%s: Warnung: \"reverse-lookup\" für lokale Adresse ergibt keinen FQDN!\n"
+
+#~ msgid "%s: Redirection to itself.\n"
+#~ msgstr "%s: Rückverweis auf sich selbst.\n"
+
+#~ msgid "Error (%s): Link %s without a base provided.\n"
+#~ msgstr "Fehler (%s): Link %s ohne eine Basis-Angabe.\n"
 
-#~ msgid "%s: Out of memory.\n"
-#~ msgstr "%s: Nicht genügend Speicher.\n"
+#~ msgid "Error (%s): Base %s relative, without referer URL.\n"
+#~ msgstr "Fehler (%s): Basis-Angabe %s ist relativ, ohne Bezugs-URL.\n"
