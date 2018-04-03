 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: kan inte ta status på %s: %s\n"
 
-#: src/recur.c:510
+#: src/recur.c:484
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Tar bort %s eftersom den skulle ha avvisats.\n"
 
-#: src/recur.c:684
+#: src/recur.c:679
 msgid "Loading robots.txt; please ignore errors.\n"
-msgstr "Laddar robots.txt; vänligen ignorera fel.\n"
+msgstr "Läser in robots.txt; ignorera fel.\n"
 
-#: src/retr.c:229
+#: src/retr.c:227
 #, c-format
-msgid ""
-"\n"
-"          [ skipping %dK ]"
-msgstr ""
-"\n"
-"          [ hoppar över %dK ]"
+msgid "\n          [ skipping %dK ]"
+msgstr "\n          [ hoppar över %dK ]"
 
-#: src/retr.c:421
+#: src/retr.c:373
 msgid "Could not find proxy host.\n"
-msgstr "Kunde inte hitta proxy-värden.\n"
+msgstr "Kunde inte hitta proxyvärden.\n"
 
-#: src/retr.c:435
+#: src/retr.c:387
 #, c-format
 msgid "Proxy %s: Must be HTTP.\n"
 msgstr "Proxy %s: Måste vara HTTP.\n"
 
-#: src/retr.c:529
-#, fuzzy, c-format
+#: src/retr.c:481
+#, c-format
 msgid "%s: Redirection cycle detected.\n"
-msgstr "%s: Omdirigering till sig själv.\n"
+msgstr "%s: Omdirigeringscykel upptäckt.\n"
 
-#: src/retr.c:623
-msgid ""
-"Giving up.\n"
-"\n"
-msgstr ""
-"Ger upp.\n"
-"\n"
+#: src/retr.c:587
+msgid "Giving up.\n\n"
+msgstr "Ger upp.\n\n"
 
-#: src/retr.c:623
-msgid ""
-"Retrying.\n"
-"\n"
-msgstr ""
-"Försöker igen.\n"
-"\n"
+#: src/retr.c:587
+msgid "Retrying.\n\n"
+msgstr "Försöker igen.\n\n"
 
-#: src/url.c:1332
+#: src/url.c:1329
 #, c-format
 msgid "Converting %s... "
 msgstr "Konverterar %s... "
 
-#: src/url.c:1345
+#: src/url.c:1342
 msgid "nothing to do.\n"
-msgstr ""
+msgstr "inget att göra.\n"
 
-#: src/url.c:1353 src/url.c:1377
+#: src/url.c:1350 src/url.c:1374
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Kan inte konvertera länkar i %s: %s\n"
 
-#: src/url.c:1368
-#, fuzzy, c-format
+#: src/url.c:1365
+#, c-format
 msgid "Unable to delete `%s': %s\n"
-msgstr "Misslyckades med att ta bort symboliska länken \"%s\": %s\n"
+msgstr "Kan inte ta bort \"%s\": %s\n"
 
-#: src/url.c:1558
-#, fuzzy, c-format
+#: src/url.c:1555
+#, c-format
 msgid "Cannot back up %s as %s: %s\n"
-msgstr "Kan inte konvertera länkar i %s: %s\n"
+msgstr "Kan inte säkerhetskopiera %s som %s: %s\n"
 
-#: src/utils.c:94
+#: src/utils.c:93
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
-msgstr "%s: %s: Ej tillräckligt med minne.\n"
+msgstr "%s: %s: Inte tillräckligt med minne.\n"
 
-#: src/utils.c:386
+#: src/utils.c:416
 msgid "Unknown/unsupported protocol"
-msgstr "Okänt/ej understött protokoll"
+msgstr "Okänt protokoll/protokollet stöds inte"
 
-#: src/utils.c:389
+#: src/utils.c:419
 msgid "Invalid port specification"
 msgstr "Ogiltig portspecifikation"
 
-#: src/utils.c:392
+#: src/utils.c:422
 msgid "Invalid host name"
 msgstr "Ogiltigt värddatornamn"
 
-#: src/utils.c:613
+#: src/utils.c:619
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Misslyckades med att ta bort symboliska länken \"%s\": %s\n"
 
-#, fuzzy
-#~ msgid "%s: Out of memory.\n"
-#~ msgstr "%s: %s: Ej tillräckligt med minne.\n"
+#~ msgid "%s: Cannot determine user-id.\n"
+#~ msgstr "%s: Kan inte avgöra användar-id.\n"
 
-#~ msgid ""
-#~ "Local file `%s' is more recent, not retrieving.\n"
-#~ "\n"
+#~ msgid "%s: Warning: uname failed: %s\n"
+#~ msgstr "%s: Varning: uname misslyckades: %s\n"
+
+#~ msgid "%s: Warning: gethostname failed\n"
+#~ msgstr "%s: Varning: gethostname misslyckades\n"
+
+#~ msgid "%s: Warning: cannot determine local IP address.\n"
+#~ msgstr "%s: Varning: kan inte avgöra lokal IP-adress.\n"
+
+#~ msgid "%s: Warning: cannot reverse-lookup local IP address.\n"
+#~ msgstr "%s: Varning: kan inte utföra omvänd uppslagning av lokal IP-adress.\n"
+
+#~ msgid "%s: Warning: reverse-lookup of local address did not yield FQDN!\n"
 #~ msgstr ""
-#~ "Lokala filen \"%s\" är nyare, hämtar inte.\n"
-#~ "\n"
+#~ "%s: Varning: omvänd uppslagning av den lokala adressen gav inget\n"
+#~ "fullständigt domännamn!\n"
+
+#~ msgid "%s: Out of memory.\n"
+#~ msgstr "%s: Slut på minne.\n"
+
+#~ msgid "%s: Redirection to itself.\n"
+#~ msgstr "%s: Omdirigering till sig själv.\n"
 
 #~ msgid "Error (%s): Link %s without a base provided.\n"
 #~ msgstr "Fel (%s): Länk %s given utan en bas.\n"
 
 #~ msgid "Error (%s): Base %s relative, without referer URL.\n"
 #~ msgstr "Fel (%s): Basen %s relativ utan hänvisar-URL.\n"
+
+#~ msgid "Local file `%s' is more recent, not retrieving.\n\n"
+#~ msgstr "Lokala filen \"%s\" är nyare, hämtar inte.\n\n"
