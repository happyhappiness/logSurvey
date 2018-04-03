 "Du kan stoppa Wget genom att trycka CTRL+ALT+DELETE.\n"
 
 #. parent, no error
-#: src/mswindows.c:106 src/utils.c:458
+#: src/mswindows.c:123 src/utils.c:462
 msgid "Continuing in background.\n"
 msgstr "Fortsätter i bakgrunden.\n"
 
-#: src/mswindows.c:108 src/utils.c:460
+#: src/mswindows.c:125 src/utils.c:464
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr "Utdata skrivs till \"%s\".\n"
 
-#: src/mswindows.c:188
+#: src/mswindows.c:205
 #, c-format
 msgid "Starting WinHelp %s\n"
 msgstr "Startar WinHelp %s\n"
 
-#: src/mswindows.c:215 src/mswindows.c:222
+#: src/mswindows.c:232 src/mswindows.c:239
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: Kunde inte hitta användbar uttagsdrivrutin (socket driver).\n"
 
-#: src/netrc.c:367
+#: src/netrc.c:365
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
 msgstr "%s: %s:%d: varning: \"%s\"-märke förekommer framför alla maskinnamn\n"
 
-#: src/netrc.c:398
+#: src/netrc.c:396
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: okänt märke \"%s\"\n"
 
-#: src/netrc.c:462
+#: src/netrc.c:460
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Användning: %s NETRC [VÄRDDATORNAMN]\n"
 
-#: src/netrc.c:472
+#: src/netrc.c:470
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: kan inte ta status på %s: %s\n"
 
-#: src/recur.c:484
+#. Align the [ skipping ... ] line with the dots.  To do
+#. that, insert the number of spaces equal to the number of
+#. digits in the skipped amount in K.
+#: src/progress.c:203
+#, c-format
+msgid "\n%*s[ skipping %dK ]"
+msgstr "\n%*s[ hoppar över %d kB ]"
+
+#: src/progress.c:370
+#, c-format
+msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
+msgstr "Punktstilsspecifikationen \"%s\" är ogiltig; lämnar oförändrad.\n"
+
+#: src/recur.c:337
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Tar bort %s eftersom den skulle ha avvisats.\n"
 
-#: src/recur.c:679
+#: src/recur.c:747
+#, c-format
+msgid "Converted %d files in %.2f seconds.\n"
+msgstr "Konverterade %d filer på %.2f sekunder.\n"
+
+#: src/res.c:541
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Läser in robots.txt; ignorera fel.\n"
 
-#: src/retr.c:227
-#, c-format
-msgid "\n          [ skipping %dK ]"
-msgstr "\n          [ hoppar över %dK ]"
-
-#: src/retr.c:373
+#: src/retr.c:363
 msgid "Could not find proxy host.\n"
 msgstr "Kunde inte hitta proxyvärden.\n"
 
-#: src/retr.c:387
+#: src/retr.c:375
+#, c-format
+msgid "Error parsing proxy URL %s: %s.\n"
+msgstr "Fel vid tolkning av proxy-URL %s: %s.\n"
+
+#: src/retr.c:384
 #, c-format
-msgid "Proxy %s: Must be HTTP.\n"
-msgstr "Proxy %s: Måste vara HTTP.\n"
+msgid "Error in proxy URL %s: Must be HTTP.\n"
+msgstr "Fel i proxy-URL %s: Måste vara HTTP.\n"
 
-#: src/retr.c:481
+#: src/retr.c:476
+#, c-format
+msgid "%d redirections exceeded.\n"
+msgstr "%d omdirigeringar överskreds.\n"
+
+#: src/retr.c:491
 #, c-format
 msgid "%s: Redirection cycle detected.\n"
 msgstr "%s: Omdirigeringscykel upptäckt.\n"
 
-#: src/retr.c:587
+#: src/retr.c:608
 msgid "Giving up.\n\n"
 msgstr "Ger upp.\n\n"
 
-#: src/retr.c:587
+#: src/retr.c:608
 msgid "Retrying.\n\n"
 msgstr "Försöker igen.\n\n"
 
-#: src/url.c:1329
+#: src/url.c:1725
 #, c-format
 msgid "Converting %s... "
 msgstr "Konverterar %s... "
 
-#: src/url.c:1342
+#: src/url.c:1738
 msgid "nothing to do.\n"
 msgstr "inget att göra.\n"
 
-#: src/url.c:1350 src/url.c:1374
+#: src/url.c:1746 src/url.c:1770
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Kan inte konvertera länkar i %s: %s\n"
 
-#: src/url.c:1365
+#: src/url.c:1761
 #, c-format
 msgid "Unable to delete `%s': %s\n"
 msgstr "Kan inte ta bort \"%s\": %s\n"
 
-#: src/url.c:1555
+#: src/url.c:1967
 #, c-format
 msgid "Cannot back up %s as %s: %s\n"
 msgstr "Kan inte säkerhetskopiera %s som %s: %s\n"
 
-#: src/utils.c:94
+#: src/utils.c:97
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: Inte tillräckligt med minne.\n"
 
-#: src/utils.c:417
-msgid "Unknown/unsupported protocol"
-msgstr "Okänt protokoll/protokollet stöds inte"
-
-#: src/utils.c:420
-msgid "Invalid port specification"
-msgstr "Ogiltig portspecifikation"
-
-#: src/utils.c:423
-msgid "Invalid host name"
-msgstr "Ogiltigt värddatornamn"
-
-#: src/utils.c:620
+#: src/utils.c:634
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Misslyckades med att ta bort symboliska länken \"%s\": %s\n"
 
+#~ msgid "Connection to %s:%hu refused.\n"
+#~ msgstr "Anslutning till %s:%hu vägras.\n"
+
+#~ msgid "Will try connecting to %s:%hu.\n"
+#~ msgstr "Försöker ansluta till %s:%hu.\n"
+
+#~ msgid "Unknown/unsupported protocol"
+#~ msgstr "Okänt protokoll/protokollet stöds inte"
+
+#~ msgid "Invalid port specification"
+#~ msgstr "Ogiltig portspecifikation"
+
+#~ msgid "Invalid host name"
+#~ msgstr "Ogiltigt värddatornamn"
+
 #~ msgid "%s: Cannot determine user-id.\n"
 #~ msgstr "%s: Kan inte avgöra användar-id.\n"
 
