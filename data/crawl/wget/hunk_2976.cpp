 "FERDIG --%s--\n"
 "Lastet ned %s bytes i %d filer\n"
 
-#: src/main.c:821
+#: src/main.c:951
 #, c-format
 msgid "Download quota (%s bytes) EXCEEDED!\n"
 msgstr "Nedlastingskvote (%s bytes) overskredet!\n"
 
-#. Please note that the double `%' in `%%s' is intentional, because
-#. redirect_output passes tmp through printf.
-#: src/main.c:851
-msgid "%s received, redirecting output to `%%s'.\n"
-msgstr "%s mottatt, omdirigerer utskrifter til «%%s».\n"
-
-#: src/mswindows.c:123
+#: src/mswindows.c:235
 #, c-format
-msgid ""
-"\n"
-"CTRL+Break received, redirecting output to `%s'.\n"
-"Execution continued in background.\n"
-"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
-msgstr ""
-"\n"
-"CTRL+Break mottatt, omdirigerer utskrifter til `%s'.\n"
-"Kjøring fortsetter i bakgrunnen.\n"
-"Du kan stoppe Wget ved å trykke CTRL+ALT+DELETE.\n"
-"\n"
-
-#. parent, no error
-#: src/mswindows.c:140 src/utils.c:451
 msgid "Continuing in background.\n"
 msgstr "Fortsetter i bakgrunnen.\n"
 
-#: src/mswindows.c:142 src/utils.c:453
+#: src/mswindows.c:427
+#, fuzzy, c-format
+msgid "Continuing in background, pid %lu.\n"
+msgstr "Fortsetter i bakgrunnen.\n"
+
+#: src/mswindows.c:429 src/utils.c:349
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr "Utskrifter vil bli skrevet til «%s».\n"
 
-#: src/mswindows.c:232
-#, c-format
-msgid "Starting WinHelp %s\n"
-msgstr "Starter WinHelp %s\n"
-
-#: src/mswindows.c:259 src/mswindows.c:267
+#: src/mswindows.c:597 src/mswindows.c:604
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: Fant ingen brukbar socket-driver.\n"
 
-#: src/netrc.c:367
+#: src/netrc.c:385
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
 msgstr "%s: %s:%d: Advarsel: symbolet «%s» funnet før tjener-navn\n"
 
-#: src/netrc.c:398
+#: src/netrc.c:416
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: ukjent symbol «%s»\n"
 
-#: src/netrc.c:462
+#: src/netrc.c:480
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Bruk: %s NETRC [TJENERNAVN]\n"
 
-#: src/netrc.c:472
+#: src/netrc.c:490
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: «stat» feilet for %s: %s\n"
 
-#: src/recur.c:510
+#. Align the [ skipping ... ] line with the dots.  To do
+#. that, insert the number of spaces equal to the number of
+#. digits in the skipped amount in K.
+#: src/progress.c:243
+#, fuzzy, c-format
+msgid ""
+"\n"
+"%*s[ skipping %dK ]"
+msgstr ""
+"\n"
+"          [ hopper over %dK ]"
+
+#: src/progress.c:410
+#, fuzzy, c-format
+msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
+msgstr "%s: Ugyldig spesifikasjon «%s»\n"
+
+#: src/recur.c:377
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Fjerner %s fordi den skal forkastes.\n"
 
-#: src/recur.c:684
+#: src/res.c:548
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Henter robots.txt; ignorer eventuelle feilmeldinger.\n"
 
-#: src/retr.c:229
+#: src/retr.c:638
 #, c-format
-msgid ""
-"\n"
-"          [ skipping %dK ]"
+msgid "Error parsing proxy URL %s: %s.\n"
 msgstr ""
-"\n"
-"          [ hopper over %dK ]"
 
-#: src/retr.c:421
-msgid "Could not find proxy host.\n"
-msgstr "Fant ikke proxy-tjener.\n"
-
-#: src/retr.c:435
-#, c-format
-msgid "Proxy %s: Must be HTTP.\n"
+#: src/retr.c:646
+#, fuzzy, c-format
+msgid "Error in proxy URL %s: Must be HTTP.\n"
 msgstr "Proxy %s: Må støtte HTTP.\n"
 
-#: src/retr.c:529
+#: src/retr.c:731
 #, fuzzy, c-format
-msgid "%s: Redirection cycle detected.\n"
+msgid "%d redirections exceeded.\n"
 msgstr "%s: Omdirigerer til seg selv.\n"
 
-#: src/retr.c:623
+#: src/retr.c:856
 msgid ""
 "Giving up.\n"
 "\n"
