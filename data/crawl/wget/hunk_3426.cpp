 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1606
+#: src/ftp.c:1608
 #, c-format
 msgid "No matches on pattern `%s'.\n"
-msgstr "Vzorke `%s' niè nezodpovedá.\n"
+msgstr "Vzoru `%s' niè nezodpovedá.\n"
 
 # , c-format
-#: src/ftp.c:1671
+#: src/ftp.c:1673
 #, c-format
 msgid "Wrote HTML-ized index to `%s' [%ld].\n"
 msgstr "Výpis adresára v HTML formáte bol zapísaný do `%s' [%ld].\n"
 
 # , c-format
-#: src/ftp.c:1676
+#: src/ftp.c:1678
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "Výpis adresára v HTML formáte bol zapísaný do `%s'.\n"
 
+#: src/gen_sslfunc.c:109
+msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
+msgstr "Nemô¾em inicializova» OpenSSL PRNG; vypínam SSL.\n"
+
 # , c-format
 #: src/getopt.c:454
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
-msgstr "%s: prepínaè `%s' nie je jednoznaèný\n"
+msgstr "%s: voµba `%s' nie je jednoznaèná\n"
 
 # , c-format
 #: src/getopt.c:478
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
-msgstr "%s: prepínaè `--%s' nemá argument\n"
+msgstr "%s: voµba `--%s' nepodporuje parameter\n"
 
 # , c-format
 #: src/getopt.c:483
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
-msgstr "%s: prepínaè `%c%s' nemá argument\n"
+msgstr "%s: voµba `%c%s' nepodporuje parameter\n"
 
 # , c-format
 #: src/getopt.c:498
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
-msgstr "%s: prepínaè `%s' vy¾aduje argument\n"
+msgstr "%s: voµba `%s' vy¾aduje parameter\n"
 
 # , c-format
 #. --option
 #: src/getopt.c:528
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
-msgstr "%s: neznámy prepínaè `--%s'\n"
+msgstr "%s: neznáma voµba `--%s'\n"
 
 # , c-format
 #. +option or -option
 #: src/getopt.c:532
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
-msgstr "%s: neznámy prepínaè `%c%s'\n"
+msgstr "%s: neznáma voµba `%c%s'\n"
 
 # , c-format
 #. 1003.2 specifies the format of this message.
 #: src/getopt.c:563
 #, c-format
 msgid "%s: illegal option -- %c\n"
-msgstr "%s: neprípustný prepínaè -- %c\n"
+msgstr "%s: neprípustná voµba -- %c\n"
 
 # , c-format
 #. 1003.2 specifies the format of this message.
 #: src/getopt.c:602
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
-msgstr "%s: prepínaè vy¾aduje argument -- %c\n"
+msgstr "%s: voµba vy¾aduje parameter -- %c\n"
 
-#: src/host.c:374
+# , c-format
+#: src/host.c:271
+#, c-format
+msgid "Resolving %s... "
+msgstr "Prevádzam %s na IP adresu... "
+
+#: src/host.c:278
+#, c-format
+msgid "failed: %s.\n"
+msgstr "zlyhalo: %s.\n"
+
+#: src/host.c:348
 msgid "Host not found"
 msgstr "Hostiteµ nebol nájdený"
 
-#: src/host.c:376
+#: src/host.c:350
 msgid "Unknown error"
 msgstr "Neznáma chyba"
 
+#: src/html-url.c:336
+#, c-format
+msgid "%s: Cannot resolve incomplete link %s.\n"
+msgstr "%s: Nemô¾em rozlo¾i» neúplný odkaz %s.\n"
+
 #. this is fatal
-#: src/http.c:555
+#: src/http.c:573
 msgid "Failed to set up an SSL context\n"
 msgstr "Nepodarilo sa nastavi» SSL kontext.\n"
 
-#: src/http.c:561
+#: src/http.c:579
 #, c-format
 msgid "Failed to load certificates from %s\n"
 msgstr "Nepodarilo sa naèíta» certifikáty z %s\n"
 
-#: src/http.c:565 src/http.c:573
+#: src/http.c:583 src/http.c:591
 msgid "Trying without the specified certificate\n"
 msgstr "Skú¹am bez zadaného certifikátu\n"
 
-#: src/http.c:569
+#: src/http.c:587
 #, c-format
 msgid "Failed to get certificate key from %s\n"
 msgstr "Nepodarilo sa naèíta» kµúè certifikátu z %s\n"
 
-#: src/http.c:663 src/http.c:1593
+#: src/http.c:657 src/http.c:1620
 msgid "Unable to establish SSL connection.\n"
-msgstr "Nepodarilo sa nadviaza» SSL spojenie\n"
+msgstr "Nepodarilo sa nadviaza» SSL spojenie.\n"
 
 # , c-format
-#: src/http.c:671
+#: src/http.c:666
 #, c-format
 msgid "Reusing connection to %s:%hu.\n"
 msgstr "Pou¾ívam existujúce spojenie s %s:%hu.\n"
 
-#: src/http.c:861
+#: src/http.c:868
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Po¾iadavku HTTP nebolo mo¾né odosla»: %s.\n"
 
 # , c-format
-#: src/http.c:866
+#: src/http.c:873
 #, c-format
 msgid "%s request sent, awaiting response... "
-msgstr "%s po¾iadavka odoslaná, èakám na odpoveï ... "
+msgstr "%s po¾iadavka odoslaná, èakám na odpoveï... "
 
-#: src/http.c:910
+#: src/http.c:917
 msgid "End of file while parsing headers.\n"
-msgstr "Hlavièka nie je úplná.\n"
+msgstr "Koniec súboru poèas analýzy hlavièiek.\n"
 
 # , c-format
-#: src/http.c:920
+#: src/http.c:927
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Chyba (%s) pri èítaní hlavièiek.\n"
 
-#: src/http.c:959
+#: src/http.c:962
 msgid "No data received"
 msgstr "Nepri¹li ¾iadne dáta"
 
-#: src/http.c:961
+#: src/http.c:964
 msgid "Malformed status line"
-msgstr "Odpoveï serveru má skomolený stavový riadok"
+msgstr "Odpoveï servera má skomolený stavový riadok"
 
-#: src/http.c:966
+#: src/http.c:969
 msgid "(no description)"
-msgstr "(¾iadny popis)"
+msgstr "(bez popisu)"
 
-#: src/http.c:1089
+#: src/http.c:1101
 msgid "Authorization failed.\n"
 msgstr "Autorizácia zlyhala.\n"
 
-#: src/http.c:1096
+#: src/http.c:1108
 msgid "Unknown authentication scheme.\n"
-msgstr "Server po¾aduje neznámy spôsob autentifikácie.\n"
+msgstr "Neznámy spôsob autentifikácie.\n"
 
 # , c-format
-#: src/http.c:1136
+#: src/http.c:1148
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Presmerované na: %s%s\n"
 
-#: src/http.c:1137 src/http.c:1269
+#: src/http.c:1149 src/http.c:1282
 msgid "unspecified"
 msgstr "neudané"
 
-#: src/http.c:1138
+#: src/http.c:1150
 msgid " [following]"
 msgstr " [nasledujem]"
 
-#: src/http.c:1200
+#: src/http.c:1213
 msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
 msgstr "\n    Tento súbor je u¾ kompletne prenesený; netreba niè robi».\n\n"
 
-#: src/http.c:1216
+#: src/http.c:1229
 #, c-format
 msgid ""
 "\n"
