 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: Fant ingen brukbar socket-driver.\n"
 
-#: src/netrc.c:359
+#: src/netrc.c:334
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
 msgstr "%s: %s:%d: Advarsel: symbolet �%s� funnet f�r tjener-navn\n"
 
-#: src/netrc.c:390
+#: src/netrc.c:365
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: ukjent symbol �%s�\n"
 
-#: src/netrc.c:454
+#: src/netrc.c:429
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Bruk: %s NETRC [TJENERNAVN]\n"
 
-#: src/netrc.c:464
+#: src/netrc.c:439
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: �stat� feilet for %s: %s\n"
 
-#: src/recur.c:469
+#: src/recur.c:449 src/retr.c:462
+#, c-format
+msgid "Removing %s.\n"
+msgstr "Fjerner %s.\n"
+
+#: src/recur.c:450
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Fjerner %s fordi den skal forkastes.\n"
 
-#: src/recur.c:630
+#: src/recur.c:609
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Henter robots.txt; ignorer eventuelle feilmeldinger.\n"
 
-#: src/retr.c:197
+#: src/retr.c:193
 #, c-format
-msgid ""
-"\n"
-"          [ skipping %dK ]"
-msgstr ""
-"\n"
-"          [ hopper over %dK ]"
+msgid "\n          [ skipping %dK ]"
+msgstr "\n          [ hopper over %dK ]"
 
-#: src/retr.c:380
+#: src/retr.c:344
 msgid "Could not find proxy host.\n"
 msgstr "Fant ikke proxy-tjener.\n"
 
-#: src/retr.c:393
+#: src/retr.c:355
 #, c-format
 msgid "Proxy %s: Must be HTTP.\n"
 msgstr "Proxy %s: M� st�tte HTTP.\n"
 
-#: src/retr.c:472
+#: src/retr.c:398
 #, c-format
 msgid "%s: Redirection to itself.\n"
 msgstr "%s: Omdirigerer til seg selv.\n"
 
-#: src/retr.c:486
-#, fuzzy, c-format
-msgid "%s: Redirection cycle detected.\n"
-msgstr "%s: Omdirigerer til seg selv.\n"
+#: src/retr.c:483
+msgid "Giving up.\n\n"
+msgstr "Gir opp.\n\n"
 
-#: src/retr.c:581
-msgid ""
-"Giving up.\n"
-"\n"
-msgstr ""
-"Gir opp.\n"
-"\n"
-
-#: src/retr.c:581
-msgid ""
-"Retrying.\n"
-"\n"
-msgstr ""
-"Pr�ver igjen.\n"
-"\n"
+#: src/retr.c:483
+msgid "Retrying.\n\n"
+msgstr "Pr�ver igjen.\n\n"
 
-#: src/url.c:983
+#: src/url.c:940
 #, c-format
 msgid "Error (%s): Link %s without a base provided.\n"
 msgstr "Feil (%s): Link %s gitt uten utgangspunkt.\n"
 
-#: src/url.c:999
+#: src/url.c:955
 #, c-format
 msgid "Error (%s): Base %s relative, without referer URL.\n"
 msgstr "Feil (%s): Utgangspunktet %s er relativt, ukjent URL som referent.\n"
 
-#: src/url.c:1533
+#: src/url.c:1373
 #, c-format
 msgid "Converting %s... "
 msgstr "Konverterer %s... "
 
-#: src/url.c:1538 src/url.c:1625
+#: src/url.c:1378 src/url.c:1389
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Kan ikke konvertere linker i %s: %s\n"
 
-#: src/url.c:1601
-#, fuzzy, c-format
-msgid "Cannot back up %s as %s: %s\n"
-msgstr "Kan ikke konvertere linker i %s: %s\n"
-
 #: src/utils.c:71
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
