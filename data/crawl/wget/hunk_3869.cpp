 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: Kunde inte hitta anv�ndbar uttagsdrivrutin (socket driver).\n"
 
-#: src/netrc.c:334
+#: src/netrc.c:367
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
 msgstr "%s: %s:%d: varning: \"%s\"-m�rke f�rekommer framf�r alla maskinnamn\n"
 
-#: src/netrc.c:365
+#: src/netrc.c:398
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: ok�nt m�rke \"%s\"\n"
 
-#: src/netrc.c:429
+#: src/netrc.c:462
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Anv�ndning: %s NETRC [V�RDDATORNAMN]\n"
 
-#: src/netrc.c:439
+#: src/netrc.c:472
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: kan inte ta status p� %s: %s\n"
 
-#: src/recur.c:449 src/retr.c:462
-#, c-format
-msgid "Removing %s.\n"
-msgstr "Tar bort %s.\n"
-
-#: src/recur.c:450
+#: src/recur.c:506
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Tar bort %s eftersom den skulle ha avvisats.\n"
 
-#: src/recur.c:609
+#: src/recur.c:680
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Laddar robots.txt; v�nligen ignorera fel.\n"
 
-#: src/retr.c:193
+#: src/retr.c:217
 #, c-format
-msgid "\n          [ skipping %dK ]"
-msgstr "\n          [ hoppar �ver %dK ]"
+msgid ""
+"\n"
+"          [ skipping %dK ]"
+msgstr ""
+"\n"
+"          [ hoppar �ver %dK ]"
 
-#: src/retr.c:344
+#: src/retr.c:399
 msgid "Could not find proxy host.\n"
 msgstr "Kunde inte hitta proxy-v�rden.\n"
 
-#: src/retr.c:355
+#: src/retr.c:413
 #, c-format
 msgid "Proxy %s: Must be HTTP.\n"
 msgstr "Proxy %s: M�ste vara HTTP.\n"
 
-#: src/retr.c:398
-#, c-format
-msgid "%s: Redirection to itself.\n"
+#: src/retr.c:507
+#, fuzzy, c-format
+msgid "%s: Redirection cycle detected.\n"
 msgstr "%s: Omdirigering till sig sj�lv.\n"
 
-#: src/retr.c:483
-msgid "Giving up.\n\n"
-msgstr "Ger upp.\n\n"
-
-#: src/retr.c:483
-msgid "Retrying.\n\n"
-msgstr "F�rs�ker igen.\n\n"
-
-#: src/url.c:940
-#, c-format
-msgid "Error (%s): Link %s without a base provided.\n"
-msgstr "Fel (%s): L�nk %s given utan en bas.\n"
+#: src/retr.c:601
+msgid ""
+"Giving up.\n"
+"\n"
+msgstr ""
+"Ger upp.\n"
+"\n"
 
-#: src/url.c:955
-#, c-format
-msgid "Error (%s): Base %s relative, without referer URL.\n"
-msgstr "Fel (%s): Basen %s relativ utan h�nvisar-URL.\n"
+#: src/retr.c:601
+msgid ""
+"Retrying.\n"
+"\n"
+msgstr ""
+"F�rs�ker igen.\n"
+"\n"
 
-#: src/url.c:1373
+#: src/url.c:1325
 #, c-format
 msgid "Converting %s... "
 msgstr "Konverterar %s... "
 
-#: src/url.c:1378 src/url.c:1389
+#: src/url.c:1338
+msgid "nothing to do.\n"
+msgstr ""
+
+#: src/url.c:1346 src/url.c:1370
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Kan inte konvertera l�nkar i %s: %s\n"
 
-#: src/utils.c:71
+#: src/url.c:1361
+#, fuzzy, c-format
+msgid "Unable to delete `%s': %s\n"
+msgstr "Misslyckades med att ta bort symboliska l�nken \"%s\": %s\n"
+
+#: src/url.c:1558
+#, fuzzy, c-format
+msgid "Cannot back up %s as %s: %s\n"
+msgstr "Kan inte konvertera l�nkar i %s: %s\n"
+
+#: src/utils.c:94
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: Ej tillr�ckligt med minne.\n"
 
-#: src/utils.c:203
+#: src/utils.c:392
 msgid "Unknown/unsupported protocol"
 msgstr "Ok�nt/ej underst�tt protokoll"
 
-#: src/utils.c:206
+#: src/utils.c:395
 msgid "Invalid port specification"
 msgstr "Ogiltig portspecifikation"
 
-#: src/utils.c:209
+#: src/utils.c:398
 msgid "Invalid host name"
 msgstr "Ogiltigt v�rddatornamn"
 
-#: src/utils.c:430
+#: src/utils.c:619
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Misslyckades med att ta bort symboliska l�nken \"%s\": %s\n"
+
+#~ msgid ""
+#~ "Local file `%s' is more recent, not retrieving.\n"
+#~ "\n"
+#~ msgstr ""
+#~ "Lokala filen \"%s\" �r nyare, h�mtar inte.\n"
+#~ "\n"
+
+#~ msgid "Error (%s): Link %s without a base provided.\n"
+#~ msgstr "Fel (%s): L�nk %s given utan en bas.\n"
+
+#~ msgid "Error (%s): Base %s relative, without referer URL.\n"
+#~ msgstr "Fel (%s): Basen %s relativ utan h�nvisar-URL.\n"
