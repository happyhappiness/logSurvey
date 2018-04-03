 "FERDIG --%s--\n"
 "Lastet ned %s bytes i %d filer\n"
 
-#: src/main.c:978
+#: src/main.c:842
 #, c-format
 msgid "Download quota (%s bytes) EXCEEDED!\n"
 msgstr "Nedlastingskvote (%s bytes) overskredet!\n"
 
-#: src/mswindows.c:235
+#. Please note that the double `%' in `%%s' is intentional, because
+#. redirect_output passes tmp through printf.
+#: src/main.c:876
 #, c-format
-msgid "Continuing in background.\n"
-msgstr "Fortsetter i bakgrunnen.\n"
+msgid "%s received, redirecting output to `%%s'.\n"
+msgstr "%s mottatt, omdirigerer utskrifter til «%%s».\n"
 
-#: src/mswindows.c:427
-#, fuzzy, c-format
-msgid "Continuing in background, pid %lu.\n"
+#: src/mswindows.c:89
+#, c-format
+msgid ""
+"\n"
+"CTRL+Break received, redirecting output to `%s'.\n"
+"Execution continued in background.\n"
+"You may stop Wget by pressing CTRL+ALT+DELETE.\n"
+msgstr ""
+"\n"
+"CTRL+Break mottatt, omdirigerer utskrifter til `%s'.\n"
+"Kjøring fortsetter i bakgrunnen.\n"
+"Du kan stoppe Wget ved å trykke CTRL+ALT+DELETE.\n"
+"\n"
+
+#. parent, no error
+#: src/mswindows.c:106 src/utils.c:458
+msgid "Continuing in background.\n"
 msgstr "Fortsetter i bakgrunnen.\n"
 
-#: src/mswindows.c:429 src/utils.c:348
+#: src/mswindows.c:108 src/utils.c:460
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr "Utskrifter vil bli skrevet til «%s».\n"
 
-#: src/mswindows.c:597 src/mswindows.c:604
+#: src/mswindows.c:188
+#, c-format
+msgid "Starting WinHelp %s\n"
+msgstr "Starter WinHelp %s\n"
+
+#: src/mswindows.c:215 src/mswindows.c:222
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: Fant ingen brukbar socket-driver.\n"
 
-#: src/netrc.c:385
+#: src/netrc.c:367
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
 msgstr "%s: %s:%d: Advarsel: symbolet «%s» funnet før tjener-navn\n"
 
-#: src/netrc.c:416
+#: src/netrc.c:398
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: ukjent symbol «%s»\n"
 
-#: src/netrc.c:480
+#: src/netrc.c:462
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Bruk: %s NETRC [TJENERNAVN]\n"
 
-#: src/netrc.c:490
+#: src/netrc.c:472
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: «stat» feilet for %s: %s\n"
 
-#. Still not random enough, presumably because neither /dev/random
-#. nor EGD were available.  Try to seed OpenSSL's PRNG with libc
-#. PRNG.  This is cryptographically weak and defeats the purpose
-#. of using OpenSSL, which is why it is highly discouraged.
-#: src/openssl.c:121
-msgid "WARNING: using a weak random seed.\n"
-msgstr ""
-
-#: src/openssl.c:181
-msgid "Could not seed PRNG; consider using --random-file.\n"
-msgstr ""
-
-#. If the user has specified --no-check-cert, we still want to warn
-#. him about problems with the server's certificate.
-#: src/openssl.c:419
-msgid "ERROR"
-msgstr ""
-
-#: src/openssl.c:419
-msgid "WARNING"
-msgstr ""
-
-#: src/openssl.c:427
-#, c-format
-msgid "%s: No certificate presented by %s.\n"
-msgstr ""
-
-#: src/openssl.c:458
-#, c-format
-msgid "%s: Certificate verification error for %s: %s\n"
-msgstr ""
-
-#: src/openssl.c:485
-#, c-format
-msgid ""
-"%s: certificate common name `%s' doesn't match requested host name `%s'.\n"
-msgstr ""
-
-#: src/openssl.c:498
-#, c-format
-msgid "To connect to %s insecurely, use `--no-check-certificate'.\n"
-msgstr ""
-
-#. Align the [ skipping ... ] line with the dots.  To do
-#. that, insert the number of spaces equal to the number of
-#. digits in the skipped amount in K.
-#: src/progress.c:243
-#, fuzzy, c-format
-msgid ""
-"\n"
-"%*s[ skipping %dK ]"
-msgstr ""
-"\n"
-"          [ hopper over %dK ]"
-
-#: src/progress.c:410
-#, fuzzy, c-format
-msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
-msgstr "%s: Ugyldig spesifikasjon «%s»\n"
-
-#: src/recur.c:377
+#: src/recur.c:484
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Fjerner %s fordi den skal forkastes.\n"
 
-#: src/res.c:544
+#: src/recur.c:679
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Henter robots.txt; ignorer eventuelle feilmeldinger.\n"
 
-#: src/retr.c:645
+#: src/retr.c:227
 #, c-format
-msgid "Error parsing proxy URL %s: %s.\n"
-msgstr ""
+msgid "\n          [ skipping %dK ]"
+msgstr "\n          [ hopper over %dK ]"
 
-#: src/retr.c:653
-#, fuzzy, c-format
-msgid "Error in proxy URL %s: Must be HTTP.\n"
+#: src/retr.c:373
+msgid "Could not find proxy host.\n"
+msgstr "Fant ikke proxy-tjener.\n"
+
+#: src/retr.c:387
+#, c-format
+msgid "Proxy %s: Must be HTTP.\n"
 msgstr "Proxy %s: Må støtte HTTP.\n"
 
-#: src/retr.c:738
+#: src/retr.c:481
 #, fuzzy, c-format
-msgid "%d redirections exceeded.\n"
+msgid "%s: Redirection cycle detected.\n"
 msgstr "%s: Omdirigerer til seg selv.\n"
 
-#: src/retr.c:863
-msgid ""
-"Giving up.\n"
-"\n"
-msgstr ""
-"Gir opp.\n"
-"\n"
+#: src/retr.c:587
+msgid "Giving up.\n\n"
+msgstr "Gir opp.\n\n"
 
-#: src/retr.c:863
-msgid ""
-"Retrying.\n"
-"\n"
-msgstr ""
-"Prøver igjen.\n"
-"\n"
+#: src/retr.c:587
+msgid "Retrying.\n\n"
+msgstr "Prøver igjen.\n\n"
 
-#: src/url.c:626
-#, fuzzy
-msgid "No error"
-msgstr "Ukjent feil"
+#: src/url.c:1329
+#, c-format
+msgid "Converting %s... "
+msgstr "Konverterer %s... "
 
-#: src/url.c:628
-msgid "Unsupported scheme"
+#: src/url.c:1342
+msgid "nothing to do.\n"
 msgstr ""
 
-#: src/url.c:630
-msgid "Empty host"
-msgstr ""
+#: src/url.c:1350 src/url.c:1374
+#, c-format
+msgid "Cannot convert links in %s: %s\n"
+msgstr "Kan ikke konvertere linker i %s: %s\n"
 
-#: src/url.c:632
-msgid "Bad port number"
-msgstr ""
+#: src/url.c:1365
+#, fuzzy, c-format
+msgid "Unable to delete `%s': %s\n"
+msgstr "Kan ikke slette den symbolske linken «%s»: %s\n"
 
-#: src/url.c:634
-#, fuzzy
-msgid "Invalid user name"
-msgstr "Tjenernavnet er ugyldig"
+#: src/url.c:1555
+#, fuzzy, c-format
+msgid "Cannot back up %s as %s: %s\n"
+msgstr "Kan ikke konvertere linker i %s: %s\n"
 
-#: src/url.c:636
-msgid "Unterminated IPv6 numeric address"
-msgstr ""
+#: src/utils.c:94
+#, c-format
+msgid "%s: %s: Not enough memory.\n"
+msgstr "%s: %s: Ikke nok minne.\n"
 
-#: src/url.c:638
-msgid "IPv6 addresses not supported"
-msgstr ""
+#: src/utils.c:417
+msgid "Unknown/unsupported protocol"
+msgstr "Protokollen er ukjent/ikke støttet"
 
-#: src/url.c:640
-msgid "Invalid IPv6 numeric address"
-msgstr ""
+#: src/utils.c:420
+msgid "Invalid port specification"
+msgstr "Port-spesifikasjonen er ugyldig"
 
-#. parent, no error
-#: src/utils.c:346
-#, fuzzy, c-format
-msgid "Continuing in background, pid %d.\n"
-msgstr "Fortsetter i bakgrunnen.\n"
+#: src/utils.c:423
+msgid "Invalid host name"
+msgstr "Tjenernavnet er ugyldig"
 
-#: src/utils.c:394
+#: src/utils.c:620
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Kan ikke slette den symbolske linken «%s»: %s\n"
 
-#: src/xmalloc.c:72
-#, c-format
-msgid "%s: %s: Failed to allocate %ld bytes; memory exhausted.\n"
-msgstr ""
-
-#~ msgid "Connection to %s:%hu refused.\n"
-#~ msgstr "Kontakt med %s:%hu nektet.\n"
-
-#~ msgid "Will try connecting to %s:%hu.\n"
-#~ msgstr "Vil prøve å kontakte %s:%hu.\n"
-
-#~ msgid " [%s to go]"
-#~ msgstr " [%s igjen]"
+#~ msgid "Local file `%s' is more recent, not retrieving.\n\n"
+#~ msgstr "Lokal fil «%s» er samme/nyere, ignoreres.\n\n"
 
 #~ msgid "%s: Cannot determine user-id.\n"
 #~ msgstr "%s: Fant ikke bruker-ID.\n"
