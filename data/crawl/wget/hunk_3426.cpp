 #. No luck.
 #. #### This message SUCKS.  We should see what was the
 #. reason that nothing was retrieved.
-#: src/ftp.c:1606
+#: src/ftp.c:1608
 #, c-format
 msgid "No matches on pattern `%s'.\n"
-msgstr "Vzorke `%s' ni� nezodpoved�.\n"
+msgstr "Vzoru `%s' ni� nezodpoved�.\n"
 
 # , c-format
-#: src/ftp.c:1671
+#: src/ftp.c:1673
 #, c-format
 msgid "Wrote HTML-ized index to `%s' [%ld].\n"
 msgstr "V�pis adres�ra v HTML form�te bol zap�san� do `%s' [%ld].\n"
 
 # , c-format
-#: src/ftp.c:1676
+#: src/ftp.c:1678
 #, c-format
 msgid "Wrote HTML-ized index to `%s'.\n"
 msgstr "V�pis adres�ra v HTML form�te bol zap�san� do `%s'.\n"
 
+#: src/gen_sslfunc.c:109
+msgid "Could not seed OpenSSL PRNG; disabling SSL.\n"
+msgstr "Nem��em inicializova� OpenSSL PRNG; vyp�nam SSL.\n"
+
 # , c-format
 #: src/getopt.c:454
 #, c-format
 msgid "%s: option `%s' is ambiguous\n"
-msgstr "%s: prep�na� `%s' nie je jednozna�n�\n"
+msgstr "%s: vo�ba `%s' nie je jednozna�n�\n"
 
 # , c-format
 #: src/getopt.c:478
 #, c-format
 msgid "%s: option `--%s' doesn't allow an argument\n"
-msgstr "%s: prep�na� `--%s' nem� argument\n"
+msgstr "%s: vo�ba `--%s' nepodporuje parameter\n"
 
 # , c-format
 #: src/getopt.c:483
 #, c-format
 msgid "%s: option `%c%s' doesn't allow an argument\n"
-msgstr "%s: prep�na� `%c%s' nem� argument\n"
+msgstr "%s: vo�ba `%c%s' nepodporuje parameter\n"
 
 # , c-format
 #: src/getopt.c:498
 #, c-format
 msgid "%s: option `%s' requires an argument\n"
-msgstr "%s: prep�na� `%s' vy�aduje argument\n"
+msgstr "%s: vo�ba `%s' vy�aduje parameter\n"
 
 # , c-format
 #. --option
 #: src/getopt.c:528
 #, c-format
 msgid "%s: unrecognized option `--%s'\n"
-msgstr "%s: nezn�my prep�na� `--%s'\n"
+msgstr "%s: nezn�ma vo�ba `--%s'\n"
 
 # , c-format
 #. +option or -option
 #: src/getopt.c:532
 #, c-format
 msgid "%s: unrecognized option `%c%s'\n"
-msgstr "%s: nezn�my prep�na� `%c%s'\n"
+msgstr "%s: nezn�ma vo�ba `%c%s'\n"
 
 # , c-format
 #. 1003.2 specifies the format of this message.
 #: src/getopt.c:563
 #, c-format
 msgid "%s: illegal option -- %c\n"
-msgstr "%s: nepr�pustn� prep�na� -- %c\n"
+msgstr "%s: nepr�pustn� vo�ba -- %c\n"
 
 # , c-format
 #. 1003.2 specifies the format of this message.
 #: src/getopt.c:602
 #, c-format
 msgid "%s: option requires an argument -- %c\n"
-msgstr "%s: prep�na� vy�aduje argument -- %c\n"
+msgstr "%s: vo�ba vy�aduje parameter -- %c\n"
 
-#: src/host.c:374
+# , c-format
+#: src/host.c:271
+#, c-format
+msgid "Resolving %s... "
+msgstr "Prev�dzam %s na IP adresu... "
+
+#: src/host.c:278
+#, c-format
+msgid "failed: %s.\n"
+msgstr "zlyhalo: %s.\n"
+
+#: src/host.c:348
 msgid "Host not found"
 msgstr "Hostite� nebol n�jden�"
 
-#: src/host.c:376
+#: src/host.c:350
 msgid "Unknown error"
 msgstr "Nezn�ma chyba"
 
+#: src/html-url.c:336
+#, c-format
+msgid "%s: Cannot resolve incomplete link %s.\n"
+msgstr "%s: Nem��em rozlo�i� ne�pln� odkaz %s.\n"
+
 #. this is fatal
-#: src/http.c:555
+#: src/http.c:573
 msgid "Failed to set up an SSL context\n"
 msgstr "Nepodarilo sa nastavi� SSL kontext.\n"
 
-#: src/http.c:561
+#: src/http.c:579
 #, c-format
 msgid "Failed to load certificates from %s\n"
 msgstr "Nepodarilo sa na��ta� certifik�ty z %s\n"
 
-#: src/http.c:565 src/http.c:573
+#: src/http.c:583 src/http.c:591
 msgid "Trying without the specified certificate\n"
 msgstr "Sk��am bez zadan�ho certifik�tu\n"
 
-#: src/http.c:569
+#: src/http.c:587
 #, c-format
 msgid "Failed to get certificate key from %s\n"
 msgstr "Nepodarilo sa na��ta� k��� certifik�tu z %s\n"
 
-#: src/http.c:663 src/http.c:1593
+#: src/http.c:657 src/http.c:1620
 msgid "Unable to establish SSL connection.\n"
-msgstr "Nepodarilo sa nadviaza� SSL spojenie\n"
+msgstr "Nepodarilo sa nadviaza� SSL spojenie.\n"
 
 # , c-format
-#: src/http.c:671
+#: src/http.c:666
 #, c-format
 msgid "Reusing connection to %s:%hu.\n"
 msgstr "Pou��vam existuj�ce spojenie s %s:%hu.\n"
 
-#: src/http.c:861
+#: src/http.c:868
 #, c-format
 msgid "Failed writing HTTP request: %s.\n"
 msgstr "Po�iadavku HTTP nebolo mo�n� odosla�: %s.\n"
 
 # , c-format
-#: src/http.c:866
+#: src/http.c:873
 #, c-format
 msgid "%s request sent, awaiting response... "
-msgstr "%s po�iadavka odoslan�, �ak�m na odpove� ... "
+msgstr "%s po�iadavka odoslan�, �ak�m na odpove�... "
 
-#: src/http.c:910
+#: src/http.c:917
 msgid "End of file while parsing headers.\n"
-msgstr "Hlavi�ka nie je �pln�.\n"
+msgstr "Koniec s�boru po�as anal�zy hlavi�iek.\n"
 
 # , c-format
-#: src/http.c:920
+#: src/http.c:927
 #, c-format
 msgid "Read error (%s) in headers.\n"
 msgstr "Chyba (%s) pri ��tan� hlavi�iek.\n"
 
-#: src/http.c:959
+#: src/http.c:962
 msgid "No data received"
 msgstr "Nepri�li �iadne d�ta"
 
-#: src/http.c:961
+#: src/http.c:964
 msgid "Malformed status line"
-msgstr "Odpove� serveru m� skomolen� stavov� riadok"
+msgstr "Odpove� servera m� skomolen� stavov� riadok"
 
-#: src/http.c:966
+#: src/http.c:969
 msgid "(no description)"
-msgstr "(�iadny popis)"
+msgstr "(bez popisu)"
 
-#: src/http.c:1089
+#: src/http.c:1101
 msgid "Authorization failed.\n"
 msgstr "Autoriz�cia zlyhala.\n"
 
-#: src/http.c:1096
+#: src/http.c:1108
 msgid "Unknown authentication scheme.\n"
-msgstr "Server po�aduje nezn�my sp�sob autentifik�cie.\n"
+msgstr "Nezn�my sp�sob autentifik�cie.\n"
 
 # , c-format
-#: src/http.c:1136
+#: src/http.c:1148
 #, c-format
 msgid "Location: %s%s\n"
 msgstr "Presmerovan� na: %s%s\n"
 
-#: src/http.c:1137 src/http.c:1269
+#: src/http.c:1149 src/http.c:1282
 msgid "unspecified"
 msgstr "neudan�"
 
-#: src/http.c:1138
+#: src/http.c:1150
 msgid " [following]"
 msgstr " [nasledujem]"
 
-#: src/http.c:1200
+#: src/http.c:1213
 msgid "\n    The file is already fully retrieved; nothing to do.\n\n"
 msgstr "\n    Tento s�bor je u� kompletne prenesen�; netreba ni� robi�.\n\n"
 
-#: src/http.c:1216
+#: src/http.c:1229
 #, c-format
 msgid ""
 "\n"
