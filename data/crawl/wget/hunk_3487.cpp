 "Wgeti peatamiseks vajuta CTRL+ALT+DELETE.\n"
 
 #. parent, no error
-#: src/mswindows.c:106 src/utils.c:458
+#: src/mswindows.c:123 src/utils.c:462
 msgid "Continuing in background.\n"
 msgstr "Jätkan taustas.\n"
 
-#: src/mswindows.c:108 src/utils.c:460
+#: src/mswindows.c:125 src/utils.c:464
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr "Väljund kirjutatakse faili `%s'.\n"
 
-#: src/mswindows.c:188
+#: src/mswindows.c:205
 #, c-format
 msgid "Starting WinHelp %s\n"
 msgstr "Stardin WinHelp %s\n"
 
-#: src/mswindows.c:215 src/mswindows.c:222
+#: src/mswindows.c:232 src/mswindows.c:239
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: Ei leia kasutuskõlblikku pistiku programmi.\n"
 
-#: src/netrc.c:367
+#: src/netrc.c:365
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
 msgstr "%s: %s:%d: hoiatus: \"%s\" identifikaator on enne masina nime\n"
 
-#: src/netrc.c:398
+#: src/netrc.c:396
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: tundmatu lekseem \"%s\"\n"
 
-#: src/netrc.c:462
+#: src/netrc.c:460
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Kasuta: %s NETRC [HOSTINIMI]\n"
 
-#: src/netrc.c:472
+#: src/netrc.c:470
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: stat operatsioon ebaõnnestus %s: %s\n"
 
-#: src/recur.c:484
+#. Align the [ skipping ... ] line with the dots.  To do
+#. that, insert the number of spaces equal to the number of
+#. digits in the skipped amount in K.
+#: src/progress.c:203
+#, c-format
+msgid "\n%*s[ skipping %dK ]"
+msgstr "\n%*s[ hüppan üle %dK ]"
+
+#: src/progress.c:370
+#, c-format
+msgid "Invalid dot style specification `%s'; leaving unchanged.\n"
+msgstr "Vigane punkt stiili spetsifikatsioon `%s'; jätan muutmata.\n"
+
+#: src/recur.c:337
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Kustutan %s, kuna see peaks olema tagasi lükatud.\n"
 
-#: src/recur.c:679
+#: src/recur.c:747
+#, c-format
+msgid "Converted %d files in %.2f seconds.\n"
+msgstr "Teisendatud %d faili %.2f sekundiga.\n"
+
+#: src/res.c:541
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Laen robots.txti faili; palun ignoreerige võimalikk vigu.\n"
 
-#: src/retr.c:227
-#, c-format
-msgid "\n          [ skipping %dK ]"
-msgstr "\n          [ hüppan üle %dK ]"
-
-#: src/retr.c:373
+#: src/retr.c:363
 msgid "Could not find proxy host.\n"
 msgstr "Ei leia proxy serverit.\n"
 
-#: src/retr.c:387
+#: src/retr.c:375
 #, c-format
-msgid "Proxy %s: Must be HTTP.\n"
-msgstr "Proxy: %s: Peab olema HTTP.\n"
+msgid "Error parsing proxy URL %s: %s.\n"
+msgstr "Viga proxy urli parsimisel %s: %s.\n"
 
-#: src/retr.c:481
+#: src/retr.c:384
+#, c-format
+msgid "Error in proxy URL %s: Must be HTTP.\n"
+msgstr "Viga proxy urlis %s: Peab olema HTTP.\n"
+
+#: src/retr.c:476
+#, c-format
+msgid "%d redirections exceeded.\n"
+msgstr "%d ümbersuunamist ületatud.\n"
+
+#: src/retr.c:491
 #, c-format
 msgid "%s: Redirection cycle detected.\n"
 msgstr "%s: Tuvastasin ümbersuunamise tsükli.\n"
 
-#: src/retr.c:587
+#: src/retr.c:608
 msgid "Giving up.\n\n"
 msgstr "Annan alla.\n"
 
-#: src/retr.c:587
+#: src/retr.c:608
 msgid "Retrying.\n\n"
 msgstr "Proovin uuesti.\n\n"
 
-#: src/url.c:1329
+#: src/url.c:1725
 #, c-format
 msgid "Converting %s... "
 msgstr "Teisendan %s... "
 
-#: src/url.c:1342
+#: src/url.c:1738
 msgid "nothing to do.\n"
 msgstr "midagi ei ole teha.\n"
 
-#: src/url.c:1350 src/url.c:1374
+#: src/url.c:1746 src/url.c:1770
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Ei suuda teisendada linke %s: %s\n"
 
-#: src/url.c:1365
+#: src/url.c:1761
 #, c-format
 msgid "Unable to delete `%s': %s\n"
 msgstr "Ei õnnestu kustutada `%s': %s\n"
 
-#: src/url.c:1555
+#: src/url.c:1967
 #, c-format
 msgid "Cannot back up %s as %s: %s\n"
 msgstr "Ei suuda luua %s varukoopiat %s: %s\n"
 
-#: src/utils.c:94
+#: src/utils.c:97
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: mälu ei jätku.\n"
 
-#: src/utils.c:417
-msgid "Unknown/unsupported protocol"
-msgstr "Tundmatu/mittetoetatav protokoll"
-
-#: src/utils.c:420
-msgid "Invalid port specification"
-msgstr "Vigane pordi spetsifikatsioon"
-
-#: src/utils.c:423
-msgid "Invalid host name"
-msgstr "Vigane hosti nimi"
-
-#: src/utils.c:620
+#: src/utils.c:634
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
 msgstr "Ei õnnestu kustutada nimeviidet `%s': %s\n"
