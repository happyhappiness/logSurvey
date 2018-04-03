 "Wgeti peatamiseks vajuta CTRL+ALT+DELETE.\n"
 
 #. parent, no error
-#: src/mswindows.c:135 src/utils.c:269
+#: src/mswindows.c:106 src/utils.c:457
 msgid "Continuing in background.\n"
 msgstr "Jätkan taustas.\n"
 
-#: src/mswindows.c:137 src/utils.c:271
+#: src/mswindows.c:108 src/utils.c:459
 #, c-format
 msgid "Output will be written to `%s'.\n"
 msgstr "Väljund kirjutatakse faili `%s'.\n"
 
-#: src/mswindows.c:227
+#: src/mswindows.c:188
 #, c-format
 msgid "Starting WinHelp %s\n"
 msgstr "Stardin WinHelp %s\n"
 
-#: src/mswindows.c:254 src/mswindows.c:262
+#: src/mswindows.c:215 src/mswindows.c:222
 #, c-format
 msgid "%s: Couldn't find usable socket driver.\n"
 msgstr "%s: Ei leia kasutuskõlblikku pistiku programmi.\n"
 
-#: src/netrc.c:359
+#: src/netrc.c:367
 #, c-format
 msgid "%s: %s:%d: warning: \"%s\" token appears before any machine name\n"
 msgstr "%s: %s:%d: hoiatus: \"%s\" identifikaator on enne masina nime\n"
 
-#: src/netrc.c:390
+#: src/netrc.c:398
 #, c-format
 msgid "%s: %s:%d: unknown token \"%s\"\n"
 msgstr "%s: %s:%d: tundmatu lekseem \"%s\"\n"
 
-#: src/netrc.c:454
+#: src/netrc.c:462
 #, c-format
 msgid "Usage: %s NETRC [HOSTNAME]\n"
 msgstr "Kasuta: %s NETRC [HOSTINIMI]\n"
 
-#: src/netrc.c:464
+#: src/netrc.c:472
 #, c-format
 msgid "%s: cannot stat %s: %s\n"
 msgstr "%s: stat operatsioon ebaõnnestus %s: %s\n"
 
-#: src/recur.c:469
+#: src/recur.c:484
 #, c-format
 msgid "Removing %s since it should be rejected.\n"
 msgstr "Kustutan %s, kuna see peaks olema tagasi lükatud.\n"
 
-#: src/recur.c:630
+#: src/recur.c:679
 msgid "Loading robots.txt; please ignore errors.\n"
 msgstr "Laen robots.txti faili; palun ignoreerige võimalikk vigu.\n"
 
-#: src/retr.c:197
+#: src/retr.c:227
 #, c-format
-msgid ""
-"\n"
-"          [ skipping %dK ]"
-msgstr ""
-"\n"
-"          [ hüppan üle %dK ]"
+msgid "\n          [ skipping %dK ]"
+msgstr "\n          [ hüppan üle %dK ]"
 
-#: src/retr.c:380
+#: src/retr.c:373
 msgid "Could not find proxy host.\n"
 msgstr "Ei leia proxy serverit.\n"
 
-#: src/retr.c:393
+#: src/retr.c:387
 #, c-format
 msgid "Proxy %s: Must be HTTP.\n"
 msgstr "Proxy: %s: Peab olema HTTP.\n"
 
-#: src/retr.c:472
-#, c-format
-msgid "%s: Redirection to itself.\n"
-msgstr "%s: Ümbersuunamine iseendale.\n"
-
-#: src/retr.c:486
+#: src/retr.c:481
 #, c-format
 msgid "%s: Redirection cycle detected.\n"
-msgstr "%s: Ümbersuunamine iseendale.\n"
+msgstr "%s: Tuvastasin ümbersuunamise tsükli.\n"
 
-#: src/retr.c:581
-msgid ""
-"Giving up.\n"
-"\n"
+#: src/retr.c:587
+msgid "Giving up.\n\n"
 msgstr "Annan alla.\n"
 
-#: src/retr.c:581
-msgid ""
-"Retrying.\n"
-"\n"
-msgstr ""
-"Proovin uuesti.\n"
-"\n"
-
-#: src/url.c:983
-#, c-format
-msgid "Error (%s): Link %s without a base provided.\n"
-msgstr "Viga (%s): Viide %s on ilma baasita.\n"
+#: src/retr.c:587
+msgid "Retrying.\n\n"
+msgstr "Proovin uuesti.\n\n"
 
-#: src/url.c:999
-#, c-format
-msgid "Error (%s): Base %s relative, without referer URL.\n"
-msgstr "Viga(%s): Baas %s on suhteline, puudub viitav URL.\n"
-
-#: src/url.c:1540
+#: src/url.c:1329
 #, c-format
 msgid "Converting %s... "
 msgstr "Teisendan %s... "
 
-#: src/url.c:1545 src/url.c:1632
+#: src/url.c:1342
+msgid "nothing to do.\n"
+msgstr "midagi ei ole teha.\n"
+
+#: src/url.c:1350 src/url.c:1374
 #, c-format
 msgid "Cannot convert links in %s: %s\n"
 msgstr "Ei suuda teisendada linke %s: %s\n"
 
-#: src/url.c:1608
+#: src/url.c:1365
+#, c-format
+msgid "Unable to delete `%s': %s\n"
+msgstr "Ei õnnestu kustutada `%s': %s\n"
+
+#: src/url.c:1555
 #, c-format
 msgid "Cannot back up %s as %s: %s\n"
-msgstr "Ei saa luua %s varukoopiat %s: %s\n"
+msgstr "Ei suuda luua %s varukoopiat %s: %s\n"
 
-#: src/utils.c:72
+#: src/utils.c:93
 #, c-format
 msgid "%s: %s: Not enough memory.\n"
 msgstr "%s: %s: mälu ei jätku.\n"
 
-#: src/utils.c:204
+#: src/utils.c:416
 msgid "Unknown/unsupported protocol"
 msgstr "Tundmatu/mittetoetatav protokoll"
 
-#: src/utils.c:207
+#: src/utils.c:419
 msgid "Invalid port specification"
 msgstr "Vigane pordi spetsifikatsioon"
 
-#: src/utils.c:210
+#: src/utils.c:422
 msgid "Invalid host name"
 msgstr "Vigane hosti nimi"
 
-#: src/utils.c:431
+#: src/utils.c:619
 #, c-format
 msgid "Failed to unlink symlink `%s': %s\n"
-msgstr "Ei õnnestu kustutada sümbol viidet `%s': %s\n"
-
-#~ msgid ""
-#~ "Local file `%s' is more recent, not retrieving.\n"
-#~ "\n"
-#~ msgstr ""
-#~ "Lokaalne fail `%s' on uuem, ei tõmba.\n"
-#~ "\n"
+msgstr "Ei õnnestu kustutada nimeviidet `%s': %s\n"
