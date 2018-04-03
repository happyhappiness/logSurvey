 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: Kan geen bruikbare \"socket driver\" vinden.\n"
 
-#: src/netrc.c:334
+#: src/netrc.c:367
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
 msgstr "%s: %s:%d: Waarschuwing: `%s'-teken verschijnt voor een machinenaam\n"
 
-#: src/netrc.c:365
+#: src/netrc.c:398
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: onbekend teken `%s'\n"
 
-#: src/netrc.c:429
+#: src/netrc.c:462
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Aanroep: %s NETRC [HOSTNAME]\n"
 
 # stat
-#: src/netrc.c:439
+#: src/netrc.c:472
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: kan de status van bestand %s niet opvragen: %s\n"
 
-#: src/recur.c:449 src/retr.c:462
-#, c-format
-msgid "Removing %s.\n"
-msgstr "Verwijder `%s'.\n"
-
-#: src/recur.c:450
+#: src/recur.c:506
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Verwijder `%s' omdat het verworpen zal worden.\n"
 
-#: src/recur.c:609
+#: src/recur.c:680
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Laad `robots.txt'; gelieve fouten te negeren.\n"
 
-#: src/retr.c:193
+#: src/retr.c:217
 #, c-format
-msgid "\n          [ skipping %dK ]"
-msgstr "\n          [ overslaan %dK ]"
+msgid ""
+"\n"
+"          [ skipping %dK ]"
+msgstr ""
+"\n"
+"          [ overslaan %dK ]"
 
-#: src/retr.c:344
+#: src/retr.c:399
 msgid "Could not find proxy host.\n"
 msgstr "Kan proxy-host niet vinden.\n"
 
-#: src/retr.c:355
+#: src/retr.c:413
 #, c-format
 msgid "Proxy %s: Must be HTTP.\n"
 msgstr "Proxy %s: Moet HTTP zijn.\n"
 
-#: src/retr.c:398
-#, c-format
-msgid "%s: Redirection to itself.\n"
+#: src/retr.c:507
+#, fuzzy, c-format
+msgid "%s: Redirection cycle detected.\n"
 msgstr "%s: Omleiding naar zichzelf.\n"
 
-#: src/retr.c:483
-msgid "Giving up.\n\n"
-msgstr "Geef op.\n\n"
-
-#: src/retr.c:483
-msgid "Retrying.\n\n"
-msgstr "Opnieuw proberen.\n\n"
-
-# ???
-#: src/url.c:935
-#, c-format
-msgid "Error (%s): Link %s without a base provided.\n"
-msgstr "Fout (%s): Verwijzing `%s' zonder basis aangeboden.\n"
+#: src/retr.c:601
+msgid ""
+"Giving up.\n"
+"\n"
+msgstr ""
+"Geef op.\n"
+"\n"
 
-#: src/url.c:950
-#, c-format
-msgid "Error (%s): Base %s relative, without referer URL.\n"
-msgstr "Fout (%s): Basis %s relatief, zonder verwijzings-URL.\n"
+#: src/retr.c:601
+msgid ""
+"Retrying.\n"
+"\n"
+msgstr ""
+"Opnieuw proberen.\n"
+"\n"
 
-#: src/url.c:1368
+#: src/url.c:1325
 #, c-format
 msgid "Converting %s... "
 msgstr "Omzetten %s... "
 
-#: src/url.c:1373 src/url.c:1384
+#: src/url.c:1338
+msgid "nothing to do.\n"
+msgstr ""
+
+#: src/url.c:1346 src/url.c:1370
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Kan verwijzingen niet omzetten naar %s: %s\n"
 
-#: src/utils.c:68
+#: src/url.c:1361
+#, fuzzy, c-format
+msgid "Unable to delete `%s': %s\n"
+msgstr "Verwijderen symbolische koppeling `%s' gefaald: %s\n"
+
+#: src/url.c:1558
+#, fuzzy, c-format
+msgid "Cannot back up %s as %s: %s\n"
+msgstr "Kan verwijzingen niet omzetten naar %s: %s\n"
+
+#: src/utils.c:94
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: Onvoldoende geheugen.\n"
 
-#: src/utils.c:200
+#: src/utils.c:392
 msgid "Unknown/unsupported protocol"
 msgstr "Onbekend/niet-ondersteund protocol"
 
-#: src/utils.c:203
+#: src/utils.c:395
 msgid "Invalid port specification"
 msgstr "Ongeldige poort-specificatie"
 
-#: src/utils.c:206
+#: src/utils.c:398
 msgid "Invalid host name"
 msgstr "Ongeldige computernaam"
 
-#: src/utils.c:427
+#: src/utils.c:619
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Verwijderen symbolische koppeling `%s' gefaald: %s\n"
+
+#~ msgid ""
+#~ "Local file `%s' is more recent, not retrieving.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Lokaal bestand `%s' is nieuwer, niet ophalen.\n"
+#~ "\n"
+
+# ???
+#~ msgid "Error (%s): Link %s without a base provided.\n"
+#~ msgstr "Fout (%s): Verwijzing `%s' zonder basis aangeboden.\n"
+
+#~ msgid "Error (%s): Base %s relative, without referer URL.\n"
+#~ msgstr "Fout (%s): Basis %s relatief, zonder verwijzings-URL.\n"
